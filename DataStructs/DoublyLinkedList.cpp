#include "DoublyLinkedList.h"

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

/**
 * Idea for push_- and pop_back:
 * 
 * Begin with head and compare it's successor with the nullptr.
 * If it's not the nullptr, iterate until you finde the node with nullptr as successor.
 * Then you can operate push or pop.
 */
template<typename T>
void DL_List<T>::push_back(T const& val)
{
    Node* node = head;
    
    while(node->next != nullptr)
    {
        node = head->next;
    }

    Node* predecessor = node;
    node = new Node{val, nullptr, predecessor};
}

template<typename T>
void DL_List<T>::pop_back()
{
    Node* node = head;
    
    while(node->next != nullptr)
    {
        node = head->next;
    }

    Node* predecessor = node->before;
    delete node;
    predecessor->next = nullptr;
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

