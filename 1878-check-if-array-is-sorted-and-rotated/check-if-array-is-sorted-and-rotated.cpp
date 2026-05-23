
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), rotations = 0;
        for (int i = 1; i < n; ++i) 
            if (nums[i] < nums[i - 1]) ++rotations;
        if (nums[0] < nums[n - 1]) ++rotations;
        return rotations <= 1;
    }
};