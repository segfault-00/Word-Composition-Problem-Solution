# Trie-Based Compounded Word Detection

## Overview

This program efficiently identifies compounded words using a Trie data structure. The decision to choose a Trie over a hashmap is explained below.

## Design Decisions

**Initial Consideration:**
I contemplated using a hashmap to store words and check concatenation during searches.

**Analysis and Decision:**
Upon closer inspection, a Trie was deemed more suitable. It excels in word retrieval, quick prefix checks, recursive traversal for compounded words, memory efficiency, structured storage, and ease of implementation.

## Approach

1. **Trie Construction:**
   - Built a Trie from the provided list of words.

2. **Compounded Word Identification:**
   - Utilized the `isCompoundedWord` function for recursive Trie traversal to identify compounded words efficiently.

## Time Complexities

### 1. Reading Words from TXT File (`readWordsFromFile`):
   - **Time Complexity: O(n * w)**
     - *Explanation:* 'n' words are read from the file, and for each word, the `insert` operation is performed with a time complexity of O(w), where 'w' is the average length of a word.

### 2. Processing (`findLongestCompoundedWords`):
   - **Time Complexity: O(n * w^2)**
     - *Explanation:* For each of the 'n' words, the `isCompoundedWord` function is called. The worst-case time complexity of `isCompoundedWord` is O(w^2) due to recursive substring checks.

### 3. Overall Time Complexity:
   - **Overall Time Complexity: O(n * w^2)**
     - *Explanation:* The overall time complexity of the program is dominated by the second part (processing), which has a quadratic term w^2.



## Steps to execute code

1. **Download Code and Input Files:**
   - Download the C++ source code and input files. Place them in the same folder.

2. **Compile and Run:**
   - Use a C++ compiler to compile the code and run the executable.

3. **Review Results:**
   - Examine the console output for identified compounded words.

