#pragma once
#include "CCanvas.h"
#include "CPoint.h"
#include "IShape.h"
#include "CCommands.h"

class CShapeCreator
{
public:
	CShapeCreator();
	~CShapeCreator() = default;
	void Run(std::istream& stream);
private:
	struct Item
	{
		Item(const std::string& shortcut, std::unique_ptr<ICommand>&& command)
			:shortcut(shortcut)
			,command(std::move(command))
		{
		}
		std::string shortcut;
		std::unique_ptr<ICommand> command;
	};

	void AddItem(const std::string & shortcut, std::unique_ptr<ICommand> && command)
	{
		m_actionMap.emplace_back(shortcut, std::move(command));
	}

	using ActionMap = std::vector<Item>;
	ActionMap m_actionMap;
	std::vector<std::unique_ptr<IShape>> m_shapes;
};