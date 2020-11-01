#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	int l = sqrt(n) ;
	vector<int> ans ;
	for(int i = 1 ; i <= l ; i++){
		if(n%i) continue ;
		if(n / i == i){
			ans.push_back(i) ;
		} else {
			ans.push_back(i) ;
			ans.push_back(n/i) ;
		}
	}
	sort(ans.begin() , ans.end()) ;
	for(auto i : ans) cout << i << '\n' ;
	return 0 ;
}

