/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    int temp = 0;
    *returnSize = numsSize;
    
    for (int i = numsSize-1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if(nums[j] > nums[j+1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    
    return nums;
}