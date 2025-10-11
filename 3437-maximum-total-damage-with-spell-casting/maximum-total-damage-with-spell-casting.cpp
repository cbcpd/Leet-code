
typedef long long int ll;

ll dp[100001];
int nxt[100001];
int same[100001];

class Solution {
    
    int n;
    vector<ll> arr;
    
    ll MaxDamage (int i) {
        if (i == n) return 0;
        
        ll &ans = dp[i];
        if (ans != -1) return ans;
        
        ans = max (
            MaxDamage(i+1),  
            MaxDamage(nxt[i]) + (same[i] - i)*arr[i]
        );        
        return ans;
    }
    
public:
    long long maximumTotalDamage(vector<int>& power) {
        arr.clear();
        n = power.size();
        
        for (auto i : power) arr.push_back(i);
        sort (arr.begin(), arr.end());
        
        int nxt_ind = 0;
        int same_ind = 0;
        
        for (int i = 0; i < n; i ++) {
            while (nxt_ind < n && arr[i]+2 >= arr[nxt_ind]) nxt_ind ++;
            nxt[i] = nxt_ind;
            
            while (same_ind < n && arr[i] == arr[same_ind]) same_ind ++;
            same[i] = same_ind;
        }
        
        memset(dp, -1, sizeof(dp));
        return MaxDamage(0);
    }
};