#include <iostream>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <time.h>
#include "character.h"
//#include "inventory.h"
#include "party.h"
#include "event.h"

using namespace std;

void printCharStatus(Character);
void beginningMenu(Party*);
int menuOptions(int numChoices, string* textChoices);

int main() 
{
  srand(time(NULL));
  #define FINAL_WEEK (10)
  int week = 1;

  Party myParty;
  beginningMenu(&myParty);

  Inventory *bag = myParty.getBag();
  bag->print();

  // Project is assigned week 1. You have _ weeks left
  // hypothetical 5 weeks
  // prompted with a choice
  // would you like to study in the library, or in the computer lab (can influence health differently)
  // based on those choices there's going to be some behind the scenes that will help you get on your progress
  // 
  // player is healthy, player is not.
  // 
  // people health
  // project completion %
  // like library get extra health but project does not get as far
  // computer lab get more project progress but health goes down
  // 
  //random events (a single player) something happens good or bad
  Event events;
  eventAttr e;
  string options[6] = {"","","","","",""};

  while (week <= FINAL_WEEK)
  {
    cout << "Week " << week << "\nProgress on final project: " << myParty.getProgress() << "\nThe people in your group:\n";
    myParty.printCharacters();

    if (week == 1)
    {
      cout << "\nIt is your first week, should you go study at the Library or in the Computer lab?\n";
      options[0] = "Library";
      options[1] = "Computer Lab";
      int choice = menuOptions(2,options);
      // Just like in real life, sometimes your choices are meaningless
    }
    else if (week == 5)
    {
      cout << "\nMidterms are coming up for all of your classes, what should you do?\n";
      options[0] = "Focus on CS";
      options[1] = "Make sure you do well in all your classes";
      options[2] = "Give up all hope";
      int choice = menuOptions(3,options);
      if (1 == choice)
      {
        myParty.damageRandomCharacter(3);
      }
      else if (2 == choice)
      {
        myParty.updateProgress(-5);
      }
      else if (3 == choice)
      {
        myParty.damageRandomCharacter(5);
      }
    }
    else if (week == 10)
    {
      cout << "\nFinals! What should you do?\n";
      options[0] = "Focus on CS";
      options[1] = "Make sure you do well in all your classes";
      options[2] = "Give up all hope";
      int choice = menuOptions(3,options);
      if (1 == choice)
      {
        myParty.damageRandomCharacter(3);
      }
      else if (2 == choice)
      {
        myParty.updateProgress(-5);
      }
      else if (3 == choice)
      {
        myParty.damageRandomCharacter(5);
      }
    }
    else
    {
      // Not a specific event week, see if random event happens
      int bad = rand() % 100;
      if (bad > 25)
      {
        //Character* randChar = myParty.getRandomCharacter();
        e = events.getEvent();
        cout << e.description << endl;
        if ((e.category == PROGRESS) || (e.category == PROGRESS_AND_HEALTH))
        {
          myParty.updateProgress(-2.5);
        }
        if ((e.category == HEALTH) || (e.category == PROGRESS_AND_HEALTH))
        {
          int health_dmg = ((rand()%2)+1)*3;
          myParty.damageRandomCharacter(health_dmg);
        }
        
      }
      else
      {
        cout << "\nThe week went by uneventful\n\n";
      }
      string garbage;
      getline(cin, garbage);
    }

    // normally each person contributes 2.5 progress each week
    myParty.weeklyProgress();

    // Do you want to study in the library or?

  //debugging function

                     /*{"Travel the trail", 
                       "Learn about the trail",
                       "See the Oregon Top Ten",
                       "Turn sound off",
                       "Choose Management Options",
                       "End"};*/
  //int userSelection;

  
    //userSelection = menuOptions(6, options);
    

    //cout << "You selected " << userSelection << endl;

    week++;
  }
  cout << "\nYour final grade on the project is " << myParty.getProgress() <<"%\n";
}

void printCharStatus(Character newChar)
{
    if (newChar.getStatus() == healthStatus::HEALTHY)
      cout << "Healthy\n";
    else if (newChar.getStatus() == healthStatus::DEAD)
      cout << "Dead\n";
    else if (newChar.getStatus() == healthStatus::NEED_COFFEE)
      cout << "Needing Coffee\n";
    else if (newChar.getStatus() == healthStatus::STRESSED)
      cout << "Stressed\n";
    else if (newChar.getStatus() == healthStatus::CRAMMING)
      cout << "Cramming\n";
    else
      cout << "I DON'T KNOW\n";
}

void beginningMenu(Party* party)
{
  #define NUM_PLAYERS (5)
  string playerName;
  cout << "What is your name?\n";
  //cin >> playerName;
  getline(cin, playerName);

  string names[NUM_PLAYERS] = { "", "Shellie", "Brett", "Tim", "Liz"};
  names[0] = playerName;

  Character* player = new Character(playerName, false);
  party->addCharacter(player);

  cout << "Hello, " << playerName << ", you are in a Computer Science Course and have showed up late to the first class. You have been assigned to a final group project without any input.\nYou will be working with ";
  for (int i = 1; i < NUM_PLAYERS; ++i)
  {
    if (i != NUM_PLAYERS-1)
    {
      cout << names[i] << ", ";
    }
    else
    {
      cout << " and " << names[i] << ".\n";
    }

    player = new Character(names[i], true);
    party->addCharacter(player);
  }

  Inventory* bag = party->getBag();

  // Buy shit
  string buyOptions[5] = {"Computer $", "Food $", "Coffee $", "Textbook $", "Done Buying"};
  buyOptions[0].append(to_string(bag->computerCost()));
  buyOptions[1].append(to_string(bag->foodCost()));
  buyOptions[2].append(to_string(bag->coffeeCost()));
  buyOptions[3].append(to_string(bag->textbookCost()));

  int selection;
  while (true)
  {
    cout << "You have " << bag->getRemainingMoneyAmount() << " money to spend. What would you like to buy?\n";
    selection = menuOptions(5, buyOptions);

    if (selection == 5)
    {
      break;
    }
    else
    {
      bag->buyItem(selection-1);
    }
  }
  
}


//=====================================================================
// menuOptions
// Function to sanitize input
// Input: 
//   numChoices
//        Number of options the user can select from. Make sure it
//        is 1 or greater.
//   textChoices
//        Array of strings representing description of options. Must be
//        at least numChoices in length. Responsibility of caller.
//
// Output: Number the user entered. Valid selection is defined as
//         ranging from 1 up to and including numChoices. 
//         Reprompts user if input was invalid
// Returns -1 on error
//
// WARNING: Ensure you are passing an array of strings that is at least
// as long as numChoices
//=====================================================================
int menuOptions (int numChoices, string* textChoices)
{
  assert(numChoices > 0);

  int MAX_LENGTH = 10;

  int selection = -1; // the return value
  string stringInput;
  int intInput;
  bool inputValid = false;

  while (false == inputValid)
  {
    // Displace choices
    cout << "Please select an option:\n";
    for (int i = 0; i < numChoices; ++i)
    {
      cout << (i+1) << ". " << textChoices[i] << endl;
    }

    // Get input
    getline(cin, stringInput);  // using getline to make sure no spaces

    // Check string length
    if (stringInput.length() > MAX_LENGTH)
    {
      cout << "That value is too long\n";
      continue;
    }
    else if (0 == stringInput.length())
    {
      continue;
    }

    // Make sure string contains only digits (credit: stackoverflow)
    if (stringInput.find_first_not_of("0123456789") == string::npos)
    {
      // Try to conver to int
      intInput = stoi(stringInput);
      // Make sure it is in proper range
      if ((intInput > 0) && (intInput <= numChoices))
      {
        selection = intInput; // everything is valid, update the return value
        inputValid = true;
      }
      else
      {
        cout << "Please enter a selection between 1 and " << numChoices << endl;
        continue;
      }
    }
    else
    {
      cout << "Please only enter number(s).\n";
    }
  }

  return selection;
}

