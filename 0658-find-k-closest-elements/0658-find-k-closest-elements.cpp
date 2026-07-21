class Solution {
public:

    struct cmp
{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b)
    {
        if (a.first != b.first)
            return a.first < b.first;   // larger distance should stay on top

        return a.second < b.second;     // if same distance, larger value should stay on top
    }
};

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp>pq; 

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();

        for (int num : arr)
        {
            int dist = abs(num - x);

            pq.push({dist, num});

            if (pq.size() > k)
                pq.pop();
        }
        vector<int> res;

        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};