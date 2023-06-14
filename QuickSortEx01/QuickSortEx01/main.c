#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_SIZE 10
#define SWAP(x,y,t)((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right){ //퀵정렬을 위한 분할 함수 생성
    int pivot, temp; // 기준점과 임시 변수 선언
    int low, high; //부분 배열 인덱스 선언
    
    low=left; //좌측 부분 배열 인덱스
    high=right+1; //우측 부분 배열 인덱스
    pivot=list[left]; //기준점을 왼쪽 인덱스의 요소로 선언
    
    do {
        do
            low++; // low를 증가
        while (list[low] < pivot); // 좌측 배열에서 pivot보다 작은 값이 나올 때까지
        do
            high--; //high를 감소
        while(list[high] > pivot); // 우측 배열에서 pivot보다 큰 값이 나올 때까지
        if(low<high) SWAP(list[low], list[high], temp); // 피벗을 기준으로 좌측에는 작은값, 우측에는 큰값이 오도록 교환
    }while (low < high); //low값이 high보다 작을동안 반복
    
    SWAP(list[left], list[high], temp); // 피벗을 제자리에 위치
    return high; //high값을 반환하여 피벗의 위치를 알림
}

void quick_sort(int list[], int left, int right){ 
    if(left<right) { //정렬할 부분 배열의 크기가 1이상인 경우
        int q = partition(list, left, right); // 분할함수를 호출하여 피벗을 중심으로 좌측, 우측 배열 분할
        quick_sort(list, left, q-1); // 피벗을 기준으로 좌측 배열 정렬
        quick_sort(list, q + 1, right); // 피벗을 기준으로 우측 배열 정렬
    }
}

int main(void) {
    int i;
    n = MAX_SIZE;
    srand(time(NULL));
    for(i=0;i<n;i++)
        list[i] = rand() % 100;
    
    quick_sort(list, 0, n-1);
    for(i=0;i<n;i++) printf("%d ", list[i]);
    printf("\n");
    
    return 0;
}
