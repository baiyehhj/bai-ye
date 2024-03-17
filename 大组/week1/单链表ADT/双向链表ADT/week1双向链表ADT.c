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

//创建双链表
struct Node *creatList(){
	struct Node *L,*r;
    L=(struct Node*)malloc(sizeof(struct Node));
    L->next=NULL;
    r=L;
    r->next=NULL; 
	printf("链表创建成功\n\n");                         
    return L;
}

//销毁链表
void destroy(struct Node *L){
	system("cls");
	struct Node *q;
	struct Node *p=L->next;			//指向第一个结点(头结点)
	while(p!=NULL) 					//p没有到表头
	{
		q=p->next;
		free(p);
		p=q;
	}	
	free(L);
	L=NULL;
	printf("链表已销毁\n\n");
}


//插入节点
struct Node *add(struct Node *L,char *element){
	system("cls");
	int num;
    struct Node *tmp=(struct Node *)malloc(sizeof(struct Node));
    strcpy(tmp->element,element);
    tmp->prior=NULL;
    tmp->next=NULL;
	struct Node *prev=L;
	system("cls");
	printf("1.在链表最前面插入\n2.在链表中间插入\n3.在链表最后面插入\n请输入插入节点的位置：");
	scanf("%d",&num);
	if(num==1){
        tmp->next=L;
        L->prior=tmp;
        L=tmp;
	}
	if(num==2){
		char s[100];
		printf("\n请输入前一个节点数据：");
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
	printf("\n已插入节点\n\n");
	return L;	
}

//删除节点
struct Node *del(struct Node *L,char *element){
	system("cls");
	struct Node *p,*tmp;
	p=L;
	if(L==NULL){
		printf("这是一个空链表\n");
		return L;
	}
	while(strcmp(element,p->element)!=0&&p->next!=NULL){
		p=p->next;
	}
    if(p->next==NULL)       
    {
        p->prior->next = NULL;
        printf("已删除节点\n\n");
        free(p);
    }	
	else{
		tmp=p;
        tmp->prior->next = tmp->next;
        tmp->next->prior = tmp->prior;
        printf("已删除节点\n\n");
        free(tmp);
	}
	return L;	
}

//查找节点
struct Node *search(struct Node *L,char *element){
	system("cls");
    struct Node *p;               
    p=L;
    while(p!=NULL)
    {                               
        if (strcmp(element,p->element)==0){
        	printf("节点存在\n\n");
            return p;
        }                     
        p=p->next;
    }
   	printf("节点不存在\n\n");
    return NULL;		            
}

int main(){	
	int num;
	char ele[100];
	struct Node* L=(struct Node*)malloc(sizeof(struct Node));
	while(1){
		printf("1.创建链表\n2.销毁链表\n3.插入\n4.删除\n5.查找\n6.结束运行\n\n请输入您要进行的操作：");
		scanf("%d",&num);
		if(num==6) break;
		switch(num){
			case 1:L=creatList();
					break;
			case 2:destroy(L);
					L=NULL;
					break;
			case 3:	printf("请输入待插入数据:");
					scanf("%s",ele);				
					L=add(L,ele);
					break;
			case 4:	printf("请输入待删除数据:");
					scanf("%s",ele);
					L=del(L,ele);
					break;
			case 5:	printf("请输入待查找数据:");
					scanf("%s",ele);
					search(L,ele);
					break;
			default:printf("输入错误，请重新输入数字");
		}		
	}
	printf("程序结束运行，感谢使用");
	return 0;
}
