#include<stdio.h>
#include<string.h>


void addition()
{
	int k,i,h,l,j,x,m,tmp, c;
	char fn[1001], sn[1001], copy[1001], n1[1001];
	int ans[1002], ans2[1002],ans3[1002], temp1[1001], temp2[1002];
	int left_shift = 0;	
	int l1,l2;
		 
	printf("enter first number\n");
	scanf(" %s", fn);
	printf("enter second number\n");
	scanf(" %s", sn);
	
	
	l1=strlen(fn);//string length
	l2=strlen(sn);
	
	if(l1>l2)                      // to make the lengths r two numbers equal
	{
			for(i=0;i<l2;i++)
				copy[i] = sn[i];
    		for(i=0;i<(l1-l2);i++)//keeping zeros before the given number
				sn[i]=48;
			for(i=(l1-l2);i<l1;i++)
				sn[i] = copy[i-(l1-l2)];//assigning the numbers in second number after the zeros 
	}		
	
	else if(l2>l1)           // similar case like that of (l1>l2)
	{
			for(i=0;i<l1;i++)
				copy[i] = fn[i];
    		for(i=0;i<(l2-l1);i++)
				fn[i]=48;
			for(i=(l2-l1);i<l2;i++)
				fn[i] = copy[i-(l2-l1)];
		l1 = l2;
	}		
	for( i=0;i<l1;i++)
	{
		fn[i]=fn[i]-48;// removing the ASCII value for all the digits in first number
		
	}
	for(j=0;j<l1;j++)
	{
		sn[j]=sn[j]-48;//removing ASCII value
	
	}
	
	int carry=0;
	for(i=l1-1;i>=0;i--)
	{
		
		l=fn[i]+sn[i]+carry;//sum
		carry = l/10;       //carry
		ans[i] = l%10;      // answer 
		
		if((i==0)&&(carry!=0))
			printf("%d",carry);}//printing carry after printing all the values 	
   	
   for(i=0;i<l1;i++)
	{
		printf("%d", ans[i]);//printing the answer
	}
	printf("\n");
}

void subtraction()
{
	int k,i,h,l,j,x,m,tmp, c;
	char fn[1001], sn[1001], copy[1001], n1[1001];
	int ans[1002], ans2[1002],ans3[1002], temp1[1001], temp2[1002];
	int left_shift = 0;	
	int l1,l2;
	
	printf("enter first number\n");
	scanf(" %s", fn);
	printf("enter second number\n");
	scanf(" %s", sn);
	

	l1=strlen(fn);//string length
	l2=strlen(sn);
	
	if(l1>l2)                      // to make the lengths r two numbers equal
	{
			for(i=0;i<l2;i++)
				copy[i] = sn[i];
    		for(i=0;i<(l1-l2);i++)//keeping zeros before the given number
				sn[i]=48;
			for(i=(l1-l2);i<l1;i++)
				sn[i] = copy[i-(l1-l2)];//assigning the numbers in second number after the zeros 
	}		
	
	else if(l2>l1)           // similar case like that of (l1>l2)
	{
			for(i=0;i<l1;i++)
				copy[i] = fn[i];
    		for(i=0;i<(l2-l1);i++)
				fn[i]=48;
			for(i=(l2-l1);i<l2;i++)
				fn[i] = copy[i-(l2-l1)];
		l1 = l2;
	}		
	for( i=0;i<l1;i++)
	{
		fn[i]=fn[i]-48;// removing the ASCII value for all the digits in first number
		
	}
	for(j=0;j<l1;j++)
	{
		sn[j]=sn[j]-48;//removing ASCII value
	
	}//
	
		x=-1;             //initially
	
	for(i=0;i<l1;i++) //loop until the length of first number 
	{
		if(fn[i]>sn[i]) //if first number greater than second
		{
			x=1;
			break;
		}
		
		else if(fn[i]<sn[i]) //if second number greater than the first number
		{ 
		  
		    x=0;
			break;	
		
        }
    }
if(x==-1)       //if both are equal
	printf("0\n");
else
{
				
if(x==1) //case for first number greater than second number
	{

	 for(i = l1-1; i>=0; i--)//loop from the units digit to first digit
        {
           j = fn[i]-sn[i]; //subtraction
          	if(j<0)         //happens if first number < second number
          	{
          		j = j + 10;       //adding 10 for subtraction < 0
          		fn[i-1]=fn[i-1]-1;//and subtracting 1 fron its previous digit
          		                  // all this kept in a loop 
			}
			ans2[i]=j;  //printing the answer
          		
		}
    }
else if(x==0)                    //case for second number > first number
    {
        for(i= l1-1; i>=0; i--)  //loop from the units digit to first digit of first number
        {
           j = sn[i]-fn[i];      //second number - first number
          	if(j<0)
          	{
          		j = j + 10;          // adding 10 if the subtraction < 0
          		sn[i-1]=sn[i-1]-1;   // and subtracting 1 from all its LHS digits
          		
			}
			ans2[i]=j;               //answer
          		
		}
    printf("-");                   	//printing - in front of the answer
	}

for(i=0;i<l1;i++)	
	printf("%d",ans2[i]);           //printing the answer
printf("\n");                       //giving space after it
}

	
}

void multiplication()
{
	int k,i,h,l,j,x,m,tmp, c;
	char fn[1001], sn[1001], copy[1001], n1[1001];
	int ans[1002], ans2[1002],ans3[1002]={0}, temp1[1001], temp2[1002];
	int left_shift = 0;	
	int l1,l2;
	
		
	printf("enter first number\n");
	scanf(" %s", fn);
	printf("enter second number\n");
	scanf(" %s", sn);
	
	
	
	l1=strlen(fn);//string length
	l2=strlen(sn);
	
		for( i=0;i<l1;i++)
	{
		fn[i]=fn[i]-48;// removing the ASCII value for all the digits in first number
		
	}
	for(j=0;j<l1;j++)
	{
		sn[j]=sn[j]-48;//removing ASCII value
	
	}
	
		
	if(l1>l2)                      // to make the lengths r two numbers equal
	{
			for(i=0;i<l2;i++)
				copy[i] = sn[i];
    		for(i=0;i<(l1-l2);i++)//keeping zeros before the given number
				sn[i]=48;
			for(i=(l1-l2);i<l1;i++)
				sn[i] = copy[i-(l1-l2)];//assigning the numbers in second number after the zeros 
	}		
	
	else if(l2>l1)           // similar case like that of (l1>l2)
	{
			for(i=0;i<l1;i++)
				copy[i] = fn[i];
    		for(i=0;i<(l2-l1);i++)
				fn[i]=48;
			for(i=(l2-l1);i<l2;i++)
				fn[i] = copy[i-(l2-l1)];
		l1 = l2;
	}		
	
		//multiplication
for(i = l1-1,j=0;i>=0;i--,j++)
    {
        temp1[j] = fn[i];         //another array which is equal to the first number array
    }
    for(i = l2-1,j=0;i>=0;i--,j++)
    {
        temp2[j] = sn[i];         //another array which is equal to the second number array
    }
    
 for(i = 0;i < l2;i++)            //loop from 0 to the size of the second number
    {
        for(j = 0;j < l1;j++)     //another loop from 0 to the size of the first number
        {
            ans3[i+j] += temp2[i]*temp1[j]; //the digit in second number is multiplied with each digit of the first number
        }
    }
    for(i = 0;i < l1+l2;i++)
    {
        tmp = ans3[i]/10;        //a dummy variable tmp for CARRY
        ans3[i] = ans3[i]%10;    //the answer
        ans3[i+1] = ans3[i+1] + tmp; //answer of the next digit's sum
    }
    for(i = l1+l2; i>= 0;i--)
    {
        if(ans3[i] > 0)
            break;
    }
    printf("Product : ");
    for(;i >= 0;i--)
    {
        printf("%d",ans3[i]);//printing the answer
        
    }
}

void division()
{
	printf("division not availiable\n");
}

int main()
{ 
int c;
while(c!=5)
{
	
	 printf("\nenter your option\n");
	 printf("1 - add\n");
	 printf("2 - subtract\n");
	 printf("3 - multiply\n");
	 printf("4 - divide\n");
	 printf("5 - exit\n");
	 scanf("%d", &c);
	 
	  switch(c)
	  {
	  	case 1:addition();break;
	  	case 2:subtraction();break;
	  	case 3:multiplication();break;
	  	case 4:division(); break;
	  	case 5:return 0;
	  	default:printf("choose valid operation\n");
	  }

}
}
