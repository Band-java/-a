#include<stdio.h>
#include<stdlib.h>//malloc在此头文件 
typedef struct node{
	char data;//结点的值域
	struct node *next;//指向后继结点的指针成员 
}list;
list *head;//定义头指针
//尾插法建立链表
void tailInsert(){
	list *r,*p;//r:尾指针，p:工作指针
	head=(list *)malloc(sizeof(list));//为head申请空间
	r=head;//为r初始化
	char c;//链表中的数据
	printf("请输入链表数据：\n");
	while((c=getchar())!='\n'){//从键盘输入字符，按回车循环结束 
		p=(list *)malloc(sizeof(list));//分配空间
		p->data=c;//指针中的值
		r->next=p;//尾指针后继指向新的结点 
		r=p;//尾指针指向最后结点 
	} 
	r->next=NULL;//也可以：p->next=NULL; 
}  
//显示-输出
void show(){
	list *s=head->next;//s指向表中第一个结点的地址
	while(s){//等价于：s!=NULL 
		printf("%-4c",s->data);//输出结点的值 
		s=s->next;//指针向后移动一位 
	} 
	printf("\n");
} 
//查找
list *select(int pos){//pos:查找位置 
	list *p=head;//p:工作指针，从头开始
	int n=0;
	//p后继不空且未到达指定位置 
	while(p->next!=NULL&&n<pos){
		p=p->next;//p指针向后移动
		n++;//n计数 
	} 
	if(n==pos){//查找成功 
		return p;//返回该结点的地址 
	}else{//没找到 
		return NULL;//返回空地址 
	}
}
//添加信息 
void add(int pos,char x){//pos:插入位置 x:插入的值 
	list *pre=select(pos-1);//查找pos前驱结点的地址
	if(pre==NULL){//不存在前驱结点 
		printf("插入失败！\n"); 
	}else{//前驱存在
	    list *s=(list *)malloc(sizeof(list));
	    //为新插入结点分配空间 
	    s->data=x;//把x插入s位置
		s->next=pre->next;//连接后面的结点
		pre->next=s;//连接前面的结点
		printf("添加成功！\n"); 
	} 
}
//删除信息
void del(int pos){
	 
} 
int main(){
	tailInsert();//调用函数，初始化链表
	int item,index;//item:选项 index:位置
	char c;//c:插入的或修改的值 
	while(1){
		printf(" 1-显示\n 2-添加\n 3-删除\n 4-修改\n 5-查找\n 6-表长\n 7-退出\n");
		printf("请输入1-7选项：\n");
		scanf("%d",&item);
		switch (item) {
			case 1:
				show();
				break;
			case 2:
				{
					printf("请输入要插入的位置及其值：\n");
					scanf("%d %c",&index,&c);
					add(index,c);
				}
				break;
			case 3:
				
				break;
			case 5:{
				printf("请输入要查找的位置：\n");
				scanf("%d",&index);
				list *s=select(index);
				if(s){//等价于s！=NULL 
					printf("您要查找的元素是：%c\n",s->data);
				}else{
					printf("Sorry,查找失败！\n");
				}
				break;
			}
			case 7:
				exit(0);
			default:
				printf("请输入正确选项！\n");
				break;
		}
	} 
} 








































































































































































