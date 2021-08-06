int partition(int *nums, int l, int r) {
    int i = l - 1;
    
    for (int j = l; j < r; j++) {
        if (nums[j] <= nums[r]) {
            i++;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
    
    int temp = nums[i + 1];
    nums[i + 1] = nums[r];
    nums[r] = temp;
    
    return i + 1;
}
void quickSort(int *nums, int l, int r) {
    if (l < r) {
        int i = 0;
        int part = partition (nums, l, r);
        
        quickSort(nums, l, part - 1);
        quickSort(nums, part + 1, r);
    }
    return;
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    
    // Quick Sort O(n^2)
    *returnSize = numsSize;
    quickSort(nums, 0, numsSize - 1);
    
    return nums;
}