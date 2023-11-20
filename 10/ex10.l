%{
#include<stdio.h>
int v=0,c=0;
%}

%%
[aeiouAEIOU] {v++;}
[ ] 
. {c++;}
%%

int main()
{
	printf("Enter the string:");
	yylex();
	printf("Number of vowels=%d\n",v);
	printf("Number of consonants=%d\n",c);
}
int yywrap()
{
	return 1;
}
