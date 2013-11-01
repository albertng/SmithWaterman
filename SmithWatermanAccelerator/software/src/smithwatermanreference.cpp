#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <sstream>
#include "fasta.h"
#include "alignment.h"
#include "scoring.h"
#include "utils.h"
#include "def.h"
#include <time.h>
#include <set>

enum AlnOp {INSERT_OP, DELETE_OP, MATCH_OP, ZERO_OP};

static const int REF_NAME_FIELD = 0;

static const int QUERY_NAME_FIELD = 0;
static const int QUERY_REF_FIELD = 1;
static const int QUERY_START_FIELD = 2;
static const int QUERY_END_FIELD = 3;
static const int QUERY_THRESHOLD_FIELD = 4;

struct HighScoreCell {
  int ref_index;
  int query_index;
  int score;
  
  bool operator==(const HighScoreCell& rhs) {
    return ref_index == rhs.ref_index && query_index == rhs.query_index && score == rhs.score;
  }
};

struct HighScoreCellComp {
  bool operator() (const HighScoreCell& lhs, const HighScoreCell& rhs) const {
    if (lhs.ref_index > rhs.ref_index) {
      return true;
    }
    else if (lhs.ref_index == rhs.ref_index) {
      return lhs.query_index > rhs.query_index;
    } else {
      return false;
    }
  }
};

struct AlignmentResultComp {
  bool operator() (const AlignmentResult& lhs, const AlignmentResult& rhs) const {
    return lhs.alignment.get_ref_offset() < rhs.alignment.get_ref_offset();
  }
};

template <class T>
T String2Type (std::string str) {
  std::stringstream ss(str);
  T result;
  ss >> result;
  return result;
}

void PrintAlignment(Alignment aln, std::string query_name, int score) {
  std::cout << "Query: " << query_name << "\nScore: " << score << "\n"
            << aln.ToString() << std::endl;
}

void Align(std::string query_name,
           char* ref_seq, char* query_seq, 
           long long int ref_len, int query_len,
           long long int offset, 
           int threshold, 
           SwAffineGapParams params) {
  int** v_matrix = new int*[ref_len + 1];
  int** e_matrix = new int*[ref_len + 1];
  int** f_matrix = new int*[ref_len + 1];
  AlnOp** dir_matrix = new AlnOp*[ref_len + 1];
  for (int i = 0; i < ref_len + 1; i++) {
    v_matrix[i] = new int[query_len + 1];
    e_matrix[i] = new int[query_len + 1];
    f_matrix[i] = new int[query_len + 1];
    dir_matrix[i] = new AlnOp[query_len + 1];
    for (int j = 0; j < query_len + 1; j++) {
      v_matrix[i][j] = 0;
      e_matrix[i][j] = 0;
      f_matrix[i][j] = 0;
      dir_matrix[i][j] = ZERO_OP;
    }
  }

  /*std::list<int> highscore_query_index;
  std::list<int> highscore_ref_index;
  std::list<int> highscore_scores;*/
  std::set<HighScoreCell, HighScoreCellComp> highscore_cells;

  int** sub_mat = new int*[4];
  for (int i = 0; i < 4; i++) {
    sub_mat[i] = new int[4];
  }
  params.GetSubMat(sub_mat);
  int gap_open = params.GetGapOpen();
  int gap_extend = params.GetGapExtend();

  // Compute dynamic programming matrices
  /*struct timespec start, finish;
  clock_gettime(CLOCK_MONOTONIC, &start);*/
  for (int i = 1; i < ref_len + 1; i++) {
    for (int j = 1; j < query_len + 1; j++) {
      NtInt ref_nt = NtChar2Int(ref_seq[offset + i-1]);
      NtInt query_nt = NtChar2Int(query_seq[j-1]);
    
      // Compute possible choices
      int match;
      if (ref_nt == N_NT || query_nt == N_NT) {
        match = -2147483648; // Force N's to align with gaps
      } else {
        match = v_matrix[i-1][j-1] + sub_mat[query_nt][ref_nt];
      }
      int ins_open   = v_matrix[i-1][j] + gap_open;
      int ins_extend = e_matrix[i-1][j] + gap_extend;
      int del_open   = v_matrix[i][j-1] + gap_open;
      int del_extend = f_matrix[i][j-1] + gap_extend;

      // Pick choice with highest score
      // Record decision in dir_matrix
      e_matrix[i][j] = (ins_open > ins_extend) ? ins_open : ins_extend;
      f_matrix[i][j] = (del_open > del_extend) ? del_open : del_extend;
      int max1;
      AlnOp dir1;
      if (match > e_matrix[i][j]) {
        max1 = match;
        dir1 = MATCH_OP;
      } else {
        max1 = e_matrix[i][j];
        dir1 = INSERT_OP;
      }
      int max2;
      AlnOp dir2;
      if (f_matrix[i][j] > 0) {
        max2 = f_matrix[i][j];
        dir2 = DELETE_OP;
      } else {
        max2 = 0;
        dir2 = ZERO_OP;
      }
      if (max1 > max2) {
        v_matrix[i][j] = max1;
        dir_matrix[i][j] = dir1;
      } else {
        v_matrix[i][j] = max2;
        dir_matrix[i][j] = dir2;
      }
      
      // Record high-scoring cells
      if (v_matrix[i][j] >= threshold) {
        HighScoreCell cell;
        cell.ref_index = i;
        cell.query_index = j;
        cell.score = v_matrix[i][j];
        highscore_cells.insert(cell);
        /*highscore_query_index.push_front(j);
        highscore_ref_index.push_front(i);
        highscore_scores.push_front(v_matrix[i][j]);*/
      }
    }
  }
  /*clock_gettime(CLOCK_MONOTONIC, &finish);
  double elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  std::cout<<"Matrix fill took "<<elapsed<<" seconds"<<std::endl;*/
  
  // Backtrace to obtain alignments
  /*struct timespec sub_start, sub_finish;
  double sub_elapsed = 0;
  clock_gettime(CLOCK_MONOTONIC, &start);*/
  //std::list<AlignmentResult> alignments;
  std::set<AlignmentResult, AlignmentResultComp> alignments;
  //int duplicates = 0;
  for (std::set<HighScoreCell, HighScoreCellComp>::iterator it = highscore_cells.begin(); it != highscore_cells.end(); ++it) {
    int query_index = (*it).query_index;
    int ref_index = (*it).ref_index;
    int score = (*it).score;
    
    Alignment aln(offset + ref_index, query_index);
    while (dir_matrix[ref_index][query_index] != ZERO_OP) {
      switch(dir_matrix[ref_index][query_index]) {
        case MATCH_OP:  aln.Prepend(ref_seq[offset + ref_index-1], query_seq[query_index-1]);
                        query_index--;
                        ref_index--;
                        break;
        case INSERT_OP: aln.Prepend(ref_seq[offset + ref_index-1], GAP);
                        ref_index--;
                       break;
        case DELETE_OP: aln.Prepend(GAP, query_seq[query_index-1]);
                        query_index--;
                        break;
       default:         assert(false);
      }
      
      // Keep alignments ending with the right-most max score cell
      if (v_matrix[ref_index][query_index] > score) {
        score = v_matrix[ref_index][query_index];
        aln.TrimEnd(1);
      }
  
      // Remove visited cells from the high score cell list
      HighScoreCell hsc;
      hsc.query_index = query_index;
      hsc.ref_index = ref_index;
      hsc.score = score;
      highscore_cells.erase(hsc);
    }
    
    AlignmentResult aln_res;
    aln_res.alignment = aln;
    aln_res.score = score;
    
    // Filter out duplicate alignments, pick the longest duplicated alignment
    //clock_gettime(CLOCK_MONOTONIC, &sub_start);
    /*bool duplicate = false;
    for (std::list<AlignmentResult>::iterator it = alignments.begin(); it != alignments.end(); ++it) {
      if ((*it).alignment.get_ref_offset() == aln_res.alignment.get_ref_offset()) {
        duplicate = true;
        std::cout<<"Duplicate:"<<std::endl;
        std::cout<<(*it).alignment.ToString()<<aln_res.alignment.ToString()<<std::endl;
        duplicates++;
        if (((*it).score < aln_res.score) || 
            ((*it).score == aln_res.score && (*it).alignment.GetLength() < aln_res.alignment.GetLength())) {
          alignments.insert(it, aln_res);
          it = alignments.erase(it);
          --it;
        }
      }
    }
    
    if (duplicate == false) {
      alignments.push_back(aln_res);
    }*/
    std::set<AlignmentResult, AlignmentResultComp>::iterator aln_it = alignments.find(aln_res);
    if (aln_it != alignments.end()) {
      if (((*aln_it).score < aln_res.score) || 
          ((*aln_it).score == aln_res.score && (*aln_it).alignment.GetLength() < aln_res.alignment.GetLength())) {
        std::set<AlignmentResult, AlignmentResultComp>::iterator aln_insert_it = aln_it;
        aln_insert_it--;
        alignments.erase(aln_it);
        alignments.insert(aln_insert_it, aln_res);
        //duplicates++;
      }
    } else {
      alignments.insert(aln_res);
    }
      
    /*clock_gettime(CLOCK_MONOTONIC, &sub_finish);
    sub_elapsed += (sub_finish.tv_sec - sub_start.tv_sec);
    sub_elapsed += (sub_finish.tv_nsec - sub_start.tv_nsec) / 1000000000.0;*/
  }
  /*clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  std::cout<<"Backtrace took "<<elapsed<<" seconds"<<std::endl;
  std::cout<<"Sub took "<<sub_elapsed<<" seconds"<<std::endl;
  std::cout<<"Duplicates: "<<duplicates<<std::endl;*/
  
  // Print alignment results list
  //for (std::list<AlignmentResult>::iterator it = alignments.begin(); it != alignments.end(); ++it) {
  for (std::set<AlignmentResult, AlignmentResultComp>::iterator it = alignments.begin(); it != alignments.end(); ++it) {
    PrintAlignment((*it).alignment, query_name, (*it).score);
  }
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: ./smithwatermanreference <REF SEQ FASTA FILE> <QUERY SEQ FASTA FILE>" << std::endl;
    exit(1);
  }
  
  // Parse the reference file
  std::vector<std::vector<std::string> > ref_descrips;
  std::vector<char*> ref_seqs;
  std::vector<int> ref_lengths;
  std::string ref_file(argv[1]);
  ParseFastaFile(ref_file, &ref_descrips, &ref_seqs, &ref_lengths);
  std::map<std::string, int> ref_names;
  for (int i = 0; i < ref_descrips.size(); i++) {
    ref_names[ref_descrips[i][REF_NAME_FIELD]] = i;
  }
  
  /*for (int i = 0; i < ref_descrips.size(); i++) {
    std::cout<<"Ref name: "<<ref_names[ref_descrips[i][REF_NAME_FIELD]]<<" "
             <<"Ref length: "<<ref_lengths[i]<<std::endl;
  }*/
     
  
  // Parse the query file
  std::vector<std::vector<std::string> > query_descrips;
  std::vector<char*> query_seqs;
  std::vector<int> query_lengths;
  std::string query_file(argv[2]);
  ParseFastaFile(query_file, &query_descrips, &query_seqs, &query_lengths);
  
  SwAffineGapParams params("2 -2 -2 -2 2 -2 -2 2 -2 2 -2 -1");
  for (int i = 0; i < query_seqs.size(); i++) {
    /*std::cout<<"Query name: "<<query_descrips[i][QUERY_NAME_FIELD]<<" "
             <<"Query length: "<<query_lengths[i]<<" "
             <<"Query ref: "<<query_descrips[i][QUERY_REF_FIELD]<<" "
             <<"Query start: "<<String2Type<long long int>(query_descrips[i][QUERY_START_FIELD])<<" "
             <<"Query end: "<<String2Type<long long int>(query_descrips[i][QUERY_END_FIELD])<<" "
             <<"Query ref length: "<<String2Type<long long int>(query_descrips[i][QUERY_END_FIELD]) - String2Type<long long int>(query_descrips[i][QUERY_START_FIELD])<<" "
             <<"Query threshold: "<<query_descrips[i][QUERY_THRESHOLD_FIELD]<<std::endl;*/
  
    Align(query_descrips[i][QUERY_NAME_FIELD],
          ref_seqs[ref_names[query_descrips[i][QUERY_REF_FIELD]]],
          query_seqs[i],
          String2Type<long long int>(query_descrips[i][QUERY_END_FIELD]) - String2Type<long long int>(query_descrips[i][QUERY_START_FIELD]),
          query_lengths[i],
          String2Type<long long int>(query_descrips[i][QUERY_START_FIELD]) - 1,
          String2Type<int>(query_descrips[i][QUERY_THRESHOLD_FIELD]),
          params);
  }
  std::cout<<"END"<<std::endl;
}
  