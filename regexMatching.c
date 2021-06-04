#include <stdbool.h>
#include <stdio.h>

bool _match(char *s, int i, char *p, int j) {
  bool match = true;
  while (p[j] || s[i]) {
    if (!p[j] && s[i])
      return false;
    if (p[j] == '.') {

    } else if (p[j] == '*') {
      i++;
      while (_match(s, i, p, j)
    } else {
      if (p[j] == s[i]) {
        i++;
        j++;
        continue;
      } else {
        if (!p[j + 1] || p[j + 1] == '.') {
          return false;
        } else if (p[j + 1] != '*') {
          return false;
        }
        i++;
        j++;
      }
    }
  }
  return true;
}

bool isMatch(char *s, char *p) {
  /*
          '.': matches any single character
          '*': matches zero or more of the preceding element
  */

  return _match(s, 0, p, 0);
}

int main() {
  // test cases
  char *s1 = "aa";
  char *s2 = "ab";
  char *s3 = "aab";
  char *s4 = "mississippi";

  char *p1 = "a";
  char *p2 = "a*";
  char *p3 = ".*";
  char *p4 = "c*a*b";
  char *p5 = "mis*is*p*.";

  // outputs
  bool o1 = isMatch(s1, p1);
  printf("isMatch(%s, %s): %d\n", s1, p1, o1);
  bool o2 = isMatch(s1, p2);
  printf("isMatch(%s, %s): %d\n", s1, p2, o2);
  //   bool o3 = isMatch(s2, p3);
  //   printf("isMatch(%s, %s): %d\n", s2, p3, o3);
  //   bool o4 = isMatch(s3, p4);
  //   printf("isMatch(%s, %s): %d\n", s3, p4, o4);
  //   bool o5 = isMatch(s4, p5);
  //   printf("isMatch(%s, %s): %d\n", s4, p5, o5);
  return 0;
}
