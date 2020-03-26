#include<bits/stdc++.h>
using namespace std;
#define int long long 
map<int, int> dp;
int mod = 1e9 + 7;

int getsum (int n)
{
    int sum = n*(n+1);
    return sum/2;
}
int getsum2(int right_most)
{
    int left = (1LL << right_most) -1 ;
    int right = (1LL<<(right_most+1)) -1 ;
    int sum = getsum(right) - getsum(left);
    return sum;
}
int solve(int n)
{
    if( n == 1 || n == 0)
        return n;
    if(dp.count(n))
        return dp[n];
    int right_most = log2(n);
    int rem = n ^ (1LL<<right_most);
    int sum = getsum2(right_most);
    return  dp[n] = ((sum%mod*(rem+1)%mod)%mod + solve(rem)%mod + solve((1LL<<right_most)-1)%mod )%mod;
}
int32_t main(){
    int t;
    while(t--)
    {
        int n ; 
        cin >> n ;
        int res = solve(n);
        cout<< res <<endl;
    }
}
