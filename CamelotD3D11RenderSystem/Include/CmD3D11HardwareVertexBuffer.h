#pragma once

#include "CmD3D11Prerequisites.h"
#include "CmHardwareVertexBuffer.h"
#include "CmD3D11HardwareBuffer.h"

namespace CamelotEngine
{
	class CM_D3D11_EXPORT D3D11HardwareVertexBuffer : public HardwareVertexBuffer
	{
	public:
		D3D11HardwareVertexBuffer(D3D11Device& device, HardwareBufferManagerBase* mgr, UINT32 vertexSize, UINT32 numVertices, 
			HardwareBuffer::Usage usage, bool useSystemMem, bool streamOut);
		~D3D11HardwareVertexBuffer();

		/**
		 * @copydoc HardwareBuffer::readData
		 */
		void readData(UINT32 offset, UINT32 length, void* pDest);

		/**
		 * @copydoc HardwareBuffer::writeData
		 */
		void writeData(UINT32 offset, UINT32 length, const void* pSource,
			bool discardWholeBuffer = false);

		/**
		 * @copydoc HardwareBuffer::copyData
		 */
		void copyData(HardwareBuffer& srcBuffer, UINT32 srcOffset, UINT32 dstOffset, UINT32 length, bool discardWholeBuffer = false);

		/**
		 * @brief	Get the D3D-specific index buffer
		 */
		ID3D11Buffer* getD3DVertexBuffer() const { return mBuffer->getD3DBuffer(); }		

	protected:
		/**
		* @copydoc HardwareBuffer::lockImpl
		 */
		void* lockImpl(UINT32 offset, UINT32 length, LockOptions options);

		/**
		 * @copydoc HardwareBuffer::unlockImpl
		 */
		void unlockImpl(void);

		D3D11HardwareBuffer* mBuffer;
	};
}