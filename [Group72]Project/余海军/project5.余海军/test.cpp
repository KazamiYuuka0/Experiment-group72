#include "sm3.h"
#include "MerkleTree.h"
#include <iostream>
#include "transform.h"
using namespace std;

int main() {
	//ǰ�򹹽�Ĭ�˶���
	MerkleTree<string> test;
	//����Ĭ�˶���
	cout << endl << "ǰ����������" << endl;
	test.PreOrder(test.getRoot());
	cout << endl << "������������" << endl;
	test.InOrder(test.getRoot());
	cout << endl << "������������" << endl;
	test.PostOrder(test.getRoot());
}
