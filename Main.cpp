#include <iostream>
#include <random>
#include <time.h>
using namespace std;

namespace mynamespace {
	template <typename T>
	void Start(long Cols, long Rows, T arr[]) {
		long RTemp = LONG_MAX;
		int index = 0;

		double** TempArr = new double*[Rows*Cols];
		for (int i = 0; i < Rows*Cols; i++) {
			TempArr[i] = new double[Rows*Cols];
		}
		for (int i = 0; i < Rows*Cols; i++) {
			for (int j = 0; j < Rows*Cols; j++) {
				TempArr[i][j] = LONG_MAX;
			}
		}

		for (int ii = 0; ii < Cols; ii++) {
			for (int i = 0; i < Rows; i++)
				for (int j = 0; j < Cols; j++)
					if (arr[i][index] < TempArr[index][index])
						TempArr[index][index] = arr[i][index]; index++;
		}

		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				cout << arr[i][j] << "\t";
				if (arr[i][j] < RTemp) {
					RTemp = arr[i][j];
				}

				if ((j + 1) % Cols == 0) { // Кiнець рядка
					cout << " Найменше значення в рядку: " << RTemp << "\n";
					RTemp = LONG_MAX;
				}
			}
		}
		cout << "\n";
		for (int i = 0; i < index; i++)
			cout << TempArr[i][i] << "\t";
		cout << "\n\n";
		delete[] TempArr;

	}
	void function() {
		srand(time(NULL));
		long int Rows; 	cout << "Розмiр стовпця: "; cin >> Rows;
		long int Cols; 	cout << "Розмiр рядка: ";	cin >> Cols;

		unsigned char** C_Arr = new unsigned char* [Rows];

		for (int i = 0; i < Rows; i++)
			C_Arr[i] = new unsigned char[Cols];

		for (int i = 0; i < Rows; i++)
			for (int j = 0; j < Cols; j++)
				C_Arr[i][j] = (rand() % 100 + rand() % 100) / 5 + 100;

		Start(Cols, Rows, C_Arr);
		delete[] C_Arr;
		cout << "Розмiр стовпця: "; cin >> Rows;
		cout << "Розмiр рядка: ";	cin >> Cols;

		double** D_Arr = new double* [Rows];

		for (int i = 0; i < Rows; i++)
			D_Arr[i] = new double[Cols];

		for (int i = 0; i < Rows; i++)
			for (int j = 0; j < Cols; j++)
				D_Arr[i][j] = (rand() % 100 + rand() % 100) / 5;

		Start(Cols, Rows, D_Arr);
		delete[] D_Arr;
	}
}

int main() {
	system("chcp 1251>nul"); // Windows
	mynamespace::function();

	return 0;
}

/*
Написати шаблон для пошуку найменшого значення в стовпцях і рядках
двомірної матриці. Матриця може бути типу int, float, char. Виконати
наглядний вивід на екран.
*/
