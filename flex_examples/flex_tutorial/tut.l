%{
    /* */
%}

/* rules */
%%

if {printf("keyword\n"); }
[a-z0-9.]{3,10}@[a-z0-9.-]+ { printf("email\n"); }
[6-9][0-9]{9} { printf("mobile\n"); }
[a-zA-Z_][a-zA-Z0-9_] { printf("valid\n"); }
. { printf("invalid\n"); }
\n {return 0;}

%%


yywrap() {};


int main() {
    printf("Enter a string: ");
    yylex();

    return 0;
};