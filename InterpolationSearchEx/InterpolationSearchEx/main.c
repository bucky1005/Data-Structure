#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define MAX_SIZE 1000

int list[MAX_SIZE];

int init_list(){
    int i;
    for(i=0; i < MAX_SIZE; i++)
        list[i] = 7 * i;
    return 0;
}

//이진 탐색
int binsearch(int key, int low, int high){
    int middle;
    
    if(low <= high){
        middle = (low+high) / 2;
        if(key == list[middle]) return middle;
        else if (key < list[middle])
            return binsearch(key, low, middle-1);
        else
            return binsearch(key, middle+1, high);
    }
    return -1;
}

int binsearch2(int key, int low, int high){
    int middle;
    while(low<=high) {
        middle = (low <= high);
        if(key == list[middle]) return middle;
        else if (key > list[middle]) low = middle + 1;
        else high = middle -1;
    }
    return -1;
}

int search_interpolation(int key, int n){
    int low, high, j;
    low = 0;
    high = n -1;
    while((list[high] >= key) && (key > list[low])) {
        j = ((float)(key - list[low] / list[high] - list[low]) * (high - low)) + low;
        if(key>list[j]) low = j + 1;
        else if (key < list[j]) high = j - 1;
        else low = j;
    }
    if (list[low] == key) return(low);
    else return -1;
}

int main() {
    int i = 0;
    init_list();
    i = binsearch(49, 0, 999);
    if(i >= 0) printf("탐색 성공 i=%d\n", i);
    else printf("탐색 실패\n");
}
