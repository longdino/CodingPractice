int search(int* nums, int numsSize, int target){
    int upper = numsSize - 1;
    int lower = 0;
    int mid = (upper + lower) / 2;
    
    while(lower <= upper) {
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) {
            lower = mid + 1;
            mid = (upper + lower) / 2;
        }
        else {
            upper = mid - 1;
            mid = (upper + lower) / 2; 
        }
    }
    return -1;
}