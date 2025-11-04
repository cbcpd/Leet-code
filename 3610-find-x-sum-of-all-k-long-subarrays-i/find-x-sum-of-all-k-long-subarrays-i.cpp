;
class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        set<pair<long long, long long>> sums;   
        unordered_map<long long, long long> mp; 
        vector<int> ans;


        for (int i = 0; i < k && i < n; i++) {
            int to_add = nums[i];
            sums.erase(
                {mp[to_add], to_add}); 
            mp[to_add]++;
            sums.insert({mp[to_add], to_add});
        }


        auto calculate_top_x_sum = [&](int x) -> long long {
            long long sum = 0;
            int count = x;
            for (auto it = sums.rbegin(); it != sums.rend() && count > 0;
                 ++it, --count) {
                sum += it->first * it->second; 
            }
            return sum;
        };

        ans.push_back(calculate_top_x_sum(x));

        for (int i = k; i < n; i++) {
            int to_remove = nums[i - k];
            int to_add = nums[i];

            sums.erase({mp[to_remove], to_remove}); 
            mp[to_remove]--;
            if (mp[to_remove] > 0) {
                sums.insert({mp[to_remove],
                             to_remove}); 
            }


            sums.erase(
                {mp[to_add], to_add}); 
            mp[to_add]++;
            sums.insert({mp[to_add], to_add}); 
            ans.push_back(calculate_top_x_sum(x));
        }

        return ans;
    }
};
