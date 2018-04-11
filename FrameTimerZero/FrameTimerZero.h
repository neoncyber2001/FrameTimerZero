/*
 Name:		FrameTimerZero.h
 Created:	4/10/2018 8:32:51 PM
 Author:	djneo
 Editor:	http://www.visualmicro.com
*/

#ifndef _FrameTimerZero_h
#define _FrameTimerZero_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class FrameTimerZero {
public:
	typedef void(*FrameCallback)(uint32_t);

	FrameTimerZero(uint8_t FPS);
	FrameTimerZero(uint8_t FPS, FrameCallback frame);
	void setStartFrame(FrameCallback callback);
	void setMainFrame(FrameCallback callback);
	void setEndFrame(FrameCallback callback);
	boolean Begin(uint32_t time);
	void pause();
	void resume();
	void checkFrame(uint32_t time);
private:

	uint8_t m_FramesPerSecond;
	uint16_t m_FrameTime;
	uint32_t m_NextTime;
	boolean m_IsFrameStart = false;
	boolean m_IsFrameMain = false;
	boolean m_IsFrameEnd = false;
	boolean m_IsRunning = false;
	boolean m_IsInit = false;
	uint32_t m_FrameCount = 0;
	FrameCallback m_StartFrame;
	FrameCallback m_MainFrame;
	FrameCallback m_EndFrame;
};

#endif

