#pragma once
#include <string>
#include <vector>
#include <stdlib.h>


using namespace std;

#define PROGRESS (0)
#define HEALTH (1)
#define PROGRESS_AND_HEALTH (2)

typedef struct 
{
  string description;
  int category;
  bool positive_effect;
} eventAttr;

class Event
{
public: 
//  Event(string text) :
//    m_description(text)
//  {}
  Event();

  string getText(void) { return m_description; }
  eventAttr getEvent(void) 
  {
    int selection = rand() % m_events.size();
    return m_events.at(selection);
  }

private:
  string m_description;
  vector<eventAttr> m_events;

// array of alive characters
// when they "die" they are remoed from the array

//event type 1) Random event during week change
  //Bad or good. Lower or raise health.
//event type 2) Choices event after event type 1. (2 choices)? 



};