#include <stdio.h>

double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2,
                              int nums2Size) {
  int nums3Size = nums1Size + nums2Size;
  int merge[nums3Size];

  int *nums3;
  if (nums1Size == 0) {
    nums3 = nums2;
  } else if (nums2Size == 0) {
    nums3 = nums1;
  } else {
    nums3 = merge;
    int n1 = 0; // index of nums1
    int n2 = 0; // index of nums2
    int n3 = 0; // index of nums3

    while (n3 < nums3Size) {
      if (nums1[n1] <= nums2[n2]) {
        nums3[n3] = nums1[n1];
        n1++;
        n3++;
      } else {
        nums3[n3] = nums2[n2];
        n2++;
        n3++;
      }

      if (n1 >= nums1Size /*!nums1[n1]*/) {
        for (int i = n2; i < nums2Size; i++) {
          nums3[n3] = nums2[i];
          n3++;
        }
        printf("no nums1\n");
        printf("n3 = %d\n", n3);
        printf("n1 = %d\n", n1);
        printf("n2 = %d\n", n2);
        break;
      } else if (n2 >= nums2Size /*!nums2[n2]*/) {
        for (int i = n1; i < nums1Size; i++) {
          nums3[n3] = nums1[i];
          n3++;
        }
        printf("no nums2\n");
        printf("n3 = %d\n", n3);
        printf("n1 = %d\n", n1);
        printf("n2 = %d\n", n2);
        break;
      }
    }
  }
  // debugging
  for (int i = 0; i < nums3Size; i++) {
    printf("%d ", nums3[i]);
  }
  printf("\n");

  double median = 0.0;
  int med = nums3Size / 2;
  if (nums3Size % 2 == 0) {
    median = (double)(nums3[med - 1] + nums3[med]) / 2;
    return median;
  } else {
    median = nums3[med];
    return median;
  }
  return 0.0;
}

int main() {
  int nums1[2] = {2, 3};
  int nums2[1] = {1};
  double output = 0.0;
  output = findMedianSortedArrays(nums1, 2, nums2, 1);
  printf("Median = %f\n", output);
  return 0;
}