#include<stdio.h>
#include<stdlib.h> 
#include<time.h>
#include <string.h>
#include<math.h>
#define n1 50
#pragma warning(disable:4996)
int fuhao();
int num(int range);
int fen(int range);
int choose(int range);
int text(int number,int range);
int correction();
int count1(int num1,int num2,int f1);
int count2(int num1,int num2,int num3,int f1,int f2);

int main()
{
	srand((unsigned)time(NULL));
	void problem();
	int input=0;
	FILE * pFile0;
	pFile0 = fopen("Exercises.txt", "w");//"w"�½�һ���ı��ļ����Ѵ��ڵ��ļ���������գ�ֻ����д
	fclose(pFile0);
	printf("*****Сѧ��������*****\n");
	printf("��ѡ������Ҫ�Ĺ��ܣ�\n1.������Ŀ   2.������Ŀ\n");
	label:scanf("%d",&input);
	if(input!=1 && input!=2){
		printf("��������ȷ�Ĺ�������\n");
		goto label;
	}else{ 
	switch(input){
		case 1:
			printf("׼��������Ŀ\n");
			problem();
			break;
		case 2:
			printf("׼��������Ŀ\n");
			correction();
			break;
		}	
	}
 } 
 
 
 void problem(){
	int number=0;//numberΪ��Ҫ����Ŀ�� 
	A:printf("��������Ҫ����Ŀ������");
    scanf("%d",&number);
	if(number<1||number>10000)
	{
		printf("������1-10000������\n"); 
		goto A;//��ת�����A�� 
	}
	else
	{
		printf("������%d����Ŀ",number);
	int range=0;//rangeΪ������������ַ�Χ 
	printf("\n���������������������:"); 
	label2:scanf("%d",&range);
	if(range<0)
	{
		printf("�������ʺ�Сѧ������ķǸ���\n");
		goto label2;
	}
	else
	{
		text(number,range);//���������㷨 
		printf("�ѳɹ������Ŀ��Exercises.txt,���Ѵ���answer.txt");
	}
    }
}

int text(int number,int range)//�����ʽ�������� 
{  
    int i,lm,l,f1,f2,num1,num2,num3,jieguo;
    for(i=0;i<number;i++)//�涨������ٸ���ʽ 
    {
     FILE * pFile1;
	 pFile1 = fopen("Exercises.txt", "a");//"a"�򿪻��½�һ���ı��ļ���ֻ�������ļ�ĩβ׷д
	 fprintf(pFile1,"��%d�⣺",i+1);//��������txt�ļ� 
	 fclose(pFile1);
     num1=choose(range);//��ʽ�е�һ���� 
     f1=fuhao();//һ������ 
     num2=choose(range);//һ���� 
     if(rand()%2==1)
     {
     	f2=fuhao();
     	num3=choose(range);
     	jieguo=count2(num1,num2,num3,f1,f2);
	 }
	 else
	 {
	 	jieguo=count1(num1,num2,f1);
	 }
	 FILE * pFile20;
	 pFile20 = fopen("answer.txt", "a");
	 fprintf(pFile20,"%d.%d\n",(i+1),jieguo);//���"="�ͻ�����txt�ļ�  
	 fclose(pFile20);
	 FILE * pFile2;
	 pFile2 = fopen("Exercises.txt", "a");
	 fprintf(pFile2,"=\n");//���"="�ͻ�����txt�ļ�  
	 fclose(pFile2);
    }
} 

int fuhao()//���øú���ʱ��ֱ�����һ��������� 
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
		 return 0;
    	 break;
    	case 1:
		 FILE * pFile4;
		 pFile4 = fopen("Exercises.txt", "a");
		 fprintf(pFile4,"-");
		 fclose(pFile4);
		 return 1;
		 break;
		case 2:
		 FILE * pFile5;
		 pFile5 = fopen("Exercises.txt", "a");
		 fprintf(pFile5,"*");
		 fclose(pFile5);
		 return 2;
		 break;
		case 3:
		 FILE * pFile6;
		 pFile6 = fopen("Exercises.txt", "a");
		 fprintf(pFile6,"��");
		 fclose(pFile6);
		 return 3;
		 break;   
	}
}

int choose(int range)//�ú����������ת��������������������������������1/3����������2/3 
{
	int choose=rand()%3;
	int i;
	switch(choose)
	{
		case 0:
			i=num(range);
			return i;
			break;
		case 1:
			i=fen(range);
			return i;
			break;
		case 2:
		    i=num(range);
		    return i;
		    break;
	}
}

int num(int range)//���øú���ʱ�����һ��С��range��������� 
{
 int i;	
 FILE * pFile7;
 pFile7 = fopen("Exercises.txt", "a");
 i=rand()%(range-1)+1;
 fprintf(pFile7,"%d",i);
 fclose(pFile7);
 return i;
}


int fen(int range)// ���øú��������һ��С��range��������� 
{
 FILE * pFile8;
 pFile8 = fopen("Exercises.txt", "a");
 int i,j,k,r;
 A:i=rand()%(range-1)+1;
 j=rand()%(range-1)+1;
 k=rand()%(range-1)+1;
 r=i+j/k;
 if(r>=range){goto A;}
 fprintf(pFile8,"%d'%d/%d",i,j,k);
 fclose(pFile8);
 return r;
}

int count1(int a,int b,int f)
{
	int i;
	switch(f)
	{
		case 0:
			i=a+b;
			break; 
		case 1:
			i=a-b;
			break;
		case 2:
			i=a*b;
			break;
		case 3:
			i=a/b;
			break;
	}
	return i;
}

int count2(int a1,int b1,int c1,int f1,int f2)
{
	if(f2==2||f2==3)
	{
		b1=count1(b1,c1,f2);
	}
	a1=count1(a1,b1,f1);
	return a1;
}

int correction()
{
	FILE *fp1,*fp2;
	fp1=fopen("answer.txt","r");  //"r"��һ���ı��ļ����ļ�������ڣ�ֻ����� 
	fp2=fopen("your answer.txt","r");
	int i=0,j=0,correct=0,wrong=0,cc[10000],ww[10000],c=0,w=0,chu;
	float num1,num2,a[10000],b[10000];
	while (!feof(fp1))//��txt�ļ��е��������� 
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
	fprintf(pFile00,"*****Сѧ������������*****\n");
	fclose(pFile00);
	printf("�ѽ����Ľ������Grade.txt\n") ;
	printf("Correct��%d Correct number",correct);
	FILE * pFile9;
	pFile9 = fopen("Grade.txt", "a");
	fprintf(pFile9,"Correct��%d Correct number ",correct);//�����ȷ������txt�ļ� 
	fclose(pFile9);
	for(chu=0;chu<c;chu++){
		printf("%d ",cc[chu]);
		FILE * pFile10;
		pFile10 = fopen("Grade.txt", "a");
		fprintf(pFile10,"%d ",cc[chu]);//�����ȷ����� 
		fclose(pFile10);
		}
	printf("\n");
	FILE * pFile11;
	pFile11 = fopen("Grade.txt", "a");
	fprintf(pFile11,"\n");
	fclose(pFile11);
	printf("Wrong��%d Wrong number ",wrong);
	FILE * pFile12;
	pFile12 = fopen("Grade.txt", "a");
	fprintf(pFile12,"Wrong��%d Wrong number ",wrong);//���������� 
	fclose(pFile12);
	for(chu=0;chu<w;chu++){
		printf("%d ",ww[chu]);
		FILE * pFile13;
		pFile13 = fopen("Grade.txt", "a");
		fprintf(pFile13,"%d ",ww[chu]);//���������� 
		fclose(pFile13);
		}
}

