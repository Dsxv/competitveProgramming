#include <bits/stdc++.h>
using namespace std ;

#define int long long

void solve(int t){
	int n ;
	cin >> n; 
	int r = 2 , c = 1 ;
	cout << "Case #"<<t<<": "<<'\n' ;
	int sum = 1 ;
	int var = 1 ;
	cout << 1 << " " << 1 << '\n' ;
	bool ok = false ;
	while(sum != n){
		if(ok){
			sum++ ;
			cout << r << " " << c << endl ;
			r++ , c++ ;
			continue ;
		}
		if(sum + var > n){
			ok = true ;
			r-- ;
		} else {
			sum += var ;
			var++ ;
			cout << r << " " << c << '\n' ;
			r++ , c++ ;
		}
	}
}

int32_t main(){
	int t ;
	cin >> t ;
	for(int i = 1 ; i <= t ; i++){
		solve(i) ;
	}	
	return 0 ;
}


