int balancedStringSplit(char * s){
    int balance = 0;
    int split = 0;
    int i = 0;
    
    while(s[i]) {
        if(s[i] == 'L') balance++;
        else balance--;
        
        if(balance == 0) split++;
        
        i++;
    }
    
    return split;
}