#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Item
{
    char c;
    struct Item *next;
}Item;
Item *deleteList (Item *ptr)
{
    Item *tmp=NULL;
    while (ptr!= NULL)
    {
        tmp=ptr;
        ptr=ptr->next;
        free(tmp);
    }
    return ptr;
}
int getList (Item **pptr)
{
    char buf[81], *str;
    Item head ={'*',NULL};
    Item *last=&head;
    int n,rc=1;
    do
    {
        n=scanf("%80[^\n]",buf);
        if (n<0)
        {
            deleteList(head.next);
            head.next=NULL;
            rc=0;
            continue;
        }
        if (n>0)
        {
            for(str=buf;*str!='\0';++str)
            {
                last->next=(Item*)malloc(sizeof(Item));
                last=last->next;
                last->c=*str;
            }
            last->next=NULL;
        }
        else scanf("%*c");
    }while(n>0);
    *pptr=head.next;
    return rc;
}
void putList( Item *str)
{
    for(;str!=NULL;str=str->next)
    printf ("%c",str->c);
    printf ("\n");
}
int count_ones (Item *str)
{
    int ones=0;
    while (1)
    {
        if (str==NULL) break;
        if (((str->c)==' ')||((str->c)=='\t')) break;
        if ((str->c)=='1') ones++;
        str=str->next;
    }
    return ones;

}
Item *delSpace_first(Item* str)
{
    while (1)
    {
        if (str==NULL) break;
        if (((str->c)=='1')||((str->c)=='0')) break;
        str=str->next;
    }
    return str;
}
Item *delCode(Item* str)
{
    while (1)
    {
        if (str==NULL) break;
        if (((str->c)==' ')||((str->c)=='\t')) break;
        str=str->next;
    }
    str=delSpace_first(str);
    return str;
}
void putfirstCode( Item** str1,Item **str2)
{
	Item *ptr = *str1;

	if (*str1 == NULL)
    {
		*str1 = *str2;
	}
	else
    {
		while ((ptr->next!=NULL)&&(ptr->c!=' ')&&(ptr->c!='\t'))
		{
			ptr= ptr->next;
			if((ptr->c)=='\t') ptr->c=' ';
		}
		ptr->next = *str2;
	}

}
void Combine( Item** str1,Item **str2)
{
	Item *ptr = *str1;

	if (*str1 == NULL)
    {
		*str1 = *str2;
	}
	else
    {
		while(ptr->next!=NULL)
		{
			ptr= ptr->next;
		}
		ptr->next = *str2;
	}

}
void new_string (Item *str)
{
    int ones;
    Item *str2=NULL,*str1,*str3,*str4;
    /*str=delSpace_first(str);*/
    str1=delCode(str);
    ones=count_ones(str);
    putfirstCode(&str,&str2);
    while (str1)
    {
        if (count_ones(str1)==ones)
        {
            str4=delCode(str1);
            putfirstCode(&str1,&str2);
            Combine(&str,&str1);
            str1=str4;

        }
        else
        {
            str1=delCode(str1);
        }
    }
    putList(str);
}
int main()
{
    Item *str,*str2;
    while (puts("Enter string"), getList(&str))
    {
        printf ("\nResult: \n");
        new_string(str);
        printf ("\n-------------------------------------------------------------\n\n");
    }
    printf("\n=========================That's all=================================");
    return 0;
}
