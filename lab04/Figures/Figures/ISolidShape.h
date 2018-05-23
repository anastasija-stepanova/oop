#pragma once
#include "IShape.h"

class ISolidShape : public virtual IShape
{
public:
	ISolidShape();
	virtual std::string GetFillColor() const = 0;
	~ISolidShape();
};
