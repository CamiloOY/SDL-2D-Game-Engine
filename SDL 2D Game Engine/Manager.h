#pragma once

#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"
#include <memory>

class Manager {
public:
	void init();
	Entity createEntity();
	void destroyEntity(Entity entity);
	template<typename T> void registerComponent();
	template<typename T> void addComponent(Entity entity, T component);
	template<typename T> void removeComponent(Entity entity);
	template<typename T> T& getComponent(Entity entity);
	template<typename T> ComponentType getComponentType(Entity entity);
	template<typename T> std::shared_ptr<T> registerSystem();
	template<typename T> void setSystemSignature(Signature signature);

private:
	std::unique_ptr<EntityManager> entity_manager;
	std::unique_ptr<ComponentManager> component_manager;
	std::unique_ptr<SystemManager> system_manager;
};