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

// For debugging
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

void printCrossReferenceToFile(const std::map<std::string, std::vector<std::pair<int, int>>> &wordLocations, const std::string &filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        int longestWordLength = 0; // Track the length of the longest word
        for (const auto &word : wordLocations) {
            if (word.first.length() > longestWordLength) {
                longestWordLength = static_cast<int>(word.first.length());
            }
        }

        // Print the table header
        outputFile << std::setw(longestWordLength + 2) << std::left << "Word" << " | Line - Count" << std::endl;
        outputFile << std::setw(longestWordLength + 2 + 15) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

        // Print word occurrences in a table
        for (const auto &word : wordLocations) {
            outputFile << std::setw(longestWordLength + 2) << std::left << word.first;
            bool firstPair = true;
            for (const auto &pair : word.second) {
                if (!firstPair) {
                    outputFile << ", ";
                } else {
                    firstPair = false;
                }
                outputFile << pair.first << "-" << pair.second;
            }
            outputFile << std::endl;
        }

        // Print the table footer
        outputFile << std::setw(longestWordLength + 2 + 15) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

        std::cout << "Cross-reference written to file '" << filename << "'" << std::endl;
    } else {
        std::cerr << "Unable to open output file!" << std::endl;
    }
}

void printWordCountToFile(const std::map<std::string, int> &wordCount, const std::string &filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        int longestWordLength = 0; // Track the length of the longest word
        for (const auto &pair : wordCount) {
            if (pair.first.length() > longestWordLength) {
                longestWordLength = static_cast<int>(pair.first.length());
            }
        }

        // Print the table header
        outputFile << std::setw(longestWordLength + 2) << std::left << "Word" << " | Count" << std::endl;
        outputFile << std::setw(longestWordLength + 2 + 10) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

        // Print word counts in a table
        for (const auto &pair : wordCount) {
            if (pair.second > 1) { // Words repeated more than once
                outputFile << std::setw(longestWordLength + 2) << std::left << pair.first << " | " << pair.second << std::endl;
            }
        }

        // Print the table footer
        outputFile << std::setw(longestWordLength + 2 + 10) << std::setfill('-') << "" << std::setfill(' ') << std::endl;

        std::cout << "Output written to file '" << filename << "'" << std::endl;
    } else {
        std::cerr << "Unable to open output file!" << std::endl;
    }
}