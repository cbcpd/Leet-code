class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        n = len(s)
        first = [-1] * 26
        last = [-1] * 26
        
        # Record first and last occurrences
        for i, ch in enumerate(s):
            idx = ord(ch) - ord('a')
            if first[idx] == -1:
                first[idx] = i
            last[idx] = i
        
        result = 0
        
        # Check for each possible outer character
        for c in range(26):
            L, R = first[c], last[c]
            if L != -1 and R != -1 and L < R:
                # collect unique chars in between
                middle = set(s[L+1:R])
                result += len(middle)
        
        return result

        