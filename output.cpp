#include<stdio.h>
int OutputData(const char *pFileName)//����Ҫ��������ֺ͵�ַ
{
    FILE * pFile;
    pFile = fopen(pFileName, "w");//"w"�½�һ���ı��ļ����Ѵ��ڵ��ļ���������գ�ֻ����д
	pFile = fopen(pFileName, "a");//"a"�򿪻��½�һ���ı��ļ���ֻ�������ļ�ĩβ׷д
	if (NULL == pFile)
	{//�ļ��򿪴���
		printf("error");
		return 0;
	}
	for (int i = 0; i < 3; i++)
	{//ѭ��������ݲ�д��
		printf("%.3f\n", 3.1415926);
		fprintf(pFile,"%.3f\n", 3.1415926);//����ѭ��д���ļ� 3��  3.14
	}
	fclose(pFile);//���һ���ǵùر��ļ�
}
//����
int main()
{
   const char *pFileName="output.txt";  //д������ļ�Ŀ¼��
   OutputData(pFileName);
   return 0;
}

