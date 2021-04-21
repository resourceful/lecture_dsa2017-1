#include <stdio.h>
#include "stack.h"

typedef enum {lparen, rparen,
              plus, minus,
              times, divide,
              mod, eos, operand
              } precedence;

precedence get_token(char *exp, char *symbol, int *pn)
{
    *symbol = exp[(*pn)++];
    switch (*symbol)
    {
        case '(': return lparen;
        case ')': return rparen;
        case '+': return plus;
        case '-': return minus;
        case '*': return times;
        case '/': return divide;
        case '%': return mod;
        case '\0': return eos;
        default : return operand;
    }
}

int eval(char* exp){
    precedence token;
    
    int op1, op2;
    int n = 0;
    char symbol;

    int result = 0;

    dstack *s = CreateStack();

    token = get_token(exp, &symbol, &n);
    
    while (token != eos)
    {
        if (token == operand)
        {
            Push(s, symbol-'0');
        }
        else
        {
            op2 = Pop(s);
            printf("op2 %d\n", op2);
            op1 = Pop(s);
            printf("op1 %d\n", op1);
            switch (token)
            {
                case plus: Push(s, op1 + op2);
                        break;
                case minus: Push(s, op1 - op2);
                        break;
                case times: Push(s, op1 * op2);
                        break;
                case divide: Push(s, op1 / op2);
                        break;
                case mod: Push(s, op1 % op2);
                        break;
            }
            printf("mid %d\n", Top(s));
        }
        token = get_token(exp, &symbol, &n);
    }
    return Pop(s);
}

int main(void)
{
    char exp[] = "235*+9-"; // 3 * 5 + 2 - 9 = 8
    printf("postfix evaluation: %d\n", eval(exp));
    return 0;
}