#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t; 
	while(t--){
		int n ;
		cin >> n ;
		string a , b ; cin >> a >> b; 
		bool ok = true ;
		set<char> ch[20] ;
		for(int i = 0 ; i < n ; i++){
			if(a[i] > b[i]) {
				ok = false ;
				break ;
			}
		}
		if(!ok){
			cout << -1 << '\n' ;
			continue ;
		}
		for(int i = 0 ; i < n ; i++){
			if(a[i] != b[i]){
				ch[a[i]-'a'].insert(b[i]) ;
			}
		}
		int ans = 0 ;
		for(int i = 0 ; i < 20 ; i++){
			if(ch[i].size()){
				ans++ ;
				char mn = *ch[i].begin() ;
				for(auto j : ch[i]){
						if(j != mn){
							ch[mn-'a'].insert(j) ;
						}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0 ;
}

