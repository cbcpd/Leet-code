class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> res;
        multiset<int> ms(nums.begin(),nums.end());
        auto range =ms.equal_range(target);
        int start_in=distance(ms.begin(),range.first);
        int end_in=distance(ms.begin() , range.second);
        for(int i=start_in;i<end_in;i++){
            res.push_back(i);
        }
        return res;
    }
};