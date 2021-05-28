#pragma once
class Workspace {
private:
	int axesLength;
	// À•W²•`‰æ
	void DrawXYZAxes();
	// °‚Ì•`‰æ
	void DrawFloor();
public:
	Workspace();
	Workspace(int length);
	// •`‰æ
	void Draw();
};