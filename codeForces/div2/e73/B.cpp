#include <bits/stdc++.h>
using namespace std ;

int32_t main(){
	int n ;
	cin >> n ;
	string s[2] = {"BW","WB"};
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++) cout << s[i%2][j%2] ;
		cout << endl ;
	}
	return 0 ;
}

