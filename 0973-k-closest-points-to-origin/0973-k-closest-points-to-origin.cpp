class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int, vector<int>>> pq;

        for(auto &i: points)
        {
            int x = i[0];
            int y = i[1];

            int dist = x * x + y * y;

            pq.push({dist, i});

            if(pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<vector<int>> res;

        while(!pq.empty())
        {
           res.push_back(pq.top().second);
           pq.pop(); 
        }
        return res;
    }
};