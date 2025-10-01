
class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int ans = 0,empty=0,extra=0;
        while(numBottles > 0) {
            ans += numBottles;
            empty = numBottles + extra;
            numBottles = empty / numExchange;
            extra = empty % numExchange;
        }
        return ans;
    }
}