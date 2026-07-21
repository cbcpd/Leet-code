class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ones = 0;
        for (char c : s) {
            if (c == '1')
                ones++;
        }
        vector<pair<char, int>> vec;
        int i = 0;
        while (i < n) {
            char current = s[i];
            int count = 0;
            while (i < n && s[i] == current) {
                count++;
                i++;
            }
            vec.push_back({current, count});
        }

        int bestGain = 0;
        for (size_t j = 0; j + 2 < vec.size(); j++) {
            if (vec[j].first == '0' && vec[j + 1].first == '1' &&
                vec[j + 2].first == '0') {
                int currentGain = vec[j].second + vec[j + 2].second;
                bestGain = max(bestGain, currentGain);
            }
        }

        return ones + bestGain;
    }
};