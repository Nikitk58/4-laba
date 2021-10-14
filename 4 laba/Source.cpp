#define _CRT_SECURE_NO_WARNINGS
#include <ctime> // ���������� �������
#include <cmath>
#include <locale.h>
#include <iostream> // ���������� �����,������
#include <conio.h>
int matrix[20][20]; // �������
bool* visited = new bool[100];
using namespace std;
/*int matrix[6][6] = {
{0,1,1,0,0,1},
{1,0,0,1,0,0},
{1,0,0,0,1,0},
{0,1,0,0,0,0},
{0,0,1,0,0,0},
{1,0,0,0,0,0}
};
*/

void DFS(int st)
{
	int r, n = 5;
	cout << st + 1 << " ";
	visited[st] = true;
	for (r = 0; r <= n; r++)
		if ((matrix[st][r] != 0) && (!visited[r]))
			DFS(r);
}

void main()
{
	setlocale(LC_ALL, "Russian"); // ����������� ��������
	srand(time(NULL)); // ����� ������ �������



	int i, j, m, n;
	int start;
	cout << "m="; // ������� ������
	cin >> m; // �������� ������
	cout << "n=";
	cin >> n;
	cout << "�������: \n";
	int z;

	for (int i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			matrix[i][j] = rand() % 2;



	for (int i = 0; i < 10; i++)
		matrix[i][i] = 0;

	for (int i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			matrix[i][j] = matrix[j][i];


	for (i = 0; i < n; i++)
	{
		visited[i] = false;
		for (j = 0; j < m; j++)
			cout << matrix[i][j] << " "; // ������� �������
		cout << endl;
	}



	for (int i = 0; i < 6; i++)
	{
		cout << "\n";
		cout << "{";
		for (j = 0; j < 6; j++)

			if (matrix[i][j] == 1)
			{
				cout << j <<" ";
				visited[i] = false;
			}
		cout << "}" << " �������  " << i;
	}
	cout << "\n";

	cout << "��������� ������� � "; cin >> start;
	bool* vis = new bool[n];
	cout << "������� ������: ";
	DFS(start - 1);
	delete[]visited;
	
}