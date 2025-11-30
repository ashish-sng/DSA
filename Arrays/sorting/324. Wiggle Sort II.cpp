// 324. Wiggle Sort II

void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    vector<int> res = nums;
    sort(res.begin(), res.end());

    int i = (n - 1) / 2, j = n - 1;

    int k = 0;
    while (k < nums.size()) {
        if (k % 2 == 0) {
            nums[k++] = res[i--];
        } else {
            nums[k++] = res[j--];
        }
    }
}