#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int inf = 1e15 ;

int32_t main(){
	int n ;
	cin >> n ;
	int a[n] ;
	int sum = 0 ;
	map<int,int> mp ;
	mp[inf%n] = 1 ;
	int ans = 0 ;
	for(int i = 0 ;  i < n ; i++){
		int x ; cin >> x ;
		sum += x ;
		if(mp.count((sum+inf)%n)){
			ans += mp[(sum+inf)%n] ;
		}
		mp[(sum+inf)%n]++ ;
	}
	cout << ans ;
	return 0 ;
}

