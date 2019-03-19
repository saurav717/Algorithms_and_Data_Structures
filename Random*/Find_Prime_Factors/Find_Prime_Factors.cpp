#include<stdio.h>

int primefactor(int t,int n)
{
	int flag=0,i;
	if(n%t==0)  // this executes if the input is divisible by t which is from the loop in main function
		{
			for(i=2;i<t;i++)   //this is for all the values between 1 and the factor 
			{
				if(t%i==0)     // if there is a number in between 1 and the factor which can divide the factor
				{
					flag=1;     // if the above condition is satisfied the variable flag is assigned value 1
					break;
				}		
			}
			if(flag==0)      //if there is no number that divides the factor between 1 and itself, then flag is made equal to zero and it returns the value 0 to main function
			  return 0;					  
		}
	return 1;	// if the flag value is 1, then it returns the value 1 to main function	
}
int main()
{
	int n,t,flag=0;
	
	printf("enter the number\n");
	scanf("%d", &n);                           // scans the number
	printf("the prime factors are\n");
	for(t=2;t<=n;t++)
	{
		if(primefactor(t,n)==0) //if the returned value is 0 then it prints the factor
		printf(" %d",t);		//prints the value of t
	}
}
	
