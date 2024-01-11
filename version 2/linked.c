// Bowei Kou
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "node.h"
#include "linkedlist.h"
#include "altmem.h"

#include "linked.h"


// Allocate memory for the node
static Node* allocate_node(void *data, int text){
	Node *node;
	static int count = 0;
	
	if(node=alternative_malloc(sizeof(struct Node))){
		count++;
		node->data = data;
		node->next = NULL;
		if(text)printf("DIAGNOSTIC: %d nodes allocated.\n", count);
	}else{
		if(text)printf("ERROR: linkedlist.c: Failed to malloc a Node.\n");
	}
	return node;
}

// free the memory for the data and node
static void free_node(void *data, int text){
	static int freed=0;
	
	if(data){
		freed++;
		alternative_free(data);
		if(text)printf("DIAGNOSTIC: %d nodes freed.\n", freed);
	}else{
		if(text)printf("ERROR: tried to free NULL pointer.\n");
	}
}

// iterate the linked list
void iterate(void *head, ActionFunction doThis){
	Node *node = head;
	while(node!=NULL){
		doThis(node->data);
		node = node->next;
	}
	
}

// count the number in linked list
int count(void *head, CriteriaFunction countThis, void *helper){
	Node *node = head;
	int num=0;
	while(node != NULL){
		if(countThis(node->data, helper))num++;
		node = node->next;
	}
	return num;
}

//insert a node into linked list
bool insert(void* p2head, void *data, ComparisonFunction goesInFrontOf, int text){
	Node **node = p2head;
	Node *newnode = allocate_node(data, text);
	
	if(newnode==NULL)return false;
	while(*node != NULL&&!goesInFrontOf(data, (**node).data)){
		node = &((**node).next);
	}
	newnode->next=*node;
	*node=newnode;
	return true;
}

// delete the nodes in linked list
int deleteSome(void *p2head, CriteriaFunction mustGo, void *helper, ActionFunction disposal, int text){
	Node** node=p2head;
	int count=0;

	while(*node!=NULL){
		if(mustGo((**node).data, helper)){
			Node* delete = *node;
			*node = (**node).next;
			disposal(delete->data);
			free_node(delete, text);
			count++;
		} else{
			node=&((**node).next);
		}
	}
	return count;
}

// sort the data in linked list
void sort(void *hptr, ComparisonFunction cf){
	Node *node=hptr;
	Node *current;
	bool swp = true;
	
	while(swp){
		swp=false;
		current = node;
		while(current->next!=NULL){
			if(cf(current->next->data, current->data)){
				void *tem=current->data;
				current->data=current->next->data;
				current->next->data=tem;
				swp=true;
			}
			current=current->next;
		}
	}
}

