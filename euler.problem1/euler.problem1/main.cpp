//
//  main.cpp
//  euler.problem1
//
//  Created by Piotr Stanczyk on 1/4/19.
//  Copyright © 2019 Piotr Stanczyk. All rights reserved.
//

// https://projecteuler.net/problem=1

/**
 Problem 1
 If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 
 Find the sum of all the multiples of 3 or 5 below 1000.
 **/

#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {


    std::cout << "Euler Problem #1\n";
    
    int sum = 0;
    for (int i=0; i<10; i++) {
        
        if (i % 3 ==0 || i % 5 == 0) {
            cout << i << endl;
            sum += i;
        }
    }
    
    cout << "sum" << sum << endl;
    return 0;
}
