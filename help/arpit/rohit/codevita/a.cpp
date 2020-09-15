#include <bits/stdc++.h>
using namespace std ;

#define int long long

int solve(map<int,int>& r , int n){
	int ans = 0;
    int lr[n][n] = {} ;
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < n; j++){
            if(r[i]>0){
                lr[i][j] = 0;
                r[i]--;
            } else {
                lr[i][j] = 1;
            }
        }
    }
    int dp[n][n] = {};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if( i==0 || j==0 ){
                dp[i][j] = lr[i][j];
            }
            else if(lr[i][j]==1){
                dp[i][j]= min({ dp[i-1][j], dp[i-1][j-1], dp[i][j-1]})+1;
            }
            else if(lr[i][j]==0){
                dp[i][j]=0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
	return ans ;
}

int32_t main() {
	int n ;
    cin >> n;
    char a[n][n];
    map<int,int> r;
    map<int,int> c;
	r.clear() ; c.clear() ;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++){
            cin >> a[i][j];
            if(a[i][j] == 'C'){
                r[i]++;
                c[j]++;
            }
        }
    }
    cout << max(solve(r,n) , solve(c,n)) ;
}

