#include "Direct3D9ViewportTarget.hpp"
#include "../RenderQueue.hpp"
#include "../GeometryBuffer.hpp"
#include <d3d9.h>

namespace OSHGui {
	namespace Drawing {
		//---------------------------------------------------------------------------
		//Constructor
		//---------------------------------------------------------------------------
		Direct3D9ViewportTarget::Direct3D9ViewportTarget(Direct3D9Renderer &owner)
			: Direct3D9RenderTarget(owner) {
			D3DVIEWPORT9 vp;
			if (FAILED(owner.GetDevice()->GetViewport(&vp))) {
				throw;
			}

			SetArea(RectangleI(PointI(vp.X, vp.Y), SizeI(vp.Width, vp.Height)));
		}
		//---------------------------------------------------------------------------
		Direct3D9ViewportTarget::Direct3D9ViewportTarget(Direct3D9Renderer &owner, const RectangleI &area)
			: Direct3D9RenderTarget(owner) {
			SetArea(area);
		}
		//---------------------------------------------------------------------------
		//Getter/Setter
		//---------------------------------------------------------------------------
		bool Direct3D9ViewportTarget::IsImageryCache() const {
			return false;
		}
		//---------------------------------------------------------------------------
	}
}
