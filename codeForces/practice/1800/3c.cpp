#include <bits/stdc++.h>
using namespace std ;

#define int long long

char s[3][3] ;

int cc(char ch){
	int count = 0 ;
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++) count += s[i][j] == ch ;
	}
	return count ;
}

bool win(char ch){
	for(int i = 0 ; i < 3 ; i++){
		int ca = 0 , cb = 0;
		for(int j = 0 ; j < 3 ; j++) {
			ca += s[i][j] == ch ;
			cb += s[j][i] == ch ;
		}
		if(ca == 3 || cb == 3) return 1 ;
	}
	int ca = 0 , cb = 0 ;
	for(int i = 0 , j = 0 , k = 2 ; i < 3 ; i++ , j++ , k--){
		ca += s[i][j] == ch ;
		cb += s[i][k] == ch ;
	}
	return (ca == 3 || cb == 3) ;
}

void no(){
	cout << "illegal" ;
	exit(0) ;
}

int32_t main(){
	for(int i = 0 ; i < 3 ; i++){
		for(int j = 0 ; j < 3 ; j++) cin >> s[i][j] ;
	}
	int x = cc('X') , y = cc('0') , dot = cc('.') ;
	int a = win('X') , b = win('0') ;
	if(x < y || x > y + 1) no() ;
	if(a && b) no() ;
	if(x == y && a) no() ;
	if(b && x > y) no() ;
	if(a){
		cout << "the first player won" ;
		return 0 ;
	}
	if(b){
		cout << "the second player won" ;
		return 0 ;
	}
	if(dot == 0){
		cout << "draw" ;
		return 0 ;
	}
	if(x == y) cout << "first" ;
	else cout << "second" ;
	return 0 ;
}

