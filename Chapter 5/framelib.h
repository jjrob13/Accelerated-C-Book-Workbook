#ifndef GUARD_framelib_h
#define GUARD_framelib_h

#include <vector>
#include <string>

std::vector<std::string> frame(const std::vector<std::string>&);
std::vector<std::string> horizontal_concatenation(const std::vector<std::string> &, const std::vector<std::string> &);
std::vector<std::string> vertical_concatenation(const std::vector<std::string> &, const std::vector<std::string> &);
std::vector<std::string> center(const std::vector<std::string> &);
#endif