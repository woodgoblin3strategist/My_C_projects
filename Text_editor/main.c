

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "input.h"
#include "num.h"
#include "sort.h"
#include "DDword.h"
#include "digits_in_words.h"


int main(void) {
	int choice;
    char **text;
    int number_of_sentence = 0;
	printf("Введите текст\n");
    text = input_text( &number_of_sentence );
	delete_duble(text,&number_of_sentence);

    while(1){
    	printf("\n1)Вывести все предложения в которых все слова состоят только из цифр.\n");
    	printf("2)Отсортировать предложения по уменьшению количества заглавных букв в нем.\n");
    	printf("3)Удалить все предложения, в которых какое-то слово встречается 2 и более раза.\n");
    	printf("4)Преобразовать все предложения так, чтобы каждое вхождение цифры заменялось на соответствующую подстроку\n");
		printf("5)Выход из программы.\n");
    	scanf("%d" , &choice);
    	switch(choice){
    		case 1:
    				word_is_only_numbers(text,&number_of_sentence);
    		break;
    		case 2:
    				sort_cap(text,number_of_sentence);
    				prnt(text, number_of_sentence);
    		break;
    		case 3:
    				ddword(text,&number_of_sentence);
    				prnt(text, number_of_sentence);
    		break;
			case 4:
					digits_in_word(text ,number_of_sentence);
					prnt(text, number_of_sentence);
			break;
			case 5:
					return 0;
					free(text);
			break;
    	}


    }

	return EXIT_SUCCESS;
}
