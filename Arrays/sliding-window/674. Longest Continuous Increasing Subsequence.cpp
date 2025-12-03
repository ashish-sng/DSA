// 674. Longest Continuous Increasing Subsequence

// just check in the window and reset the count when the condition is false
int findLengthOfLCIS(vector<int>& nums) {
    int j = 1, n = nums.size();
    int res = 1, count = 1;
    if(n == 1) return 1;
    while(j < n){
        if(nums[j] > nums[j-1]){
            count++;
            res = max(res, count);
        }else{
            count = 1;
        }
        j++;
    }
    return res;
}