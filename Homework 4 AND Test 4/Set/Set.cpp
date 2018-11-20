#include "Set.h"

Set::Set()
{
	data = new int[10];
	max_length = 10;
	real_length = 0;
}

Set::Set(const Set& set)
{
	max_length = set.max_length;
	real_length = set.real_length;
	data = new int[max_length];
	for (int i(0); i < max_length; ++i)
	{
		data[i] = set.data[i];
	}
}

Set& Set::operator=(const Set& x)
{
	max_length = x.max_length;
	real_length = x.real_length;
	delete data;
	data = new int[max_length];
	for (int i(0); i < max_length; ++i)
	{
		data[i] = x.data[i];
	}
	return *this;
}


Set::Set(int elements[], int length)
{
	max_length = length;
	data = new int[max_length];

	int i(0);
	for (int j(0); j < max_length; ++j)
	{
		int find(0);
		for (; find < i; ++find)
		{
			if (data[find] == elements[j])
				break;
		}
		if (find == i)
		{
			data[i] = elements[j];
			++i;
		}
	}
	real_length = i;
}

Set::~Set()
{
	delete data;
}

void Set::add(int element)
{
	if (real_length == max_length)
	{
		//��ʱ��Ҫ��չ���ϣ������װ������
		int *old = data;
		data = new int[2 * max_length];
		max_length *= 2;
		for (int i(0); i < max_length; ++i)
			data[i] = old[i];

	}
	//�������費��Ҫ��չ�������Ĳ���Ӧ����һ�µ�
	if (!this->contains(element))
	{
		data[real_length] = element;
		++real_length;
	}
	return;
}

bool Set::erase(int element)
{
	int find(0);
	for (; find < real_length; ++find)
	{
		if (data[find] == element)
			break;
	}
	if (find == real_length)
		return false;
	else
	{
		int i(find);
		data[find] = 0;
		for (; i < real_length - 1; ++i)
		{
			data[i] = data[i + 1];
		}
		--real_length;
		return true;
	}
}

bool Set::contains(int element) const
{
	int find(0);
	for (; find < real_length; ++find)
	{
		if (data[find] == element)
			break;
	}
	return !(find == real_length);
}

ostream& operator<<(ostream& os, Set set)
{
	if (set.real_length == 0)
		os << "Empty" /*<< endl*/;
	else
	{
		for (int i(0); i <set.real_length - 1; ++i)
		{
			for (int j(0); j < set.real_length - 1; ++j)
			{
				if (set.data[j] > set.data[j + 1])
				{
					int mid = set.data[j]; set.data[j] = set.data[j + 1]; set.data[j + 1] = mid;
				}
			}
		}
		for (int i(0); i < set.real_length; ++i)
			os << set.data[i] << " ";
		//os << endl;
	}
	return os;
}

Set operator+(const Set& lset, const Set& rset)
{
	Set ret(lset);
	for (int i(0); i < rset.real_length; ++i)
	{
		if (!ret.contains(rset.data[i]))
			ret.add(rset.data[i]);
	}
	return ret;
}

Set& Set::operator+=(const Set& rset)
{
	*this = *this + rset;
	return *this;
}

Set operator-(const Set& lset, const Set& rset)
{
	Set ret;
	for (int i(0); i < lset.real_length; ++i)
	{
		if (!rset.contains(lset.data[i]))
			ret.add(lset.data[i]);
	}
	return ret;
}

Set& Set::operator-=(const Set& rset)
{
	*this = *this - rset;
	return *this;
}


Set operator&(const Set& lset, const Set& rset)
{
	Set ret;
	for (int i(0); i < lset.real_length; ++i)
	{
		if (rset.contains(lset.data[i]))
			ret.add(lset.data[i]);
	}
	return ret;
}

Set operator|(const Set& lset, const Set& rset)
{
	return lset + rset;
}

bool operator==(const Set& lset, const Set& rset)
{
	if (lset.real_length != rset.real_length)
		return false;
	else
	{
		int i(0);
		for (; i < lset.real_length; ++i)
		{
			if (!rset.contains(lset.data[i]))
				break;
		}
		return i == lset.real_length;
	}
}

bool operator!=(const Set& lset, const Set& rset)
{
	return !(lset == rset);
}

bool operator>(const Set& lset, const Set& rset)
{
	if (lset.real_length <= rset.real_length)
		return false;
	else
	{
		int i(0);
		for (; i < rset.real_length; ++i)
		{
			if (!lset.contains(rset.data[i]))
				break;
		}
		return i == rset.real_length;
	}
}

bool operator<(const Set& lset, const Set& rset)
{
	return rset > lset;
}

bool operator<=(const Set& lset, const Set& rset)
{
	return (lset < rset) || (lset == rset);
}

bool operator>=(const Set& lset, const Set& rset)
{
	return (lset > rset) || (lset == rset);
}

//������new��delete�Ĳ����Լ��ҵ���Ӧ����===================================================================================================

void* Set::operator new(size_t size)
{
	void *p = malloc(size);//����ϵͳ�ѿռ����Ĳ����������size���Զ����㣬ΪSet����ռ�õĿռ䣬����Ҫͨ�����ô���
	memset(p, 0, size);//���ռ���ȫ����ʼ��Ϊ0��Ϊ�Զ���ĳ�ʼ����ʽ
	return p;
}

void* Set::operator new(size_t size, void* p)
{
	return p;//�ڶ��������ڵ��õ�ʱ��ͨ�� new(p)����()����ʽ����ʹ�ã������ǽ��µ�������ݴ����pָ����ָ�ĵ�ַ������ϵͳ�Լ�ָ���ĵ�ַ
}

//�ڵ������ص�new������ʱ����ʹ�õ���Ĺ��캯����ʽ��������new��ʽһ�£���new(p)����(����)����ʽ���е��ü���

void Set::operator delete(void* p, size_t size)
{
	free(p);//��new��Ӧ�����пռ�Ĺ黹
}

/*
 * ���⣬���и��Ӹ����Լ�����������new��delete����������ʽ��
 * ��ԭ������Ϊ�����ϵͳ���ڶ����ռ�Ĺ������Ƿǳ��ġ���Լ���͸�Ч��
 * �������ǿ���ͨ�������Ķ�������дnew��������delete������������ռ䡣
 * 
 * ����˼��������NUM�������������Ҫ�Ŀռ䣨NUM�Ĵ�С�ɱ�д���Լ�����������ϵͳ����
 * Ȼ��ͨ���������ʽ���й����ڴ���֮��������ռ䶼���������õġ�
 * Ȼ��ͨ��һ�������ͷ��������new��ʱ����õĵ�ַ���������ַ�ϴ�������֮�󣬽������ַ��ָ����Ϊ������ʹ�õĿռ䡣
 * ֮���new�����Ͳ����ٷ����Ѿ������������Ŀռ䡣
 * ֱ�����ص�delete�����õ�ʱ�򣬽���ָ���ָ��Ŀռ�黹������ʹ�õĿռ��У����Ϊ���Ա�ʹ�õģ��Ϳ����ٴα�new�������г�ʼ����
 * �����˶�ε�new��delete����֮�󣬿���ʹ�õĿռ���ܾͲ������������Ƕ϶���������̬��
 * 
 * ͬ���ģ����һ��NUM*sizeof(��)�Ŀռ䲻���󣬿����ٴ���һ���ȴ�Ŀռ䣬�����ǽ������ӣ���Ϊһ���ӷ��ʷ�ʽ�Ͽ������壬��ʵ�ʴ洢�����ǲ������ġ�
 * 
 * 
 */
