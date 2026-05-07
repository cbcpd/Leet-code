class Solution {
    public int[] maxValue(int[] nums) {
        int n = nums.length;
        int prefix[] = new int[n];
        int suffix[] = new int[n];
        int ans[] = new int[n];

        prefix[0] = nums[0];
        for (int i = 1; i < n; i++){
            prefix[i] = Math.max(nums[i], prefix[i - 1]);
        } 

        suffix[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--){
            suffix[i] = Math.min(nums[i], suffix[i + 1]);
        } 

        ans[n - 1] = prefix[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = prefix[i];
            if (prefix[i] > suffix[i + 1]){
                ans[i] = ans[i+1];
            }
        }
        return ans;
    }
}