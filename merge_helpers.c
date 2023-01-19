#include "sort.h"

/**
 * iParent - gets the parent node
 * 
 * @i: idx of node to find parent of
 * Return: idx of parent node
 */
int iParent(int i)
{
	return ((i - 1) / 2);
}

/**
 * iLeftChild - gets the left child of a node
 * 
 * @i: idx of node to find left child of
 * Return: idx of left child node
 */
int iLeftChild(int i)
{
	return (2 * i + 1);
}

/**
 * iRightChild - gets the right child of a node
 * 
 * @i: idx of node to find right child of
 * Return: idx of right child node
 */
int iRightChild(int i)
{
	return (2 * i + 2);
}