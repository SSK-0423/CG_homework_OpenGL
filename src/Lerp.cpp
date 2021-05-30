#include "Lerp.h"
void MakeLerpList(std::vector<int>& list, std::vector<float>& lerp, int step)
{
	for (int i = 0; i < list.size() - 1; i++) {
		//·•ª
		float diff = (float)(list[i + 1] - list[i]) / (float)step;
		for (int j = 0; j < step; j++) {
			//•âŠÔƒŠƒXƒg‚ÉŠi”[
			lerp.push_back(list[i] + diff * j);
		}
	}
}