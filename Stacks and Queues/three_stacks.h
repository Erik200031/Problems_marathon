#ifndef T_STACK
#define T_STACK

template <class T>
class T_stack {

public:
    T_stack();
    ~T_stack();
    void push_1(T);
    void push_2(T);
    void push_3(T);
    T pop_1();
    T pop_2();
    T pop_3();
    T top_1();
    T top_2();
    T top_3();
    bool is_empty(short stack_index);
private:
    T* arr;
    int size_1;
    int size_2;
    int size_3;
    int capacity_1;
    int capacity_2;
    int capacity_3;
};

template <class T>
T_stack<T>::T_stack():
size_1(0), size_2(1000), size_3(2000),
capacity_1(1000), capacity_2(2000), capacity_3(3000) 
{
    arr = new T[3000];
}

template <class T>
T_stack<T>::~T_stack() {
    delete[] arr;
    arr = nullptr;
}

template <class T>
void T_stack<T>::push_1(T element) {
    if(size_1 >= capacity_1) {
        std::cout << "Stack_1 overflow";
        return;
    }
    arr[size_1] = element;
    size_1++;
}

template <class T>
void T_stack<T>::push_2(T element) {
    if(size_2 >= capacity_2) {
        std::cout << "Stack_2 overflow";
        return;
    }
    arr[size_2] = element;
    size_2++;
}

template <class T>
void T_stack<T>::push_3(T element) {
    if(size_3 >= capacity_3) {
        std::cout << "Stack_3 overflow";
        return;
    }
    arr[size_3] = element;
    size_3++;
}

template <class T>
T T_stack<T>::pop_1() {
    if(size_1 <= 0) {
        std::cout << "Error out of range";
        return;
    }
    size_1--;
    return arr[size_1];
}

template <class T>
T T_stack<T>::pop_2() {
    if(size_2 <= capacity_1) {
        std::cout << "Error out of range";
        return -1;
    }
    size_2--;
    return arr[size_2];
}

template <class T>
T T_stack<T>::pop_3() {
    if(size_3 <= capacity_2) {
        std::cout << "Error out of range";
        return -1;
    }
    size_3--;
    return arr[size_3];
}

template <class T>
T T_stack<T>::top_1() {
    return arr[size_1-1];
}

template <class T>
T T_stack<T>::top_2() {
    return arr[size_2-1];
}

template <class T>
T T_stack<T>::top_3() {
    return arr[size_3-1];
}

template <class T>
bool T_stack<T>::is_empty(short stack_index) {
    if(stack_index == 1) {
        if(size_1 >= 0) {
            return true;
        }
        else {
            return false;
        }
    }
    else if(stack_index == 2) {
        if(size_2 >= 1000) {
            return true;
        }
        else {
            return false;
        }
    }
    else if(stack_index == 3) {
        if(size_3 >= 2000) {
            return true;
        }
        else {
            return false;
        }
    }
    return false;
}



#endif //T_STACK