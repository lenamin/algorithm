//
//  Sorting.cpp
//  cpp-algorithm
//
//  Created by Lena on 2023/02/10.
//

#include <algorithm>
#include <iostream>

using namespace std;

void bubble_sort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        // 여기 i는 정렬된 원소들의 위치겠지
        
        for (int j = n - 1; j > i; j--)
            // 여기의 j는 가장 끝 쪽부터 앞으로 가면서 바로 이전 값과 비교하기 위한 j
            if (data[j] < data[j-1]) {
                swap(data[j], data[j-1]);
            }
    }
}

void selection_sort(int data[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int index = i;
        
        for (int j = i + 1; j < n; j++) {
            if (data[j] < data[index]) {
                // index는 항상 가장 작은 값이 들어와야 하는 곳
                // 그런데 index에 있는 값보다 더 작은걸 찾았다?
                // 그럼 그걸 다시 index에 넣어야겠지
                index = j;
            }
        }
        swap(data[i], data[index]);
        // 가장 작은 값을 찾았으면 정렬할 위치의 값과 바꾼다
    }
}

void insertion_sort(int data[], int n)
{
    for (int i = 1; i < n - 1; i++) {
        int key = data[i];
        // 가리키고 있는 원소를 임시로 복사해둘 키
        int j = i - 1;
        // 정렬된 원소와 비교하기 위한 변수
        
        while (j >= 0 && data[i] > key) {
            data[i+1] = data[i];
            j--;
        }
    }
}

int main()
{
    int data[] = {4, 2, 6, 89, 3, 1};
    
    bubble_sort(data, 6);
    cout << "bubble sort: ";
    for (auto n : data)
        cout << n << ", ";
    cout << endl;
    
    selection_sort(data, 6);
    
    cout << "selection sort: ";
    for (auto n : data)
        cout << n << ", ";
    cout << endl;
    
    insertion_sort(data, 6);
    cout  << "insertion sort: ";
    for (auto n : data)
        cout << n << ", ";
    cout << endl;
    
}
