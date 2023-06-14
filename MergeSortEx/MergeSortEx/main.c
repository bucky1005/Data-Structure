#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_SIZE 10

int list[MAX_SIZE];
int n;
int sorted[MAX_SIZE]; //정렬된 요소를 저장할 배열

void merge(int list[], int left, int mid, int right)
{
   int i, j, k, l; //정렬 인덱스를 나타내는 변수 선언
   i = left;  j = mid + 1;  k = left; //i는 왼쪽, j는 오른쪽, k는 정렬될 인덱스

   while (i <= mid && j <= right) { // 분할 정렬된 list를 합치는 반복문
      if (list[i] <= list[j]) sorted[k++] = list[i++]; // 왼쪽 정렬값이 오른쪽 정렬값보다 작거나 같으면 왼쪽 요소를 sorted 배열에 저장
      else sorted[k++] = list[j++]; //오른쪽 정렬값이 더 작다면 오른쪽 요소를 저장
   }

   if (i > mid) // 변수 i가 중간 인덱스 mid보다 크다면,
      for (l = j; l <= right; l++) sorted[k++] = list[l]; //두 번째 부분 배열에 남아 있는 요소들을 sorted 배열에 저장
   else //첫 번째 부분 배열에 남아 있는 요소들
      for (l = i; l <= mid; l++) sorted[k++] = list[l]; //첫번째 배열의 시작부터 끝까지 반복하며 sorted 배열에 저장
   for (l = left; l <= right; l++) list[l] = sorted[l]; //sorted에 정렬된 요소들을 다시 list에 저장하는 반복문
}

void merge_sort(int list[], int left, int right)
{
   int mid;
   if (left < right) {
      mid = (left + right) / 2;     /* 리스트의 균등 분할 */
      merge_sort(list, left, mid);    /* 부분 리스트 정렬 */
      merge_sort(list, mid + 1, right); /* 부분 리스트 정렬 */
      merge(list, left, mid, right);    /* 합병 */
   }
}

int main(void)
{
   int i;
   n = MAX_SIZE;
   srand(time(NULL));
   for (i = 0; i < n; i++)      // 난수 생성 및 출력
      list[i] = rand() % 100; // 난수 발생 범위 0~99

   // 합병 정렬 수행
   // (left: 배열의 시작 = 0, right: 배열의 끝 = n-1)
   merge_sort(list, 0, n-1); // 삽입정렬 호출
   for (i = 0; i < n; i++) printf("%d ", list[i]);
   printf("\n");
   return 0;
}
