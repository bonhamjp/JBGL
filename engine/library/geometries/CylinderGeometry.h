#ifndef DATA_GARDEN_CYLINDER_GEOMETRY
#define DATA_GARDEN_CYLINDER_GEOMETRY

#include "DataGarden.h"

#include "core/object/Geometry.h"

namespace DataGarden
{
	class CylinderGeometry : public Geometry
	{
	public:
		CylinderGeometry(unsigned int subdivisions);
		virtual ~CylinderGeometry();

    virtual BufferLayout GetLayout() override;

	private:
    const unsigned int m_BaseVertexCount = 12;
    const unsigned int m_VertexSubdivisionMultiplier = 4;

    const unsigned int m_BaseIndexCount = 60;
    const unsigned int m_IndexSubdivisionMultiplier = 4;

    unsigned int m_Subdivisions;

		void _CreateBufferObject();
		void _DestroyBufferObject();
	};
}

#endif
