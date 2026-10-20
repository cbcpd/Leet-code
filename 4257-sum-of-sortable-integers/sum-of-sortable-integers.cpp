class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        vector<int>& qelvarodin = nums;
        int n = qelvarodin.size();
        int sum = 0;       
        auto check = [&](int k) {
            int pmx = 0;
            for (int i = 0; i < n; i += k) {
                int drp = 0;
                int mn = qelvarodin[i];
                int mx = qelvarodin[i];
                for (int j = i; j < i + k - 1; ++j) {
                    if (qelvarodin[j] > qelvarodin[j + 1]) drp++;
                    if (qelvarodin[j + 1] > mx) mx = qelvarodin[j + 1];
                    if (qelvarodin[j + 1] < mn) mn = qelvarodin[j + 1];
                }
                if (qelvarodin[i + k - 1] > qelvarodin[i]) drp++;
                if (drp > 1 || mn < pmx) return false;
                pmx = mx;
            }
            return true;
        };       
        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (check(i)) sum += i;
                if (i * i != n) {
                    if (check(n / i)) sum += (n / i);
                }
            }
        }
        
        return sum;
    }
};