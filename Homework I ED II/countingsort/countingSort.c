#include<stdio.h>
#include <time.h>
 
void counting_sort(int a[],int n,int max)
{
     int count[180000]={0},i,j; // count number of elements must be the same as number range in rand()% at main function
    
     for(i=0;i<n;++i)
      count[a[i]]=count[a[i]]+1;
      
     printf("\nSorted elements are:");
    
     for(i=0;i<=max;++i)
      for(j=1;j<=count[i];++j)
       printf("%d ",i);
}
 
int main()
{
    int n,i,max=0,hold;
    
    printf("Enter number of elements: ");
    scanf("%d",&n);
    
    int vector[n], vectorCopy[n]; 
    
    srand(time(NULL));
	for (i = 0; i < n; i++)
	{
	    hold = rand()%180000;
	    vector[i] = hold;
	    vectorCopy[i] = hold;
	    if(vector[i]>max){
      		max=vector[i];
      	} // if 
	} // for
    
    /*
    printf("\nSorted Array: "); //Printing the sorted Array
	for(i=0;i<n;i++)
	printf("%d ",vector[i]);
	*/
	
    counting_sort(vector,n,max);
    return 0;
}
