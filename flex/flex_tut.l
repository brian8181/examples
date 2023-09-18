%{
    /* definitions */
%}

%%

[a-z] {printf("Single lower case\n");}
. {printf("not a lower case\n");}
\n {return 0;}

%%

yywrap() {}

int main()
{
    printf("Enter string: ");
    yylex();

    return 0;
}

