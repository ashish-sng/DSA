// https://www.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1

import java.util.*;

class Solution {
	public ArrayList<String> generateBinary(int n) {
		// code here
		ArrayList<String> ans = new ArrayList<>();
		
		for (int i = 1; i <= n; i++) {
			StringBuilder curr = new StringBuilder();
			int currentBinary = i;
			
			while (currentBinary > 0) {
				curr.append(String.valueOf(currentBinary % 2));
				currentBinary = currentBinary / 2;
			}
			
			ans.add(curr.reverse().toString());
		}
		
		return ans;
	}
}

