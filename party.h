#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "character.h"
#include "inventory.h"

using namespace std;

class Party
{
  public:
  Party()
  {
    m_characters.clear();
    m_num_characters = 0;
    m_inventory.reset();
    m_project_completion = 0.0;
  }

  ~Party()
  {
    for (int i = 0; i < m_characters.size(); ++i)
    {
      delete m_characters.at(i);
    }
    m_characters.clear();
  }

  void addCharacter(Character* c)
  {
    if(nullptr != c)
    {
      m_characters.push_back(c);
      ++m_num_characters;
    }
  }

  int numCharactersAlive(void) {return m_num_characters;}

  Character* getCharacter(int index)
  {
    if (index < m_characters.size())
    {
      return m_characters.at(index);
    }
    else 
    {
      return nullptr;
    }
  }

  void damageCharacter(int index, int amount)
  {
    if (index < m_characters.size())
    {
      int health = static_cast<int>(m_characters.at(index)->getStatus());
      int death = m_characters.at(index)->deathStatus();

      if (amount >= (death - health))
      {
        killCharacter(index);
      }
      else
      {
        m_characters.at(index)->setStatus(static_cast<healthStatus>(health-amount));
      }
    }
  }

  void damageRandomCharacter(int amount)
  {
    damageCharacter(getRandomCharacter(), amount);
  }

  void killCharacter(int index)
  {
    if (index < m_characters.size())
    {
      m_characters.at(index)->setStatus(healthStatus::DEAD);
      --m_num_characters;
      cout << m_characters.at(index)->getName() << " has dropped out!\n";
    }
  }

  Inventory* getBag(void) { return & m_inventory; }

  void printCharacters(void) 
  {
    for (int i = 0; i < m_characters.size(); ++i)
    {
      if (m_characters.at(i)->getStatus() != healthStatus::DEAD)
      {
        cout << m_characters.at(i)->getName() << ", ";
      }
    }
    cout << endl;
  }

  int getRandomCharacter(void)
  {
    int sel;
    while (true)
    {
      sel = rand() % m_characters.size();
      if (m_characters.at(sel)->getStatus() != healthStatus::DEAD)
        break;
    }
    //return m_characters.at(sel);
    return sel;
  }

  double getProgress(void) { return m_project_completion; }
  void updateProgress(double p) 
  {
    m_project_completion += p;
    if (m_project_completion > 100.0)
      m_project_completion = 100.0;
    else if (m_project_completion < 0.0)
    {
      m_project_completion = 0.0;
    }
  }

  void weeklyProgress(void)
  {
    for (int i = 0; i < m_characters.size(); ++i)
    {
      if (m_characters.at(i)->getStatus() != healthStatus::DEAD)
      {
        updateProgress(2.5);
      }
    }
  }

private:
  vector<Character*> m_characters;
  int m_num_characters;
  Inventory m_inventory;
  double m_project_completion;

};