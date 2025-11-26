// LeetCode Problem: Remove Duplicates from Sorted Array
// Given a sorted array nums, remove the duplicates in-place such that each element appears only once
// and returns the new length.

// As the array is sorted, duplicates will be adjacent and we can just check if the next element is greater
// than the current element and then do a swap.
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    for (int j = 0; j < n; j++) {
        if (nums[j] > nums[i]) {
            i++;
        }
        nums[i] = nums[j];
    }
    return i + 1;
}