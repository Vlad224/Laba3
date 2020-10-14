#include<iostream>
#include<sstream>
#include<cstdlib>
#include<ctime>
namespace Prog3 {
	struct Card {
		int rang;//ранг
		int suit;//масть 0-пика 1-крести 2-бубна 3-черви
	};
	class DeckCard {
	private:
		static const int size = 52;
		Card cards[size];
	public:
		DeckCard();
		DeckCard(int a);
		DeckCard(int r, int s);
		int FindPlace(int r, int s)const;
		int FindElement(int r, int s)const;
		void Sort();
		int getSize()const;
		void quickSort_Rang(Card* a, int first, int last);
		void quickSort_Suit(Card* a, long N);
		DeckCard& add();
		std::string Rang(int)const;//красивый вывод  ранга
		std::string Suit(int)const;//красивый вывод  масти
		std::string rangget(int)const;//Чекаем инт выходит за пределы или нет(Rang работает через него)
		std::string suitget(int)const;//Чекаем инт выходит за пределы или нет(Suit работает через него)
		int GetRang(int a)const;
		int GetSuit(int a)const;
        friend std::ostream& operator <<(std::ostream& c, const DeckCard& r);
		friend std::istream& operator >>(std::istream& s, DeckCard& r);
	};
std::string dialog();
void F_Add(DeckCard& r);
void F_Random_DeckCard(DeckCard& r);
void F_Suit(DeckCard& r);
void F_Rang(DeckCard& r);
void F_EnterNew(DeckCard& r);
void F_Print(DeckCard& r);
}