// Monkey Business
// John Smithhisler

/*************************************************/
/* A local zoo wants to keep track of how many   */
/* pounds of food each of its three monkeys eats */
/* each day during a typical week.  Program      */
/* should display average, least amount, and     */
/* greatest amount.                              */
/*************************************************/


#include <iostream>
#include <iomanip>
using namespace std;

// Constants
const int NUM_MONKEYS = 3;
const int NUM_DAYS = 5;

int main()
{
	// Monkey array
	int monkey[NUM_MONKEYS][NUM_DAYS];
	int total = 0;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			// Get food amounts
			cout << "How many pounds of food did monkey " << row + 1 << " eat on day " << col + 1 << "? ";
			cin >> monkey[row][col];
			if (monkey[row][col] <= 0)
			{
				// Validation for entered data
				cout << "The monkeys need to eat! Enter a number larger than 0 for day " << (col + 1) << ": ";
				cin >> monkey[row][col];
			}
			total += monkey[row][col];
		}
	}

	// Starting points for finding lowest and highest
	int least = monkey[0][0];
	int greatest = monkey[0][0];
	int count1 = 0;
	int count2 = 0;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 5; col++)
		{
			// Get lowest amount
			if (monkey[row][col] < least)
			{
				least = monkey[row][col];
				count1 = row;
			}
			// Get highest amount
			if (monkey[row][col] > greatest)
			{
				greatest = monkey[row][col];
				count2 = row;
			}
		}
	}

	// Display information
	cout << setprecision(2) << fixed << endl;
	cout << "The average amount of food eaten per day by the whole family of monkeys was " << total / 15 << " pounds." << endl;
	cout << "The least amount of food eaten during the week by any one monkey was " << least << " pound(s) by monkey " << count1 + 1 << "." << endl;
	cout << "The greatest amount of food eaten during the week by any one monkey was " << greatest << " pounds by monkey " << count2 + 1 << "." << endl;

	system("pause");
	return 0;
}