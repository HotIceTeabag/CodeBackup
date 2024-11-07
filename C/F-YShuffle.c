/*	**Algorithm Discribtion**
Fisher-Yates Shuffling Algorithm:
	일반적으로 원본 배열과, 빈 배열 하나를 더 이용해
	빈 배열에 섞인 결과를 저장하는 두 배열을 쓰는 방식이 많다.
	하지만, 한 가지 배열을 사용하는 방법도 있다.
	i값을 카드 덱 배열의 끝부터 시작하여 i값이 1이 될 때까지 반복한다.
	0에서 i까지의 값을 갖는 ranNum을 random함수를 이용해 i까지의 값을 생성한다.
	따라서 i가 내려감에 따라 i번째 인덱스에 있는 값은 그 이전까지의 값들 중 하나와
	교체되어 결과적으로 모든 원소가 섞이게된다.
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