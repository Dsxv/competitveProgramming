#include <bits/stdc++.h>
using namespace std ;

#define int long long


int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		vector<bool> in(n , 0) ;
		for(int i = 0 ; i < n - 1 ; i++){
			int f , s ;
			cin >> f >> s ;
			f-- , s-- ;
			in[s] = 1 ;
		}
		cout << count(in.begin() , in.end() , 0) - 1 << '\n' ;
	}
	return 0 ;
}

