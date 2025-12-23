#include "header.h"

map<string, int> wordCount;
map<string, set<int>> wordLines;
set<string> urls;


/// Darbas su failu
// Darbas su failo eilutemis
void processLines(const string& line, int lineNumber) {

    findURLs(line);

    stringstream ss(line);
    string word;

    while (ss >> word) {
        string clean;
        bool hasLower = false;

        for (unsigned char c : word) {
            if (isalpha(c) || c >= 128) {
                clean += c;
                if (islower(c))
                    hasLower = true;
            }
        }

        if (clean.length() >= 2 && hasLower) {
            wordCount[clean]++;
            wordLines[clean].insert(lineNumber);
        }
    }
}

// Funkcija staitytit is failo
void readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    int lineNumber = 1;

    while (getline(file, line)) {
        processLines(line, lineNumber);
        lineNumber++;
    }

    file.close();
}

/// Rezultatu isvedimas i faila
// Isvedimas i faila
void writeFile_1(const string& outputFile_1) {
    ofstream outputFileStream(outputFile_1);
    if (outputFileStream.is_open()) {
        for (const auto& pair : wordCount) {
            if (pair.second > 1) {
                outputFileStream << pair.first << " - " << pair.second << endl;
            }
        }
        outputFileStream.close();
    }
}

// Cross - reference lenteles isvedimas
void writeFile_2(const string& outputFile_2) {
    ofstream outputFileStream(outputFile_2);
    if (outputFileStream.is_open()) {
        for (const auto& p : wordLines) {
            if (wordCount[p.first] > 1) {
                outputFileStream << p.first << ": ";
                for (int line : p.second) {
                    outputFileStream << line << " ";
                }
                outputFileStream << endl;
            }
        }
        outputFileStream.close();
    }
}
