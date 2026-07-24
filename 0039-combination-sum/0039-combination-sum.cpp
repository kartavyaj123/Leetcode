class Solution {
public:

    void fun(vector<int> &candidates, int n, int idx, vector<int> &diary, int sum, vector<vector<int>> &res, int target)
    {
        if(idx == n)
        {
            if(sum == target)
                res.push_back(diary);
                return;
        }
        fun(candidates, n, idx + 1, diary, sum, res, target);

        if(candidates[idx] + sum <= target)
        {
            diary.push_back(candidates[idx]);
            sum = sum + candidates[idx];
            fun(candidates, n, idx, diary, sum, res, target);

            diary.pop_back();
            sum = sum - candidates[idx];
        }   
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> diary;
        int sum = 0;
        vector<vector<int>> res;

        fun(candidates, n, 0, diary, sum, res, target);

        return res; 
    }
};