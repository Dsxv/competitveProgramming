#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e6 + 20 ;
int a[N] ;

void div(int x){
    int l = sqrt(x) ;
    for(int i = 1 ; i <= l ; i++){
        if(x%i) continue ;
		if(i == l){
            a[i]++ ;
        }else{
            a[i]++ ;
            a[x/i]++ ;
        }
    }
}

int32_t main() {
    int n ;
    cin >> n  ;
    for(int i = 0 ; i < n ; i++){
        int x ;
        cin >> x ;
        div(x) ;
    }
	int mx = 0 ;
    for(int i = 0 ; i < N ; i++){
        mx = max(mx,a[i]*i) ;
    }
    cout << mx ;
    return 0 ;
}
