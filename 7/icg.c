#include<stdio.h>
#include<string.h>
char expr[20],temp='Z';
void main()
{
    printf("Enter expression:");
    scanf("%s",expr);
    printf("\nIntermediate Code:\n");
    while(strlen(expr)>3)
    {
        int flag=0;
        if(flag !=1)
        {
            for(int i=0;i<strlen(expr);i++)
            {
                if(expr[i]=='/' || expr[i]=='*')
                {
                    printf("\n%c=%c%c%c",temp,expr[i-1],expr[i],expr[i+1]);
                    expr[i-1]=temp;
                    temp--;
                    for(int j=i;expr[j]!='\0';j++)
                        expr[j]=expr[j+2];
                    flag=1;
                    break;
                }
            }
        }
        if(flag !=1)
        {
            for(int i=0;i<strlen(expr);i++)
            {
                if(expr[i]=='+' || expr[i]=='-')
                {
                    printf("\n%c=%c%c%c",temp,expr[i-1],expr[i],expr[i+1]);
                    expr[i-1]=temp;
                    temp--;
                    for(int j=i;expr[j]!='\0';j++)
                        expr[j]=expr[j+2];
                    flag=1;
                    break;
                }
            }
        }
    }
    printf("\n%s",expr);
}
