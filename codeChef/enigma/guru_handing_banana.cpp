#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(vector<int> & v , int n){
	int l = sqrt(n) ;
	for(int i = 1 ; i <= l ; i++){
		if(n%i) continue ;
		if(i == l){
			v.push_back(i) ;
		} else {
			v.push_back(n/i) ;
			v.push_back(i) ;
		}
	}
}

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		vector<int> all_f ;
		solve(all_f , n) ;
		sort(all_f.begin() , all_f.end()) ;
		int ans = - 1 ;
		for(auto i : all_f) {
			int x = i*k*(k+1)/2 ;
			x = n/x ;
			if(!x) break ;
			ans = i ;
		}
		cout << ans << '\n';
	}
	return 0 ;
}

