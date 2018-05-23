#include "stdafx.h"
#include "CCanvas.h"
#include "Config.h"

CCanvas::CCanvas(sf::RenderWindow& window)
	: m_window(window)
{
}

CCanvas::~CCanvas()
{
}

void CCanvas::DrawLine(const CPoint& start, const CPoint& end, uint32_t lineColor)
{
	sf::Vertex vertices[] = {
		sf::Vertex(sf::Vector2f(
					   static_cast<float>(start.GetX()),
					   static_cast<float>(start.GetY())),
			sf::Color(sf::Uint32(lineColor))),

		sf::Vertex(sf::Vector2f(
					   static_cast<float>(end.GetX()),
					   static_cast<float>(end.GetY())),
			sf::Color(sf::Uint32(lineColor)))
	};
	m_window.draw(vertices, 2, sf::Lines);
}

void CCanvas::FillPolygon(const std::vector<CPoint>& points, uint32_t fillColor)
{
	sf::ConvexShape polygon;
	polygon.setPointCount(points.size());
	polygon.setFillColor(sf::Color(sf::Uint32(fillColor)));

	for (size_t i = 0; i < points.size(); i++)
	{
		polygon.setPoint(i, sf::Vector2f(static_cast<float>(points[i].GetX()), static_cast<float>(points[i].GetY())));
	}
	m_window.draw(polygon);
}

void CCanvas::DrawCircle(const CPoint& center, double radius, uint32_t lineColor)
{
	sf::CircleShape circle(static_cast<float>(radius));
	circle.setPosition(sf::Vector2f(
		static_cast<float>(center.GetX()),
		static_cast<float>(center.GetY())));

	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(OUTLINE_THICKNESS);
	circle.setOutlineColor(sf::Color(sf::Uint32(lineColor)));
	m_window.draw(circle);
}

void CCanvas::FillCircle(const CPoint& center, double radius, uint32_t fillColor)
{
	sf::CircleShape circle(static_cast<float>(radius));

	circle.setPosition(sf::Vector2f(
		static_cast<float>(center.GetX()),
		static_cast<float>(center.GetY())));
	circle.setFillColor(sf::Color(sf::Uint32(fillColor)));
	m_window.draw(circle);
}
