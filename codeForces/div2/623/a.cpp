#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int v[3] = {} ;
		for(int i = 0 ; i < 3 ; i++) cin >> v[i] ;
		sort(v , v + 3) ;
		string s[7] = {"0" , "1" , "2" , "21" , "20" , "10" , "012"} ;
		int cnt = 0 ;
		for(int i = 0 ; i < 7 ; i++){
			int a = 0 , b = 0 , c = 0 ;
			for(int j = 0 ; j < s[i].size() ; j++){
				a += s[i][j] == '0' ;
				b += s[i][j] == '1' ;
				c += s[i][j] == '2' ;
			}
			if(v[0] >= a && v[1] >= b && v[2] >= c){
				v[0] -= a , v[1] -= b , v[2] -= c ;
				cnt++ ;
			}
		}
		cout << cnt << '\n' ;
	}
	return 0 ;
}

