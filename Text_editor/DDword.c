
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "DDword.h"
#include "input.h"

void free_arr(char** words , int n){
	free(words[0]);
	free(words);
}

char** separ(char* s ,int *n){
	char **w = NULL, **w1;
	char *s1;
	int len;
	int i = 0;
	while( (*s == ' ') ||  (*s == ',')){
		s++;
	}
	len = strlen(s) +1;
	s1 = malloc(sizeof(char) * len );
	strcpy( s1, s);
	while(1){
		w1 = realloc( w, sizeof(char*) * (i + 1));
		if(w1 != 0){
			w = w1;
		}
		w[i] = s1;
		while( (*s1 != ' ') && (*s1 != ',') && (*s1 != '.') && (*s1 != '\0' )){
			s1++;
		}
		if ( (*s1 == '.') || (*s1 == '\0' ) ){
			*s1 = '\0';
			*n = i + 1;
			return w;
		}
		else{
			*s1 = '\0';
			s1++;
			while( (*s1 == ' ') ||  (*s1 == ',')){
				s1++;
			}
			i++;
	}
}





	return w;
}

int double_word(char* t){
	char** words;
	int number_word = 0;
	words = separ( t , &number_word );
	for(int i = 0 ; i < (number_word - 1) ; i++){
		for(int z = (i + 1) ; z < number_word ; z++){
			if( !strcmp( words[i], words[z] ) ){
				free_arr(words,number_word);
				return 1;
			}
		}
	}
	free_arr(words,number_word);
	return 0;
}

void ddword(char** t , int *n){
	for(int i = 0 ; i < *n ; i++){
		if(double_word(t[i])){
			t = delete_sentence(t , i , n);
		}
	}
}
