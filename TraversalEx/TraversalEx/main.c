#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode* root = &n6;

//중위 순회 L -> V -> R
void inorder(TreeNode* root) {
    if(root != NULL) {
        inorder(root->left); //왼쪽 서브 트리 순회
        printf("[%d] ", root->data); //노드 방문
        inorder(root->right); //오른쪽 서브 트리 순회
    }
}

//전위 순회 V -> L -> R
void prorder(TreeNode* root){
    if (root != NULL) {
        printf("[%d] ", root->data);
        prorder(root->left);
        prorder(root->right);
    }
}

//후위 순회 L -> R -> V
void pstorder(TreeNode* root){
    if (root != NULL) {
        pstorder(root->left);
        pstorder(root->right);
        printf("[%d] ", root->data);
    }
}

int main(void) {
    printf("중위 순회 = ");
    inorder(root);
    printf("\n");
    
    printf("전위 순회 = ");
    prorder(root);
    printf("\n");
    
    printf("후위 순회 = ");
    pstorder(root);
    printf("\n");
    
    return 0;
}
