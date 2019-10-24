
#include <bits/stdc++.h>
#include<cmath>
using namespace std;

// We will find all primes in the range 1 to 120
int const N = 20000000;
int is_prime[N];

bool prime( long  num ) {
    if (num % 2 == 0 || num == 1) {
        return false;
    }

     long square_root = sqrt(num);
    for (long i = 3; i <= square_root; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}

bool sieve() {
    // We cross out all composites from 2 to sqrt(N)
    int i=2;
    // This will loop from 2 to int(sqrt(x))
    while(i*i <= N) {
        // If we already crossed out this number, then continue
        if(is_prime[i] == 0) {
            i++;
            continue;
        }
        int j = 2*i;
        while(j < N) {
            // Cross out this as it is composite
            is_prime[j] = 0;
            // j is incremented by i, because we want to cover all multiples of i
            j += i;
        }
        i++;
    }
}

int main() {
    // is_prime[i] = 1 means that i is prime and is_prime[i] = 0 means that i is composite
    // Initially, we say all of them are prime
    for(int i=0; i<N; i++) {
        is_prime[i] = 1;
    }
    // We know 0 and 1 are composites
    is_prime[0] = 0;
    is_prime[1] = 0;
    sieve();
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int count=0;
        long temp;
        for(int i=0;i<n;i++)
        {
            cin>>temp;
            if (temp>N){if(prime(temp))count++;}
            else if (is_prime[temp]==1)count++;
        }
        cout<<count<<"\n";
    }
   return 0;
}
