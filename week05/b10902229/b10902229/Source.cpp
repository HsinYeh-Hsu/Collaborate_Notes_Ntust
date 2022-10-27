#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int num_counter = 0;
typedef struct listnode* listpointer;
typedef struct listnode {
	char data[30];
	int digit;
	int number;
	listpointer next;
};

void printlist(listpointer first) {
	for (; first; first = first->next) {
		printf("number:%2d %30s,have %2d digits\n",first->number, first->data, first->digit);
	}
}

int find_maximum(listpointer first) {
	listpointer temp = first;
	int max_digit = 0, max_digit_temp = 0;
	for (; temp; temp = temp->next) {
		max_digit_temp = temp->digit;
		if (max_digit_temp > max_digit)max_digit = max_digit_temp;
	}

	return max_digit;
}

int main() {
	FILE* fp = fopen("test.txt", "r");
	char c, * list1;
	char maximum[30], maximum_temp[30];
	int text_counter = 1, digit_counter = 0, j = 0, k = 0, max_digit = 0, flag = 0;
	while ((c = fgetc(fp)) != EOF) { //calculate how many char and integer have
		text_counter++;
		if (c == ',') {
			num_counter++;
		}
	}
	printf("total have %d integer\n", num_counter + 1);
	list1 = (char*)malloc(text_counter * sizeof(char)+1); // create an array
	rewind(fp);
	for (int i = 0; i < text_counter; i++) { //let array to store whole text file
		list1[i] = fgetc(fp);
	}

	listpointer textarray[250];
	for (int i = 0; i < 250; i++) {
		textarray[i] = (listpointer)malloc(sizeof(listpointer)+1);
	}
	fclose(fp); // close file
	for (int i = 0; i < text_counter; i++) { // to know how 
		textarray[j]->data[k] = list1[i];
		digit_counter++;
		k++;
		if (list1[i] == ',') {
			textarray[j]->digit = digit_counter - 1;
			digit_counter = 0;
			textarray[j]->number = j;
			textarray[j]->data[k-1] = '\0';
			textarray[j]->next = textarray[j + 1];
			j++;
			k = 0;
		}
	}
	free(list1);
	textarray[j]->number = j;
	textarray[j]->digit = digit_counter - 1;
	textarray[j]->data[k-1] = '\0';
	textarray[j]->next = NULL;
	printlist(textarray[0]);
	max_digit = find_maximum(textarray[0]);
	printf("\nThe maximum of digit is %d\n",max_digit);
	for (int i = 0; i < num_counter + 1; i++) {
		if (textarray[i]->digit == max_digit) {
			for (int ii = 0; ii < max_digit+1; ii++) {
				maximum_temp[ii] = textarray[i]->data[ii];
			}
			flag = 0;
			for (int ii = 0; ii < max_digit+1; ii++) {
				if (maximum_temp[ii] > maximum[ii]) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				for (int ii = 0; ii < max_digit+1; ii++) {
					maximum[ii] = maximum_temp[ii];
				}
			}
		}
	}
	printf("The maximum of list is %s\n",maximum);
	system("PAUSE");
	return 0;
}