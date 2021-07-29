/*
Given a string s and an integer k, 
reverse the first k characters for 
every 2k characters counting from the 
start of the string.

If there are fewer than k characters left, 
reverse all of them. If there are less than 
2k but greater than or equal to k characters, 
then reverse the first k characters and left 
the other as original.
*/

char * reverseStr(char * s, int k){
    int size = strlen(s);
    
    if(size < k) {
        int i = 0;
        int j = size - 1;
        char temp = 'a';
        while (i < size/2) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    else if(size >= k && size < 2 * k) {
        int i = 0;
        int j = k - 1;
        char temp = 'a';
        while(i < k / 2) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    else {
        int i = 0;
        int j = k - 1;
        int l = 0;
        char temp = 'a';
        
        while(l < size) {
            i = l;
            j = (l + k - 1) >= size ? size - 1 : l + k - 1;
            int n = (j - i + 1) / 2;
            for(int m = 0; m < n; m++){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
            l += 2 * k;
        }
    }
    
    return s;
}