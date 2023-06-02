#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_SIZE 10 // 배열의 크기를 최대 10으로 설정

int list[MAX_SIZE]; // 크기가 10인 배열 생성
int n; // 전역 변수 n 생성

void insertion_sort(int list[], int n){ // 배열과 배열요소 n을 인수로 받는 삽입 함수 정의
    int i, j, key; // 반복과 정렬에 사용할 변수 선언
    for(i=1; i < n; i++) { // 배열의 두번째 요소부터 인덱스 끝까지 반복
        key = list[i]; // 삽입 정렬할 값을 key에 저장
        for (j=i-1; j >= 0 && list[j] > key; j--) // key와 앞 인덱스 값의 크기를 비교하며 올바른 위치에 삽입하기 위한 반복문
            list[j+1] = list[j]; // key가 list[j]보다 작다면 list[j]를 한 칸 뒤로 쉬프트
        list[j+1] = key; //반복문을 마친 후 j가 하나 감소되었으므로, list[j+1]에 key를 삽입
    }
}

int main(void){
    int i; // 반복문에 사용할 인자 선언
    n = MAX_SIZE; // 배열 요소 n을 배열의 최대 크기로 설정
    srand(time(NULL)); // 현재 시간에 따라 변하는 난수 생성
    for(i=0; i<n;i++) // 배열에 값을 입력하는 반복문
        list[i] = rand() % 100; // 생성된 난수의 10의 자리까지 잘라 배열에 저장
    
    insertion_sort(list, n); // 삽입 정렬 함수 호출
    for(i=0;i<n;i++) printf("%d ", list[i]); // 배열을 0번부터 순차적으로 출력
    printf("\n"); // 배열 출력 후 개행
    
    return 0;
}









