#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void* getline(void)
{
	int ch = 0;
	int k = 0;
	char* buf = NULL;
	char temp[100] = {0};
	do
	{
		ch = getchar();
		temp[k] = ch;
		k++;
	}while((ch != EOF) && (ch != '\n'));

	if (ch != EOF)
	{
		buf = malloc(strlen(temp) + 1);
		strcpy(buf, temp);
		return buf;
	}
	else
	{
		return NULL;
	}
}


int find_str(char* buf, char* str, int row)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;
	for (i = 0; buf[i] != '\0'; i++)
	{
		for (j=i, k=0; (str[k] != '\0') && (buf[j] == str[k]); j++, k++)
		{
			;
		}
		if ((k > 0) && (str[k] == '\0'))
		{
			printf("row=%d\tcol=%d\n", row+1, i);
			printf("%s\n", buf);
			count++;
			i = j - 1;
		}
	}
	return count;
}
int main(int argc, char** argv)
{
	char* a = NULL;
	char* buf[100] = {0};
	char str[100] = "ab";
	int k = 0;
	int total = 0;
	int nline = 0;
	int i = 0;

	do{
		a = getline();
		buf[nline] = a;
		nline++;
	}while(a != NULL);
	nline--;

	for (i = 0; i < nline; i++)
	{
		total = total + find_str(buf[i], str, i);
	}
	printf("the total time :%d\n", total);
	
	return 0;
		
}