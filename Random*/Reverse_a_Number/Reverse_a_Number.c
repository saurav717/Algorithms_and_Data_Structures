#include<stdio.h>
int zeros=0;
int rev(int a)   // introducing a new function with name reverse which depends on the value of 'a'
{
	int temporary=a;     //introduced another variable 'temporary' which is equal to a 
	while(temporary%10==0&&a!=0)//made a loop when input is divisible by 10
	{
		zeros++;             // the count goes on increasing by 1 until a is made equal to zero
		temporary=temporary/10;//if input is a multiple of 10, it would decrease by a factor of 10 i.e   ( if input is 1000, output is 100) on zero decreases
	}                          // this loop continues repeating until the value is not divisible by 10
	int reverse=0;                  //this is a function to reverse the input number
	do                                 //this is done when the condition in while loop is satisfied
	{                                     
	reverse=reverse*10;                   // a variable reverse assigned value '0'  is made equal to its own multiplication with 10
	reverse=reverse + a%10;                 
	a=a/10;}while (a!=0);                 // this loop goes on repeating until 'a' is made equal to zero
	return reverse;                       //the value of reverse is returned to the main function
}

int main()
{
	int n,i;                                 
	printf("enter a number to reverse\n");
	scanf("%d", &n);                        // scans the input number
	
	int reverse=rev(n);    //the value of reverse is made equal to the output of rev function           
   	for(i=0;i<zeros;i++)      // made a loop until the number of zeros in the input which is a multiple of 10
	   printf("0");          //prints the value 0 before the number reverse until the value of 'a' is made zero in the above while loop
	printf("%d",reverse);    //the value of reversed number is produced
	
	return 0;
	
	
	
}




