//  File Name        : consttab.cpp
//  Description      : Constant table class
//
//  Revision History :
//      Albert Ng   May 13 2014     Initial Revision

#include "consttab.hpp"
#include "utils.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <assert.h>

void ConstTableEntry::dump(std::ostream& stream, int depth) {
  stream << pad(depth) << name_ << "\t";

  std::list<ConstData> print_list;
  std::list<int> depth_list;

  switch(datatype_) {
    case INT_DATA: 
      stream << "INT_DATA\t" << data_.int_data;
      assert(dimensions_ == NULL);
      break;

    case BOOL_DATA:
      stream << "BOOL_DATA\t" << data_.bool_data;
      assert(dimensions_ == NULL);
      break;

    case INT_MATRIX_DATA: 
      stream << "INT_MATRIX_DATA\t";
      assert(dimensions_->size() > 0);
      for (std::vector<int>::iterator it = dimensions_->begin(); it != dimensions_->end(); it++) {
        stream << *it << " ";
      }
      stream << '\t';

      print_list.push_front(data_);
      depth_list.push_front(0);
      while (print_list.empty() == false) {
        ConstData cur_data = print_list.front();
        print_list.pop_front();
        int cur_depth = depth_list.front();
        depth_list.pop_front();
        if (cur_depth != dimensions_->size() - 1) {
          for (std::vector<ConstData>::reverse_iterator rit = cur_data.matrix_data->rbegin(); 
               rit != cur_data.matrix_data->rend(); rit++) {
            print_list.push_front(*rit);
            depth_list.push_front(cur_depth + 1);
          }
        } else {
          for (std::vector<ConstData>::iterator it = cur_data.matrix_data->begin();
               it != cur_data.matrix_data->end(); it++) {
            stream << (*it).int_data << " ";
          }
        }
      }
      break;

    case BOOL_MATRIX_DATA:
      stream << "BOOL_MATRIX_DATA\t";
      assert(dimensions_->size() > 0);
      for (std::vector<int>::iterator it = dimensions_->begin(); it != dimensions_->end(); it++) {
        stream << *it << " ";
      }
      stream << '\t';

      print_list.push_front(data_);
      depth_list.push_front(0);
      while (print_list.empty() == false) {
        ConstData cur_data = print_list.front();
        print_list.pop_front();
        int cur_depth = depth_list.front();
        depth_list.pop_front();
        if (cur_depth != dimensions_->size() - 1) {
          for (std::vector<ConstData>::reverse_iterator rit = cur_data.matrix_data->rbegin(); 
               rit != cur_data.matrix_data->rend(); rit++) {
            print_list.push_front(*rit);
            depth_list.push_front(cur_depth + 1);
          }
        } else {
          for (std::vector<ConstData>::iterator it = cur_data.matrix_data->begin();
               it != cur_data.matrix_data->end(); it++) {
            stream << (*it).bool_data << " ";
          }
        }
      }
      break;

    default: break;
  }
  stream << std::endl;
}

bool ConstTable::AddEntry(ConstTableEntry* entry) {
  // Check for existing symbol with the same name
  for (std::list<ConstTableEntry*>::iterator it = table_.begin(); it != table_.end(); it++) {
    if ((*it)->get_name() == entry->get_name()) {
      return false;
    }
  }

  table_.push_back(entry);
  return true;
}

ConstTableEntry* ConstTable::GetEntry(std::string name) {
  for (std::list<ConstTableEntry*>::iterator it = table_.begin(); it != table_.end(); it++) {
    if ((*it)->get_name() == name) {
      return *it;
    }
  }

  return NULL;
}

void ConstTable::dump(std::ostream& stream, int depth) {
  stream << pad(depth) << "Const Table" << std::endl;
  for (std::list<ConstTableEntry*>::iterator it = table_.begin(); it != table_.end(); it++) {
    (*it)->dump(stream, depth+1);
  }
}

ConstTable const_table;
