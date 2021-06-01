#include <stdio.h>

int reverse(int x) {
  /*
      Constraints: -2^31 <= x <= 2^31 - 1
  */
  if (x < 10)
    return x;
  return 0;
}

int main() {
  // test cases
  int x1 = 123;
  int x2 = -123;
  int x3 = 120;
  int x4 = 0;

  // outputs
  int o1 = reverse(x1);
  printf("Expected Output for %d: 321\n", x1);
  printf("Actual Output for %d: %d\n\n", x1, o1);
  int o2 = reverse(x2);
  printf("Expected Output for %d: -321\n", x2);
  printf("Actual Output for %d: %d\n\n", x2, o2);
  int o3 = reverse(x3);
  printf("Expected Output for %d: 21\n", x3);
  printf("Actual Output for %d: %d\n\n", x3, o3);
  int o4 = reverse(x4);
  printf("Expected Output for %d: 0\n", x4);
  printf("Actual Output for %d: %d\n\n", x4, o4);
  return 0;
}