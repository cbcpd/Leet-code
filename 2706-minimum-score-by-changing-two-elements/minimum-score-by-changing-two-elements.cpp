class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        if(n==3) return 0;
        sort(nums.begin(),nums.end());
        //upadte 2 elements from beg 
        int diff1 = nums[n-1]-nums[2];
        //upadte 2 elements from end 
        int diff2 = nums[n-3]-nums[0];
        //upadte 1 element from beg and 1 from end
        int diff3 = nums[n-2]-nums[1];
        return min(diff1,min(diff2,diff3));
    }
};