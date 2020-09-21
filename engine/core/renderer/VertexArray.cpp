#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include "Renderer.h"

#include "core/Engine.h"

namespace DataGarden
{
  // static GLenum BufferDataTypeTopOpenGLBaseType(BufferDataType dataType)
	// {
	// 	switch (dataType)
	// 	{
	// 		case BufferDataType::Float:
	// 			return GL_FLOAT;
	// 		case BufferDataType::Float2:
	// 			return GL_FLOAT;
	// 		case BufferDataType::Float3:
	// 			return GL_FLOAT;
	// 		case BufferDataType::Float4:
	// 			return GL_FLOAT;
	// 		case BufferDataType::Mat3:
	// 			return GL_FLOAT;
	// 		case BufferDataType::Mat4:
	// 			return GL_FLOAT;
	// 		case BufferDataType::Int:
	// 			return GL_INT;
	// 		case BufferDataType::Int2:
	// 			return GL_INT;
	// 		case BufferDataType::Int3:
	// 			return GL_INT;
	// 		case BufferDataType::Int4:
	// 			return GL_INT;
	// 		case BufferDataType::Bool:
	// 			return GL_BOOL;
	// 	}
	
	// 	return 0;
	// }

	VertexArray::VertexArray()
	{
		m_ID = Engine::Get().GetRenderer().CreateVertexArray();
	}
	
	VertexArray::~VertexArray()
	{
		Engine::Get().GetRenderer().DeleteVertexArray(m_ID);
	}
	
	void VertexArray::AddVertexLayout(VertexBuffer* vertexBuffer)
	{
		// Bind();
		// vertexBuffer->Bind();

		// uint32_t i = 0;
		// const auto& layout = vertexBuffer->GetLayout();
		// for (const auto& element : layout)
		// {
		// 	glEnableVertexAttribArray(i);

		// 	glVertexAttribPointer(
		// 		i,
		// 		element.GetComponentCount(),
		// 		BufferDataTypeTopOpenGLBaseType(element.dataType),
		// 		element.normalized,
		// 		layout.GetStride(),
		// 		(const void*)element.offset
		// 	);

		// 	i++;
		// }

		// vertexBuffer->Unbind();
		// Unbind();
	}

	void VertexArray::AddIndexLayout(IndexBuffer* indexBuffer)
	{}

	void VertexArray::Bind()
	{
		Engine::Get().GetRenderer().BindVertexArray(m_ID);
	}
	
	void VertexArray::Unbind()
	{
		Engine::Get().GetRenderer().unbindVertexArray();
	}
}
