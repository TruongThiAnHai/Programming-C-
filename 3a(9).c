#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
int n,i,j,k,ones=0;
char *getstring()
{
	int n, l;
	char buf[80];
	char *str = NULL, *p;
	str = (char *)malloc(sizeof(char));
	if (str == NULL) return NULL;
    strcpy(str,"");
	do{
		n = scanf("%79[^\n]",buf);
		if (n == -1)
        {
            free(str);
            return NULL;
        }
		if (n == 0) scanf("%*c");
        else
        {
            l = strlen(buf)+strlen(str)+1;
            p = (char *)realloc(str,l);
            if (p == NULL)
            {
                free(str); return NULL;
            }
            str = p;
            strcat(str, buf);
        }
       }while(n!=0);
    k=0;
    for (i=0;i<strlen(str);i++)
    {
        if ((str[i]!='0')&&(str[i]!='1')&&(str[i]!='\t')&&(str[i]!=' ')) k++;
    }
    if (k!=0)
    {
        puts("Error");
        *str='\0';
    }
	return str;
}
char *Result_codes(char* s, char* p)
{
    char *token, ch[]={' ','\t'};
    token=strtok(s,ch);
    j=count(token);
    strcpy(p,token);
    while( token != NULL )
    {
        token = strtok(NULL, ch);
        if (token !=NULL)
        {
            i=count(token);
            if (i==j)
            {
                strcat(p," ");
                strcat(p,token);

            }
        }

    }
    return p;
}
int count(char* str)
{
    int ones=0;
    n=strlen(str);
    for (i=0;i<n;i++)
    {
            if (str[i]=='1') ones++;
    }
    return ones;
}
int main()
{
    int l,k;
    char *str;
    char *res=NULL;
    res = (char *)malloc(1);
    while((str=getstring()))
    {
        l = strlen(str);
        res =(char *)malloc((l)*sizeof(char));
        if(l>0)
        {
            if(res==NULL) exit(0);
            strcpy(res,"");
            res= Result_codes(str,res);
            printf("%s\n",res);
        }
        free(str);
        free(res);
        fflush(stdin);
    }
    printf("\n------------------------------That's all--------------------------------\n");
	return 0;
}

