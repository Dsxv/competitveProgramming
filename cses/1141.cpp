#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n;
	int a[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ;
	}
	map<int,int> mp ;
	int l = 0 ;
	int ans = 1 ;
	for(int i = 0 ; i < n ; i++){
		while(mp.count(a[i])){
			mp.erase(a[l]) ;
			l++ ;
			if(l == n) break ;
		}
		mp[a[i]] = 1 ;
		ans = max(ans , i - l + 1) ;
	}
	cout << ans ;
	return 0 ;
}

