#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		int pos[n+1] = {0};
		int a[n+1] = {0};
		int ans = 0 ;
		int l = 0 ;
		set<int> s ;
		for(int i = 1 ; i <= n ; i++) {
			cin >> a[i] ;
			pos[a[i]] = i ;
		}
		for(int i = 1 ; i <= m ; i++){
			int x ; 
			cin >> x ;
			if(s.count(x)) {
				ans++ ;
				s.erase(x) ;
			} else {
				int ind = pos[x] ;
				for(int j = l + 1 ; j < ind ; j++)
					s.insert(a[j]) ;
				l = max(l,ind) ;
				ans += 2*s.size() + 1 ;
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

