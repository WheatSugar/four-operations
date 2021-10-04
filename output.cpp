#include<stdio.h>
int OutputData(const char *pFileName)//这是要保存的名字和地址
{
    FILE * pFile;
    pFile = fopen(pFileName, "w");//"w"新建一个文本文件，已存在的文件将内容清空，只允许写
	pFile = fopen(pFileName, "a");//"a"打开或新建一个文本文件，只允许在文件末尾追写
	if (NULL == pFile)
	{//文件打开错误
		printf("error");
		return 0;
	}
	for (int i = 0; i < 3; i++)
	{//循环输出数据并写入
		printf("%.3f\n", 3.1415926);
		fprintf(pFile,"%.3f\n", 3.1415926);//这里循环写入文件 3个  3.14
	}
	fclose(pFile);//最后一定记得关闭文件
}
//测试
int main()
{
   const char *pFileName="output.txt";  //写入程序文件目录中
   OutputData(pFileName);
   return 0;
}

