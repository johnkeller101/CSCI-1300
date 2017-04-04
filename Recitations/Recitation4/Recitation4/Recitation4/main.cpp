//
//  main.cpp
//  Recitation 4
//
//  Created by John Keller on 1/30/17.
//  Copyright © 2017 John Keller. All rights reserved.
//

#include <iostream>

using namespace std;

bool isPrime(int n);
void printPrimes(int n);

int main() {
    int p = 0;
    
    cout << "Prime Printer" << endl;
    cout << "Enter a number to look for primes: ";
    cin >> p;
    
    while(p <= 2) {
        cout << "To look for primes, please enter a number greater than 1: ";
        cin >> p;
    }
    
    printPrimes(p);
    
    return 0;
}

bool isPrime(int n) {
    // a number p is prime is
    
    // A simple test for prime numbers is trial division.
    // If n is a prime number, then there is no integer m from 2 to n that evenly divides n (the division leaves no remainder).
    // If n is divisible by any m less than n, then n is composite, and therefore not prime.
    
    int m = 2;
    
    bool test = true;
    bool debug = false;
    
    while( m < n ){
        if(n%m == 0)
            test = false;
        
        if(debug)   // enable debug = true to see when test becomes false
        {
            cout << n << "%" << m << " = " << n%m;
            
            if(test == false)
                cout << "*" << endl;    // asterik will print when prime test has failed
            else
                cout << endl;
        }
        
        m = m + 1;
    }
    
    return test;
}

void printPrimes(int n) {
    int i = 2;
    cout << "All prime numbers up to and including " << n << ":" << endl;
    
    while(i <= n)
    {
        if(isPrime(i))
            cout << i << endl;
        
        i++;
    }
}
