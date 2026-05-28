class Solution:
    class TrieNode:
        def __init__(self):
            self.children = [None] * 26
            self.shortestWordLength = float('inf')
            self.shortestWordIndex = float('inf')

    def insertWord(self, root, word, wordIndex):
        wordLength = len(word)
        reversedWord = word[::-1]

        for i in range(wordLength):
            charIndex = ord(reversedWord[i]) - ord('a')
            if root.children[charIndex] is None:
                new_node = self.TrieNode()
                new_node.shortestWordLength = wordLength
                new_node.shortestWordIndex = wordIndex
                root.children[charIndex] = new_node
                root = root.children[charIndex]
            else:
                root = root.children[charIndex]
                if wordLength < root.shortestWordLength:
                    root.shortestWordLength = wordLength
                    root.shortestWordIndex = wordIndex

    def searchWord(self, root, word):
        reversedWord = word[::-1]
        wordLength = len(word)

        for i in range(wordLength):
            charIndex = ord(reversedWord[i]) - ord('a')
            if root.children[charIndex] is not None:
                root = root.children[charIndex]
            else:
                break
        return root.shortestWordIndex

    def stringIndices(self, words, queries):
        n = len(words)
        indices = []
        root = self.TrieNode()

        for i in range(n):
            if len(words[i]) < root.shortestWordLength:
                root.shortestWordLength = len(words[i])
                root.shortestWordIndex = i
            self.insertWord(root, words[i], i)

        m = len(queries)
        for i in range(m):
            index = self.searchWord(root, queries[i])
            indices.append(index)
        return indices