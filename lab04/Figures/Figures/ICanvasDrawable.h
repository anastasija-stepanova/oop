#pragma once
#include "ICanvas.h"

class ICanvasDrawable
{
public:
	ICanvasDrawable();
	virtual void Draw(ICanvas& canvas) const = 0;
	virtual ~ICanvasDrawable();
};
