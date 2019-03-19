#include<stdio.h>
int isleapyear( int year)
{
	if(year%400==0)
	   return 1;//1 means leap year
	if(year%100==0)
	   return 0;//0 means not leap year
	if(year%4==0)
	   return 1;
	else 
	   return 0;          
}
int main()
{
	int date, month, year, dd=0, h, j;  // 'h' is number of days till the previous month ,   'j' is another variable and the returned value from the above function
	printf("enter date\n");
	scanf("%d", &date);//scans date
	printf("enter month\n");
	scanf("%d", &month);//scans month
	printf("enter year\n");
	scanf("%d", &year);// scans year
	for(j=1;j<year;j++)
	{
		if(isleapyear(j)==0)// case for leap year
		{
			dd=dd+365;       // if the returned value is 1, then this executes until it returns 0 again
		}
		else// case for non leap year
		{
			dd=dd+366;      // if returned value 0, then this executes until it returns 1 again
		}			
	}
	switch(month)  // switches month depending on the input
	{
		case 1: h=0;break;//no. of days untill previous month
		case 2: h=31;break;//no. of days until previous month 
		case 3: h=59;break;
		case 4: h=90;break;
		case 5: h=120;break;
		case 6: h=151;break;
		case 7: h=181;break;
		case 8: h=212;break;
		case 9: h=243;break;
		case 10: h=273;break;
		case 11: h=304;break;
		case 12: h=334;break;
	}
	if(isleapyear(year)==1&&month>2)
	   h++;
	j = (date + h + dd)%7;//total no. of days modulo 7
	switch(j) // switches the value of j which is modulo 7
	{
		case 1: printf("monday");break;
		case 2: printf("tuesday");break;
		case 3: printf("wednesday");break;
		case 4: printf("thursday");break;
		case 5: printf("friday"); break;
		case 6: printf("saturday");break;
		case 0: printf("sunday");break;
	}
return 0;
}
