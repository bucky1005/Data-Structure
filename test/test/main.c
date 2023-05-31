#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct TreeNode {
    int data; //데이터가 저장될 공간
    struct TreeNode *left, *right; //구조체 트리노드를 가리키는 포인터 2개
}TreeNode;

int main(void){
    TreeNode *n1, *n2, *n3; //구조체를 가리키는 포인터 변수 3개 선언

    // 1. TreeNode* : 변수 n이 구조체를 가리키는 포인터 변수 유형임을 나타냄
    // 2. malloc : 동적으로 메모리를 할당 하기 위함
    // 3. sizeof(TreeNode): TreeNode 구조체의 크기만큼 동적 메모리를 할당
    // 즉, 동적으로 힙에 TreeNode만큼의 메모리를 할당하고, 할당된 메모리 주소를 변수 n에 저장함.
    // 이를 통해 포인터 변수 n을 사용하여 할당된 메모리에 데이터를 저장 할 수 있음.
    n1 = (TreeNode*)malloc(sizeof(TreeNode));
    n2 = (TreeNode*)malloc(sizeof(TreeNode));
    n3 = (TreeNode*)malloc(sizeof(TreeNode));

    // n1은 TreeNode 구조체를 가리키므로 포인터를 이용하여 각 메모리에 데이터를 저장
    n1->data=10;
    n1->left=n2;
    n1->right=n3;

    n2->data=20;
    n2->left=NULL;
    n2->right=NULL;

    n3->data=30;
    n3->left=NULL;
    n3->right=NULL;

    printf("n1: %d\n", n1->data);
    printf("n2: %d\n", n2->data);
    printf("n3: %d\n", n3->data);
    
    free(n1); free(n2); free(n3);

    return 0;
}
