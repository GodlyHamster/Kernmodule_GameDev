#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class CustomTime
{
private:
	sf::Clock deltaClock;
	float deltaTime = 0.0f;

protected:
	CustomTime() {
	}

	static CustomTime* customTime_;

public:
	float DeltaTime();
	float FPS();
	void Update();

	CustomTime(CustomTime& other) = delete;

	void operator=(const CustomTime&) = delete;

	static CustomTime* GetInstance();
};

