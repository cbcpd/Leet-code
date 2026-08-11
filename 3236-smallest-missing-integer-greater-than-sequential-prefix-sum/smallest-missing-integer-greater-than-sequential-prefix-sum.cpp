class Solution {
public:
    int missingInteger(vector<int>& nums) {
        // insert all numbers in set
        unordered_set<int> s;
        for(int num : nums)
            s.insert(num);
        
        // find sum of numbers until given condition is satisfied
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i - 1] + 1)
                sum += nums[i];
            else 
                break;
        }
        
        // find first missing number from sum onwards using set
        while(sum){
            if(s.find(sum) == s.end())    // first missing number
                return sum;
            sum++;      // check for next number
        }
        
        return 0;   // for compilation
    }
};