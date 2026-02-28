// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
    
    for (uint64_t i = 2; i * i <= value; ++i) {
        if (value % i == 0) {
            return false;
        }
    }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
    uint64_t count = 0;
    uint64_t number = 1;
    while (count < n) {
        number++;
        bool isPrime = true;
        if (number < 2) {
            isPrime = false;
        } else {
            for (uint64_t i = 2; i * i <= number; i++) {
                if (number % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            count++;
        }
    }
    return number;
}

uint64_t nextPrime(uint64_t value) {
  uint64_t candidate = value + 1;
    while (true) {
        bool isPrime = true;
        if (candidate < 2) {
            isPrime = false;
        } else if (candidate == 2 || candidate == 3) {
            isPrime = true;
        } else if (candidate % 2 == 0 || candidate % 3 == 0) {
            isPrime = false;
        } else {
            for (uint64_t i = 5; i * i <= candidate; i += 6) {
                if (candidate % i == 0 || candidate % (i + 2) == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            return candidate;
        }
        candidate++;
    }
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
    uint64_t sum = 0;
    for (uint64_t num = 2; num < hbound; num++) {
        bool isPrime = true;
        if (num < 2) {
            isPrime = false;
        } else if (num == 2) {
            isPrime = true;
        } else if (num % 2 == 0) {
            isPrime = false;
        } else {
            for (uint64_t i = 3; i * i <= num; i += 2) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if (isPrime) {
            sum += num;
        }
    }
    return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  if (hbound <= lbound || hbound < 3) return 0;
    
    uint64_t count = 0;
  
    for (uint64_t i = lbound; i + 2 < hbound; i++) {
        bool isFirstPrime = true;
        if (i < 2) {
            isFirstPrime = false;
        } else {
            for (uint64_t j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    isFirstPrime = false;
                    break;
                }
            }
        }
        
        if (!isFirstPrime) continue;
        
        uint64_t second = i + 2;
        bool isSecondPrime = true;
        for (uint64_t j = 2; j * j <= second; j++) {
            if (second % j == 0) {
                isSecondPrime = false;
                break;
            }
        }
        
        if (isSecondPrime) {
            count++;
        }
    }
    
    return count;
}
