 #include <stdio.h>
 #include <Windows.h>
 #include "string.h"
 #include <stdlib.h>
 //��̬�����ڴ�
 void mem(){
	int *a=(int*)malloc(sizeof(int)*1024*1024*5);
 }
 
 //�ṹ��  �洢���ǲ�ͬ�������͵ļ���    һϵ�в�ͬ���͵����ݵļ���     �ṹ����  ֻ�ǽṹ������  û���ڴ�
 struct People{
	 char name[20];
	 int age;
	 int (* Msg)(char * Str,int age);
 };
 
 int showMsg(char * Str,int age){
	 char a[50];

	 MessageBox(NULL,TEXT(Str),TEXT(itoa(age,a,10)),MB_OK);
 }
 
 //�����ṹ��  ��ֻ֤��������ʱ�������ṹ�����
/* struct {
	 char name[20];
	 int age;
	 char gender[20];
	 int classId;
 }stu2; **/ //stu2 �������ṹ���  ����
 
 int main(){
	// printf("����ĸ�����\n");
	//�����������ʽ������ȫ��ͬ��
	// int * tale(a,b)   ��ʾ����һ��int * ���͵ĺ���
	// int (*tale)(a,b) ��ʾ����ָ��
	
	//**************************���ʽ�������������޸ĵı���
	
	//�ڴ棺3��
	/*������  �������Ķ������ļ�
	  ��̬�洢�� ȫ�ֱ����;�̬����
	  ��̬�洢�� ��Ϊ��ջ���Ͷ���   
		ջ�����������Զ����䣬�������Զ�������ͷ� һ��2M
		����������Ա��̬�����
	**/
	
	/*int *a=(int*)malloc(sizeof(int)*1024*1024*500);
	if(a==NULL){
		printf("�ڴ治��������");
	}
	printf("a is address��%#x",a);
	**/
	
	//���malloc �����ڴ�ʧ�ܻط���NULL
	
	//calloc  Ҳ�������ڴ�� calloc ������count ����СΪsize���ڴ�ռ�   �л��ʼ��Ϊ0��
	
	//ʹ��malloc�����ڴ��ˣ�����Ҫ�����ж�  ʹ�������Ҫ�ͷ��ڴ�  ʹ��free   ����free  �����ظ��ͷ�  ��Ҫ��ֵһ��NULL
	//��������и�ֵNULL  ��ô���ܴ���Ұָ��  �����õ�ʱ����ܳ��ִ���  
	
	
	//java GC����  �ǽ��ڴ���Ϊ ���ͷŵ��ڴ�ռ�  �����������ͷ��ڴ�  �����java�н�������OOM��ԭ�� 
	//��free �ǻ������ͷ��ڴ�ռ��  ��һ���ڴ�ռ�������ϱ���������ʹ��  ��Ҳ��c����д�����ĳ���Ч�ʸߵ�ԭ��
	
	//***************************************************************�ַ���
	//c�б�ʾ�ַ��������ַ�ʽ һ������  ����ָ��   �������\0������β    
	/*char ch[10]={'c','h','i','n','a','\0'};
	char ch1[20]="china  is big"
	ch1[0]=s;//�����ǿ����޸ĵ�**/
	
	//char *ch2="china";  //����  ����������һ��ָ����� �ڶ� ����һ������ ��china��  ���� ���������׵�ַ ��ֵ��ch2  �����ǲ����Ա��޸ĵ�
	/*char *ch2=(char *)malloc(sizeof(char)*100);
	strcpy(ch2,"china")
	printf("��ã�%s\n",ch);  //��ռλ����%s ��ʱ��  ���յ���һ���׵�ַ  �����������ñ�ʾ�����׵�ַ **/
	
	
	//********************************************************�ṹ��
	/*struct People stu1={"lpf",20};   //����һ���ṹ��
	printf("name=%s\n",stu1.name);
	
	struct People stu3;
	strcpy(stu3.name,"lucy");
	stu3.age=20;	
	printf("stu3 name=%s\n",stu3.name);
	
	struct People stuArray[4]={{"lucy",20},{"lilei",21},{"hanmeimei",22},{"jack",25}};
	struct People* stus;	//�ṹ��ָ��
	stus=(struct People* )malloc(sizeof(struct People)*4);	//���ṹ��ַ����ڴ�
	//stus=stuArray;											//��ʼ��
	int i;
	for(i=0;i<4;i++){
		(stus+i)->age=20+i;         //�ṹ��ָ��  ���ʳ�Ա������ʱ�򣬿���ʹ��ָ��
//		(stus+i)->name="lucy";		//������ֵ�ǲ��Եģ����ǽṹ���У�name����Ϊָ������char *name;
		strcpy((stus+i)->name,"lucy");
		(stus+i)->Msg=showMsg;
	}

  
	printf("stus age=%d\n",stus[1].age);
	printf("stus name=%s\n",stus[1].name);
	stus[1].Msg("weiwei",20); */
	
	//***************************************************�ļ�д������ fputs ������Ƕ��ı��Ĳ��� 
	
	/*char* path="E:\\c_workspace\\c_advance\\write.txt";
	FILE * fp=fopen(path,"w");			//��ģʽ��������˫����
	if(fp==NULL){
		printf("failed----");
	}
	char* content="�й�ף���㣬����Զ�����ĵף�";
	fputs(content,fp);	
	fclose(fp); */
	
	
	//***************************************************�ļ���ȡ���� fgets ������Ƕ��ı��ļ��Ĳ���

	/*FILE * r_fp=fopen(path,"r");
	char buff[50];
	printf("��ȡ���������ǣ�\n");
	while(fgets(buff,50,r_fp)){
		printf("%s\n",buff);
	}
	fclose(r_fp);*/
	
	//*****************************************************�����ƶ�ȡ�ļ�		fread fwrite ���ǶԶ������ļ��Ĳ��� ����ָ���ʱ����ֱ�Ӳ������ڴ�
	
	/*char * r_path="E:\\c_workspace\\c_advance\\a_read.exe";
	char * w_path="E:\\c_workspace\\c_advance\\a_write.exe";
	FILE * r_fp=fopen(r_path,"rb");
	FILE * w_fp=fopen(w_path,"wb");
	int len;
	char buff[50];
	while((len=fread(buff,sizeof(char),50,r_fp))!=0){
		fwrite(buff,sizeof(char),len,w_fp);
	}
	fclose(r_fp);
	fclose(w_fp);*/
	
	//**************************************************�ļ���С
	char * r_path="E:\\c_workspace\\c_advance\\a_read.exe";
	
	FILE* fp=fopen(r_path,"r");
	if(fp==NULL){
		printf("failed");
		return 0;
	}
	
	fseek(fp,0,SEEK_END);
	long fileSize=ftell(fp);
	printf("�ļ���С�ǣ�%ld\n",fileSize);
	
	//***********************************************�ļ��ӽ���
	system("pause");
	return 0;
 }