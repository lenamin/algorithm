
//
//  main.cpp
//  cpp-algorithm
//
//  Created by Lena on 2023/01/31.
//

// MARK: 연결리스트

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* head;
    
public:
    LinkedList(): head(NULL) {};
    // LinkedList(): head(nullptr) {}; 이라고 사용하는 것도 선호함
    ~LinkedList()
    {
        while (!empty()) {
            pop_front();
        }
    }
    
    /// 맨 앞 원소 삽입
    void push_front(int val)
    {
        Node* new_node = new Node { val, NULL };
        
        if (head != NULL)
            new_node->next = head;
            // head가 비어있지 않으면 next 포인터가 첫번째 노드를 가리키도록 변경해준다
        head = new_node;
    };

    // 맨 앞 원소 삭제
    void pop_front()
    {
        if (head == NULL)
            return;
        
        Node* first = head;
        head = head->next;
        delete first;
    }

    void print_all()
    {
        Node* curr = head;
        
        while (curr != NULL) {
            cout << curr->data << ", ";
            
            curr = curr->next;
        }
        cout << endl;
    }

    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    LinkedList ll;
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.print_all();
    
    
    ll.pop_front(); // 30을 삭제해보자
    ll.print_all();
    
    ll.push_front(40);
    ll.print_all();
    // 끝나면 소멸자 자동으로 호출됨
    // 기존에 추가된 데이터가 하나씩 해제됨
}


