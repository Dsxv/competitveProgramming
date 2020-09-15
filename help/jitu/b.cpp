#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , x; 
	cin >> n >> x ;
	int cost = ceil(log2(n)) ;
	cout << (cost <= 2*x) ;
	return 0 ;
}

