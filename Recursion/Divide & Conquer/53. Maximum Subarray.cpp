// 53. Maximum Subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int j = 0, ans = INT_MIN, curr_max = 0;
        while (j < nums.size()) {
            curr_max += nums[j];
            curr_max = max(nums[j], curr_max);
            ans = max(ans, curr_max);
            j++;
        }
        return ans;
    }
};