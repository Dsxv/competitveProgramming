#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >>  n >> m ;
		bool seive[m-n+1];
		memset(seive,1,sizeof(seive)) ;	
		int l = sqrt(m) ;
		bool s2[l+10] ;
		memset(s2,1,sizeof(s2)) ;
		set<int> ans ;
		for(int i = 2 ; i <= l ; i++){
			if(i >= n && s2[i]) ans.insert(i) ;
			for(int j = i ; j <= l ; j+=i) s2[j] = 0 ;
		}
		for(int i = 2 ; i <= l ; i++){	
			for(int j = (n/i)*i ; j <= m ; j += i){
				if(j < n) continue ;
				seive[j-n] = 0;
			}
		}
		for(int i = 0 ; i <= m-n ; i++){
			if(seive[i] && (i+n) > 1) ans.insert(i+n) ;
		}
		for(auto i : ans) cout << i << "\n";
		cout << '\n';
	}
	return 0 ;
}

