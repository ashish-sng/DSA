// 215. Kth Largest Element in an Array

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int loop = k - 1;
        while (loop--) {
            pq.pop();
        }
        return pq.top();
    }
};