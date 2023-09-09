#include "sfse_common/sfse_version.h"
#include "sfse/PluginAPI.h"
#include <ShlObj.h>  // CSIDL_MYDOCUMENTS
#include "sfse_common/Relocation.h"
#include "sfse_common/SafeWrite.h"

RelocAddr <uintptr_t*> boostCheck = 0x24EF80B;

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
		// overrides the boost cost mov operation at 0x24EF80B + 5 bytes with null operations
		// this way using the jetpack doesnt reduce the boost meter
		BYTE Nop[] = { 0x90, 0x90, 0x90, 0x90, 0x90, 0x90 };
		safeWriteBuf(boostCheck.getUIntPtr(), &Nop, sizeof(Nop));
	}
};
