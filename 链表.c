#include<stdio.h>
#include<stdlib.h>//malloc�ڴ�ͷ�ļ� 
typedef struct node{
	char data;//����ֵ��
	struct node *next;//ָ���̽���ָ���Ա 
}list;
list *head;//����ͷָ��
//β�巨��������
void tailInsert(){
	list *r,*p;//r:βָ�룬p:����ָ��
	head=(list *)malloc(sizeof(list));//Ϊhead����ռ�
	r=head;//Ϊr��ʼ��
	char c;//�����е�����
	printf("�������������ݣ�\n");
	while((c=getchar())!='\n'){//�Ӽ��������ַ������س�ѭ������ 
		p=(list *)malloc(sizeof(list));//����ռ�
		p->data=c;//ָ���е�ֵ
		r->next=p;//βָ����ָ���µĽ�� 
		r=p;//βָ��ָ������� 
	} 
	r->next=NULL;//Ҳ���ԣ�p->next=NULL; 
}  
//��ʾ-���
void show(){
	list *s=head->next;//sָ����е�һ�����ĵ�ַ
	while(s){//�ȼ��ڣ�s!=NULL 
		printf("%-4c",s->data);//�������ֵ 
		s=s->next;//ָ������ƶ�һλ 
	} 
	printf("\n");
} 
//����
list *select(int pos){//pos:����λ�� 
	list *p=head;//p:����ָ�룬��ͷ��ʼ
	int n=0;
	//p��̲�����δ����ָ��λ�� 
	while(p->next!=NULL&&n<pos){
		p=p->next;//pָ������ƶ�
		n++;//n���� 
	} 
	if(n==pos){//���ҳɹ� 
		return p;//���ظý��ĵ�ַ 
	}else{//û�ҵ� 
		return NULL;//���ؿյ�ַ 
	}
}
//�����Ϣ 
void add(int pos,char x){//pos:����λ�� x:�����ֵ 
	list *pre=select(pos-1);//����posǰ�����ĵ�ַ
	if(pre==NULL){//������ǰ����� 
		printf("����ʧ�ܣ�\n"); 
	}else{//ǰ������
	    list *s=(list *)malloc(sizeof(list));
	    //Ϊ�²��������ռ� 
	    s->data=x;//��x����sλ��
		s->next=pre->next;//���Ӻ���Ľ��
		pre->next=s;//����ǰ��Ľ��
		printf("��ӳɹ���\n"); 
	} 
}
//ɾ����Ϣ
void del(int pos){
	 
} 
int main(){
	tailInsert();//���ú�������ʼ������
	int item,index;//item:ѡ�� index:λ��
	char c;//c:����Ļ��޸ĵ�ֵ 
	while(1){
		printf(" 1-��ʾ\n 2-���\n 3-ɾ��\n 4-�޸�\n 5-����\n 6-��\n 7-�˳�\n");
		printf("������1-7ѡ�\n");
		scanf("%d",&item);
		switch (item) {
			case 1:
				show();
				break;
			case 2:
				{
					printf("������Ҫ�����λ�ü���ֵ��\n");
					scanf("%d %c",&index,&c);
					add(index,c);
				}
				break;
			case 3:
				
				break;
			case 5:{
				printf("������Ҫ���ҵ�λ�ã�\n");
				scanf("%d",&index);
				list *s=select(index);
				if(s){//�ȼ���s��=NULL 
					printf("��Ҫ���ҵ�Ԫ���ǣ�%c\n",s->data);
				}else{
					printf("Sorry,����ʧ�ܣ�\n");
				}
				break;
			}
			case 7:
				exit(0);
			default:
				printf("��������ȷѡ�\n");
				break;
		}
	} 
} 








































































































































































