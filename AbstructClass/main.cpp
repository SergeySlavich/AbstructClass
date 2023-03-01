#include<iostream>
using namespace std;

//TODO:
//Реализовать иерархию геометрических фигур : квадрат, треугольник, прямоугольник, круг и т.д.
//Для каждой фигуры необходимо вывести ее первичные свойства, такие как радиус, длина стороны, и т.д.
//и вторичные свойства такие как площадь, периметр, так же каждую фигуру нужно нарисовать.

enum Color
{
	console_blue = 0x99,
	console_green = 0xAA,
	console_red = 0xCC,
	console_default = 0x07
};

class Shape
{
	Color color;
public:
	Shape(Color color) :color(color) {};
	virtual ~Shape() {}

	virtual double get_area()const = 0;
	virtual double get_perimeter()const = 0;
	virtual void draw()const = 0;
};

void main()
{
	setlocale(LC_ALL, "");

}