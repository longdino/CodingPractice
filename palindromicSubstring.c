#include <stdio.h>

char buffer[1024];

int isPalindrome(char *s, int start, int end) {
  if ((end - start) % 2 == 0) { // odd size
    int middle = (end - start) / 2 + start;
    for (int i = 1; i <= middle - start; i++) {
      if (s[middle - i] != s[middle + i])
        return 0;
    }
  } else { // even size
    int l = start;
    int r = end;
    for (int i = 0; i < (end - start + 1) / 2; i++, l++, r--) {
      if (s[l + i] != s[r - i])
        return 0;
    }
  }
  return 1;
}

char *longestPalindrome(char *s) {
  /*
      Constraints: 1 <= s.length <= 1000
      s consist of only digits and English letters (lower case and/or upper
     case)
  */
  if (s[1] == 0)
    return s;

  int max = 0;
  int maxi = 0;
  int maxj = 0;
  for (int i = 0; s[i]; i++) {
    for (int j = 0; s[j]; j++) {
      int length = j - i + 1;
      if (length <= max)
        continue;
      if (i <= j) {
        if (isPalindrome(s, i, j)) {
          if (length > max) {
            max = length;
            maxi = i;
            maxj = j;
          }
        }
      }
    }
  }
  int j = 0;
  for (int i = maxi; i <= maxj; i++, j++) {
    buffer[j] = s[i];
  }
  buffer[j] = '\0';

  return buffer;
}

int main() {
  // test cases
  char *s1 = "babad";
  char *s2 = "cbbd";
  char *s3 = "a";
  char *s4 = "ac";

  // outputs
  char *o1 = longestPalindrome(s1);
  printf("Expected Output for %s: 'bab' or 'aba'\n", s1);
  printf("Actual Output for %s: %s\n", s1, o1);
  printf("\n");
  char *o2 = longestPalindrome(s2);
  printf("Expected Output for %s: 'bb'\n", s2);
  printf("Actual Output for %s: %s\n", s2, o2);
  printf("\n");
  char *o3 = longestPalindrome(s3);
  printf("Expected Output for %s: 'a'\n", s3);
  printf("Actual Output for %s: %s\n", s3, o3);
  printf("\n");
  char *o4 = longestPalindrome(s4);
  printf("Expected Output for %s: 'a'\n", s4);
  printf("Actual Output for %s: %s\n", s4, o4);

  return 0;
}