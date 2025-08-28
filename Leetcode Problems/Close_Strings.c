#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//Better Solution

int cmp(const void *a,const void *b){
    return(*(int *)a - *(int *)b);
}

bool closeStrings(char* word1, char* word2){
    if(strlen(word1) != strlen(word2)) return false;
    else{
        int count1[26] = {0},count2[26] = {0};
        for(int i = 0;word1[i];i++) count1[word1[i] - 'a']++;
        for(int i = 0;word2[i];i++) count2[word2[i] - 'a']++;
        for(int i = 0;i<26;i++){
            if((count1[i] > 0 && count2[i] == 0) || (count1[i] == 0 && count2[i] > 0)) return false;
        }
        qsort(count1,26,sizeof(int),cmp);
        qsort(count2,26,sizeof(int),cmp);
        for(int i = 0;i<26;i++){
            if(count1[i] != count2[i]) return false;
        }
        return true;
    }
}

//My solution

/*void swap(int *arr, int index, int i){
    int temp = arr[index];
    arr[index] = arr[i];
    arr[i] = temp;
}

int search(char *c, int index, char target){
    for(int i = 0;i<index;i++){
        if(c[i] == target){
            return i;
        }
    }
    return -1;
}

int check(int *arr1, int target, int index, int size){
    for(int i=index;i<size;i++){
        if(arr1[i] == target){
            swap(arr1,index,i);
            return 1;
        }
    }
    return 0;
}

int doubleCheck(char *c, char *d,int c1){
    int flag;
    for(int i = 0;i<c1;i++){
        flag = -1;
        for(int j = 0;j<c1;j++){
            if(c[i] == d[j]){
                flag = 1;
                break;
            }
        }
        if(flag == -1) return -1;
    }
    return 1;
}

bool closeStrings(char* word1, char* word2){
    int count1 = 0, count2 = 0;
    for (int i = 0; word1[i]; i++) count1++;
    for (int j = 0; word2[j]; j++) count2++;
    if(count1 != count2) return false;
    char a[count1], b[count2];
    for(int i = 0;word1[i];i++){
        a[i] = word1[i];
        b[i] = word2[i];
    }
    int arr1[count1],arr2[count2];
    char c[count1],d[count2];
    int c1 = 0,d1 = 0;
    c[c1++] = a[0];
    d[d1++] = b[0];
    for(int i = 0;i<count1;i++){
        arr1[i] = 1;
        arr2[i] = 1;
    }
    for (int i = 1;i<count1; i++)
    {
        int result = search(c,c1,a[i]);
        if(result == -1) c[c1++] = a[i];
        else arr1[result]++;
    }
    for (int i = 1;i<count2; i++)
    {
        // printf("\nb[i] = %c",b[i]);
        int result = search(d,d1,b[i]);
        if(result == -1) d[d1++] = b[i];
        else arr2[result]++;
    }
    if(doubleCheck(c,d,c1) == -1) return false;
    for(int i = 0;i<c1;i++){
        if(arr1[i] != arr2[i]){
            if(!check(arr1,arr2[i],i,c1)) return false;
        }
    }
    return true;
}*/

int main(void){
    char *chr1 = "uiuiiuuiuuuuuuwiwuuwiiiiuuuuwwiwuuu", *chr2 = "rppprrpurrrrrurrrurprprprprpuprruur";
    printf("\nAnswer: %d",closeStrings(chr1,chr2));
    return 0;
}

// void swap(char *word1, int index, int i){
//     char temp = word1[index];
//     word1[index] = word1[i];
//     word1[i] = temp;
// }

// int Operation1(char *word1, char target, int index){
//     for(int i = index;word1[i];i++){
//         if(word1[i] == target){
//             swap(word1, index, i);
//             return 1;
//         }
//     }
//     return 0;
// }

// bool closeStrings(char* word1, char* word2) {
//     int count1 = 0, count2 = 0;
//     for (int i = 0; word1[i]; i++) count1++;
//     for (int j = 0; word2[j]; j++) count2++;
//     if(count1 != count2) return false;
//     char a[count1], b[count2];
//     for(int i = 0;word1[i];i++){
//         a[i] = word1[i];
//         b[i] = word2[i];
//     }
//     for(int i = 0; a[i]; i++){
//         if(a[i] != b[i]){
//             if(!Operation1(a,b[i],i)) return false;            
//         }
//     }
//     return true;
// }