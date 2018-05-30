#include<utility>

#include"sortedNode.h"
#include"sortedChain.h"
#include"hashTable.h"
#include"hash.h"

using namespace std;

template<class K,class E>
hashTable<K, E>::hashTable(const int theDivisor) {
	dSize = theDivisor;
	divisor = theDivisor;
	table = new sortedChain<K, E>*[theDivisor];
	for (int i = 0;i < theDivisor;i++) {
		table[i] = NULL;
	}
}

template<class K,class E>
hashTable<K, E>::~hashTable() {
	//��ͼ����sortedChain����������������table;
	for (int i = 0;i < divisor;i++) {
		(table[i]).sortedChain<K, E>::~sortedChain();
	}
	delete[] table;
}

template<class K,class E>
int hashTable<K, E>::search(const K &theKey) const {
	int item = (int)hash(theKey); //ͨ��hash��keyת����int����
	item = item % divisor;        //��item��ֵת������ʼͰ���±�
	return item;
	//��ʽ�Ĺ�ϣ�����key���ھ�һ������ʼͰ��
}

template<class K,class E>
pair<const K, E>* hashTable<K, E>::find(const K &theKey) const {
	//��λ����ʼͰ��ͷ�ڵ�
	sortedNode<K, E>* itemNode = table[search(theKey)].firstNode;
	while (itemNode->element.first != theKey && itemNode->next != NULL) {
		//����ʼͰ������key��λ�ã�����������򷵻�NULL
		itemNode = itemNode->next;
	}
	if (itemNode->next == NULL && table[search(theKey)].lastNode->element != theKey) {
		return NULL;
	}
	return itemNode->element;
}

template<class K,class E>
void hashTable<K, E>::insert(const pair<const K, E> &thePair) {
	//��ȷ��Ҫ����Ԫ�ص���ʼͰ
	//��Ϊ����table��Ԫ����sortedChain
	//���Զ�������ʼͰ����sortedChain��insert����
	//��������Ѵ������޸�ԭ���Ե�ֵ�������ھͲ���ͷ�ڵ����
	int theHash = (int)hash(thePair.first);
	table[theHash].insert(thePair);
}

template<class K,class E>
void hashTable<K, E>::erase(const K &theKey) {
	//�Ͳ���һ����������ȷ����ʼͰ
	//Ȼ�����sortedChain��erase����
	int theHash = (int)hash(theKey);
	table[theHash].erase(theKey);
}