#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k;
	cin >> n >> k ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	sort(a,a+n,greater<int>()) ;
	k = min(n,k) ;
	cout << accumulate(a+k,a+n,0LL) ;
	return 0 ;
}

