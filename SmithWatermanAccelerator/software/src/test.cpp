#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
typedef int NtInt;
#define T_NT 0
#define C_NT 1
#define A_NT 2
#define G_NT 3
#define N_NT -1
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
  }
}
int main(void) {
	struct timespec start, finish;
	uint32_t out_buf[4096];
	std::string query_seq = "GCGGATCGTCTACCGCGACCTCAAGCCCGAGAACGTGCTGCTGGACAATGACGGT";
	int query_len = query_seq.size();
	int cur_index = 0;
	clock_gettime(CLOCK_MONOTONIC, &start);
	for (int i = 0; i < 5000000; i++) { 
		out_buf[cur_index + 0] = (uint32_t) 0;
		out_buf[cur_index + 1] = (uint32_t) 0;
		out_buf[cur_index + 2] = (uint32_t) 0;
		out_buf[cur_index + 3] = (uint32_t) 0;
    
		for (int j = 0; j < query_len; j++) {
			NtInt nt = NtChar2Int(query_seq[j]);
			if (query_seq[j] == 'N' || query_seq[j] == 'n') {
				nt = rand() % 4;
			}
			if (j % 16 == 0) {
				out_buf[cur_index + 4+j/16] = nt;
			} else {
				out_buf[cur_index + 4+j/16] += (nt << (2 * (j % 16)));
			}
		}
    
		cur_index += 0;
	}
	clock_gettime(CLOCK_MONOTONIC, &finish);
	double elapsed = (finish.tv_sec - start.tv_sec);
	elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
	std::cout << elapsed << " seconds" << std::endl;
}
