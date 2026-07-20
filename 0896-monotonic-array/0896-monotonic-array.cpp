class Solution {
public:

    bool increasing(vector<int>& nums, int i)
    {
        int n = nums.size();

        if (i == n - 1)
            return true;

        if (nums[i] > nums[i + 1])
            return false;

        return increasing(nums, i + 1);
    }

    bool decreasing(vector<int>& nums, int i)
    {
        int n = nums.size();

        if (i == n - 1)
            return true;

        if (nums[i] < nums[i + 1])
            return false;

        return decreasing(nums, i + 1);
    }

    bool isMonotonic(vector<int>& nums) {
        return increasing(nums, 0) || decreasing(nums, 0);
    }
};