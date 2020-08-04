#include <iostream>
#include <vector>
using namespace std;

template<class T>
class unique_pointer
{
public:
	unique_pointer(T* ptr = nullptr);
	unique_pointer(unique_pointer<T>&& uptr);
	unique_pointer& operator=(unique_pointer<T>&& uptr);
	~unique_pointer();
	T* get();
	T* release();
	T* operator->() const;
	T& operator*()  const;
	void swap(unique_pointer<T>& uptr);
	void reset(T* ptr = nullptr);

	unique_pointer(const unique_pointer<T>& ptr) = delete;
	unique_pointer<T>& operator=(const unique_pointer<T>& ptr) = delete;
private:
	T* ptr_;
};

class Recourse;
#pragma once
