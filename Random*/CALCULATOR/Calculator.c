#include<stdio.h>

long long int add(long long int x, long long int y) // a function for addition
{
	long long int k;
	k=x+y;//addition operation
	printf("%lld + %lld = %lld\n",x,y,k);
	return 0;
}

long long int subtract(long long int a,long long int b)
{
	long long int k;
	k=a-b;
	printf("%lld - %lld = %lld\n",a,b,k);
	return 0;
}

long long int multiply(long long int a,long long int b)
{
	long long int x=0,i;
	for(i=1;i<=b;i++)//loop goes on adding first number second number no. of times
	{
		x=x+a;
	}
	printf("the result of the operation is %lld\n", x);
	
}

long long int mul(long long int a,long long int b)//a duplicate function of multiplication to avid printing the multiplication value several times
{                    // this function returns value which is used in power function
	long long int x=0,i;
	for(i=1;i<=b;i++)//same as multiplication func
	{
		x=x+a;
	}
	return x;        //returns the value of x

}


long long int division(long long int x,long long int y)//a function for division
{  
    long long int i=0,c=0;
   if(y==0)
   {
   	printf("this is not possible\n");
   	return 0;
   }
	
     while(x>=y) //while that condition is satisfying the loop goes on subtracting smaller number from larger number
	{   c++;     //this counts every time the loop runs which gives us the quotient 
		x=x-y;
		
	}
	printf("the result of the operation is %lld\n", c);		
}

long long int modulo(long long int x,long long int y)
{   
	while(x>=y)  //when the condition satisfies the loop goes on subtracting smaller number from larger number until that condition dissatisfies 
	{
		x=x-y;
	}
	printf("the result of the operation is %lld\n", x);
}

long long int square(long long int x)
{
 long long int i, m=0;

    for(i=1;i<=x;i++) //this loop goes on adding the input number its no. of times
    {
	m=m+x;
    }
	printf("%lld x %lld = %lld\n",x,x, m);
}

long long int sq(long long int x) //duplicate function of square function to avoid printing of the square of numbers while printing root  
{
 long long int m=0,i;    

    for(i=0;i<x;i++)//functions similar to square function
    {
	m=m+x;
    }
	return m;
}

long long int root(long long int y) 
{
	long long int i;
	
	if(y==0)
	{
		printf("this operation is not possible\n");
		return 0;
	}
	 for(i=1;sq(i)<=y;i++) //this loop goes on checking the squares of all the numbers until the input number 
     {
     	
	 }
	printf("the result of the operation is %lld\n",i-1); //prints the value whose square is just lesser than the square of input
}

long long int power(long long int a,long long int b) // a function that gives any no. to the power of any no. which is useful for log function
{    long long int t,c;
     	c=a;
	 for(t=2;t<=b;t++)//finds one number to the power of another number by multipling the first number second number no. of times 
	 {
	 
	 	c=mul(c,a);
	 }
	 return c;//returns the value of c
}

long long int log(long long int a)
{   long long int i,b=2; // we fixed the second number value to 2
    
    if(a==0)
    {
    	printf("this operation is not possible\n");
    	return 0;
	}


    if(a==1)
    {
    	printf("0");
    	return 0 ;
	}
	for(i=1;power(b,i)<a;i++)//finds the two power of all the numbers until it is just greater than the input value
	{
		
	}
	printf("the result of the operation is %lld\n", i);	
}
int main()
{
	long long int a,b,c;
	
	while(c!=9)
	{
	printf("menu\n");
	printf("1-add\n");
	printf("2-subtract\n");
	printf("3-multiply\n");
	printf("4-divide\n");
	printf("5-modulo\n");
	printf("6-square\n");
	printf("7-square root\n");
	printf("8-log\n");
	printf("9-exit\n");
	printf("enter your option\n");
	
	scanf("%d", &c);
		if(c==1||c==2||c==3||c==4||c==5)
	{
		printf("enter first number\n");
		scanf("%lld", &a);
		
		printf("enter second number\n");
		scanf("%lld", &b);
	}
	
	else if(c==6||c==7||c==8)
	{
		printf("enter number\n");
		scanf("%lld", &a);
	}
	
	switch (c)
	{	
	case 1:add(a,b);break;
	case 2:subtract(a,b);break;
	case 3:multiply(a,b);break;
	case 4:division(a,b);break;
	case 5:modulo(a,b);break;
	case 6:square(a);break;
	case 7:root(a);break;
	case 8:log(a);break;
	case 9: return 0;
    }
}
	return 0;
}

