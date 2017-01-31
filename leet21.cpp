#include <iostream>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{//Merge Two Sorted List, Leetcode 21
	if (l1==NULL){return l2;}
	if (l2==NULL){return l1;}
	else
	{
		if (l1->val > l2->val)
		{
			ListNode* tmp = l2;//get the smallest
			tmp->next = mergeTwoLists(l1,l2->next);
			return tmp;
		}
		else
		{
			ListNode* tmp = l1;
			tmp->next = mergeTwoLists(l2,l1->next);
			return tmp;
		}
	}
}
void printLinkedList(ListNode* head)
{
	ListNode* p = head;
	while (p!=NULL)
	{
		if (p->next!=NULL)
		{
			cout<<p->val<<"->";
			p = p->next;
		}
		else
		{
			cout<<p->val<<endl;
			p = p->next;
		}
	}
}
int main()
{
	ListNode* china = new ListNode(5);
	china->next = new ListNode(10);
	china->next->next = new ListNode(15);
	china->next->next->next = new ListNode(20);
	ListNode* us = new ListNode(11);
	us->next = new ListNode(12);
	us->next->next = new ListNode(21);
	ListNode* anew = mergeTwoLists(china,us);
}