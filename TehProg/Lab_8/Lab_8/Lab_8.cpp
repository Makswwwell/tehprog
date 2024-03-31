#include <iostream>
#include <stdexcept>

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    ListNode(T val) : data(val), next(nullptr) {}
};

template <typename T>
class List {
private:
    ListNode<T>* head;
    int size;

public:
    List() : head(nullptr), size(0) {}

    ~List() {
        while (head != nullptr) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(T val) {
        ListNode<T>* newNode = new ListNode<T>(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            ListNode<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        ListNode<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }

    List<T> operator+(const List<T>& other) {
        List<T> result = *this;
        if (result.head == nullptr) {
            result.head = other.head;
        }
        else {
            ListNode<T>* temp = result.head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = other.head;
        }
        result.size += other.size;
        return result;
    }

    bool operator==(const List<T>& other) const {
        if (size != other.size) {
            return false;
        }
        ListNode<T>* temp1 = head;
        ListNode<T>* temp2 = other.head;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->data != temp2->data) {
                return false;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }

    void print() const {
        ListNode<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    List<int> list1;
    list1.push_back(1);
    list1.push_back(2);
    list1.push_back(3);

    List<int> list2;
    list2.push_back(4);
    list2.push_back(5);
    list2.push_back(6);

    List<int> concatenatedList = list1 + list2;
    std::cout << "Concatenated List: ";
    concatenatedList.print();

    if (list1 == list2) {
        std::cout << "Lists are equal\n";
    }
    else {
        std::cout << "Lists are not equal\n";
    }

    return 0;
}
