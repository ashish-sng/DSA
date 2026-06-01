// Question link: https://www.geeksforgeeks.org/problems/minimum-swaps-required-to-group-all-1s-together2451/1

// Solution 
class Solution {
	public:
	int minSwaps(vector<int>& arr) {
		// code here
		int totalOnes = 0;
		for (int i : arr) {
			if (i == 1) {
				totalOnes++;
			}
		}
		
		int i = 0, j = 0, currOnes = 0, maxOnes = 0;
		while (j < totalOnes) {
			if (arr[j] == 1) {
				currOnes++;
			}
			j++;
		};
		
		maxOnes = max(currOnes, maxOnes);
		
		while (j < arr.size()) {
			if (arr[j] == 1) {
				currOnes++;
			}
			if (arr[i++] == 1) {
				currOnes--;
			}
			
		    maxOnes = max(currOnes, maxOnes);
			j++;
		};
		
		return totalOnes == 0 ? -1 : totalOnes - maxOnes;
	};
};
