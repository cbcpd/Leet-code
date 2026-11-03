class Solution {
    public int minMoves(int[] nums) {
        int sum=0;
        int largest=Integer.MIN_VALUE;

        for(int i=0;i<nums.length;i++){
            largest=Math.max(largest,nums[i]);
            sum+=nums[i];
        }
        return largest*nums.length-sum;
    }
}