package main

import (
    "fmt"
)

func findLadders(beginWord string, endWord string, wordList []string) [][]string {
    wordSet := make(map[string]struct{})
    for _, word := range wordList {
        wordSet[word] = struct{}{}
    }

    // Early exit if the endWord is not in the wordList
    if _, ok := wordSet[endWord]; !ok {
        return nil
    }

    // Using a map to keep track of the adjacency list of transformations
    adj := make(map[string][]string)
    queue := []string{beginWord}
    visited := make(map[string]bool)
    visited[beginWord] = true
    found := false

    // BFS to build the graph
    for len(queue) > 0 && !found {
        currentLevelVisited := make(map[string]bool)
        nextQueue := []string{}
        for _, currentWord := range queue {
            wordChars := []rune(currentWord)
            for i := range wordChars {
                originalChar := wordChars[i]
                for c := 'a'; c <= 'z'; c++ {
                    if c == originalChar {
                        continue
                    }
                    wordChars[i] = c
                    tempWord := string(wordChars)
                    if _, exists := wordSet[tempWord]; exists && !visited[tempWord] {
                        if tempWord == endWord {
                            found = true
                        }
                        if !currentLevelVisited[tempWord] {
                            currentLevelVisited[tempWord] = true
                            nextQueue = append(nextQueue, tempWord)
                        }
                        adj[tempWord] = append(adj[tempWord], currentWord)
                    }
                }
                wordChars[i] = originalChar
            }
        }
        queue = nextQueue
        for word := range currentLevelVisited {
            visited[word] = true
        }
    }

    var results [][]string
    if found {
        // Backtrack to find all paths from endWord to beginWord
        var path []string
        backtrack(endWord, beginWord, adj, path, &results)
    }
    return results
}

func backtrack(currentWord string, beginWord string, adj map[string][]string, path []string, results *[][]string) {
    path = append([]string{currentWord}, path...) // Prepend currentWord to path
    if currentWord == beginWord {
        *results = append(*results, append([]string{}, path...)) // Make a copy of path
        return
    }

    for _, prevWord := range adj[currentWord] {
        backtrack(prevWord, beginWord, adj, path, results)
    }
    path = path[1:] // Remove the prepended word
}

func main() {
    beginWord := "hit"
    endWord := "cog"
    wordList := []string{"hot", "dot", "dog", "lot", "log", "cog"}
    results := findLadders(beginWord, endWord, wordList)
    for _, path := range results {
        fmt.Println(path)
    }
}
