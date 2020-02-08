#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int s , n ;
	cin >> s >> n ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x ;
		s -= x ;
	}
	if(s <= 0){
		cout << "Yes" ;
	} else {
		cout << "No" ;
	}
	return 0 ;
}

