#include <bits/stdc++.h>
using namespace std;

#define int long long

void print(int* a , int n){
	cout << "YES ";
	for(int i = 0 ; i < n ; i++) cout << a[i] << " ";
	cout << '\n' ;
}

int32_t main(){
	int t;
	cin >> t ;
	while(t--){
		int n , p;
		cin >> n >> p;
		int cn[n] = {} ;
		int a[n] ;
		int ind = -1 ;
		for(int i = 0 ; i < n ; i++){
			cin >> a[i] ;
			if(p%a[i]) ind = i ;
		}
		if(ind != -1){
			cn[ind] = ceil((double)p/a[ind]) ;
			print(cn,n) ;
			continue ;
		}
		int ind1 = -1 , ind2 = -1;
		for(int i = 0 ; i < n-1 ; i++){
			if((a[i] != 1) && __gcd(a[i],a[i+1]) != a[i]){
				ind1 = i ; ind2 = i+1 ;
				break ;
			}
		}
		if(ind1 == -1){
			cout << "NO\n" ;
			continue ;
		} else {
			if(a[ind1] < a[ind2]) swap(ind1,ind2) ;
			cn[ind1] = (p-1)/a[ind1] ;
			double rem = p - cn[ind1]*a[ind1] ;
			double x = a[ind2] ;
			cn[ind2] = ceil(rem/x) ;
			print(cn, n) ;
		}
	}
	return 0;
}
