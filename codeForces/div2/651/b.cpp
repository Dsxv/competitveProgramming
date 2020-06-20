#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		vector<int> odd , even ;
		for(int i = 0 ; i < 2*n ; i++){
			int x ;
			cin >> x ;
			if(x&1) odd.push_back(i) ;
			else even.push_back(i) ;
		}
		vector<pair<int,int>> ans ;
		if(odd.size() % 2){
			odd.pop_back() ;
			even.pop_back() ;
		} else {
			if(odd.size() >= 2){
				odd.pop_back() ;
				odd.pop_back() ;
			} else {
				int x = even.back() ;
				even.pop_back() ;
				even.pop_back() ;
			}
		}
		for(int i = 0 ; i < odd.size() ; i += 2){
			ans.push_back({odd[i] , odd[i+1]}) ;
		}
		for(int i = 0 ; i < even.size() ; i += 2){
			ans.push_back({even[i] , even[i+1]}) ;
		}
		for(auto i : ans){
				cout << i.first + 1 << " " << i.second + 1 << '\n' ;
		}
	}
	return 0 ;
}

