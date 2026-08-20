from typing import List

class Solution:
    def resultArray(self, v: List[int]) -> List[int]:
        n = len(v)
        ans = []
        v1 = [v[0]]
        v2 = [v[1]]
        for i in range(2, n):
            if v1[-1] > v2[-1]:
                v1.append(v[i])
            else:
                v2.append(v[i])
        ans.extend(v1)
        ans.extend(v2)
        return ans