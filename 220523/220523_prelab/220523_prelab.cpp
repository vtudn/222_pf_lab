#include <iostream>

using namespace std;

/* struct node // linked list 1
{
    int data;
    node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

bool isEqual(node *head1, node *head2)
{
    // TO DO
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data != head2->data)
        {
            return false;
        }
        else
        {
            head1 = head1->next;
            head2 = head2->next;
        }
    }
    if (head1 || head2)
    {
        return false;
    }
    return true;
} */

/* struct node // linked list 2
{
    int data;
    node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

int countNode(node *head)
{
    // TODO
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
} */

/* struct node // linked list 3
{
    int data;
    node *next;
};

node *createLinkedList(int n)
{
    // TO DO
    if (n <= 0 || n >= 5000)
    {
        return NULL;
    }
    node *head = new node();
    cin >> head->data;
    head->next = NULL;
    for (int i = 1; i < n; i++)
    {
        node *new_node = new node();
        cin >> new_node->data;
        new_node->next = head;
        head = new_node;
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
} */

/* class Integer // OOP 1
{
private:
    int val;

public:
    Integer(int val) : val(val) {}
    void setValue(int val) { this->val = val; }
    int getValue() { return this->val; }
}; */

/* class ClockType // OOP 2
{
public:
    ClockType(int, int, int); // constructor with parameters
    ClockType();              // default constructor

    void printTime() const;

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
ClockType::ClockType(int hr, int min, int sec)
{
    if (hr >= 0 && hr < 24)
    {
        this->hr = hr;
    }
    if (min >= 0 && min < 60)
    {
        this->min = min;
    }
    if (sec >= 0 && sec < 60)
    {
        this->sec = sec;
    }
    else
    {
        this->hr = 0;
        this->min = 0;
        this->sec = 0;
    }
}

ClockType::ClockType() : hr(0), min(0), sec(0) {} */

/* class ClockType // OOP 3
{
public:
    ClockType();

    void setTime(int, int, int);
    void printTime() const;

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
void ClockType::setTime(int hr, int min, int sec)
{
    if (hr)
    {
        if (hr >= 0 && hr < 24)
        {
            this->hr = hr;
        }
        else
        {
            this->hr = 0;
        }
    }
    if (min)
    {
        if (min >= 0 && min < 60)
        {
            this->min = min;
        }
        else
        {
            this->min = 0;
        }
    }
    if (sec)
    {
        if (sec >= 0 && sec < 60)
        {
            this->sec = sec;
        }
        else
        {
            this->sec = 0;
        }
    }
} */

/* template <typename T> // OOP 4
class Array
{
public:
    Array(int size, T initValue);
    ~Array();

    void setAt(int idx, const T &value);
    T getAt(int idx);
    T &operator[](int idx);

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
T &Array<T>::operator[](int idx)
{
    if (idx < 0 || idx >= size)
    {
        throw -1;
    }
    return this->p[idx];
} */

/* class ClockType // OOP 5
{
public:
    ClockType(int, int, int);
    ClockType();
    void printTime() const;
    void setTime(int, int, int);

    void getTime(int &, int &, int &) const;

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
void ClockType::getTime(int &hours, int &minutes, int &seconds) const
{
    hours = this->hr;
    minutes = this->min;
    seconds = this->sec;
} */

/* class Course // OOP 6
{
private:
    int ID;
    int numOfStudent;
    int numOfTeacher;
    int numOfTA;

public:
    void getinfo();
    void disinfo();
};

void Course::getinfo()
{
    cout << "ID: ";
    cin >> ID;
    cout << "Number of Students: ";
    cin >> numOfStudent;
    cout << "Number of Teachers: ";
    cin >> numOfTeacher;
    cout << "Number of TAs: ";
    cin >> numOfTA;
}

void Course::disinfo()
{
    cout << endl;
    cout << "CourseID = " << ID << endl;
    cout << "Number of student = " << numOfStudent << endl;
    cout << "Number of teacher = " << numOfTeacher << endl;
    cout << "Number of TA = " << numOfTA << endl;
}

int main()
{
    // TODO
    int n;
    cin >> n;
    Course *arr_Course = new Course[n];
    for (int i = 0; i < n; i++)
    {
        arr_Course[i].getinfo();
    }
    for (int i = 0; i < n; i++)
    {
        arr_Course[i].disinfo();
    }
    return 0;
} */

/* class Room // OOP 7
{
private:
    float length;
    float breadth;
    float height;

public:
    Room(float l, float b, float h) : length(l), breadth(b), height(h) {}
    float calculateArea()
    {
        return length * breadth;
    }
    float calculateVolume()
    {
        return length * breadth * height;
    }
}; */

int main()
{

    cout << "\nDONE!";
    return 0;
}