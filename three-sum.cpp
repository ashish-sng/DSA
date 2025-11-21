// three sum problem solution in C++
 vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) // skip duplicates of i after precessing
            continue;

        int target = -nums[i]; // search for the pair which sums to -nums[i]
        int j = i + 1, k = n - 1;

        while (j < k) {
            int sum = nums[j] + nums[k];

            if (sum == target) {
                uniqueTriplets.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
                // Skip duplicates for j and k
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            } else if (sum > target) {
                k--;
            } else {
                j++;
            }
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}
