#include <iostream>
using namespace std;

template <typename T>
class node
{
private:
    T data;
    node *prev, *next;

public:
    node()
    {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }

    node(T value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }

    node(node &n)
    {
        data = n.data;
    }

    T GetData() { return data; }
    void SetData(T d) { data = d; }
    node *GetPrev() { return prev; }
    node *GetNext() { return next; }
    void SetPrev(node *n) { prev = n; }
    void SetNext(node *n) { next = n; }
};

template <typename T>
class Stack
{
private:
    int _size;
    node<T> *top, *end;

public:
    int size() { return _size; }
    node<T> *GetTop() { return top; }
    node<T> *GetEnd() { return end; }

    void SetTop(node<T> *top)
    {
        top->SetNext(this->top);
        this->top = top;
    }

    void SetEnd(node<T> *end)
    {
        this->end->SetNext(end);
        this->end = end;
    }

    Stack()
    {
        _size = 0;
        top = end = nullptr;
    }

    Stack(T data) : Stack() { this->push(data); }
    Stack(Stack &S) : Stack() { this->operator=(); }

    void operator=(Stack &S)
    {
        this->empty();
        int size = S.size();
        for (int i = 0; i < size; i++)
        {
            this->push(S[i]);
        }
    }

    void push(T data)
    {
        node<T> *p = new node<T>(data);
        if (top == nullptr)
        {
            top = end = p;
        }
        else
        {
            p->SetNext(top);
            top->SetPrev(p);
            top = p;
        }
        _size++;
    }

    T pop()
    {
        if (top == nullptr)
        {
            return -1;
        }
        else
        {
            node<T> *p = top;
            top = top->GetNext();
            top->SetNext(nullptr);
            T data = p->GetData();
            _size--;
            delete (p);
            return data;
        }
    }

    T peek()
    {
        if (top == nullptr)
        {
            return -1;
        }
        else
        {
            return top->GetData();
        }
    }

    bool isEmpty() { return (top == nullptr); }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    bool isEqual(Stack &S)
    {
        if (_size != S.size())
        {
            return false;
        }
        else
        {
            node<T> *p = top, *q = S.getTop();
            while (p != nullptr)
            {
                if (p->GetData() != q->GetData())
                {
                    return false;
                }
                p = p->GetNext();
            }
            return true;
        }
    }
    bool operator==(Stack &S) { return this->isEqual(S); }
    void reverse()
    {
        if (top != nullptr)
        {
            node<T> *prev = nullptr, *curr = top, *next = curr->GetNext();
            while (next != nullptr)
            {
                curr->SetPrev(next);
                curr->SetNext(prev);
                prev = curr;
                curr = next;
                next = next->GetNext();
            }
            curr->SetNext(prev);
            curr->SetPrev(nullptr);
            end = top;
            top = curr;
        }
    }

    T operator[](int k)
    {
        try
        {
            if (k > _size)
            {
                throw "Index out of range";
            }
            else
            {
                node<T> *p = top;
                for (int i = 0; i < k; i++)
                {
                    p = p->GetNext();
                }
                return p->GetData();
            }
        }
        catch (String err)
        {
            cout << err << endl;
            return (T)(-1);
        }
    }

    void empty()
    {
        while (!isEmpty())
        {
            pop();
        }
        top = nullptr;
    }

    friend ostream &operator<<(ostream &, Stack &);
    friend istream &operator>>(istream &, Stack &);
};

template <typename T>
ostream &operator<<(ostream &cout, Stack<T> &S)
{
    if (S.top != nullptr)
    {
        node<T> *p = S.top;
        while (p != nullptr)
        {
            cout << p->GetData() << " -> ";
            p = p->GetNext();
        }
        cout << "nullptr" << endl;
    }
    else
    {
        cout << "STACK IS EMPTY" << endl;
    }
}

template <typename T>
istream &operator>>(istream &cin, Stack<T> &S)
{
    bool flag = 1;
    while (flag)
    {
        cout << "Enter Elements: Press 1" << endl
             << "Exit: Press 0";
        cin >> flag;
        if (flag)
        {
            cout << "Enter Data: ";
            T data;
            cin >> data;
            S.push(data);
        }
    }
}