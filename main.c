#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	char data;//值域
	struct node *next;//指向后继结点的地址
} linkStack; //定义链栈
linkStack *top;//定义指向栈顶结点的指针变量
//初始化链栈(设置栈空)
void init() {
	top = NULL;
}
//入栈
void push(char x) { //x:新添加的元素
	//s:新元素分配空间
	linkStack *s = (linkStack *)malloc(sizeof(linkStack));
	s->data = x; //指针存储的元素取值
	s->next = top; //新元素与栈顶元素链接
	top = s; //top指向栈顶位置
}
//出栈
char pop() {
	linkStack *s = top;
	char c = top->data;
	top = top->next;
	free(s);
	return c;

}
int main() {
	char c,a[100];
	
	while (1) {
		init();
		int j;
		int i, n = 0;
		printf("请输入一个回文数!\n");
		
		while((c=getchar())!='\n'){
			//TODO
			push(c);
			a[n]=c;
			n++;
		}
		for( i=0;i<n;i++){
			if(a[i]!=pop()){
				printf("他不是回文数!\n");
		
			
				break;
			}
			
		}
		
		if(i==n){
			printf("他是回文数\n");

			
		}
		
	
		
	}
	

}
