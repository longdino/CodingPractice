#include <stdio.h>

int lengthOfLongestSubstring(char *s) {
  if (*s == 0) // when given s is NULL
    return 0;

  int max = 0;

  for (int i = 0; s[i]; i++) {
    for (int j = 0; s[j]; j++) {
      int duplicate = 0;
      for (int k = i; k < j; k++) {
        if (s[k] == s[j]) { // duplicates
          duplicate = 1;
          break;
        }
      }
      if (duplicate == 1)
        break;

      // debugging
      for (int k = i; k <= j; k++) {
        printf("%c", s[k]);
      }
      int length = j - i + 1;
      if (length > max) {
        max = length;
      }

      // debugging
      if (i <= j)
        printf(", %d\n", length);
    }
  }

  return max;
}

int main() {
  int output;
  output = lengthOfLongestSubstring("abcabcbb");

  printf("%d\n", output);
  return 0;
}
