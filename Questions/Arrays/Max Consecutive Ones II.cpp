// https://takeuforward.org/plus/dsa/problems/max-consecutive-ones-ii

// Solution 

class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        // Your code goes here
        int n = nums.length;
        int left = 0, right = 0, maxLength = 0, lastZeroIndex = -1;
        while(right < n){
            if(nums[right] == 0){
                if(lastZeroIndex != -1){
                    left = lastZeroIndex + 1;
                }

                lastZeroIndex = right;
            }

            maxLength = Math.max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
}