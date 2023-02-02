//
//  DoublyLinkedList.cpp
//  cpp-algorithm
//
//  Created by Lena on 2023/02/02.
//

#include<iostream>
using namespace std;

// MARK: 이중연결리스트

// 하나의 노드 구조체. 데이터를 담고 있고, prev, next 두 개의 포인터 변수를 가진다
struct Node
{
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList
{
private:
    int count;
    Node* header; // header 노드
    Node* trailer; // trailer 노드

public:
    DoublyLinkedList()
    {
        count = 0;
        header = new Node {0, NULL, NULL};
        // 값은 0으로 초기화, prev, next가 가리키는 것은 NULL
        trailer = new Node {0, NULL, NULL};
        
        header->next = trailer;
        // header의 next 가 trailer를
        trailer->prev = header;
    }

    
    void insert(Node* p, int val)
    {
        Node* new_node = new Node {val, p->prev, p};
        // p의 prev가 가리키고 있는 (header)를 new_node의 prev로 두고
        // p를 trailer 로 new_node를 동적생성
        
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        // 기존 연결을 끊고 new_node랑 연결하자
        
        count++;
    }
    
    void push_front(int val)
    {
        insert(header->next, val);
    }
    
    void push_back(int val)
    {
        insert(trailer, val);
    }
    
     void erase(Node* p)
    {
         p->prev->next = p->next;
         p->next->prev = p->prev;
         
         delete p;
         count--;
     }
    
    void pop_front()
    {
        if (!empty())
            erase(header->next);
    }
    
    void pop_back()
    {
        if (!empty())
            erase(trailer->prev);
    }
    
    void print_all()
    {
        Node* curr = header->next; // 첫 번째 노드 (header의 next가 가리키는)를 curr로
        
        while (curr != trailer) {
            cout << curr->data << ", ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    void print_reverse()
    {
        Node* curr = trailer->prev;
        
        while (curr != header) {
            cout << curr->data << ", ";
            curr = curr->prev;
        }
        cout << endl;
    }
    
    bool empty()
    {
        return count == 0;
    }
    
    int size()
    {
        return count;
    }
    
    ~DoublyLinkedList()
    {
        while (!empty()) {
            pop_front();
        }
        delete header;
        delete trailer;
    }
};

int main()
{
    DoublyLinkedList ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);
    ll.print_all();
    ll.print_reverse();
    
    ll.pop_front();
    ll.pop_back();
    ll.print_all();
    
    ll.push_front(100);
    ll.push_back(400);
    ll.print_all();
}

