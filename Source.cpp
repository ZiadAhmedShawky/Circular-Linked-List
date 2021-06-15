#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
};
node* head;
void create(int A[], int n)
{
	node* t, * last;
	head = new node;
	head->data = A[0];
	head->next = head;
	last = head;
	for (int i = 1; i < n; i++)
	{
		t = new node;
		t->data = A[i];
		t->next = last->next;
		last->next = t;
		last = t;

	}
}
void display()
{
	node* p;
	p = head;
	do 
	{
		cout << p->data << " ";
		p = p->next;
	} while (p != head);
}
int count(node* p)
{
	p = head;
	int len = 0;
	do {
		len++;
		p = p->next;
	} while (p != head);
	return len;
}
void insertCircularNode(int value,int position)
{
	node* p, * t;
	p = head;
	t = new node;
	t->data = value;
	//t->next = NULL;
	if (position<0 || position>count(p))
		return;
	if (position == 0)
	{
		if (head == NULL)
		{
			head = t;
			head->next = head;
		}
		else
		{
			while (p->next != head)
			{
				p = p->next;
			}
			p->next = t;
			t->next = head;
			head = t;
		}
	}
	else
	{
		for (int i = 0; i < position - 1; i++)
		{
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}


}
void Delete(int position)
{
	node* p, * q=NULL;
	p = head;
	if (position<1 || position>count(p))
		return;
	if (position == 1)
	{

		while (p->next != head)
		{
			p = p->next;
		}
			if (head == p)
			{
				delete head;
				head = NULL;
			
			}
			else
			{
				p->next = head->next;
				delete head;
				head = p->next;
			}
		
		

	}
	else
	{
		p = head;
		for (int i = 0; i < position - 1; i++)
		{
			q = p;
			p = p->next;
		}
		q->next=p->next;
		delete p;


	}
}
int main()
{
	int arr[] = { 1,2,3,4,5 };
	create(arr, 5);
	Delete(1);
	display();
}