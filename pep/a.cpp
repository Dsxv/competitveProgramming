#include <bits/stdc++.h>
using namespace std ;

#define int long long

int xx[4] = {0 , 0 , 1 , -1} ;
int yy[4] = {1 , -1 , 0 , 0} ;


int32_t main(){
	int n , m ;
	cin >> n >> m ;
	int a[n][m] ;
	int count = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin >> a[i][j] ;
			if(a[i][j] == 1) count++ ;
		}
	}
	int visited[n][m] = {} ;
	queue<vector<int>> q ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			if(a[i][j] == 2){
				vector<int> v = {i , j , 0} ;
				visited[i][j] = 1 ;
				q.push(v) ;
			}
		}
	}
	int cnt = 0 ;
	int mxd = 0 ;
	while(q.size()){
		vector<int> v = q.front() ; 
		int x = v[0] , y = v[1] , d = v[2] ;
		mxd = max(d , mxd) ;
		q.pop() ;
		for(int i = 0 ; i < 4 ; i++){
			int xi = xx[i] + x ;
			int yi = yy[i] + y ;
			if(xi >= 0 && xi < n && yi >= 0 && yi < m && !visited[xi][yi] && a[xi][yi]){
				vector<int> temp = {xi , yi , d+1} ;
				q.push(temp) ;
				visited[xi][yi] = 1 ;
				cnt++ ;
			}
		}
	}
	cout << mxd << endl ;
	cout << (count == cnt?"true":"false") ;
	return 0 ;
}

