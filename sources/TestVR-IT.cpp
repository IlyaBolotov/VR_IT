#define _USE_MATH_DEFINES // Для числа ПИ
#include <iostream>
#include <vector>		// Массивы
#include <thread>		// Многопоточность
#include <cmath>		// Математика (число ПИ и корень)
#include <string>		// Строка для динамического ввода
#include <ctime>		// Системное время для сида рандома
#include <algorithm>	// Функция sort во втором задании

std::vector <int> BubbleSort(std::vector<int> arr) { // "Пузырьковая сортировка" - сравнивается каждый со следующим и меняется местами

	bool flag = false;
	int value = 0;

	do {
		flag = false;
		for (int i = 0; i <= arr.size() - 2; i++) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				flag = true;
			}
		}
	} while (flag);

	std::cout << std::endl;
	std::cout << "BubbleSort:\n";
	for (int i = 0;i < arr.size();i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return arr;
}

std::vector <int> SmallestSort(std::vector<int> arr) { // Сортировка от малого к большему - находится самый малый объект и переставляется в начало массива

	int small = 0, i = 0, j = 0;

	for (i = 0; i < arr.size() - 1; i++) {
		small = i;
		for (int j = i + 1; j < arr.size(); j++) {
			if (arr[j] < arr[small]) {
				small = j;
			}
		}
		std::swap(arr[i], arr[small]);
	}

	std::cout << std::endl;
	std::cout << "SmallestSort:\n";
	for (int i = 0;i < arr.size();i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return arr;
}

std::vector <int> InsertionSort(std::vector<int> arr) { // Поочерёдная сортировка - Сравнивается элемент со всеми предыдущими

	for (int i = 1; i < arr.size(); i++) {
		int j = i - 1;
		while (j >= 0 && arr[j] > arr[j + 1]) {
			std::swap(arr[j], arr[j + 1]);
			j--;
		}
	}

	std::cout << std::endl;
	std::cout << "InsertionSort:\n";
	for (int i = 0;i < arr.size();i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return arr;
}

void Merge(std::vector<int>& arr, int left, int mid, int right) { // Слияние двух массивов с их сортировкой
	int leftsize = mid - left + 1;
	int rightsize = right - mid;

	std::vector<int> leftarr(leftsize);
	std::vector<int> rightarr(rightsize);

	for (int i = 0; i < leftsize;i++) {
		leftarr[i] = arr[left + i];
	}
	for (int i = 0; i < rightsize;i++) {
		rightarr[i] = arr[mid + 1 + i];
	}

	int i = 0, j = 0, key = left;

	while (i < leftsize && j < rightsize) {
		if (leftarr[i] <= rightarr[j]) {
			arr[key] = leftarr[i];
			i++;
		}
		else {
			arr[key] = rightarr[j];
			j++;
		}
		key++;
	}

	while (i < leftsize) {
		arr[key] = leftarr[i];
		i++;
		key++;
	}

	while (j < rightsize) {
		arr[key] = rightarr[j];
		j++;
		key++;
	}
}

void MergeSort(std::vector<int>& arr, int left, int right) { // Рекурсивное разбитие массива на подмассивы для дальнейшей сортировки
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		Merge(arr, left, mid, right);
	}
}

std::vector <int> MS(std::vector<int> arr) { // "Слияние" - реализован вывод в консоль и return для тестов
	MergeSort(arr, 0, arr.size() - 1);
	std::cout << std::endl;
	std::cout << "MergeSort:\n";
	for (int i = 0; i < arr.size();i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
	return arr;
}

class Shapes {
public:
	virtual std::string getType() const = 0;			// Тип фигуры
	virtual std::string getParameters() const = 0;		// Изначальные стороны
	virtual double area() const = 0;					// Функция определения площади (через константу, не помню почему, но так научили)
};

class Circle : public Shapes {					// Круг
private:
	int radius;
public:

	std::string getType() const override {
		return "Круг ";
	}
	std::string getParameters() const override {
		return "Радиус: " + std::to_string(radius);
	}
	Circle(int r) : radius(r) {}
	double area() const override {
		return M_PI * radius * radius;
	}
};

class Triangle : public Shapes {		// Треугольник
private:
	bool two = false;					// Если даётся на вход две величины - считаем, что это высота и основание к ней, в противном случае, что это три стороны
	int a = 0, b = 0, c = 0;			// Три стороны
	int base = 0, h = 0;				// Высота и основание

public:

	std::string getType() const override {
		return "Треугольник ";
	}
	Triangle(int a, int b, int c) : a(a), b(b), c(c), two(false) {}
	Triangle(int base, int height) : base(base), h(height), two(true) {}
	double area() const override {
		if (two) return 0.5 * base * h; // Через высоту и основание
		else {
			double s = (a + b + c) / 2; // Полупериметр
			return std::sqrt(s * (s - a) * (s - b) * (s - c)); // Формула Герона
		}
	}
	std::string getParameters() const override {
		if (two) {
			return "Основание: " + std::to_string(base) + ", Высота: " + std::to_string(h);
		}
		else {
			return "Стороны: " + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c);
		}
	}
};

class Rectangle : public Shapes {		// Прямоугольник
private:
	int width, height;
public:
	std::string getType() const override {
		return "Прямоугольник ";
	}
	std::string getParameters() const override {
		return "Ширина: " + std::to_string(width) + ", Высота: " + std::to_string(height);
	}
	Rectangle(int w, int h) : width(w), height(h) {}
	double area() const override {
		return width * height;
	}
};

bool sortArea(const Shapes* a, const Shapes* b) {	// Сортировка массива с фигурами (подсмотрел)
	return a->area() < b->area();
}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "Задача 1\n"; 
	int Quantity = 0;			// Переменная для выбора количества тестов
	std::string input;			// Строка для ввода значений
	bool flag = true;			// Флаг для выхода из цикла
	int value = 0, arrsize = 0; // value - Переменная для записи числа в массив, arrsize - длина массива
	srand(time(NULL));			// Сид для случайности

	do {						// Пользователь вводит значение: если число входит в int - меняется флаг и выходит из цикла, иначе возвращается на ввод с ошибкой
		std::cout << "Введите количество желаемых тестов\n";	// Ручками попробовал различные значения, ничего, кроме числовых не вводится, но при больших значениях придётся подождать
		std::cin >> input;
		try {
			Quantity = std::stoi(input);
			if (Quantity > 0) flag = false;
			else std::cout << "Введите не нулевое и не отрицательное значение\n";
		}
		catch (std::invalid_argument const& e) {
			std::cout << "Некорректное число" << std::endl;
		}
		catch (std::out_of_range const& e) {
			std::cout << "Некорректное число" << std::endl;
		}
	} while (flag);
	
	while (Quantity > 0) {
		value = 0;
		std::vector <int> mass;
		arrsize = rand() % 15 + 5;		// Длина массива (в диапазоне от 5 до 20)
		for (int i = 0; i < arrsize; i++) {
			value = rand() % 10000 + 1;
			mass.push_back(value);
		}

		std::cout << "Исходный массив:\n";
		for (int i = 0; i < arrsize; i++)
		{
			std::cout << mass[i] << " ";
		}
		std::cout << std::endl;

		std::thread th1(BubbleSort, mass);	// Определяю потоки для дальнейшей работы 
		std::thread th2(SmallestSort, mass);
		std::thread th3(InsertionSort, mass);
		std::thread th4(MS, mass);

		th1.join();							// Запускаю многопоточную сортировку
		th2.join();
		th3.join();
		th4.join();

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		Quantity--;
	}
	// ------------------------- \\
	
	std::cout << "Задача 2\n";
	flag = true;
	do {					// Пользователь вводит значение: если число входит в int - меняется флаг и выходит из цикла, иначе возвращается на ввод с ошибкой
		std::cout << "Введите количество желаемых тестов\n";
		std::cin >> input;
		try {
			Quantity = std::stoi(input);
			if (Quantity > 0) flag = false;
			else std::cout << "Введите не нулевое и не отрицательное значение\n";
		}
		catch (std::invalid_argument const& e) {
			std::cout << "Некорректное число\n";
		}
		catch (std::out_of_range const& e) {
			std::cout << "Некорректное число\n";
		}
	} while (flag);
	
	while (Quantity > 0) {
		arrsize = rand() % 2 + 2;				// Используется для случайного определения исходных данных треугольника
		int value1 = 0, value2 = 0, value3 = 0;

		std::vector<Shapes*> shapes;

		if (arrsize == 3) {						// Если даны три стороны треугольника
			flag = true;
			do {
				value1 = rand() % 30 + 1;		// Число 30 стоит как оптимальное между случайностью и длительностью перебора подходящих длин сторон
				value2 = rand() % 30 + 1;
				value3 = rand() % 30 + 1;
				if (value1 + value2 > value3 && value1 + value3 > value2 && value2 + value3 > value1) flag = false; // У треугольника длина стороны не может быть больше суммы двух других сторон
			} while (flag);
			shapes = {
			new Circle(rand() % 19 + 1),
			new Rectangle(rand() % 100 + 1, rand() % 100 + 1),
			new Triangle(value1, value2, value3)
			};
		}
		else {									// Если даны две стороны треугольника
			shapes = {
			new Circle(rand() % 19 + 1),
			new Rectangle(rand() % 100 + 1, rand() % 100 + 1),
			new Triangle(rand() % 100 + 1, rand() % 100 + 1)
			};
		}

		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Изначальные стороны фигур:\n";



		std::sort(shapes.begin(), shapes.end(), sortArea);

		for (const auto& shape : shapes) {
			std::cout << shape->getType() << "\n";
			std::cout << "  Параметры: " << shape->getParameters() << "\n";
			std::cout << "  Площадь: " << shape->area() << "\n\n";
		}
		Quantity--;
	}

	system("pause");
	return 0;
}

