#pragma once

#include "Types.h"
#include "System.h"
#include <llvm/ADT/DenseMap.h>
#include <memory>

class SystemManager {
public:
	template<typename T>
	std::shared_ptr<T> registerSystem() {
		const char* type_name = typeid(T).name();
		assert(systems.find(type_name) == systems.end()); // Ensure system hasn't been registered
		auto system = std::make_shared<T>();
		systems.insert({type_name, system});
		return system;
	}
	
	template<typename T>
	void setSignature(Signature signature) {
		const char* type_name = typeid(T).name();
		assert(systems.find(type_name) != systems.end()); // Ensure system has been registered
		signatures[type_name] = signature;
	}

	void entityDestroyed(Entity entity);
	void entitySignatureChanged(Entity entity, Signature signature);
	void update();
	void render();

private:
	llvm::DenseMap<const char*, Signature> signatures; // Map a system to its signature
	llvm::DenseMap<const char*, std::shared_ptr<System>> systems; // Map of systems
};