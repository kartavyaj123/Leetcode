class Solution {
public:

    bool fun(vector<int>&position, int n, int m, int guess)
    {
        int ball = 1; 
        int pos = position[0];
        int i = 1;
        
        for(i ; i < n; i++)
        {
            int dist = position[i] - pos;
            if(dist < guess)
            {
                continue;
            }
                ball++;
                pos = position[i];
        }
        if(ball >= m)
        return true;
        else
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1; int high = position[n - 1] - position[0];
        int res = 0;
        
        while(low <= high)
        {
            int guess = (low + high) / 2;
            if(fun(position, n, m, guess))
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