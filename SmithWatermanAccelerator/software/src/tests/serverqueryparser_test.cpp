//  File Name        : serverqueryparser_test.cpp
//  Description      : Server Query Parser class test
//
//  Revision History :
//      Albert Ng   Oct 22 2013     Initial Revision
//

#include "serverqueryparser.h"
#include "picodrv_stub.h"
#include "threadqueue.h"
#include "def.h"
#include "queryseqmanager.h"
#include "refseqmanager.h"
#include "scoring.h"
#include <list>
#include <iostream>
#include <stdio.h>
#include <cstdlib>

int main(int argc, char *argv[]) {
  ServerQueryParser sqp(30000);
  ThreadQueue<AlignmentJob> alignment_job_queue;
  QuerySeqManager query_seq_manager;
  RefSeqManager ref_seq_manager;
  PicoDrv* pico_drivers;
  if (argc < 2) {
    fprintf(stderr, "Usage: ./serverqueryparser_test <REF SEQ FASTA FILE1> [<REF SEQ FASTA FILE2> ...]\n");
    exit(1);
  }

  // Set up pico drivers
  pico_drivers = new PicoDrv[NUM_FPGAS];
  for (int i = 0; i < NUM_FPGAS; i++) {
    pico_drivers[i].Init(NUM_ENGINES_PER_FPGA);
  } 

  // Set up ref seq manager
  ref_seq_manager.Init(pico_drivers);
  for (int i = 1; i < argc; i++) {
    std::string filename(argv[i]);
    ref_seq_manager.AddRef(filename);
  }

  while(true) {
    std::list<int> query_ids = sqp.ParseQueryGroup(&alignment_job_queue, &query_seq_manager, &ref_seq_manager);
    
    while (!alignment_job_queue.Empty()) {
      AlignmentJob job = alignment_job_queue.Pop();
      std::cout << "Query ID: " << job.query_id << " Ref ID: " << job.ref_id << " Ref Offset: " << job.ref_offset 
                << " Ref Length: " << job.ref_len << " Threshold: " << job.threshold << " Params: " << job.params.ToString() << std::endl;
      if (job.query_id != -1) {
        std::cout << query_seq_manager.GetQueryName(job.query_id) << std::endl;
        int query_len;
        char* query_seq = query_seq_manager.GetQuerySeq(job.query_id, &query_len);
        for (int i = 0; i < query_len; i++) {
          std::cout << query_seq[i];
        }
      }
      std::cout<<'\n'<<std::endl;
    }
  }
}
