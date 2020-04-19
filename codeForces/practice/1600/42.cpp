#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(int a , int b){
	if(a > b) swap(a,b) ;
	int x = __gcd(a,b) ;
	a /= x , b /= x ;
	if(a == 1) return b ;
	return b/a + solve(b%a,a) ;
}

int32_t main(){
	int a , b ;
	cin >> a >> b ;
	cout << solve(a,b) ;
	return 0 ;
}

