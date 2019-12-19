#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	unordered_map<int,int> edges[n] ;
	for(int i = 0 ; i < m ; i++){
		int f , s ;
		cin >> f >> s ;
		f-- , s-- ;
		edges[f][s] = 1 ;
	}
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		int a[n] = {0} ;
		for(auto k : edges[i]){
			for(auto j : edges[k.first]){
				if(j.first == i) continue ;
				a[j.first]++ ;
			}
		}
		for(int j = 0 ; j < n ; j++){
			if(j == i) continue ;
			ans += a[j]*(a[j]-1)/2;
		}
	}
	cout << ans ;
	return 0 ;
}

