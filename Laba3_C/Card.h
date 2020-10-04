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
	    int size;
		Card* cards;
	public:
		DeckCard();
		DeckCard(int n);
		DeckCard(int a,int n);
		DeckCard(int r, int s,int n);
		DeckCard(const DeckCard& a);
		DeckCard& operator =(const DeckCard& copy);
		~DeckCard();
		int FindPlace(int r, int s)const;
		int FindElement(int r, int s)const;
		void Sort();
		int getSize()const;
		void quickSort_Rang(Card* a, int first, int last);
		void quickSort_Suit(Card* a, long N);
		DeckCard& operator ++();
		std::string Rang(int)const;
		std::string Suit(int)const;
		std::string operator[](int)const;
		std::string operator()(int)const;
        friend std::ostream& operator <<(std::ostream& c, const DeckCard& r);
		friend std::istream& operator >>(std::istream& s, DeckCard& r);
	};
std::string dialog();
DeckCard F_Add(DeckCard& r);
DeckCard F_Random_DeckCard(DeckCard& r);
DeckCard F_Suit(DeckCard& r);
DeckCard F_Rang(DeckCard& r);
DeckCard F_EnterNew(DeckCard& r);
DeckCard F_Print(DeckCard& r);
}