/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: panzd
 *
 * Created on November 4, 2016, 9:48 AM
 */

#include <cstdlib>
#include <iostream>
#include "CQueue.hpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    CQueue<int> q;
    
    q.appendTail(1);
    q.appendTail(2);
    q.appendTail(3);

    cout << q.deleteHead();
    cout << q.deleteHead();
    cout << q.deleteHead();
    cout <<"hello,world";
    
    return 0;
}

