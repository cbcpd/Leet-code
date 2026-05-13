
class Solution {
public:
  int minMoves(vector<int>& nums, int limit) {
    const int n = nums.size();
    vector<int> delta(limit * 2 + 2);
    for (int i = 0; i < n / 2; ++i) {
      const int a = min(nums[i], nums[n - i - 1]);
      const int b = max(nums[i], nums[n - i - 1]);
      delta[2] += 2;          // dec a, dec b
      --delta[a + 1];         // dec a 
      --delta[a + b];         // no op
      ++delta[a + b + 1];     // inc a
      ++delta[b + limit + 1]; // inc a, inc b     
    }
    int ans = n;
    for (int t = 2, cur = 0; t <= limit * 2; ++t) {
      cur += delta[t];
      ans = min(ans, cur);
    }
    return ans;
  }
};