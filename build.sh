echo `yacc -d translator.yacc`
echo `flex translator.lex`
echo `yacc -d translator.yacc`
echo `gcc lex.yy.c y.tab.c -o translator.out`
##echo `./translator.out`