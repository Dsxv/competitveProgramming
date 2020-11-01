#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n;
	cin >> n ;
	int cnt = 0 ;
	bool found = false ;
	for(int i = 0 ; i < n ; i++){
		int x , y ;
		cin >> x >> y ;
		x-- , y-- ;
		if(x == y){
			cnt++ ;
		} else {
			cnt = 0 ;
		}
		if(cnt > 2) found = true ;
	}
	if(found){
		cout << "Yes" ;
	} else {
		cout << "No" ;
	}
	return 0 ;
}

