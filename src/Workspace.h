#pragma once
class Workspace {
private:
	int axesLength;
	// ���W���`��
	void DrawXYZAxes();
	// ���̕`��
	void DrawFloor();
public:
	Workspace();
	Workspace(int length);
	// �`��
	void Draw();
};