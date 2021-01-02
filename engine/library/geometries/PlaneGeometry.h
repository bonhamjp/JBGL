#ifndef DATA_GARDEN_PLANE_GEOMETRY
#define DATA_GARDEN_PLANE_GEOMETRY

#include "DataGarden.h"

#include "core/object/Geometry.h"

namespace DataGarden
{
	class PlaneGeometry : public Geometry
	{
	public:
		PlaneGeometry();
		virtual ~PlaneGeometry();

    virtual std::string& GetName() override;

		virtual BufferLayout GetLayout() override;

	private:
		void _CreateBufferObject();
		void _DestroyBufferObject();

	};
}

#endif
