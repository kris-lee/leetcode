/*
204. Count Primes
Description:Count the number of prime numbers less than a non-negative number, n.
*/
class Solution {
public:
	int countPrimes(int n) {
		//Solution 1
		vector<bool> isPrime(n);
		for (int i = 2; i*i < n; i++) {  
			if(!isPrime[i]) {  
				for(int j = i; i*j < n; j++) {  
					isPrime[i*j] = true;  
				}  
			}  
		 }  
		 int prime_count=0;  
		 for (int i = 2; i < n; i++)
			 if(isPrime[i] == false) ++prime_count;  
		 return prime_count; 


		//Solution 2
		vector<bool> isPrime(n);
		for (int j = 2; j < sqrt(n); j++) {
			int count = j;
			while (count*j < n) isPrime[count*j] = true, ++count;
		}
		int prime_count = 0;
		for (int i = 2; i < n; i++)
			if (isPrime[i] == false) ++prime_count;
		return prime_count; 
	}
};