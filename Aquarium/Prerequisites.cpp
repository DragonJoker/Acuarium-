#include "Prerequisites.hpp"

#include <AquariumRenderer.hpp>
#include <FishRace.hpp>

namespace aquarium
{
	namespace render
	{
		namespace
		{
			std::string const & getGenderName( Gender gender )
			{
				static std::string const Names[GenderCount]
				{
					"Female",
					"Male"
				};

				return Names[gender];
			}

			std::string const & getRaceName( FishRace race )
			{
				static std::string const Names[RaceCount]
				{
					"Basse",
					"Tuna",
					"Clown",
					"Sole",
					"Bass",
					"Carp",
				};

				return Names[race];
			}
		}

		NameManip::NameManip( std::string const & str )
			: m_str{ str }
		{
		}

		GenderManip::GenderManip( Gender gender )
			: m_str{ getGenderName( gender ) }
		{
		}

		RaceManip::RaceManip( FishRace race )
			: m_str{ getRaceName( race ) }
		{
		}

		std::ostream & operator<<( std::ostream & stream, NameManip const & manip )
		{
			stream << std::setw( 15 ) << std::left << manip.m_str;
			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, GenderManip const & manip )
		{
			stream << std::setw( 6 ) << std::left << manip.m_str;
			return stream;
		}

		std::ostream & operator<<( std::ostream & stream, RaceManip const & manip )
		{
			stream << std::setw( 5 ) << std::left << manip.m_str;
			return stream;
		}
	}
}

void updateAquarium( aquarium::Aquarium & aqua, TurnAddsMap & turnsAdds, uint32_t turn )
{
  for ( auto && seaweed : turnsAdds[turn].m_seaweeds )
  {
    aqua.addSeaweed( std::move( seaweed ) );
  }

  for ( auto && fish : turnsAdds[turn].m_fishes )
  {
    aqua.addFish( std::move( fish ) );
  }

  turnsAdds.erase( turn );
  aqua.updateLists();
}

void saveAquarium( std::string const & filename, aquarium::Aquarium const & aqua )
{
  std::ofstream out{ filename };

  if ( out )
  {
    out << aqua;
    out.close();
  }
}
