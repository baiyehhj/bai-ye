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

//创建链表
struct Node *creatList(){
	system("cls");
	struct Node *head;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->next=NULL;
	printf("空链表创建成功\n\n");
	return (head);
}

//销毁链表
void destroy(struct Node *head)
{
	system("cls");
	if(head == NULL){
		printf("这是一个空链表\n\n");
		return; 	
	}
	struct Node *tmp;
	while(head!= NULL)
	{
		tmp =head->next;
		free(head);
		head= tmp;
	}	
	printf("链表已销毁\n\n");
}


//插入节点
struct Node *add(struct Node *head,char *element){
	system("cls");
	int num;
	struct Node *tmp=(struct Node*)malloc(sizeof(struct Node));;
	system("cls");
	printf("1.在链表最前面插入\n2.在链表中间插入\n3.在链表最后面插入\n请输入插入节点的位置：");
	scanf("%d",&num);
	if(num==1){
        strcpy(tmp->element,element);
        tmp->next = head->next;
	}
	if(num==2){
		char prev[100];
		printf("\n请输入前一个节点数据：");
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
	printf("\n已插入节点\n\n");
	return (head);	
}

//删除节点
struct Node *del(struct Node *head,char *element){
	system("cls");
	struct Node *p1,*p2;
	if(head==NULL){
		printf("这是一个空链表\n");
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
		printf("已删除节点\n\n");
	}
	else printf("未找到该节点");
	return (head);	
}

//查找节点
struct Node *search(struct Node *head,char *element){
	system("cls");
    struct Node *tmp =head;
    while (tmp!= NULL) {
        if (strcmp(element,tmp->element)==0){
        	printf("节点存在\n\n");
            return tmp;
        }
        tmp = tmp->next;
    }
    printf("节点不存在\n\n");
    return NULL;
}

int main(){	
	int num;
	char ele[100];
	struct Node* head =(struct Node*)malloc(sizeof(struct Node));
	while(1){
		printf("1.创建链表\n2.销毁链表\n3.插入\n4.删除\n5.查找\n6.结束运行\n\n请输入您要进行的操作：");
		scanf("%d",&num);
		if(num==6) break;
		switch(num){
			case 1:head=creatList();
					break;
			case 2:destroy(head);
					head=NULL;
					break;
			case 3:	printf("请输入待插入数据:");
					scanf("%s",ele);				
					head=add(head,ele);
					break;
			case 4:	printf("请输入待删除数据:");
					scanf("%s",ele);
					head=del(head,ele);
					break;
			case 5:	printf("请输入待查找数据:");
					scanf("%s",ele);
					search(head,ele);
					break;
			default:printf("输入错误，请重新输入数字");
		}	
	}
	printf("程序结束运行，感谢使用");
	return 0;
}
