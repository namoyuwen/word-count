#include<stdio.h>
#include<stdlib.h>

int charc(char *file);
int wordc(char *file);
int linec(char *file);

int main(){
	FILE *fp;
	int ch,wo,li;
	char file[150];//�ļ���ַ
	printf("\n�������ļ���ַ��\n");
	scanf("%s",file);

	if((fp=fopen(file,"r"))==NULL)
		{
			printf("����������ļ�");
			exit(-1);
		}
	else{
		ch=charc(file);
		wo=wordc(file);
		li=linec(file);
		printf("\n���ļ��ַ���Ϊ%d\n������Ϊ%d\n����Ϊ%d\n",ch,wo,li);
		}
}
int charc(char *file) {
    FILE *fp = NULL;
    int charcount = 0;
    if ((fp=fopen(file,"r"))== NULL) {
        printf("�ļ�Ѱ��ʧ�ܣ�\n");
        exit(-1);
    }
    char ch;
  ch = fgetc(fp);
    while (!feof(fp)) {
        ch = fgetc(fp);//��ȡ�ļ��е��ַ�
        charcount++;//ͳ���ַ���
    }
    fclose(fp);
    return charcount;
}
int wordc(char *file) {
    FILE *fp = NULL;
    int wordcount = 0;
    if ((fp = fopen(file,"r")) == NULL) {
        printf("�ļ�Ѱ��ʧ�ܣ�\n");
        exit(-1);
    }
    char ch;
    int word;

    while (!feof(fp)) {
        ch = fgetc(fp);
        if (ch<'A' || (ch> 'Z'&&ch< 'a') || ch>'z')
        {
            word = 0;
        }
        else if (word == 0)
        {
            word = 1;
            wordcount++;
        }
    }
    return wordcount;
}
int linec(char *file){//��������
	int linecount=0;
	char ch,li=0;
	FILE *fp;
	if ((fp=fopen(file,"r"))==NULL)
	{
		exit(-1);
	}
	ch = fgetc(fp);
	while (!feof(fp))
	{
		if(ch=='\n')
			linecount++;
		li=ch;
	}
	if (li!='\n')
		linecount++;
	return linecount;
}
