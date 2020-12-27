#include <bits/stdc++.h>
using namespace std ;

#define int long long

int findAutoCount(char *n){
	int l = 0 ;
	for(char i = 0 ; *(n + i) ; i++) l++ ;
	if(l < 2) return 0 ;
	int a = n[0] - '0' ;
	int b = n[1] - '0' ;
	int val[10] = {} ;
	for(char i = 0 ; *(n + i) ; i++){
		a -= n[i] == '0' ;
		b -= n[i] == '1' ;
		val[n[i] -'0']++ ;
	}
	if(a == 0 && b == 0){
		int ans = 0 ;
		for(int i = 0 ; i < 10 ; i++) ans += val[i] != 0 ;
		return ans ;
	}
	return 0 ;
}
		

int32_t main(){
	char n[3] = {'1' , '2' , '3'} ;
	cout << findAutoCount(n) ;
	return 0 ;
}

