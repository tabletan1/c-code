#include <iostream>
#include "LeafNode.h"
#include "InternalNode.h"
#include "QueueAr.h"

using namespace std;
void sortInsert(int value, int *values, int count);
void deleMin(int *values, int count );

LeafNode::LeafNode(int LSize, InternalNode *p,
  BTreeNode *left, BTreeNode *right) : BTreeNode(LSize, p, left, right)
{
  values = new int[LSize];
}  // LeafNode()



int LeafNode::getMinimum()const
{
  if(count > 0)  // should always be the case
    return values[0];
  else
    return 0;

} // LeafNode::getMinimum()


LeafNode* LeafNode::insert(int value)
{
	if(count < leafSize)
	{
		sortInsert(value, values, count);
		count ++;
		return NULL;
	}
	if(getLeftSibling() && ((LeafNode*)getLeftSibling())->getCount() < leafSize)
	{
		if(getMinimum() < value)
		{
			int mini = getMinimum();
			((LeafNode*)getLeftSibling())->insert(mini);
			deleMin(values, count);
			count --;
			sortInsert(value, values, count);
			count ++;	
		}
		else
		{
			((LeafNode*)getLeftSibling())->insert(value);
		}
		return NULL;	
	}
	
	if(getRightSibling() && ((LeafNode*)getRightSibling())->getCount() < leafSize)
    	{	
        	if(values[count-1] < value)
            	((LeafNode*)getRightSibling())->insert(value);      	
        	else
			{
				((LeafNode*)getRightSibling())->insert(values[--count]);	
    			sortInsert(value, values, count);
				count++;
			}
		
	return NULL;
	}
	LeafNode *newNode = new LeafNode(this->leafSize, this->parent, NULL, NULL);
	sortInsert(value, values, count);
	for(int i = (count+1)/2; i <= count; i++)
		newNode->insert(values[i]);
	count = (count+1)/2;
	LeafNode * ptr = NULL;
	if(getRightSibling())
		ptr = ((LeafNode*)rightSibling);
		
        newNode->setRightSibling(ptr);
	newNode->setLeftSibling(this);
	setRightSibling(newNode);
	if(ptr)
		ptr->setLeftSibling(newNode);
	return newNode;
	// to avoid warnings for now.
}// LeafNode::insert()

void LeafNode::print(Queue <BTreeNode*> &queue)
{
  cout << "Leaf: ";
  for (int i = 0; i < count; i++)
    cout << values[i] << ' ';
  cout << endl;
} // LeafNode::print()

void sortInsert(int value, int *values, int count)
{
	int i = 0;
	for (i = count; i > 0 && values[i-1] > value; i--)
    {
      values[i] = values[i-1];
    }
    values[i] = value;
}

void deleMin(int *values, int count )
{
 	for(int i = 1; i < count; i++)
      values[i-1] = values[i];
}


