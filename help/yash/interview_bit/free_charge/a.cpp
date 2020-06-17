#include <bits/stdc++.h>
using namespace std ;

#define int long long

struct ListNode {
	int val ;
	ListNode* next ;
	ListNode(int x){
		val = x ;
		next = nullptr ;
	}
} ;

 ListNode* solve(ListNode* head, ListNode* last){
	ListNode* prevv = last;
	while ( head != last ){
		auto x = head->next;
		head->next = prevv;
		prevv = head;
		head = x;
	}
	return prevv;
}

ListNode* reverseList(ListNode* A, int B) {
	auto node = A;
	for (int i=0; i < B; ++i){
		if ( node == nullptr)
			return A;
		node = node->next;
	}

	auto new_head = solve( A, node);
	A->next = Solution::reverseList( node, B);
	return new_head;
}
void print(ListNode* head){
	while(head){
		cout << head->val << " " ;
		head = head->next ;
	}
}

int32_t main(){
	ListNode* head  = new ListNode(1);
	head->next = new ListNode(2) ;
	head->next->next = new ListNode(3) ;
	auto ans = reverseList(head , 2) ;
	print(ans) ;
	return 0 ;
}

