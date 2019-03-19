#include<stdio.h>

struct nstk// a new data type for number stack 
{
int stack[200];
int top;
} nstack;

struct ostk//a new data type for operator stack
{
char stack[200];
int top;
} ostack;

void npush (int num) //a function to push numbers into a stack 
{
 nstack.top = nstack.top + 1;
 nstack.stack[nstack.top] = num;
 return;
}

int npop () //a function to pop out a number from a stack
{
int number;
number = nstack.stack[nstack.top];
nstack.top = nstack.top - 1;
return(number);
}

void opush (char oper)//a function to push an operator into a stack
{
 ostack.top = ostack.top + 1;
 ostack.stack[ostack.top]=oper;

 return;
}

char opop ()//a function to pop out an operator from a stack
{
char oper;
oper = ostack.stack[ostack.top];
ostack.top = ostack.top - 1;
return(oper);
}

int main()
{
  int k, l,h=0,number, i=0, j=1,y=1;//j,y - count for error for paranthesis
 char num[100],opera;               //h - count for error for having open brackets just after an integer
                                    //y - count for integers
 printf("enter your input\n");      //j - count for operators
 scanf(" %s",num);
 
 nstack.top=-1; //assuming
 ostack.top=-1; //assuming
 for(;num[i]!=0;)
 {
 	if(num[i]<='9'&&num[i]>='0')
 	{
 		j--;
 		h++;
  		number=num[i]-48; //removing ASCII values from the numbers 
  		i++;
  		for(;num[i]<='9'&&num[i]>='0';i++) number=number*10+num[i]-48;
  		npush(number);//pushes the number inside a stack
     }
 	else if(num[i]=='(') //when encountered an open bracket in the input
 	{   
 	 	opush('(');
		y++;      //pushes it into the operator stack
 	 	i++;
 	 	if(h=1)
 	 	{
 	 		printf("invalid input\n");
 	 		return 0;
		  }
		               //increases the count to find if there are any other such in the input
 	}
 	else if(num[i]==')')//when encountered a closed bracket
 	{  y--;
 	 	while (ostack.stack[ostack.top] != '(') //while the top element in the stack is not an open bracket
 	 	{
 	 		l=npop();                            //pops out the stored numbers
 	 		k=npop();
 	 		opera=opop();	
 	 		
 	 		switch(opera)                       //if the encountered operator is; the function executes
 	 		{
 	 			case '+': npush(k+l);break;
 	 			case '-': npush(k-l);break;
 	 			case '*': npush(k*l);break;
 	 			case '/': npush(k/l);break;
 	 		}	
 	 	}
          opop();	
 	 	i++;
		        
 	}
 	else if(num[i]=='+'||num[i]=='-'||num[i]=='*'||num[i]=='/')//if encountered any of these arithmetic operators
 	{char newop=num[i];j++;
 	  	while (ostack.top>-1) 
 	 	{
 	     	if (newop=='+'||newop=='-')   
 	     	{
 	     		if(ostack.stack[ostack.top]!='(')  //executes the sum by popping out the numbers and an operator 
 	     		{
 	     			l=npop();
 	     			k=npop();
 	     			opera=opop();                        
 	     			switch(opera)
 	     			{
 	     	 			case '+': npush(k+l);break;
 	     	 			case '-': npush(k-l);break;
 	     	 			case '*': npush(k*l);break;
 	     	 			case '/': npush(k/l);break;
 	     			}
 	     		}
 	     		else break;
 	     	}
 	     	
 	     	else if (newop=='*'||newop=='/')//when encountered " * , / " operators
 	     	{
 	     	
 	     		if(ostack.stack[ostack.top]=='/'||ostack.stack[ostack.top]=='*')
 	     		{
 	     			l=npop();                                //these operators are of higher precedence so they will be carried out first
 	     			k=npop();                                //the two numbers will be popped out and the following arithmetic operation will be carried out
 	     			opera=opop();
 	     	
 	     			switch(opera)
 	     			{
 	     				case '*': npush(k*l);
 	     				break;
 	     				case '/': npush(k/l);
 	     				break;
 	     				default:;
 	     			}
 	     		}
 	     		else break;
 	     	}
 	     	 
 	    }
 	 	
 	 	opush(newop);
 	
 	 i++;
 	 h--;
 	}
 	
 	
 	if(j==2)
 	{
 		printf("invalid expression\n");
 		return 0;
	 }
 
 }
 if(y!=1)
 {
 	printf("invalid expression\n");
 	return 0;
 }
 
 while (ostack.top>-1) //when the operator stack is not empty i.e the value will increase by 1 whenever an element is pushed into this stack
 {
  	opera=opop();
  	l=npop();                              //the results of the arithmetic operation of other elements will be considered as an element 
  	k=npop();                              // and picking those elements the following operations will be executed based on the input           
  	switch (opera)
      {
    	 	case '+': npush(k+l);break;
    	 	case '-': npush(k-l);break;
        	case '*': npush(k*l);break;
    	 	case '/': npush(k/l);break;
    	}   
 }
 
 
 
 number=npop(); //finally only one element will remain in the number stack and that number will be popped out and stored as NUMBER
 
 printf("\n%d",number);//final result
 return 0;
}








