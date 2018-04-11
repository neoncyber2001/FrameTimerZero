/*
 Name:		FrameTimerZero.cpp
 Created:	4/10/2018 8:32:51 PM
 Author:	djneo
 Editor:	http://www.visualmicro.com
*/

#include "FrameTimerZero.h"

FrameTimerZero::FrameTimerZero(uint8_t FPS)
{
	m_FramesPerSecond = FPS;
	m_FrameTime = (uint16_t)1000 / FPS;
}

FrameTimerZero::FrameTimerZero(uint8_t FPS, FrameCallback frame)
{
	m_FramesPerSecond = FPS;
	m_FrameTime = (uint16_t)1000 / FPS;
	setMainFrame(frame);
}

void FrameTimerZero::setStartFrame(FrameCallback callback)
{
	m_StartFrame = callback;
	m_IsFrameStart = true;
}

void FrameTimerZero::setMainFrame(FrameCallback callback)
{
	m_MainFrame = callback;
	m_IsFrameMain = true;
}

void FrameTimerZero::setEndFrame(FrameCallback callback)
{
	m_EndFrame = callback;
	m_IsFrameEnd = true;
}

boolean FrameTimerZero::Begin(uint32_t time)
{
	if ((m_IsFrameStart || m_IsFrameMain || m_IsFrameEnd) && !m_IsRunning && !m_IsInit) {
		m_NextTime = time + m_FrameTime;
		m_FrameCount = 0;
		m_IsRunning = true;
		m_IsInit = true;
		return true;
	}
	else {
		return false;
	}
}

void FrameTimerZero::pause()
{
	if (m_IsRunning) {
		m_IsRunning = false;
	}
}

void FrameTimerZero::resume()
{
	if (!m_IsRunning) {
		m_IsRunning = false;
	}
}

void FrameTimerZero::checkFrame(uint32_t time)
{
	if (m_IsRunning && (m_NextTime <= time)) {
		
		if (m_IsFrameStart) {
			m_StartFrame(m_FrameCount);
		}
		if (m_IsFrameMain) {
			m_MainFrame(m_FrameCount);
		}
		if (m_IsFrameEnd) {
			m_EndFrame(m_FrameCount);
		}
		m_NextTime = time + m_FrameTime;		
		m_FrameCount++;
	}

}

