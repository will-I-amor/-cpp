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
//print是调试时使用的
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
//用来解24题的function
//假设我们的LinkedList是20->15->10->5->0
ListNode* swapinPair(ListNode* head)//24题：不能改变node里的值，而且只能用constant的space//然后，使用recursion不是用的constant space
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
	else//之前的recursion得到了segmentation fault因为传参不对。我是先把p->next改成指向前面的Node，然后又把p->next传进recursion	
	{
		head->next = swapinPair(p->next);
		p->next = head;
		return p;
	}//正确的做法是先把p->next传进去，这样后面那一大块，就可以在recursion中计算
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
