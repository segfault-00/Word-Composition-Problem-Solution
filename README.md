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

## Time Complexity

The time complexity is influenced by the Trie's efficiency, making the identification of compounded words streamlined.

## Usage

1. **Download Source Code:**
   - Obtain the source code from the provided repository.

2. **Compile and Run:**
   - Use a C++ compiler to compile the code and run the executable.

3. **Review Results:**
   - Examine the console output for identified compounded words.

Feel free to modify and use this code for your needs!
