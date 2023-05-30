#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

int main(void) {
    TreeNode* n1,* n2,* n3;
    n1 = (TreeNode*)malloc(sizeof(TreeNode));
    n2 = (TreeNode*)malloc(sizeof(TreeNode));
    n3 = (TreeNode*)malloc(sizeof(TreeNode));
    
    n1->data = 10;
    n1->left = n2;
    n1->right = n3;
    
    n2->data = 20;
    n2->left = NULL;
    n2->right = NULL;
    
    n3->data = 30;
    n3->left = NULL;
    n3->right = NULL;
    
    printf("n1: %d\n", n1->data);
    printf("n2: %d\n", n2->data);
    printf("n3: %d\n", n3->data);
    
    free(n1);free(n2);free(n3);
    
    printf("-------free() 실행------\n");
    
    printf("n1: %d\n", n1->data);
    printf("n2: %d\n", n2->data);
    printf("n3: %d\n", n3->data);
    
    return 0;
}
