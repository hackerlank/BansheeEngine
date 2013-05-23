#pragma once

#include "BsPrerequisites.h"
#include "BsGUIElement.h"
#include "BsImageSprite.h"

namespace BansheeEngine
{
	class BS_EXPORT GUIButton : public GUIElement
	{
	public:
		static const CM::String& getGUITypeName();

		static GUIButton* create(GUIWidget& parent);
		static GUIButton* create(GUIWidget& parent, const GUILayoutOptions& layoutOptions);
	protected:
		~GUIButton();

		/**
		 * @copydoc GUIElement::getNumRenderElements()
		 */
		virtual UINT32 getNumRenderElements() const;

		/**
		 * @copydoc GUIElement::getMaterial()
		 */
		virtual const CM::HMaterial& getMaterial(UINT32 renderElementIdx) const;

		/**
		 * @copydoc GUIElement::getNumQuads()
		 */
		virtual UINT32 getNumQuads(UINT32 renderElementIdx) const;

		/**
		 * @copydoc GUIElement::fillBuffer()
		 */
		virtual void fillBuffer(UINT8* vertices, UINT8* uv, UINT32* indices, UINT32 startingQuad, 
			UINT32 maxNumQuads, UINT32 vertexStride, UINT32 indexStride, UINT32 renderElementIdx) const;

		/**
		 * @copydoc GUIElement::updateRenderElementsInternal()
		 */
		virtual void updateRenderElementsInternal();

		virtual UINT32 _getOptimalWidth() const;
		virtual UINT32 _getOptimalHeight() const;

		static const GUILayoutOptions& getDefaultLayoutOptions();
	private:
		ImageSprite* mImageSprite;
		IMAGE_SPRITE_DESC mDesc;

		GUIButton(GUIWidget& parent, const GUILayoutOptions& layoutOptions);

		virtual bool mouseEvent(const GUIMouseEvent& ev);
	};
}