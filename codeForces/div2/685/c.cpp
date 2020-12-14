#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , k ;
		cin >> n >> k ;
		string temp1 , temp2 ;
		cin >> temp1 >> temp2 ;
		int a[26] = {} , b[26] = {} ;
		for(auto i : temp1){
			a[i-'a']++ ;
		}
		for(auto i : temp2){
			b[i-'a']++ ;
		}
		bool found = true ;
		for(int i = 0 ; i < 26 ; i++){
			if(b[i] > a[i]){
				found = false ;
				break ;
			}
			if(i < 25){
				int rem = a[i] - b[i] ;
				a[i + 1] += (rem / k) * k ;
			}
		}
		cout << (found ? "YES\n" : "NO\n") ;
	}
	return 0 ;
}

