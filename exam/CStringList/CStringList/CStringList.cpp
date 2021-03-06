#include "stdafx.h"
#include <cassert>

using namespace std;

// *Односвязный* список строк
class CStringList
{
private:
	struct Node
	{
		Node(const string& data)
			: data(data)
		{
		}

		string data;
		unique_ptr<Node> next = nullptr;
	};

public:
	CStringList()
	{
	}

	CStringList(const CStringList& list)
	{
		*this = list;
	}

	CStringList(CStringList&& list)
	{
		*this = move(list);
	}

	~CStringList()
	{
		Clear();
	}

	CStringList& operator=(const CStringList& list)
	{
		auto newFront = GetCopy(list.m_front.get());
		Clear(move(m_front));
		m_front = move(newFront);
		m_size = list.m_size;

		return *this;
	}

	CStringList& operator=(CStringList&& listForMove)
	{
		if (this == &listForMove)
		{
			return *this;
		}

		swap(m_front, listForMove.m_front);
		swap(m_size, listForMove.m_size);

		listForMove.Clear();

		return *this;
	}

	// Добавляет строку в начало списка. Время выполнения: O(1)
	void AddToBegin(const string& value)
	{
		auto pNewNode = make_unique<Node>(value);
		pNewNode->next = move(m_front);

		m_front = move(pNewNode);
		m_size++;
	}

	// Возвращает размер списка. Время выполнения: O(1)
	size_t GetSize() const
	{
		return m_size;
	}

	// Возвращает первый элемент списка. Бросает logic_error, если список пуст
	// Время выполнения: O(1)
	string GetFront() const
	{
		if (!m_front)
		{
			throw logic_error("List is empty");
		}

		return m_front->data;
	}

	// Выводит элементы списка в out (по одному в каждой строке)
	void PrintList(ostream& out) const
	{
		Node* pNode = m_front.get();

		while (pNode)
		{
			out << pNode->data << endl;
			pNode = pNode->next.get();
		}
	}

	// Очищает список
	void Clear()
	{
		Clear(move(m_front));
		m_size = 0;
	}

private:
	static unique_ptr<Node> GetCopy(Node* pNode)
	{
		if (pNode == nullptr)
		{
			return nullptr;
		}

		auto pCopy = make_unique<Node>(pNode->data);
		Node* pBack = pCopy.get();
		pNode = pNode->next.get();

		try
		{
			while (pNode)
			{
				pBack->next = make_unique<Node>(pNode->data);
				pBack = pBack->next.get();
				pNode = pNode->next.get();
			}
		}
		catch (...)
		{
			Clear(move(pCopy));
			throw;
		}

		return move(pCopy);
	}

	static void Clear(unique_ptr<Node> pNode)
	{
		while (pNode)
		{
			pNode = move(pNode->next);
		}
	}

	size_t m_size = 0;
	unique_ptr<Node> m_front = nullptr;
};

int main()
{
	CStringList list;

	cout << "List:" << endl;
	list.PrintList(cout);
	cout << "size: " << list.GetSize() << endl;

	list.AddToBegin("aaa");
	list.AddToBegin("bbb");
	list.AddToBegin("ccc");

	cout << "List with data:" << endl;
	list.PrintList(cout);
	cout << "front: " << list.GetFront() << endl;
	cout << "size: " << list.GetSize() << endl;

	cout << "Copy:" << endl;
	CStringList copy(list);
	copy.PrintList(cout);
	cout << "front: " << copy.GetFront() << endl;
	cout << "size: " << copy.GetSize() << endl;

	cout << "List after clear:" << endl;
	list.Clear();
	list.PrintList(cout);
	cout << "size: " << list.GetSize() << endl;

	return 0;
}
