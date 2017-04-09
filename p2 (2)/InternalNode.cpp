#include <iostream>
#include "InternalNode.h"

using namespace std;
void deleMin(InternalNode* n);

InternalNode::InternalNode(int ISize, int LSize,
  InternalNode *p, BTreeNode *left, BTreeNode *right) :
  BTreeNode(LSize, p, left, right), internalSize(ISize)
{
  keys = new int[internalSize]; // keys[i] is the minimum of children[i]
  children = new BTreeNode* [ISize];
} // InternalNode::InternalNode()


int InternalNode::getMinimum()const
{
  if(count > 0)   // should always be the case
    return children[0]->getMinimum();
  else
    return 0;
} // InternalNode::getMinimum()


InternalNode* InternalNode::insert(int value)
{
	int pos;
	BTreeNode *temp = NULL;
	if(value > keys[count-1])
		temp = children[count-1]->insert(value);
	else
	{
 		for(pos = 1; pos < count; pos++)
		{
			if(keys[pos] > value)
				break;
		}
		temp = children[pos-1]->insert(value);
	}
	updateKeys();
	if(temp)
	{
		if(count < internalSize)
			insert(temp); // insert a new child from LeafNode;
		else
		{
			if(getLeftSibling() && ((InternalNode*)getLeftSibling())->getCount() < internalSize)
        	{       
                if(temp->getMinimum() < getMinimum())
                	((InternalNode*)leftSibling)->insert(temp);
				else    
				{
					((InternalNode*)leftSibling)->insert(children[0]);
					deleMin();
					insert(temp);	                	       
                }
                return NULL;
        	}
			if(getRightSibling() && ((InternalNode*)getRightSibling())->getCount() < internalSize)
            {
                if(value > keys[count-1])
                    ((InternalNode*)rightSibling)->insert(temp);
                else
                {
                    ((InternalNode*)rightSibling)->insert(children[count-1]);
                    count--;
                    insert(temp);
                }
                return NULL;
            }
			InternalNode* newNode = new InternalNode(internalSize, leafSize, parent, this, NULL);
			InternalNode* temp1 = NULL;
			if(getRightSibling())
				temp1 = ((InternalNode*)getRightSibling());
			newNode->setRightSibling(temp1);
			if(temp1)
				temp1->setLeftSibling(newNode);
			setRightSibling(newNode);
    		for(int i = (count+1)/2; i < count; i++)
    			newNode->insert(children[i]);
    		count = (count+1)/2;
    		if (temp->getMinimum() > keys[count-1])
        		newNode -> insert(temp);
    		else
    		{	
        		newNode -> insert(children[--count]);
        		insert(temp);
    		}
			return newNode;
		}
	}
	return NULL;
 	 // to avoid warnings for now.
} // InternalNode::insert()

void InternalNode::insert(BTreeNode *oldRoot, BTreeNode *node2)
{ // Node must be the root, and node1
	children[0] = oldRoot;
    children[1] = node2;
    count = count + 2;
    keys[0] = oldRoot->getMinimum();
    keys[1] = node2->getMinimum();  
// students must write this
} // InternalNode::insert()

void InternalNode::insert(BTreeNode *newNode) // from a sibling
{
	int i = 0;
	if(count == 0)
	{
		keys[0] = newNode->getMinimum();
		children[0] = newNode;
		count ++;	
	}
	else
	{	
		if(newNode->getMinimum() > keys[count-1])
		{
			keys[count++] = newNode->getMinimum();
			children[count - 1] = newNode;
		}
		else
		{
			for(; i < count; i++)
			{
				if(keys[i] > newNode->getMinimum())
				{
					for(int j=count-1; j >= i ; j--)
					{
						keys[j+1] = keys[j];
						children[j+1]=children[j];
					}
            		break;
         		}
     		}	
    	keys[i] = newNode->getMinimum();
    	children[i] = newNode;
		count++;
		}
	}	
  // students may write this
} // InternalNode::insert()

void InternalNode::print(Queue <BTreeNode*> &queue)
{
  int i;

  cout << "Internal: ";
  for (i = 0; i < count; i++)
    cout << keys[i] << ' ';
  cout << endl;

  for(i = 0; i < count; i++)
    queue.enqueue(children[i]);

} // InternalNode::print()

void InternalNode::deleMin()
{
	for (int i = 0; i < count; i++)
	{
    	keys[i] = keys[i+1];
        children[i] = children[i+1];
    }
    count--;
}

void InternalNode::updateKeys()
{
  for (int i = 0; i < count; i++)
    keys[i] = children[i]->getMinimum();
}
