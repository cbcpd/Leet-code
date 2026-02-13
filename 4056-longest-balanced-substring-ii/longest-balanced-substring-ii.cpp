
class Solution {
public:
    struct PairHash {
        size_t operator()(const pair<int,int>& p) const noexcept {
            return (uint64_t)(uint32_t)p.first << 32 ^ (uint32_t)p.second;
        }
    };

    int longestBalanced(string s) {
        int n = (int)s.size();

        // Case 1: single character => longest run
        int ans = 1;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            ans = max(ans, j - i);
            i = j;
        }

        // Case 2: exactly two distinct characters (third absent)
        auto solve_two = [&](char x, char y, char z) -> int {
            unordered_map<pair<int,int>, int, PairHash> first;
            first.reserve(n * 2);
            first.max_load_factor(0.7f);

            int diff = 0;   // x - y
            int cntZ = 0;   // prefix count of z
            first[{0,0}] = -1;

            int best = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == x) diff++;
                else if (s[i] == y) diff--;
                else cntZ++; // s[i] == z

                pair<int,int> st = {diff, cntZ};
                auto it = first.find(st);
                if (it != first.end()) best = max(best, i - it->second);
                else first[st] = i;
            }
            return best;
        };

        ans = max(ans, solve_two('a','b','c'));
        ans = max(ans, solve_two('a','c','b'));
        ans = max(ans, solve_two('b','c','a'));

        // Case 3: all three present and equal counts
        unordered_map<pair<int,int>, int, PairHash> first3;
        first3.reserve(n * 2);
        first3.max_load_factor(0.7f);

        int a=0,b=0,c=0;
        first3[{0,0}] = -1; // prefix before start

        for (int i = 0; i < n; i++) {
            if (s[i]=='a') a++;
            else if (s[i]=='b') b++;
            else c++;

            // state: (b-a, c-a)
            pair<int,int> st = {b-a, c-a};

            auto it = first3.find(st);
            if (it != first3.end()) {
                int len = i - it->second;
                ans = max(ans,len);
            } else {
                first3[st] = i;
            }
        }

        // For Case 3 presence-check, use prefix arrays (clean & correct)
        // vector<int> pa(n+1,0), pb(n+1,0), pc(n+1,0);
        // for (int i = 0; i < n; i++) {
        //     pa[i+1]=pa[i]; pb[i+1]=pb[i]; pc[i+1]=pc[i];
        //     if (s[i]=='a') pa[i+1]++;
        //     else if (s[i]=='b') pb[i+1]++;
        //     else pc[i+1]++;
        // }

        // first3.clear();
        // first3[{0,0}] = 0; // prefix index 0
        // for (int i = 1; i <= n; i++) {
        //     pair<int,int> st = {pb[i]-pa[i], pc[i]-pa[i]};
        //     auto it = first3.find(st);
        //     if (it != first3.end()) {
        //         int L = it->second, R = i;
        //         int ca = pa[R]-pa[L], cb = pb[R]-pb[L], cc = pc[R]-pc[L];
        //         if (ca>0 && cb>0 && cc>0) ans = max(ans, R-L);
        //     } else {
        //         first3[st] = i;
        //     }
        // }

        return ans;
    }
};