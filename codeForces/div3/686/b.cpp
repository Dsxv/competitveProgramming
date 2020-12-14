#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		vector<int> v[n + 1] ;
		int ans = -1 ;
		for(int i = 0 ; i < n ; i++){
			int x ; cin >> x ;
			v[x].push_back(i+1) ;
		}
		for(int i = 1 ; i <= n ; i++){
			if(v[i].size() == 1){
				ans = v[i][0] ;
				break ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

