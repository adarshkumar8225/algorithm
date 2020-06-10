/* In Knapsack algorithm we have to full the bag with some capacity in such a way that 
profit becomes maximum.
Algorithm:-
first take the ratio of profit/ weight and sort them in order of ratio.
then take one with maximum ratio first
*/



#include<stdio.h>
#include<stdlib.h>

//Data type to store profit corresponding weight and ratio of profit :weight.
struct data
{
        int profit;
        int weight;
        float ratio;
};
//function returning maximum possible profit.
float knapsack(struct data *X,int cap)
{
	float prof=0.0;
	int i=0;
	
	while(cap)
	{
		if(cap < (X+i)->weight)
		{
			
			prof=prof+(X+i)->ratio * cap;
			cap=0;
			break;
		}
		else{
			cap=cap-(X+i)->weight;
			prof= prof +(X+i)->profit;
			i++;
		}
       
	}
	return prof;
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
	
      
	int cap,n;
	
	printf("\nEnter the no. of data entry:");
	scanf("%d",&n);
	struct data A[n];
	printf("\nEnter the capacity of bag:");
	scanf("%d",&cap);
	//loop for taking input.
	for(i=0;i<n;i++){
		scanf("%d",&(A[i].profit));// dot operator used, As A[i] is not a pointer.
		scanf("%d",&(A[i].weight));
		A[i].ratio=(float)(A[i].profit)/(A[i].weight);//float used to give exact decimal value after decimal.
	}
	printf("\nData for knapsack: ");
	// printing data as profit weight ratio format.
	for(i=0;i<n;i++)
	{
		printf("%d	",A[i].profit);
		printf("%d	",A[i].weight);
		printf("%.2f      ",A[i].ratio);

	}
	//sorting with respect to ratio.
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((A[i].ratio - A[j].ratio)<0)
			{
			      
				swap(&A[i],&A[j]);
			}
			
		}
	}
	printf("\n Sorted knapsack Data:");
	//loop for printing the sorted data.
        for(i=0;i<n;i++)
        {
                printf("%d      ",A[i].profit);
                printf("%d      ",A[i].weight);
                printf("%.2f      ",A[i].ratio);

        }
	//function call.
	float prof= knapsack(A,cap);
	//without function call it can also be done
/*	float prof=0.0;
	i=0;
        while(cap)
	{
		if(cap<A[i].weight)
		{
			prof=prof+A[i].ratio * cap;
			i++;
			cap=0;
			break;
		}
		else
		{
			cap=cap-A[i].weight;
			prof= prof+A[i].profit;
			i++;
		}
	}*/
	printf("\nMaximum possible profit: %.2f",prof);

}
