// - Counts prime numbers less than n
// - Uses Sieve of Eratosthenes algorithm
// - Time: O(n log log n), Space: O(n)

#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n);

int main(){
    int n;
    cin>>n;
    int res = countPrimes(n);
    cout<<res<<endl;
    return 0;
}
int countPrimes(int n) {
        if (n <= 2)
            return 0;
        int count = n - 2;

        vector<int> is_prime(n, true);
        is_prime[0] = false;
        is_prime[1] = false;

        for (int i = 2; i * i < n; i++) {
            if (is_prime[i]) {
                for (int j = i * i; j < n; j += i) {
                    if (is_prime[j]) {
                        is_prime[j] = false;
                        count--;
                    }
                }
            }
        }
        return count;
    }