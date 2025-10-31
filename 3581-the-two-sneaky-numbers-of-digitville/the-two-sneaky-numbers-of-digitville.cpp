
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> unique;
        vector<int> ans;
        for(int num: nums)
            if(unique.count(num))
                ans.push_back(num);
            else
                unique.insert(num);
        return ans;
    }
};