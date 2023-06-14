#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct { // 큐 타입
element  data[MAX_QUEUE_SIZE];
int  front, rear;
} QueueType;

// 오류 함수
void error(const char* message)
{   fprintf(stderr, "%s\n", message);
    exit(1);
}

// 공백 상태 검출 함수
void init_queue(QueueType* q)
{   q->front = q->rear = 0;    }

// 공백 상태 검출 함수
int is_empty(QueueType* q)
{   return (q->front == q->rear);     }

//
// 포화 상태 검출 함수
int is_full(QueueType* q)
{   return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);   }

// 삽입 함수
void enqueue(QueueType* q, element item)
{   if (is_full(q)) error("큐가 포화상태입니다");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;        }

// 삭제 함수
element dequeue(QueueType* q)
{   if (is_empty(q)) error("큐가 공백상태입니다");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];        }

#define BUCKETS 10
#define DIGITS  4
void radix_sort(int list[], int n)
{   int i, b, d, factor = 1; //반복문에 사용할 인자들을 선언
   QueueType queues[BUCKETS]; // 크기가 10인 구조체 큐 생성

   for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);  // 큐 초기화
   for (d = 0; d < DIGITS; d++) { //각 자리수만큼 반복하는 반복문
      for (i = 0; i < n; i++)// 배열을 순차로 훑음
         enqueue(&queues[(list[i] / factor) % 10], list[i]); // 각 자리수에 따른 데이터를 큐에 삽입

    for (b = i = 0; b < BUCKETS; b++)  // 버킷에서 꺼내어 list로 합친다.
       while (!is_empty(&queues[b])) // 공백인지 검사
          list[i++] = dequeue(&queues[b]); //queue의 요소들을 꺼내어 list에 저장
    factor *= 10; //다음 자리수로 이동
    }
}
#define  SIZE 10

int main(void)
{
   int list[SIZE];
   srand(time(NULL));
   // 난수 생성 및 출력
   for (int i = 0; i < SIZE; i++)
      list[i] = rand() % 100;

   radix_sort(list, SIZE); // 기수정렬 호출
   for (int i = 0; i < SIZE; i++)
      printf("%d ", list[i]);
   printf("\n");
   return 0;
}
