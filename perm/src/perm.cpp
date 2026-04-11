/**
 * @file    perm.hpp
 * @version version 0.0.1
 * @date    Sun, 05 Apr 2026 14:35:04 +0000
 * @info    ...
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <algorithm>
#include <iterator>
#include <random>
#include <vector>
#include <sstream>
#include <iomanip>
#include <getopt.h>
#include "perm.hpp"
#include "bash_color.hpp"

using std::cerr;
using std::cout;
using std::endl;
using std::string;

using std::vector;

const string VERSION_STRING = "0.0.1";
const int DEFAULT_ARGC = 0;
const unsigned short VERBOSE = 0x01;
const unsigned short DEFAULTS = 0x00;
const unsigned short FIELDS = 0x02;
unsigned short options = DEFAULTS;
char DELIMITER = ',';

static struct option long_options[] =
	{
		{"verbose", no_argument, 0, 'v'},
		{"help", no_argument, 0, 'h'},
		{"version", no_argument, 0, 'r'},
};

unsigned short OPTION_FLAGS = DEFAULTS;

void print_version()
{
	cout << VERSION_STRING << endl;
}

void print_help()
{
	cout << endl
		 << FMT_BOLD << FMT_FG_GREEN << "Usage: " << FMT_RESET << endl
		 << FMT_BOLD << " $APP_NAME " << FMT_RESET << " "
		 << FMT_FG_BLUE << "[-hvr][...]" << FMT_RESET << " "
		 << endl
		 << endl;
}

void print(const auto &a)
{
	for (const auto e : a)
		std::cout << e << ' ';
	std::cout << '\n';
}

enum Suit
{
	Hearts = 1,
	Diamonds = 2,
	Clubs = 3,
	Spades = 4
};

enum Rank
{
	Ace = 1,
	Two = 2,
	Three = 3,
	Four = 4,
	Five = 5,
	Six = 6,
	Seven = 7,
	Eight = 8,
	Nine = 9,
	Ten = 10,
	Jack = 11,
	Queen = 12,
	King = 13
};

std::vector<int> deck{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
					  14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25,
					  26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37,
					  38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
					  50, 51, 52};

string get_card(int card)
{
	std::stringstream ss;
	int rank = (card % 13) + 1;
	int suit = (card % 4) + 1;

	string suit_str;
	switch (suit)
	{
	case Hearts:
		suit_str = "Hearts";
		break;
	case Diamonds:
		suit_str = "Diamonds";
		break;
	case Clubs:
		suit_str = "Clubs";
		break;
	case Spades:
		suit_str = "Spades";
		break;
	default:
		suit_str = "Unknown Suit";
		break;
	}
	string rank_str;
	switch (rank)
	{
	case Ace:
		rank_str = "Ace";
		break;
	case Jack:
		rank_str = "Jack";
		break;
	case Queen:
		rank_str = "Queen";
		break;
	case King:
		rank_str = "King";
		break;
	default:
		rank_str = std::to_string(rank);
		break;
	}
	ss << "[ " << std::left << std::setw(5) << rank_str << " of " << std::left << std::setw(9) << suit_str << " ]";
	return ss.str();
}

int parse_options(int argc, char *argv[])
{
	int opt = 0;
	int option_index = 0;
	optind = 0;
	while ((opt = getopt_long(argc, argv, "hv ", long_options, &option_index)) != -1)
	{
		switch (opt)
		{
		case 'h':
			print_help();
		case 'v':
			print_version();
			return 0;
		}
	}
	if (argc < DEFAULT_ARGC) // not correct number of args
	{
		cerr << "Expected argument after options, -h for help" << endl;
		return -1;
	}

	cout << "Permutation example:" << endl;
	string path = argv[0]; // get exe file path
	cout << argv[0] << endl;
	std::string s = "abcdef";

	do
	{
		std::cout << s << '\n';
	} while (std::next_permutation(s.begin(), s.end()));

	std::cout << s << '\n';

	cout << "-----------------------------" << endl;
	cout << "Random shuffle example:" << endl;
	std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::random_device rd;
	std::mt19937 g(rd());

	for (size_t i = 0; i < 52; i++)
	{
		std::shuffle(v.begin(), v.end(), g);
		std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
		std::cout << '\n';
	}

	cout << "-----------------------------" << endl;
	cout << "Deck shuffle example:" << endl;
	int n = 52;
	int suit = 4;

	std::random_device rd2;
	std::mt19937 g2(rd());
	std::shuffle(deck.begin(), deck.end(), g);
	std::cout << '\n';

	for (int i = 0; i < n; i++)
	{
		int card = deck[i];
		int rank = (card - 1) % 13 + 1;
		int suit = (card - 1) / 13 + 1;

		string rank_str;
		switch (rank)
		{
		case Ace:
			rank_str = "Ace";
			break;
		case Jack:
			rank_str = "Jack";
			break;
		case Queen:
			rank_str = "Queen";
			break;
		case King:
			rank_str = "King";
			break;
		default:
			rank_str = std::to_string(rank);
			break;
		}

		string suit_str;
		switch (suit)
		{
		case Hearts:
			suit_str = "Hearts";
			break;
		case Diamonds:
			suit_str = "Diamonds";
			break;
		case Clubs:
			suit_str = "Clubs";
			break;
		case Spades:
			suit_str = "Spades";
			break;
		default:
			suit_str = "Unknown Suit";
			break;
		}

		cout << rank_str << " of " << suit_str << endl;
		// now do random five card draw, then loop till you get a royal flush, then print the number of draws it took to get a royal flush
	}
	print(deck);

	std::default_random_engine *generator = new std::default_random_engine;
	std::uniform_int_distribution<int> deal(0, 51);
	vector<vector<int>> hands;
	vector<int> hand;

	for (int i = 0; i < 10000; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			int number = deal(*generator);
			hand.push_back(number);
		}
		hands.push_back(hand);
		hand.clear();
	}

	int len1 = hands.size();
	for (int i = 0; i < hands.size(); ++i)
	{
		for (size_t j = 0; j < 5; j++)
		{
			int card = hands[i][j];
			// cout << std::right << std::setw(2) << card << ":" << std::left << std::setw(9) << get_card(card % 4) << " ";
			cout << get_card(card) << " ";
		}
		cout << endl;
	}
	return 0;
}
