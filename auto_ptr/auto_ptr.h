#pragma once


template <class T>
class auto_ptr {

	//��Ϊ��һ������ָ�����Ԫ
	template<class U> friend class auto_ptr;

public:
	//��ֹ������������������ʽ����ת��
	explicit auto_ptr(T* p = 0);

	//���ƹ��캯�������κ����͵�auto_ptr���и��ƣ�Ҳ������������auto_ptr���Ϳ��Բ�ͬ
	template<class U>
	auto_ptr(auto_ptr<U>& rhs);

	
	~auto_ptr();

	//���صȺŲ��õȺ���������auto_ptr���Ϳ��Բ�ͬ
	template<class U>
	auto_ptr<T>& operator=(auto_ptr<U>& rhs);

	//���ؼ��źͽ����úţ����������������ָ������������һ��ԭ��ָ��
	T* operator->() const;
	T& operator*() const;

	//������ʵ��ָ��
	T* getPtr() const;

	//������ʵָ���ӵ��Ȩ����������ʵָ��
	T* release();

	//��ӵ�е�ָ��ɾ�������õ�p��ӵ��Ȩ
	//Ҳ����ɾ��ԭָ�벢�õ���ָ���ӵ��Ȩ
	void reset(T* p = 0);

private:
	//��ʵ��ָ��
	T* pointee;

};

template<class T>
auto_ptr<T>::auto_ptr(T* p):pointee(p) { }

template<class T>
template<class U>
auto_ptr<T>::auto_ptr(auto_ptr<U>& rhs): pointee(rhs.release()) {
	//�����������ָ�벻�ṩ���ü��������Ե����и��ƶ���ʱ
	//�ؽ���ֵ������Ȩת�Ƹ���ֵ
}

template<class T>
auto_ptr<T>::~auto_ptr() {
	//���ǵ�����ָ�벻֧�ֹ���
	//���Կ��Բ����ж��Ƿ���ָ��ָ��ͬһ���ڴ�ֱ��ɾ��ָ��
	delete pointee;
}

template<class T>
template<class U>
auto_ptr<T>& auto_ptr<T>::operator=(auto_ptr<U>& rhs) {
	if (pointee != rhs.pointee) {
		//���Ų�һ������Ϊthis��ָ���rhs��һ������
		//ɾ����������ֵ��ָ�벢��this��ԭָ��ɾ�����󶨵���ֵ���ص�ָ����
		this->reset(rhs.release());
	}
	return *this;
}

template<class T>
T* auto_ptr<T>::operator->() const {
	return pointee;
}

template<class T>
T& auto_ptr<T>::operator*() const {
	return *pointee;
}

template<class T>
T* auto_ptr<T>::getPtr() const {
	return pointee;
}

template<class T>
T* auto_ptr<T>::release() {
	/*
	���ｫ��ʵָ�뷵�ز���ԭָ����Ϊ��
	ע��������û�н�ָ��ָ����ڴ��ͷţ�Ҳ����oldPointee�������������������ڴ��ͷ�
	��������������������һ������ָ����Ϊ�գ����������䷵��ֵ���ǽ���һ�����޷��ͷŵ��ڴ�һֱ����

	int *b = a.release()��������
	a.release() �����᲻�������ͷ�ָ�룬��Ϊa�Ѿ�ʧȥ��ָ����ƿ�Ȩ������û��һ��ָ������̳�����ƿ�Ȩ
	�ƿ�Ȩ��oldPointee���ﵫ����ò�����
	*/
	T* oldPointee = pointee;
	pointee = 0;
	return oldPointee;
}

template<class T>
void auto_ptr<T>::reset(T* p) {
	if (pointee != p) {
		//���ｲԭָ��delete����������Ϊ��
		//��Ϊ�˺�û���κζ����ܻ����ӵ��Ȩ
		delete pointee;
		pointee = p;
	}
}