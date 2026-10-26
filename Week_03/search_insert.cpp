class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = -1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (target == nums[mid])
            {
                ans = mid;
                return ans;
            }
            else if (target < nums[mid]) r = mid - 1;
            else l = mid + 1;
        }
        if (ans == -1)
        {
            if (target < nums[0]) return 0;
            else if (target > nums[nums.size() - 1]) return nums.size();
            else {
                for (int i = 0; i < nums.size() - 1; i++)
                {
                    if (target > nums[i] && target < nums[i + 1])
                        return i + 1;
                }
            }

        }
        return ans;
    }
};