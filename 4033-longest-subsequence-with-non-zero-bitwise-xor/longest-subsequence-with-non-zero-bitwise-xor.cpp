class Solution {
public:
    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();
        int zeroes =0;
        for(int i=0;i<=31;i++){
            int count =0;
            zeroes =0;
            
            for(int j=0;j<n;j++){
                if((1<<i)&nums[j]){
                    count++;
                }

                if(nums[j]==0){
                    zeroes++;
                }

                if(zeroes==n){
                    return 0;
                }
            }

            if(count%2==1){
                return n;
            }
        }

        return n-1;
    }
};