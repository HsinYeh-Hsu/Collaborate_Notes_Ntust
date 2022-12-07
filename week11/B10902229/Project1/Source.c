#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct node *treepointer;
typedef struct node {
	int data;
	treepointer left, right, parent;
}node;

treepointer first;

void INPUT(treepointer flag) {
	printf("Input value:");
	int n;
	scanf("%d", &n);
	treepointer temp;
	temp = (node*)malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = n;
	while (1) {
		if (flag->data < n) {
			if (flag->right != NULL) {
				flag = flag->right;
			}
			else {
				flag->right = temp;
				temp->parent = flag;
				break;
			}
		}
		else if (flag->data > n) {
			if (flag->left != NULL) {
				flag = flag->left;
			}
			else {
				flag->left = temp;
				temp->parent = flag;
				break;
			}
		}
	}
}

void Delete(treepointer ptr) {
	if ((ptr->left == NULL) && (ptr->right == NULL)) {
		printf("If you only have one node, you can't delete it.\n");
	}
	else {
		if (ptr->left == NULL) {
			printf("type1\n");
			treepointer temp = first;
				first = first->right;
				first->parent = NULL;
				free(temp);
		}
		else {
			while (ptr->left) {
				ptr = ptr->left;
			}
			if (ptr->right != NULL) {
				printf("type2\n");
				treepointer temp = ptr->parent;
				temp->left = ptr->right;
				ptr = temp->left;
				ptr->parent = temp;
			}
			else {
				printf("type3\n");
				ptr = ptr->parent;
				ptr->left = NULL;
			}
		}
	}
}

void inorder(treepointer ptr)
{
	if (ptr) {
		inorder(ptr->left);
		printf("%d ", ptr->data);
		inorder(ptr->right);
	}
}

int height(treepointer ptr) {
	if (ptr == NULL) {
		return 0;
	}
	else {
		int left = height(ptr->left);
		int right = height(ptr->right);
		if (left > right) {
			return left + 1;
		}
		else {
			return right + 1;
		}
	}
}

int find_ancestor(treepointer ptr1, treepointer ptr2, int num1, int num2) {
	if (num1 == num2)return -6;
	while (1) {
		if (num1 < ptr1->data) {
			if (ptr1->left == NULL)return -1;
			ptr1 = ptr1->left;
		}
		else if (num1 > ptr1->data) {
			if (ptr1->right == NULL)return -1;
			ptr1 = ptr1->right;
		}
		if (num1 == ptr1->data)break;
	}
	while (1) {
		if (num2 < ptr2->data) {
			if (ptr2->left == NULL)return -2;
			ptr2 = ptr2->left;
		}
		else if (num2 > ptr2->data) {
			if (ptr2->right == NULL)return -2;
			ptr2 = ptr2->right;
		}
		if (num2 == ptr2->data)break;
	}// now,ptr1.data == num1, and ptr2.data == num2.
	treepointer temp1 = ptr2;
	for (; temp1; temp1 = temp1->parent) {
		if (temp1->data == ptr1->data)return -3;
	}
	for (temp1 = ptr1; temp1; temp1 = temp1->parent) {
		if (temp1->data == ptr2->data)return -4;
	}
	for (; ptr1; ptr1 = ptr1->parent) {
		treepointer temp2 = ptr2;
		for (; temp2; temp2 = temp2->parent) {
			if (ptr1->data == temp2->data)return ptr1->data;
		}
	}
	return -5;
}

int main() {
	first = (node*)malloc(sizeof(node));
	int n,i = 0,flag = 0;
	printf("Please input which function you want to use:\n\n1.Input a number(please don't input duplicate number).\n2.Remove the lowest key.\n3.Print out all keys in increasing order.\n4.Find the heigth of tree.\n5. Find the lowest common ancestor node of two given nodes in the tree.\n\nIf you input other key value,you will leave.\n");
	while (i < 6) {
		printf("========================================================\nInput function:");
		scanf("%d",&i);
		switch (i) {
			case 1:
				if (flag == 0) {
					printf("Input the root:");
					scanf("%d", &n);
					first->data = n;
					first->parent = NULL;
					first->left = NULL;
					first->right = NULL;
					flag = 1;
				}
				else {
					INPUT(first);
				}
				break;
			case 2:
				Delete(first);
				break;
			case 3:
				inorder(first);
				printf("\n");
				break;
			case 4:
				printf("The height of tree is %d\n",height(first));
				break;
			case 5:
				printf("Input the first node:");
				int k;
				scanf("%d", &k);
				printf("Input the second node:");
				int m;
				scanf("%d", &m);
				int ancestor = 0;
				ancestor = find_ancestor(first, first, k, m);
				switch (ancestor) {
					case -1:
						printf("The node %d is not exist.\n", k);
						break;
					case -2:
						printf("The node %d is not exist.\n", m);
						break;
					case -3:
						printf("%d is %d's ancestor.\n", k, m);
						break;
					case -4:
						printf("%d is %d's ancestor.\n", m, k);
						break;
					case -6:
						printf("They are same integer.\n");
						break;
					default:
						printf("%d is their lowest common ancestor.\n", ancestor);
						break;
				}
				break;
			default:
				break;
		}
	}
	system("PAUSE");
	return 0;
}