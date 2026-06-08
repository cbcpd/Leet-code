
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        
        for (int num : nums) {
            if (num < pivot) {
                less.push_back(num);
            } else if (num == pivot) {
                equal.push_back(num);
            } else {
                greater.push_back(num);
            }
        }
        
        vector<int> result;
        result.reserve(nums.size());
        for (int num : less) result.push_back(num);
        for (int num : equal) result.push_back(num);
        for (int num : greater) result.push_back(num);
        
        return result;
    }
};