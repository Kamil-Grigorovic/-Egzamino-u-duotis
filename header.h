#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <cctype>

using namespace std;

extern map<string, int> wordCount;
extern map<string, set<int>> wordLines;
extern set<string> urls;

void readFromFile(const string& filename);
void processLines(const string& line, int lineNumber);

void findURLs(const string& line);
bool isURL(const string& word);

void writeFile_1(const string& outputFile_1);
void writeFile_2(const string& outputFile_2);
void printURLs(const set<string>& urls, const string& outputFile);

void printResults();
void printCrossReference();
void printURLs_terminal(const set<string>& urls);
