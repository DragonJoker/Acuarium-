#pragma once

#include "Prerequisites.hpp"

#include <FishRenderer.hpp>

#include <array>

namespace aquarium
{
	namespace render
	{
		class GlFishRenderer
			: public FishRenderer
		{
		public:
			GlFishRenderer();
			~GlFishRenderer();

		private:
			virtual void doRender( Fish const & fish );
			virtual void doRenderBorn( Fish const & fish, Fish const & lhs, Fish const & rhs );
			virtual void doRenderDie( Fish const & fish );
			virtual void doRenderEat( Fish const & fish, Fish const & prey );
			virtual void doRenderEat( Fish const & fish, Seaweed const & prey );
			virtual void doRenderNoFood( Fish const & fish );
			virtual void doRenderNoMate( Fish const & fish );
			virtual void doRenderWrongMate( Fish const & fish, Fish const & mate );
			virtual void doRenderSwitchGender( Fish const & fish, Gender gender );

		private:
			std::array< obj::Mesh, RaceCount > m_meshes;
		};
	}
}
