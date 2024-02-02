# My_C_projects
My educational projects in С

Text_editor
The program is provided with text as input (the text is sentences separated by a dot. Sentences are a set of words separated by a space or comma, words are a set of Latin letters and numbers. The length of the text and each sentence is not known in advance.
The program must save this text into a dynamic array of strings and then operate only with it.
The program must find and delete all repeated sentences (they should be compared character-by-character, but case-insensitive).
Next, the program should prompt the user for one of the following available actions (the program should print a prompt for this. It should also be possible to exit the program):
1. Output all sentences in which all words consist only of numbers.
2. Sort the sentences by reducing the number of capital letters in it.
3. Delete all sentences in which a word occurs 2 or more times.
4. Convert all sentences so that each occurrence of a digit is replaced by the corresponding substring (0 - “Zero”, 1 - “One”, 2 - “Two”, etc.).

All sorts must be performed using the standard library function. The use of native functions, if there is an analogue among the functions of the standard library, is prohibited.
All subtasks, input/output must be implemented as a separate function.
