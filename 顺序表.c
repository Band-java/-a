#include<stdio.h>
#include<stdlib.h>//用malloc函数分配空间 
#define MAX 100
//struct SL{//定义结构体类型名：SL
//    int data[MAX];//存储数据 
//	int len; //数组实际长度
//	//定义了两个结构体成员  
//}list1,*list2;//定义结构体变量名 list1,指针变量list2 
//结构体成员必须通过结构体变量名或结构体指针名调用
typedef struct SL{//定义结构体类型名：SL
    int data[MAX];//存储数据 
	int len; //数组实际长度
	//定义了两个结构体成员  
} SeqList; //用typedef定义了结构体别名 
//初始化顺序表
void initSL(SeqList *list){//list:结构体指针变量 
	for(int i=0;i<=5;i++){
		list->data[i]=i;//为数组初始化 
	}
	list->len=6;//为长度赋值 
} 
//打印输出顺序表元素
void show(SeqList *list){
	for(int i=0;i<list->len;i++){
		printf("%-4d",list->data[i]);
	}
	printf("\n");
} 
//向顺序表中插入数据
int insertSL(SeqList *list,int pos,int x) {//表名，位置，值 
    //判断是否达到上限 
    if(list->len>=MAX){
	return 0;	//满了，插入失败 
	} 
	//判断插入位置是否有效 
	if(pos<0||pos>list->len){
		return 0;//无效，插入失败 
	}
	//开始移动元素，从后往前，知道pos位置截止 
	for(int i=list->len-1;i>=pos;i--){
		list->data[i+1]=list->data[i];//依次右移 
	}
	list->data[pos]=x;
	list->len++;//总长度加1
	return 1;//插入成功 
}
//删除元素
void del(SeqList *list,int pos){//表名，位置 
	if(list->len==0){//表空 
	printf("表空，删除失败！\n");
	}else if(pos<0||pos>=list->len){//位置无效 
		printf("位置无效，删除失败！\n");
	}else{
		//从删除位置的下一个元素开始一直到最后依次向前移动一位 
		for(int i=pos+1;i<=list->len-1;i++){
			list->data[i-1]=list->data[i];//前移 
		}
		list->len--;//表长减一 
		printf("删除成功！\n");
	}
} 
//获取表长
int getLen(SeqList *list){
	return list->len;
} 
//修改元素
void update(SeqList *list,int pos,int x){//表名，位置，新值 
	if(list->len==0){//表空 
		printf("表空，修改失败！\n");
	}else if(pos<0||pos>=list->len){//位置无效 
		printf("位置无效，修改失败！\n");
	}else{
		list->data[pos]=x;//修改 
		printf("修改成功！\n");
	}
} 
//查找
void search(SeqList *list,int pos){
	if(list->len==0){//表空 
			printf("表空，修改失败！\n");
		}else if(pos<0||pos>=list->len){//位置无效 
			printf("位置无效，修改失败！\n");
		}else{
			printf("您要查找的元素是：\n",list->data[pos]);
		}
} 
int main(){
	SeqList *list=(SeqList *)malloc(sizeof(SeqList));
    initSL(list);//调用函数，初始化数组
	show(list);//调用函数，输出顺序表信息 
	int index,value,item;//index:位置，value:值,item:选项 
		while(1){
		printf("1-插入\n");
		printf("2-删除\n");
		printf("3-修改\n");
		printf("4-查找\n");
		printf("5-表长\n");
		printf("6-显示\n");
		printf("7-退出\n");
		printf("请输入1-7选项：\n");
		scanf("%d",&item);
		switch(item){
			case 1:
				printf("请输入要插入的位置及值：\n");
					scanf("%d%d",&index,&value);
					if(insertSL(list,index,value)){
						printf("插入成功！\n");
					}else{
						printf("插入失败！\n");
					}
				break;
			case 2:
				printf("请输入要删除的位置：\n");
				scanf("%d",&index);
				del(list,index);
				break;
			case 3:
				printf("请输入要修改的位置及新的值：\n");
				scanf("%d %d",&index,&value);
				update(list,index,value);
				break;
			case 4:
				printf("请输入要查找的位置：\n");
				scanf("%d",&index);
				search(list,index);
				break;
			case 5:
				printf("表长为：%d",getLen(list));
				break;
			case 6:
				show(list);
				break;
			case 7:
//				return 0;退出系统方式1
                exit(0);//退出系统方式2(0:正常退出，1:非正常退出) 
			default:
				break;
		} 
	}
	
	return 0;
	
} 




















