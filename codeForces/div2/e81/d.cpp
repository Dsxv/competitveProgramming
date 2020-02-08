#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int a,  m ;
		cin >> a >> m ;
		int gc = __gcd(a,m) ;
		a /= gc , m /= gc ;
		cout << solve(m) << endl ;
	}
	return 0 ;
}

