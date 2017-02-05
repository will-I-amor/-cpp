//这个版本是慢速版，因为要用recursion
#include <iostream>
#include <stdlib.h>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
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
ListNode* swapinPair(ListNode* head)
{
	if(!head) {return NULL;}
	ListNode* p = head->next;
	if(!head->next) {return head;}
	if(!p->next)
	{
		p->next = head;
		head->next  = NULL;
		return p;
	}
	else
	{
		head->next = swapinPair(p->next);
		p->next = head;
		return p;
	}
}
int main()
{
	ListNode* china = new ListNode(20);
	china->next = new ListNode(15);
	/*china->next->next = new ListNode(10);
	china->next->next->next = new ListNode(5);*/
	printLinkedList(china);
	ListNode* aNew = swapinPair(china);
	cout<<'\n'<<"after swapping:"<<endl;
	printLinkedList(aNew);
	return 0;
}
