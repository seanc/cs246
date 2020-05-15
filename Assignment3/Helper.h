#ifndef HELPER_H
#define HELPER_H
#include "BNode.h"
#include "Stack.h"

template <typename T>
int Size(ds::dn::BNode<T>* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else 
    {
        return 1 + Size(root->left) + Size(root->right);
    }
}

template <typename T>
void BTInsert(ds::dn::BNode<T>*& root,const T& value)
{
    if(root == NULL)
    {
        root = new ds::dn::BNode<T>(value,NULL);
        return;
    }

    int sz = Size(root);
    int p = sz;
    ds::sn::Stack<int> anc;
    
    while(p > 0)
    {
        p = (p - 1) / 2;
        anc.Push(p);
    } 

    ds::dn::BNode<T>* t = root;
    int pp = 0;
    anc.Pop();

    while(!anc.IsEmpty())
    {
        p = anc.Top();
        anc.Pop();

        if(2 * pp + 1 == p)
        {
            t = t->left;
        }
        else 
        {
            t = t->right;
        }
        pp = p;
    }

    if(t->left == NULL)
    {
        t->left = new ds::dn::BNode<T>(value,t);
    }
    else
    {
        t->right = new ds::dn::BNode<T>(value,t);
    }
};

template <typename T>
void BSTInsert(ds::sn::BNode<T>*& root,const T& value)
{
    if(root == NULL)
    {
        root = new ds::sn::BNode<T>(value);
    }
    else if(root->data > value)
    {
        BSTInsert(root->left,value);            
    }
    else
    {
        BSTInsert(root->right,value);            
    }
}

template <typename T>
void BSTInsert(ds::dn::BNode<T>*& root,ds::dn::BNode<T>* p,const T& value)
{
    if(root == NULL)
    {
        root = new ds::dn::BNode<T>(value,p);
    }
    else if(root->data > value)
    {
        BSTInsert(root->left,root,value);
    }
    else
    {
        BSTInsert(root->right,root,value);
    }
}

template <typename T>
void BSTInsert(ds::dn::BNode<T>*& root,const T& value)
{
    if(root == NULL)
    {
        root = new ds::dn::BNode<T>(value,NULL);
    }
    else 
    {
        BSTInsert<T>(root,NULL,value);
    }
}

template <typename T>
void PreOrderPrint(ds::dn::BNode<T>* root)
{
    if(root != NULL)
    {                           
        std::cout << root->data;

        PreOrderPrint(root->right);

        PreOrderPrint(root->left);

    }
}
#endif