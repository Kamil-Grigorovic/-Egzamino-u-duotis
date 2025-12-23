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


/// Darbas su URL
// URL rinkimo funkcija
void findURLs(const string& line) {
    stringstream ss(line);
    string token;

    while (ss >> token) {
        if (isURL(token)) {
            urls.insert(token);
        }
    }
}

// URL tikrinimo funkcija
bool isURL(const string& token) {
    string s = token;

    // pašalinam skyrybos ženklus nuo galo
    while (!s.empty() && ispunct((unsigned char)s.back()) && s.back() != '/') {
        s.pop_back();
    }

    // http:// arba https://
    if (s.rfind("http://", 0) == 0 || s.rfind("https://", 0) == 0)
        return true;

    // www.
    if (s.rfind("www.", 0) == 0)
        return true;

    // paprastas domenas: kazkas.lt
    size_t dot = s.find('.');
    if (dot != string::npos && dot > 0 && dot < s.size() - 2) {
        // patikrinam, kad po taško būtų tik raidės
        for (size_t i = dot + 1; i < s.size(); i++) {
            if (!isalpha((unsigned char)s[i]))
                return false;
        }
        return true;
    }

    return false;
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

// URL adresu isvedimas i faila
void printURLs(const set<string>& urls, const string& outputFile) {
    ofstream outputFileStream(outputFile);
    if (outputFileStream.is_open()) {
        for (const auto& url : urls) {
            outputFileStream << url << endl;
        }
        outputFileStream.close();
    }
}


/// Rezultatu isvedimas i terminala
// Isvedimas i terminala cross - reference lentele
void printCrossReference() {
    for (const auto& p : wordLines) {
        if (wordCount[p.first] > 1) {
            cout << p.first << ": ";
            for (int line : p.second) {
                cout << line << " ";
            }
            cout << endl;
        }
    }
}

// Isvedimas i terminala zodziu pasikartojimu skaicius
void printResults() {
    for (const auto& pair : wordCount) {
        if (pair.second > 1) {
            cout << pair.first << " - " << pair.second << endl;
        }
    }
}

// Isvedimas i terminala URL adresai
void printURLs_terminal(const set<string>& urls) {
    for (const auto& url : urls) {
        cout << url << endl;
    }
}
