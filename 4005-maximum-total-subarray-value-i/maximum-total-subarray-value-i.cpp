class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
        long long ans =0;

        int maxi=-1e9;
        int mini =1e9;
        int diff =0;
        for(int i: nums){
            maxi = max(maxi,i);
            mini =min(mini,i);
            diff =max(diff,maxi-mini);

        }

        return diff*1LL*k;
    }
};