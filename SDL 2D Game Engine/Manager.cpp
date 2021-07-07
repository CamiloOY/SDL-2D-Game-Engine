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