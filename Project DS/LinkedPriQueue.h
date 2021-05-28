#pragma once

#include "PriQueueADT.h"
#include "NodePri.h"

template < typename T>
class LinkedPriQueue : public PriQueueADT<T>
{
	NodePri<T>* backPtr;
	NodePri<T>* frontPtr;
public:
	LinkedPriQueue();
	bool isEmpty() const;
	bool enqueue(const T& newEntry, int priority);
	bool dequeue(T& frntEntry);
	bool peek(T& frntEntry)  const;
	~LinkedPriQueue();

	//copy constructor
	LinkedPriQueue(const LinkedPriQueue<T>& LQ);
};
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: Queue()
The constructor of the Queue class.

*/

template <typename T>
LinkedPriQueue<T>::LinkedPriQueue()
{
	backPtr = nullptr;
	frontPtr = nullptr;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool LinkedPriQueue<T>::isEmpty() const
{
	return (frontPtr == nullptr);
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry at the back of this queue.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedPriQueue<T>::enqueue(const T& newEntry, int priority)
{
	NodePri<T>* tmp, * q;
	tmp = new NodePri<T>;
	tmp->setItem(newEntry);
	tmp->setPriority(priority);
	if (frontPtr == nullptr || priority < frontPtr->getPriority())
	{
		tmp->setNext(frontPtr);
		frontPtr = tmp;
	}
	else
	{
		q = frontPtr;
		while (q->getNext() != nullptr && q->getNext()->getPriority() <= priority)
			q = q->getNext();
		tmp->setNext(q->getNext());
		q->setNext(tmp);
	}
	return true;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes the front of this queue. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool LinkedPriQueue<T>::dequeue(T& frntEntry)
{
	if (isEmpty())
		return false;

	NodePri<T>* NodePriToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	if (NodePriToDeletePtr == backPtr)	 // Special case: last NodePri in the queue
		backPtr = nullptr;

	// Free memory reserved for the dequeued NodePri
	delete NodePriToDeletePtr;

	return true;

}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: peek
copies the front of this queue to the passed param. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
*/
template <typename T>
bool LinkedPriQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}
///////////////////////////////////////////////////////////////////////////////////
/*
Function: destructor
removes all NodePris from the queue by dequeuing them
*/
template <typename T>
LinkedPriQueue<T>::~LinkedPriQueue()
{
	T temp;

	//Free (Dequeue) all NodePris in the queue
	while (dequeue(temp));
}
/////////////////////////////////////////////////////////////////////////////////////////
/*
Function: Copy constructor
To avoid shallow copy,
copy constructor is provided

Input: LinkedPriQueue<T>: The Queue to be copied
Output: none
*/

template <typename T>
LinkedPriQueue<T>::LinkedPriQueue(const LinkedPriQueue<T>& LQ)
{
	NodePri<T>* NodePriPtr = LQ.frontPtr;
	if (!NodePriPtr) //LQ is empty
	{
		frontPtr = backPtr = nullptr;
		return;
	}

	//insert the first NodePri
	NodePri<T>* ptr = new NodePri<T>(NodePriPtr->getItem());
	frontPtr = backPtr = ptr;
	NodePriPtr = NodePriPtr->getNext();

	//insert remaining NodePris
	while (NodePriPtr)
	{
		NodePri<T>* ptr = new NodePri<T>(NodePriPtr->getItem());
		backPtr->setNext(ptr);
		backPtr = ptr;
		NodePriPtr = NodePriPtr->getNext();
	}
};

