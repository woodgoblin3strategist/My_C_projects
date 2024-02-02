#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "sort.h"

typedef struct{
    char* str;
    int cap;
} Sentence_t;

int cap(char* str){
	int counter = 0;
	while( *str != '\0' ){
		if( (*str >= 'A') && (*str <= 'Z') ){
			counter++;
		}
		str++;
	}
	return counter;
}

int cmp_cap(Sentence_t *a1,  Sentence_t *a2){
	return(a2->cap - a1->cap );
}

void sort_cap(char** t,int n){
	Sentence_t* arr;
	arr = malloc(n * sizeof(Sentence_t));
	for(int i = 0 ; i < n ; i++){
		arr[i].str = t[i];
		arr[i].cap = cap(t[i]);
	}
	qsort(arr , n , sizeof(Sentence_t) ,(int (*)(const void*,const void*))cmp_cap );
	for(int i = 0 ; i < n ; i++){
		t[i] = arr[i].str;
	}
	free(arr);
}



