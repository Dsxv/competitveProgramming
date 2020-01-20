#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int* a, int n){
	int x = 0 ;
	int count = 0 ;
	int sum = accumulate(a,a+n,0LL) ;
	map<int,int> mp ;
	for(int i = 0 ; i < n ; i++){
		int s = abs(sum) , ai = abs(a[i]) ;
		if((s%2) == (ai%2))
			count += mp[(sum-a[i])/2] ; 
		x += a[i] ;
		mp[x]++ ;
	}
	return count ;
}

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
		}
		int x1 = solve(a,n) ;
		reverse(a,a+n) ;
		int x2 = solve(a,n) ;
		cout << x1 + x2 << endl ;
	}

	return 0 ;
}

