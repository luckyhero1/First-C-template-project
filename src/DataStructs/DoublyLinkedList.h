#pragma once

#include <iostream>

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
    Node *head = nullptr;
    Node *tail = nullptr;
    //-----------------------------------------------------------------
    // Push- and pull-functions
    void push_front(T const& val)
    {
        if(empty())
        {
            head = new Node{val, nullptr, nullptr};
            tail = head;
        }
        else
        {
            Node* tmp = head;
            head = new Node{val, tmp, nullptr};
            tmp->before = head;
        }
    }

    void pop_front()
    {
        if (empty())
        {
            std::cout << "You can't pop a list, that is empty.\n";
            exit(-1);
        }
        else
        {
            Node *temp = head->next;
            delete head;
            head = temp;
            if(empty())
            {
                tail = nullptr;
            }
            else
            {
                head->before = nullptr;
            }
        }
    }

    void push_back(T const& val)
    {
        if (empty())
        {
            tail = new Node{val, nullptr, nullptr};
            head = tail;
        }
        else
        {
            Node *tmp = tail;
            tail = new Node{val, nullptr, tmp};
            tmp->next = tail;
        }
    }

    void pop_back()
    {
        if (empty())
        {
            std::cout << "You can't pop a list, that is empty.\n";
            exit(-1);
        }
        else
        {
            Node *temp = tail->before;
            delete tail;
            tail = temp;
            if(tail == nullptr) // list is empty, delete head
            {
                head = nullptr;
            }
            else    // list not empty
            {
                tail->next = nullptr;
            }
        }
    }

    void push_at_position(int position, T const& val)   // 0 <= position <= size
    {
        if ((position < 0) || (position > size()))
        {
            std::cout << "Argument position is not in defined scope.\n";
            exit(-2);
        }

        Node *node = head;

        for (int i = 0; i < position; i += 1)
        {
            node = node->next;
        }

        // Failure handling is already implemented with push_front/_back
        if (empty())
        {
            push_front(val);
            return;
        }
        else if (node == tail->next)
        {
            push_back(val);
            return;
        }

        Node *predecessor = node->before;
        Node *successor = node;
        node = new Node{val, successor, predecessor};
    }

    void pop_at_position(int position) // 0 <= position <= size - 1
    {
        if((position < 0) || (position > size() - 1))
        {
            std::cout << "Argument position is not in defined scope.\n.";
            exit(-2);
        }

        if(empty())
        {
            std::cout << "You can't pop a list, that is empty.\n";
            exit(-1);
        }
        
        Node *node = head;

        for (int i = 0; i < position; i += 1)
        {
            node = node->next;
        }

        // Failure handling is already implemented with pop_front/_back
        if(node == head)
        {
            pop_front();
            return;
        }
        else if(node == tail)
        {
            pop_back();
            return;
        }

        Node *predecessor = node->before;
        Node *successor = node->next;
        delete node;
        predecessor->next = successor;
        successor->before = predecessor;
    }
    //-----------------------------------------------------------------
    // Usefull functions
    int size()
    {
        if (head == nullptr)
        {
            return 0;
        }

        Node *node = head;
        int count = 1;

        while (node->next != nullptr)
        {
            node = node->next;
            count += 1;
        }

        return count;
    }
    
    bool empty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }

    void swap(DL_List& l)
    {
        Node *tmp_head = head;
        Node *tmp_tail = tail;

        head = l.head;
        tail = l.tail;

        l.head = tmp_head;
        l.tail = tmp_tail;
    }
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

    ~DL_List()  // destructor
    {
        while (!empty())
        {
            pop_front();
        }
    }

    DL_List(DL_List const &l) // copy constructor
    {
        DL_List tmp;
        for (T const &x : l)
        {
            tmp.push_front(x);
        }
        for (T const &x : tmp)
        {
            push_front(x);
        }
    }

    DL_List(DL_List &&l) // move constructor
    {
        swap(l);
    }

    DL_List &operator=(DL_List l) // copy assignment
    {
        swap(l);
        return *this;
    }

    DL_List &operator=(DL_List &&l) // move assignment
    {
        swap(l);
        return *this;
    }
    //-----------------------------------------------------------------
    // Output
    void print()
    {
        std::cout << "[";
        
        for(T const& elements : *this)
        {
            if(elements == back())
            {
                std::cout << elements;
            }
            else
            {
                std::cout << elements << ", ";
            }
        }

        std::cout << "]\n";
    }
};