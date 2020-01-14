#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int t ;
	cin >> t ;
	while(t--){
		int n ;
		cin >> n ;
		if(n%2){
			if(n == 1) {
				cout << "Hooray\n1" ;
			} else {
				cout << "Boo\n";
			}
			continue ;
		}
		cout << "Hooray\n";
		int a[n][n] = {};
		vector<int> v ;
		for(int i = 2 ; i <= n ; i++) v.push_back(i) ;
		for(int i = 0 ; i < n ; i++) a[i][i] = 1 ;
		for(int j = 1 ; j < n ; j++) {
			int ind = j-1 ; 
			for(int i = 0 ; i < j ; i++){
				a[i][j] = v[ind] ;
				ind = (ind + 1 + (j == n-1))%(n-1) ;
			}
		}
		//for(int i = 0 ; i < n ; i++){
			//for(int j = 0 ; j < n ; j++) {
				//cout << a[i][j] << " " ;
			//}
			//cout << endl ;
		//}
		for(int i = 0 ; i < n ; i++){
			for(int j = i + 1 ; j < n ; j++){
				a[j][i] = a[i][j] + n - 1 ;
			}
		}
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < n ; j++)
				cout << a[i][j] << " " ;
			cout << endl ;
		}
	}
	return 0 ;
}

