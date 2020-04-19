#include <bits/stdc++.h>
using namespace std ;

using LL = long long ;
#define int long long
const int mod = 1e9 + 7 ;
int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1) return a ;
	int x = modexp(a,n/2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}


void factorise(LL n, vector <LL> &P)
{
    for(LL i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            P.push_back(i);

            while(n%i == 0)
            {
                n /= i;
            }
        }
    }

    if(n > 1)
    {
        P.push_back(n);
    }
}

LL get_exponent(LL n, LL p)
{
    LL exponent = 0;
    LL temp_p = p;

    while(n > 0)
    {
        exponent += n/p;

        n /= p;
    }

    return exponent;
}

int32_t main()
{
    LL x, n;
    cin >> x >> n;

    vector <LL> prime_factors;
    factorise(x, prime_factors);

    const LL MOD = 1e9 + 7;
    LL answer = 1;
    for(int i = 0; i < prime_factors.size(); i++)
    {	cout << prime_factors[i] << " " ;
        LL exponent = get_exponent(n, prime_factors[i]);

        answer *= modexp(prime_factors[i], exponent);

        answer %= MOD;
    }

    cout << answer << "\n";
    return 0;
}
