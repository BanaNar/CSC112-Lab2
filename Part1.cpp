/* 
 *  @file    labTwo_Part1.cpp
 *  @author  Tony Xu (xuj16)
 *  @date    2/10/2018  
 *  @version 9.0 
 *  
 *  This is a little program that determine primes, calculate 
 *  # primes, %primes, max prime, avg distance between primes.
 *  Examine all numbers in the closed interval, [0, kN], where kN>= 2.
 *
 */

#include <iostream>
#include <math.h>
using namespace std;

int main() {
    //Declare Variables
    const int kMaxN = 5000;
    bool isPrime[kMaxN+1];

    //Use to calculate number of prime, max of prime, and average prime difference.
    int kN, i, j, iLimit, tmp, numPrimes=0, maxPrime=2, primes[kMaxN+1], primeDiffAvg=0,
        primeDiff, numTwinPtrimePairs=0;
    int numFactor = 0;
    //Use to track the largest and second largest numbers
    int firstMax, secondMax;

    cout << "Enter kN: " << endl;
    cin >> kN;
    cout << endl;

    for (i = 0; i <= kN; ++i) {
        isPrime[i] = true;
    }

    //Determine prime numbers      
    for (i = 2; i*i <= kN; ++i){
        if(isPrime[i] == true){
            for (j = i * 2; j <= kN; j = i + j){
                isPrime[j] = false;
            }
        }
    }

    //Print prime numbers found
    for (i = 2; i <= kN; ++i){
        if (isPrime[i] == true){
           cout << i << " ";
           primes[numPrimes] = i;
           numPrimes++;
           maxPrime = i; 
        } 
    }

    //Calculate the average prime difference
    primeDiffAvg = (primes[numPrimes - 1] - primes[0]) / (numPrimes - 1);

    cout << endl << endl;
    cout << "#Primes: " << numPrimes << ", " << "maxPrime: " << maxPrime << " Avg prime diff: " << primeDiffAvg << endl;
    
    //Count prime pairs
    for (i = 0; i < numPrimes - 1; ++i){
        if(primes[i+1] - primes[i] == 2){
            numTwinPtrimePairs++;
        }
    }

    cout << "#Twin prime pairs: " << numTwinPtrimePairs << endl;

    firstMax = numPrimes - 1;
    secondMax = numPrimes - 2;

    for (i = 0; i < numPrimes - 1; ++i){

        if (primes[i]%10 > primes[i+1]%10){
            if (i == firstMax){
                firstMax++;
            }

            if (i + 1 == firstMax){
                firstMax--;
            }

            if (i == secondMax){
                firstMax++;
            }

            if (i+1 == secondMax){
                secondMax--;
            }

            tmp = primes[i + 1];
            primes[i + 1] = primes[i];
            primes[i] = tmp;
        }
    }

    for (i = 0; i < numPrimes; i++){
        cout << primes[i] << " ";
    }

    cout << endl;

    //Swap the largest and second largest value
    tmp = 0;
    tmp = primes[firstMax];
    primes[firstMax] = primes[secondMax];
    primes[secondMax] = tmp;

    for (i = 0; i < numPrimes; i++){
        cout << primes[i] << " ";
    }

        return 0;
}
