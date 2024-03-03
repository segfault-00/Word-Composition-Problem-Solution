#include <bits/stdc++.h>
using namespace std;

// Function to read words from a file and store them in a set
void readWordsFromFile(unordered_set<string>& wordSet, const string& filePath) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    string word;
    while (getline(file, word)) {
        wordSet.insert(word);
    }

    file.close();
}

// Function to check if a word is compounded by combining shorter words from the set
bool isCompoundedWord(string word, const unordered_set<string>& wordSet) {
    for (int i = 1; i < word.size(); i++) {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i);

        if (wordSet.find(prefix) != wordSet.end() &&
            (wordSet.find(suffix) != wordSet.end() || isCompoundedWord(suffix, wordSet))) {
            return true;
        }
    }

    return false;
}

// Function to process the file, find the longest and second-longest compounded words, and display the result
void processFile(const string filePath) {
    auto startTime = chrono::high_resolution_clock::now();

    unordered_set<string> wordSet;
    readWordsFromFile(wordSet, filePath);

    string longestCompoundWord = "";
    string secondLongestCompoundWord = "";

    for (const auto& word : wordSet) {
        if (isCompoundedWord(word, wordSet)) {
            if (word.length() > longestCompoundWord.length()) {
                secondLongestCompoundWord = longestCompoundWord;
                longestCompoundWord = word;
            } else if (word.length() > secondLongestCompoundWord.length()) {
                secondLongestCompoundWord = word;
            }
        }
    }

    auto endTime = chrono::high_resolution_clock::now();
    auto processingTime = chrono::duration_cast<chrono::milliseconds>(endTime - startTime).count();

    
     if (longestCompoundWord.empty()) {
        cout << "No compounded words found in the file." << endl;
    } else {
        cout << "Longest Compound Word: " << longestCompoundWord << endl;
        if (secondLongestCompoundWord.empty()) {
            cout << "No second longest compounded word found." << endl;
        } else {
            cout << "Second Longest Compound Word: " << secondLongestCompoundWord << endl;
        }
        cout << "Time taken to process file " << filePath << ": " << processingTime << " milli seconds" << endl;
    }


}

int main() {
    processFile("Input_02.txt");
    return 0;
}



//  Reading file : O(n.m)
//  isCompoundedWord  : O(m^2)
//  Processing Words in the Set: O(n*(m^2))  **** over all also
