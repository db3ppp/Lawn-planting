//https://business.programmers.co.kr/tryouts/3/challenges/10855

//algorithm 1
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int arr[], size_t arr_m) {
    bool answer = true;
    int i;
    int sum1=0,sum2 = 0;
    
    for(i=0; i<arr_m; i++){
        sum1+= arr[i]; //input's sum
        }
    for(i=1; i<=arr_m; i++){
        sum2+= i; //array size's sum
    }
    if(sum1 != sum2)
        answer = false;
    
    return answer;
}

//algorithm 2
int* solution(int n) {
    int* answer = (int*)malloc( n * sizeof(int) );
    int i = 0;
    for(i=0; i<n; i++)
        
answer[i]=i+1;

    return answer;
}

//algorithm 3
bool solution(char* s) {
    int p_num = 0;
    int y_num = 0;
    int i=0;
    for(i=0; i<=strlen(s)-1; i++){
        if( s[i]=='p'|| s[i]=='P' ) {
            p_num++;
        }
        else if( s[i]=='y' || s[i]=='Y') {
            y_num++;
        }
    }        
    return p_num == y_num;
}
