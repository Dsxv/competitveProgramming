#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m; 
	pair<int,int> ans[n+1] = {} ;
	for(int i = 0 ; i < m ; i++){
		int x ;
		string y ;
		cin >> x >> y ;
		if(ans[x].first == 1) continue ;
		if(y == "AC") ans[x].first = 1 ;
		else ans[x].second++ ;
	}
	pair<int,int> v = {};
	for(int i = 1 ; i < n+1 ; i++){
		if(ans[i].first){
			v.first++ ;
			v.second += ans[i].second ;
		}
	}
	cout << v.first << " " << v.second ;
	return 0 ;
}

