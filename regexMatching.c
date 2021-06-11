#include <stdbool.h>
#include <stdio.h>

// recursive function
bool _match2(char *s, int i, char *p, int j) {
    bool match = true;
  if (!s[i] && !p[j]) // when it is last element: that means it could go thorugh all elements matching.
    return true;
  if (p[j] == '.' || s[i] == p[j])  // when the elements are matched or the pattern is '.'
    return _match2(s, i + 1, p, j + 1);
  else {
      if (p[j] == '*') {    
          /*
          * Call _match2() function 
          * Consider these cases:
          *     1. If true: then proceed on to that level
          *     2. If false, but '.': that means true. Proceed on to that level
          *     3. If false, but '*' indicates '0': that could mean true.
          *     4. If false: we're not going to that level
          */
      }
  }

  return false;
}

// non-recursive function: not context-free
bool _match(char *s, int i, char *p, int j) {
  bool match = true;
  while (p[j] || s[i]) {
    // printf("[%s]\n[%s]\n\n", &s[i], &p[j]);
    if (!p[j] && s[i])
      return false;
    if (p[j] == '.') {
      match = true;
      i++;
      j++;
    } else if (p[j] == '*') {
      if (!match) {
        j++;
      } else {
        if (s[i] == p[j - 1]) {
          i++;
        }
        if (p[j - 1] == '.') {
          i++;
        }
        j++;
      }
    } else {
      if (p[j] == s[i]) {
        match = true;
        i++;
        j++;
        continue;
      } else {
        if (p[j + 1] == '*') {
          match = false;
          j++;
        } else { // p[j+1] is '.', null, or alphabet
          return false;
        }
      }
    }
  }
  return match;
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
  char *s5 = "aaa";

  char *p1 = "a";
  char *p2 = "a*";
  char *p3 = ".*";
  char *p4 = "c*a*b";
  char *p5 = "mis*is*p*.";
  char *p6 = "ab*a*c*a";
  char *p7 = "a*a";

  // outputs
  bool o1 = isMatch(s1, p1);
  printf("isMatch(%s, %s): %d\n", s1, p1, o1);
  bool o2 = isMatch(s1, p2);
  printf("isMatch(%s, %s): %d\n", s1, p2, o2);
  bool o3 = isMatch(s2, p3);
  printf("isMatch(%s, %s): %d\n", s2, p3, o3);
  bool o4 = isMatch(s3, p4);
  printf("isMatch(%s, %s): %d\n", s3, p4, o4);
  bool o5 = isMatch(s4, p5);
  printf("isMatch(%s, %s): %d\n", s4, p5, o5);
  bool o6 = isMatch(s5, p6);
  printf("isMatch*%s, %s): %d\n", s5, p6, o6);
  bool o7 = isMatch(s5, p7);
  printf("isMatch*%s, %s): %d\n", s5, p7, o7);

  return 0;
}
