#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <set>
#include <stdlib.h>
#include "fasta.h"

// Nucleotide character definitions
#define T_NT 0
#define C_NT 1
#define A_NT 2
#define G_NT 3
#define N_NT -1
typedef int NtInt;
#define GAP '-'

// Converts a nucleotide char to nucleotide integer, accepting
//   both lowercase and uppercase.
inline NtInt NtChar2Int (char nt) {
  switch(nt) {
    case 't':
    case 'T': return T_NT;
    case 'c':
    case 'C': return C_NT;
    case 'a':
    case 'A': return A_NT;
    case 'g':
    case 'G': return G_NT;
    case 'n':
    case 'N': return N_NT;
    default:  std::cout<<"Bad Nt char: "<<nt<<" "<<(int)nt<<std::endl;
              assert(false);
  }
}

// Data structure holding affine gap penalty scoring scheme parameters
#define SW_PARAMS_BUF_LENGTH 12
class SwAffineGapParams {
  public:
    SwAffineGapParams() {};
    
    SwAffineGapParams(int sub_mat[][4], int gap_open, int gap_extend) {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          sub_mat_[i][j] = sub_mat[i][j];
        }
      }
      gap_open_ = gap_open;
      gap_extend_ = gap_extend;
    };
    
    SwAffineGapParams(std::string s) {
      std::istringstream iss(s);
      iss.exceptions(std::ios::failbit);
      iss >> sub_mat_[A_NT][A_NT];
      iss >> sub_mat_[A_NT][C_NT];
      iss >> sub_mat_[A_NT][G_NT];
      iss >> sub_mat_[A_NT][T_NT];
      iss >> sub_mat_[C_NT][C_NT];
      iss >> sub_mat_[C_NT][G_NT];
      iss >> sub_mat_[C_NT][T_NT];
      iss >> sub_mat_[G_NT][G_NT];
      iss >> sub_mat_[G_NT][T_NT];
      iss >> sub_mat_[T_NT][T_NT];
      iss >> gap_open_;
      iss >> gap_extend_;
      
      // Fill other half of matrix
      sub_mat_[C_NT][A_NT] = sub_mat_[A_NT][C_NT];
      sub_mat_[G_NT][A_NT] = sub_mat_[A_NT][G_NT];
      sub_mat_[G_NT][C_NT] = sub_mat_[C_NT][G_NT];
      sub_mat_[T_NT][A_NT] = sub_mat_[A_NT][T_NT];
      sub_mat_[T_NT][C_NT] = sub_mat_[C_NT][T_NT];
      sub_mat_[T_NT][G_NT] = sub_mat_[G_NT][T_NT];
    };
    
    ~SwAffineGapParams() {};
    
    void GetSubMat(int** sub_mat) {
      for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
          sub_mat[i][j] = sub_mat_[i][j];
        }
      }
    };
    
    int GetGapOpen() {
      return gap_open_;
    };
    
    int GetGapExtend() {
      return gap_extend_;
    };
    
    // Check if substitution matrix is symmetric
    bool IsValid() {
      for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
          if (sub_mat_[i][j] != sub_mat_[j][i]) {
            return false;
          }
        }
      }
      
      return true;
    };
    
    // Format params as a string
    std::string ToString() {
      std::stringstream ss;
      
      ss << sub_mat_[A_NT][A_NT] << " " << sub_mat_[A_NT][C_NT] << " " << sub_mat_[A_NT][G_NT] << " " 
         << sub_mat_[A_NT][T_NT] << " " << sub_mat_[C_NT][C_NT] << " " << sub_mat_[C_NT][G_NT] << " " 
         << sub_mat_[C_NT][T_NT] << " " << sub_mat_[G_NT][G_NT] << " " << sub_mat_[G_NT][T_NT] << " " 
         << sub_mat_[T_NT][T_NT] << " " << gap_open_ << " " << gap_extend_;
      return ss.str();
    };
    
    // Allocate and store params in the buffer and get the buffer length
    int* ToBuf(int* buf_len) {
      int* buf = new int[SW_PARAMS_BUF_LENGTH];
      buf[0] = sub_mat_[A_NT][A_NT];
      buf[1] = sub_mat_[A_NT][C_NT];
      buf[2] = sub_mat_[A_NT][G_NT];
      buf[3] = sub_mat_[A_NT][T_NT];
      buf[4] = sub_mat_[C_NT][C_NT];
      buf[5] = sub_mat_[C_NT][G_NT];
      buf[6] = sub_mat_[C_NT][T_NT];
      buf[7] = sub_mat_[G_NT][G_NT];
      buf[8] = sub_mat_[G_NT][T_NT];
      buf[9] = sub_mat_[T_NT][T_NT];
      buf[10] = gap_open_;
      buf[11] = gap_extend_;
      
      *buf_len = SW_PARAMS_BUF_LENGTH * sizeof(int); // 4 bytes per int
      
      return buf;
    };
    
  private:
    int sub_mat_[4][4];
    int gap_open_;
    int gap_extend_;
};


class Alignment {
  public :
    Alignment() {
      ref_str_ = "";
      query_str_ = "";
      ref_offset_ = 0;
      query_offset_ = 0;
    };
    Alignment(long long int ref_offset, long long int query_offset) {
      ref_str_ = "";
      query_str_ = "";
      ref_offset_ = ref_offset;
      query_offset_ = query_offset;
    }
    ~Alignment() {};
    
    std::string ToString() const {
      long long int ref_length = GetRefLength();
      long long int query_length = GetQueryLength();
      
      std::stringstream ss;

      ss << ref_offset_ << ":" << ref_offset_ + ref_length << "\n"
         << ref_str_ << "\n"
         << query_str_ << "\n"
         << query_offset_ << ":" << query_offset_ + query_length << std::endl;

      return ss.str();
    };

    // Alignments are built backwards, so we prepend to the beginning of
    //   the alignment, rather than extend from the end of the alignment.
    void Prepend(char ref_nt, char query_nt) {      
      if (ref_nt != GAP) {
        ref_offset_--;
      }

      if (query_nt != GAP) {
        query_offset_--;
      }

      ref_str_.insert(0, 1, ref_nt);
      query_str_.insert(0, 1, query_nt);
    };
    
    // Trim the alignment to end at the highest score
    void TrimEnd(SwAffineGapParams params) {
      int** sub_mat = new int*[4];
      for (int i = 0; i < 4; i++) {
        sub_mat[i] = new int[4];
      }
      params.GetSubMat(sub_mat);
      int gap_open = params.GetGapOpen();
      int gap_extend = params.GetGapExtend();
      
      // Find index with highest score
      int max_score = 0;
      int max_index = 0;
      int cur_score = 0;
      bool gap = false;
      for (int i = 0; i < ref_str_.length(); i++) {
        if (ref_str_[i] == GAP || query_str_[i] == GAP) {
          if (!gap) {
            cur_score += gap_open;
          } else {
            cur_score += gap_extend;
          }
          gap = true;
        } else {
          cur_score += sub_mat[NtChar2Int(ref_str_[i])][NtChar2Int(query_str_[i])];
          gap = false;
        }
        
        if (cur_score >= max_score) {
          max_score = cur_score;
          max_index = i;
        }
      }
      
      for (int i = 0; i < 4; i++) {
        delete[] sub_mat[i];
      }
      delete[] sub_mat;
      
      ref_str_ = ref_str_.substr(0, max_index + 1);
      query_str_ = query_str_.substr(0, max_index + 1);
    };
    
    // Compute length of the alignment
    int GetLength() const {
      return ref_str_.length(); 
    };
    
    long long int GetRefLength() const {
      long long int ref_length = 0;
      for (int i = 0; i < ref_str_.size(); i++) {
        if (ref_str_[i] != GAP) {
          ref_length++;
        }
      }
      return ref_length;
    };
    
    long long int GetQueryLength() const {
      long long int query_length = 0;
      for (int i = 0; i < query_str_.size(); i++) {
        if (query_str_[i] != GAP) {
          query_length++;
        }
      }
      return query_length;
    };
    
    long long int GetRefOffset() const {
      return ref_offset_;
    };
    
    long long int GetQueryOffset() const {
      return query_offset_;
    };
    
    int ComputeScore(SwAffineGapParams params) const {
      int** sub_mat = new int*[4];
      for (int i = 0; i < 4; i++) {
        sub_mat[i] = new int[4];
      }
      params.GetSubMat(sub_mat);
      int gap_open = params.GetGapOpen();
      int gap_extend = params.GetGapExtend();
      
      int score = 0;
      bool gap = false;
      for (int i = 0; i < ref_str_.length(); i++) {
        if (ref_str_[i] == GAP || query_str_[i] == GAP) {
          if (!gap) {
            score += gap_open;
          } else {
            score += gap_extend;
          }
          gap = true;
        } else {
          score += sub_mat[NtChar2Int(ref_str_[i])][NtChar2Int(query_str_[i])];
          gap = false;
        }
        //std::cout << ref_str_[i] << " " << query_str_[i] << " " << score << std::endl;
      }

      for (int i = 0; i < 4; i++) {
        delete[] sub_mat[i];
      }
      delete[] sub_mat;
          
      return score;
    };

    bool operator< (const Alignment& a) const {
      return ref_offset_ < a.GetRefOffset();
    };

  private :
    std::string ref_str_;
    std::string query_str_;
    long long int ref_offset_;
    long long int query_offset_;
};

// Data structure representing an individual DP matrix cell
struct Cell {
  int ref_index;
  int query_index;
  int score;

  bool operator==(const Cell& rhs) {
    return ref_index == rhs.ref_index && query_index == rhs.query_index;
  }
};

// Individual DP matrix comparison (descending order by ref index)
struct CellComp {
  bool operator() (const Cell& lhs, const Cell& rhs) const {
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

//enum AlnOp {ZERO_OP, MATCH_OP, INSERT_OP, DELETE_OP};
enum AlnOp {Z, M, I, D};

std::set<Alignment> Align(char* query_seq, long long int query_len, char* ref_seq, long long int ref_len,
                          SwAffineGapParams params, int threshold) {
  struct timespec start, finish;
  double elapsed;
                          
  long long int dir_matrix_query_dim = (long long int) ceil(((double) (query_len + 1)) / 4);
  unsigned char** dir_h_matrix = new unsigned char*[ref_len + 1];
  unsigned char** dir_m_matrix = new unsigned char*[ref_len + 1];
  unsigned char** dir_i_matrix = new unsigned char*[ref_len + 1];
  unsigned char** dir_d_matrix = new unsigned char*[ref_len + 1];
  for (int i = 0; i < ref_len + 1; i++) {
    dir_h_matrix[i] = new unsigned char[dir_matrix_query_dim];
    dir_m_matrix[i] = new unsigned char[dir_matrix_query_dim];
    dir_i_matrix[i] = new unsigned char[dir_matrix_query_dim];
    dir_d_matrix[i] = new unsigned char[dir_matrix_query_dim];    
    for (int j = 0; j < dir_matrix_query_dim; j++) {
      dir_h_matrix[i][j] = 0;
      dir_m_matrix[i][j] = 0;
      dir_i_matrix[i][j] = 0;
      dir_d_matrix[i][j] = 0;
    }
  }
  int* h_matrix_wr = new int[query_len + 1];
  int* m_matrix_wr = new int[query_len + 1];
  int* i_matrix_wr = new int[query_len + 1];
  int* d_matrix_wr = new int[query_len + 1];
  int* h_matrix_rd = new int[query_len + 1];
  int* m_matrix_rd = new int[query_len + 1];
  int* i_matrix_rd = new int[query_len + 1];
  int* d_matrix_rd = new int[query_len + 1];
  for (int i = 0; i < query_len + 1; i++) {
    h_matrix_rd[i] = 0;
    m_matrix_rd[i] = 0;
    i_matrix_rd[i] = 0;
    d_matrix_rd[i] = 0;
    h_matrix_wr[i] = 0;
    m_matrix_wr[i] = 0;
    i_matrix_wr[i] = 0;
    d_matrix_wr[i] = 0;
  }
  
  int** sub_mat = new int*[4];
  for (int i = 0; i < 4; i++) {
    sub_mat[i] = new int[4];
  }
  params.GetSubMat(sub_mat);
  int gap_open = params.GetGapOpen();
  int gap_extend = params.GetGapExtend();  
  
  //clock_gettime(CLOCK_MONOTONIC, &start);
  std::set<Cell, CellComp> highscore_cells;
  /*std::cout << "\t";
  for (int i = 0; i < query_len; i++) {
    std::cout << query_seq[i] << " " << i << "\t";
  }
  std::cout << std::endl;*/
  int max_score = 0; // TEST
  for (int i = 1; i < ref_len + 1; i++) {
    //std::cout << ref_seq[i-1] << " " << i-1 << "\t";
    int* m_matrix_tmp = m_matrix_wr;
    int* h_matrix_tmp = h_matrix_wr;
    int* i_matrix_tmp = i_matrix_wr;
    int* d_matrix_tmp = d_matrix_wr;
    m_matrix_wr = m_matrix_rd;
    h_matrix_wr = h_matrix_rd;
    i_matrix_wr = i_matrix_rd;
    d_matrix_wr = d_matrix_rd;
    m_matrix_rd = m_matrix_tmp;
    h_matrix_rd = h_matrix_tmp;
    i_matrix_rd = i_matrix_tmp;
    d_matrix_rd = d_matrix_tmp;
    for (int j = 1; j < query_len + 1; j++) {
      NtInt ref_nt = NtChar2Int(ref_seq[i-1]);
      NtInt query_nt = NtChar2Int(query_seq[j-1]);
      
      int match;
      if (ref_nt == N_NT || query_nt == N_NT) {
        match = -2147483648; // Force N's to align with gaps
      } else {
        match = sub_mat[query_nt][ref_nt];
      }
      if (m_matrix_rd[j-1] > i_matrix_rd[j-1] && m_matrix_rd[j-1] > d_matrix_rd[j-1]) {
        m_matrix_wr[j] = m_matrix_rd[j-1] + match;
        dir_m_matrix[i][j/4] = (dir_m_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (M << (2 * (j % 4))));
      } else if (i_matrix_rd[j-1] > d_matrix_rd[j-1]) {
        m_matrix_wr[j] = i_matrix_rd[j-1] + match;
        dir_m_matrix[i][j/4] = (dir_m_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (I << (2 * (j % 4))));
      } else {
        m_matrix_wr[j] = d_matrix_rd[j-1] + match;
        dir_m_matrix[i][j/4] = (dir_m_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (D << (2 * (j % 4))));
      }
      if (m_matrix_wr[j] < 0) {
        m_matrix_wr[j] = 0;
        dir_m_matrix[i][j/4] = (dir_m_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (Z << (2 * (j % 4))));
      }

      int ins_open   = m_matrix_rd[j] + gap_open;
      int ins_extend = i_matrix_rd[j] + gap_extend;
      int del_open   = m_matrix_wr[j-1] + gap_open;
      int del_extend = d_matrix_wr[j-1] + gap_extend;
      
      i_matrix_wr[j] =      (ins_open > ins_extend) ? ins_open : ins_extend;
      unsigned char dir_i = (ins_open > ins_extend) ? M : I;
      dir_i_matrix[i][j/4] = (dir_i_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (dir_i << (2 * (j % 4))));
      d_matrix_wr[j] =      (del_open > del_extend) ? del_open : del_extend;
      unsigned char dir_d = (del_open > del_extend) ? M : D;
      dir_d_matrix[i][j/4] = (dir_d_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (dir_d << (2 * (j % 4))));
     
      int max1 = m_matrix_wr[j] > i_matrix_wr[j] ? m_matrix_wr[j] : i_matrix_wr[j];
      unsigned char dir1 = m_matrix_wr[j] > i_matrix_wr[j] ? M : I;
      int max2 = d_matrix_wr[j] > 0 ? d_matrix_wr[j] : 0;
      unsigned char dir2 = d_matrix_wr[j] > 0 ? D : Z;
      h_matrix_wr[j] = max1 > max2 ? max1 : max2; 
      unsigned char dir_h = max1 > max2 ? dir1 : dir2;
      dir_h_matrix[i][j/4] = (dir_h_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (dir_h << (2 * (j % 4))));  
      
      max_score = h_matrix_wr[j] > max_score ? h_matrix_wr[j] : max_score;
 
      // Record high-scoring cells
      if (h_matrix_wr[j] >= threshold) {
        Cell hsc;
        hsc.ref_index = i;
        hsc.query_index = j;
        hsc.score = h_matrix_wr[j];
        highscore_cells.insert(hsc);
      }
      
      //std::cout << h_matrix_wr[j];
      //std::cout << "\t";
    }
    //std::cout << std::endl;
  }
  //clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  std::cout << ref_len << " x " << query_len << " DP matrices computed in " << elapsed << " seconds." << std::endl;
  std::cout << "Max score: " << max_score << std::endl;
  
  // Perform backtraces
  //clock_gettime(CLOCK_MONOTONIC, &start);
  std::set<Alignment> alignments;
  for (std::set<Cell, CellComp>::iterator it = highscore_cells.begin(); it != highscore_cells.end(); ++it) {
    int query_index = (*it).query_index;
    int ref_index = (*it).ref_index;
   
    // Build the alignment
    Alignment aln(ref_index, query_index);
    //std::cout << (*it).score << std::endl;
    
    int cur_matrix = (dir_h_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3;
    unsigned char** dir_matrix;
    switch(cur_matrix) {
      case M : dir_matrix = dir_m_matrix;
               break;
      case I : dir_matrix = dir_i_matrix;
               break;
      case D : dir_matrix = dir_d_matrix;
               break;
    }
    //unsigned char** dir_matrix = dir_m_matrix;
    //int cur_matrix = M;
    //while (((dir_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3) != Z) {
    while (((dir_h_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3) != Z) {
    //while (h_matrix[ref_index][query_index] != 0) {
      // Remove visited cells from the high score cell list
      if (!(query_index == (*it).query_index && ref_index == (*it).ref_index)) {
        Cell hsc;
        hsc.query_index = query_index;
        hsc.ref_index = ref_index;
        highscore_cells.erase(hsc);
      }
      
      switch(cur_matrix) {
        case M:
          aln.Prepend(ref_seq[ref_index-1], query_seq[query_index-1]);
          cur_matrix = (dir_m_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3;
          switch(cur_matrix) {
            case M:  dir_matrix = dir_m_matrix;
                     break;
            case I:  dir_matrix = dir_i_matrix;
                     break;
            case D:  dir_matrix = dir_d_matrix;
                     break;
            default: assert(false);
          }
          query_index--;
          ref_index--;
          break;
          
        case I:
          aln.Prepend(ref_seq[ref_index-1], GAP);
          cur_matrix = (dir_i_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3;
          switch(cur_matrix) {
            case M:  dir_matrix = dir_m_matrix;
                     break;
            case I:  dir_matrix = dir_i_matrix;
                     break;
            default: assert(false);
          }
          ref_index--;
          break;
        
        case D:
          aln.Prepend(GAP, query_seq[query_index-1]);
          cur_matrix = (dir_d_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3;
          switch(cur_matrix) {
            case M:  dir_matrix = dir_m_matrix;
                     break;
            case D:  dir_matrix = dir_d_matrix;
                     break;
            default: assert(false);
          }
          query_index--;
          break;
        
        default: assert(false);
      }
    }
    aln.TrimEnd(params);
    
    // TEST
    int aln_score = aln.ComputeScore(params);
    /*if (h_matrix[aln.GetRefLength() + aln.GetRefOffset()][aln.GetQueryLength() + aln.GetQueryOffset()] != aln_score) {
      std::cout << h_matrix[aln.GetRefLength() + aln.GetRefOffset()][aln.GetQueryLength() + aln.GetQueryOffset()] << " " << aln_score << std::endl;
      std::cout << aln.ToString() << std::endl;
    }
    assert(h_matrix[aln.GetRefLength() + aln.GetRefOffset()][aln.GetQueryLength() + aln.GetQueryOffset()] == aln_score);*/
    
    std::set<Alignment>::iterator aln_it = alignments.find(aln);
    if (aln_it != alignments.end()) {
      // Filter out same start-index duplicate alignments, pick the highest scoring, longest duplicated alignment
      int aln_it_score = (*aln_it).ComputeScore(params);
      if ((aln_it_score < aln_score) || 
          (aln_it_score == aln_score && (*aln_it).GetLength() < aln.GetLength())) {
        alignments.erase(aln_it);
        alignments.insert(aln);
      }
    } else {
      alignments.insert(aln);
    }
  }
  //clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  std::cout << "Computed backtrace of " << alignments.size() << " alignments in " << elapsed << " seconds." << std::endl;
   
  // Clean up memory  
  for (int i = 0; i < ref_len + 1; i++) {
    delete[] dir_m_matrix[i];
    delete[] dir_i_matrix[i];
    delete[] dir_d_matrix[i];
  }
  delete[] dir_m_matrix; 
  delete[] dir_i_matrix; 
  delete[] dir_d_matrix;
  delete[] h_matrix_wr;
  delete[] m_matrix_wr; 
  delete[] i_matrix_wr;
  delete[] d_matrix_wr;
  delete[] h_matrix_rd;
  delete[] m_matrix_rd;
  delete[] i_matrix_rd;
  delete[] d_matrix_rd;    
  for (int i = 0; i < 4; i++) {
    delete[] sub_mat[i];
  }
  delete[] sub_mat;          
  
  return alignments;
}

int main (int argc, char *argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: ./smithwatermanreference <REF SEQ FASTA FILE> <QUERY SEQ FASTA FILE> <THRESHOLD>" << std::endl;
    return 1;
  }
  
  // Parse the reference file
  std::vector<std::vector<std::string> > ref_descrips;
  std::vector<char*> ref_seqs;
  std::vector<long long int> ref_lengths;
  std::vector<long long int> ref_fileposs;
  std::string ref_file(argv[1]);
  ParseFastaFile(ref_file, &ref_descrips, &ref_seqs, &ref_lengths, &ref_fileposs);
  assert(ref_descrips.size() == ref_seqs.size());
  assert(ref_seqs.size() == ref_lengths.size());
  assert(ref_lengths.size() == ref_fileposs.size());
  
  // Parse the query file
  std::vector<std::vector<std::string> > query_descrips;
  std::vector<char*> query_seqs;
  std::vector<long long int> query_lengths;
  std::vector<long long int> query_fileposs;
  std::string query_file(argv[2]);
  ParseFastaFile(query_file, &query_descrips, &query_seqs, &query_lengths, &query_fileposs);
  assert(query_descrips.size() == query_seqs.size());
  assert(query_seqs.size() == query_lengths.size());
  assert(query_lengths.size() == query_fileposs.size());
  
  SwAffineGapParams params("91 -90 -25 -100 100 -100 -25 100 -90 91 -400 -30"); // HOXD55
  int threshold = atoi(argv[3]);
  for (int i = 0; i < query_seqs.size(); i++) {
    for (int j = 0; j < ref_seqs.size(); j++) {
      std::set<Alignment> aln_res = Align(query_seqs[i], query_lengths[i], ref_seqs[j], ref_lengths[j],
                                          params, threshold);
      for (std::set<Alignment>::iterator it = aln_res.begin(); it != aln_res.end(); it++) {
        Alignment aln = *it;
        std::cout << "Ref: hg19\n"          // TEMPORARY HACK
                  << "Chr: chr1\n"
                  << "Query: hg19_zCNE1301\n"
                  << "Score: " << aln.ComputeScore(params)
                  << std::endl;
        std::cout << aln.ToString() << std::endl;
      }
    }
  }
}
      
