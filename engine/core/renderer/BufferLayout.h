#ifndef DATA_GARDEN_BUFFER_LAYOUT
#define DATA_GARDEN_BUFFER_LAYOUT

#include <string>
#include <vector>
#include <stdint.h>

#include "DataGarden.h"

namespace DataGarden
{
	enum class BufferDataType
	{
		None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
	};

	static uint32_t BufferDataTypeSize(BufferDataType type)
	{
		switch(type)
		{
			case BufferDataType::Float:
				return 4;
			case BufferDataType::Float2:   
				return 4 * 2;
			case BufferDataType::Float3:   
				return 4 * 3;
			case BufferDataType::Float4:   
				return 4 * 4;
			case BufferDataType::Mat3:     
				return 4 * 3 * 3;
			case BufferDataType::Mat4:     
				return 4 * 4 * 4;
			case BufferDataType::Int:      
				return 4;
			case BufferDataType::Int2:     
				return 4 * 2;
			case BufferDataType::Int3:     
				return 4 * 3;
			case BufferDataType::Int4:     
				return 4 * 4;
			case BufferDataType::Bool:     
				return 1;
		}
		
		return 0;
	}

	struct BufferDataElement
	{
		std::string name;
		BufferDataType dataType;
		uint32_t size;
		uint32_t offset;
		bool normalized;

		BufferDataElement(BufferDataType dataType, const std::string& name, bool normalized = false)
			: name(name), dataType(dataType), size(BufferDataTypeSize(dataType)), offset(0), normalized(normalized)
		{}

		uint32_t GetComponentCount() const
		{
			switch (dataType)
			{
				case BufferDataType::Float:   
					return 1;
				case BufferDataType::Float2:  
					return 2;
				case BufferDataType::Float3:  
					return 3;
				case BufferDataType::Float4:  
					return 4;
				case BufferDataType::Mat3:    
					return 3 * 3;
				case BufferDataType::Mat4:    
					return 4 * 4;
				case BufferDataType::Int:     
					return 1;
				case BufferDataType::Int2:    
					return 2;
				case BufferDataType::Int3:    
					return 3;
				case BufferDataType::Int4:    
					return 4;
				case BufferDataType::Bool:    
					return 1;
			}

			return 0;
		}
	};

	class BufferLayout
	{
	public:
		BufferLayout() {}

		BufferLayout(const std::initializer_list<BufferDataElement>& elements)
			: m_Elements(elements)
		{
			_CalculateOffsetsAndStride();
		}

		inline uint32_t GetStride() const { return m_Stride; }
		inline const std::vector<BufferDataElement>& GetElements() const { return m_Elements; }

		std::vector<BufferDataElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferDataElement>::iterator end() { return m_Elements.end(); }
		std::vector<BufferDataElement>::const_iterator begin() const { return m_Elements.begin(); }
		std::vector<BufferDataElement>::const_iterator end() const { return m_Elements.end(); }
	private:
		void _CalculateOffsetsAndStride()
		{
			uint32_t offset = 0;
			m_Stride = 0;
			for(auto& element : m_Elements)
			{
				element.offset = offset;
				offset += element.size;
				m_Stride += element.size;
			}
		}
	private:
		std::vector<BufferDataElement> m_Elements;
		uint32_t m_Stride = 0;
	};
}

#endif
