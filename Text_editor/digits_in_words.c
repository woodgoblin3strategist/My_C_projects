#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "digits_in_words.h"

char * Num[] = {
		"Zero" ,
		"One" ,
		"Two" ,
		"Three" ,
		"Four" ,
		"Five" ,
		"Six" ,
		"Seven" ,
		"Eight" ,
		"Nine"
};

char* rep(char *s ,int z , char* num){
	char * s1;
	int size_str1 = strlen(s);
	int size_str2 = strlen(num);
	int size_str3 = size_str1 + size_str2 - 1 + 1;
	s1  = realloc(s , sizeof(char) * size_str3);
	if(s1 != NULL){
		s = s1;
	}
	for(int i = size_str1 ; i > z ; i--){
		s[ i + size_str2 - 1] = s[i];
	}
	for(int i = z ; i < z + size_str2 ; i++){
		s[i] = num[i - z] ;
	}
	return s;
}

char* replacement(char *s){
	for(int i = 0 ; s[i] != '\0' ; i++){
		if( (s[i] >= '0') && (s[i] <= '9') ){
			s = rep(s , i , Num[s[i]- '0']);
		}
	}
	return s;
}

void digits_in_word(char** t , int n){
	for(int i = 0 ; i < n ;i++){
		t[i] = replacement(t[i]);
	}
}


