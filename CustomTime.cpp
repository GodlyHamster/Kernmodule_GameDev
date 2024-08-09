#include "CustomTime.h"

CustomTime* CustomTime::customTime_ = nullptr;

float CustomTime::DeltaTime()
{
	return deltaTime;
}

float CustomTime::FPS()
{
	return 1000 / deltaTime;
}

void CustomTime::Update()
{
	deltaTime = (float)deltaClock.getElapsedTime().asMicroseconds() / 1000;
	deltaClock.restart();
}

CustomTime* CustomTime::GetInstance()
{
	if (customTime_ == nullptr) {
		customTime_ = new CustomTime();
	}
	return customTime_;
}
