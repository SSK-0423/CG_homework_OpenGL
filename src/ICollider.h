#pragma once

class ICollider {
private:
public:
	ICollider() {};
	~ICollider() {};
	virtual void Collision() = 0;
	virtual void OnCollisionEnter() = 0;
};