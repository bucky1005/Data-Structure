#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_SIZE 10 // 배열의 크기를 최대 10으로 설정
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) ) // 임시 변수 t를 사용하여 두 변수 x, y를 교환

int list[MAX_SIZE]; // 크기가 10인 배열 생성
int n; // 전역 변수 n 생성


void bubble_sort(int list[], int n) { // 배열과 배열요소 n을 인수로 받는 버블 정렬 함수 정의
    int i, j, temp; // 반복과 정렬에 사용할 변수 선언
    for (i=n-1; i>0; i--){ // 인덱스의 끝에서부터 내림차순 반복
        for(j=0; j<i; j++) // 버블 정렬은 인덱스 끝에서부터 정렬이 진행되므로, j가 정렬이 완료된 i보다 작을 동안만 반복
            if(list[j]>list[j+1]) SWAP(list[j], list[j+1], temp); //인접한 두 레코드를 비교하여 앞의 레코드가 더 클 경우 위치 변경
    }
}

int main(void) {
    int i; // 반복문에 사용할 인자 선언
    n = MAX_SIZE; // 배열 요소 n을 배열의 최대 크기로 설정
    srand(time(NULL)); // 현재 시간에 따라 변하는 난수 생성
    for(i=0; i<n;i++) // 배열에 값을 입력하는 반복문
        list[i] = rand() % 100; // 생성된 난수의 10의 자리까지 잘라 배열에 저장
    
    bubble_sort(list, n); // 버블 정렬 함수 호출
    for(i=0;i<n;i++) printf("%d ", list[i]); // 배열을 0번부터 순차적으로 출력
    printf("\n"); // 배열 출력 후 개행
    
    return 0;
}
