#ifndef QUEUE_TYPE_H
#define QUEUE_TYPE_H

#include <iostream>
#include <cassert>
#include "queueADT.h"

using namespace std;

template <class Type>
class queueType : public queueADT<Type>
{
public:
	queueType(int queueSize = 100)
	{
		// implement constructor
		if (queueSize < 0)
		{
			queueSize = 100;
		}
		else
		{
			maxQueueSize = queueSize;
		}
		count = 0;
		queueRear = -1;
		queueFront = 0;
		list = new Type[queueSize];
	}

	~queueType()
	{
		// implement destructor
		delete[] list;
	}

	bool isEmptyQueue() const
	{
		return (count == 0);
	}

	bool isFullQueue() const
	{
		return (count == maxQueueSize);
	}

	int getSize() const
	{
		return count;
	}

	int getMaxCapacity() const
	{
		return maxQueueSize;
	}

	void initializeQueue()
	{
		// implement function
	}

	Type front() const
	{
		assert(!isEmptyQueue());
		return list[queueFront];
	}

	Type back() const
	{
		assert(!isEmptyQueue());
		return list[queueRear];
	}

	void enQueue(const Type &queueElement)
	{
		// implement function
		if (count == maxQueueSize)
		{
			cout << "Can not add to a full queue" << endl;
			return;
		}

		queueRear++;
		list[queueRear] = queueElement;
		count++;
		cout << "New client added. Queue now has " << count << " clients." << endl;
	}

	void deQueue()
	{
		// implement function
		if (count == 0)
		{
			cout << "Cannot remove from an empty queue" << endl;
			return;
		}

		if (queueFront == queueRear)
		{
			queueFront = 0;
			queueRear = -1;
			count = 0;
			cout << "Client removed from queue. Queue now has " << count << " clients." << endl;
		}
		else
		{
			queueFront = queueFront + 1;
			count--;
			cout << "Client removed from queue. Queue now has " << count << " clients." << endl;
		}
	}

private:
	int maxQueueSize; //variable to store the maximum queue size
	int count;		  //variable to store the number of
	int queueFront;	  //variable to point to the first
	int queueRear;	  //variable to point to the last
	Type *list;		  //pointer to the array that holds
};

#endif // !QUEUE_TYPE_H
