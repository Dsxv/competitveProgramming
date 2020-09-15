#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , x ;
		cin >> n >> x ;
		vector<int> fact ;
		int l = sqrt(x) ;
		for(int i  = 1 ; i <= l ; i++) {
			if(x%i) continue ;
			fact.push_back(i) ;
		}
		int a[n] ;
		map<int,int> mp ;
		int sum = 0 ;
		int ans = 0 ;
		mp[0]++ ;
		for(int i = 0 ; i < n ; i++){
			int x ;
			cin >> x ;
			sum += x ;
			for(auto j : fact){
				if(mp.count(sum-j) && mp.count(sum-x/j)){
					ans += mp[sum-j]*mp[sum-(x/j)] ;
				}
			}
			mp[sum]++ ;
		}
		cout << sum << '\n' ;
	}
	return 0 ;
}

