#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 2e3 + 5 ;
int a[N][N] ;

bool check1(vector<pair<int,int>>& p , int k , int i , int j){
	if(p[i].first == 0) return 1 ;
	//if(j == 2 & i == 2) cout << p[i].first << " " << p[i].second << endl ;
	return p[i].first >= j && p[i].second <= j + k - 1 ;
}

bool check2(vector<pair<int,int>>& p , int i , int j, int k){
	if(p[j].first == 0) return 1 ;
	return p[j].first >= i && p[j].second <= i + k - 1 ;
}

void solve(vector<vector<int>>& ans , int n , int k) {
	vector<pair<int,int>> r(n+1) ;
	int row[n+1]  = {} ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(a[i][j]){
				if(r[i].first == 0) {
					r[i] = {j,j} ;
				} else {
					r[i].second = j ;
				}
			}
			//cout << j << " " << r[i].first << " " << r[i].second << endl ;
		}
		row[i] = row[i-1] + (r[i].first == 0) ;
	}
	for(int j = 1 ; j <= n ; j++) {
		int count = 0 ;
		for(int i = 1 ; i <= k ; i++) {
			count += check1(r,k,i,j) ;
		}
		ans[1][j] = count  + row[n] - row[k];
		//cout << count << endl ;
		for(int i = 2 ; i <= n - k + 1 ; i++){ // i down point of k sqaure
				count -= check1(r,k,i-1,j) ;
				count += check1(r,k,i+k-1,j) ;
				ans[i][j] = count + row[i-1] + row[n] - row[i+k-1] ;
		}
	}
}

int solve2(vector<vector<int>>& ans , int n , int k){
	int col[n+1] = {0} ;
	vector<pair<int,int>> r(n+1) ;
	for(int j = 1 ; j <= n ; j++){
		for(int i = 1 ; i <= n ; i++){
			if(a[i][j]){
				if(r[j].first == 0){
					r[j] = {i,i} ;
				} else {
					r[j].second = i ;
				}
			}
		}
		col[j] = col[j-1] + (r[j].first == 0) ;
	}
	for(int i = 1 ; i <= n ; i++){
		int count = 0 ;
		for(int j = 1 ; j <= k ; j++){
			count += check2(r,i,j,k) ;
		}
		ans[i][1] = count +  col[n] - col[k] ;
		for(int j = 2 ; j <= n - k + 1 ; j++){
			count -= check2(r,i,j-1,k) ;
			count += check2(r,i,j+k-1,k) ;
			ans[i][j] = count + col[j-1] + col[n] - col[j+k-1] ;
		}
	}
}

void print(vector<vector<int>>& v , int n){
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++) cout << v[i][j] << " " ;
		cout << endl ;
	}
}

int32_t main(){
	int n , k ;
	cin >> n >> k ;
	for(int i = 1 ; i <= n ; i++) {
		string s ; cin >> s ;
		s = 'x' + s ;
		for(int j = 1 ; j <= n ; j++) a[i][j] = (s[j] != 'W') ;
	}
	vector<vector<int>> ans(n+1,vector<int>(n+1)) ;
	vector<vector<int>> ans2 = ans ;
	solve(ans,n,k) ;
	solve2(ans2,n,k) ;
	//print(ans,n) ;
	//print(ans2,n) ;
	int val = 0 ;
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			val = max(val , ans[i][j] + ans2[i][j]) ;
		}
	}
	cout << val ;
	return 0 ;
}

