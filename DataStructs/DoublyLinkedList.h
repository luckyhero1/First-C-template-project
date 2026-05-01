
// TODO: Checken, ob es Probleme gibt wenn head nullptr ist und die Liste somit leer ist.

template<typename T>
class DL_List
{
    // Elements of DL_List are Nodes.
    // They know their predecessor as well as their successor.
    struct Node
    {
        T value;
        Node* next;
        Node* before;
    };

    Node* head = nullptr;

    void push_front(T const& val);
    void pop_front();

    void push_back(T const& val);
    void pop_back();

    void push_at_position(unsigned int position, T const& val);
    void pop_at_position(unsigned int position);
    
    int size();
    bool empty();

    Node* front(){return head;};
    Node* back();
};