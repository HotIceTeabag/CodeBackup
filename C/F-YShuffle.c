/*	**Algorithm Discribtion**
Fisher-Yates Shuffling Algorithm:
	�Ϲ������� ���� �迭��, �� �迭 �ϳ��� �� �̿���
	�� �迭�� ���� ����� �����ϴ� �� �迭�� ���� ����� ����.
	������, �� ���� �迭�� ����ϴ� ����� �ִ�.
	i���� ī�� �� �迭�� ������ �����Ͽ� i���� 1�� �� ������ �ݺ��Ѵ�.
	0���� i������ ���� ���� ranNum�� random�Լ��� �̿��� i������ ���� �����Ѵ�.
	���� i�� �������� ���� i��° �ε����� �ִ� ���� �� ���������� ���� �� �ϳ���
	��ü�Ǿ� ��������� ��� ���Ұ� ���̰Եȴ�.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FACES 13
#define CARDS 52

typedef struct card {
	const char* face;
	const char* suit;
} Card;

//Prototype

void fillDeck(Card* const deck, const char* faces[], const char* suits[]);
void shuffle(Card* const deck);
void deal(const Card * const deck);
void shuffle_old(Card* const deck);

int main(void) {
	srand(time(NULL));
	Card deck[CARDS];

	const char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	const char* faces[] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", 
	"Eight", "Nine", "Ten", "Jack", "Queen", "King" };

	fillDeck(deck, faces, suits);
	shuffle(deck);
	deal(deck);
}

void fillDeck(Card* const deck, const char* faces[], const char* suits[]) {
	for (size_t i = 0; i < CARDS; ++i) {
		deck[i].face = faces[i % FACES];
		deck[i].suit = suits[i / FACES];
	}
}

void deal(const Card* const deck) {
	
	for (size_t i = 0; i < CARDS; ++i) {
		printf("%5s of %-8s %s", deck[i].face, deck[i].suit, (i + 1) % 4 ? "   " : "\n");
	}
}

void shuffle(Card* const deck) {
	int ranNum;
	
	for (int i = CARDS-1; i > 0; i--) {
		ranNum = rand() % (i + 1);

		Card temp = deck[i];
		deck[i] = deck[ranNum];
		deck[ranNum] = temp;
	}
}

void shuffle_old(Card* const deck) {
	for (size_t i = 0; i < CARDS; ++i) {
		size_t j = rand() % CARDS;
		Card temp = deck[i];
		deck[i] = deck[j];
		deck[j] = temp;
	}
}