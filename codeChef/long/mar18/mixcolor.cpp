#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		set<int> s ;
		for(int i = 0 ; i < n ; i++){
			int x ;
			cin >> x ;
			s.insert(x) ;
		}
		cout << n - s.size() << endl ;
	}
	return 0 ;
}
