#define MaxQueue 100

typedef char queue_type;
//typedef int queue_type;

typedef struct
{
	int front, rear, items_num;
	queue_type items [MaxQueue];
}	queue;

void create_queue (queue *);

int enqueue (queue_type, queue *);

int dequeue (queue *, queue_type *);

int queue_front (queue *, queue_type *);

int queue_is_empty (queue *);

int queue_is_full (queue *);

int size_of_queue (queue *);