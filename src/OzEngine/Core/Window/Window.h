/** Window management system to handle creation of window **/
#ifndef _WINDOW_H_
#define _WINDOW_H_

//Includes
#include <OzEngine/Core/Core.h>
#include <OzEngine/Core/PrecompiledHeader/ozpch.h>

namespace Oz
{
	class cWindow
	{
	public:

		cWindow(const std::string& _Title,
			uint32_t _Width,
			uint32_t _Height, bool _Fullscreen);

		virtual void OnUpdate() = 0;

		virtual void SetFullscreen(bool _Fullscreen) = 0;

		virtual std::string GetTitle() const = 0;
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
		virtual bool IsFullscreen() const = 0;

		//Window Attributes
		virtual void SetEventCallback() = 0;
		virtual void SetVSync(bool _Enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		template <typename T, typename... A>
		static std::unique_ptr<T> Create(A... _args)
		{
			return std::make_unique<T>(_args...);
		}

		virtual ~cWindow() = default;

	protected:
		
		const std::string m_Title;
		uint32_t m_Width;
		uint32_t m_Height;
		bool m_Fullscreen;
		bool m_VSync;
		
	};
}

#endif