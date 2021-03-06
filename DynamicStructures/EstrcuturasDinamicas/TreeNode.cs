﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EstrcuturasDinamicas
{
    public class TreeNode<T>
    {
        private T element;
        private TreeNode<T> parent;
        private TreeNode<T> left;
        private TreeNode<T> right;

        public TreeNode(T t, TreeNode<T> above, TreeNode<T> leftChild, TreeNode<T> rightChild)
        {
            element = t;
            parent = above;
            left = leftChild;
            right = rightChild;
        }

        public T getElement()
        {
            return element;
        }

        public TreeNode<T> getParent()
        {
            return parent;
        }

        public TreeNode<T> getLeft()
        {
            return left;
        }

        public TreeNode<T> getRight()
        {
            return right;
        }

        public void setElement(T t)
        {
            element = t;
        }

        public void setParent(TreeNode<T> parentTreeNode)
        {
            parent = parentTreeNode;
        }

        public void setLeft(TreeNode<T> leftChild)
        {
            left = leftChild;
        }

        public void setRight(TreeNode<T> rightChild)
        {
            right = rightChild;
        }
    }
}
