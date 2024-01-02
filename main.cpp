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
        // std::ofstream outputFile("output.txt"); // Output file to store word count
        // if (outputFile.is_open()) {
        //     for (const auto &pair : wordCount) {
        //         if (pair.second > 1) { // Words repeated more than once
        //             outputFile << pair.first << ": " << pair.second << std::endl;
        //         }
        //     }
        //     outputFile.close();
        //     std::cout << "Output written to file 'output.txt'" << std::endl;
        // } else {
        //     std::cerr << "Unable to open output file!" << std::endl;
        // }
    } else {
        std::cerr << "Unable to open input file!" << std::endl;
    }

    return 0;
}
