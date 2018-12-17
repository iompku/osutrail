#include "event.h"



// examples of events

  // example: Tim was estimating progress completion based on his code compiling rather than it actually working. Progress goes backward.
  //
  // Ate junk food, health down
  // Hung over, health down, made no progress this week
  // Stayed up too late playing video games, didn't complete their part of project assignment, negative progress this week
  // Cat stepped on computer's surge protector, all progress lost!
  // Significant other was visiting, no progress this week
  // Contracted the flu, negative health
  // Carpal tunnel, negative health and progress

Event::Event()
{
  m_events.clear();
  string s = "Progress completion was being estimated based on code compiling rather than actually functioning. Progress regression.";

  eventAttr e= { s, PROGRESS, false};

  m_events.push_back(e);

  s = "Ate junk food, health down";
  e = { s, HEALTH, false};
  m_events.push_back(e);

  s = "Hung over, health down, made no progress this week";
  e = { s, PROGRESS_AND_HEALTH, false};
  m_events.push_back(e);
  
  s = "Stayed up too late playing video games, didn't complete their part of project assignment, negative progress this week";
  e = { s, PROGRESS, false};
  m_events.push_back(e);

  s = "Cat stepped on computer's surge protector, all progress lost!";
  e = { s, PROGRESS, false};
  m_events.push_back(e);

  s = "Significant other was visiting, no progress this week";
  e = { s, PROGRESS, false};
  m_events.push_back(e);

  s = "Contracted the flu";
  e = { s, HEALTH, false};
  m_events.push_back(e);

  s = "Carpal tunnel";
  e = { s, PROGRESS_AND_HEALTH, false};
  m_events.push_back(e);
}