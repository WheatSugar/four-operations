#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include <string.h>
#include<math.h>
#define n1 50
#pragma warning(disable:4996)
char fuhao();
int num(int range);
char fen(int range);
void choose(int range);
int text(int number,int range);
int correction();

int main()
{
	srand((unsigned)time(NULL));
	void problem();
	int input=0;
	FILE * pFile0;
	pFile0 = fopen("Exercises.txt", "w");//"w"新建一个文本文件，已存在的文件将内容清空，只允许写
	fclose(pFile0);
	printf("*****小学四则运算*****\n");
	printf("请选择所需要的功能：\n1.生成题目   2.批改题目\n");
	label:scanf("%d",&input);
	if(input!=1 && input!=2){
		printf("请输入正确的功能数字\n");
		goto label;
	}else{ 
	switch(input){
		case 1:
			printf("准备生成题目\n");
			problem();
			break;
		case 2:
			printf("准备批改题目\n");
			correction();
			break;
		}	
	}
 } 
 
 
 void problem(){
	int number=0;//number为需要的题目数 
	A:printf("请输入需要的题目数量：");
    scanf("%d",&number);
	if(number<1||number>10000)
	{
		printf("请输入1-10000的数字\n"); 
		goto A;//跳转到标记A处 
	}
	else
	{
		printf("将生成%d道题目",number);
	int range=0;//range为等下输入的数字范围 
	printf("\n请输入进行运算的最大数字:"); 
	label2:scanf("%d",&range);
	if(range<0)
	{
		printf("请输入适合小学生运算的非负数\n");
		goto label2;
	}
	else
	{
		text(number,range);//调用神奇算法 
		printf("已成功输出题目至Exercises.txt");
	}
    }
}

int text(int number,int range)//输出算式的主程序 
{  
    int i,lm,l;
    for(i=0;i<number;i++)//规定输出多少个算式 
    {
     FILE * pFile1;
	 pFile1 = fopen("Exercises.txt", "a");//"a"打开或新建一个文本文件，只允许在文件末尾追写
	 fprintf(pFile1,"第%d题：",i+1);//输出题号至txt文件 
	 fclose(pFile1);
     choose(range);//算式中第一个数 
     lm=rand()%2;
     for(l=0;l<=lm;l++)//规定算式长度 
     {
    	fuhao();//一个符号 
    	choose(range);//一个数 
	 }
	 //式子结尾的等于号 
	 FILE * pFile2;
	 pFile2 = fopen("Exercises.txt", "a");
	 fprintf(pFile2,"=\n");//输出"="和换行至txt文件  
	 fclose(pFile2);
    }
} 

char fuhao()//调用该函数时会直接输出一个随机符号 
{
	int a;
    a = rand()%4;
    switch(a)
    {
    	case 0:
    	 FILE * pFile3;
		 pFile3 = fopen("Exercises.txt", "a");
		 fprintf(pFile3,"+");
		 fclose(pFile3);
    	 break;
    	case 1:
		 FILE * pFile4;
		 pFile4 = fopen("Exercises.txt", "a");
		 fprintf(pFile4,"-");
		 fclose(pFile4);
		 break;
		case 2:
		 FILE * pFile5;
		 pFile5 = fopen("Exercises.txt", "a");
		 fprintf(pFile5,"*");
		 fclose(pFile5);
		 break;
		case 3:
		 FILE * pFile6;
		 pFile6 = fopen("Exercises.txt", "a");
		 fprintf(pFile6,"÷");
		 fclose(pFile6);
		 break;   
	}
}

void choose(int range)//该函数会随机跳转到分数函数或者整数函数，分数概率1/3，整数概率2/3 
{
	int choose=rand()%3;
	switch(choose)
	{
		case 0:
			num(range);
			break;
		case 1:
			fen(range);
			break;
		case 2:
		    num(range);
		    break;
	}
}

int num(int range)//调用该函数时会输出一个小于range的随机整数 
{
 FILE * pFile7;
 pFile7 = fopen("Exercises.txt", "a");
 fprintf(pFile7,"%d",rand()%(range-1)+1);
 fclose(pFile7);
}


char fen(int range)// 调用该函数会输出一个每个数字都小于range的随机分数 
{
 FILE * pFile8;
 pFile8 = fopen("Exercises.txt", "a");
 fprintf(pFile8,"%d'%d/%d",rand()%(range-1)+1,rand()%(range-1)+1,rand()%(range-1)+1);
 fclose(pFile8);
}

int correction()
{
	FILE *fp1,*fp2;
	fp1=fopen("answer.txt","r");  //"r"打开一个文本文件，文件必须存在，只允许读 
	fp2=fopen("your answer.txt","r");
	int i=0,j=0,correct=0,wrong=0,cc[10000],ww[10000],c=0,w=0,chu;
	float num1,num2,a[10000],b[10000];
	while (!feof(fp1))//将txt文件中的内容输入 
	{
		fscanf(fp1,"%f,",&num1);
		a[i++]=num1;
	}
	while (!feof(fp2))
	{
		fscanf(fp2,"%f,",&num2);
		b[j++]=num2;
	}
	for (j=0;j<i;j++)
	{
		if(a[j]==b[j]){
			correct++;
			cc[c++]=j+1;
		}else{
			wrong++;
			ww[w++]=j+1;
		} 
		
	}	
	
    FILE * pFile00;
	pFile00 = fopen("Grade.txt", "w");
	fprintf(pFile00,"*****小学四则运算批改*****\n");
	fclose(pFile00);
	printf("Correct：%d Correct number",correct);
	FILE * pFile9;
	pFile9 = fopen("Grade.txt", "a");
	fprintf(pFile9,"Correct：%d Correct number ",correct);//输出正确个数至txt文件 
	fclose(pFile9);
	for(chu=0;chu<c;chu++){
		printf("%d ",cc[chu]);
		FILE * pFile10;
		pFile10 = fopen("Grade.txt", "a");
		fprintf(pFile10,"%d ",cc[chu]);//输出正确的题号 
		fclose(pFile10);
		}
	printf("\n");
	FILE * pFile11;
	pFile11 = fopen("Grade.txt", "a");
	fprintf(pFile11,"\n");
	fclose(pFile11);
	printf("Wrong：%d Wrong number ",wrong);
	FILE * pFile12;
	pFile12 = fopen("Grade.txt", "a");
	fprintf(pFile12,"Wrong：%d Wrong number ",wrong);//输出错误个数 
	fclose(pFile12);
	for(chu=0;chu<w;chu++){
		printf("%d ",ww[chu]);
		FILE * pFile13;
		pFile13 = fopen("Grade.txt", "a");
		fprintf(pFile13,"%d ",ww[chu]);//输出错误题号 
		fclose(pFile13);
		}
}

