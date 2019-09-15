#include<stdio.h>

struct Node
{
	int value;
	Node* next;
	Node* previous;
	Node();
	Node(int);
};
Node::Node(){
	this->next=0;
}
Node::Node(int value){
	this->value=value;
	this->next=0;
}
//list struct
struct List
{
	Node* initial;
	int length;
	List();
	bool add(int);
	bool remove(int);
	int get(int);
};
List::List(){
	this->length=0;
	this->initial=0;
}
bool List::add(int value){
	Node* newNode=new Node(value);

	if(this->initial==0){
		this->initial=newNode;
		this->length++;
		return true;
	}

	Node* lastNode = this->initial;
	for (; lastNode->next!=0;lastNode=lastNode->next){}

	lastNode->next=newNode;
	newNode->previous=lastNode;

	this->length++;

	return true;
}
bool List::remove(int index){
	if(index<0||index>this->length)
		return false;

	if(index==0){
		this->initial->next->previous=0;
		this->initial=this->initial->next;
		this->length--;
		return true;
	}
	
	Node* actualNode = this->initial;
	for (int aux=0; actualNode->next!=0; actualNode=actualNode->next,aux++)
	{
		if(aux==index){
			actualNode->previous->next=actualNode->next;
			actualNode->next->previous=actualNode->previous;
			this->length--;
			return true;
		}
	}
	actualNode->previous->next=0;
	actualNode->previous=0;
	this->length--;
	return true;
}
int List::get(int index){
	if(index<0||index>=this->length)
		return -1;
	
	Node* actualNode = this->initial;
	for (int aux=0; actualNode->next!=0; actualNode=actualNode->next,aux++)
	{
		if(aux==index){
			return actualNode->value;
		}
	}
	return actualNode->value;
}
//main
int	main(){
	List ls;
	//add elements
	ls.add(11);
	ls.add(22);
	ls.add(33);
	ls.add(44);
	ls.add(55);

	for (int i = 0; i < ls.length; i++)
	{
		printf("%i\n",ls.get(i));
	}

	printf("\n");
	//remove elements
	ls.remove(0);
	ls.remove(0);
	ls.remove(0);

	for (int i = 0; i < ls.length; i++)
	{
		printf("%i\n",ls.get(i));
	}

	printf("\n");
	//add new elements
	ls.add(600);
	ls.add(700);

	for (int i = 0; i < ls.length; i++)
	{
		printf("%i\n",ls.get(i));
	}

	return 0;
}