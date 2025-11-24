
class Solution:
    def prefixesDivBy5(self, nums):
        result = []
        x = 0
        
        for bit in nums:
            x = (x * 2 + bit) % 5
            result.append(x == 0)
        
        return result
        