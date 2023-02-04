//
//  LinkedListTemplate.cpp
//  cpp-algorithm
//
//  Created by Lena on 2023/02/04.
//

#include<iostream>
using namespace std;

// MARK: 향상된 이중연결리스트

template <typename T>
struct Node
{
    T data;
    Node* prev;
    Node* next;
};

template <typename T>
class DoublyLinkedList
{
private:
    int count;
    Node<T>* header; // header 노드
    Node<T>* trailer; // trailer 노드

public:
    // 중첩 클래스 형태로 iterator 클래스 생성
    class iterator
    {
    private:
        Node<T>* ptr;

    public:
        iterator() : ptr(NULL) {}
        // 기본 생성자 (ptr을 NULL로 초기화함)
        
        iterator(Node<T>* p) : ptr(p) {}
        // 노드에 포인터를 전달받을 경우, 해당 p값을 이용해 ptr 멤버변수를 초기화한다

        T& operator*() { return ptr->data; }
        // 연산자 오버로딩 함수
        // 실질적으로 우리가 사용할 것은 노드 안에 있는 데이터이므로 data 멤버를 참조형태로 반환하도록 함


        /// 단항 증감연산자
        iterator& operator++() // 사용: ++it
        {
            ptr = ptr->next;
            // ptr의 위치를 ptr의 next를 가리키도록 하고
            return *this; // 자기 자신의 참조형태를 반환하도록 함
        }

        iterator& operator--() // 사용: --it
        {
            ptr = ptr->prev;
            return *this;
        }
        
        // 비교연산자 오퍼레이터 재정의 함수
        bool operator==(const iterator& it)
        {
            return ptr == it.ptr;
            // 해당 포인터와 같은 위치를 가리키는지 확인한다
        }
        
        bool operator!=(const iterator& it)
        {
            return ptr != it.ptr;
            // 해당 포인터와 다른 위치를 가리키는지 확인
        }
        

        
        friend class DoublyLinkedList;
        // DoublyLinkedList에서 iterator 클래스 안에 선언되어 있는 멤버변수에 (Node* ptr) 편하게 접근할 수 있도록 정의한 것
};
    DoublyLinkedList()
    {
        count = 0;
        header = new Node<T> {T(), NULL, NULL};
        // 값은 0으로 초기화, prev, next가 가리키는 것은 NULL
        trailer = new Node<T> {T(), NULL, NULL};
        
        header->next = trailer;
        // header의 next 가 trailer를
        trailer->prev = header;
    }

    ~DoublyLinkedList()
    {
        while (!empty()) {
            pop_front();
        }
        delete header;
        delete trailer;
    }
    
    void insert(const iterator& pos, const T& val)
    {
        Node<T>* curr = pos.ptr;
        Node<T>* new_node = new Node<T> {val, curr->prev, curr};

        
        new_node->prev->next = new_node;
        new_node->next->prev = new_node;
        // 기존 연결을 끊고 new_node랑 연결하자
        
        count++;
    }
    
    void push_front(const T& data)
    {
        insert(begin(), data);
    }
    
    void push_back(const T& data)
    {
        insert(end(), data);
        
    }
    
     void erase(const iterator& pos)
    {
         Node<T>* curr = pos.ptr;
         curr->prev->next = curr->next;
         curr->next->prev = curr->prev;
         
         delete curr;
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
    
    iterator find(const T& val)
    {
        Node<T>* curr = header->next;
        // header의 next를 curr 포인터 변수로 설정
        
        while (curr->data != val && curr != trailer)
            curr = curr->next;
            // 같지 않으면 그 다음위치로 가서 비교함
            // trailer 위치로 가게되면 while loop를 만나게 된다

        return iterator(curr);
        // 찾았을 경우, 마지막까지 가도 찾지 못했을 경우 -> trailer 인지 아닌지 확인할 필요가 있다
        // find()함수가 반환한 반복자가 end()함수가 반환한 반복자와 같지는 않은지 check할 것
        // (같으면 끝까지 가도 같은 것을 못찾은 것이니까)
    }
    
    void print_all()
    {
        Node<T>* curr = header->next; // 첫 번째 노드 (header의 next가 가리키는)를 curr로
        
        while (curr != trailer) {
            cout << curr->data << ", ";
            curr = curr->next;
        }
        cout << endl;
    }
    
    void print_reverse()
    {
        Node<T>* curr = trailer->prev;
        
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
    
    iterator begin() const
    {
        return iterator(header->next);
    }
    
    iterator end() const
    {
        return iterator(trailer);
    }
    

};

int main()
{
    DoublyLinkedList<int> ll;
    ll.push_back(10);
    ll.push_back(20);
    ll.push_back(30);

    // ll: header -> 10 -> 20 -> 30 -> trailer

    auto it = ll.find(20);
    if (it != ll.end())
        ll.insert(it, 50);

    // ll: header -> 10 -> 50 -> 20 -> 30 -> trailer

    for (const auto& a : ll)
        cout << a << ", ";
    cout << endl;
}
