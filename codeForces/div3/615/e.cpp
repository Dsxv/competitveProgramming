#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[n][m] , b[n][m] ;
	int k = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> a[i][j] ;
			b[i][j] = k++ ;
			a[i][j]-- ;
		}
	}
	int ans = 0 ;
	for(int j = 0 ; j < m ; j++){
		map<int,int> mp ;
		for(int i = 0 ; i < n ; i++){
			mp[b[i][j]] = i ;
		}
		vector<int> v(n) ;
		int tadd = 0 ;
		for(int i = 0 ; i < n ; i++){
			if(mp.count(a[i][j])) v[i] = mp[a[i][j]] + 1 ;
			else tadd++ ;
		}
		//if(j == 1) for(auto i : v) cout << i << " " ; cout << endl ;
		//v[i] is now compressed value from 1 to n , if it's wrongly present then 0
		pair<int,int> a[n] = {} ;
		for(int i = 0 ; i < n ; i++) a[i].second = i ;
		for(int i = 0 ; i < n ; i++){
			if(v[i] == 0) continue ;
			int x = i+1 - v[i] ;
			if(x < 0) x += n ;
			a[x].first++ ;
		}
		int mn = INT_MAX ;
		for(int i = 0 ; i < n ; i++){
			int rem = n - tadd - a[i].first ; // to change element if we rot acc t ith
			mn = min(a[i].second + rem , mn) ; 	// a[i].second amount of rot + rem chagne
		}
		ans += tadd + mn ;
	}
	cout << ans ;
	return 0 ;
}

