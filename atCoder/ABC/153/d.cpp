#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int x = log2(n) + 1 ;
	cout << (1LL<<x) - 1 ;
	return 0 ;
}

