#include <bits/stdc++.h>
using namespace std ;

#define int long long

int val(int i){
	if(!i) return 0 ;
	return i%10 + val(i/10) ;
}

int32_t main(){
	int a, b , c ;
	cin >> a >> b >> c ;
	int x = 1e9 ;
	set<int> ans ;
	for(int i = 1 ; i <= 81 ; i++){
		int pw = 1 ;
		for(int j = 0 ; j < a ; j++) pw *= i ;
		if(b*pw + c < x && b*pw + c > 0) {
			if(i == val(b*pw + c)) {
				ans.insert(b*pw + c) ;
			}
		}
	}
	cout << ans.size() << endl ;
	for(auto i : ans) cout << i << " " ;
	return 0 ;
}

