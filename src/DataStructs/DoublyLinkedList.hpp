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
    // Note to me: is used to traverse through data, access to value via dereference
    template<typename NN, typename TT>
    struct Iterator
    {
        NN* node;

        // Increment
        Iterator& operator++()      // prefix
        {
            node = node->next;
            return *this;
        }
        
        Iterator& operator++(int)    // postfix (the int in header is prescribed)
        {
            Iterator& result{*this};
            node = node->next;
            return result;
        }

        // Decrement
        Iterator& operator--()      // prefix
        {
            node = node->before;
            return *this;
        }

        Iterator& operator--(int)    // postfix (the int in header is prescribed)
        {
            Iterator& result{*this};
            node = node->before;
            return result;
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
    // Value queries
    T &front() { return head->value; };
    T const &front() const { return head->value; };
    T &back() { return tail->value; };
    T const &back() const { return tail->value; };
    //-----------------------------------------------------------------
    // Iterators for begin & end of DL_List
    iterator begin() { return iterator{head}; }
    iterator end() { return iterator{nullptr}; }
    const_iterator begin() const { return const_iterator{head}; }
    const_iterator end() const { return const_iterator{nullptr}; }
    // TODO: rbegin, rend, cbegin, cend, ???crbegin, crend???
    //-----------------------------------------------------------------
    // Usefull functions
    bool empty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }

    int size()
    {
        if (empty())
        {
            return 0;
        }

        iterator it = begin();
        int count = 1;

        while (it++ != end())
        {
            count += 1;
        }

        return count;
    }

    void swap(DL_List &l)
    {
        Node* tmp_head = head;
        Node* tmp_tail = tail;

        head = l.head;
        tail = l.tail;

        l.head = tmp_head;
        l.tail = tmp_tail;
    }
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
            Node* temp = head->next;
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
            Node* tmp = tail;
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
            Node* temp = tail->before;
            delete tail;
            tail = temp;
            if(tail == nullptr) // list is empty (empty() is unfortunately focused on head)
            {
                head = nullptr;
            }
            else
            {
                tail->next = nullptr;
            }
        }
    }

    void push_at_position(int position, T const& val)   /// 0 <= position <= size
    {
        if ((position < 0) || (position > size()))
        {
            std::cout << "Argument position is not in defined scope.\n";
            exit(-2);
        }

        if (empty())
        {
            push_front(val);
            return;
        }

        iterator it = begin();
        for (int i = 0; i < position; i += 1)
        {
            ++it;
        }

        if (it == end())
        {
            push_back(val);
            return;
        }

        Node* currentNode = it.node;
        Node* successor = currentNode;
        Node* predecessor = currentNode->before;
        currentNode = new Node{val, successor, predecessor};
        successor->before = currentNode;
        predecessor->next = currentNode;
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

        iterator it = begin();
        for (int i = 0; i < position; i += 1)
        {
            ++it;
        }

        // Failure handling is already implemented with pop_front/_back
        if(it == begin())
        {
            pop_front();
            return;
        }
        else if(it == --end())
        {
            pop_back();
            return;
        }

        Node* currentNode = it.node;
        Node* predecessor = currentNode->before;
        Node* successor = currentNode->next;
        delete currentNode;
        predecessor->next = successor;
        successor->before = predecessor;
    }
    //-----------------------------------------------------------------
    // Operator overloading
    Node* operator[](int n)
    {
        if((n < 0) || (n > size() - 1))
        {
            std::cout << "Argument position is not in defined scope.\n.";
            exit(-2);
        }

        if(empty())
        {
            std::cout << "You can't access a list, that is empty.\n";
            exit(-3);
        }

        iterator it = begin();

        for (int i = 0; i < n; i += 1)
        {
            ++it;
        }

        return it.node;
    }

    Node const* operator[](int n) const
    {
        if((n < 0) || (n > size() - 1))
        {
            std::cout << "Argument position is not in defined scope.\n.";
            exit(-2);
        }

        if(empty())
        {
            std::cout << "You can't access a list, that is empty.\n";
            exit(-3);
        }

        const_iterator it = begin();

        for (int i = 0; i < n; i += 1)
        {
            ++it;
        }

        return it.node;
    }

    void operator<<(std::ostream out)
    {
        out << "[";

        for(T const& elements : *this)
        {
            if(elements == back())
            {
                out << elements;
            }
            else
            {
                out << elements << ", ";
            }
        }

        std::cout << "]\n";
    }
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
        for (T const& x : l)
        {
            tmp.push_front(x);
        }
        for (T const& x : tmp)
        {
            push_front(x);
        }
    }

    DL_List(DL_List &&l) // move constructor
    {
        swap(l);
    }

    DL_List& operator=(DL_List l) // copy assignment
    {
        swap(l);
        return *this;
    }

    DL_List& operator=(DL_List &&l) // move assignment
    {
        swap(l);
        return *this;
    }
    //-----------------------------------------------------------------
    // Output
    /*void print()
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
    }*/
};