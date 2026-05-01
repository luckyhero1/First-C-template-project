#include "DoublyLinkedList.h"

// Push- and pull-functions
template<typename T>
void DL_List<T>::push_front(T const& val)
{
    Node* tmp = head;
    head = new Node{val, tmp, nullptr};
    tmp->before = &head;
}

template<typename T>
void DL_List<T>::pop_front()
{
    Node* temp = head->next;
    delete head;
    head = temp;
    head->before = nullptr;
}

template<typename T>
void DL_List<T>::push_back(T const& val)
{
    Node* tmp = tail;
    tail = new Node{val, nullptr, tmp};
    tmp->next = &tail;
}

template<typename T>
void DL_List<T>::pop_back()
{
    Node* temp = tail->before;
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

template<typename T>
void DL_List<T>::push_at_position(unsigned int position, T const& val)
{
    Node* node = head;
    
    for(int i = 0; i = position; i += 1)
    {
        node = head->next;
    }
    
    Node* predecessor = node->before;
    Node* successor = node;
    node = new Node{val, successor, predecessor};
}

template<typename T>
void DL_List<T>::pop_at_position(unsigned int position)
{
    Node* node = head;
    
    for(int i = 0; i = position; i += 1)
    {
        node = head->next;
    }
    
    Node* predecessor = node->before;
    Node* successor = node->next;
    delete node;
    predecessor->next = successor;
    successor->before = predecessor;
}
//-----------------------------------------------------------------
// Usefull functions
template<typename T>
int DL_List<T>::size()
{
    if(head == nullptr)
    {
        return 0;
    }

    Node* node = head;
    int count = 1;

    while(node->next != nullptr)
    {
        node = head->next;
        count += 1;
    }

    return count;
}

template<typename T>
bool DL_List<T>::empty()
{
    if(head == nullptr)
    {
        return true;
    }
    return false;
}

template<typename T>
void DL_List<T>::swap(DL_List& l)
{
    Node* tmp_head = head;
    Node* tmp_tail = tail;

    head = l.head;
    tail = l.tail;

    l.head = tmp_head;
    l.tail = tmp_tail;
}
//-----------------------------------------------------------------
// Constructors
template<typename T>
DL_List<T>::~DL_List()  // destructor
{
    while(!empty())
    {
        pop_front();
    }
}

template<typename T>
DL_List<T>::DL_List(DL_List const& l)   // copy constructor
{
    DL_List tmp;
    for(T const& x : l)
    {
        tmp.push_front(x);
    }
    for(T const& x : tmp)
    {
        push_front(x);
    }
}

template<typename T>
DL_List<T>::DL_List(DL_List&& l)    // move constructor
{
    swap(l);
}

template<typename T>
DL_List<T>& DL_List<T>::operator=(DL_List l)    // copy assignment
{
    swap(l);
    return *this;
}

template<typename T>
DL_List<T>& DL_List<T>::operator=(DL_List&& l) // move assignment
{
    swap(l);
    return *this;
}
//-----------------------------------------------------------------
