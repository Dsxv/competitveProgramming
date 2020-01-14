#include <bits/stdc++.h>
using namespace std ;

#define int long long

int fact(int n){
	return	n > 1 ? fact(n-1)*n : 1 ;
}

int check(vector<int>& a , vector<int>& b){
	for(int i = 0 ; i < a.size() ; i++){
		if(a[i] != b[i]) {
			if(a[i] > b[i]) return 1 ;
			else return -1 ;
		}
	}
	return 0 ;
}

int32_t main(){
	int n ;
	cin >> n ;
	vector<int> a(n) , b(n) ;
	for(int i = 0 ; i < n ; i++) cin >> a[i] ;
	for(int i = 0 ; i < n  ;i++) cin >> b[i] ;
	if(check(a,b) == 1){
		vector<int> c(a) ;
		a = b ;
		b = c ;
	}
	int count = 0 ;
	do{
		if(check(a,b) == 0){
			break ;
		}
		count++ ;
	} while(next_permutation(a.begin(),a.end())) ;
	cout << count ;
	return 0 ;
}

