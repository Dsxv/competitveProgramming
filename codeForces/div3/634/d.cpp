#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		char ch[26][26] ;
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				cin >> ch[i][j] ;
			}
		}
		ch[0][0] = ch[1][0] ;
		ch[3][1] = ch[4][1] ;
		ch[6][2] = ch[7][2] ;
		ch[1][3] = ch[2][3] ;
		ch[4][4] = ch[5][4] ;
		ch[7][5] = ch[8][5] ;
		ch[2][6] = ch[0][6] ;
		ch[5][7] = ch[4][7] ;
		ch[8][8] = ch[7][8] ;
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				cout << ch[i][j] ;
			} cout << endl ;
		}
	}
	return 0 ;
}

