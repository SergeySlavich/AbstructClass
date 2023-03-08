#include<Windows.h>
#include<iostream>
using namespace std;

//TODO:
//Реализовать иерархию геометрических фигур : квадрат, треугольник, прямоугольник, круг и т.д.
//Для каждой фигуры необходимо вывести ее первичные свойства, такие как радиус, длина стороны, и т.д.
//и вторичные свойства такие как площадь, периметр, так же каждую фигуру нужно нарисовать.
//Для рисования фигуры нужно задать начальные координаты, по которым фигура будет выводится.

#define delimiter "\n----------------------------------------\n"

namespace Geometry
{
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,
		white = 0x00FFFFFF,

		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_default = 0x07
	};
	//enum (Enumeration - Перечисление) - это набор именованных констант типа 'int'

	class Shape
	{
	protected:
		Color color;
		int start_x;
		int start_y;
		int line_width;
	public:
		int get_start_x()const
		{
			return start_x;
		}
		int get_start_y()const
		{
			return start_y;
		}
		int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(int start_x)
		{
			if (start_x < 10)start_x = 10;
			if (start_x > 1000)start_x = 1000;
			this->start_x = start_x;
		}
		void set_start_y(int start_y)
		{
			if (start_y < 10)start_y = 10;
			if (start_y > 1000)start_y = 1000;
			this->start_y = start_y;
		}
		void set_line_width(int line_width)
		{
			if (line_width < 5)line_width = 5;
			if (line_width > 20)line_width = 20;
			this->line_width = line_width;
		}

		Shape(Color color, int start_x, int start_y, int line_width) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "Area: " << get_area() << endl;
			cout << "Perimeter: " << get_perimeter() << endl;
			draw();
		}
	};

	/*class Square :public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side > 20)side = 20;
			if (side < 5)side = 5;
			this->side = side;
		}
		//					Constructors:
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Square() {}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, color);
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны квадрата: " << side << endl;
			Shape::info();
		}
	};*/

	class Rectangle :public Shape
	{
		double side_1, side_2;
	public:
		// Getters & Setters
		double get_side_1()const
		{
			return side_1;
		}
		double get_side_2()const
		{
			return side_2;
		}
		void set_side_1(double side_1)
		{
			if (side_1 < 50)side_1 = 50;
			if (side_1 > 550)side_1 = 550;
			this->side_1 = side_1;
		}
		void set_side_2(double side_2)
		{
			if (side_2 < 50)side_2 = 50;
			if (side_2 > 550)side_2 = 550;
			this->side_2 = side_2;
		}
		// Constructors & Destructor
		Rectangle(double side_1, double side_2, Color color, int start_x, int start_y, int line_width)
			:Shape(color, start_x, start_y, line_width)
		{
			set_side_1(side_1);
			set_side_2(side_2);
		}
		~Rectangle() {}
		// Methods
		double get_area()const override
		{
			return side_1 * side_2;
		}
		double get_perimeter()const override
		{
			return (side_1 + side_2) * 2;
		}
		void draw()const
		{

			HWND hwnd = GetConsoleWindow();	//Получаем обработчик окна консоли
			HDC hdc = GetDC(hwnd);	//Получаем контекст устройства окна косоли
			//Контекст устройства - это то, на чем мы будем рисовать

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			//Pen (карандаш) рисует контур фигуры,
			//PS_SOLID - сплошная линия
			//5 - толщина линии 5 пикселов

			HBRUSH hBrush = CreateSolidBrush(color);
			//Brush - это кисть, рисует заливку замкнутой фигуры.

			//Выбираем чем и на чем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Когда все инструменты созданы и выбраны, можно вызывать функцию,
			//для рисования нужной фигуры:

			::Rectangle(hdc, start_x, start_y, start_x + side_1, start_y + side_2);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);	//Освобождаем контекст устройства
		}

		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "Side 1: " << side_1 << endl;
			cout << "Side 2: " << side_2 << endl;
			Shape::info();
		}
	};

	class Square :public Rectangle
	{
	public:
		Square(double side, Color color, int start_x, int start_y, int line_width)
			:Rectangle(side, side, color, start_x, start_y, line_width) {}
		~Square() {}
	};

	class Triangle:public Shape
	{
	public:
		Triangle(Color color, int start_x, int start_y, int line_width)
			:Shape(color, start_x, start_y, line_width)
		{}
		~Triangle() {};
		// Methods
		virtual double get_height() const = 0;
		void info()const
		{
			cout << "Height of triangle: " << get_height() << endl;
			Shape::info();
		}
	};

	class EqulateralTriangle :public Triangle
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side < 50) side = 50;
			if (side > 500) side = 50;
			this->side = side;
		}
		//		Constructor:
		EqulateralTriangle(double side, Color color, int start_x, int start_y, int line_width) :
			Triangle(color, start_x, start_y, line_width)
		{
			set_side(side);
		}
		~EqulateralTriangle() {};
		double get_height()const override
		{
			return side * sqrt(3)/2;
		}
		double get_area()const override
		{
			return side * get_height() * 0.5;
		}
		double get_perimeter()const override
		{
			return 3 * side;
		}
		void draw()const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT point[] =
			{
				{start_x + side / 2, start_y},
				{start_x, start_y + get_height()},
				{start_x + side, start_y + get_height()}
			};
			::Polygon(hdc, point, 3);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Side: " << side << endl;
			Triangle::info();
		}
	};

	class IsoscelesTriangle :public Triangle
	{
		double base;
		double side;
	public:
		double get_base()const
		{
			return base;
		}
		double get_side()const
		{
			return side;
		}
		void set_base(double base)
		{
			if (base < 50) base = 50;
			if (base > 500) base = 500;
			this->base = base;
		}
		void set_side(double side)
		{
			if (side < 50) side = 50;
			if (side > 500) side = 500;
			this->side = side;
		}
		IsoscelesTriangle(double base, double side, Color color, int start_x, int start_y, int line_width) :
			Triangle(color, start_x, start_y, line_width)
		{
			set_base(base);
			set_side(side);
		}
		~IsoscelesTriangle() {};
		double get_height()const override
		{
			return sqrt(side * side - (double)(base * base) / 4);
		}
		double get_area()const override
		{
			return 0.5 * base * get_height();
		}
		double get_perimeter()const override
		{
			return base + 2 * side;
		}
		void draw() const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT point[] =
			{
				{start_x, start_y + side},
				{start_x + base, start_y + side},
				{(start_x + base / 2), (start_y + side - get_height())}
			};
			::Polygon(hdc, point, 3);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Base: " << base << endl;
			cout << "Side: " << side << endl;
			Triangle::info();
		}
	};

	class RectangularTriangle :public Triangle
	{
		double hypotenuse;
		double cathet_1;
		double cathet_2;
	public:
		double get_hypotenuse()const
		{
			return hypotenuse;
		}
		double get_cathet_1()const
		{
			return cathet_1;
		}
		double get_cathet_2()const
		{
			return cathet_2;
		}
		void set_hypotenuse(double hypotenuse)
		{
			if (hypotenuse < 30) hypotenuse = 30;
			if (hypotenuse > 500) hypotenuse = 500;
			if (cathet_1 && cathet_2)
			{
				cout << "cathet_1: " << cathet_1 << endl;
				cout << "cathet_2: " << cathet_2 << endl;
				cout << "hypotenuse: " << hypotenuse << endl;
				this->hypotenuse = sqrt((cathet_1 * cathet_1) + (cathet_2 * cathet_2));
				if (hypotenuse != this->hypotenuse) cout << "Error! Hypotenuse must " << this->hypotenuse << endl;
			}
			else
			{
				if(cathet_1 < hypotenuse && cathet_2 < hypotenuse) this->hypotenuse = hypotenuse;
				else
				{
					cout << "Error! Hypotenuse must greater of cathet.\n";
					this->hypotenuse = (cathet_1) ? (cathet_1 + 1) : (cathet_2 + 1);
				}
			}
		}
		void set_cathet_1(double cathet_1)
		{
			if (cathet_1 < 30) cathet_1 = 30;
			if (cathet_1 > 500) cathet_1 = 500;
			this->cathet_1 = cathet_1;
		}
		void set_cathet_2(double cathet_2)
		{
			if (cathet_2 < 30) cathet_2 = 30;
			if (cathet_2 > 500) cathet_2 = 500;
			this->cathet_2 = cathet_2;
		}
		RectangularTriangle(double cathet_1, double cathet_2, double hypotenuse, Color color, int start_x, int start_y, int line_width) :
			Triangle(color, start_x, start_y, line_width)
		{
			set_cathet_1(cathet_1);
			set_cathet_2(cathet_2);
			set_hypotenuse(hypotenuse);
		}
		~RectangularTriangle() {};
		double get_height()const override
		{
			return cathet_1;
		}
		double get_area()const override
		{
			return cathet_1 * cathet_2 * 0.5;
		}
		double get_perimeter()const override
		{
			return hypotenuse + cathet_1 + cathet_2;
		}
		void draw() const override
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT point[] =
			{
				{start_x, start_y},
				{start_x, start_y + cathet_1},
				{start_x + cathet_2, start_y + cathet_1}
			};
			::Polygon(hdc, point, 3);
			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Hypotenuse: " << hypotenuse << endl;
			cout << "Cathet 1: " << cathet_1 << endl;
			cout << "Cathet 2: " << cathet_2 << endl;
			Triangle::info();
		}
	};
	
	class Round:public Shape
	{
		double radius;
	public:
		// Getters & Setters
		double get_radius()
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius < 5) radius = 5;
			if (radius > 500) radius = 500;
			this->radius = radius;
		}
		// Constructors & Destructor
		Round(double radius, Color color, int start_x, int start_y, int line_width)
			:Shape(color, start_x, start_y, line_width)
		{
			set_radius(radius);
		}
		~Round() {};
		// Methods
		double get_area()const override
		{
			return 3.14 * radius * radius;
		}
		double get_perimeter()const override
		{
			return 3.14 * 2 * radius;
		}
		void draw()const override
		{

			HWND hwnd = GetConsoleWindow();	//Получаем обработчик окна консоли
			HDC hdc = GetDC(hwnd);	//Получаем контекст устройства окна косоли
			//Контекст устройства - это то, на чем мы будем рисовать

			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			//Pen (карандаш) рисует контур фигуры,
			//PS_SOLID - сплошная линия
			//5 - толщина линии 5 пикселов

			HBRUSH hBrush = CreateSolidBrush(color);
			//Brush - это кисть, рисует заливку замкнутой фигуры.

			//Выбираем чем и на чем рисовать:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//Когда все инструменты созданы и выбраны, можно вызывать функцию,
			//для рисования нужной фигуры:

			::Ellipse(hdc, start_x, start_y, start_x + 2 * radius, start_y + 2 * radius);

			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);	//Освобождаем контекст устройства
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Radius: " << radius << endl;
			Shape::info();
		}
	};
}

void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {};
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN_MODE, &coord);

	setlocale(LC_ALL, "");

	Geometry::Square square(100, Geometry::Color::red, 450, 10, 5);
	square.info();

	Geometry::Rectangle rect(120, 75, Geometry::Color::blue, 500, 130, 8);
	rect.info();

	Geometry::Round round(50, Geometry::Color::green, 550, 220, 5);
	round.info();

	Geometry::EqulateralTriangle equlateralTriangle(90, Geometry::Color::blue, 600, 340, 5);
	equlateralTriangle.info();

	Geometry::IsoscelesTriangle isoscelesTriangle(90, 50, Geometry::Color::red, 650, 450, 5);
	isoscelesTriangle.info();

	Geometry::RectangularTriangle rectangularTriangle(60, 80, 100, Geometry::Color::yellow, 700, 560, 5);
	rectangularTriangle.info();
}