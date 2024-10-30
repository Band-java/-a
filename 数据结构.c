#include<stdio.h>
#include<stdlib.h>//��malloc��������ռ� 
#define MAX 100
//struct SL{//����ṹ����������SL
//    int data[MAX];//�洢���� 
//	int len; //����ʵ�ʳ���
//	//�����������ṹ���Ա  
//}list1,*list2;//����ṹ������� list1,ָ�����list2 
//�ṹ���Ա����ͨ���ṹ���������ṹ��ָ��������
typedef struct SL{//����ṹ����������SL
    int data[MAX];//�洢���� 
	int len; //����ʵ�ʳ���
	//�����������ṹ���Ա  
} SeqList; //��typedef�����˽ṹ����� 
//��ʼ��˳���
void initSL(SeqList *list){//list:�ṹ��ָ����� 
	for(int i=0;i<=5;i++){
		list->data[i]=i;//Ϊ�����ʼ�� 
	}
	list->len=6;//Ϊ���ȸ�ֵ 
} 
//��ӡ���˳���Ԫ��
void show(SeqList *list){
	for(int i=0;i<list->len;i++){
		printf("%-4d",list->data[i]);
	}
	printf("\n");
} 
//��˳����в�������
int insertSL(SeqList *list,int pos,int x) {//������λ�ã�ֵ 
    //�ж��Ƿ�ﵽ���� 
    if(list->len>=MAX){
	return 0;	//���ˣ�����ʧ�� 
	} 
	//�жϲ���λ���Ƿ���Ч 
	if(pos<0||pos>list->len){
		return 0;//��Ч������ʧ�� 
	}
	//��ʼ�ƶ�Ԫ�أ��Ӻ���ǰ��֪��posλ�ý�ֹ 
	for(int i=list->len-1;i>=pos;i--){
		list->data[i+1]=list->data[i];//�������� 
	}
	list->data[pos]=x;
	list->len++;//�ܳ��ȼ�1
	return 1;//����ɹ� 
}
//ɾ��Ԫ��
void del(SeqList *list,int pos){//������λ�� 
	if(list->len==0){//��� 
	printf("��գ�ɾ��ʧ�ܣ�\n");
	}else if(pos<0||pos>=list->len){//λ����Ч 
		printf("λ����Ч��ɾ��ʧ�ܣ�\n");
	}else{
		//��ɾ��λ�õ���һ��Ԫ�ؿ�ʼһֱ�����������ǰ�ƶ�һλ 
		for(int i=pos+1;i<=list->len-1;i++){
			list->data[i-1]=list->data[i];//ǰ�� 
		}
		list->len--;//����һ 
		printf("ɾ���ɹ���\n");
	}
} 
//��ȡ��
int getLen(SeqList *list){
	return list->len;
} 
//�޸�Ԫ��
void update(SeqList *list,int pos,int x){//������λ�ã���ֵ 
	if(list->len==0){//��� 
		printf("��գ��޸�ʧ�ܣ�\n");
	}else if(pos<0||pos>=list->len){//λ����Ч 
		printf("λ����Ч���޸�ʧ�ܣ�\n");
	}else{
		list->data[pos]=x;//�޸� 
		printf("�޸ĳɹ���\n");
	}
} 
//����
void search(SeqList *list,int pos){
	if(list->len==0){//��� 
			printf("��գ��޸�ʧ�ܣ�\n");
		}else if(pos<0||pos>=list->len){//λ����Ч 
			printf("λ����Ч���޸�ʧ�ܣ�\n");
		}else{
			printf("��Ҫ���ҵ�Ԫ���ǣ�\n",list->data[pos]);
		}
} 
int main(){
	SeqList *list=(SeqList *)malloc(sizeof(SeqList));
    initSL(list);//���ú�������ʼ������
	show(list);//���ú��������˳�����Ϣ 
	int index,value,item;//index:λ�ã�value:ֵ,item:ѡ�� 
		while(1){
		printf("1-����\n");
		printf("2-ɾ��\n");
		printf("3-�޸�\n");
		printf("4-����\n");
		printf("5-��\n");
		printf("6-��ʾ\n");
		printf("7-�˳�\n");
		printf("������1-7ѡ�\n");
		scanf("%d",&item);
		switch(item){
			case 1:
				printf("������Ҫ�����λ�ü�ֵ��\n");
					scanf("%d%d",&index,&value);
					if(insertSL(list,index,value)){
						printf("����ɹ���\n");
					}else{
						printf("����ʧ�ܣ�\n");
					}
				break;
			case 2:
				printf("������Ҫɾ����λ�ã�\n");
				scanf("%d",&index);
				del(list,index);
				break;
			case 3:
				printf("������Ҫ�޸ĵ�λ�ü��µ�ֵ��\n");
				scanf("%d %d",&index,&value);
				update(list,index,value);
				break;
			case 4:
				printf("������Ҫ���ҵ�λ�ã�\n");
				scanf("%d",&index);
				search(list,index);
				break;
			case 5:
				printf("��Ϊ��%d",getLen(list));
				break;
			case 6:
				show(list);
				break;
			case 7:
//				return 0;�˳�ϵͳ��ʽ1
                exit(0);//�˳�ϵͳ��ʽ2(0:�����˳���1:�������˳�) 
			default:
				break;
		} 
	}
	
	return 0;
	
} 




















