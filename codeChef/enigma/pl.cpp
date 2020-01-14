#include <bits/stdc++.h>
using namespace std ;

#define int long long

int x[] = {0,0,1,-1} ;
int y[] = {1,-1,0,0} ;

int32_t main(){
	ios :: sync_with_stdio(0) ;
	cin.tie(0) ;
	int n;
	cin >> n ;
	if(n == 0){
		cout << "false" ;
		return 0 ;
	}
	bool a[n][n] ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> a[i][j] ;
		}
	} 
	int val ;
	cin >> val ;
	queue<pair<int,int>> q ;
	if(a[0][0]) q.push({0,0});
	map<pair<int,int>, int> mp ;
	while(q.size()){
		int id = q.front().first ;
		int d = q.front().second ;
		q.pop() ;
		int i = id/n , j = id%n ;
		if(i == n - 1 && j == n - 1){
			if(d <= val) {
				cout << d + 1 << " " << val << endl ;
				cout << "true" ;
			} else {
				cout << "false" ;
			}
			return 0 ;
		}
		for(int k = 0 ; k < 4 ; k++){
			int x1 = i + x[k] , y1 = j + y[k] ;
			if(x1 < n && x1 >= 0 && y1 < n && y1 >= 0){
				if(!mp.count({x1,y1}) && a[x1][y1]){
						q.push({x1*n + y1 , d + 1}) ;
						mp[{x1,y1}] = 1 ;
				}
			}
		}
	}
	
	cout << "false" ;
	return 0 ;
}

