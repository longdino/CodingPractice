void reverseString(char* s, int sSize){    
    int middle = sSize / 2;
    int i = 0;
    int j = sSize - 1;
    
    char temp = 'a';
    while(i < middle) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        
        i++;
        j--;
    }
    return;
}