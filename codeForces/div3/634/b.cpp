#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , a , b ;
		cin >> n >> a >> b ;
		string pre = "" ;
		for(int i = 0 ; i < b ; i++){
			pre += (char)(i+'a') ;
		}
		char ch[n] ;
		for(int i = 0 ; i < a ; i++){
			ch[i] = pre[i%b] ;
		}
		for(int i = a ; i < n ; i++){
			ch[i] = ch[i-a] ;
		}
		for(int i = 0 ; i < n ; i++) cout << ch[i] ;
		cout << endl ;
	}
	return 0 ;
}

