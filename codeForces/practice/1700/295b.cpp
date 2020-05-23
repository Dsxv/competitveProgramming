#include <bits/stdc++.h>
using namespace std ;

#define int long long

const int N = 505 ;
int gt[N][N] ;
int g[N][N] ;

int32_t main(){
	int n ;
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> gt[i][j] ;
		}
	}
	int x[n] ;
	for(int i = 0 ; i < n ; i++){
		cin >> x[i] ;
		x[i]-- ;
	}
	reverse(x,x+n) ;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			g[i][j] = INT_MAX ;
			g[i][j] = gt[x[i]][x[j]] ;
		}
		g[i][i] = 0 ;
	}

	vector<int> ans ;
	for(int k = 0 ; k < n ; k++){
			// between first k - 1 nodes , using first k - 1 nodes
			// k - 1 nodes have min dist between them
			// so i'd like the kth node is also on the same state as prev one's
			int sum = 0 ;
			for(int i = 0 ; i < k ; i++){
				for(int j = 0 ; j < k ; j++){
					g[k][i] = min(g[k][i] , g[k][j] + g[j][i]) ;
					g[i][k] = min(g[i][k] , g[i][j] + g[j][k]) ;
				}
			}
			// you sure for above ? ?
			// min distance of k from all nodes till 0 to k
			// basically floyd-warshal now
			for(int i = 0 ; i <= k ; i++){
				for(int j = 0 ; j <= k ; j++){
					g[i][j] = min(g[i][j] , g[i][k] + g[k][j]) ;
				}
			}
			for(int i = 0 ; i <= k ; i++){
				for(int j = 0 ; j <= k ; j++){
					if(g[i][j] < INT_MAX){
						sum += g[i][j] ;
					}
				}
			}
			ans.push_back(sum) ;
	}
	reverse(ans.begin() , ans.end()) ;
	for(auto i : ans) cout << i << " ";
	return 0 ;
}
