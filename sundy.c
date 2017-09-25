 #include <stdio.h>
 #include <Windows.h>
 #include "string.h"
 #include <stdlib.h>
 //动态分配内存
 void mem(){
	int *a=(int*)malloc(sizeof(int)*1024*1024*5);
 }
 
 //结构体  存储的是不同数据类型的集合    一系列不同类型的数据的集合     结构体名  只是结构体类型  没有内存
 struct People{
	 char name[20];
	 int age;
	 int (* Msg)(char * Str,int age);
 };
 
 int showMsg(char * Str,int age){
	 char a[50];

	 MessageBox(NULL,TEXT(Str),TEXT(itoa(age,a,10)),MB_OK);
 }
 
 //匿名结构体  保证只有声明的时候，声明结构体变量
/* struct {
	 char name[20];
	 int age;
	 char gender[20];
	 int classId;
 }stu2; **/ //stu2 是匿名结构体的  名字
 
 int main(){
	// printf("轻轻的告诉你\n");
	//下面两个表达式，是完全不同的
	// int * tale(a,b)   表示返回一个int * 类型的函数
	// int (*tale)(a,b) 表示函数指针
	
	//**************************表达式，必须是左侧可修改的变量
	
	//内存：3区
	/*程序区  保存程序的二进制文件
	  静态存储区 全局变量和静态变量
	  动态存储区 分为：栈区和堆区   
		栈区：编译器自动分配，编译器自动申请和释放 一般2M
		堆区：程序员动态分配的
	**/
	
	/*int *a=(int*)malloc(sizeof(int)*1024*1024*500);
	if(a==NULL){
		printf("内存不够请温柔");
	}
	printf("a is address：%#x",a);
	**/
	
	//如果malloc 申请内存失败回返回NULL
	
	//calloc  也是申请内存的 calloc 是申请count 个大小为size的内存空间   切会初始化为0；
	
	//使用malloc申请内存了，必须要进行判断  使用完后需要释放内存  使用free   并且free  不能重复释放  需要赋值一个NULL
	//如果不进行赋值NULL  那么可能存在野指针  程序用的时候可能出现错误  
	
	
	//java GC机制  是将内存标记为 可释放的内存空间  并不会马上释放内存  这就是java中进场出现OOM的原因 
	//而free 是会马上释放内存空间的  这一块内存空间可以马上被其他程序使用  这也是c语言写出来的程序效率高的原因
	
	//***************************************************************字符串
	//c中表示字符串有两种方式 一是数组  二是指针   数组会用\0当做结尾    
	/*char ch[10]={'c','h','i','n','a','\0'};
	char ch1[20]="china  is big"
	ch1[0]=s;//这样是可以修改的**/
	
	//char *ch2="china";  //解析  首先声明了一个指针变量 第二 声明一个常量 “china”  第三 将常量的首地址 赋值给ch2  常量是不可以被修改的
	/*char *ch2=(char *)malloc(sizeof(char)*100);
	strcpy(ch2,"china")
	printf("你好，%s\n",ch);  //当占位符是%s 的时候  接收的是一个首地址  而数组名正好表示的是首地址 **/
	
	
	//********************************************************结构体
	/*struct People stu1={"lpf",20};   //定义一个结构体
	printf("name=%s\n",stu1.name);
	
	struct People stu3;
	strcpy(stu3.name,"lucy");
	stu3.age=20;	
	printf("stu3 name=%s\n",stu3.name);
	
	struct People stuArray[4]={{"lucy",20},{"lilei",21},{"hanmeimei",22},{"jack",25}};
	struct People* stus;	//结构体指针
	stus=(struct People* )malloc(sizeof(struct People)*4);	//给结构体分分配内存
	//stus=stuArray;											//初始化
	int i;
	for(i=0;i<4;i++){
		(stus+i)->age=20+i;         //结构体指针  访问成员变量的时候，可以使用指针
//		(stus+i)->name="lucy";		//这样赋值是不对的，除非结构体中，name声明为指针类型char *name;
		strcpy((stus+i)->name,"lucy");
		(stus+i)->Msg=showMsg;
	}

  
	printf("stus age=%d\n",stus[1].age);
	printf("stus name=%s\n",stus[1].name);
	stus[1].Msg("weiwei",20); */
	
	//***************************************************文件写入内容 fputs 这个多是对文本的操作 
	
	/*char* path="E:\\c_workspace\\c_advance\\write.txt";
	FILE * fp=fopen(path,"w");			//打开模式，必须是双引号
	if(fp==NULL){
		printf("failed----");
	}
	char* content="中国祝福你，你永远在我心底！";
	fputs(content,fp);	
	fclose(fp); */
	
	
	//***************************************************文件读取内容 fgets 这个多是对文本文件的操作

	/*FILE * r_fp=fopen(path,"r");
	char buff[50];
	printf("读取到的内容是：\n");
	while(fgets(buff,50,r_fp)){
		printf("%s\n",buff);
	}
	fclose(r_fp);*/
	
	//*****************************************************二进制读取文件		fread fwrite 多是对二进制文件的操作 访问指针的时候是直接操作的内存
	
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
	
	//**************************************************文件大小
	char * r_path="E:\\c_workspace\\c_advance\\a_read.exe";
	
	FILE* fp=fopen(r_path,"r");
	if(fp==NULL){
		printf("failed");
		return 0;
	}
	
	fseek(fp,0,SEEK_END);
	long fileSize=ftell(fp);
	printf("文件大小是：%ld\n",fileSize);
	
	//***********************************************文件加解密
	system("pause");
	return 0;
 }