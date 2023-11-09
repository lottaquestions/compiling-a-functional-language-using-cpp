%option noyywrap

%{
#include <iostream>
/*
How to compile:
flex -o scanner.cpp scanner.l
g++ -o scanner scanner.cpp

Usage:

echo "3+2*6" | ./scanner
*/

%}

%%

[ \n]+ {}
\+ { std::cout << "PLUS" << std::endl; }
\* { std::cout << "TIMES" << std::endl; }
-  { std::cout << "MINUS" << std::endl; }
\/ { std::cout << "DIVIDE" << std::endl; }
[0-9]+ { std::cout << "NUMBER: " << yytext << std::endl; }
defn   { std::cout << "KEYWORD: defn" << std::endl; }
data   { std::cout << "KEYWORD: data" << std::endl; }
case   { std::cout << "KEYWORD: case" << std::endl; }
of     { std::cout << "KEYWORD: of" << std::endl; }
\{   { std::cout << "OPEN CURLY" << std::endl; }
\}   { std::cout << "CLOSED CURLY" << std::endl; }
\(   { std::cout << "OPEN PAREN" << std::endl; }
\)   { std::cout << "CLOSED PAREN" << std::endl; }
,    { std::cout << "COMMA" << std::endl; }
->   { std::cout << "PATTERN ARROW" << std::endl; }
=    { std::cout << "EQUAL" << std::endl; }
[a-z][a-zA-Z]*   { std::cout << "LOWER CASE IDENTIFIER: " << yytext << std::endl; }
[A-Z][a-zA-Z]*   { std::cout << "UPPER CASE IDENTIFIER: " << yytext << std::endl; }

%%

int main(){
  yylex();
}
