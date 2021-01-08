#include <iostream> 
#include <limits>
#include <cmath>

using namespace std;

int main()
{
	// Перевірка даних від користувача
	bool input;
	float a; 
	do
	{
		input = true;
		cout << "Usage: enter the number a." << endl << "a = "; cin >> a;
		if (!cin)
		{
			input = false;
			cout << "Error: unaccaptable value of a.\n\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} while (!input);

	// Пошук найближчого простого числа
	//################################################################################

	if (a < 2 || (a > 2 && a < 2.5) || a == 3) cout << "\nThe closest prime number is 2.\n\n";
	else
	{

		// округлене а є простим 
		bool z = true;
		int i = 2;
		if (round(a) == a) z = false;	// a - ціле число

		while (z && i <= sqrt(a))
		{
			if (int(round(a)) % i == 0) z = false;	// округлене а не є простим 
			i++;
		}

		// пошук простого числа, коли а - ціле або округлене а не є простим 
		if (!z)
		{
			int after_a, before_a;
			after_a = int(round(a)); before_a = after_a;
			bool p, q;
			do
			{
				after_a++;
				i = 2;
				p = true;
				do
				{
					if (after_a % i == 0) p = false;
					i++;
				} while (p && i <= sqrt(after_a));
				before_a--;
				i = 2;
				q = true;
				do
				{
					if (before_a % i == 0) q = false;
					i++;
				} while (q and i <= sqrt(before_a));

				if (after_a <= 1) p = false;
				if (before_a <= 1) q = false;
			} while (!p && !q);

			// Виведення результату при z = 0
			if (p && q)
			{
				if (a == round(a)) printf("\nThe closest prime number is %i and %i.\n\n", before_a, after_a);
				else
				{
					if (a > round(a)) printf("\nThe closest prime number is %i.\n\n", after_a);
					else printf("\nThe closest prime number is %i.\n\n", before_a);
				}
			}
			else
			{
				if (p) printf("\nThe closest prime number is %i.\n\n", after_a);
				else printf("\nThe closest prime number is %i.\n\n", before_a);
			}
		}

		// Виведення результату при z = 1
		if (z) cout << "\nThe closest prime number is " << int(round(a)) << ".\n\n";
	}

	system("pause");
}
