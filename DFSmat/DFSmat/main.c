//
//  main.c
//  DFSmat
//
//  Created by 손세림 on 2023/06/13.
//

#include <stdio.h>

void insert_edge(GraphType* g, int start, int end){
    if(start >= g->n || end >= g->n){
        fprintf(stderr, "정점 번호 오류");
        return;
    }
    g->adj_mat[start][end] = 1;
    g->adj_mat[end][start] = 1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
