#include "inventory.h"
#include <iostream>

#define STARTING_MONEY (1000)
#define COMPUTER_COST (250)
#define FOOD_COST (10)
#define COFFEE_COST (5)
#define TEXTBOOK_COST (100)

// 1. Computer
// 2. Food
// 3. Coffee
// 4. Textbooks
// 5. Sleep?


  Inventory::Inventory() :
    m_money(STARTING_MONEY),
    m_computer_quality(0),
    m_food_count(0),
    m_coffee_count(0),
    m_textbook_quality(0)
  {
    cout << "Inventory created\n";
  }

  Inventory::~Inventory()
  {

  }

  int Inventory::computerCost()
  {
    return COMPUTER_COST;
  }
  
  int Inventory::foodCost()
  {
    return FOOD_COST;
  }

  int Inventory::coffeeCost()
  {
    return COFFEE_COST;
  }

  int Inventory::textbookCost()
  {
    return TEXTBOOK_COST;
  }

  void Inventory::buyComputerPart()
  {
    if (m_money >= COMPUTER_COST)
    {
      m_money -= COMPUTER_COST;
      ++m_computer_quality;
      cout << "Computer part bought\n";
    }
  }

  void Inventory::buyFood()
  {
    if (m_money >= FOOD_COST)
    {
      m_money -= FOOD_COST;
      ++m_food_count;
    }
  }

  void Inventory::buyCoffee()
  {
    if (m_money >= COFFEE_COST)
    {
      m_money -= COFFEE_COST;
      ++m_coffee_count;
    }

  }

  void Inventory::buyTextbook()
  {
    if (m_money >= TEXTBOOK_COST)
    {
      m_money -= TEXTBOOK_COST;
      ++m_textbook_quality;
    }

  }

  void Inventory::buyItem(int index)
  {
    switch(index)
    {
      case 0:
        buyComputerPart();
      break;

      case 1:
        buyFood();
      break;

      case 2:
        buyCoffee();
      break;

      case 3:
        buyTextbook();
      break;

      default:
        cout << "Error buying inventory\n";
      break;
    }
  }

  void Inventory::reset()
  {
    m_money = STARTING_MONEY;
    m_computer_quality = 0;
    m_food_count = 0;
    m_coffee_count = 0;
    m_textbook_quality = 0;
  }

  void Inventory::print()
  {
    cout << "\nMoney: " << m_money <<
            "\nComputer Parts: " << m_computer_quality <<
            "\nFood: " << m_food_count <<
            "\nCoffee: " << m_coffee_count <<
            "\nTextbook: " << m_textbook_quality << endl;
  }

