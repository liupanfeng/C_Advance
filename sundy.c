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
	int i=0;
	int j=1000;
	while(j>0){
		i=(i++) % 10001;
		printf("i=%d\n",i);
		j--;
	}
	
	
	//***********************************************����Ľ����������ݵķ�ʽ
	/*int a=10;
	int b=20;
	a=a^b;
	b=a^b;
	a=a^b;
	printf("a=%d\n,b=%d\n",a,b);**/
	
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
	//^ ��λ����� ���		����һ���ͷ���false ��һ���ͷ���true  ����
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
	/*char * r_path="E:\\c_workspace\\c_advance\\a_read.exe";
	
	FILE* fp=fopen(r_path,"r");
	if(fp==NULL){
		printf("failed");
		return 0;
	}
	
	fseek(fp,0,SEEK_END);
	long fileSize=ftell(fp);
	printf("�ļ���С�ǣ�%ld\n",fileSize);*/
	
	//***********************************************�ļ�����
	/*char* normal_path="E:\\c_workspace\\c_advance\\write.txt";
	char* encode_path="E:\\c_workspace\\c_advance\\write_encode.txt";
	FILE *normal_fp=fopen(normal_path,"r");
	FILE *encode_fp=fopen(encode_path,"w");
	
	int len;
	while((len=fgetc(normal_fp))!=EOF){
		fputc(len^7,encode_fp);
	}
	
	fclose(normal_fp);
	fclose(encode_fp);*/
	
	//**********************************************�ļ�����  ��Ҫ�õ�����fgetc ��fputc����������  
	/*char* encode_path="E:\\c_workspace\\c_advance\\write_encode.txt";
	char* decode_path="E:\\c_workspace\\c_advance\\write_decode.txt";
	FILE* encode_fp=fopen(encode_path,"r");
	FILE* decode_fp=fopen(decode_path,"w");
	int len;
	while((len=fgetc(encode_fp))!=EOF){
		fputc(len^7,decode_fp);
	}
	fclose(encode_fp);
	fclose(decode_fp);*/
	
	//*************************************************�������ļ����� 
	//�ܽ᣺fgetc fputc �����ֽڷ�ʽ���ж�д��  ��ȡ�����EOF����    fgets fputs �����������ַ����ķ�ʽ���ж�д   fread��fwrite�����������ݵķ�ʽ���ж�ȡ  fwrite(buffer,size,count,fp);  
	/*char * normal_path="E:\\c_workspace\\c_advance\\girl.jpg";
	char * encode_path="E:\\c_workspace\\c_advance\\girl_encode.jpg";
	FILE * normal_fp=fopen(normal_path,"rb");
	FILE * encode_fp=fopen(encode_path,"wb");
	if(normal_fp==NULL){
		printf("normal_fp is open failed");
		return 0;
	}
	if(encode_fp==NULL){
		printf("encode_fp is open failed");
		return 0;
	}
	int len;
	char * password="LoveWeiWei";			//��������
	int pwd_lenth=strlen(password);
	printf("pwd_lenth=%d\n",pwd_lenth);
	int i = 0;
	while((len = fgetc(normal_fp)) != EOF){
		fputc(len ^ password[i % pwd_lenth],encode_fp);
		i=(i++) % 10001;		//��ֹi���󣬳����������ֵ
		printf("i=%d\n",i);
	}
	printf("��д�ļ�����");
	fclose(normal_fp);
	fclose(encode_fp);
	printf("�رվ������");*/
	system("pause");
	return 0;
 }