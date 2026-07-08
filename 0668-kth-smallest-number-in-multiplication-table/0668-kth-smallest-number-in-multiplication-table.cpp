class Solution {
public:

    int fun(int m, int n, int guess)
    {
        int count = 0;

        for (int row = 1; row <= m; row++)
        {
            count += min(n, guess / row);
        }

        return count;
    }

    int findKthNumber(int m, int n, int k) {
        int res = -1;
        int low = 1;
        int high = m * n;

        while (low <= high)
        {
            int guess = low + (high - low) / 2;

            int ans = fun(m, n, guess);

            if (ans < k)
            {
                low = guess + 1;
            }
            else
            {
                res = guess;
                high = guess - 1;
            }
        }

        return res;
    }
};