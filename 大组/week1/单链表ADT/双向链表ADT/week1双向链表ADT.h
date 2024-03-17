#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#include<unistd.h>
#include<malloc.h>
#define LEN sizeof(struct Node)
struct Node
{
	char element[100];
	struct	Node *prior;			
	struct	Node *next;		
};
struct Node *creatList();
void destroy(struct Node *head);
struct Node *add(struct Node *head,char *element);
struct Node *del(struct Node *head,char *element);
struct Node *search(struct Node *head,char *element);
