#include <stdio.h>
int main()
{
	FILE *fp1,*fp2;
	fp1=fopen("output.txt","r");  //"r"打开一个文本文件，文件必须存在，只允许读 
	fp2=fopen("output.txt","r");
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
	

	printf("正确个数为：%d 正确题号为 ",correct);
	for(chu=0;chu<c;chu++){printf("%d ",cc[chu]);}
	printf("\n");
	printf("错误个数为：%d 错误题号为 ",wrong);
	for(chu=0;chu<w;chu++){printf("%d ",ww[chu]);}
}

