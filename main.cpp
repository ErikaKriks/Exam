#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
#include "functions.h"


// int main() {
//     std::ifstream inputFile("text.txt"); // Replace with your input file name
//     std::map<std::string, int> wordCount;

//     if (inputFile.is_open()) {
//         std::string line;
//     //    ****************** PART 1 ***************************
//        while (std::getline(inputFile, line)) {
//             std::istringstream iss(line);
//             std::string word;
//             while (iss >> word) {
//                 std::string cleanedWord = cleanWord(word);
//                 if (!cleanedWord.empty()) {
//                     wordCount[cleanedWord]++;
//                 }
//             }
//         }
//         inputFile.close();

//        writeWordCountToFile(wordCount, "output.txt");
//     } else {
//         std::cerr << "Unable to open input file!" << std::endl;
//     }

//     return 0;
// }

int main() {
    std::ifstream inputFile("text.txt");
    std::map<std::string, std::vector<std::pair<int, int>>> wordLocations; // Map to store word occurrences, line numbers, and counts

    if (inputFile.is_open()) {
        std::string line;
        int lineNumber = 1;

        while (std::getline(inputFile, line)) {
            std::cout << "Processing line " << lineNumber << ": " << line << std::endl;
            processLine(line, lineNumber, wordLocations);
            ++lineNumber;
        }
        inputFile.close();

        printCrossReference(wordLocations); // Print cross-reference

        // Write the cross-reference table to a file
        // Write your code here

    } else {
        std::cerr << "Unable to open input file!" << std::endl;
    }

    return 0;
}
