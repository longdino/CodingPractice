int search(int* nums, int numsSize, int target){
    int i = numsSize / 2;
    int flag = 0;
    
    while(i < numsSize && i > -1) {
        if (nums[i] == target) return i;
        else if (nums[i] < target) {
            i++;
            flag = 1;
            continue;
        }
        else {
            if (flag == 1) return -1;
            i--;
            flag = 0;
        }
    }
    return -1;
}