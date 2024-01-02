#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <map>

// Function to clean and process a word
std::string cleanWord(const std::string &word) {
    std::string cleaned;
    for (char ch : word) {
        if (std::isalpha(ch) || ch == '\'') {
            cleaned += std::tolower(ch);
        }
    }
    return cleaned;
}

void writeWordCountToFile(const std::map<std::string, int> &wordCount, const std::string &filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (const auto &pair : wordCount) {
            if (pair.second > 1) { // Words repeated more than once
                outputFile << pair.first << ": " << pair.second << std::endl;
            }
        }
        outputFile.close();
        std::cout << "Output written to file '" << filename << "'" << std::endl;
    } else {
        std::cerr << "Unable to open output file!" << std::endl;
    }
}

void processLine(const std::string &line, int lineNumber, std::map<std::string, std::vector<std::pair<int, int>>> &wordLocations) {
    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
        std::string cleanedWord = cleanWord(word);
        if (!cleanedWord.empty()) {
            bool wordFound = false;
            for (auto &pair : wordLocations[cleanedWord]) {
                if (pair.first == lineNumber) {
                    pair.second++;
                    wordFound = true;
                    break;
                }
            }
            if (!wordFound) {
                wordLocations[cleanedWord].push_back(std::make_pair(lineNumber, 1));
            }
        }
    }
}

void printCrossReference(const std::map<std::string, std::vector<std::pair<int, int>>> &wordLocations) {
    for (const auto &word : wordLocations) {
        std::cout << "Word: " << word.first << std::endl;
        std::cout << "  Appears in lines: ";
        for (const auto &pair : word.second) {
            std::cout << "Line " << pair.first << " (" << pair.second << " times) ";
        }
        std::cout << std::endl;
    }
}
