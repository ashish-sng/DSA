//  https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

import java.util.*;

class Solution {
	public Queue<Integer> reverseFirstK(Queue<Integer> q, int k) {
		// code here
		int n = q.size();
		
		if (k > n)
			return q;
		
		Stack<Integer> rev = new Stack<>();
		
		for (int i = 0; i < k; i++) {
			rev.push(q.poll());
		}
		
		while (!rev.isEmpty()) {
			q.offer(rev.pop());
		}
		
		for (int i = 0; i < n - k; i++) {
			q.offer(q.poll());
		}
		
		return q;
	}
}
