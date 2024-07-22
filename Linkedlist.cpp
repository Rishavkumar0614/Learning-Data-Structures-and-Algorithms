#include <math.h>
#include <string>
#include <iostream>
using namespace std;

class node
{
private:
    int data;
    bool flag;
    node *next;

public:
    node()
    {
        data = 0;
        flag = false;
        next = nullptr;
    }

    node(int value)
    {
        data = value;
        flag = false;
        next = nullptr;
    }

    int GetData() { return data; }
    bool GetFlag() { return flag; }
    node *GetNext() { return next; }
    void SetData(int d) { data = d; }
    void SetFlag(bool f) { flag = f; }
    void SetNext(node *n) { next = n; }
};

class LinkedList
{
private:
    int _size;
    node *head, *end;

public:
    int size() { return _size; }
    node *GetEnd() { return end; }
    node *GetHead() { return head; }
    LinkedList()
    {
        _size = 0;
        head = end = nullptr;
    }

    LinkedList(int d)
    {
        _size = 1;
        head = end = new node(d);
    }

    LinkedList(LinkedList &L)
    {
        if (L.size() >= 1)
        {
            node *n = new node(L[0]);
            head = n;
            for (int i = 1; i <= L.size(); i++)
            {
                n->SetNext(new node(L[i]));
                n = n->GetNext();
            }
            end = n;
        }
    }

    void insert(int d)
    {
        node *ptr = new node(d);
        if (head == nullptr)
        {
            head = end = ptr;
        }
        else
        {
            end->SetNext(ptr);
        }
        _size++;
        end = ptr;
    }

    void insertAtHead(int d)
    {
        node *ptr = new node(d);
        if (head == nullptr)
        {
            end = ptr;
            head = ptr;
        }
        else
        {
            ptr->SetNext(head);
            head = ptr;
        }
        _size++;
    }

    void insertList(LinkedList &L)
    {
        _size += L.size();
        end->SetNext(L.GetHead());
    }

    int operator[](int k)
    {
        if (k > _size)
        {
            return -1;
        }
        else
        {
            node *p = head;
            for (int i = 0; i < k; i++)
            {
                p = p->GetNext();
            }
            return p->GetData();
        }
    }

    void reverse()
    {
        node *prev = nullptr, *curr, *next;
        if (_size > 1)
        {
            curr = head;
            next = curr->GetNext();
            while (next != nullptr)
            {
                curr->SetNext(prev);
                prev = curr;
                curr = next;
                next = curr->GetNext();
            }
            curr->SetNext(prev);
            head = curr;
        }
    }

    void Delete(int d)
    {
        node *temp = head;
        node *toDeleteNode = nullptr;
        if (head != nullptr)
        {
            if (head->GetData() == d)
            {
                toDeleteNode = head;
                head = head->GetNext();
                delete toDeleteNode;
                _size--;
                return;
            }
            while (temp != nullptr && temp->GetNext() != nullptr && temp->GetNext()->GetData() != d)
            {
                temp = temp->GetNext();
            }
            if (temp->GetNext()->GetData() == d)
            {
                toDeleteNode = temp->GetNext();
                if (toDeleteNode == end)
                {
                    end = temp;
                }
                temp->SetNext(temp->GetNext()->GetNext());
                delete toDeleteNode;
                _size--;
            }
        }
    }

    void DeleteHead()
    {
        if (head != nullptr)
        {
            node *p = head;
            if (head == end)
            {
                head = end = nullptr;
            }
            else
            {
                head = head->GetNext();
            }
            _size--;
            delete (p);
        }
    }

    void DeleteList()
    {
        node *temp;
        node *p = head;
        if (head != nullptr)
        {
            while (p != nullptr)
            {
                temp = p->GetNext();
                delete (p);
                p = temp;
            }
            head = end = nullptr;
        }
    }

    int nnodes()
    {
        int n = 0;
        node *temp = head;
        while (temp != nullptr)
        {
            n++;
            temp = temp->GetNext();
        }
        return n;
    }

    void Delete(node *n)
    {
        node *prev = nullptr, *curr = n, *next = n->GetNext();
        curr->SetData(next->GetData());
        prev = curr;
        curr = prev->GetNext();
        next = curr->GetNext();
        prev->SetNext(next);
        delete (curr);
    }

    int nthNodeFromEnd(int n)
    {
        if (_size < n)
        {
            return -1;
        }
        node *p = head;
        for (int i = 0; i < (_size - n); i++)
        {
            p = p->GetNext();
        }
        return p->GetData();
    }

    int GetMiddleNode()
    {
        int mid;
        if (_size == 0)
        {
            return -1;
        }
        else if (_size == 1)
        {
            return head->GetData();
        }
        if (_size % 2 == 0)
        {
            mid = (_size / 2);
        }
        else
        {
            mid = ((_size - 1) / 2);
        }
        node *p = head;
        for (int i = 1; i < mid; i++)
        {
            p = p->GetNext();
        }
        return p->GetData();
    }

    bool isPalindrome()
    {
        if (_size == 0)
        {
            return false;
        }
        else if (_size == 1)
        {
            return true;
        }
        int mid;
        if (_size % 2 == 0)
        {
            mid = (_size / 2);
        }
        else
        {
            mid = ((_size - 1) / 2);
        }
        node *p = head;
        for (int i = 0; i < mid; i++)
        {
            if (p->GetData() != nthNodeFromEnd(i + 1))
            {
                return false;
            }
            p = p->GetNext();
        }
        return true;
    }

    static bool isIntersecting(node *h1, node *h2)
    {
        while (h1->GetNext() != nullptr)
        {
            h1 = h1->GetNext();
        }
        while (h2->GetNext() != nullptr)
        {
            h2 = h2->GetNext();
        }
        return (h1 == h2);
    }

    static int intersectionPoint(node *h1, node *h2)
    {
        if (LinkedList::isIntersecting(h1, h2))
        {
            while (h1 != nullptr)
            {
                h1->SetFlag(true);
                h1 = h1->GetNext();
            }
            while (h2 != nullptr)
            {
                if (h2->GetFlag() == true)
                {
                    return h2->GetData();
                }
                h2 = h2->GetNext();
            }
            return -1;
        }
        return -1;
    }

    void rotate(int k)
    {
        if (_size == 0 || _size == 1)
        {
            return;
        }
        node *p = head;
        for (int i = 0; i < k; i++)
        {
            end->SetNext(p);
            head = head->GetNext();
            p->SetNext(nullptr);
            end = p;
            p = head;
        }
    }

    void removeDuplicate()
    {
        int minno = head->GetData();
        int maxno = head->GetData();
        node *p = head->GetNext();
        for (int i = 1; i < _size; i++)
        {
            if (minno > p->GetData())
            {
                minno = p->GetData();
            }
            if (maxno < p->GetData())
            {
                maxno = p->GetData();
            }
            p = p->GetNext();
        }
        int *array = new int[(maxno - minno + 1)];
        for (int i = 0; i < (maxno - minno + 1); i++)
        {
            array[i] = 0;
        }
        p = head;
        for (int i = 0; i < _size; i++)
        {
            array[p->GetData() - minno] = 1;
            p = p->GetNext();
        }
        p = head;
        while (p != nullptr)
        {
            node *temp = p;
            p = p->GetNext();
            delete (temp);
        }
        head = nullptr;
        head = new node(minno);
        p = head;
        for (int i = 1; i < (maxno - minno + 1); i++)
        {
            if (array[i])
            {
                p->SetNext(new node(i + minno));
                p = p->GetNext();
            }
        }
    }

    void addOne()
    {
        int num = 0;
        int k = _size;
        node *p = head;
        for (int i = 0; i < _size; i++)
        {
            num += (p->GetData() * pow(10, --k));
            p = p->GetNext();
        }
        num++;
        string numstr = to_string(num);
        p = head;
        for (int i = 0; i < numstr.size(); i++)
        {
            p->SetData(numstr[i] - '0');
            p = p->GetNext();
        }
    }

    bool DetectLoop()
    {
        node *p = head;
        while (!p->GetFlag() && p->GetNext() != nullptr)
        {
            p->SetFlag(true);
            p = p->GetNext();
        }
        if (p->GetNext() == nullptr)
        {
            return false;
        }
        else if (p->GetFlag())
        {
            return true;
        }
    }

    void RemoveLoop()
    {
        if (DetectLoop())
        {
            node *p = head;
            while (p->GetFlag())
            {
                p->SetFlag(false);
                p = p->GetNext();
            }
            p = head;
            while (!p->GetNext()->GetFlag())
            {
                p->SetFlag(true);
                p = p->GetNext();
            }
            p->SetNext(nullptr);
        }
    }

    bool isCircularList()
    {
        node *p = head;
        while (!p->GetFlag() && p != nullptr)
        {
            p->SetFlag(true);
            p = p->GetNext();
        }
        return (p == head);
    }

    void PairWiseSwap()
    {
        if (_size == 0 || _size == 1)
        {
            return;
        }
        node *prev = head, *curr = prev->GetNext(), *next = curr->GetNext();
        head = curr;
        prev->SetNext(next);
        curr->SetNext(prev);
        curr = prev->GetNext();
        while (curr != nullptr && curr->GetNext() != nullptr)
        {
            next = curr->GetNext();
            prev->SetNext(next);
            curr->SetNext(next->GetNext());
            next->SetNext(curr);
            prev = curr;
            curr = prev->GetNext();
        }
    }

    void segregate()
    {
        int count[3] = {0};
        node *p = head;
        while (p != nullptr)
        {
            count[p->GetData()]++;
            p = p->GetNext();
        }
        p = head;
        for (int i = 0; i < count[0]; i++)
        {
            p->SetData(0);
            p = p->GetNext();
        }
        for (int i = 0; i < count[1]; i++)
        {
            p->SetData(1);
            p = p->GetNext();
        }
        for (int i = 0; i < count[2]; i++)
        {
            p->SetData(2);
            p = p->GetNext();
        }
    }

    int LengthOfLoop()
    {
        if (!DetectLoop())
        {
            int _size = 0;
            node *p = head;
            while (p->GetFlag())
            {
                p->SetFlag(false);
                p = p->GetNext();
            }
            while (!p->GetFlag())
            {
                _size++;
                p->SetFlag(true);
                p = p->GetNext();
            }
            return _size;
        }
        return -1;
    }

    static bool isIdentical(node *h1, node *h2)
    {
        node *p1 = h1, *p2 = h2;
        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->GetData() != p2->GetData())
            {
                return false;
            }
            p1 = p1->GetNext();
            p2 = p2->GetNext();
        }
        if (p1->GetNext() != p2->GetNext())
        {
            return false;
        }
        return true;
    }

    void DeleteMiddleNode()
    {
        if (_size == 0 || _size == 1)
        {
            return;
        }
        int mid;
        if (_size % 2 == 0)
        {
            mid = (_size / 2);
        }
        else
        {
            mid = ((_size - 1) / 2);
        }
        node *prev = nullptr, *curr = head, *next = head->GetNext();
        for (int i = 0; i < mid; i++)
        {
            prev = curr;
            curr = next;
            next = next->GetNext();
        }
        prev->SetNext(next);
        delete (curr);
    }

    void InsertMiddleNode(int value)
    {
        if (_size == 0 || _size == 1)
        {
            return;
        }
        int mid;
        if (_size % 2 == 0)
        {
            mid = (_size / 2);
        }
        else
        {
            mid = ((_size - 1) / 2);
        }
        node *prev = nullptr, *curr = head, *next = head->GetNext();
        for (int i = 0; i < mid; i++)
        {
            prev = curr;
            curr = next;
            next = next->GetNext();
        }
        node *p = new node(value);
        curr->SetNext(p);
        p->SetNext(next);
    }

    int count(int key)
    {
        int count = 0;
        node *p = head;
        while (p != nullptr)
        {
            if (key == p->GetData())
            {
                count++;
            }
            p = p->GetNext();
        }
        return count;
    }

    void DeleteAlternateNodes()
    {
        if (_size == 0 || _size == 1 || _size == 2)
        {
            return;
        }
        node *prev = head, *curr = prev->GetNext(), *next = curr->GetNext();
        while (next != nullptr)
        {
            prev->SetNext(next);
            delete (curr);
            prev = next;
            curr = next->GetNext();
            if (curr != nullptr)
            {
                next = curr->GetNext();
            }
            else
            {
                next = nullptr;
            }
        }
        prev->SetNext(nullptr);
        delete (curr);
    }

    friend ostream &operator>>(ostream &, LinkedList &);
    ~LinkedList() { this->DeleteList(); }
};

ostream &operator>>(ostream &cout, LinkedList &L)
{
    if (L.head != nullptr)
    {
        node *p = L.head;
        while (p != nullptr)
        {
            cout << p->GetData() << " -> ";
            p = p->GetNext();
        }
        cout << "nullptr" << endl;
    }
    else
    {
        cout << "LIST IS EMPTY";
    }
}

class dnode
{
private:
    int data;
    dnode *prev;
    dnode *next;

public:
    dnode()
    {
        data = 0;
        prev = nullptr;
        next = nullptr;
    }

    dnode(int data)
    {
        prev = nullptr;
        next = nullptr;
        this->data = data;
    }

    int GetData() { return data; }
    void SetData(int data) { this->data = data; }
    dnode *GetPrev() { return prev; }
    void SetPrev(dnode *prev) { this->prev = prev; }
    dnode *GetNext() { return next; }
    void SetNext(dnode *next) { this->next = next; }
};
class DoublyLinkedList
{
private:
    int _size;
    dnode *head, *end;

public:
    int size() { return _size; }
    DoublyLinkedList()
    {
        _size = 0;
        head = end = nullptr;
    }

    DoublyLinkedList(int d)
    {
        _size = 1;
        head = end = new dnode(d);
    }

    DoublyLinkedList(DoublyLinkedList &L)
    {
        if (L.size() >= 1)
        {
            dnode *p = new dnode(L[0]);
            head = p;
            for (int i = 1; i <= L.size(); i++)
            {
                p->SetNext(new dnode(L[i]));
                p->GetNext()->SetPrev(p);
                p = p->GetNext();
            }
        }
    }

    int operator[](int key)
    {
        if (key > _size)
        {
            return -1;
        }
        else
        {
            dnode *p = head;
            for (int i = 0; i < key; i++)
            {
                p = p->GetNext();
            }
            return p->GetData();
        }
    }

    void insert(int data)
    {
        dnode *p = new dnode(data);
        if (head == nullptr)
        {
            head = p;
        }
        else
        {
            dnode *temp = head;
            while (temp->GetNext() != nullptr)
            {
                temp = temp->GetNext();
            }
            temp->SetNext(p);
            p->SetPrev(temp);
        }
        end = p;
        _size++;
    }

    void insertAtHead(int value)
    {
        dnode *p = new dnode(value);
        if (head == nullptr)
        {
            head = p;
        }
        else
        {
            head->SetPrev(p);
            p->SetNext(head);
            head = p;
        }
        _size++;
    }

    void Display()
    {
        if (head != nullptr)
        {
            dnode *temp = head;
            while (temp != nullptr)
            {
                cout << temp->GetData() << " -> ";
                temp = temp->GetNext();
            }
            cout << "nullptr" << endl;
        }
        else
            cout << "List Is Empty" << endl;
    }

    void DisplayReverse()
    {
        if (end != nullptr)
        {
            dnode *temp = end;
            while (temp != head)
            {
                cout << temp->GetData() << " -> ";
                temp = temp->GetPrev();
            }
            cout << temp->GetData() << endl;
        }
        else
            cout << "List Is Empty";
    }

    void Delete(int key)
    {
        if (head == nullptr)
        {
            return;
        }
        else if (head->GetData() == key)
        {
            dnode *temp = head;
            temp->GetNext()->SetPrev(nullptr);
            head = head->GetNext();
            delete (temp);
        }
        else
        {
            dnode *prev = head, *curr = prev->GetNext(), *next = curr->GetNext();
            while (curr->GetData() != key && next != nullptr)
            {
                prev = curr;
                curr = prev->GetNext();
                next = curr->GetNext();
            }
            if (curr->GetData() == key)
            {
                if (next != nullptr)
                {
                    prev->SetNext(next);
                    next->SetPrev(prev);
                }
                else
                {
                    prev->SetNext(nullptr);
                }
                delete (curr);
            }
        }
        _size--;
    }

    void DeleteHead()
    {
        dnode *curr = head;
        curr->GetNext()->SetPrev(nullptr);
        head = head->GetNext();
        delete (curr);
        _size--;
    }

    void DeleteList()
    {
        dnode *temp;
        dnode *p = head;
        while (p->GetNext() != nullptr)
        {
            temp = p->GetNext();
            delete (p);
            p = temp;
        }
        head = nullptr;
    }

    ~DoublyLinkedList()
    {
        dnode *temp;
        dnode *p = head;
        while (p->GetNext() != nullptr)
        {
            temp = p->GetNext();
            delete (p);
            p = temp;
        }
        head = nullptr;
    }
};

class mnode
{
private:
    int data;
    mnode *next;
    mnode *below;
    int row, col;

public:
    mnode()
    {
        row = 0;
        col = 0;
        data = 0;
        next = nullptr;
        below = nullptr;
    }

    mnode(int data)
    {
        row = 0;
        col = 0;
        next = nullptr;
        below = nullptr;
        this->data = data;
    }

    mnode(int data, int row, int col)
    {
        next = nullptr;
        below = nullptr;
        this->col = col;
        this->row = row;
        this->data = data;
    }

    int GetRow() { return row; }
    int GetCol() { return col; }
    int GetData() { return data; }
    mnode *GetNext() { return next; }
    mnode *GetBelow() { return below; }
    void SetRow(int row) { this->row = row; }
    void SetCol(int col) { this->col = col; }
    void SetData(int data) { this->data = data; }
    void SetNext(mnode *next) { this->next = next; }
    void SetBelow(mnode *below) { this->below = below; }
};
class LinkedListMatrix
{
private:
    mnode *head;
    int rows, cols;
    void construct(int rows, int cols, int d = 0)
    {
        this->rows = rows;
        this->cols = cols;
        mnode *end = nullptr;
        while (rows > 0)
        {
            mnode *m = new mnode(d);
            if (head == nullptr)
            {
                end = m;
                head = m;
            }
            else
            {
                end->SetNext(m);
                end = m;
            }
            rows--;
        }
        mnode *_temp;
        mnode *temp = this->head;
        while (temp != nullptr)
        {
            _temp = temp;
            for (int i = 1; i < cols; i++)
            {
                mnode *m = new mnode(d);
                _temp->SetBelow(m);
                _temp = _temp->GetBelow();
            }
            temp = temp->GetNext();
        }
        if (this->head != nullptr)
        {
            mnode *curr = this->head, *next = this->head->GetNext();
            while (next != nullptr)
            {
                mnode *temp = curr->GetBelow(), *_temp = next->GetBelow();
                while (temp != nullptr && _temp != nullptr)
                {
                    temp->SetNext(_temp);
                    temp = temp->GetBelow();
                    _temp = _temp->GetBelow();
                }
                curr = next;
                next = curr->GetNext();
            }
        }
    }

public:
    int getRows() { return rows; }
    int getCols() { return cols; }
    LinkedListMatrix() { head = nullptr; }
    LinkedListMatrix(int row, int col, int d = 0) : LinkedListMatrix() { this->construct(row, col, d); }
    LinkedListMatrix(LinkedListMatrix &l)
    {
        this->construct(l.getRows(), l.getCols());
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->set(i, j, l.get(i, j));
            }
        }
    }

    void operator=(LinkedListMatrix &l)
    {
        this->construct(l.getRows(), l.getCols());
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->set(i, j, l.get(i, j));
            }
        }
    }

    bool operator==(LinkedListMatrix &l)
    {
        if (this->rows == l.getRows() && this->cols == l.getCols())
        {
            for (int i = 0; i < this->rows; i++)
            {
                for (int j = 0; j < this->cols; j++)
                {
                    if (this->get(i, j) != l.get(i, j))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    LinkedListMatrix operator++()
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->set(i, j, (this->get(i, j) + 1));
            }
        }
        return (*this);
    }

    LinkedListMatrix operator--()
    {
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->set(i, j, (this->get(i, j) - 1));
            }
        }
        return (*this);
    }

    LinkedListMatrix operator++(int)
    {
        LinkedListMatrix l = (*this);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->set(i, j, (this->get(i, j) + 1));
            }
        }
        return l;
    }

    LinkedListMatrix operator--(int)
    {
        LinkedListMatrix l = (*this);
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this->set(i, j, (this->get(i, j) - 1));
            }
        }
        return l;
    }

    void display()
    {
        if (head != nullptr)
        {
            mnode *temp = this->head;
            while (temp != nullptr)
            {
                mnode *_temp = temp;
                while (_temp != nullptr)
                {
                    cout << _temp->GetData() << " ";
                    _temp = _temp->GetNext();
                }
                cout << endl;
                temp = temp->GetBelow();
            }
        }
        else
        {
            cout << "matrix is empty";
        }
        cout << endl;
    }

    int get(int i, int j)
    {
        try
        {
            if (i < this->rows && j < this->cols)
            {
                mnode *temp = this->head;
                for (int k = 0; k < i; k++)
                {
                    temp = temp->GetNext();
                }
                for (int k = 0; k < j; k++)
                {
                    temp = temp->GetBelow();
                }
                return temp->GetData();
            }
            else
            {
                throw "index out of bounds";
            }
        }
        catch (const char *str)
        {
            cout << str << endl;
            exit(1);
        }
    }

    void set(int i, int j, int d)
    {
        if (i < this->rows && j < this->cols)
        {
            mnode *temp = this->head;
            for (int k = 0; k < i; k++)
            {
                temp = temp->GetNext();
            }
            for (int k = 0; k < j; k++)
            {
                temp = temp->GetBelow();
            }
            temp->SetData(d);
        }
    }

    void deleteList()
    {
        mnode *row = this->head, *col;
        mnode *todelete;
        while (row != nullptr)
        {
            col = row;
            row = row->GetNext();
            while (col != nullptr)
            {
                todelete = col;
                col = col->GetBelow();
                delete (todelete);
            }
        }
        this->rows = 0;
        this->cols = 0;
        this->head = nullptr;
    }

    void reverse()
    {
        mnode *prev = nullptr, *curr = this->head, *next;
        mnode *col_prev, *col_curr, *col_prev_above, *col_prev_below;
        while (curr != nullptr)
        {
            next = curr->GetNext();
            col_prev = prev;
            col_curr = curr;
            col_prev_above = nullptr;
            while (col_curr != nullptr)
            {
                col_curr->SetNext(col_prev);
                if (col_prev != nullptr)
                {
                    col_prev_below = col_prev->GetBelow();
                    col_prev->SetBelow(col_prev_above);
                    col_prev_above = col_prev;
                    col_prev = col_prev_below;
                }
                col_curr = col_curr->GetBelow();
            }
            while (col_prev != nullptr)
            {
                col_prev_below = col_prev->GetBelow();
                col_prev->SetBelow(col_prev_above);
                col_prev_above = col_prev;
                col_prev = col_prev_below;
            }
            prev = curr;
            curr = next;
        }
        col_prev = prev;
        col_prev_above = nullptr;
        while (col_prev != nullptr)
        {
            col_prev_below = col_prev->GetBelow();
            col_prev->SetBelow(col_prev_above);
            col_prev_above = col_prev;
            col_prev = col_prev_below;
        }
        this->head = col_prev_above;
    }

    LinkedListMatrix operator+(LinkedListMatrix &l)
    {
        try
        {
            if (this->rows == l.getRows() && this->cols == l.getCols())
            {
                LinkedListMatrix l1(this->rows, this->cols);
                for (int i = 0; i < this->rows; i++)
                {
                    for (int j = 0; j < this->cols; j++)
                    {
                        l1.set(i, j, (this->get(i, j) + l.get(i, j)));
                    }
                }
                return l1;
            }
            else
            {
                throw "no. of rows and columns of first matrix should be equal to that of second matrix and vice versa to perform addition";
            }
        }
        catch (const char *str)
        {
            cout << str << endl;
            exit(1);
        }
    }

    LinkedListMatrix operator-(LinkedListMatrix &l)
    {
        try
        {
            if (this->rows == l.getRows() && this->cols == l.getCols())
            {
                LinkedListMatrix l1(this->rows, this->cols);
                for (int i = 0; i < this->rows; i++)
                {
                    for (int j = 0; j < this->cols; j++)
                    {
                        l1.set(i, j, (this->get(i, j) - l.get(i, j)));
                    }
                }
                return l1;
            }
            else
            {
                throw "no. of rows and columns of first matrix should be equal to that of second matrix and vice versa to perform substraction";
            }
        }
        catch (const char *str)
        {
            cout << str << endl;
            exit(1);
        }
    }

    LinkedListMatrix operator*(LinkedListMatrix &l)
    {
        try
        {
            if (this->cols == l.getRows())
            {
                LinkedListMatrix l1(this->rows, l.getCols());
                for (int i = 0; i < l.getCols(); i++)
                {
                    for (int j = 0; j < this->rows; j++)
                    {
                        int sum = 0;
                        for (int k = 0; k < this->cols; k++)
                        {
                            sum += (this->get(j, k) * l.get(k, i));
                        }
                        l1.set(i, j, sum);
                    }
                }
                return l1;
            }
            else
            {
                throw "no. of columns of first matrix should be equal to no. of rows of second matrix to perform multiplication";
            }
        }
        catch (const char *str)
        {
            cout << str << endl;
            exit(1);
        }
    }

    int *getDiagonalMatrix()
    {
        int *arr = new int[this->rows];
        for (int i = 0; i < this->rows; i++)
        {
            arr[i] = this->get(i, i);
        }
        return arr;
    }

    int getDiagonalSum()
    {
        int sum = 0;
        for (int i = 0; i < this->rows; i++)
        {
            sum += this->get(i, i);
        }
        return sum;
    }

    friend istream &operator>>(istream &, LinkedListMatrix &);
    friend ostream &operator<<(ostream &, LinkedListMatrix &);
    // resize, deleteRows, and deleteCols functions are incomplete
    void resize(int r, int c)
    {
        mnode *temp = head;
        while (temp != nullptr)
        {
            mnode *_temp = temp;
            if (this->cols > c)
            {
                for (int i = 1; i < c; i++)
                {
                    _temp = _temp->GetBelow();
                }
                mnode *todelete;
                _temp->SetBelow(nullptr);
                todelete = _temp->GetBelow();
                _temp = todelete;
                while (_temp != nullptr)
                {
                    todelete = _temp;
                    _temp = _temp->GetBelow();
                    delete (todelete);
                }
            }
            else
            {
                for (int i = 1; i < this->cols; i++)
                {
                    _temp = _temp->GetBelow();
                }
                for (int i = 0; i < (c - this->cols); i++)
                {
                    mnode *m = new mnode(0);
                    _temp->SetBelow(m);
                    _temp = m;
                }
            }
            temp = temp->GetNext();
        }
        temp = head;
    }

    void deleteRow(int r)
    {
        if (this->rows > r)
        {
            mnode *temp = head;
            mnode *todelete, *_temp;
            if (r == 0)
            {
                _temp = head;
                head = head->GetNext();
                while (_temp != nullptr)
                {
                    todelete = _temp;
                    _temp = _temp->GetBelow();
                    delete (todelete);
                }
                return;
            }
            for (int i = 1; i < r; i++)
            {
                temp = temp->GetNext();
            }
            _temp = temp->GetNext();
            while (temp != nullptr && _temp != nullptr)
            {
                todelete = _temp;
                temp->SetNext(_temp->GetNext());
                temp = temp->GetBelow();
                _temp = _temp->GetBelow();
                delete (todelete);
            }
            while (_temp != nullptr)
            {
                todelete = _temp;
                _temp = _temp->GetBelow();
                delete (todelete);
            }
            this->rows--;
        }
    }

    void deleteCol(int c)
    {
    }
    ~LinkedListMatrix() { this->deleteList(); }
};

istream &operator>>(istream &din, LinkedListMatrix &l)
{
    int d;
    cout << "Enter no. of rows: ";
    cin >> l.rows;
    cout << "Enter no. of columns: ";
    cin >> l.cols;
    l.construct(l.rows, l.cols);
    for (int i = 0; i < l.rows; i++)
    {
        for (int j = 0; j < l.cols; j++)
        {
            cout << "Enter Element at [" << (i + 1) << "," << (j + 1) << "]: ";
            cin >> d;
            l.set(i, j, d);
        }
    }
    return din;
}

ostream &operator<<(ostream &dout, LinkedListMatrix &l)
{
    cout << endl;
    cout << "rows: " << l.rows << endl;
    cout << "columns: " << l.cols << endl;
    for (int i = 0; i < l.rows; i++)
    {
        for (int j = 0; j < l.cols; j++)
        {
            cout << l.get(i, j) << " ";
        }
        cout << endl;
    }
    cout << endl;
    return dout;
}