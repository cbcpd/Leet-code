
class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int firstMin  = nums[0];
        int secondMin = INT_MAX;
        int thirdMin  = INT_MAX;

        for(int i = 1; i < n; i++) {
            if(nums[i] < secondMin) {
                thirdMin  = secondMin;
                secondMin = nums[i];
            } else if(nums[i] < thirdMin) {
                thirdMin = nums[i];
            }
        }

        return firstMin + secondMin + thirdMin;
    }
};
