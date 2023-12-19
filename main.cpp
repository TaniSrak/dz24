#include <iostream>
#include <cstdlib>
#include <ctime>

//разбрасываем массив
template <typename T>
void fill_arr(T arr[], const int length, int left, int rigth)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % (rigth - left) + left;
	}
}
//выводим массив
template <typename T>
void print_arr(T arr[], const int length)
{
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}
// task2
template <typename T>
void resize_arr(T*& arr, int& starlength, int newlength)
{
	T* newarr = new T[newlength]{};

	for(int i = 0; i < newlength; i++)
	{
		if (i < starlength)
		{
			newarr[i] = arr[i];
		}
		else
		{
			newarr[i] = arr[starlength - 1];
		}
	}
	delete[] arr;
	arr = newarr;
	starlength = newlength;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m, f;
	//Task1
	std::cout << "Введите длины массивов -> ";
	std::cin >> n >> m;
	int* A = new int[n];
	int* B = new int[m];

	fill_arr(A, n, 10, 20);
	fill_arr(B, m, 20, 30);

	std::cout << "A: ";
	print_arr(A, n);
	std::cout << "B: ";
	print_arr(B, m);

	int* C = new int[n + m];

	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = 0; i < m; i++)
		C[n + i] = B[i];

	std::cout << "C: ";
	print_arr(C, n + m);
	delete[] A;
	delete[] B;

	//Task2
	std::cout << "Введите размер массива -> ";
	int size1;
	std::cin >> size1;

	int* arr1 = new int[size1];
	int stararr1 = size1;

	fill_arr(arr1, size1, 20, 31);

	std::cout << "Массив до: ";
	print_arr(arr1, size1);

	std::cout << "Введите новый размер массива -> ";
	int newsize2;
	std::cin >> newsize2;

	resize_arr(arr1, size1, newsize2 );
	std::cout << "Итоговый массив: ";
	print_arr(arr1, size1); 

	delete[] arr1;

	return 0;
}