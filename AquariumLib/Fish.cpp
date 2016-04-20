﻿#include "Fish.hpp"

#include "Aquarium.hpp"

namespace aquarium
{
  Fish::Fish( FishRace race, bool herbivore, bool carnivore, uint16_t age, std::string const & name, Gender gender )
    : Living{ age, 10u }
    , m_race{ race }
    , m_name{ name }
    , m_gender{ gender }
    , m_herbivore{ herbivore }
    , m_carnivore{ carnivore }
  {
  }

  void Fish::onNewTurn( Aquarium & aqua )
  {
    grow();
    damage( 1 );

    if ( isAlive() )
    {
      doOnNewTurn( aqua );

      if ( getHealth() <= 5 )
      {
        eat( aqua );
      }
      else if ( canReproduce() )
      {
        reproduce( aqua );
      }
    }
  }

  void Fish::switchGender()
  {
    std::cout << "[" << aquarium::manip( m_name ) << "] switches gender from " << aquarium::manip( m_gender );
    m_gender = Gender( 1 - m_gender );
    std::cout << " to " << aquarium::manip( m_gender ) << "\n";
  }

  void Fish::reproduce( Aquarium & aqua )
  {
    try
    {
      doReproduce( aqua );
    }
    catch ( NoMateException & exc )
    {
      std::cout << "[" << aquarium::manip( this->getName() ) << "] tried to reproduce, but ";
      std::cout << exc.what() << ".\n";
    }
    catch ( WrongMateException & exc )
    {
      std::cout << "[" << aquarium::manip( this->getName() ) << "] tried to reproduce, but ";
      std::cout << exc.what() << ".\n";
    }
  }

  void Fish::eat( Aquarium & aqua )
  {
    try
    {
      doEat( aqua );
    }
    catch ( NoFoodException & exc )
    {
      std::cout << "[" << aquarium::manip( this->getName() ) << "] is hungry, but ";
      std::cout << exc.what() << ".\n";
    }
  }

  std::ostream & operator<<( std::ostream & stream, Fish const & fish )
  {
    stream << aquarium::manip( fish.getRace() );
    stream << "\t" << aquarium::manip( fish.getName() );
    stream << "\t" << aquarium::manip( fish.getGender() );
    stream << static_cast< Living const & >( fish );
    return stream;
  }

  std::istream & operator>>( std::istream & stream, Fish & fish )
  {
    std::string genderName;
    std::getline( stream, fish.m_name, '\t' );
    fish.m_name = fish.m_name.substr( fish.m_name.find_first_not_of( " \t" ) );
    fish.m_name = fish.m_name.substr( 0, fish.m_name.find_last_not_of( " \t" ) + 1 );
    stream >> genderName;
    fish.m_gender = getGender( genderName );
    stream >> static_cast< Living & >( fish );
    return stream;
  }
}
