#include <iostream>
using namespace std;

struct Node 
{
	string value;
	Node* nextNode;
    Node* prevNode;
	Node(string input) : value(input), nextNode(nullptr), prevNode(nullptr) {}
};

struct list {
	Node* first;
	Node* last;
	list() : first(nullptr), last(nullptr) {}

    bool IsEmpty()
    {
        return first == nullptr;
    }

    void AddTail(string input) 
    {
        Node* elem = new Node(input);
        if (IsEmpty()) 
        {
            first = elem;
            last = elem;
            return;
        }
        elem->prevNode = last;
        last->nextNode = elem;
        last = elem;
    }

    void AddHead(string input)
    {
        Node* elem = new Node(input);
        if (IsEmpty())
        {
            first = elem;
            last = elem;    
            return;
        }
        first->prevNode = elem;
        elem->nextNode = first;
        first = elem;
    }

    void Insert(string input, int index)
    {
        Node* elem = new Node(input);
        int counter=0;
        if (index == 0)
        {
            elem->nextNode = first;
            first = elem;
            return;
        }
        for (Node* p = first; p; p = p->nextNode, counter++) {       
            if (counter==index) 
            {
                p->prevNode = elem;
                elem->prevNode = p->prevNode;
                elem->nextNode = p;
                p->prevNode = elem;
                //elem->nextNode = p->nextNode;
                //p->nextNode = elem;
                //break;
            }
        }
    }

    void RemoveHead()
    {
        Node* temp = first;
        first->nextNode->prevNode = nullptr;
        first = first->nextNode;
        delete temp;
    }

    void RemoveTail() 
    {
        if (IsEmpty()) return;
        if (first == last) {
            RemoveHead();
            return;
        }
        Node* p = first;
        while (p->nextNode != last) p = p->nextNode;
        p->nextNode = nullptr;
        delete last;
        last = p;
    }

    void Remove(int index)
    {
        int counter = 0;
        if (index == 0)
        {
            RemoveHead();
            return;
        }
        for (Node* p = first; p; p = p->nextNode, counter++) 
        {
            if (counter == index) 
            {
                p->prevNode->nextNode = p->nextNode;
                p->nextNode = p->prevNode;
                delete p;
                /*p->nextNode = p->nextNode->nextNode;
                break;*/
            }
        }
    }

    void RemoveAll()
    {
        while (first) {
            Node* p = first->nextNode;
            free(first);
            first = p;
        }
    }

    void Print() 
    {
        if (IsEmpty()) 
            return;
        Node* p = first;
        while (p) {
            cout << p->value << " ";
            p = p->nextNode;
        }
        cout << endl;
    }

    void FindIndex(int index)
    {
        int counter = 0;
        for (Node* i = first; i; i=i->nextNode, counter++)
        {
            if (counter == index)
                cout << i;
        }
        cout << endl;
    }

    void FindValue(string val) 
    {
        for (Node* i = first; i; i = i->nextNode)
        {
            if (i->value == val)
            {
                cout << i;
                cout << endl;
            }
        }
        cout << endl;
    }

    void Retrieve(Node* path)
    {
        for (Node* i = first; i; i = i->nextNode)
        {
            if (i == path)
                cout << i->value;
        }
        cout << endl;
    }

    void Reverse()
    {
        Node* prhead = nullptr; 
        while (first != nullptr)
        {
            Node* p = first->nextNode;
            first->prevNode = first->nextNode;
            first->nextNode = prhead;
            prhead = first;
            first = p;
        }
        first = prhead;
    }
};

int main()
{
    list a;
    cout << a.IsEmpty() << endl;
    a.AddTail("3");
    a.AddTail("3");
    a.AddHead("hui");
    a.AddTail("last");
    a.AddTail("3");
    a.Insert("in", 0);
    a.Print();
    a.Reverse();
    a.Print();
    //a.Retrieve(1);
    //a.FindValue("hui");
    //cout << a.first;
    //a.FindIndex(4);
    //cout << a.last;
    /*a.RemoveAll();*/

    //a.RemoveHead();
    //a.RemoveTail();
    //a.AddHead("b");
    //a.Remove(3);
    cout << a.IsEmpty() << endl;
}