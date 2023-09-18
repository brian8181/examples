%{
    /* definitions */
%}

/* rules section */
%%

[a-z] {printf("Single lower case character...\n");}
. {printf("Not a lower case character...\n");}
\n {return 0;}

%%

<<<<<<< HEAD:flex/flex1.l
int yywrap() {return 0;}
=======
int yywrap() {return 1;}
>>>>>>> f858373d60c6077435484273a943128b2de59335:flex/flex_tut.l

int main()
{
    printf("Enter string: ");
    yylex();

    return 0;
}
