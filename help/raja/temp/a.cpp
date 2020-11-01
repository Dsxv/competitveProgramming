#include <bits/stdc++.h>
using namespace std ;

template <typename T , int count>
void foo(T x){
	T val[count] ;
	for(int i = 0 ; i < count ; i++){
		val[i] = x++ ;
		cout << val[i] << " " ;
	}
} ;

int32_t main(){
	string s = "Hacker Earth" ;
	s.erase(remove(s.begin() , s.end() , ' ') , s.end()) ;
	cout << s ;
	return 0 ;
}

