#ifndef GUARD_my_string_lib_h
#define GUARD_my_string_lib_h

#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <map>

std::vector<std::string> split_string_to_words(const std::string &);
std::istream & fill_vector_with_lines(std::istream &, std::vector<std::string> &);
void print_vector_of_strings(const std::vector<std::string> &);
bool is_palindrome(const std::string &);

std::vector<std::string> extract_palindromes(std::vector<std::string> &);
std::list<std::string> extract_palindromes(std::list<std::string> &);

std::map<std::string, std::vector<int> > xref(std::istream &, std::vector<std::string> (const std::string &) = split_string_to_words);

#endif