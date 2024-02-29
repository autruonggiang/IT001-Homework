#include <iostream>
using namespace std;

#define MAX 100


void NhapN (int &N)
{
	do
	{
	cout << "Nhap so phan tu cua mang N: ";
	cin >> N;

	if (N <= 0 || N > MAX)
		cout << "Nhap sai. Vui long nhap la 0 < N <= " << MAX << "\n";

	} while (N <= 0 || N > MAX);
}

void NhapMang (float A[], int N)
{
	for (int i = 0; i < N; i++)
	{
	cout << "A[" << i + 1 << "]= ";
	cin >> A[i];
	}
}

void XuatMang (float A[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << A[i] << "\t";
	}
}

void LietKeBoBa (float A[], int N)
{
	for (int x = 0; x < N - 2; x++)
	{
		for (int y = x + 1; y < N - 1; y++)
		{
			for (int z = y + 1; z < N; z++)
			{
			if (A[x] == A[y] + A[z])
    		cout << "(" << A[x] << "," << A[y] << "," << A[z] << ")\n";
			}
		}

	}
}

int main()
{

	int N = 0;
	NhapN (N);

	float A[MAX];
	NhapMang (A, N);
	cout << "MANG BAN DAU\n";
	XuatMang (A, N);
	cout << "\n";

	cout << "Bo ba gia tri thu duoc: \n";
	LietKeBoBa (A, N);
	cout << "\n";
 
 return 0;
}
