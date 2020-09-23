
//UTSAB OJHA
//119CS0145
//g++ compiler


#include<iostream>
#include <cstring>
using namespace std;
int top = -1;
int preced(char val)
{
    switch (val)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    case '(':
        return 0;
    }
    return -1;
}
int getNextToken(char *a)
{
    int i=0;
    if(i<strlen(a))
        return i++;
    else
    {
        return NULL;
    }
}
char* infixToPostfix(char* a)
{
    int i, j = 0; char* b, * c;
    b = new char[strlen(a) + 1];
    c = new char[strlen(a)];
    for (i = 0; i < strlen(a); i++)
    {
        if ((a[i] >= 'a' && a[i] <= 'z') || (a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= '0' && a[i] <= '9'))
            b[j++] = a[i];
        else if (a[i] == '(')
            c[++top] = a[i];
        else if (a[i] == ')')
        {
            while (c[top] != '(')
                b[j++] = c[top--];
            top--;
        }
        else
        {
            if (top == -1)
                c[++top] = a[i];
            else
            {
                if (preced(a[i]) <= preced(c[top]))
                {
                    while (top >=0 && preced(a[i]) <= preced(c[top]))
                        b[j++] = c[top--];
                    c[++top] = a[i];
                }
                else
                    c[++top] = a[i];
            }
        }
    }
    while (top != -1)
        b[j++] = c[top--];
    b[j] = '\0';
    return b;
}
int main()
{
    char* expres; int n;
    cout << "expression length : ";
    cin >> n;
    expres = new char[n + 1];
    cout << "expression : ";
    cin >> expres;
    if (expres[n - 1] == '+' || expres[n - 1] == '-' || expres[n - 1] == '/' || expres[n - 1] == '*' || expres[n - 1] == '(' || expres[n - 1] == '^')
    {
        cout << "Invalid expression";
        return 1;
    }
    expres[n] = '\0';
    cout << "Infix expression : ";
    cout << expres << "\n";
    expres = infixToPostfix(expres);
    cout << "Postfix expression : ";
    cout <<expres<<"\n";
    return 0;
}