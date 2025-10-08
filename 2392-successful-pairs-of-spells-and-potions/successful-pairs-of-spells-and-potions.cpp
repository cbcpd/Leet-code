
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        int n = potions.size();
        vector<int> ans;

        for (int i : spells) {

            long long int target = success / i;

            if (target * i < success) {
                target++;
            }

            auto it = lower_bound(potions.begin(), potions.end(), target);
            if (it != potions.end()) {
                int index = it - potions.begin();
                ans.push_back(n - index);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
};