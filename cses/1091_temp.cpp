#include <bits/stdc++.h>
using namespace std ;
 
int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n , m ;
	cin >> n >> m ;
	int x ;
	multiset<int> s;
	for(int i = 0 ; i < n ; i++){
		cin >> x ;
		s.insert(x) ;
	}
	vector<int> ans(m) ;
	for(int i = 0 ; i < m ; i++){
		cin >> x ;
		if(s.size() == 0){
			ans[i] = -1 ;
			continue ;
		}
		auto it = s.lower_bound(x) ;
		if(*it == x){
			ans[i] = *it ;
			s.erase(it) ;
		} else {
			if(it == s.begin()){
				ans[i] = -1 ;
			} else {
				it-- ;
				ans[i] = *it ;
				s.erase(it) ;
			}
		}
	}
	for(auto i : ans) cout << i << " ";
	return 0 ;
}
