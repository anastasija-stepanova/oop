// Figures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CCanvas.h"
#include "CShapeCreator.h"
#include "ICanvas.h"

using namespace std;

void DrawShapes(vector<shared_ptr<IShape>>& shapes)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Canvas");
	CCanvas canvas(window);
	for (auto shape : shapes)
	{
		shape->Draw(canvas);
	}
	window.display();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
	}
}

void PrintShapesInfo(vector<shared_ptr<IShape>>& shapes)
{
	for (auto shape : shapes)
	{
		cout << shape->ToString() << endl;
	}
}

void PrintShapeWithMinPerimeter(vector<shared_ptr<IShape>>& shapes)
{
	vector<shared_ptr<IShape>>::iterator it = min_element(shapes.begin(), shapes.end(),
		[](const shared_ptr<IShape>& shapeOne, const shared_ptr<IShape>& shapeTwo) {
			return shapeOne->GetPerimeter() < shapeTwo->GetPerimeter();
		});
	if (it != shapes.end())
	{
		cout << (*it)->ToString() << endl;
	}
}

void PrintShapeWithMaxArea(vector<shared_ptr<IShape>>& shapes)
{
	vector<shared_ptr<IShape>>::iterator it = max_element(shapes.begin(), shapes.end(),
		[](const shared_ptr<IShape>& shapeOne, const shared_ptr<IShape>& shapeTwo) {
			return shapeOne->GetArea() < shapeTwo->GetArea();
		});
	if (it != shapes.end())
	{
		cout << (*it)->ToString() << endl;
	}
}

int _tmain()
{
	try
	{
		vector<shared_ptr<IShape>> shapes;
		CShapeCreator shapeCreator(cin);
		while (auto shape = shapeCreator.HandleCommand())
		{
			shapes.push_back(shape);
		}

		if (!shapes.empty())
		{
			PrintShapesInfo(shapes);

			cout << "Shape with min perimeter: " << endl;
			PrintShapeWithMinPerimeter(shapes);

			cout << "Shape with max area: " << endl;
			PrintShapeWithMaxArea(shapes);

			DrawShapes(shapes);
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
	return 0;
}
