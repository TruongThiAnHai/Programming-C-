#include <stdio.h>
#include <conio.h>
#include<malloc.h>
int getInt(int* a)
{
    int n;
    do {
        n=scanf("%d",a);
        if (n==0 || (*a<=0) )
        {
            printf ("Error");
            scanf ("%*[^\n]");
            n=0;
        }

    }while (n==0);
    return 1;
}
int kolichestvo (int num)
{
    int a,n=1;
    a=num/10;
    while (a!=0)
    {
        n=n+1;
        a=a/10;
    }
    return n;

}
int function(int num, int* newnum)
{
    int i,n,j=1,k,b[100],m;
    n=kolichestvo (num);
    m=n;
    for (i=0;i<n;i++)
    {
        b[i]= num%10;
        num=num/10;
    }
    newnum[0]=b[0];
    for (i=1;i<m;i++)
    {
        if (b[i]!=b[i-1])
        {
            newnum[j]=b[i];
            j=j+1;
        }
        else n=n-1;

    }
    printf ("new number: ");
     for (i=n-1;i>=0;i--)
     {
         printf ("%d", newnum[i]);
     }
    printf ("\tn=%d",n);
    return n;
}
int main()
{
    int n,num[100],i,j,a[100],c,newnum[100],m;
    printf ("How many numbers in the sequence? n=");//сколко чисел в последовательности?
    getInt(&n);
    m=n;
    for (i=0; i<n;i++)
    {
        printf ("\n\nNumber %d:",i+1);
        getInt(&num[i]);
        a[i]=function(num[i],&newnum[i]);
    }
    printf ("\n-----------------------------------------------------------\n");
    printf ("\n\nOld sequence:\n");
     for (i=0; i<m;i++)
        {
            printf ("\nNumber %d: %d",i+1,num[i]);

        }
    for (i=0; i<n;i++)
     {
         for (j=0;j<i;j++)
            {
                if (a[i]<a[j])
                    {
                        c=num[i];
                        num[i]=num[j];
                        num[j]=c;

                    }
            }
     }

    printf ("\n-----------------------------------------------------------\n");
    printf ("\n\nNew sequence:\n");
    for (i=0; i<n;i++)
        {
            printf ("\nNumber %d:",i+1);
            function(num[i],&newnum[i]);
        }
    getch();
}

