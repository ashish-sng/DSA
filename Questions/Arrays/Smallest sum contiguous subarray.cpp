// Smallest sum contiguous subarray -
// https://www.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1

// Solution
class Solution {
	public:
	int smallestSumSubarray(vector<int>& a) {
		// Code here
		int n = a.size();
		int currSum = a[0];
		int minSum = a[0];
		for (int i = 1; i < n; i++) {
			currSum = min(a[i], a[i] + currSum);
			minSum = min(minSum, currSum);
		}
		return minSum;
	}
};