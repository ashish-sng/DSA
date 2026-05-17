// Minimum Platforms -
// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// Solution
class Solution {
	public:
	int minPlatform(vector<int>& arr, vector<int>& dep) {
		// code here
		int n = arr.size();
		vector<int> timeline(2401, 0);
		for (int i = 0; i < n; i++) {
			int arrival = arr[i];
			int departure = dep[i];
			
			timeline[arrival] += 1;
			
			timeline[departure + 1] -= 1;
			
		}
		
		for (int i = 1; i < 2401; i++) {
			timeline[i] += timeline[i - 1];
		}
		
		int ans = *max_element(timeline.begin(), timeline.end());
		return ans;
	}
};
