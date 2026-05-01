#pragma once

#include <iostream>

// TODO: Checken, ob es Probleme gibt wenn head nullptr ist und die Liste somit leer ist.

template<typename T>
class DL_List
{
public:
    // Elements of DL_List are Nodes.
    // They know their predecessor as well as their successor.
    struct Node
    {
        T value;
        Node* next;
        Node* before;
    };
    //-----------------------------------------------------------------
    // Iterator
    template<typename NN, typename TT>
    struct Iterator
    {
        NN* node;

        Iterator& operator++()
        {
            node = node->next;
            return *this;
        }

        friend
        bool operator==(Iterator a, Iterator b)
        {
            return a.node == b.node;
        }

        friend
        bool operator!=(Iterator a, Iterator b)
        {
            return !(a == b);
        }

        TT& operator*() const
        {
            return node->value;
        }

        TT* operator->() const
        {
            return &(node->value);
        }
    };
    //-----------------------------------------------------------------
    // Standard-Libs convention
    using iterator = Iterator<Node, T>;
    using const_iterator = Iterator<Node const, T const>;
    //-----------------------------------------------------------------
    // Data attributes
    Node* head = nullptr;
    Node* tail = nullptr;
    //-----------------------------------------------------------------
    // Push- and pull-functions
    void push_front(T const& val);
    void pop_front();

    void push_back(T const& val);
    void pop_back();

    void push_at_position(unsigned int position, T const& val);
    void pop_at_position(unsigned int position);
    //-----------------------------------------------------------------
    // Usefull functions
    int size();
    bool empty();
    void swap(DL_List& l);
    //-----------------------------------------------------------------
    // Value queries
    T& front(){return head->value;};
    T const& front() const{return head->value;};
    T& back(){return tail->value;};
    T const& back() const{return tail->value;};
    //-----------------------------------------------------------------
    // Iterators for begin & end of DL_List
    iterator begin(){return iterator{head};}
    iterator end(){return iterator{nullptr};}
    const_iterator begin() const{return const_iterator{head};}
    const_iterator end() const{return const_iterator{nullptr};}
    //-----------------------------------------------------------------
    // Constructors
    DL_List() = default;
    ~DL_List();
    DL_List(DL_List const& l);
    DL_List(DL_List&& l);
    DL_List& operator=(DL_List l);
    DL_List& operator=(DL_List&& l);
    //-----------------------------------------------------------------
    // Output
    void print()
    {
        for(T const& elements : *this)
        {
            std::cout << "[" << elements << " ,";
        }

        std::cout << "]\n";
    }
};