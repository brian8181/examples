%%

. ECHO;  /** match everything except newline **/
\n ECHO; /** match newline **/

%%

int yywrap(void) 
{
    return 1;
}

int main(void)
{
    yylex();
    return 0;
}
