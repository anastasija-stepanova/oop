#pragma once
#include "CMyIterator.h"

template <typename T>
class CMyList
{
public:
	CMyList();
	CMyList(const CMyList<T>& other);
	~CMyList();
	CMyList(CMyList<T>&& other);

	CMyList<T>& operator=(const CMyList<T>& other);
	CMyList<T>& operator=(CMyList<T>&& other);

	size_t GetSize() const;
	bool IsEmpty() const;

	void PushBack(const T& data);
	void PushFront(const T& data);
	void Insert(const CMyIterator<T>& it, const T& data);

	void Erase(const CMyIterator<T>& it);
	void Clear();

	CMyIterator<T> begin();
	CMyIterator<T> end();
	CMyIterator<const T> begin() const;
	CMyIterator<const T> end() const;
	CMyIterator<const T> cbegin() const;
	CMyIterator<const T> cend() const;

	std::reverse_iterator<CMyIterator<T>> rbegin();
	std::reverse_iterator<CMyIterator<T>> rend();
	std::reverse_iterator<CMyIterator<const T>> rbegin() const;
	std::reverse_iterator<CMyIterator<const T>> rend() const;

private:
	size_t m_size = 0;
	std::unique_ptr<Node<T>> m_firstNode = nullptr;
	Node<T>* m_lastNode = nullptr;

	void swapsValues(CMyList<T> tmp);
};

using namespace std;

template <typename T>
CMyList<T>::CMyList()
{
	m_firstNode = make_unique<Node<T>>(nullopt, nullptr, nullptr);
	m_firstNode->next = make_unique<Node<T>>(nullopt, m_firstNode.get(), nullptr);
	m_lastNode = m_firstNode->next.get();
}

template <typename T>
CMyList<T>::CMyList(const CMyList<T>& other)
	: CMyList<T>()
{
	try
	{
		for (auto const& data : other)
		{
			PushBack(data);
		}
	}
	catch (...)
	{
		Clear();
		throw;
	}
}

template <typename T>
CMyList<T>::CMyList(CMyList<T>&& other)
	: CMyList<T>()
{
	swapsValues(tmp);
}

template <typename T>
CMyList<T>& CMyList<T>::operator=(CMyList<T> const& other)
{
	if (this != addressof(other))
	{
		CMyList<T> tmp(other);
		swapsValues(tmp);
	}
	return *this;
}

template <typename T>
CMyList<T>& CMyList<T>::operator=(CMyList<T>&& other)
{
	if (this != addressof(other))
	{
		CMyList<T> tmp(move(other));
		swapsValues(tmp);
	}
	return *this;
}

template <typename T>
CMyList<T>::~CMyList()
{
	Clear();
}

template <typename T>
size_t CMyList<T>::GetSize() const
{
	return m_size;
}

template <typename T>
bool CMyList<T>::IsEmpty() const
{
	return m_size == 0;
}

template <typename T>
void CMyList<T>::PushBack(const T& data)
{
	Insert(end(), data);
}

template <typename T>
void CMyList<T>::PushFront(const T& data)
{
	Insert(begin(), data);
}

template <typename T>
void CMyList<T>::Insert(const CMyIterator<T>& it, const T& data)
{
	unique_ptr<Node<T>> newNode = make_unique<Node<T>>(make_optional(data), it.m_node->prev, move(it.m_node->prev->next));
	it.m_node->prev = newNode.get();
	newNode->prev->next = move(newNode);
	++m_size;
}

template <typename T>
void CMyList<T>::Erase(const CMyIterator<T>& it)
{
	it.m_node->next->prev = it.m_node->prev;
	it.m_node->prev->next = move(it.m_node->next);
	--m_size;
}

template <typename T>
void CMyList<T>::Clear()
{
	while (m_size != 0)
	{
		Erase(begin());
	}
}

template <typename T>
CMyIterator<T> CMyList<T>::begin()
{
	return m_firstNode->next.get();
}

template <typename T>
CMyIterator<const T> CMyList<T>::begin() const
{
	return m_firstNode->next.get();
}

template <typename T>
CMyIterator<T> CMyList<T>::end()
{
	return m_lastNode;
}

template <typename T>
CMyIterator<const T> CMyList<T>::end() const
{
	return m_lastNode;
}

template <typename T>
CMyIterator<const T> CMyList<T>::cbegin() const
{
	return begin();
}

template <typename T>
CMyIterator<const T> CMyList<T>::cend() const
{
	return end();
}

template <typename T>
reverse_iterator<CMyIterator<T>> CMyList<T>::rbegin()
{
	return reverse_iterator<CMyIterator<T>>(end());
}

template <typename T>
reverse_iterator<CMyIterator<const T>> CMyList<T>::rbegin() const
{
	return reverse_iterator<CMyIterator<const T>>(end());
}

template <typename T>
reverse_iterator<CMyIterator<T>> CMyList<T>::rend()
{
	return reverse_iterator<CMyIterator<T>>(begin());
}

template <typename T>
reverse_iterator<CMyIterator<const T>> CMyList<T>::rend() const
{
	return reverse_iterator<CMyIterator<const T>>(begin());
}

template <typename T>
void CMyList<T>::swapsValues(CMyList<T> tmp)
{
	swap(m_firstNode, tmp.m_firstNode);
	swap(m_lastNode, tmp.m_lastNode);
	swap(m_size, tmp.m_size);
}