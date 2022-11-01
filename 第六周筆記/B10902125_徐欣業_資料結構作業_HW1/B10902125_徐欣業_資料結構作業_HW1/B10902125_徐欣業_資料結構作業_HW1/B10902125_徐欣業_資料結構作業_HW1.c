#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num_counter = 0;
typedef struct listnode* listpointer;
typedef struct listnode {
	char data[50];    // largest size of input data
	int digit;        // how many digit
	int number;       // number of the data
	listpointer next; // pointer to...
} listnode;
int main() {
	char filename[50];
	printf("Input filename:");
	scanf("%s", filename);
	FILE* fp = fopen(filename, "r");
	// FILE *fp = fopen("list.txt", "r");
	char c, * list1;
	char maximum[40], maximum_temp[40];
	int text_counter = 1, digit_counter = 0;
	int list[400], list2[400];
	int i;
	int temp;
	listpointer temp_first;
	for (int i = 0; i < 400; i++)
		list[i] = 0;
	for (int i = 0; i < 400; i++)
		list2[i] = 0;
	while ((c = fgetc(fp)) != EOF) { // calculate how many char and integer have
		text_counter++;
		if (c == ',') {
			num_counter++;
		}
	}
	printf("\nTotal have %d integer\n", num_counter + 1);

	list1 = (char*)malloc(text_counter * sizeof(char) + 1); // create an array
	rewind(fp);
	for (i = 0; i < text_counter; i++) { // let array to store whole text file
		list1[i] = fgetc(fp);
	}
	printf("==============================\n\n");
	listpointer textarray;
	textarray = (listpointer)malloc(sizeof(listnode) * 400); //申請400個節點
	for (i = 0; i < 400; i++) {                              // Reset array
		(textarray + i)->digit = 0;
		(textarray + i)->next = NULL;
	}
	fclose(fp);
	//==============  save the data into linked list
	int j = 0;
	int k = 0;
	for (i = 0; i < text_counter; i++) {
		(textarray + j)->data[k] = list1[i];
		digit_counter++;
		k++;
		if (list1[i] == ',') {
			(textarray + j)->digit = digit_counter - 1;
			digit_counter = 0;
			(textarray + j)->number = j;
			(textarray + j)->data[k - 1] = '\0';
			(textarray + j)->next = (textarray + j + 1);
			j++;
			k = 0;
		}
	}
	(textarray + j)->number = j;
	(textarray + j)->digit = digit_counter - 1;
	(textarray + j)->data[k - 1] = '\0';
	(textarray + j)->next = NULL;
	free(list1);
	j = 0;
	//=========================== find the maximum digit count and number
	int maximum_digit = 0;
	int max_digit = 0;
	char temp_data[40];
	char maximum_data[40] = {};
	int flag = 0;
	//===========================maximum_digit
	for (i = 0; i < num_counter + 1; i++) {
		if ((textarray + i)->digit > max_digit) {
			max_digit = (textarray + i)->digit;
		}
	}
	printf("maximum_digit:%d\n", max_digit);
	printf("==============================");
	//==========================max_data
	for (i = 0; i < num_counter + 1; i++) {
		if (max_digit == (textarray + i)->digit) {
			flag = 0;
			for (j = 0; j < max_digit; j++) {
				temp_data[j] = (textarray + i)->data[j];
				if (temp_data[j] > maximum_data[j]) {
					flag = 1;
				}
			}
			if (flag == 1) {
				for (j = 0; j < max_digit; j++) {
					maximum_data[j] = temp_data[j];
					maximum_digit = i;
				}
			}
		}
	}
	printf("\nNO.%d %20s\n\n===============================", maximum_digit + 1, maximum_data);
	//===========================  Remove duplicate integers for each list and
	//print out the resulting lists.j+2
	char temp_duplicate[40];
	int iii;
	int z;
	for (i = 0; i < num_counter + 1; i++) {
		for (iii = 0; iii < 40; iii++)
			temp_duplicate[iii] = 0;
		for (j = i + 1; j < num_counter + 1; j++) { // flag == 1:不一樣,flag==0:一樣
			if ((textarray + i)->digit == (textarray + j)->digit) {
				flag = 0;
				for (z = 0; z < (textarray + i)->digit; z++) {
					if ((textarray + i)->data[z] != (textarray + j)->data[z]) {
						flag = 1; //不一樣的話flag=1
					}
				}
				if (flag == 0) {
					for (z = 0; z < (textarray + j)->digit; z++) {
						(textarray + j)->data[z] = 0;
					}
					(textarray + j)->digit = 0;
				}
			}
		}
	}
	//================================================================
	int upper = 1;
	for (i = 0; i < num_counter + 1; i++) {
		if (((textarray + i)->digit) > 0) {
			printf("\nNO.%3d Data:%40s Digits:%d\n", upper, (textarray + i)->data, (textarray + i)->digit);
			upper++;
		}
	}
	//========================== change char into integer
	//================================================================ Sum all the
	//distinct integers
	int sum[50];
	int tag = 0;
	int largest_tag = 0;
	int temp_1 = 0;
	for (i = 0; i < 50; i++) {
		sum[i] = 0;
	}
	for (i = 0; i < num_counter + 1; i++) {
		temp_1 = (textarray + i)->digit;
		for (j = 0; j < temp_1; j++) {
			sum[j] = sum[j] + ((textarray + i)->data[temp_1 - 1 - j] - '0');
			tag = j + 1;
			if (sum[j] > 9) {
				sum[j + 1] = sum[j + 1] + 1;
				sum[j] = sum[j] - 10;
				tag = j + 2;
			}
			if (tag > largest_tag) {
				largest_tag = tag;
			}
		}
	}
	//==========================
	// printf("%d\n",largest_tag);
	printf("Total Sum:");
	for (i = 1; i <= largest_tag; i++) {
		printf("%d", sum[largest_tag - i]);
	}
	//================================================================end
	free(textarray);
	return 0;
}