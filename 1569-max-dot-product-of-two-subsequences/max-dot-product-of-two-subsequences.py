
class Solution:
    def __init__(self):
        self.memo = [[-1] * 505 for _ in range(505)]
        self.lengthA = 0
        self.lengthB = 0

    def dfsMaxDotProduct(self, arrayA: list[int], arrayB: list[int], indexA: int, indexB: int) -> int:
        if indexA == self.lengthA or indexB == self.lengthB:
            return 0
        # If already computed
        if self.memo[indexA][indexB] != -1:
            return self.memo[indexA][indexB]
        # Option 1: take both elements
        takeBoth = (
            arrayA[indexA] * arrayB[indexB]
            + self.dfsMaxDotProduct(arrayA, arrayB, indexA + 1, indexB + 1)
        )
        # Option 2: skip element in arrayB
        skipB = self.dfsMaxDotProduct(arrayA, arrayB, indexA, indexB + 1)
        # Option 3: skip element in arrayA
        skipA = self.dfsMaxDotProduct(arrayA, arrayB, indexA + 1, indexB)
        # Store best result
        self.memo[indexA][indexB] = max(takeBoth, skipA, skipB)
        return self.memo[indexA][indexB]
    def maxDotProduct(self, nums1: list[int], nums2: list[int]) -> int:
        self.lengthA = len(nums1)
        self.lengthB = len(nums2)
        maxA = float('-inf')
        minA = float('inf')
        maxB = float('-inf')
        minB = float('inf')
        # Find min and max in nums1
        for value in nums1:
            maxA = max(maxA, value)
            minA = min(minA, value)
        # Find min and max in nums2
        for value in nums2:
            maxB = max(maxB, value)
            minB = min(minB, value)

        # Handle edge case where best answer is negative
        if (maxA < 0 and minB > 0) or (minA > 0 and maxB < 0):
            return max(maxA * minB, minA * maxB)

        # Reset memo table
        for i in range(505):
            for j in range(505):
                self.memo[i][j] = -1

        return self.dfsMaxDotProduct(nums1, nums2, 0, 0)        