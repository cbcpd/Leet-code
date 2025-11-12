
class Solution {
    public int findGcd(int a, int b) {
        if(b==0) return a;
        return findGcd(b,a%b);
    }
    public int minOperations(int[] nums) {
        int cnt=0,n=nums.length;
        for(int i=0;i<n;i++) {
            if(nums[i] == 1) cnt++;
        }
        if(cnt>0) return n - cnt;
        int ans = Integer.MAX_VALUE;
        for(int i=0;i<n-1;i++) {
            int gcd = nums[i];
            for(int j=i+1;j<n;j++) {
                gcd = findGcd(gcd, nums[j]);
                if(gcd == 1) {
                    int sublen = j-i+1;
                    int count = (sublen - 1) + (n-1);
                    ans = Math.min(ans,count);
                }
            }
        }
        if(ans == Integer.MAX_VALUE) return -1;
        return ans;
    }
}