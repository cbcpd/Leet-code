
class Solution {
    public int findMin(int[] nums) {
        int n = nums.length;
        int l =0; int r=n-1;
        int ans = Integer.MAX_VALUE;
        while(l <= r)
        {
            int mid = l - ( l - r)/2;
            if(nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else{
                ans = Math.min(ans, nums[mid]);
                r = mid -1;
            }
        }
        return ans;
    }
}