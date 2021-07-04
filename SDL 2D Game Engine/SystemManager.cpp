#include "SystemManager.h"

template<typename T>
std::shared_ptr<T> SystemManager::registerSystem() {
	const char* type_name = typeid(T).name();
	assert(systems.find(type_name) == systems.end()); // Ensure system hasn't been registered
	auto system = std::make_shared<T>();
	systems.insert({type_name, system});
	return system;
}

template<typename T>
void SystemManager::setSignature(Signature signature) {
	const char* type_name = typeid(T).name();
	assert(systems.find(type_name) != systems.end()); // Ensure system has been registered
	signatures[type_name] = signature;
}

void SystemManager::entityDestroyed(Entity entity) {
	for(auto system : systems) {
		system.second.get()->entities.erase(entity);
	}
}

void SystemManager::entitySignatureChanged(Entity entity, Signature signature) {
	for(auto system : systems) { // For each system
		Signature system_signature = signatures.lookup(system.first);
		if((signature & system_signature) == system_signature) { // If the system signature and entity signature match
			system.second.get()->entities.insert(entity); // Add the entity to the system
		}
		else {
			system.second.get()->entities.erase(entity); // Otherwise remove the entity from the system
		}
	}
}
