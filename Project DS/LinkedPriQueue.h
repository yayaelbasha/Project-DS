#pragma once
#include "PriQueueADT.h"
class LinkedPriQueue : public PriQueueADT
{
    private:
        node* front;
    public:
        Priority_Queue()
        {
            front = NULL;
        }
      
        void insert(int item, int priority)
        {
            node* tmp, * q;
            tmp = new node;
            tmp->info = item;
            tmp->priority = priority;
            if (front == NULL || priority < front->priority)
            {
                tmp->link = front;
                front = tmp;
            }
            else
            {
                q = front;
                while (q->link != NULL && q->link->priority <= priority)
                    q = q->link;
                tmp->link = q->link;
                q->link = tmp;
            }
        }
        /*
         * Delete from Priority Queue
         */
        void del()
        {
            node* tmp;
            if (front == NULL)
                cout << "Queue Underflow\n";
            else
            {
                tmp = front;
                cout << "Deleted item is: " << tmp->info << endl;
                front = front->link;
                free(tmp);
            }
        }
        /*
         * Print Priority Queue
         */
        void display()
        {
            node* ptr;
            ptr = front;
            if (front == NULL)
                cout << "Queue is empty\n";
            else
            {
                cout << "Queue is :\n";
                cout << "Priority       Item\n";
                while (ptr != NULL)
                {
                    cout << ptr->priority << "                 " << ptr->info << endl;
                    ptr = ptr->link;
                }
            }
        }
    };
};

