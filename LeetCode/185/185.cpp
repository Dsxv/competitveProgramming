#include <bits/stdc++.h>
using namespace std ;

#define int long long
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        map<int,vector<int>> mp ;
        for(int i = 0 ; i < routes.size() ; i++){
            for(int j = 0; j < routes[i].size() ; j++){
                mp[routes[i][j]].push_back(i) ;
            }
        }
		queue<pair<int,int>> q ;
		q.push({S,0}) ;
		bool visited[(int)routes.size()] = {} ;
		while(q.size()){
			cout << "hello" ;
			int tp = q.front().first ;
			int d = q.front().second ;
			if(tp == T){
				return d ;
			}
			q.pop() ;
			vector<int>& v = mp[tp] ;
			for(auto i : v){
				if(!visited[i]){
					visited[i] = 1 ;
					for(auto j : routes[i]){
						q.push({j,i}) ;
					}
				}
			}
		}
        return -1;
    }
};
int32_t main(){
	Solution s ;
	int n , m;
	cin >> n >> m;
	vector<vector<int>> v(n,vector<int>(m)) ;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++){
			cin >> v[i][j] ;
		}
	}
	cout << s.numBusesToDestination(v,1,6) ;
	return 0 ;
}

