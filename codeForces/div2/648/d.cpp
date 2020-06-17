#include <bits/stdc++.h>
using namespace std ;

#define int long long

int xx[4] = {1 , -1 , 0 , 0} ;
int yy[4] = {0 , 0 , 1 , -1} ;

int32_t main(){
	int t ;
	cin >> t ;
	while(t--){
		int n , m ;
		cin >> n >> m ;
		char ch[n][m] ;
		int cnt = 0 ;
		for(int i = 0 ; i < n ; i++){
			for(int j = 0 ; j < m ; j++){
				cin >> ch[i][j] ;
				cnt += ch[i][j] == 'G' ;
			}
		}
		bool visited[n][m] = {} ;
		visited[n-1][m-1] = 1 ;
		queue<pair<int,int>> q ;
		q.push({n-1,m-1}) ;
		bool found = true ;
		for(int i = 0 ; i < 4 ; i++){
			int xi = xx[i] + n - 1 ;
			int yi = yy[i] + m - 1 ;
			if(xi >= 0 && xi < n && yi >= 0 && yi < m){
				if(ch[xi][yi] == 'B') found = false ;
			}
		}
		if(!found && cnt){
			cout << "No\n";
			continue ;
		}
		int count = 0 ;
		while(q.size()){
			int x = q.front().first , y = q.front().second ;
			count += ch[x][y] == 'G' ;
			q.pop() ;
			for(int i = 0 ; i < 4 ; i++){
				int xi = xx[i] + x , yi = yy[i] + y ;
				if(xi >= 0 && xi < n && yi >= 0 && yi < m && !visited[xi][yi]){
					if(ch[xi][yi] == '.' || ch[xi][yi] == 'G'){
						bool ok = true ;
						for(int j = 0 ; j < 4 ; j++){
							int xj = xx[j] + xi , yj = yy[j] + yi ;
							if(xj >= 0 && xj < n && yj >= 0 && yj < m) {
								if(ch[xj][yj] == 'B'){
									ok = false ;
								}
							}
						}
						if(ok){
							q.push({xi,yi}) ;
							visited[xi][yi] = 1;
						}
					}
				}
			}
		}
		if(cnt == count){
			cout << "Yes\n";
		} else {
			cout << "No\n" ;
		}
	}
	return 0 ;
}

