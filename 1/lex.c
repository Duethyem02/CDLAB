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
	FILE *fp1,*fp2;
	int i,j=0;
	fp1=fopen("prgm1.c","r");
	fp2=fopen("out1.txt","w");
	if(fp1==NULL)
	{
		printf("Error in opening\n");
		exit(0);
	}
	fprintf(fp2,"Lexeme\t\tToken\n");
	while((ch=fgetc(fp1))!=EOF)
	{
		if(isdigit(ch))
		{
			fprintf(fp2,"%7c\t\tDigit\n",ch);
		}

		else if(isalpha(ch))
		{
			buffer[j]=ch;
			j++;
			ch=fgetc(fp1);

			while(isalnum(ch) && ch!=' ')
			{
				buffer[j]=ch;
				j++;
				ch=fgetc(fp1);
			}

			buffer[j]='\0';
			j=0;
			if(iskeyword(buffer)==1)
			{
				fprintf(fp2,"%7s\t\tKeyword\n",buffer);
			}

			else
			{
				fprintf(fp2,"%7s\t\tIdentifier\n",buffer);
			}

		}
		for(i=0;i<6;i++)
		{
			if(ch==operators[i])
			{
				if(ch=='/')
				{

					char c=fgetc(fp1);
					if(c =='/')
					{
						while((c=fgetc(fp1))!='\n');
					}
					else if(c =='*')
					{
						while((c=fgetc(fp1))!='/'); 	
					}
					else
					{
						fprintf(fp2,"%7c\t\tOperator\n",ch);
						ungetc(c,fp1);
						break;
					}
				}
				else
					{
						fprintf(fp2,"%7c\t\tOperator\n",ch);
						break;
					}
			}
		}
		for(i=0;i<7;i++)
		{
			if(ch==special[i])
			{
				fprintf(fp2,"%7c\t\tSpecial symbol\n",ch);
				break;
			}
		}
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}
