#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "SkipList.h"
#include "QueueAr.h"
#include "LinkedList.h"
#include "CursorList.h"
#include "StackLi.h"
#include "StackAr.h"
#include "vector.h"
#include "CPUTimer.h"

using namespace std;

void RunList(const char filename[])
{
	ifstream inf(filename);
	char command, line[200];
	int data;
	inf.getline(line, 200, '\n');
	List<int> *list = new List<int>();
	ListItr<int> cur = list->zeroth();

	while(inf >> command)
	{
		inf >> data;

		if (command == 'i')
			list->insert(data, cur);
		else if (command == 'd')
			list->remove(data);
	}
}

void RunCursorList(const char filename[])
{
	ifstream inf(filename);
	char command, line[200];
	int data;
	inf.getline(line, 200, '\n');
	vector<CursorNode<int> > cur(500000);
	CursorList<int> *list = new CursorList<int>(cur);
	CursorListItr<int> current = list->zeroth();

	while(inf >> command)
	{
		inf >> data;

		if (command == 'i')
			list->insert(data, current);
		else if (command == 'd')
			list->remove(data);
	}
}

void RunStackAr(const char filename[])
{
	ifstream inf(filename);
	char command, line[200];
	int data;
	inf.getline(line, 200, '\n');
	StackAr<int> *sa = new StackAr<int>(500000);

	while(inf >> command)
	{
		inf >> data;

		if (command == 'i')
			sa->push(data);
		else if (command == 'd')
			sa->pop();
	}
}

void RunStackLi(const char filename[])
{
	ifstream inf(filename);
	char command, line[200];
	int data;
	inf.getline(line, 200, '\n');
	StackLi<int> *sl = new StackLi<int>();

	while(inf >> command)
	{
		inf >> data;

		if (command == 'i')
			sl->push(data);
		else if (command == 'd')
			sl->pop();
	}
}

void RunQueueAr(const char filename[])
{
	ifstream inf(filename);
	char command, line[200];
	int data;
	inf.getline(line, 200, '\n');
	Queue<int> *qa = new Queue<int>(500000);

	while(inf >> command)
	{
		inf >> data;

		if (command == 'i')
			qa->enqueue(data);
		else if (command == 'd')
			qa->dequeue();
	}
}

void RunSkipList(const char filename[])
{
	ifstream inf(filename);
	char command, line[200];
	int data;
	inf.getline(line, 200, '\n');
	SkipList<int> *sl = new SkipList<int>(-1, 500000);

	while(inf >> command)
	{
		inf >> data;

		if (command == 'i')
			sl->insert(data);
		else if (command == 'd')
			sl->deleteNode(data);
	}
}

int main()
{
	CPUTimer ct;
	char filename[10];
	int choice;
	cout << "Filename >> ";
	cin >> filename;

	cout << "      ADT Menu" << endl;
	cout << "0. Quit" << endl;
	cout << "1. LinkedList" << endl;
	cout << "2. CursorList" << endl;
	cout << "3. StackAr" << endl;
	cout << "4. StackLi" << endl;
	cout << "5. QueueAr" << endl;
	cout << "6. SkipList" << endl;

	do {
		cout << "Your choice >> ";
		cin >> choice;
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