#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_ELEMENTS 1000
int list[MAX_ELEMENTS];
int count;

//이진 탐색
int binsearch(int list[], int n, int searchnum){
    int left = 0;
    int right = n - 1;
    int middle;
    count = 0;
    
    while(left <= right) {
        count++;
        middle = (left+right)/2;
        if(searchnum == list[middle]) return middle;
        else if(searchnum < list[middle]) right = middle - 1;
        else left = middle + 1;
    }
    return -1;
}

//순차 탐색
int seqsearch(int list[], int n, int searchnum){
    int i;
    
    count = 0;
    for(i=0; i<n; i++){
        count++;
        if(searchnum == list[i]) return i;
    }
    return -1;
}

int main(void) {
    int i, value = 1;
    int search_number;
    int return_value;
    
    clock_t start, finish;
    clock_t duration;
    
    list[0] = 0;
    for(i=1; i < MAX_ELEMENTS; i++){
        list[i] = value;
        value = value + 2;
    }
    printf("숫자를 입력하세요 :");
    scanf("%d", &search_number);
    
    start = clock();
    return_value = seqsearch(list, MAX_ELEMENTS, search_number);
    finish = clock();
    duration = finish - start;
    printf("%d millisecond\n", duration);
    printf("순차 탐색의 수행 횟수 = %d\n\n", count);
    
    return_value = binsearch(list, MAX_ELEMENTS, search_number);
    finish = clock();
    duration = finish - start;
    printf("%d millisecond\n", duration);
    printf("이진 탐색의 수행 횟수 = %d\n\n", count);
    
    if(return_value == -1) printf("숫자가 발견되지 않았습니다\n");
    else printf("숫자가 위치 %d에서 발견되었습니다.\n", return_value);
}
