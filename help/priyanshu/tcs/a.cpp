#include <bits/stdc++.h>
using namespace std ;

int main(){
	int n ;
	cin >> n ;
	if(n <= 0){
		cout << "Not Possible" ;
		return 0 ;
	}
	int cnt[10] = {} ;
	for(int i = 9 ; i > 1; i--){
		while(n % i == 0){
			cnt[i]++ ;
			n /= i ;
		}
	}
	if(n >= 10){
		cout << "Not Possible" ;
		return 0 ;
	}
	string s = "" ;
	for(int i = 2 ; i < 10 ; i++){
		s += string(cnt[i] , i + '0') ;
	}
	if(s.size() == 1){
		s = "1" + s ;
	}
	cout << s ;
	return 0 ;
}

