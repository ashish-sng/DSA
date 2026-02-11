// Recursive solution
class Solution {
public:
    int solve(int index, vector<int>& nums){
        if(index >= nums.size()) return 0;

        int pick = nums[index] + solve(index + 2, nums);

        int notPick = solve(index + 1, nums);

        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        return solve(0, nums);
    }
};

// Optimzed approach
class Solution {
public:vector<int> dp;
    int solve(int index, vector<int>& nums){
        if(index >= nums.size()) return 0;

        if(dp[index] != -1) return dp[index];

        int pick = nums[index] + solve(index + 2, nums);

        int notPick = solve(index + 1, nums);

        return dp[index] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n, -1);
        return solve(0, nums);
    }
};