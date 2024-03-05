
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26]; // Assuming lowercase English alphabet
    bool isEndOfWord;

    TrieNode() {
        // Initialize children array with nullptr
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        isEndOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (!current->children[index]) {
                current->children[index] = new TrieNode();
            }
            current = current->children[index];
        }
        current->isEndOfWord = true;
    }

    // Check if a word is a compounded word
    bool isCompoundedWord(const string& str, int start, int end) {
        TrieNode* current = root;

        int originalStart = start;

        while (start <= end) {
            int index = str[start] - 'a';
            if (!current->children[index]) {
                return false;
            }

            current = current->children[index];

            if (current->isEndOfWord && ((start == end && originalStart != 0) || isCompoundedWord(str, start + 1, end))) {
                return true;
            }

            start++;
        }

        return false;
    }
};

// Function to read words from a file and insert them into the Trie
void readWordsFromFile(vector<string>& wordList, Trie* myTrie, const string& filePath) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    string word;
    while (getline(file, word)) {
        myTrie->insert(word);
        wordList.push_back(word);
    }

    file.close();
}

// Process the list of words to find the longest and second longest compounded words
pair<string, string> findLongestCompoundedWords(vector<string>& wordList, Trie* myTrie) {
    string longestCompoundWord = "";
    string secondLongestCompoundWord = "";

    for (auto word : wordList) {
        if (myTrie -> isCompoundedWord(word, 0, word.size() - 1)) {
            if (word.length() > longestCompoundWord.length()) {
                secondLongestCompoundWord = longestCompoundWord;
                longestCompoundWord = word;
            } else if (word.length() > secondLongestCompoundWord.length()) {
                secondLongestCompoundWord = word;
            }
        }
    }

    return {longestCompoundWord, secondLongestCompoundWord};
}

int main() {
    auto startTime = chrono::high_resolution_clock::now();

    Trie myTrie;
    vector<string> wordList;

    // Replace "Input_01.txt" with the appropriate file path
    string filePath = "Input_02.txt";
    readWordsFromFile(wordList, &myTrie, filePath);

    pair<string, string> result = findLongestCompoundedWords(wordList, &myTrie);

    string longestCompoundWord = result.first;
    string secondLongestCompoundWord = result.second;

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

    

    return 0;
}


