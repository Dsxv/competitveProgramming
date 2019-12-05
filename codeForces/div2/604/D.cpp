#
#include <bits/stdc++.h>
using namespace std ;
 
#define int long long
 
void print(int a , int b, int x){
	cout << "YES\n" ;
	if( x == 0 ) { cout << x <<" " ;
	for(int i = 0 ; i < b ; i++) cout << x + 1 << " " << x <<" " ;
	} else{
		cout << x + 1 << " " ;
		for(int i = 0 ; i < b ; i++) cout << x << " " << x + 1 << " " ; 
	}
}
 
int32_t main(){
	int a , b , c, d ;
	cin >> a >> b >> c >> d ;
	int n = a + b + d + c ;
	vector<int> x , y ;
	if(a > b + 1 || d > c + 1){
		cout << "NO" ;
		return 0 ;
	}
	if(a == b+1){
		if(c +d == 0) print(a,b,0) ;
		else cout << "NO" ; return 0 ;
	} 
	if(d == c+1){
		if(a+b == 0) print(d,c,2) ;	
		else cout << "NO" ; return 0  ;
	}
	b -= a , c -= d;
	if(abs(b-c) > 1){
		cout << "NO" ; return 0 ;
	}
	if(b > c) x.push_back(2) ;
	while(a--){
		x.push_back(1) ; x.push_back(2) ;
	} 
	while(d--){
		y.push_back(3) ; y.push_back(4) ;
	}
	if(c > b) y.push_back(3) ;
	int t = min(c,b) ;
	while(t--){
		x.push_back(3) ; x.push_back(2) ;
	}
	for(auto i : y) x.push_back(i) ;
	assert(x.size() == n) ;
	cout << "YES\n" ;
	for(auto i : x) cout << i - 1<<" " ;
	return 0 ;
}
