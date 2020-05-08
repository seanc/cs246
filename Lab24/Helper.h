#include "BNode.h"

#ifndef HELPER_H
#define HELPER_h

namespace ds::dn
{
    template <typename T>
    bool IsLeaf(BNode<T>* root)
    {
        if(root != NULL)
        {
            return root->left == NULL && root->right == NULL;
        }
        return false;
    }

    template <typename T>
    void InOrderPrint(BNode<T>* root)
    {
        if(root != NULL)
        {
            InOrderPrint(root->left);
            std::cout << root->data << " ";
            InOrderPrint(root->right);
        }
    }

    template <typename T>
    void PreOrderPrint(BNode<T>* root)
    {
        if(root != NULL)
        {                                    
            std::cout << root->data << " ";
            PreOrderPrint(root->left);
            PreOrderPrint(root->right);
        }
    }

    template <typename T>
    void PostOrderPrint(BNode<T>* root)
    {
        if(root != NULL)
        {                                    
            PostOrderPrint(root->left);
            PostOrderPrint(root->right);
            std::cout << root->data << " ";
        }
    }

    template <typename T>
    int Size(BNode<T>* root)
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
    void BSTInsert(BNode<T>*& root,BNode<T>* p,const T& value)
    {
        if(root == NULL)
        {
            root = new BNode<T>(value,p);
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
    void BSTInsert(BNode<T>*& root,const T& value)
    {
        if(root == NULL)
        {
            root = new BNode<T>(value,NULL);
        }
        else 
        {
            BSTInsert<T>(root,NULL,value);
        }
    }

    template <typename T>
    BNode<T>* BTSearch(BNode<T>* root,const T& value)
    {
        if(root == NULL)
        {
            return NULL;
        }
        else if(root->data == value)
        {
            return root;
        }
        else
        {
            BNode<T>* ltNode = BTSearch(root->left,value);
            BNode<T>* rtNode = BTSearch(root->right,value);

            if(ltNode == NULL && rtNode == NULL)
            {
                return NULL;
            }
            else if(ltNode != NULL)
            {
                return ltNode;
            }
            else
            {
                return rtNode;
            }
        }
    }

    template <typename T>
    BNode<T>* BSTSearch(BNode<T>* root,const T& value)
    {
        if(root == NULL || root->data == value)
        {
            return root;
        }
        else if(root->data > value)
        {
            return BSTSearch(root->left,value);
        }
        else
        {
            return BSTSearch(root->right,value);
        }
    }
}
#endif