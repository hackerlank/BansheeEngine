#pragma once

#include "CmPrerequisites.h"
#include "CmIReflectable.h"

namespace CamelotEngine
{
	class CM_EXPORT MeshData : public IReflectable
	{
	public:
		struct SubMeshData
		{
			SubMeshData():
				indexOffset(0), indexCount(0)
			{ }

			int indexOffset;
			int indexCount;
		};

		struct VertexData : public IReflectable
		{
			VertexData(UINT32 vertexCount);
			~VertexData();

			Vector3* vertex;
			Vector3* normal;
			Vector3* tangent;
			Vector3* bitangent;
			Vector2* uv0;
			Vector2* uv1;

			UINT32 vertexCount;

			/************************************************************************/
			/* 								SERIALIZATION                      		*/
			/************************************************************************/
		public:
			friend class VertexDataST;
			static RTTITypeBase* getRTTIStatic();
			virtual RTTITypeBase* getRTTI() const;
		};

		MeshData();
		~MeshData();

		int* index;

		int indexCount;
		int vertexCount;

		VertexDeclaration* declaration;
		map<int, std::shared_ptr<VertexData>>::type vertexBuffers;
		vector<SubMeshData>::type subMeshes;

		/************************************************************************/
		/* 								SERIALIZATION                      		*/
		/************************************************************************/
	public:
		friend class MeshDataST;
		static RTTITypeBase* getRTTIStatic();
		virtual RTTITypeBase* getRTTI() const;
	};
}