#ifndef DATA_GARDEN_SPHERE_GEOMETRY
#define DATA_GARDEN_SPHERE_GEOMETRY

#include "DataGarden.h"

#include "core/object/Geometry.h"

#include <map>

#include <glm/glm.hpp>

namespace DataGarden
{
	class SphereGeometry : public Geometry
	{
	public:
		SphereGeometry(unsigned int subdivisions);
		virtual ~SphereGeometry();

    virtual std::string& GetName() override;

		virtual BufferLayout GetLayout() override;

	private:
    const unsigned int m_BaseVertexCount = 12;
    const unsigned int m_VertexSubdivisionMultiplier = 4;

    const unsigned int m_BaseIndexCount = 60;
    const unsigned int m_IndexSubdivisionMultiplier = 4;

    unsigned int m_Subdivisions;

    unsigned int m_CurrentIndex = 0;
    std::map<long long, unsigned int> m_HalfPointIndexCache;

    glm::vec3 _GetVectorAtIndex(unsigned int vertexIndex);
    unsigned int _GetHalfPointIndex(unsigned int vectorAIndex, unsigned int vectorBIndex);

    // slow, since recursive, probably should simplify these
    unsigned int _VerticesForSubdivisions(unsigned int subdivision);
    unsigned int _IndicesForSubdivisions(unsigned int subdivsion);

    void _NormalizeVertices();

		void _CreateBufferObject();
		void _DestroyBufferObject();

	};
}

#endif
