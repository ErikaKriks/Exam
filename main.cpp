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

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                std::string cleanedWord = cleanWord(word);
                if (!cleanedWord.empty()) {
                    wordCount[cleanedWord]++;
                }
            }
        }
        inputFile.close();

       writeWordCountToFile(wordCount, "output.txt");
    } else {
        std::cerr << "Unable to open input file!" << std::endl;
    }

    return 0;
}
