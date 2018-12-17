#pragma once

#include <iostream>
#include <string>

using namespace std;

enum class healthStatus
{
  HEALTHY = 1,
  NEED_COFFEE,
  STRESSED,
  CRAMMING,
  DEAD
};


// Characterter ideas
// 1. Professor
// 2. Student
// 3. TA (zombie?)


class Character
{
public: Character(string, bool);

 ~Character();

  string getName() { return m_name; }
  bool isNpc() { return m_npc; }
  healthStatus getStatus() { return m_status; }
  //int getStatus() { return static_cast<int>(m_status); }
  int deathStatus() { return static_cast<int>(healthStatus::DEAD); }

  void setStatus(healthStatus s) { m_status = s; }
  void killCharacter() { m_status = healthStatus::DEAD; }

protected:  // Protected is the same as private, except child classes can access these
  string m_name;  // name of character

private:
  bool m_npc;     // this Characterr is the Character or an NPC
  healthStatus m_status; // status of the character
};

class Student : public Character // inheritance. Character is the base class, Student is the child class
{
public:
  // Constructor
  Student(string name, bool npc, double gpa) : 
    Character(name, npc), // pass values to the base class constructor
    m_gpa(gpa) // initialize gpa value
  {
    cout << m_name <<" is also a student.\n"; // m_name must be set as PROTECTED and not PRIVATE in Character class for this to work
  }

  double getGPA() { return m_gpa; }

private:
  double m_gpa;
};