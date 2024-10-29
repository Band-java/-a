#include <stdio.h>
#include <stdlib.h>

#define Max 100

typedef struct {
	int a[Max]; // 存储数据的数组
	int top; // 栈顶元素的索引
} seqStack; // 定义顺序栈

// 1 - 初始化栈
void init(seqStack *s) {
	s->top = 0; // 将栈设置为空
}

// 2 - 入栈（添加元素）
void push(seqStack *s, int x) {
	if (s->top == Max) {
		printf("栈已满，入栈失败\n"); // 栈满，入栈失败
	} else {
		s->a[s->top++] = x; // 将元素入栈并增加栈顶指针
	}
}

// 3 - 出栈（移除元素）
int pop(seqStack *s) {
	if (s->top == 0) { // 检查栈是否为空
		printf("栈空，出栈失败\n"); // 栈为空，出栈失败
		return -1; // 返回 -1 表示失败
	} else {
		return s->a[--s->top]; // 减小栈顶指针并返回栈顶元素
	}
}

// 4 - 主函数，将十进制转换为其他进制
int main() {
	seqStack *s = (seqStack *)malloc(sizeof(seqStack));
	init(s); // 初始化栈
	
	int n, r; // n 为十进制数，r 为要转换的进制
	while (1) {
		printf("请输入一个十进制数：\n");
		scanf("%d", &n);
		printf("请输入一个其他进制数来进行转换：\n");
		scanf("%d", &r);
		
		// 将十进制转换为指定进制
		while (n != 0) {
			push(s, n % r); // 将余数入栈
			n /= r; // 更新 n 为下一次循环的值
		}
		
		// 按逆序打印所有余数（基数表示）
		while (s->top != 0) {
			printf("%X", pop(s)); // 调用出栈函数
		}
		printf("\n");
		init(s); // 为下一次输入重新初始化栈
	}
	
	free(s); // 释放分配的内存（此行在当前逻辑中不可达，但为了良好实践保留）
	return 0;
}

