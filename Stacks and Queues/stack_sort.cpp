#include <iostream>
#include "stack.h"

template <class T>
void stack_sort(Stack<T>& st) {
    Stack<T> tmp1;
    Stack<T> tmp2;
    bool flag = true;
    while(flag) {
        while(!st.is_empty()) {
            if(st.top() != st.min() && !st.is_empty()) {
               tmp1.push(st.pop());
            }
            else if(st.top() == st.min() && !st.is_empty()){
                tmp2.push(st.pop());
            }
            else {
                st.pop();
            }
        }
        if(st.is_empty() && tmp1.is_empty() ) {
            flag = false;
            break;
        }
        while (!tmp1.is_empty()) {
            if(tmp1.top() != tmp1.min() && !tmp1.is_empty()) {
               st.push(tmp1.pop());
            }
            else if(tmp1.top() == tmp1.min() && !tmp1.is_empty()){
                tmp2.push(tmp1.pop());
            }
            else{
                tmp1.pop();
            }
        }
    }
    while(!tmp2.is_empty()) {
        st.push(tmp2.pop());
    }
}

int main() {

    Stack<int> st1;
    st1.push(55);
    st1.push(33);
    st1.push(111);
    st1.push(155);
    st1.push(8);
    st1.push(147);
    st1.push(190);
    stack_sort(st1);
    std::cout<<st1.top();

}