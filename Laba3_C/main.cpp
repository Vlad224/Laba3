#include"Card.h"
using namespace Prog3;
int main() {
	srand(time(0));
	int b = 10;
	DeckCard(*dp[7])(DeckCard & r) = { nullptr, Prog3::F_Add, Prog3::F_Print,Prog3::F_Suit, Prog3::F_Rang,Prog3::F_Random_DeckCard,Prog3::F_EnterNew };
	DeckCard a(b,10);
	a.Sort();
	int fl1 = 1;
	int c;
	std::cout << a;
	while (fl1) {
		std::cout<< Prog3::dialog();
		std::cin >> c;
		if (!std::cin.good() || c < 0 || c > 6) {

			std::cin.clear();

			std::cin.ignore(INT_MAX, '\n');

			std::cout << "Incorrect input!" << std::endl;
		}
		else
			if (c == 0)
				fl1 = 0;
			else
				dp[c](a);
	}
}