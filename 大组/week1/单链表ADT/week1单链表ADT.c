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
	struct Node *next;
};
int n;

//��������
struct Node *creatList(){
	system("cls");
	struct Node *head;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->next=NULL;
	printf("���������ɹ�\n\n");
	return (head);
}

//��������
void destroy(struct Node *head)
{
	system("cls");
	if(head == NULL){
		printf("����һ��������\n\n");
		return; 	
	}
	struct Node *tmp;
	while(head!= NULL)
	{
		tmp =head->next;
		free(head);
		head= tmp;
	}	
	printf("����������\n\n");
}


//����ڵ�
struct Node *add(struct Node *head,char *element){
	system("cls");
	int num;
	struct Node *tmp=(struct Node*)malloc(sizeof(struct Node));;
	system("cls");
	printf("1.��������ǰ�����\n2.�������м����\n3.��������������\n���������ڵ��λ�ã�");
	scanf("%d",&num);
	if(num==1){
        strcpy(tmp->element,element);
        tmp->next = head->next;
	}
	if(num==2){
		char prev[100];
		printf("\n������ǰһ���ڵ����ݣ�");
		scanf("%s",prev);
		while(strcmp(prev,head->element)!=0){
			head=head->next;
		}
	   	strcpy(tmp->element,element);
	   	tmp->next=head->next;
	   	head->next =tmp;
	}
	if(num==3){
        strcpy(tmp->element,element);
        tmp->next = NULL;
        struct Node *cur=head;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        cur->next=tmp;		
	}
	printf("\n�Ѳ���ڵ�\n\n");
	return (head);	
}

//ɾ���ڵ�
struct Node *del(struct Node *head,char *element){
	system("cls");
	struct Node *p1,*p2;
	if(head==NULL){
		printf("����һ��������\n");
		return(head);
	}
	p1=head;
	while(strcmp(element,p1->element)!=0&&p1->next!=NULL){
		p2=p1;
		p1=p1->next;
	}
	if(strcmp(element,p1->element)==0){
		if(p1==head) head=p1->next;
		else p2->next=p1->next;
		n=n-1;
		printf("��ɾ���ڵ�\n\n");
	}
	else printf("δ�ҵ��ýڵ�");
	return (head);	
}

//���ҽڵ�
struct Node *search(struct Node *head,char *element){
	system("cls");
    struct Node *tmp =head;
    while (tmp!= NULL) {
        if (strcmp(element,tmp->element)==0){
        	printf("�ڵ����\n\n");
            return tmp;
        }
        tmp = tmp->next;
    }
    printf("�ڵ㲻����\n\n");
    return NULL;
}

int main(){	
	int num;
	char ele[100];
	struct Node* head =(struct Node*)malloc(sizeof(struct Node));
	while(1){
		printf("1.��������\n2.��������\n3.����\n4.ɾ��\n5.����\n6.��������\n\n��������Ҫ���еĲ�����");
		scanf("%d",&num);
		if(num==6) break;
		switch(num){
			case 1:head=creatList();
					break;
			case 2:destroy(head);
					head=NULL;
					break;
			case 3:	printf("���������������:");
					scanf("%s",ele);				
					head=add(head,ele);
					break;
			case 4:	printf("�������ɾ������:");
					scanf("%s",ele);
					head=del(head,ele);
					break;
			case 5:	printf("���������������:");
					scanf("%s",ele);
					search(head,ele);
					break;
			default:printf("���������������������");
		}	
	}
	printf("����������У���лʹ��");
	return 0;
}
