

bool areAlmostEqual(char * s1, char * s2){
    int i = 0;
    int index1 = -9999;
    int index2 = -9999;
    char c1 = 'a';
    char c2 = 'a';
    char c3 = 'a';
    char c4 = 'a';
    
    while(s1[i] && s2[i]){
        if(s1[i] != s2[i]) {
            if(index1 > -1 && index2 > -1) return false;
            if(index1 > -1 && index2 < 0) {
                index2 = i;
                c2 = s1[i];
                c4 = s2[i];
            }
            else {
                index1 = i;
                c1 = s1[i];
                c3 = s2[i];
            }
        }
        
        i++;
    }
    
    if(index1 > -1 && index2 > -1) {
        if(c1 == c4 && c2 == c3) return true;
    }
    else if(strcmp(s1, s2) == 0) return true;
    
    return false;
}