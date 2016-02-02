#include <iostream>
#include "list.h"

List::List() {
	first = nullptr;
}

List::~List() {
	Node* temp = first;

	while(first == nullptr){
		while(temp == nullptr){
			temp = temp->next;
		}
		delete temp;
		temp = first;
	}
}

bool List::exists(int d) const {
	Node* temp = first;
	while(temp != nullptr){
		if(temp->value ==d ){
			return true;
		}
		temp = temp->next;
	}
	return false;
}

int List::size() const {
	Node* temp = first;
	int size=0;
	while(temp != nullptr){
		++size;
		temp = temp->next;
	}
	return size;
}

bool List::empty() const {
	return (first == nullptr);
}

void List::insertFirst(int d) {
	if(first == nullptr){
		first = new Node (d,nullptr);
	}else{
		Node* temp = new Node(d, first);
		first = temp;
	}
}

void List::remove(int d, DeleteFlag df) {
	Node* temp = first;
	Node* before = first;
	Node* temp2;


	while(temp != nullptr){
		switch(df){
			case DeleteFlag::EQUAL:
				if (temp->value == d && temp->next == nullptr){
					before->next = nullptr;
					delete temp;
					return;
				}
				else if(temp->value == d && temp == first){
					temp2 = first;
					first = temp->next;
					delete temp2;
					return;
				}
				else if(temp->value == d ){
					temp2 = temp;
					temp = temp->next;
					before->next = temp;
					delete temp2;
					return;


				}
				break;
			case DeleteFlag::GREATER:
				if (temp->value > d && temp->next == nullptr){
					before->next = nullptr;
					delete temp;
					return;
				}
				else if(temp->value > d && temp == first){
					temp2 = first;
					first = temp->next;
					delete temp2;
					return;
				}
				else if(temp->value > d ){
					temp2 = temp;
					temp = temp->next;
					before->next = temp;
					delete temp2;
					return;


				}
				break;
			case DeleteFlag::LESS:
				if (temp->value < d && temp->next == nullptr){
					before->next = nullptr;
					delete temp;
					return;
				}
				else if(temp->value < d && temp == first){
					temp2 = first;
					first = temp->next;
					delete temp2;
					return;
				}
				else if(temp->value < d ){
					temp2 = temp;
					temp = temp->next;
					before->next = temp;
					delete temp2;
					return;


				}
				break;
			default: break;
		}

		before = temp;
		temp = temp->next;	
	}
}

void List::print() const {
	Node* temp = first;
	while(temp != nullptr){
		std::cout<<temp->value<<std::endl;
		temp = temp->next;
	}
}

