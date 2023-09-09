#include "sfse_common/sfse_version.h"
#include "sfse/PluginAPI.h"
#include <ShlObj.h>  // CSIDL_MYDOCUMENTS
#include "sfse_common/Relocation.h"
#include "sfse_common/SafeWrite.h"

RelocAddr <uintptr_t*> boostCheckWithGravJump = 0x24EF80B;
RelocAddr <uintptr_t*> boostCalculation = 0x24EEFE5;

extern "C" {
	SFSEPluginVersionData SFSEPlugin_Version = {
		SFSEPluginVersionData::kVersion,
		1,
		"Unlimited Jetpack",
		"Florian Taute",
		0,
		1,
		{ RUNTIME_VERSION_1_7_23, 0 },
		0,
		0, 0,
	};

	void SFSEPlugin_Load(const SFSEInterface* sfse)
	{
		//BYTE MovZero[] = { 0x42, 0xC7, 0x04, 0xA6, 0x00, 0x00, 0x00, 0x00, 0x90, 0x90 }; // will also make grav jump instant
		//safeWriteBuf(boostCheckWithGravJump.getUIntPtr(), &MovZero, sizeof(MovZero)); // will also make grav jump instant

		BYTE Nop[] = { 0x90, 0x90, 0x90, 0x90 };
		safeWriteBuf(boostCalculation.getUIntPtr(), &Nop, sizeof(Nop));
	}
};
