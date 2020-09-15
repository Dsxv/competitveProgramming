#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int N = 1e5 + 10 ;
int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n; 
		cin >> n ;
		int a[N] = {} ;
		for(int i = 0 ; i < n ; i++) {
			int x ;
			cin >> x ;
			a[x]++ ;
		}
		vector<int> v ;
		for(int i = 1 ; i <= n ; i++){
			v.push_back(a[i]) ;
		}
		sort(v.begin()  , v.end() , greater<int>()) ;
		int fr = 0 ;
		for(int i = 1 ; i < v.size() && v[i] == v[0] ; i++) fr = i ;
		int ans = fr ;
		for(int i = fr + 1 , j = 0 ; i < v.size() ; i++){
			while(v[i]){
				v[i]-- ;
				j++ ;
				if(j == (v[0] - 1)) {
					ans++ ;
					j = 0 ;
				}
			}
		}
		cout << ans << '\n' ;
	}
	return 0 ;
}

