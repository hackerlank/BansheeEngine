#include "CmTechnique.h"
#include "CmException.h"
#include "CmRenderSystemManager.h"
#include "CmRenderSystem.h"
#include "CmRendererManager.h"
#include "CmPass.h"
#include "CmRenderer.h"

namespace CamelotEngine
{
	Technique::Technique(const String& renderSystem, const String& renderer)
		:mRenderSystem(renderSystem), mRenderer(renderer)
	{

	}

	PassPtr Technique::addPass()
	{
		PassPtr newPass(new Pass(this, mPasses.size()));

		mPasses.push_back(newPass);
		return newPass;
	}

	void Technique::removePass(UINT32 idx)
	{
		if(idx < 0 || idx >= mPasses.size())
			CM_EXCEPT(InvalidParametersException, "Index out of range: " + toString(idx));

		int count = 0;
		auto iter = mPasses.begin();
		while(count != idx)
		{
			++count;
			++iter;
		}

		mPasses.erase(iter);
	}

	PassPtr Technique::getPass(UINT32 idx) const
	{
		if(idx < 0 || idx >= mPasses.size())
			CM_EXCEPT(InvalidParametersException, "Index out of range: " + toString(idx));

		return mPasses[idx];
	}

	bool Technique::isSupported() const
	{
		if(RenderSystemManager::getActive()->getName() == mRenderSystem &&
			RendererManager::getActive()->getName() == mRenderer)
		{
			return true;
		}

		return false;
	}
}