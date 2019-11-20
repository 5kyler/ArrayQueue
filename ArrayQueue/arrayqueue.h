#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

typedef struct ArrayQueueNodeType {
	char data;
}ArrayQueueNode;

typedef struct ArrayQueueType {
	int maxCount;
	int currentCount;
	int front;
	int rear;
	ArrayQueueNode *pElement;
}ArrayQueue;

ArrayQueue* createArrayQueue(int size);
int EnqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element);
ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue);
ArrayQueueNode *peekAQ(ArrayQueue* pQueue);
void deleteArrayQueue(ArrayQueue* pQueue);
int isArrayQueueFull(ArrayQueue* pQueue);


#endif // !_ARRAY_QUEUE_

#ifndef _COMMON_QUEUE_DEF_

#define TRUE		1
#define FALSE		0

#endif // !_COMMON_QUEUE_DEF_
