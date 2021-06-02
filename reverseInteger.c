#include <limits.h>
#include <stdio.h>

int reverse(int x) {
  /*
      Constraints: -2^31 <= x <= 2^31 - 1
  */
  int negative = 0;
  int lastDigit = 0;
  long int rev = 0;

  if (x < 10 && x >= 0) // when x is 1s.
    return x;
  else if (x < (INT_MIN) || x > (INT_MAX))
    return 0;
  if (x < 0) {
    x *= -1;
    negative = 1;
  }

  while (x > 0) {
    lastDigit = x % 10;
    rev = (rev * 10) + lastDigit;
    x /= 10;
  }

  if (negative == 1)
    rev *= -1;

  if (rev < INT_MIN || rev > INT_MAX)
    return 0;

  return rev;
}

int main() {
  // test cases
  int x1 = 321;
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