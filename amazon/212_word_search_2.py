

#trie (prefix tree) & Depth-First Search
from typing import List

class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_word = False

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        #build the trie
        root = TrieNode()
        for word in words:
            node = root
            for char in words:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.is_word = True

        def dfs(node, i, j, path):
            char = board[i][j]
            if char not in node.children:
                return

            node = node.children[char]
            path += char

            if node.is_word:
                result.add(path)
                node.is_word = False #to prevent duplicates

            board[i][j] = '#'
            #Explore neighbors
            for x,y in [(i-1, j), (i+1, j), (i, j+1), (i, j-1)]:
                if 0 <= x < len(board) and 0 <= y < len(board[0]) and board[x][y] != "#":
                    dfs(node, x, y, path)
            # restore the current cell's orgininal value
            board[i][j] = char

        result = set()
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] in root.children:
                    dfs(root, i, j, "")

        return list(result)



#n2
class TrieNode:
    def __init__(self):
        self.children = {}
        self.isWord = False
        self.refs = 0

    def addWord(self, word):
        cur = self
        cur.refs += 1
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
            cur.refs += 1
        cur.isWord = True

    def removeWord(self, word):
        cur = self
        cur.refs -= 1
        for c in word:
            if c in cur.children:
                cur = cur.children[c]
                cur.refs -= 1
        cur.isWord = False

class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        def dfs(r, c, node, word):
            if (
                r not in range(m) 
                or c not in range(n)
                or board[r][c] not in node.children
                or node.children[board[r][c]].refs < 1
                or (r, c) in visited
            ):
                return

            visited.add((r, c))
            node = node.children[board[r][c]]
            word += board[r][c]
            if node.isWord:
                res.append(word)
                root.removeWord(word)

            dfs(r + 1, c, node, word)
            dfs(r - 1, c, node, word)
            dfs(r, c + 1, node, word)
            dfs(r, c - 1, node, word)
            visited.remove((r, c))
        
        root = TrieNode()
        for w in words:
            root.addWord(w)

        m, n = len(board), len(board[0])
        res, visited = [], set()

        for r in range(m):
            for c in range(n):
                dfs(r, c, root, "")

        return res