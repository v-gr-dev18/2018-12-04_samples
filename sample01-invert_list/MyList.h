// https://github.com/v-gr-dev18/2018-12-04_samples/blob/master/sample01-invert_list/MyList.h
// Класс MyList
//============================================================================================================
#ifndef _MYLIST_H_
#define _MYLIST_H_
#include <functional>
#include "invert_list.h"

template<typename T> class MyList;
template<typename T> struct MyListNode;
template<typename T> struct MyListNode
{    T value;
     friend class MyList<T>;
     friend void invert_list<T, MyListNode<T>>(MyListNode<T>* &);
private:
     MyListNode* next;
     MyListNode(const T& v0, MyListNode* n0=nullptr) :value(v0), next(n0) {};
     ~MyListNode(void){};
};

template<typename T> class MyList {
private:
    MyListNode<T>* first;
    MyListNode<T>* last;
public:
    MyList() : first(nullptr), last(nullptr) {};
    MyList& add(const T&);
    void clear(void);
    MyList& invert(void);
    void for_each(std::function<void(const T&)>);
    ~MyList() { clear(); };
};

template<typename T> void MyList<T>::clear(void) {
    while (first != nullptr){
        MyListNode<T>* current = first;
        first = first->next;
        delete current;
    }
    last = nullptr;
}

template<typename T> MyList<T>& MyList<T>::add(const T& v) {
    MyListNode<T>* newbie = new  MyListNode<T>(v);
    if (last)
        last->next = newbie;
    else 
        first = newbie;
    last = newbie;
    return *this;
}

template<typename T>
void MyList<T>::for_each(std::function<void(const T&)> f)
{
    for (const MyListNode<T>* current = first; current != nullptr; current = current->next)
      f(current->value);
}

template<typename T>
MyList<T>& MyList<T>::invert(void) {
    auto old_first = first;
    last = nullptr;
    invert_list<T,MyListNode<T>>(first);
    last = old_first;
    return *this;
};

#endif
