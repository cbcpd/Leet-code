class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n = len(grid)

        def countZeros(arr):
            n_zero = 0
            for i in range(n-1, -1, -1):
                if arr[i] == 0:
                    n_zero += 1
                else:
                    break
            return n_zero

        zeros = [countZeros(row) for row in grid]
        res = 0
        
        for i in range(n):
            target = n - i - 1
            if zeros[i] >= target: continue
            possible = False
            for j in range(i+1, n):
                if zeros[j] >= target:
                    possible = True
                    res += (j - i)
                    zeros[i+1:j+1] = zeros[i:j]
                    break
            if not possible: return -1

        return res
        