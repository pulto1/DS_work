#define _CRT_SECURE_NO_WARNINGS

//设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。
//
//循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。
//
//你的实现应该支持如下操作：
//
//MyCircularQueue(k) : 构造器，设置队列长度为 k 。
//Front : 从队首获取元素。如果队列为空，返回 - 1 。
//	Rear : 获取队尾元素。如果队列为空，返回 - 1 。
//		   enQueue(value) : 向循环队列插入一个元素。如果成功插入则返回真。
//		   deQueue() : 从循环队列中删除一个元素。如果成功删除则返回真。
//		   isEmpty() : 检查循环队列是否为空。
//		   isFull() : 检查循环队列是否已满。

typedef struct
{
	int* _a;
	int _front;
	int _rear;
	int _k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
	MyCircularQueue* q = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	q->_a = (int*)malloc(sizeof(int)* (k + 1));
	q->_front = 0;
	q->_rear = 0;
	q->_k = k;

	return q;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
	if (myCircularQueueIsFull(obj))
		return false;

	obj->_a[obj->_rear] = value;
	obj->_rear++;
	obj->_rear %= (obj->_k + 1);

	return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return false;

	obj->_front++;
	obj->_front %= (obj->_k + 1);

	return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;

	return obj->_a[obj->_front];
}

int myCircularQueueRear(MyCircularQueue* obj)
{
	if (myCircularQueueIsEmpty(obj))
		return -1;

	int tail = obj->_rear - 1;

	if (tail == -1)
		tail = obj->_k;

	return obj->_a[tail];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
	return obj->_front == obj->_rear;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
	return (obj->_rear + 1) % (obj->_k + 1) == obj->_front;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
	free(obj->_a);
	free(obj);
}