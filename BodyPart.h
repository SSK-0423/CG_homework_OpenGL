#pragma once
class BodyPart {
public:
	virtual void Draw() = 0;
	virtual void Animation() = 0;
	virtual void SetPosition() = 0;
};