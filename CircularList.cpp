#ifndef CIRCULAR_LIST_CPP
#define CIRCULAR_LIST_CPP

#include "CircularList.h"

template <typename T>
CircularList<T>::CircularList() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
CircularList<T>::~CircularList() {
    clear();
}

template <typename T>
void CircularList<T>::add(T item) {
    Node<T>* newNode = new Node<T>(item);
    if (isEmpty()) {
        head = tail = newNode;
        newNode->next = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
    size++;
}

template <typename T>
void CircularList<T>::remove(int index) {
    if (isEmpty() || index < 0 || index >= size) return;

    Node<T>* current = head;

    if (size == 1) {
        delete head;
        head = tail = nullptr;
    }
    else if (index == 0) {
        head = head->next;
        tail->next = head;
        delete current;
    }
    else {
        Node<T>* previous = nullptr;
        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        if (index == size - 1) tail = previous;
        delete current;
    }
    size--;
}

template <typename T>
T CircularList<T>::search(int index) const {
    if (isEmpty() || index < 0 || index >= size) return T();

    Node<T>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

template <typename T>
T CircularList<T>::searchByBrand(const string& targetBrand) const {
    if (isEmpty()) return T();
    
    Node<T>* current = head;
    for (int i = 0; i < size; i++) {
        if (current->data->getBrand() == targetBrand) {
            return current->data;
        }
        current = current->next;
    }
    return T();
}

template <typename T>
void CircularList<T>::clear() {
    if (isEmpty()) return;

    Node<T>* current = head;
    tail->next = nullptr;

    while (current != nullptr) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    head = tail = nullptr;
    size = 0;
}

template <typename T>
int CircularList<T>::getSize() const { return size; }

template <typename T>
bool CircularList<T>::isEmpty() const { return size == 0; }


template <typename T>
void CircularList<T>::printTable() const {
    if (isEmpty()) {
        cout << "[Ring is empty]\n";
        return;
    }

    Node<T>* current = head;
    for (int i = 0; i < size; i++) {
        // Печатаем шапку перед первым элементом
        if (i == 0) {
            current->data->printTableHeader();
        }

        // Выводим ID + сам объект через его собственный operator<<
        cout << left << setw(5) << (i + 1) << *(current->data) << "\n";

        current = current->next;
    }
    cout << "======================================================================================================\n";
}

#endif // CIRCULAR_LIST_CPP