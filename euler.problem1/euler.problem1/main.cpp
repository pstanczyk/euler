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

    const int iterationLimit = 1000;
    int sum = 0;
    
    // reference implementation
    auto start = std::chrono::system_clock::now();
    for (int i=0; i<iterationLimit; i++) {

        if (i % 3 ==0 || i % 5 == 0) {
            sum += i;
        }
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;

    cout << "reference implemention : sum " << sum << " time : " << diff.count() << " s\n";

    start = std::chrono::system_clock::now();
    // factors of 3
    sum = 0;
    for (int i=0; i<iterationLimit; i+=3) {
        sum += i;
    }
    // factors of 5
    for (int i=0; i<iterationLimit; i+=5) {
        sum += i;
    }
    // remove duplicates
    for (int i=0; i<iterationLimit; i+=15) {
        sum -= i;
    }
    end = std::chrono::system_clock::now();
    diff = end-start;
    
    cout << "optimised implemention : sum " << sum << " time : " << diff.count() << " s\n";
    return 0;
}
