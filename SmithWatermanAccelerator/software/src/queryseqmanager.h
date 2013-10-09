//  File Name        : queryseqmanager.h
//  Description      : Query Sequence Manager definitions
//
//  Revision History :
//      Albert Ng   Oct 09 2013     Initial Revision 


#ifndef QUERYSEQMANAGER_H_
#define QUERYSEQMANAGER_H_

#include <pthread.h>
#include <map>

class QuerySeqManager {
  public:
    QuerySeqManager();
    ~QuerySeqManager();

  private:
    std::map<int, 


#endif // QUERYSEQMANAGER_H_
