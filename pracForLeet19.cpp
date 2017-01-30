#include <iostream>
#include <stdlib.h>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
};
int getLength(ListNode* head)//得到Linkedlist的长度
{
	if (head)
	{
		ListNode* p = head;
		int n = 0;
		while (p)
		{
			n++;
			p = p->next;
		}
		return n;
	}
	else
	{
		return 0;
	}
}
int findLength(ListNode* head)
{
	ListNode* p = head;
	int count = 0;
	while (p!=NULL)
	{
		++count;
		p = p->next;
	}
	return count;
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
int getNthNode(ListNode* head,int index)
{
	ListNode* p = head;
	int count = 0;
	while (p!=NULL)
	{
		++count;
		if (count==index)
		{
			return p->val;
		}
		else
		{
			p = p->next;
		}
	}
	//in case the index is out of range
	cout<<"index too big or too small"<<endl;
	return 0;
}
//删掉倒数第N个的Node
ListNode* removeNthFromEnd(ListNode* head, int n)
{
	int len = getLength(head);
	if (len==0)
	{
		return head;
	}
	else if (len==1)//要考虑极端情况，如果只有一个Node，就return NULL
	{
		return NULL;
	}
	else
	{
		if (n!=0 && n!=len && n!=1)
		{
			ListNode* p = head;
			int index = len - n;
			for (int i = 0; i<index-1;i++)
			{
				ListNode* temp = p->next;
				p = temp;
			}
			ListNode* q;
			q = p->next;
			p->next = q->next;
			delete q;
			return head;
		}
		else if(n==0 || n==1)//if want to remove the last Node
		{
			ListNode* p1 = head;
			for (int j = 0; j<len-2;j++)
			{
				ListNode* temp1 = p1->next;
				p1 = temp1;//move p1 to 2nd last Node
			}
			//cout<<"p1->val"<<p1->val<<endl;
			delete p1->next;
			p1->next = NULL;
			return head;
		}
		else//n==len,means we want to delete the head
		{//first Node很难删除，我就把1st Node赋上2nd Node的值，然后删掉2nd Node
			ListNode* p2;
			p2 = head->next;
			head->val = p2->val;
			head->next = p2->next;
			delete p2;
			return head;
		}
	}
}
int main()
{
	ListNode* china = new ListNode(20);
	china->next = new ListNode(15);
	china->next->next = new ListNode(10);
	china->next->next->next = new ListNode(5);
	china->next->next->next->next = new ListNode(0);
	cout<<"Before:"<<endl;
	printLinkedList(china);
	removeNthFromEnd(china,5);
	cout<<"After:"<<endl;
	printLinkedList(china);
	return 0;
}