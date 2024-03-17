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

//����˫����
struct Node *creatList(){
	struct Node *L,*r;
    L=(struct Node*)malloc(sizeof(struct Node));
    L->next=NULL;
    r=L;
    r->next=NULL; 
	printf("�������ɹ�\n\n");                         
    return L;
}

//��������
void destroy(struct Node *L){
	system("cls");
	struct Node *q;
	struct Node *p=L->next;			//ָ���һ�����(ͷ���)
	while(p!=NULL) 					//pû�е���ͷ
	{
		q=p->next;
		free(p);
		p=q;
	}	
	free(L);
	L=NULL;
	printf("����������\n\n");
}


//����ڵ�
struct Node *add(struct Node *L,char *element){
	system("cls");
	int num;
    struct Node *tmp=(struct Node *)malloc(sizeof(struct Node));
    strcpy(tmp->element,element);
    tmp->prior=NULL;
    tmp->next=NULL;
	struct Node *prev=L;
	system("cls");
	printf("1.��������ǰ�����\n2.�������м����\n3.��������������\n���������ڵ��λ�ã�");
	scanf("%d",&num);
	if(num==1){
        tmp->next=L;
        L->prior=tmp;
        L=tmp;
	}
	if(num==2){
		char s[100];
		printf("\n������ǰһ���ڵ����ݣ�");
		scanf("%s",s);
		while(strcmp(s,prev->element)!=0){
			prev=prev->next;
		}
		strcpy(prev->element,element);
        tmp->next=prev->next;
        prev->next->prior=tmp;
        prev->next=tmp;
        tmp->prior=prev;
	}
	if(num==3){
        strcpy(tmp->element,element);
        tmp->next = NULL;
        while(prev->next!=NULL){
            prev=prev->next;
        }
        prev->next=tmp;
		tmp->prior=prev;
	}
	printf("\n�Ѳ���ڵ�\n\n");
	return L;	
}

//ɾ���ڵ�
struct Node *del(struct Node *L,char *element){
	system("cls");
	struct Node *p,*tmp;
	p=L;
	if(L==NULL){
		printf("����һ��������\n");
		return L;
	}
	while(strcmp(element,p->element)!=0&&p->next!=NULL){
		p=p->next;
	}
    if(p->next==NULL)       
    {
        p->prior->next = NULL;
        printf("��ɾ���ڵ�\n\n");
        free(p);
    }	
	else{
		tmp=p;
        tmp->prior->next = tmp->next;
        tmp->next->prior = tmp->prior;
        printf("��ɾ���ڵ�\n\n");
        free(tmp);
	}
	return L;	
}

//���ҽڵ�
struct Node *search(struct Node *L,char *element){
	system("cls");
    struct Node *p;               
    p=L;
    while(p!=NULL)
    {                               
        if (strcmp(element,p->element)==0){
        	printf("�ڵ����\n\n");
            return p;
        }                     
        p=p->next;
    }
   	printf("�ڵ㲻����\n\n");
    return NULL;		            
}

int main(){	
	int num;
	char ele[100];
	struct Node* L=(struct Node*)malloc(sizeof(struct Node));
	while(1){
		printf("1.��������\n2.��������\n3.����\n4.ɾ��\n5.����\n6.��������\n\n��������Ҫ���еĲ�����");
		scanf("%d",&num);
		if(num==6) break;
		switch(num){
			case 1:L=creatList();
					break;
			case 2:destroy(L);
					L=NULL;
					break;
			case 3:	printf("���������������:");
					scanf("%s",ele);				
					L=add(L,ele);
					break;
			case 4:	printf("�������ɾ������:");
					scanf("%s",ele);
					L=del(L,ele);
					break;
			case 5:	printf("���������������:");
					scanf("%s",ele);
					search(L,ele);
					break;
			default:printf("���������������������");
		}		
	}
	printf("����������У���лʹ��");
	return 0;
}
