#include <iostream>
#include "BTree.h"
#include "BTreeNode.h"
#include "LeafNode.h"
#include "InternalNode.h"
using namespace std;

BTree::BTree(int ISize, int LSize):internalSize(ISize), leafSize(LSize)
{
  root = new LeafNode(LSize, NULL, NULL, NULL);
} // BTree::BTree()


void BTree::insert(const int value)
{
  	BTreeNode *temp = root->insert(value);
	
	if(temp)
	{
		BTreeNode * inter = new InternalNode(internalSize, leafSize, NULL, NULL, NULL);	
		((InternalNode*)inter)->insert(root, temp);
		root->setParent((InternalNode*)inter);
		temp->setParent((InternalNode*)inter);	
		root = inter;
	}
}// students must write this // BTree::insert()


void BTree::print()
{
  BTreeNode *BTreeNodePtr;
  Queue<BTreeNode*> queue(1000);

  queue.enqueue(root);
  while(!queue.isEmpty())
  {
    BTreeNodePtr = queue.dequeue();
    BTreeNodePtr->print(queue);
  } // while
} // BTree::print()
