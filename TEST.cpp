// 链表逆置.cpp : 
#include "stdafx.h"
#include <iostream>
using namespace std;
typedef struct Link{
	int data;
	struct Link *next;
};
Link *createLink(Link *head){
	Link *p = new Link;
	head=p;
	int i;
	for (i=0; i<99;i++){
		Link *q = new Link;
		p->data=i+1;
		p->next=q;
		p=q;
	}
	p->data=i+1;
	p->next=NULL;
	return head;
}
void printLink(Link *head){
	Link *p=head;
	cout<<"打印链表:";
	while(p!=NULL){
		cout<<p->data<<"->";
		p=p->next;
	}
	cout<<"NULL"<<endl;
}
Link *Reverse(Link *head){
	Link *pre=NULL;
	Link *curr = head;
	Link *next;
	while(curr!=NULL){
		next = curr->next;
		curr->next=pre;
		pre=curr;
		curr=next;
	}
	return pre;
}
int main(){
	cout<<"开始创建链表"<<endl;
	Link *head=NULL;
	head=createLink(head);
	cout<<"创建链表完成"<<endl;
	cout<<"开始打印链表"<<endl;
	printLink(head);
	cout<<"打印链表完成"<<endl;
	cout<<"开始逆置链表"<<endl;
	head=Reverse(head);
	printLink(head);
	cout<<"逆置链表打印完成"<<endl;
	return 0;
}
