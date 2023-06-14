#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_SIZE 10

int list[MAX_SIZE];
int n;

void inc_insertion_sort(int list[], int first, int last, int gap)
{
   int i, j, key; // 반복, 정렬에 사용할 변수 선언
   for (i = first + gap; i <= last; i = i + gap) { // gap 만큼 떨어진 요소들을 삽입 정렬 하기 위한 반복문
      key = list[i]; // 정렬할 요소를 key에 저장
      for (j = i - gap; j >= first && key < list[j]; j = j - gap) // 요소를 비교하여 정렬시키기 위한 반복문
         list[j + gap] = list[j]; //현재 요소를 gap만큼 오른쪽으로 이동
      list[j + gap] = key;  // 정렬할 요소를 올바른 위치에 삽입
   }
}

void shell_sort(int list[], int n)
{
   int i, gap; // 반복, 정렬에 사용할 변수
   for (gap = n / 2; gap > 0; gap = gap / 2) { // 배열의 절반크기부터 절반씩 점점 줄여가며 반복 gap이 0이 될때까지 반복
       if ((gap % 2) == 0) gap++; //gap 이 짝수인 경우 홀수로 만듦
      for (i = 0; i < gap; i++) //부분리스트만큼 반복하는 반복문
         inc_insertion_sort(list, i, n - 1, gap); // 부분 삽입 정렬 함수 호출
   }
}

int main(void)
{
   int i;
   n = MAX_SIZE;
   srand(time(NULL));
   for (i = 0; i < n; i++)      // 난수 생성 및 출력
      list[i] = rand() % 100; // 난수 발생 범위 0~99

   shell_sort(list, n); // 삽입정렬 호출
   for (i = 0; i < n; i++) printf("%d ", list[i]);
   printf("\n");
   return 0;
}
