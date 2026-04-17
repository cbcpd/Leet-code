
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        vector<int> rev;

        unordered_map<int, set<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());

            int val = stoi(s);

            mp[nums[i]].insert(i);
            rev.push_back(val);
        }

        int ans = 1e9;

        for (int i = 0; i < rev.size(); i++) {
            if (mp.find(rev[i]) != mp.end()) {
                auto it = mp[rev[i]].upper_bound(i);
                if (it == mp[rev[i]].end()) {
                    continue;
                }
                int v = *it;

                ans = min(ans, v - i);
            }
        }

        if (ans == 1e9) {
            return -1;
        }

        return ans;
    }
};