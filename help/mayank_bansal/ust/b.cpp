#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

int solve(int N){ 
    int two = 2,ans = 0; 
    int n = N; 
	int pow = 1 ;
    while(n){ 
        ans += ((N/two)*(two>>1)) * pow ; 
		int count = 0 ; 
        if((N&(two-1)) > (two>>1)-1) count = (N&(two-1)) - (two>>1)+1;
		ans += pow * count ;
		ans %= mod ;
		pow = (pow * 10) % mod ;
        two <<= 1; 
        n >>= 1; 
    } 
    return ans; 
}

int32_t main() {
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		cout << solve(n) << '\n' ;
	}
	return 0; 
}

