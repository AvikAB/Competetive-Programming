// Number Theory:


#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define nl "\n"
#define mem(a,b) memset(a, b, sizeof(a))
#define FASTER ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const ll N = 1e6+9;
const ll mod = 1e9+7;

bool isPrime[N];
vector<ll>primes;

void PrimeGen(ll n){
    for(int i=3; i<=n; i+=2) isPrime[i] = 1;

    ll sqr = sqrt(n);
    for(int i=3; i<=sqr; i+=2){
        if(isPrime[i]){
            for(int j=i*i; j<=n; j+=i){
                isPrime[j] = 0;
            }
        }
    }

    isPrime[2] = 1;
    primes.push_back(2);

    for(int i=3; i<=n; i+=2){
        if(isPrime[i]==1) primes.push_back(i);
    }
}

vector<ll> SegmentedSieve(ll L, ll R){
    ll lim = sqrt(R);
    PrimeGen(lim); // Generate all primes up to sqrt(r)

    vector<bool> isSegmentPrime( R-L+1, 1);   // R-L is the size of range where I will find the prime numbers

    if(L==1) isSegmentPrime[0] = 0; // 1 is not a prime number

    for(auto p: primes){
        ll start = max(p*p, (L+p-1)/p*p);
        if(start>R) continue;

        for(int j=start; j<=R; j+=p){  // prime er multiple ber korbe
            isSegmentPrime[j-L] = 0;    // index onujayi vector er value jegula non-prime tader 0 korbe
        }
    }

    // Collect all primes in the range [L, R]
    vector<ll> SegmentPrimes;
    for(int i=0; i<=R-L; i++){
        if(isSegmentPrime[i]) SegmentPrimes.push_back(L+i);
    }
    return SegmentPrimes;
}

vector<ll>PrimeFactors(ll n){
    vector<ll>factors;
    for(auto p: primes){
        if(p*p>n) break;
        if(n%p==0){
            while(n%p==0){
                factors.push_back(p);
                n/=p;
            }
        }
    }
    if(n>1) factors.push_back(n);
    return factors;
}

ll NOD(ll n){
    ll nod = 1;
    for(auto p: primes){
        if(p*p>n) break;
        if(n%p==0){
            ll cnt = 0;
            while(n%p==0){
                n/=p;
                cnt++;
            }
            cnt++;   // this is for 0 ranged power
            nod *= cnt;
        }
    }
    if(n>1) nod*=2;

    return nod;
}

ll SOD(ll n){
    ll sod = 1;
    for(auto p: primes){
        if(1LL*p*p>n) break;
        if(n%p==0){
            ll sum = 1;
            ll a = 1;
            while(n%p==0){
                a *= p;
                sum += a;
                n /= p;
            }
            sod *= sum;
        }
    }
    if(n>1) sod *= (n+1);

    return sod;
}

ll eulerPhi(ll n){
    //if(n==1) return 0;  /// special case for phi(1) = 0 if the range is 1 to (n-1)
    ll phi = n;
    for(auto p: primes){
        if(1LL*p*p>n) break;
        if(n%p==0){
            while(n%p==0){
                n /= p;
            }
            phi /= p;
            phi *= (p-1);  // phi *= ((p-1)/p) from euler's formula 
        }
    }
    if(n>1){
        phi /= n;
        phi *= (n-1);
    }

    return phi;
}

ll phi[N];

int main(){
    FASTER

    ll lim = 1e6;
    PrimeGen(lim);  // pre calculation of all prime numbers between 2 to 10^6
    
    // for(int i=1; i<=lim; i++) phi[i] = i; 

    // for(auto p: primes){
    //     for(int j=p; j<=lim; j+=p){
    //         phi[j] /= p;
    //         phi[j] *= (p-1);
    //     }
    // }

    // ll n;
    // cin>>n;

    // ll sumCoPrime = (phi[n]*n)/2;
    // cout<<sumCoPrime<<nl;

    vector<ll>factors = PrimeFactors(1100);
    for(auto av:factors){
        cout<<av<<" ";
    }
    cout<<nl;
}
