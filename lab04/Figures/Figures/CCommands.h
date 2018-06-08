#pragma once
#include "CCircle.h"
#include "CLineSegment.h"
#include "CPoint.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "ICommand.h"
#include "IShape.h"
#include <memory>

class CAddLineSegmentCommand : public ICommand
{
public:
	CAddLineSegmentCommand(std::vector<std::unique_ptr<IShape>>& shapes);
	void Execute(const std::vector<std::string>& params) override;

private:
	std::vector<std::unique_ptr<IShape>>& m_shapes;
};

class CAddCircleCommand : public ICommand
{
public:
	CAddCircleCommand(std::vector<std::unique_ptr<IShape>>& shapes);
	void Execute(const std::vector<std::string>& params) override;

private:
	std::vector<std::unique_ptr<IShape>>& m_shapes;
};

class CAddRectangleCommand : public ICommand
{
public:
	CAddRectangleCommand(std::vector<std::unique_ptr<IShape>>& shapes);
	void Execute(const std::vector<std::string>& params) override;

private:
	std::vector<std::unique_ptr<IShape>>& m_shapes;
};

class CAddTriangleCommand : public ICommand
{
public:
	CAddTriangleCommand(std::vector<std::unique_ptr<IShape>>& shapes);
	void Execute(const std::vector<std::string>& params) override;

private:
	std::vector<std::unique_ptr<IShape>>& m_shapes;
};

class CPrintInfoCommand : public ICommand
{
public:
	CPrintInfoCommand(std::vector<std::unique_ptr<IShape>>& shapes);
	void Execute(const std::vector<std::string>& params) override;

private:
	std::vector<std::unique_ptr<IShape>>& m_shapes;
};

class CPrintMinPerimeterCommand : public ICommand
{
public:
	CPrintMinPerimeterCommand(std::vector<std::unique_ptr<IShape>>& shapes);
	void Execute(const std::vector<std::string>& params) override;

private:
	std::vector<std::unique_ptr<IShape>>& m_shapes;
};

class CPrintMaxAreaCommand : public ICommand
{
public:
	CPrintMaxAreaCommand(std::vector<std::unique_ptr<IShape>>& shapes);
	void Execute(const std::vector<std::string>& params) override;

private:
	std::vector<std::unique_ptr<IShape>>& m_shapes;
};
