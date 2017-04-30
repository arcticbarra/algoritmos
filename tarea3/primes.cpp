/*
Enrique Barragan Gonzalez
A01370878
Range primes

Algoritmos
 */

#include <iostream>

using namespace std;

int arrLength = 1000000;
bool primes[1000000];

bool isPrime(int num) {
  // Sieve of Atkin algorithm for prime numbers (multiples of squares of primes)
  // https://en.wikipedia.org/wiki/Sieve_of_Atkin
  if (num == 2 || num == 3) {
    return true;
  }
  if (num % 2 == 0 || num % 3 == 0) {
    return false;
  }
  int i = 5, w = 2;
  while (i * i <= num) {
    if (num % i == 0) {
      return false;
    }
    i += w;
    w = 6 - w;
  }
  return true;
}

void fillArray() {
  fill_n(primes, arrLength, true);
  primes[0] = false;
  primes[1] = false;

  for (int i = 2; i < arrLength; i++) {

    if (primes[i]) {
      if (isPrime(i)) {
        for (int j = i+i; j < arrLength; j+=i) {
          primes[j] = false;
        }
      } else {
        for (int j = i; j < arrLength; j+=i) {
          primes[j] = false;
        }
      } // end else
    } // end primes[i] if
  } // end for
} // end func

void findPrimes(int num) {
  if (primes[num]) {
    cout << num << " " << num << endl;
  } else {

    int low = num-1;
    while (!primes[low]) {
      low--;
    }
    cout << low << " ";

    int high = num+1;
    while (!primes[high]) {
      high++;
    }
    cout << high << endl;
  }
}

int main() {

  fillArray();
  int testcases = 0, num = 0;
  cin >> testcases;

  for (int i = 0; i < testcases; i++) {
    cin >> num;
    findPrimes(num);
  }

  return 0;
}
