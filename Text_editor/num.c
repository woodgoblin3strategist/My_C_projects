#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "num.h"

int cmp_numbers(char* str){
	int str_len = strlen(str);
	for(int i = 0 ; i < str_len ; i++){
		if ( ( (str[i] != ',') && (str[i] != ' ') && (str[i] != '.') ) &&  !( (str[i] >= '0' ) && (str[i] <= '9') ) ){
			return 0;
		}
	}
	return 1;
}

void word_is_only_numbers(char** t, int *n){
	for(int z = 0 ; z < *n ;z++ ){
		if( cmp_numbers( t[z] ) ){
			printf("\n%s" , t[z]);
		}
	}
}




