/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   CQueue.hpp
 * Author: panzd
 *
 * Created on November 4, 2016, 10:31 AM
 */

#ifndef CQUEUE_HPP
#define CQUEUE_HPP

#include <stack>

using namespace std;

template<typename T> class CQueue
{
public:
      CQueue(){};
      ~CQueue() {}
 
      void appendTail(const T& node); // append a element to tail
      T deleteHead();               // remove a element from head
 
private:
     stack<T> m_stack1;
     stack<T> m_stack2;
};

template<typename T> 
void CQueue<T>::appendTail(const T& node)
{
    while (!m_stack2.empty()) {
	m_stack1.push(m_stack2.top());
	m_stack2.pop();
    }

    m_stack1.push(node);
}

template<typename T> 
T CQueue<T>::deleteHead()
{
    while(m_stack1.size() > 1) {
	m_stack2.push(m_stack1.top());
	m_stack1.pop();
    }

    T v;
    if (!m_stack1.empty()) {
    	v = m_stack1.top();
    	m_stack1.pop();
    } else {
	v = m_stack2.top();
	m_stack2.pop();
    }
   
    return v;
}

#endif /* CQUEUE_HPP */

