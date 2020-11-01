#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		map<int , int> mp1 ;
		map<int , int> mp2 ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			mp1[x]++ ;
		}
		for(int i = 0 ; i < m ; i++){
			int x ; cin >> x ;
			mp2[x]++ ;
		}
		vector<int> v ;
		for(auto i : mp1){
			if(mp2.count(i.first)){
				v.push_back(i.first) ;
			}
		}
		if(!v.size()){
			cout << 0 << '\n' ;
			continue ;
		}
		cout << *max_element(v.begin() , v.end()) - *min_element(v.begin() , v.end()) << '\n' ;
	}
	return 0 ;
}
	
