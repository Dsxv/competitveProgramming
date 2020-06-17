#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n , m ;
	cin >> n >> m ;
	vector<pair<int,int>> inc , dec ;
	for(int i =  0 ; i < m ; i++){
		int t , l , r;
		cin >> t >> l >> r ;
		if(t == 1){
			inc.push_back({l-1,r-1}) ;
		} else {
			dec.push_back({l-1,r-1}) ;
		}
	}
	int a[n] ;
	memset(a , -1 , sizeof(a)) ;
	for(auto i : inc){
		for(int j = i.first + 1 ; j <= i.second ; j++){
			a[j] = 0 ;
		}
	}
	int val = n+1 ;
	int ans[n] = {} ;
	for(int i = 0 ; i < n ; i++){
		val += a[i] ;
		ans[i] = val ;
	}
	bool found = true ;
	for(auto i : dec){
		vector<int> v ;
		for(int j = i.first ; j <= i.second ; j++){
			v.push_back(ans[j]) ;
		}
		if(is_sorted(v.begin() , v.end() , [](int a , int b){ return a < b ;})){
			found = false ;
			break ;
		}
	}
	if(!found){
		cout << "NO" ;
		return 0 ;
	}
	cout << "YES\n" ;
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

