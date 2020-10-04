#include"Card.h"
namespace Prog3 {
    DeckCard::~DeckCard() {

        delete[] cards;

    }
    DeckCard::DeckCard(const DeckCard& copy): size(copy.size), cards(nullptr) {

        if (size) {

            cards = new Card[size];

            for (int i = 0; i < size; i++) {
                    cards[i] = copy.cards[i];

            }

        }

    }
    DeckCard& DeckCard::operator =(const DeckCard& copy) {
        int f = 0;
        if (size == copy.size) {
            for (int i = 0; i < size; i++) {
                if (cards[i].rang != copy.cards[i].rang || cards[i].suit != copy.cards[i].suit) {
                    f = 1;
                    break;
                }
                if (f)
                    break;
            }
        }
        else
            f = 1;
        if (f) {
                delete[] cards;
                size = copy.size;
                cards = new Card[size];
                for (int i = 0; i < size; i++) {
                    cards[i] = copy.cards[i];

                }
        }
        return *this;
    }
    DeckCard::DeckCard(){
        size = 10;
        cards = new Card[size];
        for (int i = 0; i < size; i++) {
            cards[i].rang = -1;
            cards[i].suit = -1;
        }
    }
	DeckCard::DeckCard(int r,int s,int n) {
        if (n > 0 && n < 52) {
            if (r > -1 && r<15 && s>-1 && s < 4) {
                size = n;
                cards = new Card[size];
                cards[0].rang = r;
                cards[0].suit = s;
                for (int i = 1; i < size; i++) {
                    cards[i].rang = -1;
                    cards[i].suit = -1;
                }
            }
            else
                throw std::exception("invalid suit or rang");
        }
        else
            throw std::exception("invalid size");
	}
    int DeckCard::FindPlace(int r, int s)const {
        int i = 0;
        while (i != size && cards[i].rang != -1 && (cards[i].rang != r || cards[i].suit != s) )
            i++;
        if (cards[i].rang == -1)
            return i;
        else
            return -1;

    }
    int DeckCard::FindElement(int r, int s)const {
        int i = 0;
        while (i != size && -1 != cards[i].rang && (cards[i].rang != r || cards[i].suit != s))
            i++;
        return i;
    }
    DeckCard::DeckCard(int a, int n) {
        if (n > 0 && n < 52 && a<=n) {
            size = n;
            cards = new Card[size];
            int r = -1;
            int s = -1;
            int n = -1;
            for (int i = 0; i < size; i++) {
                cards[i].rang = -1;
                cards[i].suit = -1;
            }
           for (int i = 0; i < a; i++) {
                    r = 2 + rand() % 13;
                    s = rand() % 4;
                    n = FindPlace(r, s);
                    if (n > -1) {
                        cards[n].rang = r;
                        cards[n].suit = s;
                    }
                    else {
                        i--;
                    }
           }
        }
            else
                throw std::exception("too a large number of cards to initializations ");
     }
    void DeckCard::quickSort_Suit(Card* a, long N) {//Быстрая сортировка
        // На входе - массив a[], a[N] - его последний элемент.

        long i = 0, j = N;      // поставить указатели на исходные места
        Card temp, p;

        p = a[N >> 1];      // центральный элемент

        // процедура разделения
        do {
            while (a[i].suit > p.suit) i++;
            while (a[j].suit < p.suit) j--;

            if (i <= j) {
                temp = a[i]; a[i] = a[j]; a[j] = temp;
                i++; j--;
            }
        } while (i <= j);

        // рекурсивные вызовы, если есть, что сортировать 
        if (j > 0) quickSort_Suit(a, j);
        if (N > i) quickSort_Suit(a + i, N - i);
    }
    void DeckCard::quickSort_Rang(Card* s_arr, int first, int last) {//Быстрая сортировка
    // На входе - массив a[], a[N] - его последний элемент.
        
        int i = first, j = last;
        Card tmp;
        Card check = s_arr[(first + last) / 2];
        do {
            while (s_arr[i].rang > check.rang) i++;
            while (s_arr[j].rang < check.rang) j--;

            if (i <= j) {
                if (s_arr[i].rang < s_arr[j].rang) {
                    tmp = s_arr[i];
                    s_arr[i] = s_arr[j];
                    s_arr[j] = tmp;
                }
                i++;
                j--;
            }
        } while (i <= j);

        if (i < last)
            quickSort_Rang(s_arr, i, last);
        if (first < j)
            quickSort_Rang(s_arr, first, j);
    }
    void DeckCard::Sort() {
        quickSort_Suit(cards, size);
        //std::cout << *this;
        int n = 0;
        int n0 = 0;
        for (int i = 4; i > 0; i--) {
            while (cards[n].suit == i-1)
                n++;
            if(n-1!=n0)
                quickSort_Rang((cards), n0,n-1);
            n0 = n;
        }
    }
    DeckCard& DeckCard::operator++() {
        int flag = 1;
        Card t;
        t.rang = -1;
        Card k;
        if (cards[size - 1].rang != -1)
            throw std::exception("full deckcard");
        while (flag) {
            int i = 0;
            int r = 2 + rand() % 13;
            int s = rand() % 4;
            while (cards[i].suit > s)
                i++;
            if(cards[i].suit==s)
                while (cards[i].rang > r&&cards[i].suit==s)
                    i++;
            if ((i < size) && (cards[i].rang != r || cards[i].suit != s))
            {
                if (cards[i].rang != -1) {
                    int j = i;
                    while (cards[j].rang != -1)
                    {
                        if (t.rang != -1)
                        {
                            k = cards[j];
                            cards[j] = t;
                            t = k;
                        }
                        else {
                            t = cards[i];
                            cards[i].rang = r;
                            cards[i].suit = s;
                        }
                        j++;
                    }
                    cards[j] = t;
                }
                else {
                    cards[i].rang = r;
                    cards[i].suit = s;
                }
                flag = 0;
            }
        }
    }
    std::string DeckCard::operator[](int a)const{
        if(a<0||a>=size)
            throw std::exception("illegal index");
        return Rang(cards[a].rang);
    }
    std::string DeckCard::operator()(int a)const{
        if (a<0 || a>=size)
            throw std::exception("illegal index");
        return Suit(cards[a].suit);
    }
    std::string DeckCard::Rang(int i)const {
        std::stringstream c;
        if (i == -1)
            c << "Rang: " << "Empity" << std::endl;
        if (i< 11 && i>= 0)
            c << "Rang: " << i << std::endl;
        if (i == 11)
            c << "Rang: " << "jack" << std::endl;
        if(i == 12)
            c << "Rang: " << "queen" << std::endl;
        if (i == 13)
            c << "Rang: " << "king" << std::endl;
        if (i == 14)
            c << "Rang: " << "ace" << std::endl;
        return c.str();
    }
    std::string DeckCard::Suit(int i)const {
        std::stringstream c;
        if (i == -1)
            c << "Suit: " << "Empity" << std::endl;
        if (i == 0)
            c << "Suit: " << "spades" << std::endl;
        if (i == 1)
            c << "Suit: " << "clubs" << std::endl;
        if (i == 2)
            c << "Suit: " << "diamonds" << std::endl;
        if (i == 3)
            c << "Suit: " << "hearts" << std::endl;
        return c.str();
    }
    std::ostream& operator <<(std::ostream& c,
        const DeckCard& r)
    {
        if (r.cards[0].rang == -1)
            c << "DeckCard empty" << std::endl;
        else {
            c << "Size: " << r.size<<std::endl;
            for (int i = 0; i < r.size; i++)
            {
                c << r.Rang(r.cards[i].rang);
                c << r.Suit(r.cards[i].suit) << std::endl;
            }
        }
        return c;
    }
    std::istream& operator >>(std::istream& s, DeckCard& r){
        for (int i = 0; i < r.size; i++)
        {
            r.cards[i].rang = -1;
            r.cards[i].suit = -1;
        }
        for (int i = 0; i < r.size; i++)
        {
            std::cout << "Card " << i << std::endl;
            s >> r.cards[i].rang >> r.cards[i].suit;
            if (s.good()) {
                if (r.cards[i].rang < 0 || r.cards[i].rang > 14 || r.cards[i].suit < 0 || r.cards[i].suit > 3 || i != r.FindElement(r.cards[i].rang, r.cards[i].suit))
                {
                    s.setstate(std::ios::failbit);
                    return s;
                }
            }
        }
        r.Sort();
        return s;
    }
    int DeckCard::getSize()const {
        return size;
    }
    std::string dialog() {

        std::stringstream s;

        s << "0. Exit" << std::endl << "1. Add new card" << std::endl<< "2. Show cards" << std::endl<< "3. Take suit card please enter number" << std::endl<< "4. Take rang card please enter number" << std::endl<< "5. Random New DeckCard"<< std::endl << "6. Enter New DeckCard" << std::endl<<  "Your choice: ";
        return s.str();

    }
    DeckCard F_Add(DeckCard& a) {
        try {
            ++a;
        }
        catch (std::exception & ex) {
            std::cout << ex.what() << std::endl;
        }
        return a;
    }
    DeckCard F_Random_DeckCard(DeckCard& r) {
        int c;
        int size;
            std::cout<< "Enter number of random elements and size"<<std::endl;
            std::cin >> c>>size;
            if (!std::cin.good())
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
            }
            try {
                DeckCard a(c,size);
                a.Sort();
                r = a;
            }
            catch (std::exception & ex) {
                std::cout << ex.what() << std::endl;
            } 
        return r;
    }
    DeckCard F_Suit(DeckCard& r) {
        int c;
        std::cout << "Enter number for get Suit"<<std::endl;
        std::cin >> c;
        if (!std::cin.good())
        {
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                c = r.getSize();
        }
        try {
            std::cout << r(c) << std::endl;
        }
        catch (std::exception & ex) {
            std::cout << ex.what() << std::endl;
        }
        return r;
    }
    DeckCard F_Rang(DeckCard& r) {
        int c;
        std::cout << "Enter number for get Rang"<< std::endl;
        std::cin >> c;
        if (!std::cin.good())
        {
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            c = r.getSize();
        }
        try {
            std::cout << r[c] << std::endl;
        }
        catch (std::exception & ex) {
            std::cout << ex.what() << std::endl;
        }
        return r;
    }
    DeckCard F_EnterNew(DeckCard& r) {
        DeckCard a;
        std::cin >> a;
        if (!std::cin.good())
        {
            std::cout << "You wrong";
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
        }
        else {
            r = a;
        }
        return r;
    }
    DeckCard F_Print(DeckCard& r) {
        std::cout << r;
        return r;
    }
}