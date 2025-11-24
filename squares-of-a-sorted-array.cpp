// Leetcode Problem: 977. Squares of a Sorted Array 

// ------ APPROACH ------
// check for the absolute value which is bigger from both ends and place its square at the end of the result array.
vector<int> squaresOfASortedArray(vector<int>& nums) {
    vector<int> ans(nums.size());
    int l=0,r=nums.size()-1;
    int pos = nums.size()-1;
    while(l<=r){
        if(abs(nums[r])>abs(nums[l])){
            ans[pos--] = nums[r]*nums[r];
            r--;
        }
        else{
            ans[pos--] = nums[l]*nums[l];
            l++;
        }
    }
    return ans;
}