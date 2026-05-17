// 3712. Sum of Elements With Frequency Divisible by K -
// https://leetcode.com/problems/sum-of-elements-with-frequency-divisible-by-k/description/

// Solution
class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        int result = 0;
        for (auto& num : mp) {
            if (num.second % k == 0) {
                result += num.first * num.second;
            }
        }
        return result;
    }
};