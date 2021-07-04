#include "Manager.h"

void Manager::init() {
    entity_manager = std::make_unique<EntityManager>();
    component_manager = std::make_unique<ComponentManager>();
    system_manager = std::make_unique<SystemManager>();
}

Entity Manager::createEntity() {
    return entity_manager->createEntity();
}

void Manager::destroyEntity(Entity entity) {
    entity_manager->destroyEntity(entity);
    component_manager->entityDestroyed(entity);
    system_manager->entityDestroyed(entity);
}

template<typename T>
void Manager::registerComponent() {
    component_manager->registerComponent<T>();
}

template<typename T>
void Manager::addComponent(Entity entity, T component) {
    component_manager->addComponent<T>(entity, component); // Add the component to the entity

    // Change the entity's signature so it contains the new component
    Signature signature = entity_manager->getSignature(entity);
    signature.set(component_manager->getComponentType<T>());
    entity_manager->setSignature(entity, signature);

    system_manager->entitySignatureChanged(entity, signature); // Notify the systems that the entity's signature has changed
}

template<typename T>
void Manager::removeComponent(Entity entity) {
    component_manager->removeComponent<T>(entity); // Remove the component from the entity

    // Change the entity's signature so it doesn't contain the old component
    Signature signature = entity_manager->getSignature(entity);
    signature.reset(component_manager->getComponentType<T>());
    entity_manager->setSignature(entity, signature);

    system_manager->entitySignatureChanged(entity, signature); // Notify the systems that the entity's signature has changed
}

template<typename T>
T& Manager::getComponent(Entity entity) {
    return component_manager->getComponent<T>(entity);
}

template<typename T>
ComponentType Manager::getComponentType(Entity entity) {
    return component_manager->getComponentType<T>();
}

template<typename T>
std::shared_ptr<T> Manager::registerSystem() {
    return system_manager->registerSystem<T>();
}

template<typename T>
void Manager::setSystemSignature(Signature signature) {
    system_manager->setSignature<T>(signature);
}
