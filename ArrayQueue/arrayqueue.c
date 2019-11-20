#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayqueue.h"

ArrayQueue* createArrayQueue(int size) {
	ArrayQueue *pReturn = NULL;
	int i = 0;

	if (size > 0) {
		pReturn = (ArrayQueue*)malloc(sizeof(ArrayQueue));
		if (pReturn != NULL) {
			memset(pReturn, 0, sizeof(ArrayQueue));
			pReturn->maxCount = size;
			pReturn->front = -1;
			pReturn->rear = -1;
		}
		else
		{
			printf("pReturn �޸� �Ҵ� ����, createArrayQueue()\n");
			return NULL;
		}
	}
	else {
		printf("����, size�� 0���� Ŀ����\n");
		return NULL;
	}

	pReturn->pElement = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode)*size);
	if (pReturn->pElement != NULL) {
		memset(pReturn->pElement, 0, sizeof(ArrayQueueNode)*size);
	}
	else
	{
		printf("����, �޸� �Ҵ� 2nd createArrayQueue()\n");
		return	NULL;
	}
	return pReturn;
}

int EnqueueAQ(ArrayQueue* pQueue, ArrayQueueNode element) {
	int ret = FALSE;
	int i = 0;

	if (pQueue != NULL) {
		if (isArrayQueueFull(pQueue) == FALSE) {
			pQueue->rear++;
			//pQueue->rear = (pQueue->rear+1)%pQueue->maxCount;		//����ť�϶�
			pQueue->pElement[pQueue->rear] = element;
			pQueue->currentCount++;
			ret = TRUE;
		}
		else
		{
			printf("����, ť�� ����á���ϴ�, enqueueAQ()\n");
		}
	}
	return ret;
}

ArrayQueueNode *dequeueAQ(ArrayQueue* pQueue) {
	ArrayQueueNode *pReturn = NULL;
	if (pQueue != NULL) {
		if (pQueue->currentCount != 0) {
			pReturn = (ArrayQueueNode*)malloc(sizeof(ArrayQueueNode));
			if (pReturn != NULL) {
				pQueue->front++;
				//pQueue->front = (pQueue->front+1)%pQueue->maxCount;		//����ť�϶�
				pReturn->data = pQueue->pElement[pQueue->front].data;
				pQueue->currentCount--;
			}
			else
			{
				printf("����, �޸� �Ҵ�, dequeueAQ()\n");
			}
		}
		else
		{
			printf("����, ť�� ����ֽ��ϴ�, dequeue()\n");
		}
	}
	return pReturn;
}

ArrayQueueNode *peekAQ(ArrayQueue* pQueue) {
	ArrayQueueNode *pReturn = NULL;
	if (pQueue != NULL) {
		if (pQueue->currentCount != 0) {
			pReturn = &(pQueue->pElement[pQueue -> front + 1]);
		}
	}
	return pReturn;
}

void deleteArrayQueue(ArrayQueue* pQueue) {
	if (pQueue != NULL) {
		if (pQueue->pElement != NULL) {
			free(pQueue->pElement);
		}
		free(pQueue);
	}
}

int isArrayQueueFull(ArrayQueue* pQueue) {
	int ret = FALSE;
	if (pQueue != NULL) {
		if (pQueue->currentCount == pQueue->maxCount || pQueue->rear == pQueue->maxCount - 1) {
		//if (pQueue->currentCount == pQueue->maxCount)		//����ť�϶��� rear üũ�� ����
			ret = TRUE;
		}
	}
	return ret;
}