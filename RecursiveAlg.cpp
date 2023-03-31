/*
* Проект "Король под угрозой".
* Имеется шахматная доска размером 8х8,
* на которой расположен король и
* еще одна фигура (слон, ладья, и пр.)
* Реализовать функции, проверяющие, находится ли
* король под угрозой фигуры.
* Для каждой из фигур создать отдельную
* функцию проверки.
*/

#include <iostream>
using namespace std;

const short N = 8;
// Условные обозначения фигур на поле
const char K = 'K'; // Король (King)
const char B = 'B'; // Слон (Bishop)
const char H = 'H'; // Конь (Horse) :-)
const char R = 'R'; // Ладья (Rock)
const char Q = 'Q'; // Ферзь (Queen)
const char P = 'P'; // Пешка (Pawn)


// Вывод доски на консоль
void show_board(char b[N][N])
{
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (b[i][j] == 0) cout << '.' << ' ';
			else cout << b[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}



// Функция поиска запрошенной фигуры на доске
void find_fig(char b[N][N], char fig, short& r, short& c)
{
	short i, j;
	// ищем фигуру <fig> на поле
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (b[i][j] == fig) {
				r = i;
				c = j;
				break;
			}
}
	

// Определение нахождения короля под ударом ладьи
bool check_rock_is_killer(char b[N][N])
{
	// Ищем ладью и короля
	short rR, cR; // координаты ладьи
	short rK, cK; // координаты короля
	find_fig(b, R, rR, cR);
	find_fig(b, K, rK, cK);
	// Сама проверка угрозы
	if ((rR == rK) || (cR == cK)) return true;
	return false;
}


// Функция проверки нахождения короля под ударом
bool check_bishop_is_killer(char b[N][N])
{
	// Ищем слона и короля
	short rB, cB; // координаты слона
	short rK, cK; // координаты короля
	find_fig(b, B, rB, cB);
	find_fig(b, K, rK, cK);
	// Сама проверка угрозы
	if (((rB + cB) == (rK + cK)) || ((rB - cB) == (rK - cK)))
		return true;
	return false;
}



int main()
{
	char board[N][N] = { {}, {}, {}, {}, {}, {}, {}, {} };
	board[0][7] = B;
	board[5][2] = K;
	show_board(board);
	if (check_bishop_is_killer(board))
		cout << "King is under attack!!!" << endl;
	else
		cout << "King is safe and happy!" << endl;

}
