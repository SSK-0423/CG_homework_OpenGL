#pragma once
#include "Component.hpp"
#include <vector>
#include <iostream>
class Component;

class Object {
protected:
	std::vector<Component*> componentList;	//コンポーネントリスト

public:
	Object() {}
	virtual ~Object() {
		for (auto comp : componentList) {
			delete comp;
		}
		componentList.clear();
	}

	//コンポーネント取得
	template <class T>
	T* GetComponent() {
		for (auto comp : componentList) {
			// dynamic_castは避けるべき
			T* castComp = dynamic_cast<T*>(comp);
			if (castComp != nullptr) {
				return castComp;
			}
		}
		return nullptr;
	}

	//コンポーネント追加
	template <class T>
	T* AddComponent() {
		//コンポーネントが既に存在するかチェック
		for (auto comp : componentList) {
			// #ダウンキャストは危険(?)
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