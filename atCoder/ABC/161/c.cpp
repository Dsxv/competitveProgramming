#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	cout << min((n%k),k-n%k) ;
	return 0 ;
}

