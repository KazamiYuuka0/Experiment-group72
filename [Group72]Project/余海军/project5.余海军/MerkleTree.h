#pragma once
#include "sm3.h"
#include<iostream>
using namespace std;

//Ĭ�˶��������
template<class T>
class MerkleTreeNode {
	//��Ԫ������
	template<class T>
	friend class MerkleTree;
private:
	T data;
	MerkleTreeNode<T>* leftchild;
	MerkleTreeNode<T>* rightchild;
public:
	//���캯��
	MerkleTreeNode() {
		leftchild = NULL;
		rightchild = NULL;
	}
	MerkleTreeNode(const T& dataValue) {
		data = iteration(padding(dataValue));
		leftchild = NULL;
		rightchild = NULL;
	}
	MerkleTreeNode(const T& dataValue, MerkleTreeNode<T>* leftchildValue, MerkleTreeNode<T>* rightchildValue) {
		data = dataValue;
		leftchild = leftchildValue;
		rightchild = rightchildValue;
	}
	//��������
	~MerkleTreeNode() {
		leftchild = NULL;
		rightchild = NULL;
	}
	//���½ڵ�ֵ
	void UpdateNode(const T& dataValue) {
		data = dataValue;
	}
	//���ʽ��
	void VisitNode() {
		cout << data << endl;
	}
	//ȡ����
	MerkleTreeNode<T>* getLeft() {
		return leftchild;
	}
	//ȡ�ҽ��
	MerkleTreeNode<T>* getRight() {
		return rightchild;
	}
};

//Ĭ�˶�����
template<class T>
class MerkleTree {
private:
	MerkleTreeNode<T>* root;
public:
	//���캯��
	MerkleTree() {
		root = NULL;
		cout << "Now start to construct the MerkleTree" << endl;
		CreateNode(root);
	}
	//��������
	~MerkleTree() {
		root = NULL;
	}
	//ǰ�򹹽�Ĭ�˶���
	void CreateNode(MerkleTreeNode<T>*& treeNode) {
		cout << "Please enter value or '#' to stop:";
		T value;
		cin >> value;
		treeNode = new MerkleTreeNode<T>(value);
		if (value == "#") {
			delete treeNode;
			treeNode = NULL;
		}
		else {
			CreateNode(treeNode->leftchild);
			CreateNode(treeNode->rightchild);
			//�������Ҷ�ӽ�㣬������������ֽ�������Ϲ�ϣ
			if (treeNode->leftchild != NULL && treeNode->rightchild != NULL) {
				treeNode->data = iteration(padding(treeNode->leftchild->data + treeNode->rightchild->data));
			}
		}
	}
	//ȡ���ڵ�
	MerkleTreeNode<T>* getRoot() {
		return root;
	}
	//�ݹ�ǰ�����
	void PreOrder(MerkleTreeNode<T>* treeNode) {
		if (treeNode != NULL) {
			treeNode->VisitNode();
			PreOrder(treeNode->getLeft());
			PreOrder(treeNode->getRight());
		}
	}
	//�ݹ��������
	void InOrder(MerkleTreeNode<T>* treeNode) {
		if (treeNode != NULL) {
			InOrder(treeNode->getLeft());
			treeNode->VisitNode();
			InOrder(treeNode->getRight());
		}
	}
	//�ݹ�������
	void PostOrder(MerkleTreeNode<T>* treeNode) {
		if (treeNode != NULL) {
			PostOrder(treeNode->getLeft());
			PostOrder(treeNode->getRight());
			treeNode->VisitNode();
		}
	}
};

