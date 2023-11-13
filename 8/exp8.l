%{
#include<stdio.h>
int wc=0,lc=0,cc=0;
%}

%%
[\n] {lc++;cc+=yyleng;}
[^\t\n ]+ {wc++;cc+=yyleng;}
%%

int main()
{
	FILE *fp=fopen("text.txt","r");
	if(fp)
	{
		yyin=fp;
	}
	yylex();
	printf("The number of lines=%d\n",lc);
	printf("The number of words=%d\n",wc);
	printf("The number of characters are=%d\n",cc);
}
int yywrap()
{
	return 1;
}
