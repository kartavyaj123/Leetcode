class Solution {
public:
    int sumBase(int n, int k) {
        if(n == 0)
        return 0;

        int d = n % k;
        int m = n / k;

        int ans = sumBase(m, k);
        return d + ans;
    }
};