#include <bits/stdc++.h>
using namespace std ;

#define int long long

int numberSorter(int n){
	string s = to_string(n) ;
	sort(s.begin() , s.end() , greater<char>()) ;
	return stoi(s) ;
}
int32_t main(){
	int n ;
	cin >> n ;
	cout << numberSorter(n) ;
	return 0 ;
}

