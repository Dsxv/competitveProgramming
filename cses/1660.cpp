#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , x ;
	cin >> n >> x ;
	map<int,int> mp ;
	mp[0] = 1 ;
	int ans = 0 , sum = 0 ;
	for(int i = 0 ; i < n ; i++){
		int t;
		cin >> t ;
		sum += t ;
		if(mp.count(sum-x)){
			ans += mp[sum-x] ;
		}
		mp[sum]++ ;
	}
	cout << ans ;
	return 0 ;
}

