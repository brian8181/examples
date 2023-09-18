%{
    /* definitions */
%}

/* rules section */
%%

[a-z] {printf("Single lower case character...\n");}
. {printf("Not a lower case character...\n");}
\n {return 0;}

%%

int yywrap() {return 1;}

int main()
{
    printf("Enter string: ");
    yylex();

    return 0;
}

