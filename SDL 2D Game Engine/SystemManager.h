#pragma once

#include "Types.h"
#include "System.h"
#include <llvm/ADT/DenseMap.h>
#include <memory>

class SystemManager {
public:
	template<typename T> std::shared_ptr<T> registerSystem();
	template<typename T> void setSignature(Signature signature);
	void entityDestroyed(Entity entity);
	void entitySignatureChanged(Entity entity, Signature signature);

private:
	llvm::DenseMap<const char*, Signature> signatures; // Map a system to its signature
	llvm::DenseMap<const char*, std::shared_ptr<System>> systems; // Map of systems
};