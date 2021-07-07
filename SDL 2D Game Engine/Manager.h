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

	template<typename T>
	void registerComponent() {
		component_manager->registerComponent<T>();
	}
	
	template<typename T>
	void addComponent(Entity entity, T component) {
		component_manager->addComponent<T>(entity, component); // Add the component to the entity

		// Change the entity's signature so it contains the new component
		Signature signature = entity_manager->getSignature(entity);
		signature.set(component_manager->getComponentType<T>());
		entity_manager->setSignature(entity, signature);

		system_manager->entitySignatureChanged(entity, signature); // Notify the systems that the entity's signature has changed
	}

	template<typename T>
	void removeComponent(Entity entity) {
		component_manager->removeComponent<T>(entity); // Remove the component from the entity

		// Change the entity's signature so it doesn't contain the old component
		Signature signature = entity_manager->getSignature(entity);
		signature.reset(component_manager->getComponentType<T>());
		entity_manager->setSignature(entity, signature);

		system_manager->entitySignatureChanged(entity, signature); // Notify the systems that the entity's signature has changed
	}

	template<typename T>
	T& getComponent(Entity entity) {
		return component_manager->getComponent<T>(entity);
	}

	template<typename T>
	ComponentType getComponentType() {
		return component_manager->getComponentType<T>();
	}

	template<typename T>
	std::shared_ptr<T> registerSystem() {
		return system_manager->registerSystem<T>();
	}

	template<typename T>
	void setSystemSignature(Signature signature) {
		system_manager->setSignature<T>(signature);
	}

private:
	std::unique_ptr<EntityManager> entity_manager;
	std::unique_ptr<ComponentManager> component_manager;
	std::unique_ptr<SystemManager> system_manager;
};