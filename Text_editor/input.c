#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "input.h"
#include "sort.h"

#define G_CHAR getchar()

void prnt(char** t, int n){
	for(int i = 0 ; i < n ; i++){
		printf("\n%s" , t[i]);
	}
}

int cmp_str(char* s1,char* s2){
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);
	int a , b;
	if (s1_len == s2_len){
		for(int i = 0 ;i < s1_len ; i++){
			a = toupper (s1[i]);
			b = toupper (s2[i]);
			if(a != b){
				return 1;
			}
		}
	}
	else{
		return 0;
	}
	return 1;
}

char** delete_sentence(char** t , int z ,int *n){
	char** t1;
	free(t[z]);
	for(int q = z ; q < (*n - 1) ; q++ ){
		t[q] = t[q + 1];
	}
	(*n)--;
	t1 = realloc(t , sizeof(char*) * (*n) );
	return t1;

}


void delete_duble(char** t, int *n){
	for(int i = 0 ; i < *n - 1 ; i++ ){
		for(int z = (i + 1) ; z < *n ; z ++ ){
			if (cmp_str( t[i], t[z] )){
				t = delete_sentence(t , z , n);
				z--;
			}
		}
	}
}

char* input_sentence(char* end){

   char *str,*str1;
   int i = 0;
   str = (char *)malloc(sizeof(char));
   do{
	   *end = G_CHAR ;
       str[i] = *end;
       i++;
       str1 = realloc(str ,(i + 1) * sizeof(char));
       if( str1 != NULL){
          str = str1;
       }
       else{
       	printf("Мало памяти!!!\n");
           exit(1);
       }
   }
   while((*end != '\n') && (*end != '.'));
   str[i] = '\0';
   return str;
}


char** input_text(int* number_of_sentence){
    char **text,**t;
    char end_of_sentece;

    *number_of_sentence = 0;
    text = (char **)malloc(sizeof(char **));
    do{
        text[*number_of_sentence] = input_sentence(&end_of_sentece);
        (*number_of_sentence)++;
        t = (char **)realloc(text, (*number_of_sentence + 1)*sizeof(char *));
        if(t != NULL)
            text = t;
        else{
            printf("Мало памяти!!!\n");
            exit(1);
        }
    }
    while(end_of_sentece != '\n');
    (*number_of_sentence)--;
    return text;
}



