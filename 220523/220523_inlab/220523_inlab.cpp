#include <iostream>
#include <string.h>

using namespace std;

/* struct node // linked list 1
{
    int data;
    node *next;
};

node *createLinkedList(int n)
{
    // TO DO
    node *head = new node();
    cin >> head->data;
    head->next = NULL;
    node *tail = head;

    while ((n - 1) > 0)
    {
        node *new_node = new node();
        cin >> new_node->data;
        new_node->next = NULL;
        tail->next = new_node;
        tail = new_node;
        // delete new_node;
        n--;
    }

    return head;
}

void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

int main()
{
    int n = 0;
    cin >> n;
    if (n > 0)
    {
        node *head = createLinkedList(n);
        print(head);
    }
    else
    {
        cout << "Invalid n" << endl;
    }
    return 0;
} */

/* struct node // linked list 2
{
    int data;
    node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

// additional
int size_of_Linked_List(node *head)
{
    int size_of_LL = 0;
    while (head != NULL)
    {
        size_of_LL++;
        head = head->next;
    }
    return size_of_LL;
}

node *insertNode(node *head, node *newNode, int position)
{
    // TO DO
    if (position > 0)
    {
        int size_of_LL = size_of_Linked_List(head);
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
        }
        else if (position > size_of_LL)
        {
            node *tail = head;
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            node *prev = head;
            while ((position - 1) > 1)
            {
                prev = prev->next;
                position--;
            }
            node *newNext = prev->next;
            prev->next = newNode;
            newNode->next = newNext;
        }
    }
    return head;
}

void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

int main()
{
    int n = 0;
    cin >> n;
    node *head = createLinkedList(n);
    node *newNode = new node();
    cin >> newNode->data;
    int position = 0;
    cin >> position;
    head = insertNode(head, newNode, position);
    print(head);
    return 0;
} */

/* struct node // linked list 3
{
    int data;
    node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

// additional
int size_of_Linked_List(node *head)
{
    int size_of_LL = 0;
    while (head != NULL)
    {
        size_of_LL++;
        head = head->next;
    }
    return size_of_LL;
}

void replace(node *head, int position, int value)
{
    // TODO
    int size_of_LL = size_of_Linked_List(head);
    if (position >= 0 && position < size_of_LL)
    {
        node *cur = head;
        while (position > 0)
        {
            cur = cur->next;
            position--;
        }
        cur->data = value;
    }
}

void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n = 0;
    cin >> n;
    node *head = createLinkedList(n);
    print(head);
    int pos, val;
    cin >> pos >> val;
    replace(head, pos, val);
    print(head);
    return 0;
} */

/* struct node // linked list 4
{
    int data;
    node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

int searchLinkedList(node *head, int key)
{
    // TODO
    int pos = 0;
    while (head != NULL)
    {
        if (head->data == key)
            return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

int main()
{
    int n = 0;
    cin >> n;
    node *head = createLinkedList(n);
    print(head);
    int m;
    cin >> m;
    cout << searchLinkedList(head, m);
    return 0;
} */

/* class ClockType // OOP 1
{
public:
    void setTime(int, int, int);
    bool equalTime(const ClockType &) const;
    ClockType(int, int, int);
    ClockType();

private:
    int hr;
    int min;
    int sec;
};

// TODO
bool ClockType::equalTime(const ClockType &newClock) const
{
    if (newClock.hr == this->hr && newClock.min == this->min && newClock.sec == this->sec)
        return true;
    else
        return false;
} */

/* template <typename T> // OOP 2
class Array
{
public:
    Array(int size, T initValue);
    ~Array();
    void print();

    Array(const Array<T> &other); // Copy Constructor

private:
    int size;
    T *p;
};

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < this->size; ++i)
    {
        cout << (i > 0 ? " " : "") << this->p[i];
    }
    cout << endl;
}

// TODO
template <typename T>
Array<T>::Array(const Array<T> &other)
{
    this->size = other.size;
    this->p = new T[this->size];
    for (int i = 0; i < this->size; ++i)
    {
        this->p[i] = other.p[i];
    }
} */

/* template <class T> // OOP 3
class Cell
{
protected:
    T infor;

public:
    void set(T _infor) { this->infor = _infor; };
    T get() { return this->infor; };
};

enum Color
{
    White,
    Yellow,
    Black,
    Red,
    Blue
};

// TODO
template <class T>
class ColoredCell : public Cell<T>
{
protected:
    Color clr;

public:
    void setColor(Color clr) { this->clr = clr; };
    T getColor() { return this->clr; };
    T *get()
    {
        if (this->clr == 0)
            return NULL;
        else
            return &(this->infor);
    }
};

int main()
{
    int test, c;
    cin >> test >> c;
    ColoredCell<int> *a = new ColoredCell<int>();
    switch (test)
    {
    case 1:
        a->setColor(Color(c));
        cout << int(a->getColor());
        break;
    case 2:
        a->setColor(Color(c));
        a->set(10);
        if (a->get() == NULL)
            cout << "null" << endl;
        else
            cout << *(a->get());
    default:
        break;
    }
    return 0;
} */

/* class ClockType // OOP 4
{
public:
    void setTime(int, int, int);
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    ClockType(int, int, int);
    ClockType();

private:
    int hr;
    int min;
    int sec;
};

void ClockType::printTime() const
{
    if (hr < 10)
        cout << "0";
    cout << hr << ":";
    if (min < 10)
        cout << "0";
    cout << min << ":";
    if (sec < 10)
        cout << "0";
    cout << sec;
}

// TODO
void ClockType::incrementSeconds()
{
    this->sec++;
    if (sec >= 60)
    {
        sec = 0;
        incrementMinutes();
    }
}

void ClockType::incrementMinutes()
{
    this->min++;
    if (min >= 60)
    {
        min = 0;
        incrementHours();
    }
}

void ClockType::incrementHours()
{
    this->hr++;
    if (hr >= 24)
    {
        hr = 0;
    }
} */

/* class Book // OOP 5
{
    char *name;

public:
    Book(const char *);
    ~Book();

    void display();
    char *getName();
};

void Book::display()
{
    cout << "Book: " << this->name << endl;
}

char *Book::getName()
{
    return this->name;
}

// TODO: Book and ~Book
Book::Book(const char *book_name)
{
    // string book_name_str(book_name);
    this->name = new char[strlen(book_name) + 1];
    strcpy(this->name, book_name);
}

Book::~Book()
{
    delete[] name;
} */

/* template <typename T> // OOP 6
class Array
{
public:
    Array(int size, T initValue);
    ~Array();
    void print();

private:
    int size;
    T *p;
};

// TODO
template <typename T>
Array<T>::Array(int size, T initValue)
{
    this->size = size;
    this->p = new T[this->size];
    for (int i = 0; i < this->size; ++i)
    {
        this->p[i] = initValue;
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] p;
} */

/* // TODO
class Integer // OOP 7
{
private:
    int val;

public:
    Integer(int);
    Integer(Integer *);
    Integer operator+(const Integer &other);
    Integer operator+(int num);
    void print();
};

Integer::Integer(int val)
{
    this->val = val;
}

Integer::Integer(Integer *newInteger)
{
    this->val = newInteger->val;
}

Integer Integer::operator+(const Integer &other)
{
    return Integer(this->val + other.val);
}

Integer Integer::operator+(int num)
{
    return Integer(this->val + num);
}

void Integer::print()
{
    cout << this->val << endl;
}

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    Integer a(x);
    Integer b(y);
    Integer *t = new Integer(z);
    Integer c(t);

    a.print();
    b.print();
    (a + b + c + 4).print();

    delete t;
    return 0;
} */

/* template <typename T> // OOP 8
class Array
{
public:
    Array(int size, T initValue);
    ~Array();

    Array(const Array<T> &other);               // Copy constructor
    Array<T> &operator=(const Array<T> &other); // Copy assignment operator

    void print();

private:
    int size;
    T *p;
};

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < this->size; ++i)
    {
        cout << (i > 0 ? " " : "")
             << this->p[i];
    }
    cout << endl;
}

// TODO
template <typename T>
Array<T>::Array(const Array<T> &other)
{
    this->size = other.size;
    this->p = new T[this->size];
    for (int i = 0; i < this->size; ++i)
    {
        this->p[i] = other.p[i];
    }
    cout << "Call copy constructor\n";
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this == &other)
    {
        return *this;
    }
    delete[] p;
    this->size = other.size;
    this->p = new T[this->size];
    for (int i = 0; i < this->size; ++i)
    {
        this->p[i] = other.p[i];
    }
    cout << "Call assignment operator\n";
    return *this;
} */

int main()
{

    std::cout << "Done!\n";
    return 0;
}