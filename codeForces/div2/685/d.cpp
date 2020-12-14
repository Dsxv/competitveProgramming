#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int d , k ;
		cin >> d >> k ;
		int x = 0 ;
		while(2*(x + k)*(x + k) <= d * d){
			x += k ;
		}
		bool found = false ;
		if((x + k) * (x + k) + x * x <= d * d) found = true ;
		if(found){
			cout << "Ashish\n" ;
		} else {
			cout << "Utkarsh\n" ;
		}
	}
	return 0 ;
}

