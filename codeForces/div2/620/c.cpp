#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		int rem = INT_MAX ;
		int init = 0 ;
		bool found = true ;
		for(int i = 0  ; i < n ; i++){
			int  ti , fi , si ;
			cin >> ti >> fi >> si ;
			rem += ti - init ;
			rem = min(si-fi+1,rem) ;
			init = ti ;
			if(m >= fi && m <= si){
				continue ;
			} else{
				if(abs(m-fi) < abs(m-si)){
					rem -= abs(m-fi) ;
					m = fi ;
				} else {
					rem -= abs(m-si) ;
					m = si ;
				}
				if(rem < 0){
					found = false ;
					break ;
				}
			}
			cout << m << endl ;
		}
		if(found) cout << "YES\n" ;
		else cout << "NO\n" ;
	}
	return 0 ;
}

