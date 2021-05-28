#pragma once

template<class ItemType>
class PriQueueADT
{
public:

    virtual bool isEmpty() const = 0;

    virtual bool enqueue(const ItemType& newEntry, int priority) = 0;

    virtual bool dequeue(ItemType& FrontEntry) = 0;

    virtual bool peek(ItemType& FrontEntry) const = 0;

    virtual ~PriQueueADT() { }
}; 

