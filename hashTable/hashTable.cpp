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
	//企图借用sortedChain的析构函数来析构table;
	for (int i = 0;i < divisor;i++) {
		(table[i]).sortedChain<K, E>::~sortedChain();
	}
	delete[] table;
}

template<class K,class E>
int hashTable<K, E>::search(const K &theKey) const {
	int item = (int)hash(theKey); //通过hash将key转换成int类型
	item = item % divisor;        //将item的值转换成起始桶的下标
	return item;
	//链式的哈希表如果key存在就一定在起始桶中
}

template<class K,class E>
pair<const K, E>* hashTable<K, E>::find(const K &theKey) const {
	//定位到起始桶的头节点
	sortedNode<K, E>* itemNode = table[search(theKey)].firstNode;
	while (itemNode->element.first != theKey && itemNode->next != NULL) {
		//在起始桶中搜索key的位置，如果不存在则返回NULL
		itemNode = itemNode->next;
	}
	if (itemNode->next == NULL && table[search(theKey)].lastNode->element != theKey) {
		return NULL;
	}
	return itemNode->element;
}

template<class K,class E>
void hashTable<K, E>::insert(const pair<const K, E> &thePair) {
	//先确定要插入元素的起始桶
	//因为数组table的元素是sortedChain
	//所以对他的起始桶调用sortedChain的insert函数
	//如果数对已存在则修改原数对的值，不存在就插在头节点后面
	int theHash = (int)hash(thePair.first);
	table[theHash].insert(thePair);
}

template<class K,class E>
void hashTable<K, E>::erase(const K &theKey) {
	//和插入一样，都是先确定起始桶
	//然后调用sortedChain的erase函数
	int theHash = (int)hash(theKey);
	table[theHash].erase(theKey);
}