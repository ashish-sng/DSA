//https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

import java.util.*;

class Solution {
	public String firstNonRepeating(String s) {
		// code here
		int[] charFreq = new int[26];
		Queue<Character> q = new ArrayDeque<>();
		StringBuilder ans = new StringBuilder();
		
		for (int i = 0; i < s.length(); i++) {
			char ch = s.charAt(i);
			charFreq[ch - 'a']++;
			q.add(ch);
			
			while (!q.isEmpty() && charFreq[q.peek() - 'a'] > 1) {
				q.poll();
			}
			
			char insert = '#';
			
			if (!q.isEmpty()) {
				insert = q.peek();
			}
			
			ans.append(insert);
		}
		
		return ans.toString();
	}
}
