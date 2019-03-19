#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void QS_random(int*,int ,int );
void QS_Last(int*,int ,int );
void QS_med3(int*,int ,int );
     
int main()
{

    clock_t start, end, start1, end1, start2, end2; //clock_t is a data type for clock functions
    float timex, timex1, timex2;
    time_t t;
    int i,j,n,m,*arr;
    srand((unsigned) time(&t));
    float arr1[20],arrt[20], arr2[20], arrt1[20], arr3[20], avg1[5], avg2[5], avg3[5];
for(int f = 1; f<=5 ; f++)
{
  for(int p =0; p<20;p++)
  {
    arrt[0]==0;
    n = 50*f;
    printf("n  = %d\n", n);
    arr=(int*)malloc(sizeof(int)*n);
    
    for(i=0;i<n;i++)
    {
                    int random1 = rand()%500;
                    arr[i] = random1;
    }

    start = clock();       // clock () function starts the timer and its like a checkpoint 
    QS_random(arr,0,n-1); // we calculate the time based on these checkpoints
    end = clock();

     printf("random element as pivot\n");
     printf("sorted array %d\n", p+1);
     for(i=0;i<n;i++)
     {
                     printf("%d\t",arr[i]);
     }

     printf("\n\n");


    start1 = clock();
    QS_Last(arr,0,n-1);
    end1 = clock();
   
     printf("last element as pivot\n");
     printf("sorted array %d\n", p+1);
     for(i=0;i<n;i++)
     {
                     printf("%d\t",arr[i]);
     }

     printf("\n\n");


    start2 = clock();
    QS_med3(arr, 0, n-1);
    end2 = clock();

     printf("median of first middle and last elements as pivot\n");
     printf("sorted array %d\n", p+1);
     for(i=0;i<n;i++)
     {
                     printf("%d\t",arr[i]);
     }
     
     printf("\n\n");

     timex = (float)(end - start)/CLOCKS_PER_SEC;
     timex1 = (float)(end1-start1)/CLOCKS_PER_SEC;
     timex2 = (float)(end2-start2)/CLOCKS_PER_SEC;


     arr1[p]=timex;
     arr2[p]=timex1;
     arr3[p]=timex2;
     printf("\n\n\n\n");
  }

  float avgt=0, avgt1=0, avgt2=0;

  for(int p =0 ; p <20; p++)
  {
    avgt+=arr1[p];
    avgt1+=arr2[p];
    avgt2+=arr3[p];
  }

  avgt = (avgt)/20;
  avgt1 = (avgt1)/20;
  avgt2 = (avgt2)/20;

  avg1[f] = avgt;
  avg2[f] = avgt1;
  avg3[f] = avgt2;

  printf("time taken table with array size = %d\n", n);
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("         random number as pivot       |           last number as pivot       |             median as pivot          |\n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("| trial no.|         time taken       || trial no.|         time taken       || trial no.|         time taken       |\n");
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    for(int p = 0 ;p < 20; p++)
    {
     
      if(p==19)
      {
        printf("|    %d    |          %f        ||    %d    |          %f        ||    %d    |          %f        |\n", p+1, arr1[p], p+1, arr2[p], p+1, arr3[p]);
      }

      if(p<19)
      {
        if((p>=9)&&(p<19))
        {
          printf("|    %d    |          %f        ||    %d    |          %f        ||    %d    |          %f        |\n", p+1, arr1[p], p+1, arr2[p], p+1, arr3[p]);
        }
      }

      if(p<9)
      {
         printf("|    %d     |          %f        ||    %d     |          %f        ||    %d     |          %f        |\n", p+1, arr1[p], p+1, arr2[p], p+1, arr3[p]); 
      }
    }
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    printf("| avg time |          %f        || avg time |          %f        || avg time |          %f        |\n", avgt, avgt1, avgt2);
    printf("---------------------------------------------------------------------------------------------------------------------\n");
}
 printf("---------------------------------------------------------------------------------------------------------------------\n");
 printf("\n\n");

printf("----------------------------------------------------------------------------------------------\n");
printf("|           |                              average time taken                                |\n");
printf("|  n value  |--------------------------------------------------------------------------------\n");
printf("|           |   random no. as pivot    |    last no. as pivot     |    median no. as pivot   |\n");
printf("|-----------|---------------------------------------------------------------------------------\n");
 for(int p = 1 ;p < 6; p++)
    {
      if(p==1)
      {
        printf("|    %d     |          %f        |          %f        |          %f        |\n",50*p ,avg1[p], avg2[p], avg3[p] );
      }

      if(p>1)
      {
      printf("|    %d    |          %f        |          %f        |          %f        |\n",50*p ,avg1[p], avg2[p], avg3[p] );
      }
    }
printf("----------------------------------------------------------------------------------------------\n");

}
    
void QS_random(int arr[],int start,int last)
{
     int i=start-1,j=start,temp;

     if(j>=last)
     {return;}

    if((j<last)||((j<=last)&&(i==j-1)))
    {

      int random = rand() % (last + 1 - start) + start;
       
       int temp;
       temp = arr[random];
       arr[random] = arr[last];
       arr[last] = temp;
    }

     while((j<last)||((j<=last)&&(i==j-1)))
     {
             
              if(arr[j]>arr[last])
              {
                               j++;                
              }

               if(arr[j]<=arr[last])
              {
                               i++;
              }

              if((arr[j]<=arr[last]))
              {
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
              }

              if(i==j)
              {
                j++;
              }
             
      }

      QS_random(arr,start,i-1);
      QS_random(arr,i+1,last);      
}

void QS_Last(int arr[],int start,int last)
{
 // printf("function is being called \n");
     int i=start-1,j=start,temp;
     if(j>=last)
     {return;}
     while((j<last)||((j<=last)&&(i==j-1)))
     {
             
              if(arr[j]>arr[last])
              {
                               j++;                
              }

               if(arr[j]<=arr[last])
              {
                               i++;
              }

              if((arr[j]<=arr[last]))
              {
                      temp=arr[i];
                      arr[i]=arr[j];
                      arr[j]=temp;
              }

              if(i==j)
              {
                j++;
              }
             
      }
      QS_Last(arr,start,i-1);
      QS_Last(arr,i+1,last);     
}

void QS_med3(int arr[],int start,int last)
{
  int i=start-1,j=start,temp, median, arrtemp[3];

    arrtemp[0] = arr[start];
    arrtemp[1] = arr[(start+last)/2];
    arrtemp[2] = arr[last];


  for(int i = 0; i <=2; i++)
  {
      for(int i = 0; i<2; i++)
      {
         if(arrtemp[i]>arrtemp[i+1])
         {
            int temp;
            temp     = arrtemp[i];
            arrtemp[i]   = arrtemp[i+1];
            arrtemp[i+1] = temp;
         }
      }
  }


    if(arrtemp[1] == arr[0])
    {
      int temp;
      temp = arr[last];
      arr[last] = arr[0];
      arr[0] = temp;
    }
      
    if(arrtemp[1] == arr[(start+last)/2])
    {
      int temp;
      temp = arr[last];
      arr[last] = arr[(start+last)/2];
      arr[(start+last)/2] = temp;
    }

    if(arrtemp[1] == arr[last])
    {
      int temp;
      temp = arr[last];
      arr[last] = arr[last];
      arr[last] = temp;
    }


     if(j>=last)
     {return;}
      
     while((j<last)||((j<=last)&&(i==j-1)))
     {
             
              if(arr[j]>arr[last])
              {
                               j++;                
              }

               if(arr[j]<=arr[last])
              {
                               i++;
              }

              if((arr[j]<=arr[last]))
              {
               temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
              }

              if(i==j)
              {
                j++;
              }
             
      }

      QS_med3(arr,start,i-1);
      QS_med3(arr,i+1,last);
}
     