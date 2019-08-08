#pragma once


template <class T>
class auto_ptr {

	//成为另一个智能指针的友元
	template<class U> friend class auto_ptr;

public:
	//防止编译器帮我们做的隐式类型转换
	explicit auto_ptr(T* p = 0);

	//复制构造函数，供任何类型的auto_ptr进行复制，也就是左右两个auto_ptr类型可以不同
	template<class U>
	auto_ptr(auto_ptr<U>& rhs);

	
	~auto_ptr();

	//重载等号并让等号左右两个auto_ptr类型可以不同
	template<class U>
	auto_ptr<T>& operator=(auto_ptr<U>& rhs);

	//重载箭号和解引用号，尽可能让这个智能指针用起来像是一个原生指针
	T* operator->() const;
	T& operator*() const;

	//返回真实的指针
	T* getPtr() const;

	//撤回真实指针的拥有权并返回其真实指针
	T* release();

	//将拥有的指针删除，并得到p的拥有权
	//也就是删除原指针并得到新指针的拥有权
	void reset(T* p = 0);

private:
	//真实的指针
	T* pointee;

};

template<class T>
auto_ptr<T>::auto_ptr(T* p):pointee(p) { }

template<class T>
template<class U>
auto_ptr<T>::auto_ptr(auto_ptr<U>& rhs): pointee(rhs.release()) {
	//由于这个智能指针不提供引用计数，所以当进行复制动作时
	//回将右值的所有权转移给左值
}

template<class T>
auto_ptr<T>::~auto_ptr() {
	//我们的智能指针不支持共享
	//所以可以不用判断是否还有指针指向同一块内存直接删除指针
	delete pointee;
}

template<class T>
template<class U>
auto_ptr<T>& auto_ptr<T>::operator=(auto_ptr<U>& rhs) {
	if (pointee != rhs.pointee) {
		//符号不一样是因为this是指针而rhs是一个引用
		//删除并返回右值的指针并将this的原指针删除并绑定到右值返回的指针上
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
	这里将真实指针返回并将原指针置为空
	注意这里名没有将指针指向的内存释放，也就是oldPointee及其继任者有义务将这块内存释放
	如果你想用这个函数来将一个智能指针置为空，而不接受其返回值，那将有一块你无法释放的内存一直存在

	int *b = a.release()这样可以
	a.release() 这样会不能正常释放指针，因为a已经失去了指针的掌控权，但是没有一个指针出来继承这个掌控权
	掌控权在oldPointee手里但是你得不到他
	*/
	T* oldPointee = pointee;
	pointee = 0;
	return oldPointee;
}

template<class T>
void auto_ptr<T>::reset(T* p) {
	if (pointee != p) {
		//这里讲原指针delete掉而不是置为空
		//因为此后讲没有任何对象能获得其拥有权
		delete pointee;
		pointee = p;
	}
}