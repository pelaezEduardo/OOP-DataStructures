﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using EstrcuturasDinamicas;

namespace BinarySearchTree
{
    public class BinaryTree<T>
    {
        public Node<T> root;
        private int numberOfNodes = 0;        
        Comparer<T> comp = Comparer<T>.Default;
        public MyLinkedList<Node<T>> order = new MyLinkedList<Node<T>>();

        public BinaryTree()
        {
            root = null;
        }

        public int weight()
        {
            return numberOfNodes;
        }
        

        public int treeDepth(Node<T> root)
        {
            if (root != null)
            {
                return 0;
            }
            else
            {
                int leftDepth = treeDepth(root.getLeft());
                int rightDepth = treeDepth(root.getRight());
                return Math.Max(leftDepth, rightDepth);
            }
        }

        public void add(T element) {
            if (this.root == null)
            {
                root = new Node<T>(element, null, null, null);
                numberOfNodes++;
            }
            else
            {
                addElement(root, element);
            }
        }

        private void addElement(Node<T> root, T element)
        {            
            if (this.root == null)
            {
                this.root = new Node<T>(element, null, null, null);
                numberOfNodes++;
            }
            else
            {                
                if (comp.Compare(element, root.getElement()) < 0)//x es menor que y
                {
                    if (root.getLeft() == null)
                    {
                        root.setLeft(new Node<T>(element, root, null, null));
                        numberOfNodes++;
                    }
                    else
                    {
                        addElement(root.getLeft(), element);
                    }
                }
                else if (comp.Compare(element, root.getElement()) > 0)//x es mayor que y 
                {
                    if (root.getRight() == null)
                    {
                        root.setRight(new Node<T>(element,root, null, null));
                        numberOfNodes++;
                    }
                    else
                    {
                        addElement(root.getRight(), element);
                    }
                }
                else//x es igual que y
                {
                    throw new Exception("NO SE PERMITEN DUPLICADOS");
                }
            }
        }

        public bool elementExists(Node<T> root, T element)
        {
            if (root == null)
            {
                return false;
            }
            else if (comp.Compare(element, root.getElement()) == 0)
            {
                return true;
            }
            else
            {
                if (comp.Compare(element, root.getElement()) < 0)
                {
                    return elementExists(root.getLeft(), element);
                }
                else
                {
                    return elementExists(root.getRight(), element);
                }
            }
        }       

        public int numberOfChildren(Node<T> root)
        {
                int count = 0;
                if (root.getLeft() != null)
                    count++;
                if (root.getRight() != null)
                    count++;
                return count;            
        }        

        public T remove(Node<T> root, T element)
        {
            if (root == null)
            {
                return default(T);
            }
            else if (comp.Compare(element, root.getElement()) == 0)
            {
                if (numberOfChildren(root) == 0)
                {
                    T aux = root.getElement();
                    if (root == this.root)
                    {
                        this.root = null;
                    }
                    else
                    {
                        if (comp.Compare(element, root.getParent().getLeft().getElement()) == 0)
                        {
                            root.getParent().setLeft(null);
                            root = null;
                        }
                        else
                        {
                            root.getParent().setRight(null);
                            root = null;
                        }
                    }
                    numberOfNodes--;
                    return aux;
                }
                else if (numberOfChildren(root) == 1)
                {
                    T aux = root.getElement();
                    if (root == this.root)
                    {
                        if (root.getLeft() != null)
                        {
                            this.root = root.getLeft();
                        }
                        else
                        {
                            this.root = root.getRight();
                        }
                    }
                    else
                    {                        
                        if (root.getParent().getLeft() != null)
                        {
                            if (root.getLeft() != null)
                            {
                                root.getParent().setLeft(root.getLeft());
                            }
                            else
                            {
                                root.getParent().setLeft(root.getRight());
                            }
                        }
                        else
                        {
                            if (root.getLeft() != null)
                            {
                                root.getParent().setRight(root.getLeft());
                            }
                            else
                            {
                                root.getParent().setRight(root.getRight());
                            }
                        }
                    }
                    numberOfNodes--;
                    return aux;
                }
                else//El que sustituirá será el más derecho de los izquierdos
                {
                    Node<T> next = root.getLeft();
                    T aux = root.getElement();
                    if (next.getRight() != null)
                    {
                        while (next.getRight() != null)
                        {
                            next = next.getRight();
                        }
                        root.setElement(next.getElement());
                        Node<T> father = next.getParent();
                        father.setRight(null);
                    }
                    else
                    {
                        root.setElement(next.getElement());
                        root.setLeft(null); 
                    }

                    numberOfNodes--;
                    return aux;
                }
            }
            else
            {
                if (comp.Compare(element, root.getElement()) < 0)
                {
                    return remove(root.getLeft(), element);
                }
                else
                {
                    return remove(root.getRight(), element);
                }
            }                                   
        }        

        public void preOrder(Node<T> root)
        {
            if (root != null)
            {
                Console.Write(root.getElement() + "->");
                preOrder(root.getLeft());
                preOrder(root.getRight());
            }   
        }

        public void postOrder(Node<T> root)
        {
            if (root != null)
            {
                postOrder(root.getLeft());
                postOrder(root.getRight());
                order.addLast(root);
            }
        }

        public void inOrder(Node<T> root)
        {
            if (root != null)
            {
                inOrder(root.getLeft());
                order.addLast(root);
                inOrder(root.getRight());
            }
        }
    }
}
