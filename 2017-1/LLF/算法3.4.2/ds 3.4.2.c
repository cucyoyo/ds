#include<stdio.h>
#include<stdlib.h>
typedef int	QelemType;

typedef struct QNode
{
	QelemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针

}LinkQueue;

typedef enum
{
	OK,
	ERROR,
	OVERFLOW
}Status;

typedef enum
{
	true,
	false
}bool;

Status InitQueue(LinkQueue *Q)//构造一个空队列Q
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)exit(OVERFLOW); //存储分配失败
	Q->front->next = NULL;
	return OK;
}

Status DestroyQueue(LinkQueue *Q)//销毁队列Q
{
	while (Q->front)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue *Q)//将Q清为空队列
{
	QNode *p = Q->front;
	while (p != NULL)//依次删除队列中的每一个结点，最后使队首指针为空
	{
		Q->front = Q->front->next;
		free(p);
		p = Q->front;
	}
	Q->rear = NULL;
	return OK;
}

bool QueueEmpty(LinkQueue *Q)//判断队列是否为空
{
	if (Q->front == NULL)
	{
		return false;
	}
	else return true;
}

int QueueLength(LinkQueue *Q)//返回元素个数，即队列长度
{
	QueuePtr p;
	p = Q->front->next;
	int i = 1;
	while (p != Q->rear)

	{
		i++;
		p = p->next;
	}
	return i;

}

QelemType GetHead(LinkQueue *Q, QelemType *e)
//若队列不空，则用e返回Q的队头元素，并返回OK；否则返回ERROR
{
	if (Q->front == NULL)
	{
		exit(ERROR);
	}
	
	return  e=Q->front->data;
	
}

Status EnQueue(LinkQueue *Q, QelemType e)//插入元素e为Q的新的队尾元素
{
	QNode *p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);//存储分配失败
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q, QelemType *e)
//若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；
//否则返回ERROR
{
	QNode *p;
	if (Q->front == Q->rear)
	{
		return ERROR;
	}
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
	{
		Q->rear = Q->front;
	}
	free(p);
	return OK;
}

void QueueTraverse(LinkQueue *Q)
// 从队头到队尾依次对队列Q中每个元素调用函数visit() 
{
	Q->front = Q->front->next;
	while (visit(Q->front) == true)
	{
		Q->front = Q->front->next;
	}
	return OK;
}

bool  visit(QueuePtr p)
{
	if (p != NULL)
	{
		QelemType x = p->data;
		printf(" %d ", x);
		return true;
	}
	else return false;
}


void main()
{
	LinkQueue q;
	InitQueue(&q);
	QelemType a[] = { 1,2,3,4,5,6 };
	QelemType e;
	for (int i = 0; i < 6; i++)
	{
		EnQueue(&q, a[i]);
	}
	printf("\n队列的长度: %d\n", QueueLength(&q));
	
	printf("插入完成：");
	
	QueueTraverse(&q);

	printf("\n销毁队列\n");

	DestroyQueue(&q);
}
