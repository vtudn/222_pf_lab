// Vào một ngày đẹp trời, thần rượu nho Dionysus quyết định tổ chức sẽ một buổi tiệc linh đình và ra lệnh cho vua Midas thực hiện việc tiếp tân theo danh sách do thần đưa xuống. Thần Dionysus gửi cho vua Midas 2 danh sách khách mời, một là danh sách khách thông thường gồm tên một số con người; hai là danh sách khách vip gồm tên các vị thần. Nhiệm vụ của vua Midas là trong lúc diễn ra buổi tiệc, vua Midas phải lập 2 danh sách khách đến tham dự buổi tiệc để gửi lại cho Dionysus.
// Đồng thời, không cho phép khách không mời bước vào buổi tiệc. Do buổi tiệc diễn ra nhiều ngày đêm, có những vị khách có thể ra về rồi trở lại tiếp tục tham dự tiệc; trong trường hợp này, tên vị khách không cần thêm lại vào danh sách dự tiệc.

// Hãy hỗ trợ vua Midas thực hiện công việc của mình bằng cách thực hiện theo các yêu cầu sau:

// Cho 2 mảng string global chứa tên (1 từ tiếng Anh) các vị khách; biết cả 2 mảng này đều kết thúc bằng phần tử string "end".

// _ Mảng thứ nhất guessList chứa tên khách thông thường.

// _ Mảng thứ hai vipList chứa tên khách Vip.

// Lưu ý: Tên của mỗi vị khách là độc nhất.

// Tạo class Guess gồm string name và int ID; Constructor và một hàm print(). (Cách in tham khảo trong example)

// Tạo class Vip kế thừa từ class Guess và có thêm thuộc tính int level; Constructor và một hàm print(). (Cách in tham khảo trong example)

// Tạo một template class Node để phục vụ cho việc tạo danh sách liên kết

// Tạo một template class entranceList để có thể làm linked list cho 2 nhóm khách trên (cách tổ chức linked list tùy ý sinh viên) và tối thiểu có con trỏ head; hàm add() (vào cuối list); hàm size(); hàm printList(). (Cách in tham khảo trong example)

// Hàm checkguess(string,entranceList<Guess>&,entranceList<Vip>&) để kiểm tra và đưa khách vào danh sách vào cổng theo kiểu phù hợp.

// + ID của các vị khách sẽ là index vị trí của họ trong mảng phù hợp

// + level của khách vip sẽ là ID/5+1

// TEST CASES:

// entranceList<Guess> GL;
// entranceList<Vip> VL;
// int n;
// cin>>n;  
// for(int i=0;i<n;i++){
// string input;
// cin>>input;
// checkGuess(input,GL,VL);
// }
// GL.printList();
// VL.printList();

// This list included 4 guess(es):
// Guess number: 0 Name: Adam
// Guess number: 1 Name: Eve
// Guess number: 5 Name: David
// Guess number: 7 Name: Sheba

// entranceList<Guess> GL;
// entranceList<Vip> VL;
// int n;
// cin>>n;  
// for(int i=0;i<n;i++){
// string input;
// cin>>input;
// checkGuess(input,GL,VL);
// }
// GL.printList();
// VL.printList();

// This list included 5 guess(es):
// Vip number: 2 Level: 1 Name: Odin
// Vip number: 8 Level: 2 Name: Ganesha
// Vip number: 1 Level: 1 Name: Hera
// Vip number: 4 Level: 1 Name: Hades
// Vip number: 3 Level: 1 Name: Shiva

// entranceList<Guess> GL;
// entranceList<Vip> VL;
// int n;
// cin>>n;  
// for(int i=0;i<n;i++){
// string input;
// cin>>input;
// checkGuess(input,GL,VL);
// }
// GL.printList();
// VL.printList();

// This list included 2 guess(es):
// Guess number: 0 Name: Adam
// Guess number: 1 Name: Eve
// This list included 2 guess(es):
// Vip number: 2 Level: 1 Name: Odin
// Vip number: 5 Level: 2 Name: Thor

#include <iostream>
#include <string>

using namespace std;

class Guess
{
protected:
    string name;
    int ID;

public:
    Guess() = default;
    Guess(string name, int ID)
    {
        this->name = name;
        this->ID = ID;
    }
    void print()
    {
        cout << "Guess number: " << this->ID << " Name: " << this->name << "\n";
    }
};

class Vip : public Guess
{
protected:
    int level;

public:
    Vip() = default;
    Vip(string name, int ID, int level)
    {
        this->name = name;
        this->ID = ID;
        this->level = level;
    }
    void print()
    {
        cout << "Vip number: " << this->ID << " Level: " << this->level << " Name: " << this->name << "\n";
    }
};

template <typename T>
class entranceList
{
public:
    class Node;

protected:
    // T *guess;
    Node *head;
    Node *tail;
    int cnt;

public:
    entranceList()
    {
        this->head = this->tail = NULL;
        this->cnt = 0;
    }
    ~entranceList()
    {
        while (this->head != NULL)
        {
            Node *temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
    }
    void add()
    {
    }
    int size()
    {
        return this->cnt;
    }
    void printList()
    {
        cout << "This list included " << this->cnt << " guess(es):\n";
        while (this->head != NULL)
        {
            this->head->data->print();
        }
    }

    class Node
    {
    protected:
        T *data;
        Node *next;
        friend class entranceList<T>;

    public:
        Node()
        {
            this->next = NULL;
        }
        Node(T *data, Node *next)
        {
            this->data = data;
            this->next = next;
        }
    };
};

void checkGuess(string input, entranceList<Guess> &GL, entranceList<Vip> &VL)
{
}

int main()
{
    entranceList<Guess> GL;
    entranceList<Vip> VL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        checkGuess(input, GL, VL);
    }
    GL.printList();
    VL.printList();
    cout << "DONE!\n";
    return 0;
}