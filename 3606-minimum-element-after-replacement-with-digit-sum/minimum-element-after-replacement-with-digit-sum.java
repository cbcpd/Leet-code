
class Solution {
    public int minElement(int[] nums) {
        int min = nums[0];
        for (int num : nums) {
            int digitSum = calculateDigitSum(num);
            min = Math.min(min, digitSum);
        }
        return min;
    }

    private int calculateDigitSum(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
}