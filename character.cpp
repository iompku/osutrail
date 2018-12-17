
#include "character.h"


// Constructor
Character::Character(string name, bool npc) :
  m_name(name),
  m_npc(npc),
  m_status(healthStatus::HEALTHY)
{
  //cout << "Creating player " << m_name << endl;

}

// Destructor
Character::~Character()
{

}