#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		vector<int> odd , even ;
		for(int i = 0 ; i < n ; i++){
			int x ;
			cin >> x ;
			if(x&1) odd.push_back(i+1) ;
			else even.push_back(i+1) ;
		}
		if(even.size()) cout << 1 << '\n' <<  even[0] << '\n' ;
		else {
			if(odd.size() == 1){
				cout << -1 << '\n' ;
			} else{
				cout << 2 << '\n' ;
				cout << odd[0] << " " << odd[1] << '\n' ;
			}
		}
	}
	return 0 ;
}

