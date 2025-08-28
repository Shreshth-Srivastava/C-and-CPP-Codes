#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s)
{
    int N = strlen(s),count = 0;
    for (int i = N - 1; i >= 0; i--){
        if(count > 0 && s[i] == ' ') break;
        if(s[i] != ' ') count++;
    }
    return count;
}

int main(void)
{
    char *s = "luffy is still joyboy";
    printf("\n%d\n",lengthOfLastWord(s));
    return 0;
}