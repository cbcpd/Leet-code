
class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int distinctCount = 0, prevMax = INT_MIN;

        for (int num : nums) {
            int lowerBound = num - k;
            int upperBound = num + k;

            if (prevMax < lowerBound) {
                prevMax = lowerBound;
                distinctCount++;
            } else if (prevMax < upperBound) {
                prevMax++;
                distinctCount++;
            }
        }

        return distinctCount;
    }
};