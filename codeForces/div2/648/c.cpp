#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] , b[n] ;
	int c1[n+1] , c2[n+1] ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n ; i++) cin >> b[i] ;
	for(int i = 0 ; i < n ; i++){
		c1[a[i]] = i+1 ;
	}
	for(int i = 0 ; i < n ; i++){
		c2[b[i]] = i+1 ;
	}
	map<int,int> mp ;
	for(int i = 1 ; i <= n ; i++){
		mp[(c1[i] - c2[i] + n)%n]++ ;
	}
	int mx = 1 ;
	for(auto i : mp){
		mx = max(i.second , mx) ;
	}
	cout << mx ;
	return 0 ;
}

