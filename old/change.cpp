#include <iostream>

using namespace std;

int main() {
	int coins, quarters, dimes, nickels, pennies, totalCoins;

	cout << "Enter the total number of cents: ";
	cin >> coins;
	cout << coins;

	quarters = coins / 25;
	coins %= 25;

	dimes = coins / 10;
	coins %= 10;

	nickels = coins / 5;
	coins %= 5;

	pennies = coins;

	totalCoins = pennies + nickels + dimes + quarters;

	cout << " cents can be made using";
	if (quarters != 0) {
		cout << " " << quarters << " quarter";
		if (quarters != 1)
			cout << "s";
	}

	if (dimes != 0) {
		cout << " " << dimes << " dime";
		if (dimes != 1)
			cout << "s";
	}

	if (nickels != 0) {
		cout << " " << nickels << " nickel";
		if (nickels != 1)
			cout << "s";
	}

	if (pennies != 0) {
		cout << " " << pennies << " penn";
		if (pennies != 1)
			cout << "ies";
		else
			cout << "y";
	}

	cout << " for " << totalCoins << " coins total." << endl;
}
