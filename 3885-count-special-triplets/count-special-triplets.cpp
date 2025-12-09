
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        int ans = 0;
        unordered_map<int,int>left,right;
        int n = nums.size();
        for(int i=1;i<n;i++){
            right[nums[i]]++;
        }
        
        for(int i=0;i<(n-1);i++){
            int l = left[nums[i]*2];
            int r = right[nums[i]*2];

            ans=(ans+((long long)l*r)%1000000007)%1000000007;
            left[nums[i]]++;
            right[nums[i+1]]--;
        }
        return ans;
    }
};