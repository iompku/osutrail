#pragma once

#include <string>

using namespace std;

class Inventory
{
public:
  Inventory();
  ~Inventory();

  void buyComputerPart();
  void buyFood();
  void buyCoffee();
  void buyTextbook();
  void buyItem(int);

  void reset();

  //debug
  void print();

  int computerCost();
  int foodCost();
  int coffeeCost();
  int textbookCost();
  int getRemainingMoneyAmount() { return m_money; }
  int getComputerQuality() { return m_computer_quality; }
  int getFoodCount() { return m_food_count; }
  int getCoffeeCount() { return m_coffee_count; }
  int getTextbookQuality() { return m_textbook_quality; }

private:
  int m_money;
  int m_computer_quality;
  int m_food_count;
  int m_coffee_count;
  int m_textbook_quality;
};