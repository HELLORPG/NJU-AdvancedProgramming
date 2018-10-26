#pragma once
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;
using std::endl;

template <typename T>
class Vector
{
public:
	typedef  T* iterator;
private:
	iterator start;
	size_t m_size;
	size_t m_capcity;

public:
	//typedef  T* iterator;
	Vector(size_t c);
	~Vector() {}
	void push_back(T e);
	size_t size();
	iterator begin();
	iterator end();
	//�� it ǰ����һ��Ԫ�أ����صĵ�����ָ�����Ԫ��
	iterator insert(iterator it, T e);
	//ɾ�� it ָ���Ԫ�أ����صĵ�����ָ��ɾ��Ԫ�ص���һ��Ԫ��
	iterator erase(iterator it);
	T& operator[](int i);
};

template <typename T>
Vector<T>::Vector(size_t c)
{
	m_size = 0;
	start = new T[c];
	m_capcity = c;
	//begin = start;
	//end = start + 1;
}

template <typename T>
void Vector<T>::push_back(T e)
{
	//m_size = m_size + 1;
	start[m_size] = e;
	//end = end + 1;
	++m_size;
	return;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
	return start;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end()
{
	return start + m_size;
}

template <typename T>
size_t Vector<T>::size()
{
	return m_size;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(iterator it, T e)//�� it ǰ����һ��Ԫ�أ����صĵ�����ָ�����Ԫ��
{
	for (iterator p = this->end(); p > it; p = p - 1)
	{
		*p = *(p - 1);
	}
	m_size += 1;
	*it = e;
	return it;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(iterator it)//ɾ�� it ָ���Ԫ�أ����صĵ�����ָ��ɾ��Ԫ�ص���һ��Ԫ��
{
	for (iterator p = it; p < this->end() - 1; ++p)
	{
		*p = *(p + 1);
	}
	m_size -= 1;
	return it;
}


template <typename T>
T& Vector<T>::operator[](int i)
{
	return start[i];
}

