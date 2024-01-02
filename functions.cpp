#include <string>
#include <iostream>
#include <fstream>
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
