#pragma once
#include "Component.hpp"
#include <vector>
#include <iostream>
class Component;

class Object {
protected:
	std::vector<Component*> componentList;	//�R���|�[�l���g���X�g

public:
	Object() {}
	virtual ~Object() {
		for (auto comp : componentList) {
			delete comp;
		}
		componentList.clear();
	}

	//�R���|�[�l���g�擾
	template <class T>
	T* GetComponent() {
		for (auto comp : componentList) {
			// dynamic_cast�͔�����ׂ�
			T* castComp = dynamic_cast<T*>(comp);
			if (castComp != nullptr) {
				return castComp;
			}
		}
		return nullptr;
	}

	//�R���|�[�l���g�ǉ�
	template <class T>
	T* AddComponent() {
		//�R���|�[�l���g�����ɑ��݂��邩�`�F�b�N
		for (auto comp : componentList) {
			// #�_�E���L���X�g�͊댯(?)
			T* castComp = dynamic_cast<T*>(comp);
			if (castComp != nullptr) {
				return nullptr;
			}
		}
		T* component = new T();
		component->SetParentObject(*this);
		componentList.push_back(component);
		return component;
	}
};