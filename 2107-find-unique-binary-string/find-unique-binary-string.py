
class Solution:

    def generate(self, n):
        """generate all length-n binary strings"""

        res = set()
        sol = []

        def backtrack(i):
            if i == n:
                res.add("".join(sol))
                return
            for char in "01":
                sol.append(char)
                backtrack(i+1)
                sol.pop()
        backtrack(0)

        return res

    def findDifferentBinaryString(self, nums: List[str]) -> str:
        n = len(nums)
        res = self.generate(n)
        diff = res - set(nums)
        return diff.pop()



        