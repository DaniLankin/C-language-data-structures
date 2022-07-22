#include <stdio.h>
#include "Queue_arr.h"

/*
	Question 1:
	Make sure to change queue_type to int
*/

void print_queue(queue *pq)
{
	int i, temp;
	int size = size_of_queue(pq);

	for (i=0;i<size;i++)
	{
		dequeue(pq,&temp);
		printf("%d ",temp);
		enqueue(temp,pq);
	}
	printf("\n");
}

int minCommon(queue *pq1, queue *pq2)
{
	int min = -1;
	int current1, current2;
	int size1 = size_of_queue(pq1);
	int size2 = size_of_queue(pq2);

	//if one of the queues is empty, there won't be a common minimum number
	if ((size1 == 0) || (size2 == 0))
		return min;
	
	do
	{
		//we check the front of each queue, and by that decide from which queue to dequeue 
		queue_front(pq1,&current1);
		queue_front(pq2,&current2);

		if (current1 == current2)
		{
			min = current1;
			break;
		}
		else if (current1 < current2)
		{
			dequeue(pq1,&current1);
			enqueue(current1,pq1);		
			size1--;
		}
		else
		{
			dequeue(pq2,&current2);
			enqueue(current2,pq2);			
			size2--;
		}
	}while ((size1 > 0) && (size2 > 0));

	//finish cycle of queue1
	while (size1-- > 0)
	{
		dequeue(pq1,&current1);
		enqueue(current1,pq1);
	}

	//finish cycle of queue2
	while (size2-- > 0)
	{
		dequeue(pq2,&current2);
		enqueue(current2,pq2);
	}

	return min;
}


void main()
{
	int i;
	queue q1, q2;
	int tempArr1[6] = {3,7,13,20,47,70};
	int tempArr2[5] = {12,20,65,70,75};

	create_queue(&q1);
	create_queue(&q2);

	for (i=0;i<6;i++)
		enqueue(tempArr1[i],&q1);
	
	for (i=0;i<5;i++)
		enqueue(tempArr2[i],&q2);

	printf("The minimum common value is: %d\n",minCommon(&q1,&q2));
	
	printf("Queue1: ");
	print_queue(&q1);

	printf("Queue2: ");
	print_queue(&q2);

}