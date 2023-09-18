#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int iskeyword(char buffer[])
{
char keywords[32][10] = {"auto","break","case","char","const","continue","default",
"do","double","else","enum","extern","float","for","goto",
"if","int","long","register","return","short","signed",
"sizeof","static","struct","switch","typedef","union",
"unsigned","void","volatile","while"};
int flag=0;
for(int i=0;i<32;i++)
{
if(strcmp(keywords[i],buffer)==0)
{
flag=1;
break;
}
}
return flag;
}


int main()
{
	char ch,buffer[15],operators[]="+-*/%=";
	char special[]="#{};()\"\'<>";
	FILE *fp;
	int i,j=0;
	fp=fopen("prgm1.c","r");
	if(fp==NULL)
	{
		printf("Error in opening\n");
		exit(0);
	}
	while((ch=fgetc(fp))!=EOF)
	{
		for(i=0;i<6;i++)
		{
			if(ch==operators[i])
			{
				if(ch=='/')
				{
					if((ch=fgetc(fp))=='/')
					{
						while((ch=fgetc(fp))!='\n');
					}
					else if((ch=fgetc(fp))=="*")
					{
						while((ch=fgetc(fp))!='/');
						
					}
					else
					{
						printf("%c is an operator\n",ch);
						break;
					}
				}
				else
					{
						printf("%c is an operator\n",ch);
						break;
					}
			}
		}
		for(i=0;i<7;i++)
		{
			if(ch==special[i])
			{
				printf("%c is a special symbol\n",ch);
				break;
			}
		}
		if(isalnum(ch))
		{
			buffer[j++]=ch;
		}
		else if((ch==' ' || ch=='\n'||ch=='('||ch==')'||ch=='<'||ch=='>') && (j!=0))
		{
			buffer[j]='\0';
			j=0;
			if(iskeyword(buffer)==1)
				printf("%s is keyword\n",buffer);
			else
				printf("%s is identifier\n",buffer);
		}
	}
	fclose(fp);
	return 0;
}
