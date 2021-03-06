#include "stdafx.h"
#include "CStringStack.h"

using namespace std;

CStringStack::Node::Node(const string& data, unique_ptr<Node>&& next)
	: data(data)
	, next(move(next))
{
}

CStringStack::CStringStack()
{
}

CStringStack::CStringStack(const CStringStack& stack)
{
	*(this) = stack;
}

CStringStack::CStringStack(CStringStack&& stack)
{
	if (this != addressof(stack))
	{
		m_top = move(stack.m_top);
		stack.m_top = nullptr;
	}
}

CStringStack::~CStringStack()
{
	Clear();
}

CStringStack& CStringStack::operator=(const CStringStack& stackForCopy)
{
	if (stackForCopy.IsEmpty())
	{
		Clear();
		return *this;
	}

	if (this != addressof(stackForCopy))
	{
		Node* node = stackForCopy.m_top.get();
		unique_ptr<Node> element = make_unique<Node>(node->data, nullptr);
		unique_ptr<Node> top = make_unique<Node>(element->data, nullptr);

		node = node->next.get();
		while (node)
		{
			element->next = make_unique<Node>(node->data, nullptr);
			element = move(element->next);
			node = node->next.get();
		}
		Clear();
		m_top.swap(top);
	}
	return *this;
}

CStringStack& CStringStack::operator=(CStringStack&& stackForMove)
{
	if (stackForMove.IsEmpty())
	{
		Clear();
		return *this;
	}

	if (this != addressof(stackForMove))
	{
		m_top = move(stackForMove.m_top);
		stackForMove.m_top = nullptr;
	}
	return *this;
}

void CStringStack::Push(const string& data)
{
	auto newNode = make_unique<Node>(data, move(m_top));
	m_top = move(newNode);
}

bool CStringStack::IsEmpty() const
{
	return m_top == nullptr;
}

string CStringStack::GetTopValue() const
{
	if (IsEmpty())
	{
		throw logic_error("Stack is empty");
	}
	return m_top->data;
}

void CStringStack::Pop()
{
	if (IsEmpty())
	{
		throw logic_error("Stack is empty");
	}
	m_top = move(m_top->next);
}

void CStringStack::Clear()
{
	while (m_top)
	{
		Pop();
	}
}
