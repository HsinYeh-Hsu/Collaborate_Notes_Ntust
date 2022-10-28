#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int num_counter = 0;
typedef struct listnode* listpointer;
typedef struct listnode {
	char data[40];
	int digit;
	int number;
	listpointer next;
};
listpointer temp;
void printlist(listpointer first) {
	int i = 1;
	for (; first; first = first->next) {
		printf("NO.%3d%40s\n",i,first->data);
		i++;
	}
}
int find_minimum(int temp, int temp2) {
	if (temp > temp2)return temp;
	if (temp < temp2)return temp2;
	return temp2;
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
	char filename[50];
	printf("Input filename:");
	scanf("%s", &filename);
	FILE* fp = fopen(filename, "r");
	char c, * list1;
	char maximum[40], maximum_temp[40];
	int text_counter = 1, digit_counter = 0, j = 0, k = 0, max_digit = 0, flag = 0;
	int list[400],list2[100];
	for (int i = 0; i < 400; i++)list[i] = 0;
	for (int i = 0; i < 100; i++)list2[i] = 0;
	while ((c = fgetc(fp)) != EOF) { //calculate how many char and integer have
		text_counter++;
		if (c == ',') {
			num_counter++;
		}
	}
	printf("\nTotal have %d integer\n", num_counter + 1);
	list1 = (char*)malloc(text_counter * sizeof(char)+1); // create an array
	rewind(fp);
	for (int i = 0; i < text_counter; i++) { //let array to store whole text file
		list1[i] = fgetc(fp);
	}

	listpointer textarray[400];
	for (int i = 0; i < 400; i++) {
		textarray[i] = (listpointer)malloc(sizeof(listpointer)+1);
		textarray[i]->digit = 1203;
		textarray[i]->next = NULL;
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

	//======================================================================
	//find maximun

	max_digit = find_maximum(textarray[0]);
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
	printf("\nThe maximum of list is %s\n\n",maximum);

	//======================================================================

	temp = textarray[0];
	for (; temp; temp = temp->next) {
		for (listpointer temp2 = temp->next; temp2; temp2 = temp2->next) {
			flag = 0;
			for (int i = 0; i < find_minimum(temp->digit,temp2->digit); i++) {
				if (temp->data[i] != temp2->data[i]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				//textarray[temp2->number-1]->next = temp2->next;
				list[temp2->number] = 1;
			}
		}
	}
	for (int i = 0; i < num_counter+1; i++) {
		if (list[i] == 1) {
			int j = i;
			while (list[j] == 1) {
				j += 1;
				textarray[i - 1]->next = textarray[j - 1]->next;
			}
			i = j-1;
		}
	}

	//======================================================================

	for (int i = 1; i < max_digit+1; i++) {
		temp = textarray[0];
		for (; temp; temp = temp->next) {
			if (temp->digit == i) {
				//printf("%s\n", temp->data);
				for (int ii = 0; ii < i;ii++) {
					list2[i - ii] += temp->data[ii] - 48;
				}
			}
		}
	}

	printlist(textarray[0]);
	for (int i = 1; i < max_digit+1; i++) {
		if (list2[i] > 9) {
			list2[i + 1] += list2[i] / 10;
			list2[i] %= 10;
		}
	}
	printf("\nThe sum of list is: ");
	for (int i = 1; i < max_digit + 1; i++) {
		printf("%d", list2[max_digit - i + 1]);
	}
	printf("\n\n");
	system("PAUSE");
	return 0;
}