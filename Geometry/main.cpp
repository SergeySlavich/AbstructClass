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
//					Square
class Square :public Shape
{
	Color color;
	int a;
public:
	//					Constructors:
	Square(Color color, int a = 1) :Shape(color)
	{
		this->color = color;
		this->a = a;
	};
	//					Destructor:
	~Square() {}
	double get_area()const override
	{
		return a * a;
	}
	double get_perimeter()const override
	{
		return 4 * a;
	}
	//					Methods:
	void draw()const
	{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < a; j++)
			{
				cout << '*';
			}
			cout << endl;
		}
		cout << endl;
	}
};
//					Triangle
class Triangle :public Shape
{
	Color color;
	int a, h;
public:
	//					Constructors:
	Triangle(Color color, int a = 1, int h = 1) :Shape(color)
	{
		this->color = color;
		this->a = a;
		this->h = h;
	};
	//					Destructor:
	~Triangle() {}
	double get_area()const override
	{
		return (double)a * h * 0.5;
	}
	double get_perimeter()const override
	{
		return (double)a + h + sqrt(a * a + h * h);
	}
	//					Methods:
	void draw()const
	{
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < (int)(i * ((double)a / h)); j++)
			{
				cout << '*';
			}
			cout << endl;
		}
		cout << endl;
	}
};
//					Rectangle
class Rectangle:public Shape
{
	Color color;
	int a, b;
public:
	//					Constructors:
	Rectangle(Color color, int a = 1, int b = 1) :Shape(color)
	{
		this->color = color;
		this->a = a;
		this->b = b;
	};
	//					Destructor:
	~Rectangle() {}
	double get_area()const override
	{
		return a * b;
	}
	double get_perimeter()const override
	{
		return 2 * (a + b);
	}
	//					Methods:
	void draw()const
	{
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			{
				cout << '*';
			}
			cout << endl;
		}
		cout << endl;
	}
};
//					Round
class Round :public Shape
{
	Color color;
	int r;
public:
	//					Constructors:
	Round(Color color, int r = 1) :Shape(color)
	{
		this->color = color;
		this->r = r;
	};
	//					Destructor:
	~Round() {}
	double get_area()const override
	{
		return 3.14 * (double)r * r;
	}
	double get_perimeter()const override
	{
		return 2 * 3.14 * (double)r;
	}
	//					Methods:
	void draw()const
	{
		cout << "Draw round...." << endl;
		//for (int i = 0; i < r; i++)
		//{
		//	for (int j = 0; j < 2 * r; j++)
		//	{
		//		if ((r - i) < (int)sqrt(r * r - j * j)) cout << '*';
		//		//if (j > (int)sqrt(r * r - (j - r) * (j - r))) cout << '*';
		//	}
		//	cout << endl;
		//}
		//for (int i = r; i < 2 * r; i++)
		//{
		//	for (int j = 0; j < 2 * r; j++)
		//	{
		//		//if ((j - r) > (int)sqrt(r * r - j * j)) cout << '*';
		//		if (i > r && (i) < (int)sqrt(4 * r * r - (j - r) * (j - r))) cout << '*';
		//	}
		//	cout << endl;
		//}
		//cout << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	Rectangle rect(console_red, 5, 6);
	cout << typeid(rect).name() << endl;
	cout << "Area of shape: " << rect.get_area() << endl;
	cout << "Perimeter of shape: " << rect.get_perimeter() << endl;
	cout << "Draw shape:\n";
	rect.draw();
	cout << "\n--------------------------------------------------------------------\n";

	Square quattro(console_red, 5);
	cout << typeid(quattro).name() << endl;
	cout << "Area of shape: " << quattro.get_area() << endl;
	cout << "Perimeter of shape: " << quattro.get_perimeter() << endl;
	cout << "Draw shape:\n";
	quattro.draw();
	cout << "\n--------------------------------------------------------------------\n";

	Triangle trio(console_red, 6, 8);
	cout << typeid(trio).name() << endl;
	cout << "Area of shape: " << trio.get_area() << endl;
	cout << "Perimeter of shape: " << trio.get_perimeter() << endl;
	cout << "Draw shape:\n";
	trio.draw();
	cout << "\n--------------------------------------------------------------------\n";

	Round round(console_red, 10);
	cout << typeid(round).name() << endl;
	cout << "Area of shape: " << round.get_area() << endl;
	cout << "Perimeter of shape: " << round.get_perimeter() << endl;
	cout << "Draw shape:\n";
	round.draw();
	cout << "\n--------------------------------------------------------------------\n";

}