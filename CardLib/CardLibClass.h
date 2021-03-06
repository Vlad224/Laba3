#include<iostream>
#include<sstream>
#include<cstdlib>
#include<ctime>
namespace Prog3 {
	struct Card {
		int rang;//����
		int suit;//����� 0-���� 1-������ 2-����� 3-�����
	};
	class DeckCard {
	private:
		int size;
		int size_real;
		Card* cards;
	public:
		DeckCard();
		DeckCard(int n);
		DeckCard(int a, int n);
		DeckCard(int r, int s, int n);
		DeckCard(const DeckCard& a);
		DeckCard(DeckCard&& a);
		DeckCard& operator = (DeckCard&& a);
		DeckCard& operator =(const DeckCard& copy);
		~DeckCard();
		int FindPlace(int r, int s)const;
		int FindElement(int r, int s)const;
		void Sort();
		int getMemorySize()const;
		int getSize()const;
		int getRang(int i)const;
		int getSuit(int i)const;
		void quickSort_Rang(Card* a, int first, int last);
		DeckCard& operator ++();
		std::string Rang(int)const;
		std::string Suit(int)const;
		std::string operator[](int)const;
		std::string operator()(int)const;
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