

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void mergeSort(int* nums, int l, int r) {
    if (l < r) {
        int middle = (l + r) / 2;
        mergeSort(nums, l, middle);
        mergeSort(nums, middle + 1, r);
        merge(nums, l, middle, r);
    }
    return;
}

void merge(int* nums, int l, int m, int r) {
    int n1 = l;     // first index of array 1
    int n2 = m + 1; // first index of array 2
    int* temp[r - l + 1];
    int k = 0;
    
    while (n1 <= m && n2 <= r) {
        if(nums[n1] <= nums[n2]) {
            temp[k] = nums[n1];
            n1++;
        }
        else {
            temp[k] = nums[n2];
            n2++;
        }
        k++;
    }
    while(n1 <= m) {
        temp[k] = nums[n1];
        k++;
        n1++;
    }
    while(n2 <= r) {
        temp[k] = nums[n2];
        k++;
        n2++;
    }
    
    for (int i = l; i <= r; i++) {
        nums[i] = temp[i - l];
    }
    printf("\n");
    
    
    return;
}

int* sortArray(int* nums, int numsSize, int* returnSize){    
    // Merge Sort O(nlogn)
    *returnSize = numsSize; 
    // call mergeSort function
    mergeSort(nums, 0, numsSize - 1);
    
    return nums;
}