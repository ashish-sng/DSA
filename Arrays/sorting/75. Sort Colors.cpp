// 75. Sort Colors
// partition function used to partion the array around a pivot
int partition(vector<int>& nums, int pivot, int startI){
    int i = startI;
    int j = startI + 1;
    while(j < nums.size()){
        if(nums[j] < pivot){
            i++;
            swap(nums[i], nums[j]);
        }
        j++;
    }

    return i;
}

void sortColors(vector<int>& nums) {
    int pivot = partition(nums, 1, -1); // partitioning the array around pivot 1
    partition(nums, 2, pivot); // partitioning the right side of the array around pivot 2
}