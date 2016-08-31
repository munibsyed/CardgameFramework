#include "Dealer.h"




Dealer::Dealer()
{
	m_valueChar[Card::valuesArray[0]] = "2";
	m_valueChar[Card::valuesArray[1]] = "3";
	m_valueChar[Card::valuesArray[2]] = "4";
	m_valueChar[Card::valuesArray[3]] = "5";
	m_valueChar[Card::valuesArray[4]] = "6";
	m_valueChar[Card::valuesArray[5]] = "7";
	m_valueChar[Card::valuesArray[6]] = "8";
	m_valueChar[Card::valuesArray[7]] = "9";
	m_valueChar[Card::valuesArray[8]] =	"10";
	m_valueChar[Card::valuesArray[9]] = "J";
	m_valueChar[Card::valuesArray[10]] = "Q";
	m_valueChar[Card::valuesArray[11]] = "K";
	m_valueChar[Card::valuesArray[12]] = "A";

	

}

Dealer::~Dealer()
{
}