#include <bits/stdc++.h>
using namespace std ;

#define int long long
const int mod = 1e9 + 7 ;

void prod(int a[2][2] , int b[2][2] , int c[2][2]){
	c[0][0] = (a[0][0]*b[0][0] + a[0][1]*b[1][0]) % mod ;
	c[0][1] = (a[0][0]*b[0][1] + a[0][1]*b[1][1]) % mod ;
	c[1][0] = (a[1][0]*b[0][0] + a[1][1]*b[1][0]) % mod;
	c[1][1] = (a[1][0]*b[0][1] + a[1][1]*b[1][1]) % mod ;
}

void modexp(int a[2][2] ,int n , int c[2][2]){
	if(n == 0){
		for(int i = 0 ; i < 2 ; i++){
			for(int j = 0 ; j < 2 ; j++) c[i][j] = 1 ;
		}
		return ;
	}
	if(n == 1){
		for(int i = 0 ; i < 2 ; i++){
			for(int j = 0 ; j < 2 ; j++) c[i][j] = a[i][j] ;
		}
		return ;
	}
	int temp[2][2] ;
	modexp(a,n/2,temp) ;
	prod(temp,temp,c) ;
	if(n&1) {
		prod(c,a,temp) ;
		for(int i = 0 ; i < 2 ; i++){
			for(int j = 0 ; j < 2 ; j++) c[i][j] = temp[i][j] ;
		}
	}
	return ;
}


int32_t main(){
	int  t ;
	cin >> t;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		if(n == 1) {
			cout << m << endl ;
			continue ;
		}
		//n-- ;
		int a[2][2] = {{1,1},{1,0}} ;
		//int b[2][2] = {{1,0},{0,1}} ;
		int c[2][2] = {} ;
		//prod(a,b,c) ;
		//for(int i = 0 ; i < 2 ; i++){
			//for(int j = 0 ;j  < 2 ; j++) cout << c[i][j] << " " ;
		//}
		modexp(a,n,c) ;
		//int ans = (c[1][0]*((m*m)) % mod ) % mod;
		//ans = ans*(m-1) % mod 
		cout << c[0][0] << endl;
		int ans = (c[1][0]*((m*m)) % mod ) % mod;
		ans = ans*(m-1) % mod ;
		//cout << ans << endl ;
	}
	return 0 ;
}

