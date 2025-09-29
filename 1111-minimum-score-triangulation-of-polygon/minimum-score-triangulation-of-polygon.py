
class Solution:
    def triangle(self, s: int, e: int, values: List[int], dp: List[List[int]]) -> int:
        if e - s < 2:
            return 0
        if dp[s][e] != -1:
            return dp[s][e]
        min_val = float('inf')
        for i in range(s + 1, e):
            min_val = min(min_val, values[s] * values[i] * values[e] + self.triangle(s, i, values, dp) + self.triangle(i, e, values, dp))
        dp[s][e] = min_val
        return dp[s][e]
 
    def minScoreTriangulation(self, values: List[int]) -> int:
        n = len(values)
        dp = [[-1] * n for _ in range(n)]
        return self.triangle(0, n - 1, values, dp)        