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
            j = l + k - 1;
            for(int m = 0; m < k/2; m++){
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