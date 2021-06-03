#include <limits.h>
#include <stdio.h>

int myAtoi(char *s) {
  int digit = 0;
  long long int num = 0;
  int negative = 0;
  int positive = 0;
  int alpha = 0;
  int dig = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == ' ') {
      if (dig == 1 || positive || negative)
        break;
      continue;
    }
    if (i > 0 && dig == 1 && (s[i] == '-' || s[i] == '+'))
      break;
    if (s[i] == '-') {
      if (positive == 1 || dig == 1 || negative)
        return 0;
      negative = 1;
      continue;
    }
    if (s[i] == '+') {
      if (negative == 1 || dig == 1 || positive)
        return 0;
      positive = 1;
      continue;
    }
    digit = s[i] - '0';
    if (digit > 9 || digit < 0) {
      alpha = 1;
      continue;
    }
    if (alpha == 1)
      break;
    num = num * 10 + digit;
    if (negative) {
      if (num >= ((long long int)INT_MIN) * (-1)) {
        num = ((long long int)INT_MIN) * (-1);
        break;
      }
    } else {
      if (num >= INT_MAX) {
        num = INT_MAX;
        break;
      }
    }
    dig = 1;
  }

  if (negative == 1)
    num *= -1;
  if (num < INT_MIN)
    return INT_MIN;
  else if (num > INT_MAX)
    return INT_MAX;
  return num;
}

int main() {
  // test cases
  char *s1 = "321";
  char *s2 = "   -42";
  char *s3 = "4193 with words";
  char *s4 = "words and 987";
  char *s5 = "3a1439";

  printf("%d\n", INT_MIN);

  // outputs
  int o1 = myAtoi(s1);
  printf("myAtoi(%s) = %d\n", s1, o1);
  int o2 = myAtoi(s2);
  printf("myAtoi(%s) = %d\n", s2, o2);
  int o3 = myAtoi(s3);
  printf("myAtoi(%s) = %d\n", s3, o3);
  int o4 = myAtoi(s4);
  printf("myAtoi(%s) = %d\n", s4, o4);
  int o5 = myAtoi(s5);
  printf("myAtoi(%s) = %d\n", s5, o5);

  return 0;
}