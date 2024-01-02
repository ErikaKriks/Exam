#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include "functions.h"


int main() {
    std::ifstream inputFile("text.txt"); // Replace with your input file name
    std::map<std::string, int> wordCount;
    std::map<std::string, std::vector<std::pair<int, int>>> wordLocations; // Map to store word occurrences, line numbers, and counts


    if (inputFile.is_open()) {
        std::string line;
        int lineNumber = 1;

       while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string word;

            // Part 1
            while (iss >> word) {
                std::string cleanedWord = cleanWord(word);
                if (!cleanedWord.empty()) {
                    wordCount[cleanedWord]++;
                }
            }

            // Part 2
            processLine(line, lineNumber, wordLocations);
            ++lineNumber;
        }
        inputFile.close();

       printWordCountToFile(wordCount, "output_table.txt");
       printCrossReferenceToFile(wordLocations, "cross_reference_table.txt");
       extractAndWriteURLsToFile("text.txt", "urls.txt"); // Part 3
    } else {
        std::cerr << "Unable to open input file!" << std::endl;
    }

    return 0;
}
