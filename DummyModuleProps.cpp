#include "pch.h"
#include "DummyModuleProps.h"
#include "DummyModule.h"

DEFINE_STATIC_RT_CLASS_MEMBERS(DummyModuleProps);

void* DummyModuleProps::GetModuleType() {
	return DummyModule::GetRTClass();
}

void DummyModuleProps::ModInit() {
	vftable = copyVFTable(getActualOffset(0x1CEB998), 20); // Edited by jkn

	patchVFTable(vftable, (void*)DummyModuleProps::GetRTClass, 0);
	patchVFTable(vftable, (void*)DummyModuleProps::GetModuleType, 14);

	DummyModuleProps::GetRTClass();
}
