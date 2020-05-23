#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int mod = 1e9 + 7 ;

const int N = 1e5 + 10 ;

int fib[N] ;

int32_t main(){
	fib[0] = 1 ;
	fib[1] = 1 ;
	for(int i = 2 ; i < N ; i++){
		fib[i] = (fib[i-1] + fib[i-2]) % mod ;
	}
	int n , m ;
	cin >> n >> m ;
	cout << (fib[n] + fib[m] - 1)*2 % mod ;
	return 0 ;
}

