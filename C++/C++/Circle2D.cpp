#include <cmath>
#include "Circle2D.h"

Circle2D::Circle2D()
{
	x = 0;
	y = 0;
	radius = 1;
}

Circle2D::Circle2D(double x, double y, double radius)
{
	this->x = x;
	this->y = y;
	this->radius = radius;
}

double Circle2D::getX() const
{
	return x;
}

double Circle2D::getY() const
{
	return y;
}

double Circle2D::getRadius() const
{
	return radius;
}

double Circle2D::getArea() const
{
	return radius * radius * 3.14159;
}

double Circle2D::getPerimeter() const
{
	return (radius * 2 * 3.14159);
}

bool Circle2D::contains(double x, double y) const
{
	if (sqrt(pow((x - this->x), 2) + pow((y - this->y), 2)) < radius)
		return 1;
	else
		return 0;
}

bool Circle2D::contains(const Circle2D& circle) const
{
	double centerDistance =
		sqrt(pow((x - circle.getX()), 2) + pow((y - circle.getY()), 2));

	if (centerDistance <= abs(radius - circle.getRadius()) && circle.radius 
		!= radius)
		return 1;
	else
		return 0;
}

bool Circle2D::overlaps(const Circle2D& circle) const
{
	//两圆相交的条件
	//圆心距大于两圆半径之差，小于两圆半径之和
	double centerDistance =
		sqrt(pow((x - circle.getX()), 2) + pow((y - circle.getY()), 2));
	if (centerDistance > abs(radius - circle.getRadius()) && 
		centerDistance < abs(radius + circle.getRadius()))
		return 1;
	else
		return 0;
}