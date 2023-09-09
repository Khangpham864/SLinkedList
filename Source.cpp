#include<iostream>

using namespace std;

class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
public:
    SLinkedList() : head(NULL), tail(NULL) {}
    ~SLinkedList();
    void    addHead(const int& e);
    void    addIndex(int index, const int& e);
    int     size();
    bool    empty();
    int     get(int index);
    void    set(int index, const int& e);
    void    printNode();
    void   deleteNode(int index);
public:
    class Node {
    private:
        int data;
        Node* next;
        friend class SLinkedList;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(int data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};
//! hàm hủy
SLinkedList::~SLinkedList() {
    while (head != NULL) {
        deleteNode(0); 
    }
}

//! thêm node vào đầu danh sách
void   SLinkedList::addHead(const int& e) {
    Node* temp = new Node(e, NULL);

    if (head == NULL) {
        head = temp; 
    }
    else {
        temp->next = head;
        head = temp; 
    }
}

//! thêm node vào vị trí index ,vị trí tính bằng đầu từ 0
void   SLinkedList::addIndex(int index, const int& e) {
    Node* temp = new Node(e, NULL);
    Node* previous = head;

    for (int i = 0; i < index; ++i) {
        previous = previous->next;
    }

    temp->next = previous->next;
    previous->next = temp;
}

//! trả về số lượng node
int    SLinkedList::size() {
    Node* current = head;
    int count = 0;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

//! kiểm tra xem có node nào không
bool   SLinkedList::empty() {
    if (head == NULL) {
        return true;
    }
    return false;
}

//! lấy giá trị của node ở vị trí index
int    SLinkedList::get(int index) {
    Node* current = head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

//! gán giá trí node ở vị trí index
void   SLinkedList::set(int index, const int& e) {
    Node* current = head;

    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    current->data = e;
}

//! in ra danh sách 
void   SLinkedList::printNode() {
    Node* current = head;

    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;  
}

//! xóa node ở vị trí index
void   SLinkedList::deleteNode(int index) { 
    if (head == NULL) return;  

    if (index == 0) {   
        if (head->next == NULL) {
            free(head); 
            head = NULL;
        }
        else {
            Node* temp = head;
            head = head->next;  
            free(temp); 
        }
    }
    else if (index == size() - 1) {
        Node* last = head;

        while (last->next->next != NULL) {
            last = last->next; 
        }
        free(last->next); 
        last->next = NULL;
    }
    else if (index < size()) {
        Node* previous = head;
        
        for (int i = 0; i < index - 1; ++i) { 
            previous = previous->next; 
        }

        Node* temp = previous->next; 
        previous->next = temp->next;
        free(temp);
    }
}

int main() {

    //* Tạo một danh sách liên kết trống
    SLinkedList list;

    //* Thêm các phần tử vào danh sách
    list.addHead(10);
    list.addHead(20);
    list.addHead(30);
    list.addHead(40);
    list.addHead(50);
    list.addHead(60);

    //* In danh sách
    list.printNode();
    //! 30 20 10
        //* Lấy giá trị của phần tử ở vị trí thứ 1
    int value = list.get(1);
    cout << "Giá trị của phần tử ở vị trí  1 là: " << value << endl;
    //! 20
        //* Gán giá trị cho phần tử ở vị trí thứ 2
    int number = 100;
    list.set(2, number);
    list.printNode();
    //! 30 20 100
    
    //* Xóa phần tử ở vị trí thứ 2
    list.deleteNode(2);
    list.printNode();
    //* Xóa phần tử ở vị trí thứ 4
    list.deleteNode(4);
    list.printNode();
    //* Xóa phần tử ở vị trí thứ 3
    list.deleteNode(3);
    list.printNode();
    //* Xóa phần tử ở vị trí đầu
    list.deleteNode(0);
    list.printNode();
    //* Xóa phần tử ở vị trí thứ 1
    list.deleteNode(1); 
    list.printNode();
    //* Xóa phần 
    list.deleteNode(0); 
    list.printNode();
    //! 30 20
    cout << list.size(); 
    return 0;
}