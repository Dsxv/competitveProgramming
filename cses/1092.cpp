#include <bits/stdc++.h>
using namespace std ;

#define int long long

int32_t main(){
	int n ;
	cin >> n;
	if((n*(n+1) / 2) % 2 == 0){
		cout << "YES\n" ;
		int visited[n+1] = {} ;
		if(n%2) {
			visited[n/2] = 1 ;
			visited[n/2 + 1] = 1;
			for(int i = 1 ; i < n / 2 ; i += 2){
			visited[n-i] = 1 ;
			visited[i] = 1 ;
			}
		} else {
			for(int i = 1 ; i < n / 2 ; i += 2){
				visited[i] = 1 ;
				visited[n-i+1] = 1 ;
			}
		}
		cout << count(visited , visited + n + 1 , 1) << '\n' ;
		for(int i = 1 ; i <= n ; i++){
			if(visited[i]) cout << i << " " ;
		}
		cout << '\n' ;
		cout << count(visited + 1, visited + n + 1 , 0) << '\n' ;
		for(int i = 1 ; i <= n ; i++){
			if(!visited[i]) cout << i << " " ;
		}
	} else {
		cout << "NO\n" ;
	}
	return 0 ;
}

