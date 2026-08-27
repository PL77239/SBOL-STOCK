#pragma once
float* drawDistance[]{
	nullptr,
	(float*)0x005F405C, // Track draw distance
	(float*)0x005F3AEC, // Mirror draw distance
};

int* resWidth[]{
	nullptr,
	(int*)0x004122E6, // Window Width after start
	(int*)0x0041251B, // Window Width after start
	//(int*)0x004A68C5, // 3d window width in game
	(int*)0x005C1684, // Window Width on start
	
	// Other 3d windows
	/*
	(int*)0x00452CE1,
	(int*)0x00453E7E,
	(int*)0x00453F43,
	(int*)0x00455386,
	(int*)0x004571BC,
	(int*)0x00458C3F,
	(int*)0x004631A6,
	(int*)0x00464F2F,
	(int*)0x00480E60,
	(int*)0x00482014,
	(int*)0x004879B3,
	(int*)0x00490498,
	(int*)0x004ACC73,
	(int*)0x004B00D7,
	*/
};

float* resWidthF[]{
	nullptr,
	(float*)0x004E601D,
	//(float*)0x0045CEB0, // Item black back but using createUIElement
	//(float*)0x004BC492, // Garage black back
	(float*)0x00434957,
	(float*)0x0045A6FA,
	//(float*)0x0045B7CB, // Item box but using createUIElement
	(float*)0x00470C01,
	(float*)0x0048A257,
	(float*)0x0049C78C,
	(float*)0x0049D2C2,
	//(float*)0x004E2451, // ???
	//(float*)0x004E27AE, // ???
	//(float*)0x004E33BD, // ???
	//(float*)0x004E3478, // ???
	//(float*)0x004E34C5, // ???
	//(float*)0x004E34E3, // ???
	//(float*)0x004E3501, // ???
	//(float*)0x004E351F, // ???
	//(float*)0x004E353D, // ???
	//(float*)0x004E355B, // ???
	//(float*)0x004E3579, // ???
	//(float*)0x004E3597, // ???
	//(float*)0x004E35B5, // ???
	//(float*)0x004E35D3, // ???
	//(float*)0x004E35F1, // ???
	//(float*)0x004E360F, // ???
	//(float*)0x004E362D, // ???
	//(float*)0x004E364B, // ???
	//(float*)0x004E5F52, // ???
	//(float*)0x004E5FB3, // ???
	//(float*)0x004E6057, // ???
	//(float*)0x004F6C7C, // ???
};

int* resHeight[]{
	nullptr,
	(int*)0x004122F6, // Window Height after start
	(int*)0x00412524, // Window Height after start
	//(int*)0x004A68D0, // 3d window height in game
	(int*)0x005C1688, // Window Height on start

	// Other 3d windows
	/*
	(int*)0x00452CDC,
	(int*)0x00453E79,
	(int*)0x00453F3E,
	(int*)0x00455381,
	(int*)0x004571B7,
	(int*)0x00458C3A,
	(int*)0x004631A1,
	(int*)0x00464F2A,
	(int*)0x00480E5B,
	(int*)0x0048200F,
	(int*)0x004879A4,
	(int*)0x00490493,
	(int*)0x004ACC6E,
	(int*)0x004B00D2,
	*/
};

float* resHeightF[]{
	nullptr,
	//(float*)0x0045CEA5, // Item black back but using createUIElement
	//(float*)0x004BC487,	// Garage black back
	(float*)0x0043494C,
	(float*)0x0045A6F5,
	//(float*)0x0045B7C0, // Item box but using createUIElement
	(float*)0x00470BFC,
	(float*)0x0048A252,
	(float*)0x0049C787,
	(float*)0x0049D2BD,
};

int* centerJust[]{
	nullptr,
	(int*)0x004DC601,
	(int*)0x004DC9A4,
	(int*)0x004DC3D9, // Garage dialog
	(int*)0x00443688, // Quit dialog
	(int*)0x0042661B, // Error dialog
	(int*)0x004263B8, // Error text
};

int* centerJustV[]{
	nullptr,
	(int*)0x004DC3D4, // Garage dialog
	(int*)0x00443683, // Quit dialog
	(int*)0x00426623, // Error dialog
	(int*)0x004263B3, // Error text
};

int* rightJust[] {
	nullptr,
	(int*)0x004DBBF6,
	(int*)0x004DBDAB,
	(int*)0x004DB509,
	(int*)0x004DB515,
	(int*)0x004DB521,
};

int* bottomJust[]{
	nullptr,
	(int*)0x004DBCE9,
	(int*)0x004DB501,
	(int*)0x004D84D1,
	(int*)0x004D5CAD,
	(int*)0x004D5CFF,
	(int*)0x004D5D76,
	(int*)0x004D5DD4,
	(int*)0x004D5E23,
	(int*)0x004ABF7D,
	(int*)0x004DC60B,
	(int*)0x004DC9AB,
};

float* centerJustF[]{
	nullptr,
	(float*)0x004DC9D1,
};

float* rightJustF[]{
	nullptr,
	(float*)0x004DB217,
	(float*)0x004DB59F,
	(float*)0x004DB786,
	(float*)0x004DB82D,
	(float*)0x004DB939,
	(float*)0x004DB975,
	(float*)0x004DB9B1,
	(float*)0x005F36F8, // Tacho needle X
};

float* bottomJustF[]{
	nullptr,
	(float*)0x004DB212,
	(float*)0x004DB59A,
	(float*)0x004DB781,
	(float*)0x004DB828,
	
	(float*)0x004DBB16, // in course icon back box
	(float*)0x004DBB74,
	(float*)0x004D5BA3,
	(float*)0x004D5BF2,
	(float*)0x004D5C41, // Navi map back box (affected by tachno needle Y also)
	(float*)0x004DC9CC,
	
	(float*)0x004DB934,
	(float*)0x004DB970,
	(float*)0x004DB9AC,
	(float*)0x005F36F4, // Tacho needle Y
};

//int* repositionAddr[]{
//	(int*)(0x0043F75A), // Loading Screen
//	(int*)(0x0045CEBA), // Itembox
//};

ADJUSTFLOATS adjustFloatAddr[]{
	{ nullptr, nullptr, nullptr },
	{ &adjustfloatsNBR, (float*)0x005F36F8, (float*)0x005F36F4 }, // Tacho needle
	{ &adjustfloatsN, (float*)0x005F36F0, (float*)0x005F36EC }, // Tacho needle pivot point
	//{ &adjustfloatsN, (float*)0x004D68FF, (float*)0x004D690F }, // Car arrow on navimap pivot point - Not needed if viewport is being resized.
	{ adjustfloats43, (float*)0x005EEB2C, nullptr }, // Handle offsets related
	{ adjustfloats43, (float*)0x005EEB30, nullptr }, // Handle offsets related
	{ adjustfloats43, (float*)0x005EEB34, nullptr }, // Handle offsets related
	{ adjustfloats43, (float*)0x005EEB38, nullptr }, // Handle offsets related
	{ adjustfloats43, (float*)0x005EEB3C, nullptr }, // Handle offsets related
	{ adjustfloats43, (float*)0x005EEB40, nullptr }, // Handle offsets related
	{ adjustfloats43, (float*)0x005EEB44, nullptr }, // Handle offsets related
	{ adjustfloats43, (float*)0x005EEB48, nullptr }, // Handle offsets related
	{ adjustfloats43, (float*)0x005EEB4C, nullptr }, // Handle offsets related
	{ adjustfloats43, nullptr, (float*)0x005EEB50 }, // Handle offsets related
	{ adjustfloats43, nullptr, (float*)0x005EEB54 }, // Handle offsets related
	{ adjustfloats43, nullptr, (float*)0x005EEB58 }, // Handle offsets related
	{ adjustfloats43, nullptr, (float*)0x005EEB5C }, // Handle offsets related
	{ adjustfloats43, (float*)0x005EEB60, nullptr }, // Handle offsets related
	{ adjustfloats43, nullptr, (float*)0x005EEB64 }, // Handle offsets related
	{ adjustfloats43, nullptr, (float*)0x005EEB68 }, // Handle offsets related
	{ adjustfloats43, nullptr, (float*)0x005EEB6C }, // Handle offsets related
	{ adjustfloats43, nullptr, (float*)0x005EEB70 }, // Handle offsets related
	{ adjustfloats43, nullptr, (float*)0x005EEB74 }, // Handle offsets related
	{ adjustfloats43, nullptr, (float*)0x005EEB78 }, // Handle offsets related
};

ADJUSTINTS adjustIntAddr[]{
	{ nullptr, nullptr, nullptr },
	//{ &adjustintsN, (int*)0x00600900, (int*)0x00600904 }, // Tache needle size
	//{ &adjustints43, (int*)0x004E185B, (int*)0x004E1862 }, // Mirror size - dealt with in viewport function
	//{ &adjustints43Center, (int*)0x004E184D, (int*)0x004E1854 }, // Mirror position - dealt with in viewport function
	//{ &adjustbytesN, (int*)0x004D6A1D, (int*)0x004D6A20 }, // Car arrow offset (they are bytes). Not needed if viewport is being resized
};

/*
	The address point can be used to specify the bytes that need to be nop'd. By default 5 bytes are nop'd.
	Set 0x01 for 6 bytes, 0x02 for 7 and so on. This value is then masked out when processed;
	e.g.: 0x02412345 to nop 7 bytes.
	Setting 0xFF will just replace the function pointer at that address.
*/
REPLACEFUNCTION replaceFunctionAddr[]{
	// Create UI Element
	{ createUIElementObject, nullptr },
	{ createUIElementObject_43, (int*)0x004263C5 }, // Disconnect error string
	//{ createUIElementObject_43, (int*)0x00431529 },
	//{ createUIElementObject_43, (int*)0x00431532 },
	//{ createUIElementObject_43, (int*)0x00431540 },
	//{ createUIElementObject_43, (int*)0x00434C8F },
	//{ createUIElementObject_43, (int*)0x0043501A },
	//{ createUIElementObject_43, (int*)0x0043507F },
	//{ createUIElementObject_43, (int*)0x004350F1 },
	//{ createUIElementObject_43, (int*)0x0043513D },
	//{ createUIElementObject_43, (int*)0x00435517 },
	//{ createUIElementObject_43, (int*)0x0043556B },
	//{ createUIElementObject_43, (int*)0x004355BC },
	//{ createUIElementObject_43, (int*)0x0043560C },
	//{ createUIElementObject_43, (int*)0x004404A8 },
	//{ createUIElementObject_43, (int*)0x0044FEB9 },
	//{ createUIElementObject_43, (int*)0x0044FF1D },
	//{ createUIElementObject_43, (int*)0x00450342 },
	//{ createUIElementObject_43, (int*)0x0045038B },
	{ createUIElementObject_43, (int*)0x0045B705 }, // Itembox related
	{ createUIElementObject_43, (int*)0x0045B796 }, // Itembox related
	{ createUIElementObject_43, (int*)0x0045BEAD }, // Itembox text
	{ createUIElementObject_43, (int*)0x0045BF0A }, // Itembox text
	{ createUIElementObject_43, (int*)0x0045D225 }, // Itembox related most likely
	{ createUIElementObject_43, (int*)0x0045D27F }, // Itembox related most likely
	{ createUIElementObject_43, (int*)0x0045D672 }, // Itembox text
	{ createUIElementObject_43, (int*)0x0045D68D }, // Itembox text
	//{ createUIElementObject_43, (int*)0x00477C20 },
	//{ createUIElementObject_43, (int*)0x00478DE9 },
	//{ createUIElementObject_43, (int*)0x00485B1D },
	//{ createUIElementObject_43, (int*)0x00497355 },
	//{ createUIElementObject_43, (int*)0x0049B7F2 },
	//{ createUIElementObject_43, (int*)0x0049B851 },
	//{ createUIElementObject_43, (int*)0x0049CCF5 },
	//{ createUIElementObject_43, (int*)0x0049CD4F },
	//{ createUIElementObject_43, (int*)0x0049D795 },
	//{ createUIElementObject_43, (int*)0x0049D7EF },
	//{ createUIElementObject_43, (int*)0x0049E93D },
	//{ createUIElementObject_43, (int*)0x004A908D },
	//{ createUIElementObject_43, (int*)0x004A9433 },
	{ createUIElementObject_43, (int*)0x004AB4C0 }, // Reconnecting when swapping servers string
	{ createUIElementObject_Scale_Reposition_BottomLeft, (int*)0x004ABF85 }, // Course network string
	{ createUIElementObject_43, (int*)0x004BC43D }, // Enter garage dialog string
	//{ createUIElementObject_43, (int*)0x004BD725 },
	{ createUIElementObject_Scale_Reposition_BottomLeft, (int*)0x004D5CB5 }, // Persons in course
	{ createUIElementObject_Scale_Reposition_BottomLeft, (int*)0x004D5D07 }, // Course Name
	{ createUIElementObject_Scale_Reposition_BottomLeft, (int*)0x004D5D7E }, // LV CP String
	{ createUIElementObject_Scale_Reposition_BottomLeft, (int*)0x004D5DDC }, // Autorun String while in autopilot
	{ createUIElementObject_Scale_Reposition_BottomLeft, (int*)0x004D5E2B }, // Autorun String while not in autopilot
	{ createUIElementObject_Scale_Reposition_BottomRight, (int*)0x004D5F18 }, // Survival Strings
	//{ createUIElementObject_43, (int*)0x004D8D66 },
	{ createUIElementObject_43, (int*)0x004DC729 }, // Wrong way warning text
	{ createUIElementObject_43, (int*)0x004DE74D }, // Battle String Player Team
	{ createUIElementObject_43, (int*)0x004DE79B }, // Battle String Player Handle
	{ createUIElementObject_43, (int*)0x004DE7E9 }, // Battle String Rival Team
	{ createUIElementObject_43, (int*)0x004DE839 }, // Battle String Rival Handle
	//{ createUIElementObject_43, (int*)0x004DE8C1 },
	//{ createUIElementObject_43, (int*)0x004DE90E },
	{ createUIElementObject_AutoScale_43, (int*)0x004FBB54 }, // Addressbook textbox input
	//{ createUIElementObject_43, (int*)0x004FBB92 },
	//{ createUIElementObject_43, (int*)0x004FD1F4 },
	//{ createUIElementObject_43, (int*)0x004FD33F },
	{ createUIElementObject_43, (int*)0x004FD9EE }, // Chat log text
	//{ createUIElementObject_43, (int*)0x004FDA26 }, // Addressbook text box

	// Create UI
	{ createUIElement, nullptr },
	{ createUIElement_43, (int*)0x0042680E }, // Disconnect error dialog back and button.
	//{ createUIElement_43, (int*)0x00426899 }, // ???
	//{ createUIElement_43, (int*)0x00434968 }, // ???
	//{ createUIElement_43, (int*)0x00434A8E }, // ???
	//{ createUIElement_43, (int*)0x00434B5F }, // ???
	//{ createUIElement_43, (int*)0x00434CCB }, // ???
	//{ createUIElement_43, (int*)0x00434D1B }, // ???
	//{ createUIElement_43, (int*)0x00434DBB }, // ???
	//{ createUIElement_43, (int*)0x00434EA0 }, // ???
	//{ createUIElement_43, (int*)0x00434EEF }, // ???
	//{ createUIElement_43, (int*)0x00434F3E }, // ???
	//{ createUIElement_43, (int*)0x00435221 }, // ???
	//{ createUIElement_43, (int*)0x0043529E }, // ???
	//{ createUIElement_43, (int*)0x00435383 }, // ???
	//{ createUIElement_43, (int*)0x004353E1 }, // ???
	//{ createUIElement_43, (int*)0x00435427 }, // ???
	//{ createUIElement_43, (int*)0x00435468 }, // ???
	//{ createUIElement_43, (int*)0x004354AD }, // ???
	//{ createUIElement_43, (int*)0x00435644 }, // ???
	//{ createUIElement_43, (int*)0x00435693 }, // ???
	//{ createUIElement_43, (int*)0x004356E2 }, // ???
	//{ createUIElement_43, (int*)0x00435731 }, // ???
	//{ createUIElement_43, (int*)0x004357AF }, // ???
	//{ createUIElement_43, (int*)0x00438C95 }, // ???
	//{ createUIElement_43, (int*)0x00438CC1 }, // ???
	{ createUIElement_43, (int*)0x0043F75A }, // Loading Screen
	//{ createUIElement_43, (int*)0x0044070A }, // ???
	//{ createUIElement_43, (int*)0x00440792 }, // ???
	//{ createUIElement_43, (int*)0x0044F8BB }, // ???
	//{ createUIElement_43, (int*)0x0044FB99 }, // ???
	//{ createUIElement_43, (int*)0x0044FC6D }, // ???
	//{ createUIElement_43, (int*)0x0044FCE6 }, // ???
	//{ createUIElement_43, (int*)0x0044FD4F }, // ???
	//{ createUIElement_43, (int*)0x0044FE31 }, // ???
	//{ createUIElement_43, (int*)0x00450121 }, // ???
	//{ createUIElement_43, (int*)0x004501C7 }, // ???
	//{ createUIElement_43, (int*)0x00450574 }, // ???
	//{ createUIElement_43, (int*)0x004509BF }, // ???
	//{ createUIElement_43, (int*)0x00451547 }, // ???
	//{ createUIElement_43, (int*)0x00451683 }, // ???
	//{ createUIElement_43, (int*)0x00451791 }, // ???
	//{ createUIElement_43, (int*)0x0045189F }, // ???
	//{ createUIElement_43, (int*)0x0045195F }, // ???
	//{ createUIElement_43, (int*)0x004519EB }, // ???
	//{ createUIElement_43, (int*)0x00451A65 }, // ???
	//{ createUIElement_43, (int*)0x00451AE0 }, // ???
	//{ createUIElement_43, (int*)0x00451B3E }, // ???
	//{ createUIElement_43, (int*)0x00451BB8 }, // ???
	//{ createUIElement_43, (int*)0x00451C6F }, // ???
	//{ createUIElement_43, (int*)0x004521EA }, // ???
	//{ createUIElement_43, (int*)0x00452898 }, // ???
	//{ createUIElement_43, (int*)0x00452D81 }, // ???
	//{ createUIElement_43, (int*)0x004545E2 }, // ???
	//{ createUIElement_43, (int*)0x00454626 }, // ???
	//{ createUIElement_43, (int*)0x0045A719 }, // ???
	//{ createUIElement_43, (int*)0x0045A82D }, // ???
	//{ createUIElement_43, (int*)0x0045A9B3 }, // ???
	//{ createUIElement_43, (int*)0x0045AA2C }, // ???
	//{ createUIElement_43, (int*)0x0045AACF }, // ???
	//{ createUIElement_43, (int*)0x0045ABAF }, // ???
	//{ createUIElement_43, (int*)0x0045AFC1 }, // ???
	//{ createUIElement_43, (int*)0x0045B0B0 }, // ???
	{ createUIElement, (int*)0x0045B7D7 }, // Itembox dim game window box when using
	{ createUIElement_43, (int*)0x0045B8E7 }, // Itembox use/trash related
	{ createUIElement_43, (int*)0x0045BA5E }, // Itembox use/trash related
	{ createUIElement_43, (int*)0x0045BADA }, // Itembox use/trash related
	{ createUIElement_43, (int*)0x0045BBB8 }, // Itembox use/trash related
	{ createUIElement_43, (int*)0x0045BD30 }, // Itembox use/trash related
	{ createUIElement_43, (int*)0x0045BD83 }, // Itembox use/trash related
	{ createUIElement_43, (int*)0x0045C250 }, // Itembox use/trash related
	{ createUIElement_43, (int*)0x0045C359 }, // Itembox use/trash related
	{ createUIElement, (int*)0x0045CEBA }, // Itembox dim game window box
	{ createUIElement_43, (int*)0x0045D7F1 }, // Itembox related
	{ createUIElement_43, (int*)0x0045D8A0 }, // Itembox related
	{ createUIElement_43, (int*)0x0045D91A }, // Itembox related
	{ createUIElement_43, (int*)0x0045D9C5 }, // Itembox close button back
	{ createUIElement_43, (int*)0x0045DA41 }, // Itembox related
	{ createUIElement_43, (int*)0x0045DAE3 }, // Itembox related
	{ createUIElement_43, (int*)0x0045DBED }, // Itembox item button back
	{ createUIElement_43, (int*)0x0045DEEF }, // Itembox related
	{ createUIElement_43, (int*)0x0045E0B3 }, // Itembox related
	{ createUIElement_43, (int*)0x0045E21C }, // Itembox item button icon
	{ createUIElement_43, (int*)0x0045E307 }, // Itembox item button label
	{ createUIElement_43, (int*)0x0045F367 }, // Itembox close button text
	//{ createUIElement_43, (int*)0x0046F7AB }, // ???
	//{ createUIElement_43, (int*)0x0046F8A7 }, // ???
	//{ createUIElement_43, (int*)0x0046F9D1 }, // ???
	//{ createUIElement_43, (int*)0x0046FF20 }, // ???
	//{ createUIElement_43, (int*)0x00470056 }, // ???
	//{ createUIElement_43, (int*)0x00470197 }, // ???
	//{ createUIElement_43, (int*)0x0047023C }, // ???
	//{ createUIElement_43, (int*)0x00470C20 }, // ???
	//{ createUIElement_43, (int*)0x00470D43 }, // ???
	//{ createUIElement_43, (int*)0x00470DE0 }, // ???
	//{ createUIElement_43, (int*)0x00470EBF }, // ???
	//{ createUIElement_43, (int*)0x00470FA5 }, // ???
	//{ createUIElement_43, (int*)0x004710B6 }, // ???
	//{ createUIElement_43, (int*)0x004711B1 }, // ???
	//{ createUIElement_43, (int*)0x00471265 }, // ???
	//{ createUIElement_43, (int*)0x004712FA }, // ???
	//{ createUIElement_43, (int*)0x00471363 }, // ???
	//{ createUIElement_43, (int*)0x00471406 }, // ???
	//{ createUIElement_43, (int*)0x004714D3 }, // ???
	//{ createUIElement_43, (int*)0x0047154B }, // ???
	//{ createUIElement_43, (int*)0x004715B5 }, // ???
	//{ createUIElement_43, (int*)0x0047161E }, // ???
	//{ createUIElement_43, (int*)0x00471687 }, // ???
	//{ createUIElement_43, (int*)0x0047548C }, // ???
	//{ createUIElement_43, (int*)0x00475A4C }, // ???
	//{ createUIElement_43, (int*)0x00475AB7 }, // ???
	//{ createUIElement_43, (int*)0x00475B81 }, // ???
	//{ createUIElement_43, (int*)0x00475C42 }, // ???
	//{ createUIElement_43, (int*)0x00475D0F }, // ???
	//{ createUIElement_43, (int*)0x00475DBD }, // ???
	//{ createUIElement_43, (int*)0x00477847 }, // ???
	//{ createUIElement_43, (int*)0x004778BF }, // ???
	//{ createUIElement_43, (int*)0x00477962 }, // ???
	//{ createUIElement_43, (int*)0x00477A07 }, // ???
	//{ createUIElement_43, (int*)0x00477AC4 }, // ???
	//{ createUIElement_43, (int*)0x00477B93 }, // ???
	//{ createUIElement_43, (int*)0x00478A99 }, // ???
	//{ createUIElement_43, (int*)0x00478B2A }, // ???
	//{ createUIElement_43, (int*)0x00478BD1 }, // ???
	//{ createUIElement_43, (int*)0x00478D5C }, // ???
	//{ createUIElement_43, (int*)0x00478E90 }, // ???
	//{ createUIElement_43, (int*)0x0047A5A0 }, // ???
	//{ createUIElement_43, (int*)0x0047A648 }, // ???
	//{ createUIElement_43, (int*)0x0047A6FB }, // ???
	//{ createUIElement_43, (int*)0x0047A8B6 }, // ???
	//{ createUIElement_43, (int*)0x0047B3C2 }, // ???
	//{ createUIElement_43, (int*)0x0047B4AA }, // ???
	//{ createUIElement_43, (int*)0x0047B5B5 }, // ???
	//{ createUIElement_43, (int*)0x0047B656 }, // ???
	//{ createUIElement_43, (int*)0x0047E02C }, // ???
	//{ createUIElement_43, (int*)0x0047E0C5 }, // ???
	//{ createUIElement_43, (int*)0x0047E16D }, // ???
	//{ createUIElement_43, (int*)0x0047E29F }, // ???
	//{ createUIElement_43, (int*)0x004848E8 }, // ???
	//{ createUIElement_43, (int*)0x00484A1D }, // ???
	//{ createUIElement_43, (int*)0x00484B55 }, // ???
	//{ createUIElement_43, (int*)0x00484C88 }, // ???
	//{ createUIElement_43, (int*)0x00484DDA }, // ???
	//{ createUIElement_43, (int*)0x00484EC5 }, // ???
	//{ createUIElement_43, (int*)0x00484FAE }, // ???
	//{ createUIElement_43, (int*)0x0048501C }, // ???
	//{ createUIElement_43, (int*)0x00485189 }, // ???
	//{ createUIElement_43, (int*)0x004851D1 }, // ???
	//{ createUIElement_43, (int*)0x00485A58 }, // ???
	//{ createUIElement_43, (int*)0x00485B9C }, // ???
	//{ createUIElement_43, (int*)0x004869BA }, // ???
	//{ createUIElement_43, (int*)0x00486CBC }, // ???
	//{ createUIElement_43, (int*)0x00486D72 }, // ???
	//{ createUIElement_43, (int*)0x004880AF }, // ???
	//{ createUIElement_43, (int*)0x00488ABD }, // ???
	//{ createUIElement_43, (int*)0x004895A5 }, // ???
	//{ createUIElement_43, (int*)0x00489642 }, // ???
	//{ createUIElement_43, (int*)0x004896F3 }, // ???
	//{ createUIElement_43, (int*)0x00489824 }, // ???
	//{ createUIElement_43, (int*)0x0048A27C }, // ???
	//{ createUIElement_43, (int*)0x0048A3A2 }, // ???
	//{ createUIElement_43, (int*)0x0048A461 }, // ???
	//{ createUIElement_43, (int*)0x0048A55B }, // ???
	//{ createUIElement_43, (int*)0x0048A601 }, // ???
	//{ createUIElement_43, (int*)0x0048A6B0 }, // ???
	//{ createUIElement_43, (int*)0x0048A78C }, // ???
	//{ createUIElement_43, (int*)0x0048B87F }, // ???
	//{ createUIElement_43, (int*)0x0048B96B }, // ???
	//{ createUIElement_43, (int*)0x0048BE71 }, // ???
	//{ createUIElement_43, (int*)0x0048BEF8 }, // ???
	//{ createUIElement_43, (int*)0x0048BF9E }, // ???
	//{ createUIElement_43, (int*)0x0048C090 }, // ???
	{ createUIElement_43, (int*)0x0048C98C }, // Battle win/lose texture
	{ createUIElement_43, (int*)0x0048C9F7 }, // Battle win/lose texture
	{ createUIElement_43, (int*)0x0048CF3F }, // Battle Result Value Labels
	{ createUIElement_43, (int*)0x0048D1A4 }, // Battle Result Value Labels
	{ createUIElement_43, (int*)0x0048D2B9 }, // Battle Result Value Labels	
	{ createUIElement_43, (int*)0x0048D696 }, // Battle Exp Percent Bar
	{ createUIElement_43, (int*)0x0048D9AF }, // Battle Something probably so will leave it enabled
	{ createUIElement_43, (int*)0x0048DAEA }, // Battle Something probably so will leave it enabled
	{ createUIElement_43, (int*)0x0048DBB5 }, // Battle Something probably so will leave it enabled
	{ createUIElement_43, (int*)0x0048DEF3 }, // Battle Reward Item
	{ createUIElement_43, (int*)0x0048DF7E }, // Battle Reward Item
	{ createUIElement_43, (int*)0x0048E31E }, // Battle Result Dialog 
	//{ createUIElement_43, (int*)0x004972B1 }, // ???
	//{ createUIElement_43, (int*)0x004984C1 }, // ???
	//{ createUIElement_43, (int*)0x0049932E }, // ???
	//{ createUIElement_43, (int*)0x0049957A }, // ???
	//{ createUIElement_43, (int*)0x0049A119 }, // ???
	//{ createUIElement_43, (int*)0x0049A258 }, // ???
	//{ createUIElement_43, (int*)0x0049A3C3 }, // ???
	//{ createUIElement_43, (int*)0x0049A463 }, // ???
	//{ createUIElement_43, (int*)0x0049B3FD }, // ???
	//{ createUIElement_43, (int*)0x0049B590 }, // ???
	//{ createUIElement_43, (int*)0x0049B6D1 }, // ???
	//{ createUIElement_43, (int*)0x0049B942 }, // ???
	//{ createUIElement_43, (int*)0x0049B9B7 }, // ???
	//{ createUIElement_43, (int*)0x0049C7AB }, // ???
	//{ createUIElement_43, (int*)0x0049C8CE }, // ???
	//{ createUIElement_43, (int*)0x0049C9D6 }, // ???
	//{ createUIElement_43, (int*)0x0049CAF7 }, // ???
	//{ createUIElement_43, (int*)0x0049CBA2 }, // ???
	//{ createUIElement_43, (int*)0x0049CC59 }, // ???
	//{ createUIElement_43, (int*)0x0049D2E1 }, // ???
	//{ createUIElement_43, (int*)0x0049D404 }, // ???
	//{ createUIElement_43, (int*)0x0049D518 }, // ???
	//{ createUIElement_43, (int*)0x0049D666 }, // ???
	//{ createUIElement_43, (int*)0x0049D6F3 }, // ???
	//{ createUIElement_43, (int*)0x0049DE4E }, // ???
	//{ createUIElement_43, (int*)0x0049DF4F }, // ???
	//{ createUIElement_43, (int*)0x0049E064 }, // ???
	//{ createUIElement_43, (int*)0x0049E108 }, // ???
	//{ createUIElement_43, (int*)0x0049E705 }, // ???
	//{ createUIElement_43, (int*)0x0049E84D }, // ???
	//{ createUIElement_43, (int*)0x0049E9C9 }, // ???
	//{ createUIElement_43, (int*)0x0049EA41 }, // ???
	//{ createUIElement_43, (int*)0x0049EAB8 }, // ???
	//{ createUIElement_43, (int*)0x0049EB2C }, // ???
	//{ createUIElement_43, (int*)0x0049EBE4 }, // ???
	//{ createUIElement_43, (int*)0x0049F44B }, // ???
	//{ createUIElement_43, (int*)0x0049F536 }, // ???
	//{ createUIElement_43, (int*)0x0049F61F }, // ???
	//{ createUIElement_43, (int*)0x0049FC4C }, // ???
	//{ createUIElement_43, (int*)0x0049FD33 }, // ???
	//{ createUIElement_43, (int*)0x0049FDEB }, // ???
	//{ createUIElement_43, (int*)0x0049FF37 }, // ???
	//{ createUIElement_43, (int*)0x0049FF9C }, // ???
	//{ createUIElement_43, (int*)0x004A00DB }, // ???
	//{ createUIElement_43, (int*)0x004A0149 }, // ???
	//{ createUIElement_43, (int*)0x004A02C0 }, // ???
	//{ createUIElement_43, (int*)0x004A034C }, // ???
	//{ createUIElement_43, (int*)0x004A03FB }, // ???
	//{ createUIElement_43, (int*)0x004A0DAF }, // ???
	//{ createUIElement_43, (int*)0x004A0E94 }, // ???
	//{ createUIElement_43, (int*)0x004A0F77 }, // ???
	//{ createUIElement_43, (int*)0x004A1094 }, // ???
	//{ createUIElement_43, (int*)0x004A1912 }, // ???
	//{ createUIElement_43, (int*)0x004A1BE7 }, // ???
	//{ createUIElement_43, (int*)0x004A1C60 }, // ???
	//{ createUIElement_43, (int*)0x004A1DC6 }, // ???
	//{ createUIElement_43, (int*)0x004A1E39 }, // ???
	//{ createUIElement_43, (int*)0x004A1EB7 }, // ???
	//{ createUIElement_43, (int*)0x004A1F9E }, // ???
	//{ createUIElement_43, (int*)0x004A2043 }, // ???
	//{ createUIElement_43, (int*)0x004A9017 }, // ???
	//{ createUIElement_43, (int*)0x004A9618 }, // ???
	//{ createUIElement_43, (int*)0x004A968B }, // ???
	//{ createUIElement_43, (int*)0x004A970F }, // ???
	//{ createUIElement_43, (int*)0x004A9A05 }, // ???
	{ createUIElement_43, (int*)0x004AA269 }, // Battle end text
	{ createUIElement_43, (int*)0x004AA296 }, // Battle end related
	{ createUIElement_43, (int*)0x004AA327 }, // Battle end related
	{ createUIElement_43, (int*)0x004AA358 }, // Battle end related
	//{ createUIElement_43, (int*)0x004AA5A8 }, // ???
	//{ createUIElement_43, (int*)0x004AA5D5 }, // ???
	//{ createUIElement_43, (int*)0x004AA646 }, // ???
	//{ createUIElement_43, (int*)0x004AA687 }, // ???
	{ createUIElement_43, (int*)0x004AA7CF }, // Battle end + symbols
	//{ createUIElement_43, (int*)0x004AB082 }, // ???
	{ createUIElement_43, (int*)0x004AB450 }, // Reconnect strings
	//{ createUIElement_43, (int*)0x004ADFD8 }, // ???
	//{ createUIElement_43, (int*)0x004AE08E }, // ???
	//{ createUIElement_43, (int*)0x004B16D7 }, // ???
	//{ createUIElement_43, (int*)0x004B180F }, // ???
	//{ createUIElement_43, (int*)0x004B196B }, // ???
	//{ createUIElement_43, (int*)0x004B1AA0 }, // ???
	//{ createUIElement_43, (int*)0x004B1BE6 }, // ???
	//{ createUIElement_43, (int*)0x004B1D55 }, // ???
	//{ createUIElement_43, (int*)0x004B1EBB }, // ???
	//{ createUIElement_43, (int*)0x004B201C }, // ???
	//{ createUIElement_43, (int*)0x004B2150 }, // ???
	//{ createUIElement_43, (int*)0x004B2284 }, // ???
	//{ createUIElement_43, (int*)0x004B24EC }, // ???
	//{ createUIElement_43, (int*)0x004B2697 }, // ???
	//{ createUIElement_43, (int*)0x004B27E8 }, // ???
	//{ createUIElement_43, (int*)0x004B2972 }, // ???
	//{ createUIElement_43, (int*)0x004B2ABA }, // ???
	//{ createUIElement_43, (int*)0x004B2BEE }, // ???
	//{ createUIElement_43, (int*)0x004B553D }, // ???
	{ createUIElement, (int*)0x004BC49E }, // Enter garage back black box
	{ createUIElement_43, (int*)0x004BC5B2 }, // Enter garage dialog back
	{ createUIElement_43, (int*)0x004BC642 }, // Enter garage OK button
	{ createUIElement_43, (int*)0x004BC6D7 }, // Enter garage CANCEL button
	//{ createUIElement, (int*)0x004BD197 }, // ???
	//{ createUIElement, (int*)0x004BD39B }, // ???
	{ createUIElement_43, (int*)0x004BF8D3 }, // Warning screen
	{ createUIElement_43, (int*)0x004C1F3B }, // Mirror frame top
	{ createUIElement_43, (int*)0x004C1F5C }, // Mirror frame bottom
	{ createUIElement_43, (int*)0x004C1F7D }, // Mirror frame left
	{ createUIElement_43, (int*)0x004C1FA2 }, // Mirror frame right
	{ createUIElement_AutoScale_Handle, (int*)0x004C3152 }, // Handle string above player car
	{ createUIElement_AutoScale_TeamName, (int*)0x004C31D1 }, // Team name above handle box
	{ createUIElement_AutoScale_43, (int*)0x004C3231 }, // Box around player handle
	{ createUIElement_AutoScale_43, (int*)0x004C3284 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C32D7 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C332E }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C337B }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C33C8 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3417 }, // Safemode above player car
	{ createUIElement_AutoScale_43, (int*)0x004C3470 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3554 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C363F }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C36BC }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3735 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3798 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3811 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3874 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C38D7 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3954 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C39B7 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3A1A }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3A7D }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3AF0 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3B53 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3BB6 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3C19 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3C97 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3D13 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3D76 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3DF2 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3E55 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3EB8 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3F38 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3F9B }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C3FFE }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C4061 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C40D7 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C413A }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C419D }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C4200 }, // Handle box related
	{ createUIElement_AutoScale_43, (int*)0x004C4263 }, // Handle box related
	//{ createUIElement_Scale_Reposition_BottomLeft, (int*)0x004D2D1A }, // ???
	//{ createUIElement_Scale_Reposition_BottomLeft, (int*)0x004D59A7 }, // ???
	//{ createUIElement_Scale_Reposition_BottomLeft, (int*)0x004D59E8 }, // ???
	//{ createUIElement_Scale, (int*)0x004D5A11 }, // car arrows on navimap (rival and player) - Position is centered in navimap so no point trying to move it. Not needed if resizing viewport.
	//{ createUIElement_Scale_Reposition_BottomLeft, (int*)0x004D5AF2 }, // ???
	//{ createUIElement_Scale_Reposition_BottomLeft, (int*)0x004D5B3B }, // ???
	//{ createUIElement_Scale_Reposition_BottomLeft, (int*)0x004D5B7B }, // ???
	{ createUIElement_Scale_Reposition_BottomLeft, (int*)0x004D5BAC }, // "NORMAL MAP" above navi box
	{ createUIElement_Scale_Reposition_BottomLeft, (int*)0x004D5BFB }, // "WIDE MAP" above navi box
	{ createUIElement_Scale_Reposition_BottomLeft, (int*)0x004D5C4A }, // navimap box
	//{ createUIElement, (int*)0x004D5E9B }, // ???
	//{ createUIElement_Scale, (int*)0x004D8842 }, // Naimap road
	//{ createUIElement, (int*)0x004D8DCF }, // ???
	//{ createUIElement, (int*)0x004D8E11 }, // ???
	{ createUIElement_Scale_Reposition_BottomRight, (int*)0x004DB21B }, // Tacho guage back
	{ createUIElement_Scale_Reposition_TopLeft, (int*)0x004DB25D }, // Tacho needle
	{ createUIElement_Scale_Reposition_BottomRight, (int*)0x004DB55E }, // Digital speed
	{ createUIElement_Scale_Reposition_BottomRight, (int*)0x004DB5A3 }, // "kmph" next to speed
	{ createUIElement_Scale_Reposition_BottomRight, (int*)0x004DB78A }, // "assist" above "kmph"
	{ createUIElement_Scale_Reposition_BottomRight, (int*)0x004DB831 }, // gear indicator
	{ createUIElement_Scale_Reposition_BottomRight, (int*)0x004DB93D }, // Item active icon in bottom right
	{ createUIElement_Scale_Reposition_BottomRight, (int*)0x004DB979 }, // Item active icon in bottom right 
	{ createUIElement_Scale_Reposition_BottomRight, (int*)0x004DB9B5 }, // Item active icon in bottom right 
	{ createUIElement_Scale_Reposition_BottomLeft, (int*)0x004DBB2B }, // Icon backing
	{ createUIElement_Scale_Reposition_BottomLeft, (int*)0x004DBB8C }, // Icon
	//{ createUIElement, (int*)0x004DBD3D }, // Linked to bottom right buttons
	//{ createUIElement, (int*)0x004DBD62 }, // Linked to bottom right buttons
	//{ createUIElement, (int*)0x004DBE40 }, // ???
	//{ createUIElement, (int*)0x004DBE8F }, // ???
	{ createUIElement_43, (int*)0x004DC6AD }, // Wrong way dialog window (without text)
	{ createUIElement_43, (int*)0x004DC9D5 }, // Course information dialog left backing that appears when you approach a junction
	{ createUIElement_43, (int*)0x004DCA3E }, // Course information dialog right backing that appears when you approach a junction
	{ createUIElement_43, (int*)0x004DD09D }, // Course information dialog foreground that appears when you approach a junction
	{ createUIElement_43, (int*)0x004DD114 }, // Course information dialog related
	{ createUIElement_43, (int*)0x004DD18B }, // Course information dialog related
	{ createUIElement_43, (int*)0x004DD250 }, // Course information dialog related
	{ createUIElement_43, (int*)0x004DD2DF }, // Course information dialog related
	{ createUIElement_43, (int*)0x004DD385 }, // Course information dialog related
	{ createUIElement_43, (int*)0x004DD3FC }, // Course information dialog related
	{ createUIElement_43, (int*)0x004DD473 }, // Course information dialog related
	{ createUIElement_43, (int*)0x004DD5AA }, // Course information dialog related
	{ createUIElement_43, (int*)0x004DD61E }, // Course information dialog related
	{ createUIElement_43, (int*)0x004DDF41 }, // Course information dialog rival direction
	{ createUIElement_43, (int*)0x004DE45C }, // Battle related
	{ createUIElement_43, (int*)0x004DE4A2 }, // Battle related
	{ createUIElement_43, (int*)0x004DE4EE }, // Battle related
	{ createUIElement_43, (int*)0x004DE5C6 }, // Battle related
	{ createUIElement_43, (int*)0x004DE68F }, // Battle related
	{ createUIElement_43, (int*)0x004DE6EC }, // Battle related
	{ createUIElement_43, (int*)0x004DF110 }, // Battle related
	{ createUIElement_43, (int*)0x004DF15D }, // Battle related
	{ createUIElement_43, (int*)0x004DF2EE }, // Battle related
	{ createUIElement_43, (int*)0x004DF3B9 }, // Battle related
	{ createUIElement_43, (int*)0x004DF41C }, // Battle related
	{ createUIElement_43, (int*)0x004DF74E }, // Battle related
	{ createUIElement_43, (int*)0x004DF94B }, // Battle cancel
	//{ createUIElement, (int*)0x004E075B }, // ???
	//{ createUIElement_Scale, (int*)0x004E07A2 }, // Car arrows on navimap - Not needed when viewport is resized
	//{ createUIElement_Scale, (int*)0x004E07A2 }, // Car arrows on navimap - Not needed when viewport is resized
	//{ createUIElement, (int*)0x004E0883 }, // ??? 
	//{ createUIElement, (int*)0x004E08CC }, // ???
	//{ createUIElement, (int*)0x004E090C }, // ???
	//{ createUIElement_Scale_Reposition_TopLeft, (int*)0x004F4A27 }, // Addressbook and bottom right buttons scale - Handled by interactionUIElement
	{ createUIElement_43, (int*)0x004F501E }, // Chatbox back right side
	{ createUIElement_43, (int*)0x004F504A }, // Chatbox back left side
	{ createUIElement_43, (int*)0x004F6C8A }, // Chatbox backing
	{ createUIElement_43, (int*)0x004F6CB9 }, // Addressbook backing
	//{ createUIElement, (int*)0x004F8084 }, // ???
	//{ createUIElement, (int*)0x004F809F }, // ???
	{ createUIElement_43, (int*)0x004F8311 }, // Chat hide button when in shops
	{ createUIElement_43, (int*)0x004F8349 }, // Addressbook textbox back while in shops
	//{ createUIElement, (int*)0x004F866F }, // ???
	//{ createUIElement, (int*)0x004F868E }, // ???
	//{ createUIElement, (int*)0x004F875F }, // ???
	//{ createUIElement, (int*)0x004F8777 }, // ???
	//{ createUIElement, (int*)0x004F8828 }, // ???
	//{ createUIElement, (int*)0x004F8840 }, // ???
	{ createUIElement_43, (int*)0x004F8AD9 }, // Chat window label when chat hidden
	{ createUIElement_43, (int*)0x004F8B08 }, // Addressbook input textbox back
	{ createUIElement_43, (int*)0x004FB0D2 }, // In Create UI String
	{ createUIElement_43, (int*)0x004FB10C }, // In Create UI String
	{ createUIElement_43, (int*)0x004FB1D3 }, // In Create UI String
	{ createUIElement_43, (int*)0x004FB217 }, // In Create UI String
	//{ createUIElement, (int*)0x004FB8C4 }, // Textbox carat
	//{ createUIElement, (int*)0x004FB92B }, // ???
	//{ createUIElement, (int*)0x004FC163 }, // ???
	//{ createUIElement, (int*)0x004FC17C }, // ???
	//{ createUIElement, (int*)0x004FC195 }, // ???
	//{ createUIElement, (int*)0x004FC1AE }, // ???
	//{ createUIElement, (int*)0x004FC1C7 }, // ???
	//{ createUIElement, (int*)0x004FC8A9 }, // ???
	//{ createUIElement, (int*)0x004FC8C8 }, // ???
	//{ createUIElement, (int*)0x004FC9CD }, // ???
	//{ createUIElement, (int*)0x004FC9EC }, // ???
	//{ createUIElement, (int*)0x004FCA8B }, // ???
	//{ createUIElement, (int*)0x004FCAAA }, // ???
	//{ createUIElement, (int*)0x004FCB28 }, // ???
	{ createUIElement_43, (int*)0x004FCBD3 }, // Chat and addressbook scrollbar back
	//{ createUIElement_43, (int*)0x004FCE24 }, // ???
	//{ createUIElement_43, (int*)0x004FCE3D }, // ???
	//{ createUIElement, (int*)0x004FD7CB }, // createUIElementObject (Textboxes affected)
	//{ createUIElement_AutoScale_43, (int*)0x004FD951 }, // ???
	{ createUIElement_AutoScale_43, (int*)0x004FD9BA }, // Addressbook selection
	{ createUIElement_AutoScale_43, (int*)0x004FDAE5 }, // In setUIElement - Needed for addressbook add textbox flashing backing.
	
	// Position UI
	{ nullptr, nullptr },
	//{ positionUIElement_Reposition_43, (int*)0x004546FA }, // ???
	{ positionUIElement_Reposition_43, (int*)0x0045F547 }, // Reward item back (itembox)
	{ positionUIElement_Reposition_43, (int*)0x0045F6C8 }, // Garage itembox related
	//{ positionUIElement_Reposition_43, (int*)0x004755E6 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004756CF }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x0047575B }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x00475835 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x00492EE9 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004A93FF }, // ???
	{ positionUIElement_Reposition_43, (int*)0x004A9B9F }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F4A59 }, // All chat area buttons Handled by MoveUIElement
	//{ positionUIElement_Reposition_43, (int*)0x004F81DD }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F81F0 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F8240 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F8256 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F828D }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F82A3 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F893D }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F8950 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F89A5 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F89BB }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F89FA }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F8A10 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F8A47 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F8A5D }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F8A94 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004F8AAA }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004FC914 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004FC92B }, // ???
	{ positionUIElement_Reposition_43, (int*)0x004FCB80 }, // Chat addressbook scrollbar
	{ positionUIElement_Reposition_43, (int*)0x004FCB93 }, // Chat addressbook scrollbar
	//{ positionUIElement_Reposition_43, (int*)0x004FCC21 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004FCC30 }, // ???
	//{ positionUIElement_Reposition_43, (int*)0x004FDB06 }, // In setUIElement
	
	// Interaction UI
	{ nullptr, nullptr },
	{ interactionUIElement_43, (int*)0x004FCDDF }, // Chat scrollbars
	{ interactionUIElement_43, (int*)0x004FCA5C }, // ???
	{ interactionUIElement_43, (int*)0x004FC99E }, // Srollbar down buttons
	{ interactionUIElement_43, (int*)0x004FC87A }, // Scrollbar up buttons
	{ interactionUIElement_43, (int*)0x004F87FC }, // Chatbox minimize button
	{ interactionUIElement_43, (int*)0x004F8733 }, // Chatbox maximize button
	{ interactionUIElement_43, (int*)0x004F8640 }, // Chat type buttons
	{ interactionUIElement_43, (int*)0x004F8056 }, // ???
	{ interactionUIElement_Scale_Reposition_BottomRight, (int*)0x004DBD00 }, // Buttom right buttons
	
	// Move UI
	{ nullptr, nullptr },
	{ moveUIElement_43, (int*)0x004F81B6 }, // Chat type buttons
	{ moveUIElement_43, (int*)0x004F822A }, // Chat
	{ moveUIElement_43, (int*)0x004F8277 }, // Chat
	{ moveUIElement_43, (int*)0x004F8916 }, // Chat type buttons
	{ moveUIElement_43, (int*)0x004F898A }, // Chat
	{ moveUIElement_43, (int*)0x004F89E4 }, // Chat
	{ moveUIElement_43, (int*)0x004F8A31 }, // Chat
	{ moveUIElement_43, (int*)0x004F8A7E }, // Chat
	{ moveUIElement_43, (int*)0x004FC8ED }, // Chat
	{ moveUIElement_43, (int*)0x004FCB59 }, // Chat addressbook scrollbar button up
	{ moveUIElement_43, (int*)0x004FCC06 }, // Chat addressbook scrollbar button down

	// Position UI
	//{ positionInteractionUI, (int*)0x004F4A3F }, // Move UI
	{ positionInteractionUI, (int*)0x004FD9E5 }, // Chat history

	// Place UI
	//{ placeUIElement, (int*)0x00416DD6 }, // Car shadows in garage
	//{ placeUIElement, (int*)0x0045862D }, // Car shadows in garage
	//{ placeUIElement, (int*)0x00458822 }, // Car shadows in garage
	
	// Textbox
	{ nullptr, nullptr },
	{ createTextbox_43, (int*)0x0041714A }, // Login screen
	//{ createTextbox, (int*)0x004758C6 }, // ???
	//{ createTextbox, (int*)0x00476040 }, // ???
	//{ createTextbox, (int*)0x004760B9 }, // ???
	//{ createTextbox, (int*)0x0047A7CE }, // ???
	{ createTextbox_43, (int*)0x004F4FC4 }, // Chatbox
	{ createTextbox_43, (int*)0x004F52AE }, // Chatbox after chat
	//{ createTextbox_43, (int*)0x004F9561 }, // Addressbook add
	
	// Textbox carat
	{ nullptr, nullptr },
	{ createTextboxCarat, (int*)0x004FB48C }, //
	{ createTextboxCarat, (int*)0x004FB652 }, //
	{ createTextboxCarat, (int*)0x004FB733 }, //
	{ createTextboxCarat, (int*)0x004FBD16 }, // Login screen and chatbox and addressbook add
	{ createTextboxCarat, (int*)0x004FBF39 }, //
	{ createTextboxCarat, (int*)0x004FC0A5 }, //
	
	// Addressbook
	{ nullptr, nullptr },
	{ addressbookArea, (int*)0x004F6C31 },
	{ addressbookArea, (int*)0x004F94BE },
	{ addAddressbookEntry, (int*)0x004FCC53 },
	//{ addAddressbookEntry, (int*)0xFF4FCC81 },
	{ addAddressbookEntry, (int*)0x004FCCB0 },
	{ addAddressbookEntry, (int*)0x004FCCD4 },
	{ addAddressbookEntry, (int*)0x004FCD13 },
	{ addAddressbookEntry, (int*)0x004FCD33 },
	
	// SWF
	{ nullptr, nullptr },
	{ SwfMatrixConstruct_Centered, (int*)0x00512306 }, // Menu UIs
	{ SwfMatrixConstruct_Centered, (int*)0x00512468 }, // Black boxes
	{ SwfDrawPrimitive, (int*)0x015125BB },
	{ SwfDrawPrimitive, (int*)0x0151264B },
	{ SwfGetMouseState, (int*)0xFF60537C },

	// Misc
	{ ButtonInteract43, (int*)0x00493086 },
	{ ButtonInteract43, (int*)0x00493406 },
	{ ButtonInteract43, (int*)0x0049361B },
	{ ButtonInteract43, (int*)0x00493B5B },
	{ ButtonInteract43, (int*)0x004940BC },
	{ ButtonInteract43, (int*)0x00494189 },
	{ ButtonInteract43_Object, (int*)0x0043AFAA },
	{ gameCreateRectRgn, (int*)0x004FB302 },
	//{ setRect1, (int*)0x004FDf2E },
	//{ setRect1, (int*)0x004FDf45 },		
	//{ setRect2, (int*)0x0051DA8C },
	//{ setRect2, (int*)0x0051DAC2 },
	{ colourUIElement, (int*)0x004C3182 }, // Handle string colour above the car
	//{ colourUIElement, (int*)0x004C31E2 }, // Team name colour above the car
	//{ colourUIElement, (int*)0x004C323B }, //
	//{ colourUIElement, (int*)0x004c328e }, //
	//{ colourUIElement, (int*)0x004c32e1 }, //
	//{ colourUIElement, (int*)0x004c3421 }, //
	//{ colourUIElement, (int*)0x004c347a }, //
	//{ colourUIElement, (int*)0x004c355e }, //
	//{ colourUIElement, (int*)0x004c3649 }, //
	//{ colourUIElement, (int*)0x004c3ca1 }, //
	//{ colourUIElement, (int*)0x004c3d1d }, //
	//{ colourUIElement, (int*)0x004c3d80 }, //
	//{ colourUIElement, (int*)0x004c3dfc }, //
	//{ colourUIElement, (int*)0x004c3e5f }, //
	//{ colourUIElement, (int*)0x004c3ec2 }, //
	//{ colourUIElement, (int*)0x004c3ec2 }, //
	//{ colourUIElement, (int*)0x004c3f42 }, //
	//{ colourUIElement, (int*)0x004c3fa5 }, //
	//{ colourUIElement, (int*)0x004c4008 }, //
	//{ colourUIElement, (int*)0x004c406b }, //
	//{ colourUIElement, (int*)0x004c40e1 }, //
	//{ colourUIElement, (int*)0x004c4144 }, //
	//{ colourUIElement, (int*)0x004c41a7 }, //
	//{ colourUIElement, (int*)0x004c420a }, //
	//{ colourUIElement, (int*)0x004c426d }, //


	// Direct X
	{ SetViewport_Scale_Centered, (int*)0x004A625B }, // ???
	{ SetViewport_Scale_Centered, (int*)0x004A68EA }, // Window
	{ SetViewport_Scale_Reposition_BottomLeft, (int*)0x004D8501 }, // Navimap
	{ SetViewport_Scale_Centered, (int*)0x004D8E6D }, // places main window in navimap :S
	{ SetViewport_Scale_Centered, (int*)0x004E0DB8 }, // ???
	{ SetViewport_Scale_Centered1, (int*)0x004E1C08 }, // Rearview mirror
	{ SetViewport_Scale_Centered, (int*)0x004E1E15 }, // ???
	{ SetViewport_Scale_Centered, (int*)0x004E920F }, // ???
	{ SetViewport_Scale_Centered, (int*)0x004E937A }, // ???
	//{ endScene, (int*)0x0941BEAA }, // End scene (Top layer)
	{ endScene, (int*)0x094C769C }, // End scene (under loading)
	{ endScene, (int*)0x044C8A10 }, // End scene (inside car)

	// Bug fixes
	{ UpdateCarClassString, (int*)0x004EBF63 },
	{ UpdateCarClassString, (int*)0x004EC022 },
	{ UpdateCarClassString, (int*)0x004EC294 },

	// Improvements
};
int* repositionAddr[]{
	// Check - Not text box
	//(int*)(0x004DBB8C),		  // Not battle related
	// 
	//(int*)(0x004265B0 + 0x25E), // Not battle related
	//(int*)(0x004265B0 + 0x2E9), // Not battle related
	
	//(int*)(0x00434910 + 0x17E), // Not battle related
	//(int*)(0x00434910 + 0x24F), // Not battle related
	//(int*)(0x00434910 + 0x3BB), // Not battle related
	//(int*)(0x00434910 + 0x40B), // Not battle related
	//(int*)(0x00434910 + 0x4AB), // Not battle related
	//(int*)(0x00434910 + 0x58),  // Not battle related
	//(int*)(0x00434910 + 0x590), // Not battle related
	//(int*)(0x00434910 + 0x5DF), // Not battle related
	//(int*)(0x00434910 + 0x62E), // Not battle related
	//(int*)(0x00434910 + 0x911), // Not battle related
	//(int*)(0x00434910 + 0x98E), // Not battle related
	//(int*)(0x00434910 + 0xA73), // Not battle related
	//(int*)(0x00434910 + 0xAD1), // Not battle related
	//(int*)(0x00434910 + 0xB17), // Not battle related
	//(int*)(0x00434910 + 0xB58), // Not battle related
	//(int*)(0x00434910 + 0xB9D), // Not battle related
	//(int*)(0x00434910 + 0xD34), // Not battle related
	//(int*)(0x00434910 + 0xD83), // Not battle related
	//(int*)(0x00434910 + 0xDD2), // Not battle related
	//(int*)(0x00434910 + 0xE21), // Not battle related
	//(int*)(0x00434910 + 0xE9F), // Not battle related
	
	//(int*)(0x004389F0 + 0x2A5), // Not battle related
	//(int*)(0x004389F0 + 0x2D1), // Not battle related



	(int*)(0x0043F4B0 + 0x2AA), // Loading Screen
	
	
	// Check - Not text box
	//(int*)(0x00440460 + 0x2AA), // Not battle related
	//(int*)(0x00440460 + 0x332), // Not battle related
	
	//(int*)(0x0044F2E0 + 0x5DB), // Not battle related
	//(int*)(0x0044F2E0 + 0x8B9), // Not battle related
	//(int*)(0x0044F2E0 + 0x98D), // Not battle related
	//(int*)(0x0044F2E0 + 0xA06), // Not battle related
	//(int*)(0x0044F2E0 + 0xA6F), // Not battle related
	//(int*)(0x0044F2E0 + 0xB51), // Not battle related
	//(int*)(0x0044F2E0 + 0xE41), // Not battle related
	//(int*)(0x0044F2E0 + 0xEE7), // Not battle related
	
	//(int*)(0x00450460 + 0x114), // Not battle related
	//(int*)(0x00450460 + 0x55F), // Not battle related
	
	//(int*)(0x004510D0 + 0x477), // Not battle related
	//(int*)(0x004510D0 + 0x5B3), // Not battle related
	//(int*)(0x004510D0 + 0x6C1), // Not battle related
	//(int*)(0x004510D0 + 0x7CF), // Not battle related
	//(int*)(0x004510D0 + 0x88F), // Not battle related
	//(int*)(0x004510D0 + 0x91B), // Not battle related
	//(int*)(0x004510D0 + 0x995), // Not battle related
	//(int*)(0x004510D0 + 0xA10), // Not battle related
	//(int*)(0x004510D0 + 0xA6E), // Not battle related
	//(int*)(0x004510D0 + 0xAE8), // Not battle related
	//(int*)(0x004510D0 + 0xB9F), // Not battle related
	
	//(int*)(0x00452030 + 0x1BA), // Not battle related
	//(int*)(0x00452030 + 0x868), // Not battle related
	//(int*)(0x00452030 + 0xD51), // Not battle related
	
	//(int*)(0x00454450 + 0x192), // Not battle related
	//(int*)(0x00454450 + 0x1D6), // Not battle related
	
	//(int*)(0x0045A510 + 0x209), // Not battle related
	//(int*)(0x0045A510 + 0x31D), // Not battle related
	//(int*)(0x0045A510 + 0x4A3), // Not battle related
	//(int*)(0x0045A510 + 0x51C), // Not battle related
	//(int*)(0x0045A510 + 0x5BF), // Not battle related
	//(int*)(0x0045A510 + 0x69F), // Not battle related
	
	//(int*)(0x0045ADB0 + 0x211), // Not battle related
	//(int*)(0x0045ADB0 + 0x300), // Not battle related



	(int*)(0x0045B660 + 0x177), // Item Use
	(int*)(0x0045B660 + 0x287), // Item Use
	(int*)(0x0045B660 + 0x3FE), // Item Use
	(int*)(0x0045B660 + 0x47A), // Item Use
	(int*)(0x0045B660 + 0x558), // Item Use
	(int*)(0x0045BC90 + 0xA0), // Item Use Cancel
	(int*)(0x0045BC90 + 0xF3), // Item Use Cancel
	(int*)(0x0045C1A0 + 0xB0), // Item Use Image
	(int*)(0x0045C270 + 0xE9), // Item Use Image
	(int*)(0x0045CE90 + 0x2A), // Item Box Black Back
	(int*)(0x0045D710 + 0x190),  // Item Box Frame
	(int*)(0x0045D710 + 0x20A),  // Item Box Frame
	(int*)(0x0045D710 + 0x2B5),  // Item Box Frame
	(int*)(0x0045D710 + 0x331),  // Item Box Frame
	(int*)(0x0045D710 + 0x3D3),  // Item Box Frame
	(int*)(0x0045D710 + 0xE1),   // Item Box Frame
	(int*)(0x0045DB50 + 0x9D),	 // Item Box Items Back
	(int*)(0x0045DDF0 + 0xFF),   // Item Box Items ???
	(int*)(0x0045DF20 + 0x193),  // Item Box Items ???
	(int*)(0x0045E130 + 0xEC),	 // Item Box Item Icon
	(int*)(0x0045E250 + 0xB7),	 // Item Box Item Name
	(int*)(0x0045F2D0 + 0x97),   // Item Box Close Button
	(int*)(0x0046F5D0 + 0x1DB),	 // Item Box Close Button
	(int*)(0x0046F5D0 + 0x2D7),	 // Item Box Close Button
	(int*)(0x0046F5D0 + 0x401),	 // Item Box Close Button
	
	
	// Check - Text scale in this list
	//(int*)(0x004FD760 + 0x6B),	 // Draw String
	
	//(int*)(0x0046FCE0 + 0x240),	// Not battle related
	//(int*)(0x0046FCE0 + 0x376),	// Not battle related
	//(int*)(0x0046FCE0 + 0x4B7),	// Not battle related
	//(int*)(0x0046FCE0 + 0x55C),	// Not battle related
	
	//(int*)(0x00470800 + 0x420),	// Not battle related
	//(int*)(0x00470800 + 0x543),	// Not battle related
	//(int*)(0x00470800 + 0x5E0),	// Not battle related
	//(int*)(0x00470800 + 0x6BF),	// Not battle related
	//(int*)(0x00470800 + 0x7A5),	// Not battle related
	//(int*)(0x00470800 + 0x8B6),	// Not battle related
	//(int*)(0x00470800 + 0x9B1),	// Not battle related
	//(int*)(0x00470800 + 0xA65),	// Not battle related
	//(int*)(0x00470800 + 0xAFA),	// Not battle related
	//(int*)(0x00470800 + 0xB63),	// Not battle related
	//(int*)(0x00470800 + 0xC06),	// Not battle related
	//(int*)(0x00470800 + 0xCD3),	// Not battle related
	//(int*)(0x00470800 + 0xD4B),	// Not battle related
	//(int*)(0x00470800 + 0xDB5),	// Not battle related
	//(int*)(0x00470800 + 0xE1E),	// Not battle related
	//(int*)(0x00470800 + 0xE87),	// Not battle related
	
	//(int*)(0x004717F0 + 0x22F4),	// Not battle related
	//(int*)(0x004717F0 + 0x28FA),	// Not battle related
	//(int*)(0x004717F0 + 0x3C9C),	// Not battle related
	//(int*)(0x004717F0 + 0x425C),	// Not battle related
	//(int*)(0x004717F0 + 0x42C7),	// Not battle related
	//(int*)(0x004717F0 + 0x4391),	// Not battle related
	//(int*)(0x004717F0 + 0x4452),	// Not battle related
	//(int*)(0x004717F0 + 0x451F),	// Not battle related
	//(int*)(0x004717F0 + 0x45CD),	// Not battle related
	
	//(int*)(0x00477520 + 0x327),	// Not battle related
	//(int*)(0x00477520 + 0x39F),	// Not battle related
	//(int*)(0x00477520 + 0x442),	// Not battle related
	//(int*)(0x00477520 + 0x4E7),	// Not battle related
	//(int*)(0x00477520 + 0x5A4),	// Not battle related
	//(int*)(0x00477520 + 0x673),	// Not battle related
	
	//(int*)(0x00478810 + 0x289),	// Not battle related
	//(int*)(0x00478810 + 0x31A),	// Not battle related
	//(int*)(0x00478810 + 0x3C1),	// Not battle related
	//(int*)(0x00478810 + 0x54C),	// Not battle related
	
	//(int*)(0x00478E30 + 0x60),	// Not battle related
	
	//(int*)(0x0047A320 + 0x280),	// Not battle related
	//(int*)(0x0047A320 + 0x328),	// Not battle related
	//(int*)(0x0047A320 + 0x3DB),	// Not battle related
	//(int*)(0x0047A320 + 0x596),	// Not battle related
	
	//(int*)(0x0047B1C0 + 0x202),	// Not battle related
	//(int*)(0x0047B1C0 + 0x2EA),	// Not battle related
	//(int*)(0x0047B1C0 + 0x3F5),	// Not battle related
	//(int*)(0x0047B1C0 + 0x496),	// Not battle related
	
	//(int*)(0x0047DDA0 + 0x28C),	// Not battle related
	//(int*)(0x0047DDA0 + 0x325),	// Not battle related
	//(int*)(0x0047DDA0 + 0x3CD),	// Not battle related
	//(int*)(0x0047DDA0 + 0x4FF),	// Not battle related
	
	//(int*)(0x00484400 + 0x4E8),	// Not battle related
	//(int*)(0x00484400 + 0x61D),	// Not battle related
	//(int*)(0x00484400 + 0x755),	// Not battle related
	//(int*)(0x00484400 + 0x888),	// Not battle related
	//(int*)(0x00484400 + 0x9DA),	// Not battle related
	//(int*)(0x00484400 + 0xAC5),	// Not battle related
	//(int*)(0x00484400 + 0xBAE),	// Not battle related
	//(int*)(0x00484400 + 0xC1C),	// Not battle related
	//(int*)(0x00484400 + 0xD89),	// Not battle related
	//(int*)(0x00484400 + 0xDD1),	// Not battle related
	
	//(int*)(0x004859F0 + 0x1AC),	// Not battle related  
	//(int*)(0x004859F0 + 0x68),	// Not battle related
	
	//(int*)(0x00486880 + 0x13A),	// Not battle related
	
	//(int*)(0x00486A10 + 0x2AC),	// Not battle related
	//(int*)(0x00486A10 + 0x362),	// Not battle related
	
	//(int*)(0x00487EB0 + 0x1FF),	// Not battle related
	
	//(int*)(0x00488780 + 0x33D),	// Not battle related
	
	//(int*)(0x00489310 + 0x295),	// Not battle related
	//(int*)(0x00489310 + 0x332),	// Not battle related
	//(int*)(0x00489310 + 0x3E3),	// Not battle related
	//(int*)(0x00489310 + 0x514),	// Not battle related
	
	//(int*)(0x0048A020 + 0x25C),	// Not battle related
	//(int*)(0x0048A020 + 0x382),	// Not battle related
	//(int*)(0x0048A020 + 0x441),	// Not battle related
	//(int*)(0x0048A020 + 0x53B),	// Not battle related
	//(int*)(0x0048A020 + 0x5E1),	// Not battle related
	//(int*)(0x0048A020 + 0x690),	// Not battle related
	//(int*)(0x0048A020 + 0x76C),	// Not battle related
	//(int*)(0x0048A820 + 0x105F),	// Not battle related
	//(int*)(0x0048A820 + 0x114B),	// Not battle related
	//(int*)(0x0048A820 + 0x1651),	// Not battle related
	//(int*)(0x0048A820 + 0x16D8),	// Not battle related
	//(int*)(0x0048A820 + 0x177E),	// Not battle related
	//(int*)(0x0048A820 + 0x1870),	// Not battle related
	



	(int*)(0x0048C940 + 0x4C),	// Battle Win/Lose Texture
	(int*)(0x0048C940 + 0xB7),	// Battle Win/Lose Texture
	(int*)(0x0048CB60 + 0x3DF),	// Battle Result Value Labels
	(int*)(0x0048CB60 + 0x644),	// Battle Result Value Labels
	(int*)(0x0048CB60 + 0x759),	// Battle Result Value Labels	
	(int*)(0x0048D520 + 0x176),	// Battle Exp Percent Bar
	(int*)(0x0048D780 + 0x22F),	// Battle Something probably so will leave it enabled
	(int*)(0x0048D780 + 0x36A),	// Battle Something probably so will leave it enabled
	(int*)(0x0048D780 + 0x435),	// Battle Something probably so will leave it enabled  
	(int*)(0x0048DD60 + 0x193), // Itembox (not in course)
	(int*)(0x0048DD60 + 0x21E), // Itembox (not in course)	
	(int*)(0x0048E1B0 + 0x16E), // Battle Result Dialog 
	
		
	// Check - Not text box
	//(int*)(0x00497150 + 0x161), // Not Battle Related
	
	//(int*)(0x004983F0 + 0xD1),  // Not Battle Related
	
	//(int*)(0x00499130 + 0x1FE), // Not Battle Related
	//(int*)(0x00499130 + 0x44A), // Not Battle Related
	
	//(int*)(0x00499DE0 + 0x339), // Not Battle Related
	//(int*)(0x00499DE0 + 0x478), // Not Battle Related
	//(int*)(0x00499DE0 + 0x5E3), // Not Battle Related
	//(int*)(0x00499DE0 + 0x683), // Not Battle Related
	
	//(int*)(0x0049B080 + 0x37D), // Not Battle Related
	//(int*)(0x0049B080 + 0x510), // Not Battle Related
	//(int*)(0x0049B080 + 0x651), // Not Battle Related
	//(int*)(0x0049B080 + 0x8C2), // Not Battle Related
	//(int*)(0x0049B080 + 0x937), // Not Battle Related
	
	//(int*)(0x0049C5A0 + 0x20B), // Not Battle Related	
	//(int*)(0x0049C5A0 + 0x32E), // Not Battle Related
	//(int*)(0x0049C5A0 + 0x436), // Not Battle Related
	//(int*)(0x0049C5A0 + 0x557), // Not Battle Related
	//(int*)(0x0049C5A0 + 0x602), // Not Battle Related
	//(int*)(0x0049C5A0 + 0x6B9), // Not Battle Related
	
	//(int*)(0x0049D0B0 + 0x231), // Not Battle Related
	//(int*)(0x0049D0B0 + 0x354), // Not Battle Related
	//(int*)(0x0049D0B0 + 0x468), // Not Battle Related
	//(int*)(0x0049D0B0 + 0x5B6), // Not Battle Related
	//(int*)(0x0049D0B0 + 0x643), // Not Battle Related
	//(int*)(0x0049DB80 + 0x2CE), // Not Battle Related
	//(int*)(0x0049DB80 + 0x3CF), // Not Battle Related
	//(int*)(0x0049DB80 + 0x4E4), // Not Battle Related
	//(int*)(0x0049DB80 + 0x588), // Not Battle Related 
	
	//(int*)(0x0049E470 + 0x295), // Not battle related
	//(int*)(0x0049E470 + 0x3DD), // Not battle related
	//(int*)(0x0049E470 + 0x559), // Not battle related
	//(int*)(0x0049E470 + 0x5D1), // Not battle related
	//(int*)(0x0049E470 + 0x648), // Not battle related
	//(int*)(0x0049E470 + 0x6BC), // Not battle related
	//(int*)(0x0049E470 + 0x774), // Not battle related
	
	//(int*)(0x0049F270 + 0x1DB), // Not battle related
	//(int*)(0x0049F270 + 0x2C6), // Not battle related
	//(int*)(0x0049F270 + 0x3AF), // Not battle related
	
	//(int*)(0x0049F8E0 + 0x36C), // Not battle related
	//(int*)(0x0049F8E0 + 0x453), // Not battle related
	//(int*)(0x0049F8E0 + 0x50B), // Not battle related
	//(int*)(0x0049F8E0 + 0x657), // Not battle related
	//(int*)(0x0049F8E0 + 0x6BC), // Not battle related
	//(int*)(0x0049F8E0 + 0x7FB), // Not battle related
	//(int*)(0x0049F8E0 + 0x869), // Not battle related
	//(int*)(0x0049F8E0 + 0x9E0), // Not battle related
	//(int*)(0x0049F8E0 + 0xA6C), // Not battle related
	//(int*)(0x0049F8E0 + 0xB1B), // Not battle related
	
	//(int*)(0x004A0B70 + 0x23F), // Not battle related
	//(int*)(0x004A0B70 + 0x324), // Not battle related
	//(int*)(0x004A0B70 + 0x407), // Not battle related
	//(int*)(0x004A0B70 + 0x524), // Not battle related
	
	//(int*)(0x004A1600 + 0x312), // Not battle related
	//(int*)(0x004A1600 + 0x5E7), // Not battle related
	//(int*)(0x004A1600 + 0x660), // Not battle related
	//(int*)(0x004A1600 + 0x7C6), // Not battle related
	//(int*)(0x004A1600 + 0x839), // Not battle related
	//(int*)(0x004A1600 + 0x8B7), // Not battle related
	//(int*)(0x004A1600 + 0x99E), // Not battle related
	//(int*)(0x004A1600 + 0xA43), // Not battle related
	
	//(int*)(0x004A8D90 + 0x287), // Not battle related	
	
		
		
	(int*)(0x004A91B0 + 0x468), // 
	(int*)(0x004A91B0 + 0x4DB), // 
	(int*)(0x004A91B0 + 0x55F), // 
	
		
	// Check - Not text box
	//(int*)(0x004A9830 + 0x1D5), // Not Shop price
	
		
		
		
	(int*)(0x004AA150 + 0x119), // 
	(int*)(0x004AA150 + 0x146), // 
	(int*)(0x004AA150 + 0x1D7), // 
	(int*)(0x004AA150 + 0x208), // 
	(int*)(0x004AA490 + 0x118), // 
	(int*)(0x004AA490 + 0x145), // 
	(int*)(0x004AA490 + 0x1B6), // 
	(int*)(0x004AA490 + 0x1F7), // 
	(int*)(0x004AA770 + 0x5F),  // Battle '+' for EXP
	
	
	
	// Check - Not text box
	//(int*)(0x004AB050 + 0x32),  // not battle related
	//(int*)(0x004AB050 + 0x400), // not battle related
	
	//(int*)(0x004ADC80 + 0x358), // not battle related
	//(int*)(0x004ADC80 + 0x40E), // not battle related
	
	//(int*)(0x004B1100 + 0x1050),// not battle related
	//(int*)(0x004B1100 + 0x1184),// not battle related
	//(int*)(0x004B1100 + 0x13EC),// not battle related
	//(int*)(0x004B1100 + 0x1597),// not battle related
	//(int*)(0x004B1100 + 0x16E8),// not battle related
	//(int*)(0x004B1100 + 0x1872),// not battle related
	//(int*)(0x004B1100 + 0x19BA),// not battle related
	//(int*)(0x004B1100 + 0x1AEE),// not battle related
	//(int*)(0x004B1100 + 0x5D7), // not battle related
	//(int*)(0x004B1100 + 0x70F), // not battle related
	//(int*)(0x004B1100 + 0x86B), // not battle related
	//(int*)(0x004B1100 + 0x9A0), // not battle related
	//(int*)(0x004B1100 + 0xAE6), // not battle related
	//(int*)(0x004B1100 + 0xC55), // not battle related
	//(int*)(0x004B1100 + 0xDBB), // not battle related
	//(int*)(0x004B1100 + 0xF1C), // not battle related
	
	//(int*)(0x004B5220 + 0x31D), // not battle related
	
	//(int*)(0x004BC380 + 0x11E), // not battle related
	//(int*)(0x004BC380 + 0x232), // not battle related
	//(int*)(0x004BC380 + 0x2C2), // not battle related
	//(int*)(0x004BC380 + 0x357), // not battle related
	
	//(int*)(0x004BD090 + 0x107), // not battle related
	
	//(int*)(0x004BD260 + 0x13B), // not battle related
	
		
		
	(int*)(0x004BF6F0 + 0x1E3), // Warning Screens	
	
		
		
		
	// Check - Not text box
	//(int*)(0x004C1E30 + 0x10B),
	//(int*)(0x004C1E30 + 0x12C), // Tacho
	//(int*)(0x004C1E30 + 0x14D),
	//(int*)(0x004C1E30 + 0x172),
	
	//(int*)(0x004D2C80 + 0x9A),  // Not battle related
	
	//(int*)(0x004D83F0 + 0x452), // Not battle related
	//(int*)(0x004D83F0 + 0x9DF), // Not battle related
	//(int*)(0x004D83F0 + 0xA21), // Not battle related
	
	//(int*)(0x004DB1D0 + 0x4B),
	//(int*)(0x004DB1D0 + 0x8D), // Tacho
	
	//(int*)(0x004DB4F0 + 0x6E), // Gears Shift Assist
	//(int*)(0x004DB4F0 + 0xB3),	
	
	//(int*)(0x004DB750 + 0x3A), // Not battle related
	
	//(int*)(0x004DB800 + 0x31), // Not battle related
	
	//(int*)(0x004DB910 + 0x2D), // Not battle related
	//(int*)(0x004DB910 + 0x69), // Not battle related
	//(int*)(0x004DB910 + 0xA5), // Not battle related
	
	//(int*)(0x004DBAF0 + 0x3B), // Not battle related	
	
	//(int*)(0x004DBBE0 + 0x15D), // Gears Shift Assist
	//(int*)(0x004DBBE0 + 0x182), // Nothing visible
	//(int*)(0x004DBBE0 + 0x260),
	//(int*)(0x004DBBE0 + 0x2AF),
	
	//(int*)(0x004DC5E0 + 0xCD), // Not battle related
	
	//(int*)(0x004DC990 + 0x45), // Not battle related
	//(int*)(0x004DC990 + 0xAE), // Not battle related
	
	//(int*)(0x004DCEB0 + 0x1ED), // Not battle related
	//(int*)(0x004DCEB0 + 0x264), // Not battle related
	//(int*)(0x004DCEB0 + 0x2DB), // Not battle related
	//(int*)(0x004DCEB0 + 0x3A0), // Not battle related
	//(int*)(0x004DCEB0 + 0x42F), // Not battle related
	//(int*)(0x004DCEB0 + 0x4D5), // Not battle related
	//(int*)(0x004DCEB0 + 0x54C), // Not battle related
	//(int*)(0x004DCEB0 + 0x5C3), // Not battle related
	//(int*)(0x004DCEB0 + 0x6FA), // Not battle related
	//(int*)(0x004DCEB0 + 0x76E), // Not battle related
	
	//(int*)(0x004DD720 + 0x821), // Not battle related
	
		
		
	(int*)(0x004DE420 + 0x1A6), // Battle Bars Background
	(int*)(0x004DE420 + 0x26F), // Battle Bars Background
	(int*)(0x004DE420 + 0x2CC), // Battle Bars Background
	(int*)(0x004DE420 + 0x3C),	// Battle Bars Background
	(int*)(0x004DE420 + 0x82),	// Battle Bars Background
	(int*)(0x004DE420 + 0xCE),	// Battle Bars Background
	(int*)(0x004DF020 + 0x13D), // Battle Bars
	(int*)(0x004DF020 + 0xF0),	// Battle Bars
	(int*)(0x004DF240 + 0x179), // Battle Clock Background
	(int*)(0x004DF240 + 0x1DC), // Battle Clock Background
	(int*)(0x004DF240 + 0xAE),  // Battle Clock
	//(int*)(0x004DF6E0 + 0x6E), // Not battle related
	(int*)(0x004DF8D0 + 0x7B),  // Battle Cancel Text

	
	
	// Check
	//(int*)(0x004E0710 + 0x173), // Not battle related
	//(int*)(0x004E0710 + 0x1BC), // Not battle related
	//(int*)(0x004E0710 + 0x1FC), // Not battle related
	//(int*)(0x004E0710 + 0x4B), // Nothing Visible 3
	//(int*)(0x004E0710 + 0x92), // Chat and Buttons Dialogs
	
	//(int*)(0x004F49E0 + 0x47), // Not battle related
	
	//(int*)(0x004F4F90 + 0x8E), // Not battle related
	//(int*)(0x004F4F90 + 0xBA), // Chat box left
	
	//(int*)(0x004F6BE0 + 0xAA), // Chat background
	//(int*)(0x004F6BE0 + 0xD9), // Address book back
	
	//(int*)(0x004F7F80 + 0x104), // Not battle related
	//(int*)(0x004F7F80 + 0x11F),	// Not battle related
	
	//(int*)(0x004F8150 + 0x1C1),	// Not battle related
	//(int*)(0x004F8150 + 0x1F9),	// Not battle related
	
	//(int*)(0x004F8560 + 0x10F),	// Not battle related
	//(int*)(0x004F8560 + 0x12E),	// Not battle related
	//(int*)(0x004F8560 + 0x1FF),	// Not battle related
	//(int*)(0x004F8560 + 0x217), // Address book back
	//(int*)(0x004F8560 + 0x2C8), // address book search
	//(int*)(0x004F8560 + 0x2E0),// Not battle related
	
	//(int*)(0x004F88B0 + 0x229),// Not battle related
	//(int*)(0x004F88B0 + 0x258),// Not battle related
	
	//(int*)(0x004FB070 + 0x163),// Not battle related
	//(int*)(0x004FB070 + 0x1A7),// Not battle related
	//(int*)(0x004FB070 + 0x62), // Not battle related
	//(int*)(0x004FB070 + 0x9C), // Not battle related
	
	//(int*)(0x004FB830 + 0x94), // Not battle related - Textbox carat
	
	//(int*)(0x004FB8D0 + 0x5B), // Not battle related
	
	//(int*)(0x004FC140 + 0x23), // Not battle related
	//(int*)(0x004FC140 + 0x3C), // Not battle related
	//(int*)(0x004FC140 + 0x55), // Not battle related
	//(int*)(0x004FC140 + 0x6E), // address book search
	//(int*)(0x004FC140 + 0x87), // Not battle related
	
	//(int*)(0x004FC800 + 0x1CD),// Not battle related
	//(int*)(0x004FC800 + 0x1EC),// Not battle related
	//(int*)(0x004FC800 + 0x28B),// Not battle related
	//(int*)(0x004FC800 + 0x2AA),// Not battle related
	//(int*)(0x004FC800 + 0x328),// Not battle related
	//(int*)(0x004FC800 + 0xA9), // Not battle related
	//(int*)(0x004FC800 + 0xC8), // Not battle related
	
	//(int*)(0x004FCB40 + 0x93), // Not battle related
	
	//(int*)(0x004FCD40 + 0xE4), // Not battle related
	//(int*)(0x004FCD40 + 0xFD), // Not battle related
	
	//(int*)(0x004FD8D0 + 0x81), // Not battle related
	
	//(int*)(0x004FD990 + 0x2A), // Not battle related
	
	//(int*)(0x004FDAA0 + 0x45)  // Not battle related
};

int* repositionIntAddr[]{
	(int*)(0x004F8150 + 0x66),
	(int*)(0x004F8150 + 0xDA),
	(int*)(0x004F8150 + 0x127),
	(int*)(0x004F88B0 + 0x66),
	(int*)(0x004F88B0 + 0xDA),
	(int*)(0x004F88B0 + 0x134),
	(int*)(0x004F88B0 + 0x181),
	(int*)(0x004F88B0 + 0x1CE),
	(int*)(0x004FC800 + 0xED),
	(int*)(0x004FCB40 + 0x19),
	(int*)(0x004FCB40 + 0xC6),
};

int* drawStringAddr[]{
	//(int*)(0x00434910 + 0x37F),
	//(int*)(0x0043501A),
	//(int*)(0x0043507F),
	//(int*)(0x00434910 + 0x7E1),
	//(int*)(0x00434910 + 0x82D),
	//(int*)(0x00434910 + 0xC07),
	//(int*)(0x00434910 + 0xC5B),
	//(int*)(0x00434910 + 0xCAC),
	//(int*)(0x00434910 + 0xCFC),
	//(int*)(0x00440460 + 0x48),
	//(int*)(0x0044F2E0 + 0xBD9),
	//(int*)(0x0044F2E0 + 0xC3D),
	//(int*)(0x00450270 + 0xD2),
	//(int*)(0x00450270 + 0x11B),
	//(int*)(0x0045B660 + 0xA5),
	//(int*)(0x0045B660 + 0x136),

	(int*)(0x0045BC90 + 0x21D), // Item Use
	(int*)(0x0045BC90 + 0x27A), // Item Use

	//(int*)(0x0045CEF0 + 0x335),
	//(int*)(0x0045CEF0 + 0x38F),

	(int*)(0x0045D650 + 0x22), // Item Hover
	(int*)(0x0045D650 + 0x3D), // Item Hover
	
	//(int*)(0x004717F0 + 0x23E3),
	//(int*)(0x004717F0 + 0x2495),
	//(int*)(0x004717F0 + 0x2579),
	//(int*)(0x004717F0 + 0x2656),
	//(int*)(0x004717F0 + 0x2711),
	//(int*)(0x00477520 + 0x700),
	//(int*)(0x00478810 + 0x5D9),
	//(int*)(0x004859F0 + 0x12D),
	//(int*)(0x00497150 + 0x205),
	//(int*)(0x0049B080 + 0x772),
	//(int*)(0x0049B080 + 0x7D1),
	//(int*)(0x0049C5A0 + 0x755),
	//(int*)(0x0049C5A0 + 0x7AF),
	//(int*)(0x0049D0B0 + 0x6E5),
	//(int*)(0x0049D0B0 + 0x73F),

	//(int*)(0x0049E470 + 0x4CD),
	//(int*)(0x004A8D90 + 0x2FD),
	//(int*)(0x004A91B0 + 0x283),
	//(int*)(0x004AB050 + 0x470),
	//(int*)(0x004ABF40 + 0x45),
	//(int*)(0x004BC380 + 0xBD),
	//(int*)(0x004BD6E0 + 0x45),
	//(int*)(0x004D83F0 + 0x976),
	//(int*)(0x004DC5E0 + 0x149),
	//(int*)(0x004DE420 + 0x32D),
	//(int*)(0x004DE420 + 0x37B),
	//(int*)(0x004DE420 + 0x3C9),
	//(int*)(0x004DE420 + 0x419),
	//(int*)(0x004DE420 + 0x4A1),
	//(int*)(0x004DE420 + 0x4EE),
	//(int*)(0x004FBB10 + 0x44),
	//(int*)(0x004FBB60 + 0x32),
	//(int*)(0x004FD0E0 + 0x114),
	//(int*)(0x004FD9D0 + 0x1E),
	//(int*)(0x004FDA00 + 0x26)
};