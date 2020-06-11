#include<stdio.h>
#include<stdlib.h>

//Data type to store profit and corresponding deadline.
struct data
{
        int profit;
        int deadline;
      
};
//function returning maximum possible profit.
int Job_sequence(struct data *X,int max)
{
	int profit[max];
	int i=0,j,max_profit=0;
	
	for(i=0;i<max;i++)
	{
		profit[i]=0;
	}

        for(i=0;i<max;i++)
        {
                for(j=((X+i)->deadline -1);j>=0;j--)
		{
			if(profit[j]==0)
			{
				profit[j]=(X+i)->profit;
				max_profit= max_profit+profit[j];
				break;
			}

		}
        }

	return max_profit;
}
//swap function to swap two structure.
void swap(struct data *A, struct data *B)
{
	struct data temp= *A;
	*A= *B;
	*B= temp;

}



int main()
{
        int i,j;   
	
      
	int max,n;
	
	printf("\nEnter the no. of data entry:");
	scanf("%d",&n);
	struct data A[n];
	printf("\nEnter profit and corresponding deadline:\n");
	//loop for taking input.
	for(i=0;i<n;i++){
		scanf("%d",&(A[i].profit));// dot operator used, As A[i] is not a pointer.
		scanf("%d",&(A[i].deadline));
		
	}
	printf("\nData for job sequence: ");
	// printing data as profit weight ratio format.
	for(i=0;i<n;i++)
	{
		printf("%d	",A[i].profit);
		printf("%d	",A[i].deadline);

	}
	//sorting with respect to ratio.
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((A[i].profit - A[j].profit)<0)
			{
			      
				swap(&A[i],&A[j]);
			}
			
		}
	}
	printf("\n Sorted data with respect to profit:");
	//loop for printing the sorted data.
        for(i=0;i<n;i++)
        {
                printf("%d      ",A[i].profit);
                printf("%d      ",A[i].deadline);

        }
	max=A[0].deadline;
        for(i=0;i<n;i++)
        {
		if(max < A[i].deadline)
		{
			max=A[i].deadline;
		}
        }
	//function call.
	int prof= Job_sequence(A,max);
	printf("\nMaximum possible profit:	 %d",prof);

}

