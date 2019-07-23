#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        for(auto &i : hours){
			i  = (i <= 8 ? -1 : 1) ;
		}
		stack<pair<int,int>> s ;
        int n = hours.size() ;
        int pre[n + 1] ;
        pre[0] = 0 ;
        for(int i = 0 ; i < n ; i++){
            pre[i+1] = pre[i] + hours[i] ;
        }
        s.push({0,0}) ;
        for(int i = 1 ; i <= n ; i++) {
            if(pre[i] < s.top().first){
                s.push({pre[i],i}) ;
            }
        }
        int maxL = 0 ;
        for(int i = n ; i >= 1; i--){
            while(s.size() && i <= s.top().second){
                s.pop() ;
            }
            while(s.size() && pre[i] - s.top().first > 0){
				maxL = max(i - s.top().second,maxL) ;
                s.pop() ;
            }
        }
        return maxL ;
    }
};

int main() {
	Solution s ;
	vector<int> hours = {9,9,6,0,6,6,9} ;
	cout << s.longestWPI(hours) ;
	return 0;
}
