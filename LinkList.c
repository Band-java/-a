#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct node {
	DataType data;
	struct node *next;
} LinkList;
LinkList *head;//定义头指针
//尾插法
void tailInsert() {

	LinkList *r,*p;//r为尾指针,p为工作指针
	head = (LinkList *)malloc(sizeof(LinkList));//为HEAD申请空间
	r = head;//r初始化
	DataType c;
	printf("请输入链表数据\n");
	while ((c = getchar()) != '\n') { //从键盘输入字符,按回车循环结束
		p = (LinkList *)malloc(sizeof(LinkList));//分配空间
		p->data = c;//指针中的值
		r->next = p;//尾指针后继指向新的节点
		r = p;//尾指针后移
	}
	r->next = NULL;
}
void display() {
	LinkList *p;
	p = head->next;
	while (p) {

		printf("%-4c", p->data);
		p = p->next;

	}
	printf("\n");
}
//查找
LinkList *select(int i) { //i:代表查找位置
	LinkList *p = head; //p代表工作指针
	int count = 0;
	//p后继不为空且未到达指定地址
	while (p->next != NULL && count < i) {
		p = p->next;
		count++;
	}
	if (count == i) {
		//查找成功
		return p;//返回该节点的地址
	} else {
		return NULL;//没找到返回空值
	}

}
//添加信息
void add(int i, DataType x) { //i:插入位置,x:插入的值
	LinkList *p =  select(i - 1); //查找前驱节点的地址
	if (!p) {//不存在前驱节点
		printf("插入位置错误!\n");

		//TODO
	} else {//存在前驱节点
		LinkList *s = (LinkList *)malloc(sizeof(LinkList));//为新建立节点开辟空间
		s->data = x;//将插入值赋给S
		s->next = p->next; //插入节点连接到被插入位置前驱节点的后继位置
		p->next = s; //将前驱节点连接至新插入节点
		printf("添加成功!\n");
	}
//删除表节点
	void del(int i){//i:删除位置
	
}

}
int main() {
	int item, index; //定义菜单选项index代表位置
	DataType data;//值
	tailInsert();//调用函数初始化链表
	void display();
	while (1) {
		printf("1-显示\n");
		printf("2-添加\n");
		printf("3-删除\n");
		printf("4-修改\n");
		printf("5-查找\n");
		printf("6-表长\n");
		printf("7-退出\n");
		printf("请输入1-7选项:\n");
		scanf("%d", &item);
		switch (item) {
			case 1:
				display();
				break;
			case 2: {
				printf("请输入要插入的位置和值:\n");
				printf("中间用空格间隔!\n");
				scanf("%d %c", &index, &data);
				add(index, data);
			}
			break;
			case 5: {
				printf("请输入要查找的位置:\n");
				scanf("%d", &index);
				LinkList *s = select(index);
				if (s) { //等价于s!=null
					printf("您要查找的元素是:%c\n", s->data);
				} else {
					printf("对不起您查找的元素不存在!\n");
				}
			}
			break;
			case 7:
				exit(0);
				break;
			default:
				printf("请输入在1-7范围内选项\n");
				break;
		}

	}
}
