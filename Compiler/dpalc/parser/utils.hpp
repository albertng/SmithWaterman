//  File Name        : utils.hpp
//  Description      : Useful utility functions
//
//  Revision History :
//      Albert Ng   Apr 17 2014     Initial Revision

#ifndef UTILS_H_
#define UTILS_H_

#include <string>

std::string pad(int);
void print_escaped_string(std::ostream& stream, char *str);
void print_token(std::ostream &stream, int token);
std::string token_to_string(int);


#endif // UTILS_H_
