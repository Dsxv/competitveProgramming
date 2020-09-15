#include <bits/stdc++.h>
using namespace std ;

const int N = 1e5 + 10 ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n ;
	cin >> n ;
	int a[N] = {} ;
	for(int i = 0 ; i < n ; i++){
		int x ; 
		cin >> x ;
		a[x]++ ;
	}
	multiset<pair<int,int> , greater<pair<int,int>>> s ;
	for(int i = 1 ; i < N ; i++){
		s.insert({a[i] , i}) ;
	}
	int q ;
	cin >> q ;
	while(q--){
		char ch ;
		int i ;
		cin >> ch >> i ;
		if(ch == '-'){
			auto it = s.find({ a[i] , i}) ;
			s.erase(it) ;
			a[i]-- ;
			s.insert({ a[i] , i}) ;
		} else {
			auto it = s.find({a[i] , i}) ;
			s.erase(it) ;
			a[i]++ ;
			s.insert({a[i] , i}) ;
		}
		auto [val , id] = *s.begin() ; s.erase(s.begin()) ;
		auto [val2 , id2] = *s.begin() ; s.erase(s.begin()) ;
		auto [val3 , id3] = *s.begin() ; s.erase(s.begin()) ;
		if(val >= 8){
			cout << "YES\n" ;
		} else if(val >= 6){
			if(val2 >= 2){
				cout << "YES\n" ;
			} else {
				cout << "NO\n" ;
			}
		} else if(val >= 4){
			if(val2 >= 4){
				cout << "YES\n" ;
			} else if(val2 >= 2){
				if(val3 >= 2){
					cout << "YES\n" ;
				} else {
					cout << "NO\n" ;
				}
			} else {
				cout << "NO\n" ;
			}
		} else {
			cout << "NO\n" ;
		}
		s.insert({val , id}) ;
		s.insert({val2 , id2}) ;
		s.insert({val3 , id3}) ;
	}
	return 0 ;
}

