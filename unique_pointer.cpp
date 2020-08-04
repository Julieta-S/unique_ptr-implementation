#include "unique_pointer.h"

template<class T>
unique_pointer<T>::unique_pointer(T* ptr) :ptr_(ptr) {}

template<class T>
unique_pointer<T>::unique_pointer(unique_pointer<T>&& uptr) : ptr_(uptr.ptr_)
{
	uptr.ptr_ = nullptr;
}

template<class T>
unique_pointer<T>& unique_pointer<T>::operator=(unique_pointer<T>&& uptr)
{
	if (&uptr == this)
		return *this;
	ptr_ = uptr.ptr_;
	uptr.ptr_ = nullptr;
	return *this;
}

template<class T>
unique_pointer<T>::~unique_pointer()
{
	delete ptr_;
}

template<class T>
T* unique_pointer<T>::get()
{
	return ptr_;
}

template<class T>
T* unique_pointer<T>::release()
{
	T* new_ptr = ptr_;
	ptr_ = nullptr;
	return new_ptr;
}

template<class T>
T* unique_pointer<T>::operator->() const
{
	return ptr_;
}

template<class T>
T& unique_pointer<T>::operator*() const
{
	return *ptr_;
}

template<class T>
void unique_pointer<T>::swap(unique_pointer<T>& uptr)
{
	std::swap(ptr_, uptr.ptr_);
}

template<class T>
void unique_pointer<T>::reset(T* ptr)
{
	T* old_ptr = ptr_;
	ptr_ = ptr;
	delete old_ptr;
}

template<class T, class... Args>
unique_pointer<T> make_uniquee(Args&&...args)
{
	return unique_pointer<T>(new T(forward<Args>(args)...));
}

class Resource
{
public:
	Resource() :value_(0) { cout << "empty resource acquired\n"; };
	Resource(int num) : value_(num) { cout << "empty resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
	int get() { return value_; }
	friend ostream& operator<<(std::ostream& out, const Resource &res)
	{
		cout << "current resource" << endl;
		return out;
	}
private:
	int value_;
};

