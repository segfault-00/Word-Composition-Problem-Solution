# Trie-Based Compounded Word Detection

This program efficiently identifies compounded words using a Trie data structure.

## Overview

The solution utilizes a Trie, a tree-like data structure, for optimized storage and retrieval of strings. The core function, `isCompoundedWord`, employs a recursive approach to determine if a given word is compounded, providing a boolean result.

## Implementation Steps

1. **Trie Construction:**
   - Build a Trie using the provided list of words.

2. **Compounded Word Detection:**
   - Implement the `isCompoundedWord` function for recursive identification of compounded words.

## Usage

1. **Download Source Code:**
   - Obtain the source code from the provided repository.

2. **Compile and Run:**
   - Use a C++ compiler to compile the code and run the executable.

3. **Review Results:**
   - Examine the console output for identified compounded words.

## Time Complexity

The solution's efficiency is influenced by the Trie's quick search, insertion, and deletion operations, each taking O(k) time, where k is the length of the word. The recursive nature of `isCompoundedWord` contributes to a streamlined process.
