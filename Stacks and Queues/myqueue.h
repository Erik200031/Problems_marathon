#ifndef MY_QUEUE_H
#define MY_QUEUE_H
#include "stack.h"

template <class T>
class My_Queue {
public:
    My_Queue () :m_size (0) {}
    void push_back(T);
    T pop_front();
    int size();
    bool is_empty();
private:
    Stack<T> m_st1;
    Stack<T> m_st2;
    int m_size;
};

template <class T>
void My_Queue<T>::push_back(T element) {
    m_st2.push(element);
    m_size++;
}

template <class T>
bool My_Queue<T>::is_empty() {
    if(size == 0) {
        return true;
    }
    return false;
}

template <class T>
int My_Queue<T>::size() {
    return m_size;
}


template <class T>
T My_Queue<T>::pop_front() {
    int tmp = m_size - 1;
    while(tmp) {
        m_st1.push(m_st2.pop());
        tmp--;
    }
    m_size--;
    T tmpp = m_st2.pop();
    tmp = m_size;
    while(tmp) {
    m_st2.push(m_st1.pop());
    tmp--;
    }
    return tmpp;
}



#endif //MY_QUEUE_H