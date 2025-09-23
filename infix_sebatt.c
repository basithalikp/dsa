#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100


char stack[MAX];
int top=-1;



void push(char c){
       
stack[++top]=c;
}



char pop(){
        if(top==-1)
        {
           printf("Stack is empty\n");
           }
        else
return stack[top--];
}


int precedence(char op){
if(op=='^')
return 3;
else if(op=='*' || op=='/')
return 2;
else if(op=='+' || op=='-')
return 1;
else
 return 0;

}



void intopost(char infix[],char postfix[]){
int i=0,k=0;
char c;
top=-1;
while (infix[i]!='\0'){
c=infix[i];
if(c!=' ' && c!='\t'){
if(isalnum(c)){
postfix[k]=c;
k=k+1;;
}
else if(c=='('){
push(c);
}
else if(c==')'){
while(top!=-1 && stack[top]!='('){
postfix[k]=pop();
k=k+1;
}
pop();

}
else{
while(top!=-1 && ((c!='^' && precedence(stack[top])>=precedence(c)) ||
(c!='^' && precedence(stack[top])>precedence(c)))){
postfix[k]=pop();
k=k+1;

}
push(c);
}


}
i=i+1;
}

while(top != -1){
postfix[k]=pop();
k=k+1;
}
postfix[k]='\0';
}




int main(){

char infix[MAX];
char postfix[MAX];

printf("Enter the infix expression: ");
fgets(infix,MAX,stdin);

intopost(infix,postfix);

printf("the postfix expression is %s\n",postfix);

return 0;
}