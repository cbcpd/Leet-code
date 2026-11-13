class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq;

        long long cost = 0;
        long long ans = 0;

        int R = n - 1;

        for (int i = n - 1; i >= 0; i--) {

            while (!dq.empty() && nums[dq.front()] <= nums[i]) {

                int idx = dq.front();
                dq.pop_front();

                int next = dq.empty() ? R + 1 : dq.front();

                cost += 1LL * (nums[i] - nums[idx])
                        * (next - idx);
            }

            dq.push_front(i);

            while (cost > k) {

                cost -= nums[dq.back()] - nums[R];

                if (dq.back() == R) {
                    dq.pop_back();
                }

                R--;
            }

            ans += R - i + 1;
        }

        return ans;
    }
};