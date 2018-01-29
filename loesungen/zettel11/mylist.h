#ifndef MYLIST_H
#define MYLIST_H

#include <string>

class myList
{
private:

// Listenelement als Klasse definieren
    class myListElement
    {
    public:
        myListElement * prev;
        myListElement * next;
        double data;

        myListElement(double new_data) : prev(NULL), next(NULL), data(new_data){};
    };

    myListElement * head;
    myListElement * end;

public:

    myList()
    {
        head = end = NULL;
    };

    ~myList()
    {
        this->remove();
    };

    class Iterator
    {

    public:

        myListElement * it;


        Iterator() : it(NULL) {};
        Iterator(myListElement * it_element) : it(it_element){};


        void operator++()
        {
            if (it != NULL)
                it = it->next;
        }

        void operator--()
        {
            if (it != NULL)
                it = it->prev;
        }

        bool operator==(myListElement * ptr)
        {
            if ( NULL != it && it == ptr) return true;
            else return false;
        }

        bool operator!=(myListElement * ptr)
        {
            if ( NULL != it && it != ptr) return true;
            else return false;
        }

        std::string printValue()
        {
            return std::to_string(it->data);
        }

        double& operator*()
        {
            return it->data;
        }

    };



    void push_back(double new_data)
    {
        myListElement * new_list_element = new myListElement(new_data);

        if (this->isEmpty())
            end = head = new_list_element;
        
        else
        {
        //  Last Element's next element is new element
            end->next = new_list_element;

        //  new element's previous is former last element
            new_list_element -> prev = end;

        //  new element is new end
            end = new_list_element;
        }

    };

    void remove()
    {
        if(this->isEmpty())
            return;

        // While there are still elements (except head/end), delete list from back
        while(head->next != NULL)
        {
            //  take vorletztes Element
            myListElement *vorletztes_element = end->prev;

            // and delete it
            delete end;

            // and move on
            vorletztes_element->next = NULL;
            end = vorletztes_element;
        }

        // delete head
        delete head;
        head = NULL;
    };

    bool isEmpty()
    {
        return ((head == NULL)? true : false);
    };

    myListElement * first()
    {
        return this->head;
    }

    myListElement * last()
    {
        if (end == NULL) return NULL;
        else return this->end->next;
    }

};


#endif