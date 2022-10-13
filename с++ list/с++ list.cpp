#include <iostream>
using namespace std;

struct Node 
{
	string value;
	Node* nextNode;
	Node(string input) : value(input), nextNode(nullptr) {}
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
        elem->nextNode = first;
        first = elem;
    }

    void print() 
    {
        if (IsEmpty()) 
            return  ;
        Node* p = first;
        while (p) {
            cout << p->value << " ";
            p = p->nextNode;
        }
        cout << endl;
    }
};

int main()
{
    list a;
    cout << a.IsEmpty() << endl;
    a.AddTail("3");
    a.AddTail("3");
    a.AddTail("3");
    a.AddHead("hui");
    //a.AddHead("b");
    a.print();
    cout << a.IsEmpty() << endl;
}