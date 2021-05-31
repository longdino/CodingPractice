#include <stdio.h>

char *longestPalindrome(char *s) {
  /*
      Constraints: 1 <= s.length <= 1000
      s consist of only digits and English letters (lower case and/or upper
     case)
  */
  return s;
}

int main() {
  // test cases
  char *s1 = "babad";
  char *s2 = "cbbd";
  char *s3 = "a";
  char *s4 = "ac";

  // expected outcomes
  char *o1 = longestPalindrome(s1);
  char *o2 = longestPalindrome(s2);
  char *o3 = longestPalindrome(s3);
  char *o4 = longestPalindrome(s4);

  // display expected outputs and actual outputs
  printf("Expected Output for %s: 'bab' or 'aba'\n", s1);
  printf("Actual Output for %s: %s\n", s1, o1);
  printf("\n");
  printf("Expected Output for %s: 'bb'\n", s2);
  printf("Actual Output for %s: %s\n", s2, o2);
  printf("\n");
  printf("Expected Output for %s: 'a'\n", s3);
  printf("Actual Output for %s: %s\n", s3, o3);
  printf("\n");
  printf("Expected Output for %s: 'a'\n", s4);
  printf("Actual Output for %s: %s\n", s4, o4);

  return 0;
}