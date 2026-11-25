//#ifndef CIRCULAR_LIST_H
//#define CIRCULAR_LIST_H
//
//#include <iostream>
//#include <iomanip>
//#include <string>
//
//using namespace std;
//
//template <typename T>
//class Node {
//public:
//    T data;
//    Node* next;
//    Node(T val) : data(val), next(nullptr) {}
//};
//
//
//template <typename T>
//class CircularList;
//
//template <typename T>
//ostream& operator<<(ostream& os, const CircularList<T>& list);
//
//template <typename T>
//class CircularList {
//private:
//    Node<T>* head;
//    Node<T>* tail;
//    int size;
//
//public:
//    CircularList();
//    ~CircularList();
//
//    void add(T item);
//    void remove(int index);
//    T search(int index) const;
//
//    // Метод поиска по бренду
//    T searchByBrand(const string& targetBrand) const;
//
//    void clear();
//    int getSize() const;
//    bool isEmpty() const;
//
//    friend ostream& operator<< <T>(ostream& os, const CircularList<T>& list);
//};
//
//#include "CircularList.cpp"
//
//#endif // CIRCULAR_LIST_H

#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <iostream>
#include <stdexcept>
#include <iomanip>

using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class CircularList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    CircularList();
    ~CircularList();

    void add(T item);
    void remove(int index);
    T search(int index) const;
    T searchByBrand(const string& targetBrand) const;
    void clear();
    int getSize() const;
    bool isEmpty() const;


    void printTable() const;
};

#include "CircularList.cpp"
#endif // CIRCULAR_LIST_H