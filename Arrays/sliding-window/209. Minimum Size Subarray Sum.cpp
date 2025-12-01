// 209. Minimum Size Subarray Sum

int minSubArrayLen(int target, vector<int>& nums) {
    int i = 0, j = 0, ans = INT_MAX;
    int sum = 0;
    while (j < nums.size()) {
        sum += nums[j];
        while (sum >= target && i <= j) {
            ans = min(ans, j - i + 1);
            sum -= nums[i];
            i++;
        }
        j++;
    }
    return ans == INT_MAX ? 0 : ans;
}