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
enum AlnOp {Z, V, E, F};

std::set<Alignment> Align(char* query_seq, long long int query_len, char* ref_seq, long long int ref_len,
                          SwAffineGapParams params, int threshold) {
  struct timespec start, finish;
  double elapsed;
                          
  long long int dir_matrix_query_dim = (long long int) ceil(((double) (query_len + 1)) / 4);
  /*unsigned char** dir_matrix = new unsigned char*[ref_len + 1];
  for (int i = 0; i < ref_len + 1; i++) {
    dir_matrix[i] = new unsigned char[dir_matrix_query_dim];
    for (int j = 0; j < dir_matrix_query_dim; j++) {
      dir_matrix[i][j] = 0;
    }
  }*/
  unsigned char** dir_v_matrix = new unsigned char*[ref_len + 1];
  unsigned char** dir_e_matrix = new unsigned char*[ref_len + 1];
  unsigned char** dir_f_matrix = new unsigned char*[ref_len + 1];
  for (int i = 0; i < ref_len + 1; i++) {
    dir_v_matrix[i] = new unsigned char[dir_matrix_query_dim];
    dir_e_matrix[i] = new unsigned char[dir_matrix_query_dim];
    dir_f_matrix[i] = new unsigned char[dir_matrix_query_dim];    
    for (int j = 0; j < dir_matrix_query_dim; j++) {
      dir_v_matrix[i][j] = 0;
      dir_e_matrix[i][j] = 0;
      dir_f_matrix[i][j] = 0;
    }
  }
  int* v_matrix_wr = new int[query_len + 1];
  int* e_matrix_wr = new int[query_len + 1];
  int* f_matrix_wr = new int[query_len + 1];
  int* v_matrix_rd = new int[query_len + 1];
  int* e_matrix_rd = new int[query_len + 1];
  int* f_matrix_rd = new int[query_len + 1];
  for (int i = 0; i < query_len + 1; i++) {
    v_matrix_rd[i] = 0;
    e_matrix_rd[i] = 0;
    f_matrix_rd[i] = 0;
    v_matrix_wr[i] = 0;
    e_matrix_wr[i] = 0;
    f_matrix_wr[i] = 0;
  }
  
  
  int** sub_mat = new int*[4];
  for (int i = 0; i < 4; i++) {
    sub_mat[i] = new int[4];
  }
  params.GetSubMat(sub_mat);
  int gap_open = params.GetGapOpen();
  int gap_extend = params.GetGapExtend();  
  
  clock_gettime(CLOCK_MONOTONIC, &start);
  std::set<Cell, CellComp> highscore_cells;
  std::cout << "\t";
  for (int i = 0; i < query_len; i++) {
    std::cout << query_seq[i] << " " << i << "\t";
  }
  std::cout << std::endl;
  for (int i = 1; i < ref_len + 1; i++) {
    std::cout << ref_seq[i-1] << " " << i-1 << "\t";
    int* v_matrix_tmp = v_matrix_wr;
    int* e_matrix_tmp = e_matrix_wr;
    int* f_matrix_tmp = f_matrix_wr;
    v_matrix_wr = v_matrix_rd;
    e_matrix_wr = e_matrix_rd;
    f_matrix_wr = f_matrix_rd;
    v_matrix_rd = v_matrix_tmp;
    e_matrix_rd = e_matrix_tmp;
    f_matrix_rd = f_matrix_tmp;
    for (int j = 1; j < query_len + 1; j++) {
      NtInt ref_nt = NtChar2Int(ref_seq[i-1]);
      NtInt query_nt = NtChar2Int(query_seq[j-1]);
      
      int match;
      //std::cout << v_matrix_rd[j] << "\t";
      if (ref_nt == N_NT || query_nt == N_NT) {
        match = -2147483648; // Force N's to align with gaps
      } else {
        match = v_matrix_rd[j-1] + sub_mat[query_nt][ref_nt];
        /*if (v_matrix_rd[j-1] == 452) {
          std::cout << "v_matrix_rd = 452 from " << "(" << i << ", " << j << ")" << std::endl;
        }*/
      }
      int ins_open   = v_matrix_rd[j] + gap_open;
      int ins_extend = e_matrix_rd[j] + gap_extend;
      int del_open   = v_matrix_wr[j-1] + gap_open;
      int del_extend = f_matrix_wr[j-1] + gap_extend;
      
      unsigned char e_dir;
      if (ins_open > ins_extend) {
        e_matrix_wr[j] = ins_open;
        dir_e_matrix[i][j/4] = (dir_e_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (V << (2 * (j % 4))));
        e_dir = V;
      } else {
        e_matrix_wr[j] = ins_extend;
        dir_e_matrix[i][j/4] = (dir_e_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (E << (2 * (j % 4))));
        e_dir = E;
      }
      unsigned char f_dir;
      if (del_open > del_extend) {
        f_matrix_wr[j] = del_open;
        dir_f_matrix[i][j/4] = (dir_f_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (V << (2 * (j % 4))));
        f_dir = V;
      } else {
        f_matrix_wr[j] = del_extend;
        dir_f_matrix[i][j/4] = (dir_f_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (F << (2 * (j % 4))));
        f_dir = F;
      }
      /*e_matrix_wr[j] = (ins_open > ins_extend) ? ins_open : ins_extend;
      f_matrix_wr[j] = (del_open > del_extend) ? del_open : del_extend;*/
      
      int max1 = e_matrix_wr[j];
      //unsigned char dir1 = INSERT_OP;
      unsigned char dir1 = E;
      if (match > max1) {
        max1 = match;
        //dir1 = MATCH_OP;
        dir1 = V;
      }
      int max2 = 0;
      //unsigned char dir2 = ZERO_OP;
      unsigned char dir2 = Z;
      if (f_matrix_wr[j] > 0) {
        max2 = f_matrix_wr[j];
        //dir2 = DELETE_OP;
        dir2 = F;
      }
      
      unsigned char v_dir;
      if (max1 > max2) {
        v_matrix_wr[j] = max1;
        //dir_matrix[i][j/4] = (dir_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (dir1 << (2 * (j % 4))));
        dir_v_matrix[i][j/4] = (dir_v_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (dir1 << (2 * (j % 4))));
        v_dir = dir1;
        /*if (v_matrix_wr[j] == 427) {
          std::cout << "Max1 > Max2 " << (int) v_dir << "(" << i << ", " << j << ")" << std::endl;
        }*/
      } else {
        v_matrix_wr[j] = max2;
        //dir_matrix[i][j/4] = (dir_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (dir2 << (2 * (j % 4))));
        dir_v_matrix[i][j/4] = (dir_v_matrix[i][j/4] & ~(0x3 << (2 * (j % 4))) | (dir2 << (2 * (j % 4))));
        v_dir = dir2;
      }
      
      // Record high-scoring cells
      if (v_matrix_wr[j] >= threshold) {
        Cell hsc;
        hsc.ref_index = i;
        hsc.query_index = j;
        hsc.score = v_matrix_wr[j];
        highscore_cells.insert(hsc);
      }
      
      std::cout << v_matrix_wr[j];
      /*switch(v_dir) {
        case ZERO_OP: std::cout << "Z\t"; break;
        case INSERT_OP: std::cout << "I\t"; break;
        case DELETE_OP: std::cout << "D\t"; break;
        case MATCH_OP: std::cout << "M\t"; break;
        default: assert(false);
      }*/
      /*if (v_matrix_wr[j] == 427) {
        std::cout << (int) v_dir << std::endl;
      }*/
      switch(v_dir) {
        case Z: std::cout << "Z"; break;
        case V: std::cout << "V"; break;
        case E: std::cout << "E"; break;
        case F: std::cout << "F"; break;
        default: assert(false);
      }
      switch(e_dir) {
        case Z: std::cout << "Z"; break;
        case V: std::cout << "V"; break;
        case E: std::cout << "E"; break;
        default: assert(false);
      }
      switch(f_dir) {
        case Z: std::cout << "Z"; break;
        case V: std::cout << "V"; break;
        case F: std::cout << "F"; break;
        default: assert(false);
      }
      std::cout << "\t";
    }
    std::cout << std::endl;
  }
  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  std::cout << ref_len << " x " << query_len << " DP matrices computed in " << elapsed << " seconds." << std::endl;
  
  // Perform backtraces
  clock_gettime(CLOCK_MONOTONIC, &start);
  std::set<Alignment> alignments;
  for (std::set<Cell, CellComp>::iterator it = highscore_cells.begin(); it != highscore_cells.end(); ++it) {
    int query_index = (*it).query_index;
    int ref_index = (*it).ref_index;
   
    // Build the alignment
    Alignment aln(ref_index, query_index);
    std::cout << (*it).score << std::endl;
    
    unsigned char** dir_matrix = dir_v_matrix;
    int cur_matrix = V;
    //while (((dir_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3) != ZERO_OP) {
    while (((dir_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3) != Z) {
      // Remove visited cells from the high score cell list
      if (!(query_index == (*it).query_index && ref_index == (*it).ref_index)) {
        Cell hsc;
        hsc.query_index = query_index;
        hsc.ref_index = ref_index;
        highscore_cells.erase(hsc);
      }
      
      /*switch((dir_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3) {
        case MATCH_OP:  aln.Prepend(ref_seq[ref_index-1], query_seq[query_index-1]);
                        query_index--;
                        ref_index--;
                        break;
        case INSERT_OP: aln.Prepend(ref_seq[ref_index-1], GAP);
                        ref_index--;
                        break;
        case DELETE_OP: aln.Prepend(GAP, query_seq[query_index-1]);
                        query_index--;
                        break;
        default:        assert(false);
      }*/
      switch(cur_matrix) {
        case V:
          aln.Prepend(ref_seq[ref_index-1], query_seq[query_index-1]);
          cur_matrix = (dir_v_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3;
          std::cout << ref_seq[ref_index-1] << " " << query_seq[query_index-1] << " " << cur_matrix << std::endl;
          switch(cur_matrix) {
            case V:  dir_matrix = dir_v_matrix;
                     break;
            case E:  dir_matrix = dir_e_matrix;
                     break;
            case F:  dir_matrix = dir_f_matrix;
                     break;
            //default: assert(false);
          }
          query_index--;
          ref_index--;
          break;
          
        case E:
          aln.Prepend(ref_seq[ref_index-1], GAP);
          cur_matrix = (dir_e_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3;
          std::cout << ref_seq[ref_index-1] << " " << GAP << " " << cur_matrix << std::endl;
          switch(cur_matrix) {
            case V:  dir_matrix = dir_v_matrix;
                     break;
            case E:  dir_matrix = dir_e_matrix;
                     break;
            //default: assert(false);
          }
          ref_index--;
          break;
        
        case F:
          aln.Prepend(GAP, query_seq[query_index-1]);
          cur_matrix = (dir_f_matrix[ref_index][query_index / 4] >> (2 * (query_index % 4))) & 0x3;
          std::cout << GAP << " " << query_seq[query_index-1] << " " << cur_matrix << std::endl;
          switch(cur_matrix) {
            case V:  dir_matrix = dir_v_matrix;
                     break;
            case F:  dir_matrix = dir_f_matrix;
                     break;
            //default: assert(false);
          }
          query_index--;
          break;
        
        default: assert(false);
      }
    }
    //std::cout << "Before Trim: " << aln.ComputeScore(params) << std::endl;
    aln.TrimEnd(params);
    //std::cout << "After Trim: " << aln.ComputeScore(params) << std::endl;
    
    std::set<Alignment>::iterator aln_it = alignments.find(aln);
    if (aln_it != alignments.end()) {
      // Filter out same start-index duplicate alignments, pick the highest scoring, longest duplicated alignment
      int aln_it_score = (*aln_it).ComputeScore(params);
      int aln_score = aln.ComputeScore(params);
      if ((aln_it_score < aln_score) || 
          (aln_it_score == aln_score && (*aln_it).GetLength() < aln.GetLength())) {
        alignments.erase(aln_it);
        alignments.insert(aln);
      }
    } else {
      alignments.insert(aln);
    }
  }
  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  std::cout << "Computed backtrace of " << alignments.size() << " alignments in " << elapsed << " seconds." << std::endl;
   
  // Clean up memory  
  for (int i = 0; i < ref_len + 1; i++) {
    //delete[] dir_matrix[i];
    delete[] dir_v_matrix[i];
    delete[] dir_e_matrix[i];
    delete[] dir_f_matrix[i];
  }
  //delete[] dir_matrix; 
  delete[] dir_v_matrix; 
  delete[] dir_e_matrix; 
  delete[] dir_f_matrix; 
  delete[] v_matrix_wr;
  delete[] e_matrix_wr;
  delete[] f_matrix_wr;
  delete[] v_matrix_rd;
  delete[] e_matrix_rd;
  delete[] f_matrix_rd;    
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
      
