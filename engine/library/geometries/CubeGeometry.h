#ifndef DATA_GARDEN_CUBE_GEOMETRY
#define DATA_GARDEN_CUBE_GEOMETRY

#include "DataGarden.h"

#include "core/object/Geometry.h"

namespace DataGarden
{
	class CubeGeometry : public Geometry
	{
	public:
		CubeGeometry();
		virtual ~CubeGeometry();

    virtual std::string& GetName() override;

		virtual BufferLayout GetLayout() override;

	private:
		void _CreateBufferObject();
		void _DestroyBufferObject();

	};
}

#endif
