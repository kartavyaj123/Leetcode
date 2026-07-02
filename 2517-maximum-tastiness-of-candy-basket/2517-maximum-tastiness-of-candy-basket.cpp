class Solution {
public:

    bool fun(vector<int>&price, int n, int k, int guess)
    {
        int candy = 1; 
        int pos = price[0];
        int i = 1;
        
        for(i ; i < n; i++)
        {
            int dist = price[i] - pos;
            if(dist < guess)
            {
                continue;
            }
                candy++;
                pos = price[i];
        }
        if(candy >= k)
        return true;
        else
        return false;
    }

    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int low = 1; int high = price[n - 1] - price[0];
        int res = 0;
        
        while(low <= high)
        {
            int guess = (low + high) / 2;
            if(fun(price, n, k, guess))
            {
                res = guess; 
                low = guess + 1;
            }
            else {
                high = guess - 1;
            }
        }
        return res;
    }
};