
class Solution {
    public int maxFrequencyElements(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int max_freq=0, ans=0;
        for(int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
            if(map.get(num) > max_freq) {
                ans = map.get(num);
                max_freq = map.get(num);
            } else if(map.get(num) == max_freq) {
                ans += map.get(num);
            }
        }
        return ans;
    }
}