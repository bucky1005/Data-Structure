#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)


#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) ) // 임시 변수 t를 사용하여 두 변수 x, y를 교환

int list[MAX_SIZE]; // 10의 크기를 가지는 배열 생성
int n; // 전역 변수 n 생성

void selection_sort(int list[], int n){ // 배열과 배열요소 n을 인수로 받는 선택정렬 함수 정의
    int i, j, least, temp; // 반복과 정렬 과정에 사용될 변수 선언
    for(i=0; i < n-1; i++){ // 배열 인덱스를 순회하는 반복문
        least = i; // 최소값 비교를 위해 배열 인덱스를 least로 설정
        for(j=i+1; j<n; j++) // 최소값 탐색을 위한 반복문
            if(list[j] < list[least]) least = j; // 연속된 두 배열 요소를 비교하여 더 작은 값의 인덱스를 least에 저장
            SWAP(list[i], list[least], temp); // j가 더 작으면 위치 변경, 아닌 경우 그대로 유지
    }
}

int main(void) {
    int i; // 반복문에 사용할 인자 선언
    n = MAX_SIZE; // 배열 요소 n을 배열의 최대 크기로 설정
    srand(time(NULL)); // 현재 시간에 따라 변하는 난수 생성
    for (i=0; i<n; i++) // 배열에 값을 입력하는 반복문
        list[i] = rand() % 100; // 생성된 난수의 10의 자리까지 잘라 배열에 저장
    
    selection_sort(list, n); // 선택 정렬 함수 호출
    for(i=0; i<n; i++) printf("%d ", list[i]); // 배열을 0번부터 순차적으로 출력
    printf("\n"); // 배열 출력 후 개행
    
    return 0;
}
