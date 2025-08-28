#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Approach 3 : DP
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n);  // DP array to store ugly numbers
        uglyNumbers[0] = 1;          // The first ugly number is 1

        // Three pointers for the multiples of 2, 3, and 5
        int indexMultipleOf2 = 0, indexMultipleOf3 = 0, indexMultipleOf5 = 0;
        int nextMultipleOf2 = 2, nextMultipleOf3 = 3, nextMultipleOf5 = 5;

        // Generate ugly numbers until we reach the nth one
        for (int i = 1; i < n; i++) {
            // Find the next ugly number as the minimum of the next multiples
            int nextUglyNumber =
                min(nextMultipleOf2, min(nextMultipleOf3, nextMultipleOf5));
            uglyNumbers[i] = nextUglyNumber;

            // Update the corresponding pointer and next multiple
            if (nextUglyNumber == nextMultipleOf2) {
                indexMultipleOf2++;
                nextMultipleOf2 = uglyNumbers[indexMultipleOf2] * 2;
            }
            if (nextUglyNumber == nextMultipleOf3) {
                indexMultipleOf3++;
                nextMultipleOf3 = uglyNumbers[indexMultipleOf3] * 3;
            }
            if (nextUglyNumber == nextMultipleOf5) {
                indexMultipleOf5++;
                nextMultipleOf5 = uglyNumbers[indexMultipleOf5] * 5;
            }
        }

        return uglyNumbers[n - 1];  // Return the nth ugly number
    }
};

// Approach 2
/*class Solution {
public:
    int nthUglyNumber(int n) {
        // Min-heap to store and retrieve the smallest ugly number
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> seenNumbers;  // Set to avoid duplicates
        vector<int> primeFactors = {
            2, 3, 5};  // Factors for generating new ugly numbers

        minHeap.push(1);
        seenNumbers.insert(1);

        long currentUgly = 1;
        for (int i = 0; i < n; ++i) {
            currentUgly = minHeap.top();  // Get the smallest number
            minHeap.pop();                // Remove it from the heap

            // Generate and push the next ugly numbers
            for (int prime : primeFactors) {
                long nextUgly = currentUgly * prime;
                if (seenNumbers.find(nextUgly) ==
                    seenNumbers.end()) {  // Avoid duplicates
                    minHeap.push(nextUgly);
                    seenNumbers.insert(nextUgly);
                }
            }
        }

        return static_cast<int>(currentUgly);  // Return the nth ugly number
    }
};*/

// Approach 1
/*class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> uglyNumbersSet;  // Set to store potential ugly numbers
        uglyNumbersSet.insert(1);  // Start with 1, the first ugly number

        long currentUgly = 1;
        for (int i = 0; i < n; i++) {
            currentUgly = *uglyNumbersSet.begin();  // Get the smallest number from the set
            uglyNumbersSet.erase(uglyNumbersSet.begin());  // Remove it from the set

            // Insert the next potential ugly numbers
            uglyNumbersSet.insert(currentUgly * 2);
            uglyNumbersSet.insert(currentUgly * 3);
            uglyNumbersSet.insert(currentUgly * 5);
        }

        return static_cast<int>(currentUgly);  // Return the nth ugly number
    }
};*/

int main(){
    Solution sol;
    cout<<sol.nthUglyNumber(10);
    return 0;
}