// 912. Sort an Array

// MERGE SORT
class Solution {
public:
    void merge(vector<int>& nums, int left, int mid, int right,
               vector<int>& temp) {
        int i = left, j = mid + 1, k = left;
        while (i <= mid && j <= right) {
            if (nums[i] < nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        while (i < mid + 1) {
            temp[k++] = nums[i++];
        }

        while (j < right + 1) {
            temp[k++] = nums[j++];
        }

        for (int p = left; p <= right; p++) {
            nums[p] = temp[p];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high, vector<int>& temp) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid, temp);
        mergeSort(nums, mid + 1, high, temp);

        merge(nums, low, mid, high, temp);
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> temp(nums.size());
        mergeSort(nums, 0, nums.size() - 1, temp);
        return nums;
    }
};

// QUICK SORT RANDOMIZED
class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low;

        for (int j = low; j < high; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        // RANDOM PIVOT
        int randomIndex = low + rand() % (high - low + 1);
        swap(nums[randomIndex], nums[high]);

        int pivotIndex = partition(nums, low, high);

        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};