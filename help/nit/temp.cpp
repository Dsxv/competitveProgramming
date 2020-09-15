#include <bits/stdc++.h>
using namespace std ;

#define int long long

int mod = 1025 ;

int modexp(int a , int n){
	if(n == 0) return 1 ;
	if(n == 1){
		return a ;
	}
	int x = modexp(a , n / 2) ;
	x = (x*x) % mod ;
	if(n&1) x = (x*a) % mod ;
	return x ;
}

int32_t main(){
	//int x = 50*27 ;
	//int mx = 0 ;
	//for(int i = 1 ; i <= x ; i++){
		//if(i*(10000) % 444 == 0) {
			//mx = i ;
		//}
	//}
	//cout << modexp(2 , 72) << endl ;
	string s = "fruit" ;
	int sum = 0 ;
	for(auto i : s) cout <<  i - 'a' + 1 << " " ;
	cout << sum ;
	//cout << mx / 0.444 << endl ;
	//cout << mx << endl ;
	return 0 ;
}

