//
//  tree.c
//  demoTree2
//
//  Created by Slava Gubar on 4/25/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include "tree.h"
#include <stdlib.h>

static void destroyNode(ShortNode *aNode);
static ShortNode *createShortNodeWithValue(short aValue);
static ShortNode *getSuccessor(ShortTree *tree, ShortNode *toDelete);
static void print_short_node(ShortNode *node);

ShortTree *createShortTree()
{
	ShortTree *theTree = (ShortTree *)malloc(sizeof(ShortTree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}

void destroyShortTree(ShortTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertShortValueToTree(ShortTree *aTree, short aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	ShortNode *theNode = createShortNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}
	
	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count ++;
	}
	else
	{
		ShortNode *theCurrent = aTree->root;
		ShortNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;
		
			if (aValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}
	
		aTree->count ++;
	}
}

ShortNode *findNodeWithValue(ShortTree *aTree, short aValue)
{
	ShortNode *theCurrentNode = NULL;
	
	if (NULL != aTree && NULL != aTree->root)
	{
		theCurrentNode = aTree->root; //<! - start from root
		while (aValue != theCurrentNode->value) //<! - walk through the tree
		{
			theCurrentNode = (aValue < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;
		
			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}
	
	return theCurrentNode;
}

void deleteNodeWithValue(ShortTree *aTree, short aValue) {

	// check input parameters
	if (NULL == aTree || NULL == aTree->root) {
		return ;
	}

	ShortNode *current = aTree->root;
	ShortNode *parent = aTree->root;

	// find node for delete
	while (aValue != current->value) {
		parent = current;
		if (aValue < current->value) {
			current = current->leftChild;
		} else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return ;
		}
	}

	//1) the found node is leaf node?
	if (NULL == current->leftChild && NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = NULL;
		} else {
			parent->rightChild = NULL;
		}

		aTree->count --;
	} else if (NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = current->leftChild;
		} else if (parent->leftChild == current) {
			parent->leftChild = current->leftChild;
		} else {
			parent->rightChild = current->rightChild;
		}
	} else if (NULL == current->leftChild) {
		if (aTree->root == current) {
			aTree->root = current->rightChild;
		} else if (parent->rightChild == current) {
		 	parent->rightChild = current->rightChild;
		} else {
			parent->leftChild = current->leftChild;
		}
	} else {
		ShortNode *successor = getSuccessor(aTree, current);
		if (aTree->root == successor) {
			aTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = successor;
		} else {
			parent->rightChild = successor;
		}
		current->leftChild = NULL;
		current->rightChild = NULL;
	}

	destroyNode(current);
}

//void mergeTrees(ShortTree *aTreeDst, ShortTree *aTreeSrc);
//
void printTree(ShortTree *aTree) {
	ShortNode* item = aTree->root;
	print_short_node(item);
}

void print_short_node(ShortNode *node) {
	if (node == NULL)
		return;
	print_short_node(node->leftChild);
	printf("Элемент: %d\n", node->value);
	print_short_node(node->rightChild);
}

void printNode(ShortNode *aNode)
{
	if (aNode == NULL)
	 return;

	printf("value(%d)", aNode->value);
}

//int countNodesWithTree(ShortTree *aTree);

#pragma mark -
void destroyNode(ShortNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
	
		free(aNode);
	}
}

ShortNode *createShortNodeWithValue(short aValue)
{
	ShortNode *theNode = (ShortNode *)malloc(sizeof(ShortNode));
	
	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	
	return theNode;
}

ShortNode *getSuccessor(ShortTree *tree, ShortNode *toDelete) {
	ShortNode *successParent = toDelete;
	ShortNode *successor = toDelete;
	ShortNode *current = toDelete->rightChild;

	while(NULL != current) {
		successParent = successor;
		successor = current;
		current = current->leftChild;
	}
//current = NULL;
//successor = 35
	if (successor != toDelete->rightChild) { // 35 != 39
		successParent->leftChild = successor->rightChild; //39 -> NULL
		successor->rightChild = toDelete->rightChild; //35->39
	}

	successor->leftChild = toDelete->leftChild;

	return successor;
}
