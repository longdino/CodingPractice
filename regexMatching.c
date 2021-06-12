#include <stdbool.h>
#include <stdio.h>

// recursive function
bool _match2(char* s, int i, char* p, int j) {
	//printf("[%s]  [%s]\n", &s[i], &p[j]);
	bool match = true;
	if (!s[i]) {
		if (!p[j]) {
			return true;
		}
		// when it is last element: that means it could go thorugh all elements matching.
		//printf("Finished! i = %d j = %d \n", i, j);
		//printf("[%s]\n[%s]\n\n", &s[i], &p[j]);
		if (p[j] == '*' && !p[j + 1]) return true;
		if (p[j + 1] && p[j + 1] == '*' && !p[j + 2]) return true;
		return false;
	}
	if (!p[j]) {
		return false;
	}
	if (p[j] == '.' || s[i] == p[j]) {
		// when the elements are matched or the pattern is '.'
		//printf("Matching! i = %d j = %d \n", i, j);
		//printf("[%s]\n[%s]\n\n", &s[i], &p[j]);
		return _match2(s, i + 1, p, j + 1);
	}
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
			//printf("Star! i = %d j = %d \n", i, j);
			//printf("[%s]\n[%s]\n\n", &s[i], &p[j]);
			if (p[j - 1] == '.' || p[j - 1] == s[i]) {
				bool m = _match2(s, i, p, j + 1); 
				if (m == false) {
					return _match2(s, i + 1, p, j);
				}
				return m;
			}
			if (p[j - 1] != s[i]) {
				return _match2(s, i, p, j + 1);
			}

			if (_match2(s, i, p, j - 1) || p[j - 1] == '.') {
				//printf("Dot or previous! i = %d j = %d \n", i, j);
				//printf("[%s]\n[%s]\n\n", &s[i], &p[j]);
				return _match2(s, i, p, j - 1);
			}
			else {
				//printf("Zero! i = %d j = %d \n", i, j);
				//printf("[%s]\n[%s]\n\n", &s[i], &p[j]);
				return _match2(s, i, p, j + 1);
			}

		}
		else {    // when s[i] != p[j] 
			if (p[j + 1] == '*') {
				//printf("Zero! i = %d j = %d \n", i, j);
				//printf("[%s]\n[%s]\n\n", &s[i], &p[j]);
				return _match2(s, i, p, j + 2);
			}
			else {
				//printf("Not Maching! i = %d j = %d \n", i, j);
				//printf("[%s]\n[%s]\n\n", &s[i], &p[j]);
				return false;
			}
		}
	}

	return false;
}

bool isMatch(char* s, char* p) {
	/*
			'.': matches any single character
			'*': matches zero or more of the preceding element
	*/

	return _match2(s, 0, p, 0);
}

int main() {
	// test cases
	char* s1 = "aa";
	char* s2 = "ab";
	char* s3 = "aab";
	char* s4 = "mississippi";
	char* s5 = "aaa";

	char* p1 = "a";
	char* p2 = "a*";
	char* p3 = ".*";
	char* p4 = "c*a*b";
	char* p5 = "mis*is*p*.";
	char* p6 = "ab*a*c*a";
	char* p7 = "a*a";

	// outputs
	bool o1 = isMatch(s1, p1);
	printf("isMatch(%s, %s): %d\n", s1, p1, o1);
	printf("===========================================\n");
	bool o2 = isMatch(s1, p2);
	printf("isMatch(%s, %s): %d\n", s1, p2, o2);
	printf("===========================================\n");
	bool o3 = isMatch(s2, p3);
	printf("isMatch(%s, %s): %d\n", s2, p3, o3);
	printf("===========================================\n");
	bool o4 = isMatch(s3, p4);
	printf("isMatch(%s, %s): %d\n", s3, p4, o4);
	printf("===========================================\n");
	bool o5 = isMatch(s4, p5);
	printf("isMatch(%s, %s): %d\n", s4, p5, o5);
	printf("===========================================\n");
	bool o6 = isMatch(s5, p6);
	printf("isMatch(%s, %s): %d\n", s5, p6, o6);
	printf("===========================================\n");
	bool o7 = isMatch(s5, p7);
	printf("isMatch(%s, %s): %d\n", s5, p7, o7);

	return 0;
}
