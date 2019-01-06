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

/**
 Notes:
 examples of using the clock / timing functionality
 https://en.cppreference.com/w/cpp/chrono/system_clock/now
 
 **/
#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {

    std::cout << "Euler Problem #1\n"; // Helpful message to tell us what we are doing

    const int iterationLimit = 1000; // The amount we are looping to
    int sum = 0; // The answer!
    
    //
    // Reference implementation
    // Loop over all the numbers upto the iteration limit and simply check if they are
    // divisible by 3 or 5
    auto start = std::chrono::system_clock::now();
    for (int i=0; i<iterationLimit; i++) {
        if (i % 3 ==0 || i % 5 == 0) {
            sum += i;
        }
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diffReference = end-start;
    cout << "reference implemention : sum " << sum << " time : " << diffReference.count() << " s\n";

    //
    // Optimised Implementation
    // Loop in increments of 3 then 5 and sum up as we go along
    // We take care to make sure we don;t double count by having a third loop that goes
    // in increments of 3x5=15 and removes those values
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
    std::chrono::duration<double> diffOptimised = end-start;
    cout << "optimised implemention : sum " << sum << " time : " << diffOptimised.count() << " s\n";
    
    cout << "speed up factor : x" << diffReference.count() / diffOptimised.count() << endl;
    // Return success
    return 0;
}
