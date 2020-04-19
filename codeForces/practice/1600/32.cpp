#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n ;
	if(n <=3 ){
		cout << "NO" ;
		return 0 ;
	}
	cout << "YES\n" ;
	string s = "";
	if(n%2 == 0){
		s =  "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24\n" ;
	}
	if(n%2){
		s = "5 * 4 = 20\n20 + 3 = 23\n2 - 1 = 1\n23 + 1 = 24\n" ;
	}
	cout << s ;
	for(int i = 6+(n%2) ; i <= n ; i+=2){
		cout << i << " - " << (i-1) << " = " << 1 << endl ;
		cout << "24 * 1 = 24\n";
	}
	
	return 0 ;
}

