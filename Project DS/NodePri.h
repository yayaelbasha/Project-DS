
#ifndef _NodePri
#define _NodePri

template < typename T>
class NodePri
{
private:
	T item; // A data item
	NodePri<T>* next; // Pointer to next NodePri
	int Priority;
public:
	NodePri();
	NodePri(const T& r_Item);
	NodePri(const T& r_Item, NodePri<T>* nextNodePriPtr);
	void setItem(const T& r_Item);
	void setNext(NodePri<T>* nextNodePriPtr);
	void setPriority(int Priority);
	T getItem() const;
	NodePri<T>* getNext() const;
	int getPriority();
}; // end NodePri
#endif

template < typename T>
NodePri<T>::NodePri()
{
	next = nullptr;
}

template < typename T>
NodePri<T>::NodePri(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
}

template < typename T>
NodePri<T>::NodePri(const T& r_Item, NodePri<T>* nextNodePriPtr)
{
	item = r_Item;
	next = nextNodePriPtr;
}
template < typename T>
void NodePri<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void NodePri<T>::setNext(NodePri<T>* nextNodePriPtr)
{
	next = nextNodePriPtr;
}

template < typename T>
T NodePri<T>::getItem() const
{
	return item;
}

template < typename T>
NodePri<T>* NodePri<T>::getNext() const
{
	return next;
}

template < typename T>
int NodePri<T>::getPriority()
{
	return Priority;
}

template < typename T>
void NodePri<T>::setPriority(int Priority)
{
	this->Priority = Priority;
}