class Solution {
public:
    vector<int> dp;
    int climbRecursively(int n) {
        if (n <= 2)
            return n;

        if (dp[n] != 0)
            return dp[n];

        return dp[n] = climbRecursively(n - 1) + climbRecursively(n - 2);
    }
    int climbStairs(int n) {
        dp.resize(n + 1, 0);
        return climbRecursively(n);
    }
};