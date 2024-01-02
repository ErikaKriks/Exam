#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <string>
#include <map>

std::string cleanWord(const std::string &word);
void writeWordCountToFile(const std::map<std::string, int> &wordCount, const std::string &filename);

#endif // FUNCTIONS_H_INCLUDED