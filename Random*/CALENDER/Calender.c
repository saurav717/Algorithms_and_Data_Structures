#include<stdio.h>
int isleapyear( int year)//function for leap year
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


int no_of_days(int d, int mm, int yy)
{
	
	int   dd=0, b, e,j,h,month;
	for(j=1;j<yy;j++)
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

	switch(mm)  // switches month depending on the input
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
	if(isleapyear(yy)==1&&mm>2)
	   h++;
	
	j = (d+ h + dd)%7;//total no. of days modulo 7
	return j;	
	
}
	
int printmonth(int m,int y)//a function for printing months
{
  int dd, maxdays,i,q;
   int p=no_of_days(1,m,y);
   switch(m)
  {
  	case 1:printf("\tjanuary\n");maxdays=31;break;//defining maximum nunber of days and the month name assosited with the month no.
  	case 2:printf("\tfebruary\n");maxdays=28;break;
  	case 3:printf("\tmarch\n");maxdays=31;break;
  	case 4:printf("\tapril\n");maxdays=30;break;
  	case 5:printf("\tmay\n");maxdays=31;break;
  	case 6:printf("\tjune\n");maxdays=30;break;
  	case 7:printf("\tjuly\n");maxdays=31;break;
  	case 8:printf("\taugust\n");maxdays=31;break;
  	case 9:printf("\tseptember\n");maxdays=30;break;
  	case 10:printf("\toctober\n");maxdays=31;break;
  	case 11:printf("\tnovember\n");maxdays=30;break;
  	case 12:printf("\tdecember\n");maxdays=31;break;
  } 
  printf("su  mo  tu  we  th  fr  sa\n");   //prints the days 
  switch(p)                                  //swutches the place of first day of the month
  {
  	case 1:printf("     1  ");break;  //adjusting spaces given the no. of day of the week //monday
    case 2:printf("         1  ");break;//tuesday
    case 3:printf("             1  ");break;//wednesday
	case 4:printf("                 1  ");break;//thursday
	case 5:printf("                     1  ");break;//friday
	case 6:printf("                         1  ");break;//saturday
	default:printf(" 1  ");break; 	//sunday
  }

  for(i=2;i<=maxdays;i++)   //loop in printing all the dates from 
  { 
          q = (no_of_days(i,m,y));//total no. of days mod 7 in that month from 1st to the maximum days of that month
        if(q==0)    //seventh day
      {
      	printf("\n");
      }
  
        if(i<=9)   //for adjusting spaces
      {
     	printf(" ");
      }
      
  	printf("%d  ", i);	
  }
  return i;
}

int month_days(int m_c,int y) //assigning the no. of days to each month
{
	if(m_c==1)               //january
       return 31;
    else if(m_c == 2)       //february
    {
        if(isleapyear(y))    //leap year case
            return 29;
        else                 //non leap year case
            return 28;
    }
    else if(m_c == 3)   //march
        return 31;
    else if(m_c == 4)  //april
        return 30;
    else if(m_c == 5)//may
        return 31;
    else if(m_c == 6)//june
        return 30;
    else if(m_c == 7)//july
        return 31;
    else if(m_c == 8)//august
        return 31;
    else if(m_c == 9)//september
        return 30;
    else if(m_c == 10)//october
        return 31;
    else if(m_c == 11)//november
        return 30;
    else //december
        return 31;

}
int min(int x,int y)
{
	return x < y ? x : y;//if x<y returns x and if not returns y
}
int printyear(int year)//year function
{  
	int spaces_before=(no_of_days(1,1,year)),spaces_after;//defining the spaces for each number to be printed
	int m_c=1,i=1,j=1,k=1,space_i; 
	while(m_c <=12)
	{	

		printf("                                 %d\n",year);
		if(m_c == 1)	
			printf("        January                February               March      \n");//prints three months at a time 
		else if(m_c == 4)
			printf("        April                  May                    June       \n");
		else if(m_c == 7)
			printf("        July                   August                 September  \n");
		else if(m_c == 10)
			printf("        October                November               December   \n");
		printf("Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa  Su Mo Tu We Th Fr Sa \n"); //prints the days for each months with adjusted spaces 

		while(i <= month_days(m_c,year) || j <= month_days(m_c+1,year) || k <= month_days(m_c+2,year))
		{
			for(space_i = 0 ; i==1  && space_i < spaces_before ; space_i++ ) printf("   "); 
			int week_end_i,week_end_j ,week_end_k;
			if(i==1)
			{
				week_end_i = (7-spaces_before %7);
				spaces_before = (spaces_before + month_days(m_c,year))%7;
			} 
			else week_end_i = i +6;

			for( ; i<= min(week_end_i,month_days(m_c,year));i++) 
			{
				printf("%d",i);
				if(i < 10) printf("  ");
				else printf(" ");
			}

			for(spaces_after = 0; i== month_days(m_c,year)+1 && spaces_after <= (week_end_i - i); spaces_after ++) printf("   ");

			for(space_i = 0 ; j==1  && space_i < spaces_before ; space_i++ ) printf("   ");
			
			printf(" ");
				
			if(j==1)
			{
				week_end_j = (7-spaces_before %7);
				spaces_before = (spaces_before + month_days(m_c+1,year))%7;
			}
			else week_end_j = j +6;
			
			for( ; j<= min(week_end_j ,month_days(m_c+1,year));j++) 
			{
				printf("%d",j);
				if(j < 10) printf("  ");
				else printf(" ");
			}

			for(spaces_after = 0;j== month_days(m_c+1,year) +1 && spaces_after <= (week_end_j - j); spaces_after ++) printf("   ");

			printf(" ");

			for(space_i = 0 ; k==1  && space_i < spaces_before ; space_i++ ) printf("   ");
			if(k==1)
			{
				week_end_k =(7-spaces_before %7);
				spaces_before = (spaces_before + month_days(m_c+2,year))%7;
			}
			else week_end_k = k+6;
			for( ; k<= min(week_end_k,month_days(m_c+2,year));k++) 
			{
				printf("%d",k);
				if(k < 10) printf("  ");
				else printf(" ");
			}
			for(spaces_after = 0; k== month_days(m_c+2,year)+1 && spaces_after <= (week_end_k - k); spaces_after ++) printf("   ");
			printf("\n");
		}
		m_c+=3;
		i=1;
		j=1;
		k=1;

		printf("\n \n ");
	}
	printf("\n");
	
	
	
		
}
int main()
{
	int a, year, month,lastch = -1,lastyear = -1,lastmonth = -1;
	
	while(1)//infinite looping
	{
		printf("menu\n");
		printf("1:display year\n");
		printf("2:display month\n");
		printf("3:move right\n");
		printf("4:move left\n");
		printf("5:exit\n");
		
		printf("enter your choice\n");
		scanf("%d", &a);// scanning choice
		if(a==1)// if a=1 the loop goes to year function
		{
			printf("enter year\n");
			scanf("%d", &year);	
			
			printyear(year);	
		}
		
		else if(a==2)       //if satisfies, month function will be executed
		{
			printf("enter year\n");
			scanf("%d", &year);	
			
			printf("enter month\n");
			scanf("%d", &month);
		    
		    printmonth(month,year);
		    
		
		}
		else if(a == 3) 
		{
			if(lastch == -1)//check whether 1 or 2 option of the menu have been used before
			{
				printf("No previous commands exist \n");
			}
			else
			{
				if(lastch == 1)
				{
					printyear(lastyear+1);
					lastyear = lastyear +1;
				}
				else
				{
					if(lastmonth != 12)
					{
				 		printmonth(lastmonth +1,lastyear);
						lastmonth = lastmonth +1;
					}
					else
					{
						printmonth(1,lastyear+1);
						lastmonth = 1;
						lastyear = lastyear +1;
					}
				}
			}
		}
		else if(a == 4)
		{
			if(lastch == -1)
			{
				printf("No previous commands exist \n");
			}
			else
			{
				if(lastch == 1)
				{
					printyear(lastyear-1);
					lastyear = lastyear - 1;
				}
				else 
				{
					if(lastmonth != 1)//move left command for month
					{
						printmonth(lastmonth -1,lastyear);
						lastmonth = lastmonth -1;
					}
					else//move left command for year
					{
						printmonth(12,lastyear -1);
						lastmonth =12;
						lastyear = lastyear -1 ;
					}

				}
			}
		}
		else if(a == 5)
			return 0;
		else
		{
			printf("Enter a valid case\n");
			continue;
		}
		if(a == 1 || a == 2)
		{
			lastch =a;
			lastmonth=month;
			lastyear=year;	
		}
	}
	
	
return 0;		
}

	
	
	
	
	
	
	
	
	
	





