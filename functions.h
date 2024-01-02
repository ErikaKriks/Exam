#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <string>
#include <map>

std::string cleanWord(const std::string &word);
void writeWordCountToFile(const std::map<std::string, int> &wordCount, const std::string &filename);
void processLine(const std::string &line, int lineNumber, std::map<std::string, std::vector<std::pair<int, int>>> &wordLocations);
void printCrossReference(const std::map<std::string, std::vector<std::pair<int, int>>> &wordLocations);
void printCrossReferenceToFile(const std::map<std::string, std::vector<std::pair<int, int>>> &wordLocations, const std::string &filename);




#endif // FUNCTIONS_H_INCLUDED