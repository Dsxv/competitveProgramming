#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k;
		cin >> n >> k ;
		int a[n] ;
		for(int i = 0 ; i < n ; i++) cin >> a[i] ;
		set<int> s(a,a+n) ;
		if(s.size() > k){
			cout << -1 << '\n' ;
			continue ;
		}
		vector<int> temp(s.begin() , s.end()) ;
		while(temp.size() < k){
			temp.push_back(temp[0]) ;
		}
		vector<int> v ;
		for(int i = 0 ; i < n*n ; i++){
			v.push_back(temp[i%k]) ;
		}
		cout << v.size() << '\n' ;
		for(auto i : v) cout << i << " " ; 
		cout << '\n' ;
	}
	return 0 ;
}

