#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	int sum = accumulate(a,a+n,0LL) ;
	int mx = *max_element(a,a+n) ;
	cout << max(mx , (sum+n-2)/(n-1)) ;
	return 0 ;
}

