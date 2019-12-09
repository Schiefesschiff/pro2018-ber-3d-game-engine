#pragma once

#include "Types.h"
#include "Singleton.h"

class Clock
{
	GE_DECLARE_SINGLETON(Clock)

public:

	void Initialize(void);
	u64 GetElapsedTime(void);
	real GetTimeScale(void) const;
	u64 GetTimeSinceStart(void) const;

	void SetTimeScale(real timeScale);

private:

	u64 miEngineStartTime = 0;
	u64 miLastFrameTime = 0;
	real mfTimeScale = 0.0f;

};