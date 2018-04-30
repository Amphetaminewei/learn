#include"chain.h"
#include"chainNode.h"
#include"linearList.h"
#include"illegalParameterValue.h"

using namespace std;

//���������ʵ��

//���캯��
template<class T>
chain<T>::chain(int initialCapacity) {
	if (initialCapacity < 1) {
		ostream s;
		s << "Initial capacity = " << initialCapacity << "Must be > 0";
		throw illegalParameterVaule(s.str());
	}
	//��������һ���ͼ���һ��������ֱ�ӳ�ʼ��Ϊ����һ��һ�����ϼӾ�����
	firstNode = NULL;
	listSize = 0;
}
//���ƹ��캯��
template<class T>
chain<T>::chain(const chain<T>& theList) {
	listSize = theList.listSize;

	if (listSize == 0) {
		firstNode = NULL;
		return;
	}
	else {
		chainNode<T>* sourceNode = theList.firstNode;    
		firstNode = new chainNode<T>(sourceNode->element);   //����c++����д����������ָ��ͱ�����ָͨ�룬�������ݽṹ����������ָ���ǲ�����Ϊ����Ч�ʡ�
		sourceNode = sourceNode->next;
		chainNode<T>* targetNode = firstNode;
		while (sourceNede != NULL) {
			targetNode->next = new chainNode<T>(sourceNode->element);
			targetNode = targetNode->next;
			sourceNode = sourceNode->next;
			//ע���������ϵ�д�������˺ü���û������
			//�������־����½�������ָ��������theList.firstNode��this.firtsNode
			//����ҲûдΪʲôҪ�������м����������Ϊ�˿������߼��򵥣�

			//���˿����ˣ��ǲ��ܶ�ͷָ�룬��Ȼͷָ��λ�ñ��˻�������
		}
	}
}

//��������
template<class T>
chain<T>::~chain() {
	while (firstNode != NULL) {
		chainNode<T>* nextNode = firstNode->next;
		//��һ���м�����ʱ������һ���ڵ�ĵ�ַȻ���ͷŵ�ǰ�ڵ�
		delete firstNode;
		firstNode = nextNode;
	}
}

//�ж��Ƿ�Ϊ��
template<class T>
bool chain<T>::empty() {
	if (firstNode = NULL) {
		return false;
	}
	else {
		return true;
	}
}

//����Ԫ�ظ���
template<class T>
int chain<T>::size() {
	return listSize;
}

//����index��ֵ
template<class T>
T& chain<T>::get(int theIndex){
	chackIndex(theIndex);
	chainNode<T>* tempNode = firstNode;
	//����������������ʱ�򷵻ص�ǰ������
	for (int i = 0;i < theIndex;i++) {
		tempNode = tempNode->next;
	}
	return tempNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) {
	chainNode<T>* tempNode = firstNode;
	for (int i = 0;i < listSize;i++) {
		//�����ǰ������������Ϊ�������ݣ�������һ���ڵ�
		if (tempNode->element == theElement) {
			return i;
		}
		tempNode = tempNode->next;
	}
	cout << "without this element" << endl;
	return 0;
}

template<class T>
void chain<T>::erase(int theIndex) {
	chainNode<T>* delNode = firstNode;
	for (int i = 0;i < theIndex - 1;i++) {
		delNode = delNode->next;
	}
	chainNode<T>* tempNode = delNode->next;
	delNode->next = delNode->next->next;
	//ͨ��ѭ����λ��theindex��λ�ã�Ȼ���ͷŽڵ㲢������һ
	delNode = NULL;
	delete delNode->next;
	listSize--;
}

template<class T>
void chain<T>::insert(int theIndex, const T& theElement) {
	//��λ��theIndex��ǰһ���ڵ�
	chainNode<T>* tempNode = firstNode;
	for (int i = 0;i < theIndex - 1;i++) {
		tempNode = tempNode->next;
	}
	//����һ���½ڵ㣬��ַ�򴢴�firstNode����һ���ڵ�
	chainNode<T>* newNode = new chainNode<T>(theElement, tempNode->next);
	//��firstNode�ĵ�ַ��ָ��newNode
	tempNode->next = newNode;
	//����һ
	listSize++;
}

template<class T>
void chain<T>::output(ostream& out) {
	chainNode<T>* tempNode = firstNode;
	//�����������������Ԫ��
	if (listSize == 0) {
		out << "the linearList is empty" << endl;
	}
	for (i = 0;i < listSize;i++) {
		out << tempNode->element;
		tempNode = tempNode->next;
	}
}

template<class T>
void chain<T>::checkIndex(int theIndex)const {
	//�쳣���ǳ����ġ������ǵú����׼��Ҳ�в��ġ�
	if (theIndex < 0) {
		throw illegalParameterVaule("theIndex should be >= 0");
	}
}

