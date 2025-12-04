// 152. Maximum Product Subarray

int maxProduct(vector<int>& nums) {
    // Initialize tracking variables:
    // min_product: minimum product ending at current position (handles negative numbers)
    // max_product: maximum product ending at current position
    // res: overall maximum product found so far (start with first element)
    int min_product = nums[0], max_product = nums[0], res = nums[0];

    // Process each element starting from the second one
    for (int i = 1; i < nums.size(); i++) {
        // CRITICAL: When current number is negative, swap max and min
        // Why? Because multiplying by negative flips signs:
        // - Large positive * negative = Large negative
        // - Large negative * negative = Large positive
        if (nums[i] < 0) {
            swap(max_product, min_product);
        }

        // Update max_product: Three possibilities:
        // 1. Start new subarray at current position: nums[i]
        // 2. Extend previous max subarray: max_product * nums[i]
        // 3. Extend previous min subarray: (implicitly considered after swap)
        // We take the maximum of these options
        max_product = max(nums[i], max_product * nums[i]);
        
        // Update min_product: Similar logic but take minimum
        // Important to track min because it can become max when multiplied by negative
        min_product = min(nums[i], min_product * nums[i]);

        // Update overall result with current maximum ending here
        res = max(res, max_product);
    }

    return res;
}