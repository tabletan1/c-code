#include <iostream>
#include <fstream>
#include <string>
#include "vector.h"
#include "CPUTimer.h"
#include "LinkedList.h"
#include "StackAr.h"
#include "CursorList.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "SkipList.h"

vector<CursorNode <int> > cursorSpace;

using namespace std;

void RunList(string filename);
void RunCursorList(string filename);
void RunStackAr(string filename);
void RunStackLi(string filename);
void RunQueueAr(string filename);
void RunSkipList(string filename);

int Menu(){
	int choice;
	while(1){
		cout <<"	ADT Menu\n";
		cout<< "0. Quit\n"<<"1. LinkedList\n"<<"2. CursorList\n";
		cout<<"3. StackAr\n"<<"4. StackLi\n"<<"5. QueueAr\n";
		cout<<"6. SkipList\n"<<"Your choice >>\n";
		cin>>choice;
		if (choice<7&&choice>=0){
		return choice;}
		else{
			cout<<"Please choose between 0-6\n";
		}
		
		
	}
	
	}




int main() {

    string filename = "";
	cout << "Filename >> ";
    getline(cin, filename);
	CPUTimer ct;
	int choice;
	do
{
 choice = Menu();
 ct.reset();
 switch (choice)
 {
 case 1: RunList(filename); break;
 case 2: RunCursorList(filename); break;
 case 3: RunStackAr(filename); break;
 case 4: RunStackLi(filename); break;
 case 5: RunQueueAr(filename); break;
 case 6: RunSkipList(filename); break;
 }
 cout << "CPU time: " << ct.cur_CPUTime() << endl;
} while(choice > 0);
	return 0;
	
    }


   

void RunList(string filename) {
    List <int> list;
    ListItr <int> listItr = list.zeroth();
    ifstream inf(filename);
    char command, A[512];
    int value;
    inf.getline(A, 512);

    while (inf >> command >> value) {
        if (command == 'i'){
		list.insert(value, listItr);}
        else if (command == 'd'){
		list.remove(value);}
    } 
    

}

void RunCursorList(string filename) {
    CursorList <int> list(cursorSpace);
    CursorListItr <int> listItr = list.zeroth();
    ifstream inf(filename);
    char command, A[512];
    int value;
    inf.getline(A, 512);

    while (inf >> command >> value) {
        if (command == 'i'){
		list.insert(value, listItr);}
        else if (command == 'd'){
		list.remove(value);}
    }}

void RunStackAr(string filename) {
    StackAr <int> stack(500001);
    ifstream inf(filename);
    char command, A[512];
    int value;
	inf.getline(A, 512);
	while (inf >> command >> value) {
        if (command == 'i'){
		stack.push(value);}
        else if (command == 'd'){
		stack.pop();}
    }} 

void RunStackLi(string filename) {
    StackLi<int> stack;
    ifstream inf(filename);
    int value;
    char command, A[512];
	inf.getline(A, 512);
	while (inf >> command >> value) {
        if (command == 'i'){
		stack.push(value);}
        else if (command == 'd'){
		stack.pop();}
    }} 

void RunQueueAr(string filename) {
    Queue<int> queue(500001);
    ifstream inf(filename);
    int value;
    char command, A[512];
    inf.getline(A, 512);
	while (inf >> command >> value) {
        if (command == 'i'){
		queue.enqueue(value);}
        else if (command == 'd'){
		queue.dequeue();}
    }}

void RunSkipList(string filename) {
    SkipList <int> list(0, 500001);
    ifstream inf;
    int value;
    char command, A[512];
	inf.getline(A, 512);
	while (inf >> command >> value) {
        if (command == 'i'){
		list.insert(value);}
        else if (command == 'd'){
		list.deleteNode(value);}
    }}