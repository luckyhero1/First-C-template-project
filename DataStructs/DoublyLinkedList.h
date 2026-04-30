

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

    void push_front(T const& val)
    {
        Node* tmp = head;
        head = new Node{val, head, nullptr};
        tmp->before = &head;
    }

    void pop_front()
    {
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}