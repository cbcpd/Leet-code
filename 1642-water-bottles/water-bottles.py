
class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        ans = 0
        empty = 0
        extra = 0
        while numBottles > 0:
            ans += numBottles
            empty = numBottles + extra
            numBottles = empty // numExchange
            extra = empty % numExchange
        return ans        