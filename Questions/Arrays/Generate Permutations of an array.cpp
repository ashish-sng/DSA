// Generate Permutations of an array -
// https://www.geeksforgeeks.org/problems/generate-permutations-of-an-array/1

// Solution
class Solution {
	public:
	void calculatePermutation(int index, vector<int>& arr, vector<vector<int>> & ans) {
		if (index == arr.size()) {
			ans.push_back(arr);
			return;
		}
		
		for (int i = index; i < arr.size(); i++) {
			swap(arr[i], arr[index]);
			
			calculatePermutation(index + 1, arr, ans);
			
			swap(arr[index], arr[i]);
		}
	}
	vector<vector<int>> permuteDist(vector<int>& arr) {
		// code here
		vector<vector<int>> ans;
		calculatePermutation(0, arr, ans);
		return ans;
	}
};
