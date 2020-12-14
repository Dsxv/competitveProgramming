#include <bits/stdc++.h>
using namespace std ;

#define int long long

int a[101][101] ;
int n , m ;
vector<vector<int>> ans ;

void print(vector<int>&temp , pair<int,int> &p){
	int i = p.second / m , j = p.second % m ;
	temp.push_back(i) ; temp.push_back(j) ;
	a[i][j] ^= 1 ;
}

int gc(int i , int j){
	int cnt = 0 ;
	for(int x = 0 ; x < 2 ; x++){
		for(int y = 0 ; y < 2 ; y++){
			if(a[i + x][j + y]) cnt++ ;
		}
	}
	return cnt ;
}

int solve(int i , int j){
	vector<pair<int , int>> v ;
	int cnt = 0 ;
	for(int x = 0 ; x < 2 ; x++){
		for(int y = 0 ; y < 2 ; y++){
			if(a[i + x][j + y]) cnt++ ;
			v.push_back({a[i + x][j + y] , (i + x) * m + j + y}) ;
		}
	}
	if(cnt == 0) return 0 ;
	sort(v.begin() , v.end()) ;
	vector<int> temp ;
	if(cnt != 2){
		print(temp , v[1]) ; print(temp , v[2]) ; print(temp , v[3]) ;
	} else{
		print(temp , v[0]) ; print(temp , v[1]) ; print(temp , v[2]) ;
	}
	ans.push_back(temp) ;
	return 1 ;
}

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		ans.clear() ;
		cin >> n >> m;
		for(int i = 0 ; i < n ; i++){
			string s ; cin >> s ;
			for(int j = 0 ; j < m ; j++){
				a[i][j] = s[j] - '0' ;
			}
		}

		for(int i = 0 ; i < n - 2 ; i++){
			for(int j = 0 ; j < m - 1 ; j++){
				vector<int> temp ;
				if(a[i][j] && a[i][j+1]){
					temp = {i , j , i , j + 1 , i + 1 , j + 1} ;
					a[i][j] = a[i][j+1] = 0 ;
					a[i+1][j+1] ^= 1 ;
				}
				if(a[i][j+1]){
					a[i][j+1] = 0 ;
					a[i+1][j+1] ^= 1 ;
					a[i+1][j] ^= 1 ;
					temp = {i , j + 1 , i + 1 , j + 1 , i + 1 , j} ;
				}
				if(temp.size()) ans.push_back(temp) ;
			}
		}
	
		for(int i = n - 2 ; i < n - 1 ; i++){
			for(int j = 0 ; j < m - 1 ; j++){
				if(gc(i , j) == 3) solve(i,j) ; 
			}
		}

		for(int i = n - 2 ; i < n - 1 ; i++){
			for(int j = 0 ; j < m - 1 ; j++){
				while(solve(i,j)) ;
			}
		}

		cout << ans.size() << '\n' ;
		for(auto i : ans){
			for(auto j : i) cout << j + 1 << ' ' ;
			cout << '\n' ;
		}
	}
	return 0 ;
}

