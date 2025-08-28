bool isPalindrome(int x) {
    if(x<0) return false;
    else{
        char str[11];
        sprintf(str,"%d",x);
        for(int i = 0;i<=strlen(str)/2;i++){
            if(str[i] != str[strlen(str) - 1 - i]){
                return false;
            }
        }
    }
    return true;
}