#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	map<int,int> mp , mp2 ;
	int ans = 0 ;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	for(int i = n - 1 ; i >= 0 ; i--){
		ans += mp2[a[i]*k] ;
		mp2[a[i]] += mp[a[i]*k] ;
		mp[a[i]]++ ;
	}
	cout << ans ;
	return 0 ;
}

