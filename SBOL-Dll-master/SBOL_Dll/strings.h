#pragma once
#include "structures.h"

extern char* windowTitle;
extern char* defaultIP;
extern char* defaultServerName;
extern char* clientName;
extern char* versionStr;
extern char* sysinfoPath;
extern char* logPath;

const STRINGENTRY strings[]{
	{ FALSE, (char*)0x0041C1B9, sysinfoPath },
	{ FALSE, (char*)0x0040581A, logPath },
	{ FALSE, (char*)0x00408D7A, logPath },
	{ FALSE, (char*)0x0041909C, logPath },
	{ FALSE, (char*)0x0041915D, logPath },
	{ FALSE, (char*)0x004191EF, logPath },
	{ FALSE, (char*)0x00419292, logPath },
	{ FALSE, (char*)0x00419350, logPath },
	{ FALSE, (char*)0x00419652, logPath },
	{ FALSE, (char*)0x0041970E, logPath },
	{ FALSE, (char*)0x004197DB, logPath },
	{ FALSE, (char*)0x004198B4, logPath },
	{ FALSE, (char*)0x00419CAC, logPath },
	{ FALSE, (char*)0x0041C278, logPath },
	{ FALSE, (char*)0x0041C339, logPath },
	{ FALSE, (char*)0x004271D8, logPath },
	{ FALSE, (char*)0x0044A7D5, logPath },
	{ FALSE, (char*)0x0044A8B5, logPath },
	//{ FALSE, (char*)0x00656B70, "!!! W R O N G  W A Y !!!"},
};

const STATICSTRING stringaddresses[]{
	{ (char*)0x005BB6DC, 0x64 }, // 
	{ (char*)0x005BB7A2, 0x64 }, // 
	{ (char*)0x005BB868, 0x64 }, // 
	{ (char*)0x005BB92E, 0x64 }, // 
	{ (char*)0x005BB9F4, 0x64 }, // 
	{ (char*)0x005BBABA, 0x64 }, // 
	{ (char*)0x005BBB80, 0x64 }, // 
	{ (char*)0x005BBC46, 0x64 }, // 
	{ (char*)0x005BBD0C, 0x64 }, // 
	{ (char*)0x005BBDD2, 0x64 }, // 
	{ (char*)0x005BBE98, 0x64 }, // 
	{ (char*)0x005BBF5E, 0x64 }, // 
	{ (char*)0x005BC024, 0x64 }, // 
	{ (char*)0x005BC0EA, 0x64 }, // 
	{ (char*)0x005BC1B0, 0x64 }, // 
	{ (char*)0x005BC276, 0x64 }, // 
	{ (char*)0x005BC33C, 0x64 }, // 
	{ (char*)0x005BC402, 0x64 }, // 
	{ (char*)0x005BC4C8, 0x64 }, // 
	{ (char*)0x005BC58E, 0x64 }, // 
	{ (char*)0x005BC654, 0x64 }, // 
	{ (char*)0x005BC71A, 0x64 }, // 
	{ (char*)0x005BC8A6, 0x64 }, // 
	{ (char*)0x005BC96C, 0x64 }, // 
	{ (char*)0x005BCA32, 0x64 }, // 
	{ (char*)0x005BCAF8, 0x64 }, // 
	{ (char*)0x005BCBBE, 0x64 }, // 
	{ (char*)0x005BCC84, 0x64 }, // 
	{ (char*)0x005BCD4A, 0x64 }, // 
	{ (char*)0x005BCE10, 0x64 }, // 
	{ (char*)0x005BD062, 0x64 }, // 
	{ (char*)0x005BD128, 0x64 }, // 
	{ (char*)0x005BD1EE, 0x64 }, // 
	{ (char*)0x005BD2B4, 0x64 }, // 
	{ (char*)0x005BD37A, 0x64 }, // 
	{ (char*)0x005BD440, 0x64 }, // 
	{ (char*)0x005BD506, 0x64 }, // 
	{ (char*)0x005BD5CC, 0x64 }, // 
	{ (char*)0x005BD692, 0x64 }, // 
	{ (char*)0x005BD758, 0x64 }, // 
	{ (char*)0x005BD81E, 0x64 }, // 
	{ (char*)0x005BD8E4, 0x64 }, // 
	{ (char*)0x005BD9AA, 0x64 }, // 
	{ (char*)0x005BDA70, 0x64 }, // 
	{ (char*)0x005BDB36, 0x64 }, // 
	{ (char*)0x005BDBFC, 0x64 }, // 
	{ (char*)0x005BDCC2, 0x64 }, // 
	{ (char*)0x005BDD88, 0x64 }, // 
	{ (char*)0x005BDE4E, 0x64 }, // 
	{ (char*)0x005BDF14, 0x64 }, // 
	{ (char*)0x005BDFDA, 0x64 }, // 
	{ (char*)0x005BE0A0, 0x64 }, // 
	{ (char*)0x005BE166, 0x64 }, // 
	{ (char*)0x005BE22C, 0x64 }, // 
	{ (char*)0x005BE2F2, 0x64 }, // 
	{ (char*)0x005BE3B8, 0x64 }, // 
	{ (char*)0x005BE47E, 0x64 }, // 
	{ (char*)0x005BE544, 0x64 }, // 
	{ (char*)0x005BE60A, 0x64 }, // 
	{ (char*)0x005BE6D0, 0x64 }, // 
	{ (char*)0x005BE796, 0x64 }, // 
	{ (char*)0x005BE85C, 0x64 }, // 
	{ (char*)0x005BE922, 0x64 }, // 
	{ (char*)0x005BE9E8, 0x64 }, // 
	{ (char*)0x005BEAAE, 0x64 }, // 
	{ (char*)0x005BEB74, 0x64 }, // 
	{ (char*)0x005BEC3A, 0x64 }, // 
	{ (char*)0x005BED00, 0x64 }, // 
	{ (char*)0x005BEDC6, 0x64 }, // 
	{ (char*)0x005BEE8C, 0x64 }, // 
	{ (char*)0x005BEF52, 0x64 }, // 
	{ (char*)0x005BF018, 0x64 }, // 
	{ (char*)0x005BF0DE, 0x64 }, // 
	{ (char*)0x005BF1A4, 0x64 }, // 
	{ (char*)0x005BF26A, 0x64 }, // 
	{ (char*)0x005BF330, 0x64 }, // 
	{ (char*)0x005BF3F6, 0x64 }, // 
	{ (char*)0x005BF4BC, 0x64 }, // 
	{ (char*)0x005BF582, 0x64 }, // 
	{ (char*)0x005BF648, 0x64 }, // 
	{ (char*)0x005BF70E, 0x64 }, // 
	{ (char*)0x005BF7D4, 0x64 }, // 
	{ (char*)0x005BF89A, 0x64 }, // 
	{ (char*)0x005BF960, 0x64 }, // 
	{ (char*)0x005BFA26, 0x64 }, // 
	{ (char*)0x005BFAEC, 0x64 }, // 
	{ (char*)0x005BFBB2, 0x64 }, // 
	{ (char*)0x005BFC78, 0x64 }, // 
	{ (char*)0x005BFD3E, 0x64 }, // 
	{ (char*)0x005BFE04, 0x64 }, // 
	{ (char*)0x005BFECA, 0x64 }, // 
	{ (char*)0x005BFF90, 0x64 }, // 
	{ (char*)0x005C0056, 0x64 }, // 
	{ (char*)0x005C011C, 0x64 }, // 
	{ (char*)0x005C01E2, 0x64 }, // 
	{ (char*)0x005C02A8, 0x64 }, // 
	{ (char*)0x005C036E, 0x64 }, // 
	{ (char*)0x005C0434, 0x64 }, // 
	{ (char*)0x005C04FA, 0x64 }, // 
	{ (char*)0x005C05C0, 0x64 }, // 
	{ (char*)0x005C0686, 0x64 }, // 
	{ (char*)0x005C074C, 0x64 }, // 
	{ (char*)0x005C0812, 0x64 }, // 
	{ (char*)0x005C08D8, 0x64 }, // 
	{ (char*)0x005C099E, 0x64 }, // 
	{ (char*)0x005C0A64, 0x64 }, // 
	{ (char*)0x005C0B2A, 0x64 }, // 
	{ (char*)0x005C0BF0, 0x64 }, // 
	{ (char*)0x005C0CB6, 0x64 }, // 
	{ (char*)0x005C0D7C, 0x64 }, // 
	{ (char*)0x005C0E42, 0x64 }, // 
	{ (char*)0x005C0F08, 0x64 }, // 
	{ (char*)0x005C0FCE, 0x64 }, // 
	{ (char*)0x005C1094, 0x64 }, // 
	{ (char*)0x005C115A, 0x64 }, // 
	{ (char*)0x005C1220, 0x64 }, // 
	{ (char*)0x005C12E6, 0x64 }, // 
	{ (char*)0x005DDC54, 0x64 }, // 
	{ (char*)0x005DDCBC, 0x64 }, // 
	{ (char*)0x005DDD24, 0x64 }, // 
	{ (char*)0x005DDD8C, 0x64 }, // 
	{ (char*)0x005DDDF4, 0x64 }, // 
	{ (char*)0x005DDE5C, 0x64 }, // 
	{ (char*)0x005DDEC4, 0x64 }, // 
	{ (char*)0x005DDF2C, 0x64 }, // 
	{ (char*)0x005DDF94, 0x64 }, // 
	{ (char*)0x005DDFFC, 0x64 }, // 
	{ (char*)0x005DE064, 0x64 }, // 
	{ (char*)0x005DE0CC, 0x64 }, // 
	{ (char*)0x005DE134, 0x64 }, // 
	{ (char*)0x005DE19C, 0x64 }, // 
	{ (char*)0x005DE204, 0x64 }, // 
	{ (char*)0x005DE26C, 0x64 }, // 
	{ (char*)0x005DE2D4, 0x64 }, // 
	{ (char*)0x005DE33C, 0x64 }, // 
	{ (char*)0x005DE3A4, 0x64 }, // 
	{ (char*)0x005DE40C, 0x64 }, // 
	{ (char*)0x005DE474, 0x64 }, // 
	{ (char*)0x005DE4DC, 0x64 }, // 
	{ (char*)0x005DE544, 0x64 }, // 
	{ (char*)0x005DE5AC, 0x64 }, // 
	{ (char*)0x005DE614, 0x64 }, // 
	{ (char*)0x005DE67C, 0x64 }, // 
	{ (char*)0x005DE6E4, 0x64 }, // 
	{ (char*)0x005DE74C, 0x64 }, // 
	{ (char*)0x005DE7B4, 0x64 }, // 
	{ (char*)0x005DE81C, 0x64 }, // 
	{ (char*)0x005DE884, 0x64 }, // 
	{ (char*)0x005DE8EC, 0x64 }, // 
	{ (char*)0x005DE954, 0x64 }, // 
	{ (char*)0x005DE9BC, 0x64 }, // 
	{ (char*)0x005DEA24, 0x64 }, // 
	{ (char*)0x005DEA8C, 0x64 }, // 
	{ (char*)0x005DEAF4, 0x64 }, // 
	{ (char*)0x005DEB5C, 0x64 }, // 
	{ (char*)0x005DEBC4, 0x64 }, // 
	{ (char*)0x005DEC2C, 0x64 }, // 
	{ (char*)0x005DEC94, 0x64 }, // 
	{ (char*)0x005DECFC, 0x64 }, // 
	{ (char*)0x005DED64, 0x64 }, // 
	{ (char*)0x005DEDCC, 0x64 }, // 
	{ (char*)0x005DEE34, 0x64 }, // 
	{ (char*)0x005DEE9C, 0x64 }, // 
	{ (char*)0x005DEF04, 0x64 }, // 
	{ (char*)0x005DEF6C, 0x64 }, // 
	{ (char*)0x005DF10C, 0x64 }, // 
	{ (char*)0x005DF174, 0x64 }, // 
	{ (char*)0x005DF1DC, 0x64 }, // 
	{ (char*)0x005DF244, 0x64 }, // 
	{ (char*)0x005DF2AC, 0x64 }, // 
	{ (char*)0x005DF314, 0x64 }, // 
	{ (char*)0x005DF37C, 0x64 }, // 
	{ (char*)0x005DF3E4, 0x64 }, // 
	{ (char*)0x005DF44C, 0x64 }, // 
	{ (char*)0x005DF4B4, 0x64 }, // 
	{ (char*)0x005DF51C, 0x64 }, // 
	{ (char*)0x005DF584, 0x64 }, // 
	{ (char*)0x005DF5EC, 0x64 }, // 
	{ (char*)0x005DF654, 0x64 }, // 
	{ (char*)0x005DF6BC, 0x64 }, // 
	{ (char*)0x005DF724, 0x64 }, // 
	{ (char*)0x005DF78C, 0x64 }, // 
	{ (char*)0x005DF7F4, 0x64 }, // 
	{ (char*)0x005DF85C, 0x64 }, // 
	{ (char*)0x005DF8C4, 0x64 }, // 
	{ (char*)0x005DF92C, 0x64 }, // 
	{ (char*)0x005DF994, 0x64 }, // 
	{ (char*)0x005DF9FC, 0x64 }, // 
	{ (char*)0x005DFA64, 0x64 }, // 
	{ (char*)0x005DFACC, 0x64 }, // 
	{ (char*)0x005DFB34, 0x64 }, // 
	{ (char*)0x005DFB9C, 0x64 }, // 
	{ (char*)0x005DFC04, 0x64 }, // 
	{ (char*)0x005DFC6C, 0x64 }, // 
	{ (char*)0x005DFCD4, 0x64 }, // 
	{ (char*)0x005DFD3C, 0x64 }, // 
	{ (char*)0x005DFE74, 0x64 }, // 
	{ (char*)0x005DFEDC, 0x64 }, // 
	{ (char*)0x005DFF44, 0x64 }, // 
	{ (char*)0x005DFFAC, 0x64 }, // 
	{ (char*)0x005E0014, 0x64 }, // 
	{ (char*)0x005E007C, 0x64 }, // 
	{ (char*)0x005E00E4, 0x64 }, // 
	{ (char*)0x005E014C, 0x64 }, // 
	{ (char*)0x005E01B4, 0x64 }, // 
	{ (char*)0x005E021C, 0x64 }, // 
	{ (char*)0x005E0284, 0x64 }, // 
	{ (char*)0x005E02EC, 0x64 }, // 
	{ (char*)0x005E0354, 0x64 }, // 
	{ (char*)0x005E0424, 0x64 }, // 
	{ (char*)0x005E048C, 0x64 }, // 
	{ (char*)0x005E05C4, 0x64 }, // 
	{ (char*)0x005E062C, 0x64 }, // 
	{ (char*)0x005E0694, 0x64 }, // 
	{ (char*)0x005E06FC, 0x64 }, // 
	{ (char*)0x005E0764, 0x64 }, // 
	{ (char*)0x005E07CC, 0x64 }, // 
	{ (char*)0x005E0834, 0x64 }, // 
	{ (char*)0x005E089C, 0x64 }, // 
	{ (char*)0x005E0904, 0x64 }, // 
	{ (char*)0x005E096C, 0x64 }, // 
	{ (char*)0x005E09D4, 0x64 }, // 
	{ (char*)0x005E0A3C, 0x64 }, // 
	{ (char*)0x005E0AA4, 0x64 }, // 
	{ (char*)0x005E0B0C, 0x64 }, // 
	{ (char*)0x005E0B74, 0x64 }, // 
	{ (char*)0x005E0BDC, 0x64 }, // 
	{ (char*)0x005E0C44, 0x64 }, // 
	{ (char*)0x005E0CAC, 0x64 }, // 
	{ (char*)0x005E0D14, 0x64 }, // 
	{ (char*)0x005E0D7C, 0x64 }, // 
	{ (char*)0x005E0DE4, 0x64 }, // 
	{ (char*)0x005E0E4C, 0x64 }, // 
	{ (char*)0x005E0EB4, 0x64 }, // 
	{ (char*)0x005E0F1C, 0x64 }, // 
	{ (char*)0x005E0F84, 0x64 }, // 
	{ (char*)0x005E0FEC, 0x64 }, // 
	{ (char*)0x005E1054, 0x64 }, // 
	{ (char*)0x005E10BC, 0x64 }, // 
	{ (char*)0x005E1124, 0x64 }, // 
	{ (char*)0x005E118C, 0x64 }, // 
	{ (char*)0x005E11F4, 0x64 }, // 
	{ (char*)0x005E125C, 0x64 }, // 
	{ (char*)0x005E12C4, 0x64 }, // 
	{ (char*)0x005E132C, 0x64 }, // 
	{ (char*)0x005E1394, 0x64 }, // 
	{ (char*)0x005E13FC, 0x64 }, // 
	{ (char*)0x005E1464, 0x64 }, // 
	{ (char*)0x005E14CC, 0x64 }, // 
	{ (char*)0x005E1534, 0x64 }, // 
	{ (char*)0x005E159C, 0x64 }, // 
	{ (char*)0x005E1604, 0x64 }, // 
	{ (char*)0x005E166C, 0x64 }, // 
	{ (char*)0x005E16D4, 0x64 }, // 
	{ (char*)0x005E173C, 0x64 }, // 
	{ (char*)0x005E17A4, 0x64 }, // 
	{ (char*)0x005E180C, 0x64 }, // 
	{ (char*)0x005E1874, 0x64 }, // 
	{ (char*)0x005E18DC, 0x64 }, // 
	{ (char*)0x005E1944, 0x64 }, // 
	{ (char*)0x005E19AC, 0x64 }, // 
	{ (char*)0x005E1A14, 0x64 }, // 
	{ (char*)0x005E1A7C, 0x64 }, // 
	{ (char*)0x005E1AE4, 0x64 }, // 
	{ (char*)0x005E1B4C, 0x64 }, // 
	{ (char*)0x005E1BB4, 0x64 }, // 
	{ (char*)0x005E1C1C, 0x64 }, // 
	{ (char*)0x005E1C84, 0x64 }, // 
	{ (char*)0x005E1CEC, 0x64 }, // 
	{ (char*)0x005E1D54, 0x64 }, // 
	{ (char*)0x005E1DBC, 0x64 }, // 
	{ (char*)0x005E1E24, 0x64 }, // 
	{ (char*)0x005E1E8C, 0x64 }, // 
	{ (char*)0x005E1EF4, 0x64 }, // 
	{ (char*)0x005E1F5C, 0x64 }, // 
	{ (char*)0x005E1FC4, 0x64 }, // 
	{ (char*)0x005E202C, 0x64 }, // 
	{ (char*)0x005E2094, 0x64 }, // 
	{ (char*)0x005E2164, 0x64 }, // 
	{ (char*)0x005E21CC, 0x64 }, // 
	{ (char*)0x005E2234, 0x64 }, // 
	{ (char*)0x005E229C, 0x64 }, // 
	{ (char*)0x005E2304, 0x64 }, // 
	{ (char*)0x005E236C, 0x64 }, // 
	{ (char*)0x005E23D4, 0x64 }, // 
	{ (char*)0x005E243C, 0x64 }, // 
	{ (char*)0x005E24A4, 0x64 }, // 
	{ (char*)0x005E250C, 0x64 }, // 
	{ (char*)0x005E2574, 0x64 }, // 
	{ (char*)0x005E2644, 0x64 }, // 
	{ (char*)0x005E26AC, 0x64 }, // 
	{ (char*)0x005E2714, 0x64 }, // 
	{ (char*)0x005E277C, 0x64 }, // 
	{ (char*)0x005E27E4, 0x64 }, // 
	{ (char*)0x005E284C, 0x64 }, // 
	{ (char*)0x005E28B4, 0x64 }, // 
	{ (char*)0x005E291C, 0x64 }, // 
	{ (char*)0x005E2984, 0x64 }, // 
	{ (char*)0x005E29EC, 0x64 }, // 
	{ (char*)0x005E2ABC, 0x64 }, // 
	{ (char*)0x005E2B24, 0x64 }, // 
	{ (char*)0x005E2B8C, 0x64 }, // 
	{ (char*)0x005E2BF4, 0x64 }, // 
	{ (char*)0x005E2C5C, 0x64 }, // 
	{ (char*)0x005E2CC4, 0x64 }, // 
	{ (char*)0x005E2D2C, 0x64 }, // 
	{ (char*)0x005E2D94, 0x64 }, // 
	{ (char*)0x005E2DFC, 0x64 }, // 
	{ (char*)0x005E2E64, 0x64 }, // 
	{ (char*)0x005E2ECC, 0x64 }, // 
	{ (char*)0x005E2F34, 0x64 }, // 
	{ (char*)0x005E2F9C, 0x64 }, // 
	{ (char*)0x005E3004, 0x64 }, // 
	{ (char*)0x005E306C, 0x64 }, // 
	{ (char*)0x005E30D4, 0x64 }, // 
	{ (char*)0x005E313C, 0x64 }, // 
	{ (char*)0x005E31A4, 0x64 }, // 
	{ (char*)0x005E320C, 0x64 }, // 
	{ (char*)0x005E3274, 0x64 }, // 
	{ (char*)0x005E32DC, 0x64 }, // 
	{ (char*)0x005E3344, 0x64 }, // 
	{ (char*)0x005E33AC, 0x64 }, // 
	{ (char*)0x005E3414, 0x64 }, // 
	{ (char*)0x005E347C, 0x64 }, // 
	{ (char*)0x005E34E4, 0x64 }, // 
	{ (char*)0x005E354C, 0x64 }, // 
	{ (char*)0x005E35B4, 0x64 }, // 
	{ (char*)0x005E3684, 0x64 }, // 
	{ (char*)0x005E36EC, 0x64 }, // 
	{ (char*)0x005E3754, 0x64 }, // 
	{ (char*)0x005E37BC, 0x64 }, // 
	{ (char*)0x005E3824, 0x64 }, // 
	{ (char*)0x005E388C, 0x64 }, // 
	{ (char*)0x005E38F4, 0x64 }, // 
	{ (char*)0x005E395C, 0x64 }, // 
	{ (char*)0x005E39C4, 0x64 }, // 
	{ (char*)0x005E3A2C, 0x64 }, // 
	{ (char*)0x005E3A94, 0x64 }, // 
	{ (char*)0x005E3AFC, 0x64 }, // 
	{ (char*)0x005E3B64, 0x64 }, // 
	{ (char*)0x005E3BCC, 0x64 }, // 
	{ (char*)0x005E3C34, 0x64 }, // 
	{ (char*)0x005E3C9C, 0x64 }, // 
	{ (char*)0x005E3D04, 0x64 }, // 
	{ (char*)0x005E3D6C, 0x64 }, // 
	{ (char*)0x005E3DD4, 0x64 }, // 
	{ (char*)0x005E3E3C, 0x64 }, // 
	{ (char*)0x005E3EA4, 0x64 }, // 
	{ (char*)0x005E3F0C, 0x64 }, // 
	{ (char*)0x005E3F74, 0x64 }, // 
	{ (char*)0x005E3FDC, 0x64 }, // 
	{ (char*)0x005E4044, 0x64 }, // 
	{ (char*)0x005E40AC, 0x64 }, // 
	{ (char*)0x005E4114, 0x64 }, // 
	{ (char*)0x005E417C, 0x64 }, // 
	{ (char*)0x005E41E4, 0x64 }, // 
	{ (char*)0x005E424C, 0x64 }, // 
	{ (char*)0x005E42B4, 0x64 }, // 
	{ (char*)0x005E431C, 0x64 }, // 
	{ (char*)0x005E4384, 0x64 }, // 
	{ (char*)0x005E43EC, 0x64 }, // 
	{ (char*)0x005E4454, 0x64 }, // 
	{ (char*)0x005E44BC, 0x64 }, // 
	{ (char*)0x005E4524, 0x64 }, // 
	{ (char*)0x005E458C, 0x64 }, // 
	{ (char*)0x005E45F4, 0x64 }, // 
	{ (char*)0x005E465C, 0x64 }, // 
	{ (char*)0x005E46C4, 0x64 }, // 
	{ (char*)0x005E472C, 0x64 }, // 
	{ (char*)0x005E4794, 0x64 }, // 
	{ (char*)0x005E47FC, 0x64 }, // 
	{ (char*)0x005E4864, 0x64 }, // 
	{ (char*)0x005E48CC, 0x64 }, // 
	{ (char*)0x005E4934, 0x64 }, // 
	{ (char*)0x005E499C, 0x64 }, // 
	{ (char*)0x005E4A04, 0x64 }, // 
	{ (char*)0x005E4A6C, 0x64 }, // 
	{ (char*)0x005E4AD4, 0x64 }, // 
	{ (char*)0x005E4B3C, 0x64 }, // 
	{ (char*)0x005E4BA4, 0x64 }, // 
	{ (char*)0x005E4C0C, 0x64 }, // 
	{ (char*)0x005E4C74, 0x64 }, // 
	{ (char*)0x005E4CDC, 0x64 }, // 
	{ (char*)0x005E4D44, 0x64 }, // 
	{ (char*)0x005E4DAC, 0x64 }, // 
	{ (char*)0x005E4E14, 0x64 }, // 
	{ (char*)0x005E4E7C, 0x64 }, // 
	{ (char*)0x005E4EE4, 0x64 }, // 
	{ (char*)0x005E4F4C, 0x64 }, // 
	{ (char*)0x005E4FB4, 0x64 }, // 
	{ (char*)0x005E501C, 0x64 }, // 
	{ (char*)0x005E5084, 0x64 }, // 
	{ (char*)0x005E50EC, 0x64 }, // 
	{ (char*)0x005E5154, 0x64 }, // 
	{ (char*)0x005E51BC, 0x64 }, // 
	{ (char*)0x005E5224, 0x64 }, // 
	{ (char*)0x005E528C, 0x64 }, // 
	{ (char*)0x005E52F4, 0x64 }, // 
	{ (char*)0x005E535C, 0x64 }, // 
	{ (char*)0x005E53C4, 0x64 }, // 
	{ (char*)0x005E542C, 0x64 }, // 
	{ (char*)0x005E5494, 0x64 }, // 
	{ (char*)0x005E54FC, 0x64 }, // 
	{ (char*)0x005E5564, 0x64 }, // 
	{ (char*)0x005E55CC, 0x64 }, // 
	{ (char*)0x005E5634, 0x64 }, // 
	{ (char*)0x005E569C, 0x64 }, // 
	{ (char*)0x005E5704, 0x64 }, // 
	{ (char*)0x005E576C, 0x64 }, // 
	{ (char*)0x005E57D4, 0x64 }, // 
	{ (char*)0x005E583C, 0x64 }, // 
	{ (char*)0x005E58A4, 0x64 }, // 
	{ (char*)0x005E590C, 0x64 }, // 
	{ (char*)0x005E5974, 0x64 }, // 
	{ (char*)0x005E59DC, 0x64 }, // 
	{ (char*)0x005E5A44, 0x64 }, // 
	{ (char*)0x005E5AAC, 0x64 }, // 
	{ (char*)0x005E5B14, 0x64 }, // 
	{ (char*)0x005E5B7C, 0x64 }, // 
	{ (char*)0x005E5BE4, 0x64 }, // 
	{ (char*)0x005E5C4C, 0x64 }, // 
	{ (char*)0x005E5CB4, 0x64 }, // 
	{ (char*)0x005E5D1C, 0x64 }, // 
	{ (char*)0x005E5D84, 0x64 }, // 
	{ (char*)0x005E5DEC, 0x64 }, // 
	{ (char*)0x005E5E54, 0x64 }, // 
	{ (char*)0x005E5EBC, 0x64 }, // 
	{ (char*)0x005E5F24, 0x64 }, // 
	{ (char*)0x005E5F8C, 0x64 }, // 
	{ (char*)0x005E5FF4, 0x64 }, // 
	{ (char*)0x005E605C, 0x64 }, // 
	{ (char*)0x005E60C4, 0x64 }, // 
	{ (char*)0x005E612C, 0x64 }, // 
	{ (char*)0x005E6194, 0x64 }, // 
	{ (char*)0x005E61FC, 0x64 }, // 
	{ (char*)0x005E6264, 0x64 }, // 
	{ (char*)0x005E62CC, 0x64 }, // 
	{ (char*)0x005E6334, 0x64 }, // 
	{ (char*)0x005E639C, 0x64 }, // 
	{ (char*)0x005E6404, 0x64 }, // 
	{ (char*)0x005E646C, 0x64 }, // 
	{ (char*)0x005E64D4, 0x64 }, // 
	{ (char*)0x005E653C, 0x64 }, // 
	{ (char*)0x005E65A4, 0x64 }, // 
	{ (char*)0x005E660C, 0x64 }, // 
	{ (char*)0x005E6674, 0x64 }, // 
	{ (char*)0x005E66DC, 0x64 }, // 
	{ (char*)0x005E67AC, 0x64 }, // 
	{ (char*)0x005E6814, 0x64 }, // 
	{ (char*)0x005E687C, 0x64 }, // 
	{ (char*)0x005E68E4, 0x64 }, // 
	{ (char*)0x005E694C, 0x64 }, // 
	{ (char*)0x005E69B4, 0x64 }, // 
	{ (char*)0x005E6A1C, 0x64 }, // 
	{ (char*)0x005E6A84, 0x64 }, // 
	{ (char*)0x005E6AEC, 0x64 }, // 
	{ (char*)0x005E6B54, 0x64 }, // 
	{ (char*)0x005E6BBC, 0x64 }, // 
	{ (char*)0x005E6C24, 0x64 }, // 
	{ (char*)0x005E6C8C, 0x64 }, // 
	{ (char*)0x005E6CF4, 0x64 }, // 
	{ (char*)0x005E6D5C, 0x64 }, // 
	{ (char*)0x005E6DC4, 0x64 }, // 
	{ (char*)0x005E6E2C, 0x64 }, // 
	{ (char*)0x005E6E94, 0x64 }, // 
	{ (char*)0x005E6EFC, 0x64 }, // 
	{ (char*)0x005E6F64, 0x64 }, // 
	{ (char*)0x005E6FCC, 0x64 }, // 
	{ (char*)0x005E7034, 0x64 }, // 
	{ (char*)0x005E709C, 0x64 }, // 
	{ (char*)0x005E7104, 0x64 }, // 
	{ (char*)0x005E71D4, 0x64 }, // 
	{ (char*)0x005E723C, 0x64 }, // 
	{ (char*)0x005E72A4, 0x64 }, // 
	{ (char*)0x005E730C, 0x64 }, // 
	{ (char*)0x005E7374, 0x64 }, // 
	{ (char*)0x005E73DC, 0x64 }, // 
	{ (char*)0x005E7444, 0x64 }, // 
	{ (char*)0x005E74AC, 0x64 }, // 
	{ (char*)0x005E7514, 0x64 }, // 
	{ (char*)0x005E757C, 0x64 }, // 
	{ (char*)0x005E75E4, 0x64 }, // 
	{ (char*)0x005E764C, 0x64 }, // 
	{ (char*)0x005E76B4, 0x64 }, // 
	{ (char*)0x005E771C, 0x64 }, // 
	{ (char*)0x005E7784, 0x64 }, // 
	{ (char*)0x005E77EC, 0x64 }, // 
	{ (char*)0x005E7854, 0x64 }, // 
	{ (char*)0x005E78BC, 0x64 }, // 
	{ (char*)0x005E7924, 0x64 }, // 
	{ (char*)0x005E798C, 0x64 }, // 
	{ (char*)0x005E79F4, 0x64 }, // 
	{ (char*)0x005E7A5C, 0x64 }, // 
	{ (char*)0x005E7AC4, 0x64 }, // 
	{ (char*)0x005E7B2C, 0x64 }, // 
	{ (char*)0x005E7B94, 0x64 }, // 
	{ (char*)0x005E7BFC, 0x64 }, // 
	{ (char*)0x005E7C64, 0x64 }, // 
	{ (char*)0x005E7CCC, 0x64 }, // 
	{ (char*)0x005E7D34, 0x64 }, // 
	{ (char*)0x005E7D9C, 0x64 }, // 
	{ (char*)0x005E7E04, 0x64 }, // 
	{ (char*)0x005E7E6C, 0x64 }, // 
	{ (char*)0x005E7ED4, 0x64 }, // 
	{ (char*)0x005E7F3C, 0x64 }, // 
	{ (char*)0x005E7FA4, 0x64 }, // 
	{ (char*)0x005E800C, 0x64 }, // 
	{ (char*)0x005E8074, 0x64 }, // 
	{ (char*)0x005E80DC, 0x64 }, // 
	{ (char*)0x005E8144, 0x64 }, // 
	{ (char*)0x005E81AC, 0x64 }, // 
	{ (char*)0x005E8214, 0x64 }, // 
	{ (char*)0x005E827C, 0x64 }, // 
	{ (char*)0x005E82E4, 0x64 }, // 
	{ (char*)0x005E834C, 0x64 }, // 
	{ (char*)0x005E841C, 0x64 }, // 
	{ (char*)0x005E8484, 0x64 }, // 
	{ (char*)0x005E8554, 0x64 }, // 
	{ (char*)0x005E85BC, 0x64 }, // 
	{ (char*)0x005E8624, 0x64 }, // 
	{ (char*)0x005E868C, 0x64 }, // 
	{ (char*)0x005E86F4, 0x64 }, // 
	{ (char*)0x005E875C, 0x64 }, // 
	{ (char*)0x005E87C4, 0x64 }, // 
	{ (char*)0x005E882C, 0x64 }, // 
	{ (char*)0x005E8894, 0x64 }, // 
	{ (char*)0x005E88FC, 0x64 }, // 
	{ (char*)0x005E89CC, 0x64 }, // 
	{ (char*)0x005E8A34, 0x64 }, // 
	{ (char*)0x005E8A9C, 0x64 }, // 
	{ (char*)0x005E8B04, 0x64 }, // 
	{ (char*)0x005E8B6C, 0x64 }, // 
	{ (char*)0x005E8BD4, 0x64 }, // 
	{ (char*)0x005E8C3C, 0x64 }, // 
	{ (char*)0x005E8CA4, 0x64 }, // 
	{ (char*)0x005E8D0C, 0x64 }, // 
	{ (char*)0x005E8D74, 0x64 }, // 
	{ (char*)0x005E8DDC, 0x64 }, // 
	{ (char*)0x005E8E44, 0x64 }, // 
	{ (char*)0x005E8EAC, 0x64 }, // 
	{ (char*)0x005E8F14, 0x64 }, // 
	{ (char*)0x005E8F7C, 0x64 }, // 
	{ (char*)0x005E8FE4, 0x64 }, // 
	{ (char*)0x005E904C, 0x64 }, // 
	{ (char*)0x005E90B4, 0x64 }, // 
	{ (char*)0x005E911C, 0x64 }, // 
	{ (char*)0x005E9184, 0x64 }, // 
	{ (char*)0x005E91EC, 0x64 }, // 
	{ (char*)0x005E9254, 0x64 }, // 
	{ (char*)0x005E92BC, 0x64 }, // 
	{ (char*)0x005E9324, 0x64 }, // 
	{ (char*)0x005E938C, 0x64 }, // 
	{ (char*)0x005E93F4, 0x64 }, // 
	{ (char*)0x005E945C, 0x64 }, // 
	{ (char*)0x005E94C4, 0x64 }, // 
	{ (char*)0x005E952C, 0x64 }, // 
	{ (char*)0x005E9594, 0x64 }, // 
	{ (char*)0x005E95FC, 0x64 }, // 
	{ (char*)0x005E9664, 0x64 }, // 
	{ (char*)0x005E96CC, 0x64 }, // 
	{ (char*)0x005E9734, 0x64 }, // 
	{ (char*)0x005E979C, 0x64 }, // 
	{ (char*)0x005E9804, 0x64 }, // 
	{ (char*)0x005E986C, 0x64 }, // 
	{ (char*)0x005E98D4, 0x64 }, // 
	{ (char*)0x005E993C, 0x64 }, // 
	{ (char*)0x005E99A4, 0x64 }, // 
	{ (char*)0x005E9A0C, 0x64 }, // 
	{ (char*)0x005E9A74, 0x64 }, // 
	{ (char*)0x005E9ADC, 0x64 }, // 
	{ (char*)0x005E9B44, 0x64 }, // 
	{ (char*)0x005E9BAC, 0x64 }, // 
	{ (char*)0x005E9C14, 0x64 }, // 
	{ (char*)0x005E9C7C, 0x64 }, // 
	{ (char*)0x005E9CE4, 0x64 }, // 
	{ (char*)0x005E9D4C, 0x64 }, // 
	{ (char*)0x005E9DB4, 0x64 }, // 
	{ (char*)0x005E9E1C, 0x64 }, // 
	{ (char*)0x005E9E84, 0x64 }, // 
	{ (char*)0x005E9EEC, 0x64 }, // 
	{ (char*)0x005E9F54, 0x64 }, // 
	{ (char*)0x005E9FBC, 0x64 }, // 
	{ (char*)0x005EA024, 0x64 }, // 
	{ (char*)0x005EA08C, 0x64 }, // 
	{ (char*)0x005EA0F4, 0x64 }, // 
	{ (char*)0x005EA15C, 0x64 }, // 
	{ (char*)0x005EA1C4, 0x64 }, // 
	{ (char*)0x005EA22C, 0x64 }, // 
	{ (char*)0x005EA294, 0x64 }, // 
	{ (char*)0x005EA2FC, 0x64 }, // 
	{ (char*)0x005EA3CC, 0x64 }, // 
	{ (char*)0x005EA434, 0x64 }, // 
	{ (char*)0x005EA504, 0x64 }, // 
	{ (char*)0x005EA56C, 0x64 }, // 
	{ (char*)0x005EA5D4, 0x64 }, // 
	{ (char*)0x005EA63C, 0x64 }, // 
	{ (char*)0x005EA6A4, 0x64 }, // 
	{ (char*)0x005EA70C, 0x64 }, // 
	{ (char*)0x005EA774, 0x64 }, // 
	{ (char*)0x005EA7DC, 0x64 }, // 
	{ (char*)0x005EA844, 0x64 }, // 
	{ (char*)0x005EA8AC, 0x64 }, // 
	{ (char*)0x005EA914, 0x64 }, // 
	{ (char*)0x005EA97C, 0x64 }, // 
	{ (char*)0x005EA9E4, 0x64 }, // 
	{ (char*)0x005EAA4C, 0x64 }, // 
	{ (char*)0x005EAAB4, 0x64 }, // 
	{ (char*)0x005EAB1C, 0x64 }, // 
	{ (char*)0x005EAB84, 0x64 }, // 
	{ (char*)0x005EABEC, 0x64 }, // 
	{ (char*)0x005EAC54, 0x64 }, // 
	{ (char*)0x005EACBC, 0x64 }, // 
	{ (char*)0x005EAD24, 0x64 }, // 
	{ (char*)0x005EAD8C, 0x64 }, // 
	{ (char*)0x005EADF4, 0x64 }, // 
	{ (char*)0x005EAE5C, 0x64 }, // 
	{ (char*)0x005EAEC4, 0x64 }, // 
	{ (char*)0x005EB064, 0x64 }, // 
	{ (char*)0x005EB204, 0x64 }, // 
	{ (char*)0x005EB26C, 0x64 }, // 
	{ (char*)0x005EB2D4, 0x64 }, // 
	{ (char*)0x005EB33C, 0x64 }, // 
	{ (char*)0x005EB3A4, 0x64 }, // 
	{ (char*)0x005EB614, 0x64 }, // 
	{ (char*)0x005EB67C, 0x64 }, // 
	{ (char*)0x005EB6E4, 0x64 }, // 
	{ (char*)0x005EB74C, 0x64 }, // 
	{ (char*)0x005EB7B4, 0x64 }, // 
	{ (char*)0x005EB81C, 0x64 }, // 
	{ (char*)0x005EB884, 0x64 }, // 
	{ (char*)0x005EB8EC, 0x64 }, // 
	{ (char*)0x005EB954, 0x64 }, // 
	{ (char*)0x005EB9BC, 0x64 }, // 
	{ (char*)0x005EBA24, 0x64 }, // 
	{ (char*)0x006283B4, 0x28 }, //
	{ (char*)0x006283DC, 0x20 }, //
	{ (char*)0x006283FC, 0x24 }, //
	{ (char*)0x00628420, 0x2C }, //
	{ (char*)0x0062844C, 0x2C }, //
	{ (char*)0x00628478, 0x28 }, //
	{ (char*)0x006284A0, 0x24 }, //
	{ (char*)0x006284C4, 0x24 }, //
	{ (char*)0x006284E8, 0x2C }, //
	{ (char*)0x00628514, 0x28 }, //
	{ (char*)0x0062853C, 0x24 }, //
	{ (char*)0x00628560, 0x2C }, //
	{ (char*)0x0062858C, 0x2C }, //
	{ (char*)0x006285B8, 0x18 }, //
	{ (char*)0x006285D0, 0x20 }, //
	{ (char*)0x006285F0, 0x1C }, //
	{ (char*)0x0062860C, 0x7C }, //
	{ (char*)0x00628688, 0x7C }, //
	{ (char*)0x00628704, 0x7C }, //
	{ (char*)0x00628780, 0x7C }, //
	{ (char*)0x006287FC, 0x7C }, //
	{ (char*)0x00628878, 0x7C }, //
	{ (char*)0x006288F4, 0x7C }, //
	{ (char*)0x00628970, 0x20 }, //
	{ (char*)0x00628990, 0x20 }, //
	{ (char*)0x006289B0, 0x18 }, //
	{ (char*)0x006289C8, 0x18 }, //
	{ (char*)0x006289E0, 0x20 }, //
	{ (char*)0x00628A00, 0x20 }, //
	{ (char*)0x00628A20, 0x28 }, //
	{ (char*)0x00628A48, 0x18 }, //
	{ (char*)0x00628A60, 0x08 }, //
	{ (char*)0x00628A68, 0x18 }, //
	{ (char*)0x00628A80, 0x1C }, //
	{ (char*)0x00628A9C, 0x14 }, //
	{ (char*)0x00628AB0, 0x14 }, //
	{ (char*)0x00628AC4, 0x24 }, //
	{ (char*)0x00628AE8, 0x20 }, //
	{ (char*)0x00628B08, 0x0C }, //
	{ (char*)0x00628B14, 0x1C }, //
	{ (char*)0x00628B30, 0x20 }, //
	{ (char*)0x00628B50, 0x4C }, //
	{ (char*)0x00628B9C, 0x2C }, //
	{ (char*)0x00628BC8, 0x5C }, //
	{ (char*)0x00628C24, 0x34 }, //
	{ (char*)0x00628C58, 0x90 }, //
	{ (char*)0x00628CE8, 0x10 }, //
	{ (char*)0x00628CF8, 0x38 }, //
	{ (char*)0x00628D30, 0x2C }, //
	{ (char*)0x00628D5C, 0x38 }, //
	{ (char*)0x00628D94, 0x28 }, //
	{ (char*)0x00628DBC, 0x20 }, //
	{ (char*)0x00628DDC, 0x14 }, //
	{ (char*)0x00628DF0, 0x14 }, //
	{ (char*)0x00628E04, 0x28 }, //
	{ (char*)0x00628E2C, 0x18 }, //
	{ (char*)0x00628E44, 0x1C }, //
	{ (char*)0x00628E60, 0x38 }, //
	{ (char*)0x00628E98, 0x3C }, //
	{ (char*)0x00628ED4, 0x38 }, //
	{ (char*)0x00628F0C, 0x34 }, //
	{ (char*)0x00628F40, 0x2C }, //
	{ (char*)0x00628F6C, 0x2C }, //
	{ (char*)0x00628F98, 0x18 }, //
	{ (char*)0x00628FB0, 0x20 }, //
	{ (char*)0x00628FD0, 0x24 }, //
	{ (char*)0x00628FF4, 0x24 }, //
	{ (char*)0x00629018, 0x24 }, //
	{ (char*)0x0062903C, 0x24 }, //
	{ (char*)0x00629060, 0x24 }, //
	{ (char*)0x00629084, 0x28 }, //
	{ (char*)0x006290AC, 0x24 }, //
	{ (char*)0x006290D0, 0x40 }, //
	{ (char*)0x00629110, 0x54 }, //
	{ (char*)0x00629164, 0x3C }, //
	{ (char*)0x006291A0, 0x3C }, //
	{ (char*)0x006291DC, 0x38 }, //
	{ (char*)0x00629214, 0x1C }, //
	{ (char*)0x00629230, 0x20 }, //
	{ (char*)0x00629250, 0x20 }, //
	{ (char*)0x00629270, 0x1C }, //
	{ (char*)0x0062928C, 0x28 }, //
	{ (char*)0x006292B4, 0x28 }, //
	{ (char*)0x006292DC, 0x20 }, //
	{ (char*)0x006292FC, 0x24 }, //
	{ (char*)0x00629320, 0x28 }, //
	{ (char*)0x00629348, 0x24 }, //
	{ (char*)0x0062936C, 0x1C }, //
	{ (char*)0x00629388, 0x24 }, //
	{ (char*)0x006293AC, 0x30 }, //
	{ (char*)0x006293DC, 0x2C }, //
	{ (char*)0x00629408, 0x2C }, //
	{ (char*)0x00629434, 0x20 }, //
	{ (char*)0x00629454, 0x28 }, //
	{ (char*)0x0062947C, 0x28 }, //
	{ (char*)0x006294A4, 0x24 }, //
	{ (char*)0x0062E08C, 0x14 }, //
	{ (char*)0x0062E078, 0x14 }, //
	{ (char*)0x0062E064, 0x14 }, //
	{ (char*)0x0062E050, 0x14 }, //
	{ (char*)0x0062E03C, 0x14 }, //
	{ (char*)0x0062E028, 0x14 }, //
	{ (char*)0x0062E014, 0x14 }, //
	{ (char*)0x0062E000, 0x14 }, //
	{ (char*)0x0062DFEC, 0x14 }, //
	{ (char*)0x0062DFD8, 0x14 }, //
	{ (char*)0x0062DFC4, 0x14 }, //
	{ (char*)0x0062DFB0, 0x14 }, //
	{ (char*)0x0062DF9C, 0x14 }, //
	{ (char*)0x0062DF88, 0x14 }, //
	{ (char*)0x0062DF74, 0x14 }, //
	{ (char*)0x0062DF60, 0x14 }, //
	{ (char*)0x0062DF4C, 0x14 }, //
	{ (char*)0x0062DF38, 0x14 }, //
	{ (char*)0x0062DF24, 0x14 }, //
	{ (char*)0x0062DF10, 0x14 }, //
	{ (char*)0x0062DEFC, 0x14 }, //
	{ (char*)0x0062DEE8, 0x14 }, //
	{ (char*)0x0062DED4, 0x14 }, //
	{ (char*)0x0062DEC0, 0x14 }, //
	{ (char*)0x0062DEAC, 0x14 }, //
	{ (char*)0x0062DE98, 0x14 }, //
	{ (char*)0x0062DE84, 0x14 }, //
	{ (char*)0x0062DE70, 0x14 }, //
	{ (char*)0x0062DE5C, 0x14 }, //
	{ (char*)0x0062DE48, 0x14 }, //
	{ (char*)0x0062DE34, 0x14 }, //
	{ (char*)0x0062DE20, 0x14 }, //
	{ (char*)0x0062DE0C, 0x14 }, //
	{ (char*)0x0062DDF8, 0x14 }, //
	{ (char*)0x0062DDE4, 0x14 }, //
	{ (char*)0x0062DDD0, 0x14 }, //
	{ (char*)0x0062DDBC, 0x14 }, //
	{ (char*)0x0062DDA8, 0x14 }, //
	{ (char*)0x0062DD94, 0x14 }, //
	{ (char*)0x0062F330, 0x1C }, //
	{ (char*)0x0062F34C, 0x24 }, //
	{ (char*)0x0062F370, 0x20 }, //
	{ (char*)0x0062F390, 0x20 }, //
	{ (char*)0x0062F3B0, 0x24 }, //
	{ (char*)0x0062F3D4, 0x1C }, //
	{ (char*)0x0062F3F0, 0x3C }, //
	{ (char*)0x0062F42C, 0x28 }, //
	{ (char*)0x0062F454, 0x24 }, //
	{ (char*)0x0062F478, 0x28 }, //
	{ (char*)0x0062F4A0, 0x24 }, //
	{ (char*)0x0062F4C4, 0x2C }, //
	{ (char*)0x0062F4F0, 0x1C }, //
	{ (char*)0x0062F50C, 0x24 }, //
	{ (char*)0x0062F530, 0x28 }, //
	{ (char*)0x0062F558, 0x20 }, //
	{ (char*)0x0062F578, 0x24 }, //
	{ (char*)0x0062F59C, 0x34 }, //
	{ (char*)0x0062F5D0, 0x30 }, //
	{ (char*)0x0062F600, 0x2C }, //
	{ (char*)0x0062F62C, 0x24 }, //
	{ (char*)0x0062F650, 0x28 }, //
	{ (char*)0x0062F678, 0x34 }, //
	{ (char*)0x0062F6AC, 0x24 }, //
	{ (char*)0x0062F6D0, 0x24 }, //
	{ (char*)0x0062F6F4, 0x28 }, //
	{ (char*)0x0062F71C, 0x20 }, //
	{ (char*)0x0062F73C, 0x18 }, //
	{ (char*)0x0062F754, 0x18 }, //
	{ (char*)0x0062F76C, 0x18 }, //
	{ (char*)0x0062F784, 0x24 }, //
	{ (char*)0x0062F7A8, 0x24 }, //
	{ (char*)0x0062F7CC, 0x28 }, //
	{ (char*)0x0062F7F4, 0x30 }, //
	{ (char*)0x0062F824, 0x20 }, //
	{ (char*)0x0062F844, 0x18 }, //
	{ (char*)0x0062F85C, 0x1C }, //
	{ (char*)0x0062F878, 0x1C }, //
	{ (char*)0x0062F894, 0x34 }, //
	{ (char*)0x0062F8C8, 0x14 }, //
	{ (char*)0x0062F8DC, 0x2C }, //
	{ (char*)0x0062F908, 0x24 }, //
	{ (char*)0x0062F92C, 0x2C }, //
	{ (char*)0x0062F958, 0x30 }, //
	{ (char*)0x0062F988, 0x50 }, //
	{ (char*)0x0062F9D8, 0x18 }, //
	{ (char*)0x0062F9F0, 0x30 }, //
	{ (char*)0x0062FA20, 0x64 }, //
	{ (char*)0x0062FA84, 0x20 }, //
	{ (char*)0x0062FAA4, 0x54 }, //
	{ (char*)0x0062FAF8, 0x34 }, //
	{ (char*)0x0062FB2C, 0x24 }, //
	{ (char*)0x0062FB50, 0x24 }, //
	{ (char*)0x0062FB74, 0x3C }, //
	{ (char*)0x0062FBB0, 0x20 }, //
	{ (char*)0x0062FBD0, 0x20 }, //
	{ (char*)0x0062FBF0, 0x38 }, //
	{ (char*)0x0062FC28, 0x2C }, //
	{ (char*)0x0062FC54, 0x20 }, //
	{ (char*)0x0062FC74, 0x24 }, //
	{ (char*)0x0062FC98, 0x2C }, //
	{ (char*)0x0062FCC4, 0x1C }, //
	{ (char*)0x0062FCE0, 0x1C }, //
	{ (char*)0x0062FCFC, 0x1C }, //
	{ (char*)0x0062FD18, 0x20 }, //
	{ (char*)0x0062FD38, 0x24 }, //
	{ (char*)0x0062FD5C, 0x1C }, //
	{ (char*)0x0062FD78, 0x1C }, //
	{ (char*)0x0062FD94, 0x24 }, //
	{ (char*)0x0062FDB8, 0x28 }, //
	{ (char*)0x0062FDE0, 0x3C }, //
	{ (char*)0x0062FE1C, 0x28 }, //
	{ (char*)0x0062FE44, 0x20 }, //
	{ (char*)0x0062FE64, 0x20 }, //
	{ (char*)0x0062FE84, 0x28 }, //
	{ (char*)0x0062FEAC, 0x18 }, //
	{ (char*)0x0062FEC4, 0x20 }, //
	{ (char*)0x0062FEE4, 0x20 }, //
	{ (char*)0x0062FF04, 0x1C }, //
	{ (char*)0x0062FF20, 0x18 }, //
	{ (char*)0x0062FF38, 0x18 }, //
	{ (char*)0x0062FF50, 0x28 }, //
	{ (char*)0x0062FF78, 0x2C }, //
	{ (char*)0x0062FFA4, 0x20 }, //
	{ (char*)0x0062FFC4, 0x1C }, //
	{ (char*)0x0062FFE0, 0x28 }, //
	{ (char*)0x00630008, 0x20 }, //
	{ (char*)0x00630028, 0x1C }, //
	{ (char*)0x00630044, 0x28 }, //
	{ (char*)0x0063006C, 0x20 }, //
	{ (char*)0x0063008C, 0x34 }, //
	{ (char*)0x006300C0, 0x18 }, //
	{ (char*)0x006300D8, 0x2C }, //
	{ (char*)0x00630104, 0x20 }, //
	{ (char*)0x00630124, 0x28 }, //
	{ (char*)0x0063014C, 0x20 }, //
	{ (char*)0x0063016C, 0x20 }, //
	{ (char*)0x0063018C, 0x28 }, //
	{ (char*)0x006301B4, 0x28 }, //
	{ (char*)0x006301DC, 0x18 }, //
	{ (char*)0x006301F4, 0x40 }, //
	{ (char*)0x00630234, 0x1C }, //
	{ (char*)0x00630250, 0x18 }, //
	{ (char*)0x00630268, 0x20 }, //
	{ (char*)0x006389FC, 0x7C }, //
	{ (char*)0x00638A78, 0x80 }, //
	{ (char*)0x00638AF8, 0x80 }, // 875
	{ (char*)0x00638B78, 0x36 }, //
	{ (char*)0x00638BAE, 0x4A }, //
	{ (char*)0x00638BF8, 0x80 }, //
	{ (char*)0x00638C78, 0x80 }, //
	{ (char*)0x00638D4C, 0x1C }, //
	{ (char*)0x00638ED4, 0x18 }, //
	{ (char*)0x00638EF8, 0x14 }, //
	{ (char*)0x00638F18, 0x20 }, //
	{ (char*)0x00638F40, 0x24 }, //
	{ (char*)0x00638F6C, 0x1C }, //
	{ (char*)0x0063A17C, 0x18 }, //
	{ (char*)0x0063A1BC, 0x38 }, //
	{ (char*)0x0063A1F4, 0x34 }, //
	{ (char*)0x0063A228, 0x1C }, //
	{ (char*)0x0063EE4E, 0x1C }, //
	{ (char*)0x0063EE7C, 0x1C }, //
	{ (char*)0x0063EEAC, 0x1C }, //
	{ (char*)0x0063EED8, 0x1C }, //
	{ (char*)0x0063EF1C, 0x1C }, //
	{ (char*)0x0063EF54, 0x1C }, //
	{ (char*)0x0063EF8C, 0x1C }, //
	{ (char*)0x0063EFC0, 0x1C }, //
	{ (char*)0x0063EFF0, 0x1C }, //
	{ (char*)0x0063F028, 0x1C }, //
	{ (char*)0x0063F068, 0x1C }, //
	{ (char*)0x0063F084, 0x1C }, //
	{ (char*)0x0063F0A4, 0x1C }, //
	{ (char*)0x0063F0C4, 0x1C }, //
	{ (char*)0x0063F0E0, 0x1C }, //
	{ (char*)0x0063F0FC, 0x1C }, //
	{ (char*)0x0063F118, 0x1C }, //
	{ (char*)0x00647540, 0x58 }, //
	{ (char*)0x006475A4, 0x48 }, //
	{ (char*)0x00647614, 0x18 }, //
	{ (char*)0x00647638, 0x0C }, //
	{ (char*)0x00647650, 0x0C }, //
	{ (char*)0x00647684, 0x10 }, //
	{ (char*)0x0064A82C, 0x2C }, //
	{ (char*)0x0064A864, 0x40 }, //
	{ (char*)0x0064CDA0, 0x38 }, //
	{ (char*)0x0064CDE4, 0x3C }, //
	{ (char*)0x0064CE38, 0x20 }, //
	{ (char*)0x0064CE64, 0x44 }, //
	{ (char*)0x0064CEA8, 0x2C }, //
	{ (char*)0x0064CED4, 0x28 }, //
	{ (char*)0x00652C7C, 0x10C },//
	{ (char*)0x00652D88, 0x14 }, //
	{ (char*)0x00652D9C, 0x10C },//
	{ (char*)0x00652EA8, 0x14 }, //
	{ (char*)0x00652EBC, 0x10C },//
	{ (char*)0x00652FC8, 0x18 }, //
	{ (char*)0x00652FE0, 0x10C },//
	{ (char*)0x006530EC, 0x18 }, //
	{ (char*)0x0063032C, 0x18 }, //
	{ (char*)0x00654630, 0x0C }, //
	{ (char*)0x00654660, 0x0C }, //
	{ (char*)0x00654690, 0x0C }, //
	{ (char*)0x006546C0, 0x0C }, //
	{ (char*)0x006546CC, 0x1C }, //
	{ (char*)0x006546E8, 0x20 }, //
	{ (char*)0x006547B0, 0x20 }, //
	{ (char*)0x0065572C, 0x18 }, //
	{ (char*)0x00657050, 0x10 }, //
	{ (char*)0x00657060, 0x10 }, //
	{ (char*)0x006924A0, 0x0C }, //
	{ (char*)0x006924AC, 0x10 }, //
	{ (char*)0x006924BC, 0x10 }, //
	{ (char*)0x006924CC, 0x10 }, //
	{ (char*)0x006924DC, 0x10 }, //
	{ (char*)0x006924EC, 0x10 }, //
	{ (char*)0x006927F0, 0x28 }, //
	{ (char*)0x00692818, 0x20 }, //
	{ (char*)0x00692848, 0x30 }, //
	{ (char*)0x00692878, 0x34 }, //
	{ (char*)0x006928AC, 0x28 }, //
	{ (char*)0x006928D4, 0x2C }, //
	{ (char*)0x00692900, 0x30 }, //
	{ (char*)0x00692930, 0x28 }, //
	{ (char*)0x00692958, 0x38 }, //
	{ (char*)0x00692990, 0x2C }, //
	{ (char*)0x006929BC, 0x40 }, //
};

const char** rivalTeamNameTable = (const char**)0x006509D4;
const char** rivalHandleTable = (const char**)0x00650A8C;

const STRINGREPLACEENTRY replaceStrings[]{
	{ nullptr, nullptr },
	{ (char*)0x0063100C, "\nFailed to restore game data.", 0x24 },
	{ (char*)0x00631030, "\nDirect3D: Device reset failed", 0x2C },
	{ (char*)0x0063105C, "\nFailed to release game data.", 0x2C },
};

int* itemIDNumber[]{
	(int*)(0x0045FC40 + 0x16),
	(int*)(0x0045FC80 + 0x16),
	(int*)(0x0045FCC0 + 0x08),
	(int*)(0x0045FCF0 + 0x08),
	(int*)(0x004386E0 + 0x1D1),
};

int* itemIDName[]{
	(int*)(0x0045FC40 + 0x33),
	(int*)(0x0045FCC0 + 0x25),
};

int* itemIDDescription[]{
	(int*)(0x0045FC80 + 0x33),
	(int*)(0x0045FCF0 + 0x25),
	(int*)(0x004386E0 + 0x1F9),
};

int* itemIDEnd[]{
	(int*)(0x0045FC40 + 0x24),
	(int*)(0x0045FC80 + 0x24),
	(int*)(0x0045FCC0 + 0x16),
	(int*)(0x0045FCF0 + 0x16),
};

int* itemIDMid[]{ // Add (2034 * 12) + 8 to the itemDetailsAddress (2034 items so increase with any additional items)
	(int*)(0x0045EFF0 + 0x17B),
};

int* itemIDMid2[]{ // Add (2071 * 12) to the itemDetailsAddress (2071 items so increase with any additional items)
	(int*)(0x004386E0 + 0x1E9),
};

int* itemSpriteSmallID[]{
	(int*)(0x0045FB10 + 0x1E),
};

int* itemSpriteSmallSprite[]{ // Add 4 to itemSpritesSmall
	(int*)(0x0045FB6C),
};

int* itemSpriteSmallEnd[]{ // Add Size of itemSpritesSmall to itemSpritesSmall
	(int*)(0x0045FB3C),
};

int* itemSpriteBigID[]{
	(int*)(0x0045FBA0 + 0x36),
};

int* itemSpriteBigSprite[]{ // Add 4 to itemSpritesBig
	(int*)(0x0045FC14),
};

int* itemSpriteBigEnd[]{ // Add Size of itemSpritesBig to itemSpritesBig
	(int*)(0x0045FBA0 + 0x44),
};

const ITEMSPRITE itemSpritesSmall[]{
	{ 0, 79 },
	{ 2, 79 },
	{ 1, 80 },
	{ 3, 80 },
	{ 4, 81 },
	{ 5, 82 },
	{ 6, 82 },
	{ 7, 82 },
	{ 8, 83 },
	{ 9, 84 },
	{ 10, 84 },
	{ 11, 85 },
	{ 12, 86 },
	{ 13, 86 },
	{ 14, 86 },
	{ 15, 86 },
	{ 16, 86 },
	{ 17, 86 },
	{ 18, 86 },
	{ 19, 87 },
	{ 20, 87 },
	{ 21, 88 },
	{ 22, 88 },
	{ 23, 88 },
	{ 24, 88 },
	{ 25, 88 },
	{ 26, 88 },
	{ 27, 89 },
	{ 28, 89 },
	{ 29, 90 },
	{ 30, 91 },
	{ 31, 92 },
	{ 32, 92 },
	{ 33, 92 },
	{ 34, 92 },
	{ 35, 92 },
	{ 36, 93 },
	{ 37, 94 },
	{ 38, 94 },
	{ 39, 63 },
	{ 40, 63 },
	{ 41, 63 },
	{ 42, 63 },
	{ 43, 63 },
	{ 44, 63 },
	{ 45, 63 },
	{ 46, 63 },
	{ 47, 63 },
	{ 48, 63 },
	{ 49, 89 },
	{ 50, 89 },
	{ 51, 64 },
	{ 52, 65 },
	{ 53, 65 },
	{ 54, 66 },
	{ 55, 66 },
	{ 56, 67 },
	{ 57, 68 },
	{ 58, 69 },
	{ 59, 70 },
	{ 60, 70 },
	{ 61, 74 },
	{ 62, 71 },
	{ 63, 90 },
	{ 64, 91 },
	{ 65, 72 },
	{ 66, 72 },
	{ 67, 73 },
	{ 68, 73 },
	{ 69, 74 },
	{ 70, 75 },
	{ 71, 76 },
	{ 72, 77 },
	{ 73, 78 },
	{ 74, 62 },
	{ 75, 88 },
	{ 76, 88 },
	{ 77, 88 },
	{ 78, 93 },
	{ 79, 58 },
	{ 80, 59 },
	{ 81, 60 },
	{ 82, 82 },
	{ 83, 82 },
	{ 84, 92 },
	{ 85, 63 },
	{ 86, 63 },
	{ 87, 61 },
	{ 2071, 0 },
	{ 2072, 0 },
	{ 2073, 0 },
	{ 2074, 0 },
	{ 2075, 0 },
	{ 2076, 0 },
	{ 2077, 1 },
	{ 2078, 1 },
	{ 2079, 1 },
	{ 2080, 1 },
	{ 2081, 1 },
	{ 2082, 1 },
	{ 2085, 6 },
	{ 2086, 6 },
	{ 2087, 6 },
	{ 2088, 6 },
	{ 2089, 6 },
	{ 2090, 6 },
	{ 2091, 7 },
	{ 2092, 7 },
	{ 2093, 7 },
	{ 2094, 7 },
	{ 2095, 7 },
	{ 2096, 7 },
	{ 2097, 8 },
	{ 2098, 8 },
	{ 2099, 8 },
	{ 2100, 8 },
	{ 2101, 8 },
	{ 2102, 8 },
	{ 2103, 9 },
	{ 2104, 9 },
	{ 2105, 9 },
	{ 2106, 9 },
	{ 2107, 9 },
	{ 2108, 9 },
	{ 2109, 10 },
	{ 2110, 11 },
	{ 2111, 13 },
	{ 2112, 12 },
	{ 2113, 14 },
	{ 2114, 17 },
	{ 2115, 15 },
	{ 2116, 16 },
	{ 2117, 18 },
	{ 2159, 19 },
	{ 2160, 20 },
	{ 2161, 21 },
	{ 2162, 22 },
	{ 2163, 23 },
	{ 2164, 24 },
	{ 2165, 25 },
	{ 2169, 26 },
	{ 2170, 27 },
	{ 2219, 28 },
	{ 2220, 29 },
	{ 2221, 30 },
	{ 2222, 31 },
	{ 2223, 32 },
	{ 2269, 33 },
	{ 2270, 36 },
	{ 2271, 37 },
};
const ITEMSPRITE itemSpritesBig[]{
	{ 0, 87 },
	{ 2, 87 },
	{ 1, 88 },
	{ 3, 88 },
	{ 4, 89 },
	{ 5, 90 },
	{ 6, 90 },
	{ 7, 90 },
	{ 8, 91 },
	{ 9, 92 },
	{ 10, 92 },
	{ 11, 93 },
	{ 12, 94 },
	{ 13, 94 },
	{ 14, 94 },
	{ 15, 94 },
	{ 16, 94 },
	{ 17, 94 },
	{ 18, 94 },
	{ 19, 79 },
	{ 20, 79 },
	{ 21, 80 },
	{ 22, 80 },
	{ 23, 80 },
	{ 24, 80 },
	{ 25, 80 },
	{ 26, 80 },
	{ 27, 81 },
	{ 28, 81 },
	{ 29, 82 },
	{ 30, 83 },
	{ 31, 84 },
	{ 32, 84 },
	{ 33, 84 },
	{ 34, 84 },
	{ 35, 84 },
	{ 36, 85 },
	{ 37, 86 },
	{ 38, 86 },
	{ 39, 71 },
	{ 40, 71 },
	{ 41, 71 },
	{ 42, 71 },
	{ 43, 71 },
	{ 44, 71 },
	{ 45, 71 },
	{ 46, 71 },
	{ 47, 71 },
	{ 48, 71 },
	{ 49, 81 },
	{ 50, 81 },
	{ 51, 72 },
	{ 52, 73 },
	{ 53, 73 },
	{ 54, 74 },
	{ 55, 74 },
	{ 56, 75 },
	{ 57, 76 },
	{ 58, 77 },
	{ 59, 78 },
	{ 60, 78 },
	{ 61, 74 },
	{ 62, 63 },
	{ 63, 82 },
	{ 64, 83 },
	{ 65, 64 },
	{ 66, 64 },
	{ 67, 65 },
	{ 68, 65 },
	{ 69, 66 },
	{ 70, 67 },
	{ 71, 68 },
	{ 72, 69 },
	{ 73, 70 },
	{ 74, 62 },
	{ 75, 80 },
	{ 76, 80 },
	{ 77, 80 },
	{ 78, 85 },
	{ 79, 58 },
	{ 80, 59 },
	{ 81, 60 },
	{ 82, 90 },
	{ 83, 90 },
	{ 84, 84 },
	{ 85, 71 },
	{ 86, 71 },
	{ 87, 61 },
	{ 2071, 0 },
	{ 2072, 0 },
	{ 2073, 0 },
	{ 2074, 0 },
	{ 2075, 0 },
	{ 2076, 0 },
	{ 2077, 1 },
	{ 2078, 1 },
	{ 2079, 1 },
	{ 2080, 1 },
	{ 2081, 1 },
	{ 2082, 1 },
	{ 2085, 6 },
	{ 2086, 6 },
	{ 2087, 6 },
	{ 2088, 6 },
	{ 2089, 6 },
	{ 2090, 6 },
	{ 2091, 7 },
	{ 2092, 7 },
	{ 2093, 7 },
	{ 2094, 7 },
	{ 2095, 7 },
	{ 2096, 7 },
	{ 2097, 8 },
	{ 2098, 8 },
	{ 2099, 8 },
	{ 2100, 8 },
	{ 2101, 8 },
	{ 2102, 8 },
	{ 2103, 9 },
	{ 2104, 9 },
	{ 2105, 9 },
	{ 2106, 9 },
	{ 2107, 9 },
	{ 2108, 9 },
	{ 2109, 10 },
	{ 2110, 11 },
	{ 2111, 12 },
	{ 2112, 13 },
	{ 2113, 14 },
	{ 2114, 17 },
	{ 2115, 15 },
	{ 2116, 16 },
	{ 2117, 18 },
	{ 2159, 19 },
	{ 2160, 20 },
	{ 2161, 21 },
	{ 2162, 22 },
	{ 2163, 23 },
	{ 2164, 24 },
	{ 2165, 25 },
	{ 2169, 26 },
	{ 2170, 27 },
	{ 2219, 28 },
	{ 2220, 29 },
	{ 2221, 30 },
	{ 2222, 31 },
	{ 2223, 32 },
	{ 2269, 33 },
	{ 2270, 36 },
	{ 2271, 37 },
};

const ITEMDETAILENTRY* itemDetailsInternal1 = (ITEMDETAILENTRY*)0x005C34E8;
const ITEMDETAILENTRY* itemDetailsInternal2 = (ITEMDETAILENTRY*)0x005CE868;
extern ITEMDETAILENTRY* itemDetailsJson;

const ITEMDETAILENTRY itemDetails[]{
	{ 0, (char*)(0x0063684C), (char*)(0x0063682C) },
	{ 1, (char*)(0x0063684C), (char*)(0x00636808) },
	{ 2, (char*)(0x0063684C), (char*)(0x006367E8) },
	{ 3, (char*)(0x0063684C), (char*)(0x006367C4) },
	{ 4, (char*)(0x0063684C), (char*)(0x006367B0) },
	{ 5, (char*)(0x0063684C), (char*)(0x00636798) },
	{ 6, (char*)(0x0063684C), (char*)(0x00636780) },
	{ 7, (char*)(0x0063684C), (char*)(0x00636768) },
	{ 8, (char*)(0x0063684C), (char*)(0x00636744) },
	{ 9, (char*)(0x0063684C), (char*)(0x00636728) },
	{ 10, (char*)(0x0063684C), (char*)(0x0063670C) },
	{ 11, (char*)(0x0063684C), (char*)(0x006366EC) },
	{ 12, (char*)(0x0063684C), (char*)(0x006366D4) },
	{ 13, (char*)(0x0063684C), (char*)(0x006366BC) },
	{ 14, (char*)(0x0063684C), (char*)(0x006366A4) },
	{ 15, (char*)(0x0063684C), (char*)(0x0063668C) },
	{ 16, (char*)(0x0063684C), (char*)(0x00636674) },
	{ 17, (char*)(0x0063684C), (char*)(0x00636658) },
	{ 18, (char*)(0x0063684C), (char*)(0x0063663C) },
	{ 19, (char*)(0x0063684C), (char*)(0x00636620) },
	{ 20, (char*)(0x0063684C), (char*)(0x00636604) },
	{ 21, (char*)(0x0063684C), (char*)(0x006365E0) },
	{ 22, (char*)(0x0063684C), (char*)(0x006365C4) },
	{ 23, (char*)(0x0063684C), (char*)(0x006365A0) },
	{ 24, (char*)(0x0063684C), (char*)(0x00636580) },
	{ 25, (char*)(0x0063684C), (char*)(0x00636560) },
	{ 26, (char*)(0x0063684C), (char*)(0x00636540) },
	{ 27, (char*)(0x0063684C), (char*)(0x0063650C) },
	{ 28, (char*)(0x0063684C), (char*)(0x006364DC) },
	{ 29, (char*)(0x0063684C), (char*)(0x006364BC) },
	{ 30, (char*)(0x0063684C), (char*)(0x00636494) },
	{ 31, (char*)(0x0063684C), (char*)(0x0063646C) },
	{ 32, (char*)(0x0063684C), (char*)(0x00636444) },
	{ 33, (char*)(0x0063684C), (char*)(0x0063641C) },
	{ 34, (char*)(0x0063684C), (char*)(0x006363F4) },
	{ 35, (char*)(0x0063684C), (char*)(0x006363B4) },
	{ 36, (char*)(0x0063684C), (char*)(0x00636394) },
	{ 37, (char*)(0x0063684C), (char*)(0x0063637C) },
	{ 38, (char*)(0x0063684C), (char*)(0x00636364) },
	{ 39, (char*)(0x0063684C), (char*)(0x00636348) },
	{ 40, (char*)(0x0063684C), (char*)(0x00636324) },
	{ 41, (char*)(0x0063684C), (char*)(0x006362F8) },
	{ 42, (char*)(0x0063684C), (char*)(0x006362D4) },
	{ 43, (char*)(0x0063684C), (char*)(0x006362A8) },
	{ 44, (char*)(0x0063684C), (char*)(0x00636284) },
	{ 45, (char*)(0x0063684C), (char*)(0x00636258) },
	{ 46, (char*)(0x0063684C), (char*)(0x00636228) },
	{ 47, (char*)(0x0063684C), (char*)(0x006361F8) },
	{ 48, (char*)(0x0063684C), (char*)(0x006361C8) },
	{ 49, (char*)(0x0063684C), (char*)(0x006361AC) },
	{ 50, (char*)(0x0063684C), (char*)(0x0063618C) },
	{ 51, (char*)(0x0063684C), (char*)(0x00636170) },
	{ 52, (char*)(0x0063684C), (char*)(0x00636158) },
	{ 53, (char*)(0x0063684C), (char*)(0x00636140) },
	{ 54, (char*)(0x0063684C), (char*)(0x00636124) },
	{ 55, (char*)(0x0063684C), (char*)(0x00636108) },
	{ 56, (char*)(0x0063684C), (char*)(0x006360E8) },
	{ 57, (char*)(0x0063684C), (char*)(0x006360C8) },
	{ 58, (char*)(0x0063684C), (char*)(0x0063609C) },
	{ 59, (char*)(0x0063684C), (char*)(0x00636084) },
	{ 60, (char*)(0x0063684C), (char*)(0x0063605C) },
	{ 61, (char*)(0x0063684C), (char*)(0x0063602C) },
	{ 62, (char*)(0x0063684C), (char*)(0x00636018) },
	{ 63, (char*)(0x0063684C), (char*)(0x00635FFC) },
	{ 64, (char*)(0x0063684C), (char*)(0x00635FDC) },
	{ 65, (char*)(0x0063684C), (char*)(0x00635FB4) },
	{ 66, (char*)(0x0063684C), (char*)(0x00635F8C) },
	{ 67, (char*)(0x0063684C), (char*)(0x00635F64) },
	{ 68, (char*)(0x0063684C), (char*)(0x00635F3C) },
	{ 69, (char*)(0x0063684C), (char*)(0x00635F2C) },
	{ 70, (char*)(0x0063684C), (char*)(0x00635F14) },
	{ 71, (char*)(0x0063684C), (char*)(0x00635EF0) },
	{ 72, (char*)(0x0063684C), (char*)(0x00635ED4) },
	{ 73, (char*)(0x0063684C), (char*)(0x00635EB4) },
	{ 74, (char*)(0x0063684C), (char*)(0x00635E98) },
	{ 75, (char*)(0x0063684C), (char*)(0x00635E78) },
	{ 76, (char*)(0x0063684C), (char*)(0x00635E54) },
	{ 77, (char*)(0x0063684C), (char*)(0x00635E30) },
	{ 78, (char*)(0x0063684C), (char*)(0x00635E10) },
	{ 79, (char*)(0x0063684C), (char*)(0x00635DF0) },
	{ 80, (char*)(0x0063684C), (char*)(0x00635DDC) },
	{ 81, (char*)(0x0063684C), (char*)(0x00635DB4) },
	{ 82, (char*)(0x0063684C), (char*)(0x00635D94) },
	{ 83, (char*)(0x0063684C), (char*)(0x00635D70) },
	{ 84, (char*)(0x0063684C), (char*)(0x00635D48) },
	{ 85, (char*)(0x0063684C), (char*)(0x00635D2C) },
	{ 86, (char*)(0x0063684C), (char*)(0x00635D10) },
	{ 87, (char*)(0x0063684C), (char*)(0x00635CF0) },
	{ 88, (char*)(0x00635CCC), (char*)(0x00635CBC) },
	{ 89, (char*)(0x00635C98), (char*)(0x00635CBC) },
	{ 90, (char*)(0x00635C74), (char*)(0x00635CBC) },
	{ 91, (char*)(0x00635C50), (char*)(0x00635CBC) },
	{ 92, (char*)(0x00635C2C), (char*)(0x00635CBC) },
	{ 93, (char*)(0x00635C08), (char*)(0x00635CBC) },
	{ 94, (char*)(0x00635BE4), (char*)(0x00635CBC) },
	{ 95, (char*)(0x00635BC0), (char*)(0x00635CBC) },
	{ 96, (char*)(0x00635B9C), (char*)(0x00635CBC) },
	{ 97, (char*)(0x00635B78), (char*)(0x00635CBC) },
	{ 98, (char*)(0x00635B54), (char*)(0x00635CBC) },
	{ 99, (char*)(0x00635B30), (char*)(0x00635CBC) },
	{ 100, (char*)(0x00635B0C), (char*)(0x00635CBC) },
	{ 101, (char*)(0x00635AE8), (char*)(0x00635CBC) },
	{ 102, (char*)(0x00635AC4), (char*)(0x00635CBC) },
	{ 103, (char*)(0x00635A98), (char*)(0x00635CBC) },
	{ 104, (char*)(0x00635A6C), (char*)(0x00635CBC) },
	{ 105, (char*)(0x00635A40), (char*)(0x00635CBC) },
	{ 106, (char*)(0x00635A14), (char*)(0x00635CBC) },
	{ 107, (char*)(0x006359F4), (char*)(0x00635CBC) },
	{ 108, (char*)(0x006359D4), (char*)(0x00635CBC) },
	{ 109, (char*)(0x006359B4), (char*)(0x00635CBC) },
	{ 110, (char*)(0x00635994), (char*)(0x00635CBC) },
	{ 111, (char*)(0x00635974), (char*)(0x00635CBC) },
	{ 112, (char*)(0x00635954), (char*)(0x00635CBC) },
	{ 113, (char*)(0x00635934), (char*)(0x00635CBC) },
	{ 114, (char*)(0x00635914), (char*)(0x00635CBC) },
	{ 115, (char*)(0x006358F4), (char*)(0x00635CBC) },
	{ 116, (char*)(0x006358CC), (char*)(0x00635CBC) },
	{ 117, (char*)(0x006358A4), (char*)(0x00635CBC) },
	{ 118, (char*)(0x0063587C), (char*)(0x00635CBC) },
	{ 119, (char*)(0x00635854), (char*)(0x00635CBC) },
	{ 120, (char*)(0x0063582C), (char*)(0x00635CBC) },
	{ 121, (char*)(0x00635804), (char*)(0x00635CBC) },
	{ 122, (char*)(0x006357DC), (char*)(0x00635CBC) },
	{ 123, (char*)(0x006357B4), (char*)(0x00635CBC) },
	{ 124, (char*)(0x00635790), (char*)(0x00635CBC) },
	{ 125, (char*)(0x0063576C), (char*)(0x00635CBC) },
	{ 126, (char*)(0x00635748), (char*)(0x00635CBC) },
	{ 127, (char*)(0x00635724), (char*)(0x00635CBC) },
	{ 128, (char*)(0x00635700), (char*)(0x00635CBC) },
	{ 129, (char*)(0x006356D4), (char*)(0x00635CBC) },
	{ 130, (char*)(0x006356A8), (char*)(0x00635CBC) },
	{ 131, (char*)(0x0063567C), (char*)(0x00635CBC) },
	{ 132, (char*)(0x00635650), (char*)(0x00635CBC) },
	{ 133, (char*)(0x00635624), (char*)(0x00635CBC) },
	{ 134, (char*)(0x00635600), (char*)(0x00635CBC) },
	{ 135, (char*)(0x006355DC), (char*)(0x00635CBC) },
	{ 136, (char*)(0x006355B8), (char*)(0x00635CBC) },
	{ 137, (char*)(0x00635594), (char*)(0x00635CBC) },
	{ 138, (char*)(0x00635570), (char*)(0x00635CBC) },
	{ 139, (char*)(0x00635548), (char*)(0x00635CBC) },
	{ 140, (char*)(0x00635520), (char*)(0x00635CBC) },
	{ 141, (char*)(0x006354F8), (char*)(0x00635CBC) },
	{ 142, (char*)(0x006354D0), (char*)(0x00635CBC) },
	{ 143, (char*)(0x006354A8), (char*)(0x00635CBC) },
	{ 144, (char*)(0x00635480), (char*)(0x00635CBC) },
	{ 145, (char*)(0x00635458), (char*)(0x00635CBC) },
	{ 146, (char*)(0x00635430), (char*)(0x00635CBC) },
	{ 147, (char*)(0x00635408), (char*)(0x00635CBC) },
	{ 148, (char*)(0x006353E0), (char*)(0x00635CBC) },
	{ 149, (char*)(0x006353B4), (char*)(0x00635CBC) },
	{ 150, (char*)(0x00635388), (char*)(0x00635CBC) },
	{ 151, (char*)(0x0063535C), (char*)(0x00635CBC) },
	{ 152, (char*)(0x00635330), (char*)(0x00635CBC) },
	{ 153, (char*)(0x00635304), (char*)(0x00635CBC) },
	{ 154, (char*)(0x006352E0), (char*)(0x00635CBC) },
	{ 155, (char*)(0x006352BC), (char*)(0x00635CBC) },
	{ 156, (char*)(0x00635298), (char*)(0x00635CBC) },
	{ 157, (char*)(0x00635274), (char*)(0x00635CBC) },
	{ 158, (char*)(0x00635254), (char*)(0x00635CBC) },
	{ 159, (char*)(0x00635230), (char*)(0x00635220) },
	{ 160, (char*)(0x006351FC), (char*)(0x00635220) },
	{ 161, (char*)(0x006351D8), (char*)(0x00635220) },
	{ 162, (char*)(0x006351B4), (char*)(0x00635220) },
	{ 163, (char*)(0x00635190), (char*)(0x00635220) },
	{ 164, (char*)(0x0063516C), (char*)(0x00635220) },
	{ 165, (char*)(0x00635148), (char*)(0x00635220) },
	{ 166, (char*)(0x00635124), (char*)(0x00635220) },
	{ 167, (char*)(0x006350F8), (char*)(0x00635220) },
	{ 168, (char*)(0x006350CC), (char*)(0x00635220) },
	{ 169, (char*)(0x006350AC), (char*)(0x00635220) },
	{ 170, (char*)(0x0063508C), (char*)(0x00635220) },
	{ 171, (char*)(0x0063506C), (char*)(0x00635220) },
	{ 172, (char*)(0x0063504C), (char*)(0x00635220) },
	{ 173, (char*)(0x0063502C), (char*)(0x00635220) },
	{ 174, (char*)(0x00635004), (char*)(0x00635220) },
	{ 175, (char*)(0x00634FDC), (char*)(0x00635220) },
	{ 176, (char*)(0x00634FB4), (char*)(0x00635220) },
	{ 177, (char*)(0x00634F8C), (char*)(0x00635220) },
	{ 178, (char*)(0x00634F68), (char*)(0x00635220) },
	{ 179, (char*)(0x00634F44), (char*)(0x00635220) },
	{ 180, (char*)(0x00634F20), (char*)(0x00635220) },
	{ 181, (char*)(0x00634EF4), (char*)(0x00635220) },
	{ 182, (char*)(0x00634EC8), (char*)(0x00635220) },
	{ 183, (char*)(0x00634E9C), (char*)(0x00635220) },
	{ 184, (char*)(0x00634E78), (char*)(0x00635220) },
	{ 185, (char*)(0x00634E54), (char*)(0x00635220) },
	{ 186, (char*)(0x00634E30), (char*)(0x00635220) },
	{ 187, (char*)(0x00634E08), (char*)(0x00635220) },
	{ 188, (char*)(0x00634DE0), (char*)(0x00635220) },
	{ 189, (char*)(0x00634DB8), (char*)(0x00635220) },
	{ 190, (char*)(0x00634D90), (char*)(0x00635220) },
	{ 191, (char*)(0x00634D68), (char*)(0x00635220) },
	{ 192, (char*)(0x00634D40), (char*)(0x00635220) },
	{ 193, (char*)(0x00634D14), (char*)(0x00635220) },
	{ 194, (char*)(0x00634CE8), (char*)(0x00635220) },
	{ 195, (char*)(0x00634CBC), (char*)(0x00635220) },
	{ 196, (char*)(0x00634C98), (char*)(0x00635220) },
	{ 197, (char*)(0x00634C74), (char*)(0x00635220) },
	{ 198, (char*)(0x00634C54), (char*)(0x00635220) },
	{ 199, (char*)(0x00634C30), (char*)(0x00634C18) },
	{ 200, (char*)(0x00634BF4), (char*)(0x00634C18) },
	{ 201, (char*)(0x00634BD0), (char*)(0x00634C18) },
	{ 202, (char*)(0x00634BAC), (char*)(0x00634C18) },
	{ 203, (char*)(0x00634B88), (char*)(0x00634C18) },
	{ 204, (char*)(0x00634B64), (char*)(0x00634C18) },
	{ 205, (char*)(0x00634B40), (char*)(0x00634C18) },
	{ 206, (char*)(0x00634B14), (char*)(0x00634C18) },
	{ 207, (char*)(0x00634AE8), (char*)(0x00634C18) },
	{ 208, (char*)(0x00634AC8), (char*)(0x00634C18) },
	{ 209, (char*)(0x00634AA8), (char*)(0x00634C18) },
	{ 210, (char*)(0x00634A88), (char*)(0x00634C18) },
	{ 211, (char*)(0x00634A68), (char*)(0x00634C18) },
	{ 212, (char*)(0x00634A40), (char*)(0x00634C18) },
	{ 213, (char*)(0x00634A18), (char*)(0x00634C18) },
	{ 214, (char*)(0x006349F0), (char*)(0x00634C18) },
	{ 215, (char*)(0x006349C8), (char*)(0x00634C18) },
	{ 216, (char*)(0x006349A4), (char*)(0x00634C18) },
	{ 217, (char*)(0x00634980), (char*)(0x00634C18) },
	{ 218, (char*)(0x00634954), (char*)(0x00634C18) },
	{ 219, (char*)(0x00634928), (char*)(0x00634C18) },
	{ 220, (char*)(0x00634904), (char*)(0x00634C18) },
	{ 221, (char*)(0x006348E0), (char*)(0x00634C18) },
	{ 222, (char*)(0x006348B8), (char*)(0x00634C18) },
	{ 223, (char*)(0x00634890), (char*)(0x00634C18) },
	{ 224, (char*)(0x00634868), (char*)(0x00634C18) },
	{ 225, (char*)(0x00634840), (char*)(0x00634C18) },
	{ 226, (char*)(0x00634814), (char*)(0x00634C18) },
	{ 227, (char*)(0x006347E8), (char*)(0x00634C18) },
	{ 228, (char*)(0x006347C4), (char*)(0x00634C18) },
	{ 229, (char*)(0x006347A0), (char*)(0x00634C18) },
	{ 230, (char*)(0x00634C30), (char*)(0x00634788) },
	{ 231, (char*)(0x00634BF4), (char*)(0x00634788) },
	{ 232, (char*)(0x00634BD0), (char*)(0x00634788) },
	{ 233, (char*)(0x00634BAC), (char*)(0x00634788) },
	{ 234, (char*)(0x00634B88), (char*)(0x00634788) },
	{ 235, (char*)(0x00634B64), (char*)(0x00634788) },
	{ 236, (char*)(0x00634B40), (char*)(0x00634788) },
	{ 237, (char*)(0x00634B14), (char*)(0x00634788) },
	{ 238, (char*)(0x00634AE8), (char*)(0x00634788) },
	{ 239, (char*)(0x00634AC8), (char*)(0x00634788) },
	{ 240, (char*)(0x00634AA8), (char*)(0x00634788) },
	{ 241, (char*)(0x00634A88), (char*)(0x00634788) },
	{ 242, (char*)(0x00634A68), (char*)(0x00634788) },
	{ 243, (char*)(0x00634A40), (char*)(0x00634788) },
	{ 244, (char*)(0x00634A18), (char*)(0x00634788) },
	{ 245, (char*)(0x006349F0), (char*)(0x00634788) },
	{ 246, (char*)(0x006349C8), (char*)(0x00634788) },
	{ 247, (char*)(0x006349A4), (char*)(0x00634788) },
	{ 248, (char*)(0x00634980), (char*)(0x00634788) },
	{ 249, (char*)(0x00634954), (char*)(0x00634788) },
	{ 250, (char*)(0x00634928), (char*)(0x00634788) },
	{ 251, (char*)(0x00634904), (char*)(0x00634788) },
	{ 252, (char*)(0x006348E0), (char*)(0x00634788) },
	{ 253, (char*)(0x006348B8), (char*)(0x00634788) },
	{ 254, (char*)(0x00634890), (char*)(0x00634788) },
	{ 255, (char*)(0x00634868), (char*)(0x00634788) },
	{ 256, (char*)(0x00634840), (char*)(0x00634788) },
	{ 257, (char*)(0x00634814), (char*)(0x00634788) },
	{ 258, (char*)(0x006347E8), (char*)(0x00634788) },
	{ 259, (char*)(0x006347C4), (char*)(0x00634788) },
	{ 260, (char*)(0x006347A0), (char*)(0x00634788) },
	{ 261, (char*)(0x00634C30), (char*)(0x0063476C) },
	{ 262, (char*)(0x00634BF4), (char*)(0x0063476C) },
	{ 263, (char*)(0x00634BD0), (char*)(0x0063476C) },
	{ 264, (char*)(0x00634BAC), (char*)(0x0063476C) },
	{ 265, (char*)(0x00634B88), (char*)(0x0063476C) },
	{ 266, (char*)(0x00634B64), (char*)(0x0063476C) },
	{ 267, (char*)(0x00634B40), (char*)(0x0063476C) },
	{ 268, (char*)(0x00634B14), (char*)(0x0063476C) },
	{ 269, (char*)(0x00634AE8), (char*)(0x0063476C) },
	{ 270, (char*)(0x00634AC8), (char*)(0x0063476C) },
	{ 271, (char*)(0x00634AA8), (char*)(0x0063476C) },
	{ 272, (char*)(0x00634A88), (char*)(0x0063476C) },
	{ 273, (char*)(0x00634A68), (char*)(0x0063476C) },
	{ 274, (char*)(0x00634A40), (char*)(0x0063476C) },
	{ 275, (char*)(0x00634A18), (char*)(0x0063476C) },
	{ 276, (char*)(0x006349F0), (char*)(0x0063476C) },
	{ 277, (char*)(0x006349C8), (char*)(0x0063476C) },
	{ 278, (char*)(0x006349A4), (char*)(0x0063476C) },
	{ 279, (char*)(0x00634980), (char*)(0x0063476C) },
	{ 280, (char*)(0x00634954), (char*)(0x0063476C) },
	{ 281, (char*)(0x00634928), (char*)(0x0063476C) },
	{ 282, (char*)(0x00634904), (char*)(0x0063476C) },
	{ 283, (char*)(0x006348E0), (char*)(0x0063476C) },
	{ 284, (char*)(0x006348B8), (char*)(0x0063476C) },
	{ 285, (char*)(0x00634890), (char*)(0x0063476C) },
	{ 286, (char*)(0x00634868), (char*)(0x0063476C) },
	{ 287, (char*)(0x00634840), (char*)(0x0063476C) },
	{ 288, (char*)(0x00634814), (char*)(0x0063476C) },
	{ 289, (char*)(0x006347E8), (char*)(0x0063476C) },
	{ 290, (char*)(0x006347C4), (char*)(0x0063476C) },
	{ 291, (char*)(0x006347A0), (char*)(0x0063476C) },
	{ 292, (char*)(0x00634C30), (char*)(0x00634754) },
	{ 293, (char*)(0x00634BF4), (char*)(0x00634754) },
	{ 294, (char*)(0x00634BD0), (char*)(0x00634754) },
	{ 295, (char*)(0x00634BAC), (char*)(0x00634754) },
	{ 296, (char*)(0x00634B88), (char*)(0x00634754) },
	{ 297, (char*)(0x00634B64), (char*)(0x00634754) },
	{ 298, (char*)(0x00634B40), (char*)(0x00634754) },
	{ 299, (char*)(0x00634B14), (char*)(0x00634754) },
	{ 300, (char*)(0x00634AE8), (char*)(0x00634754) },
	{ 301, (char*)(0x00634AC8), (char*)(0x00634754) },
	{ 302, (char*)(0x00634AA8), (char*)(0x00634754) },
	{ 303, (char*)(0x00634A88), (char*)(0x00634754) },
	{ 304, (char*)(0x00634A68), (char*)(0x00634754) },
	{ 305, (char*)(0x00634A40), (char*)(0x00634754) },
	{ 306, (char*)(0x00634A18), (char*)(0x00634754) },
	{ 307, (char*)(0x006349F0), (char*)(0x00634754) },
	{ 308, (char*)(0x006349C8), (char*)(0x00634754) },
	{ 309, (char*)(0x006349A4), (char*)(0x00634754) },
	{ 310, (char*)(0x00634980), (char*)(0x00634754) },
	{ 311, (char*)(0x00634954), (char*)(0x00634754) },
	{ 312, (char*)(0x00634928), (char*)(0x00634754) },
	{ 313, (char*)(0x00634904), (char*)(0x00634754) },
	{ 314, (char*)(0x006348E0), (char*)(0x00634754) },
	{ 315, (char*)(0x006348B8), (char*)(0x00634754) },
	{ 316, (char*)(0x00634890), (char*)(0x00634754) },
	{ 317, (char*)(0x00634868), (char*)(0x00634754) },
	{ 318, (char*)(0x00634840), (char*)(0x00634754) },
	{ 319, (char*)(0x00634814), (char*)(0x00634754) },
	{ 320, (char*)(0x006347E8), (char*)(0x00634754) },
	{ 321, (char*)(0x006347C4), (char*)(0x00634754) },
	{ 322, (char*)(0x006347A0), (char*)(0x00634754) },
	{ 323, (char*)(0x00634730), (char*)(0x00634720) },
	{ 324, (char*)(0x006346FC), (char*)(0x00634720) },
	{ 325, (char*)(0x006346D8), (char*)(0x00634720) },
	{ 326, (char*)(0x006346B4), (char*)(0x00634720) },
	{ 327, (char*)(0x00634688), (char*)(0x00634720) },
	{ 328, (char*)(0x0063465C), (char*)(0x00634720) },
	{ 329, (char*)(0x0063463C), (char*)(0x00634720) },
	{ 330, (char*)(0x0063461C), (char*)(0x00634720) },
	{ 331, (char*)(0x006345FC), (char*)(0x00634720) },
	{ 332, (char*)(0x006345DC), (char*)(0x00634720) },
	{ 333, (char*)(0x006345B4), (char*)(0x00634720) },
	{ 334, (char*)(0x0063458C), (char*)(0x00634720) },
	{ 335, (char*)(0x00634568), (char*)(0x00634720) },
	{ 336, (char*)(0x00634544), (char*)(0x00634720) },
	{ 337, (char*)(0x00634518), (char*)(0x00634720) },
	{ 338, (char*)(0x006344EC), (char*)(0x00634720) },
	{ 339, (char*)(0x006344C8), (char*)(0x00634720) },
	{ 340, (char*)(0x006344A4), (char*)(0x00634720) },
	{ 341, (char*)(0x00634480), (char*)(0x00634720) },
	{ 342, (char*)(0x00634458), (char*)(0x00634720) },
	{ 343, (char*)(0x00634430), (char*)(0x00634720) },
	{ 344, (char*)(0x00634408), (char*)(0x00634720) },
	{ 345, (char*)(0x006343E0), (char*)(0x00634720) },
	{ 346, (char*)(0x006343B4), (char*)(0x00634720) },
	{ 347, (char*)(0x00634388), (char*)(0x00634720) },
	{ 348, (char*)(0x00634364), (char*)(0x00634720) },
	{ 349, (char*)(0x00634340), (char*)(0x00634720) },
	{ 350, (char*)(0x00634320), (char*)(0x00634720) },
	{ 351, (char*)(0x006342FC), (char*)(0x006342E8) },
	{ 352, (char*)(0x006342C4), (char*)(0x006342E8) },
	{ 353, (char*)(0x006342A0), (char*)(0x006342E8) },
	{ 354, (char*)(0x0063427C), (char*)(0x006342E8) },
	{ 355, (char*)(0x00634258), (char*)(0x006342E8) },
	{ 356, (char*)(0x00634234), (char*)(0x006342E8) },
	{ 357, (char*)(0x00634210), (char*)(0x006342E8) },
	{ 358, (char*)(0x006341EC), (char*)(0x006342E8) },
	{ 359, (char*)(0x006341C8), (char*)(0x006342E8) },
	{ 360, (char*)(0x006341A4), (char*)(0x006342E8) },
	{ 361, (char*)(0x00634180), (char*)(0x006342E8) },
	{ 362, (char*)(0x00634154), (char*)(0x006342E8) },
	{ 363, (char*)(0x00634128), (char*)(0x006342E8) },
	{ 364, (char*)(0x00634108), (char*)(0x006342E8) },
	{ 365, (char*)(0x006340E8), (char*)(0x006342E8) },
	{ 366, (char*)(0x006340C8), (char*)(0x006342E8) },
	{ 367, (char*)(0x006340A8), (char*)(0x006342E8) },
	{ 368, (char*)(0x00634088), (char*)(0x006342E8) },
	{ 369, (char*)(0x00634060), (char*)(0x006342E8) },
	{ 370, (char*)(0x00634038), (char*)(0x006342E8) },
	{ 371, (char*)(0x00634010), (char*)(0x006342E8) },
	{ 372, (char*)(0x00633FE8), (char*)(0x006342E8) },
	{ 373, (char*)(0x00633FC0), (char*)(0x006342E8) },
	{ 374, (char*)(0x00633F98), (char*)(0x006342E8) },
	{ 375, (char*)(0x00633F70), (char*)(0x006342E8) },
	{ 376, (char*)(0x00633F4C), (char*)(0x006342E8) },
	{ 377, (char*)(0x00633F28), (char*)(0x006342E8) },
	{ 378, (char*)(0x00633EFC), (char*)(0x006342E8) },
	{ 379, (char*)(0x00633ED0), (char*)(0x006342E8) },
	{ 380, (char*)(0x00633EA4), (char*)(0x006342E8) },
	{ 381, (char*)(0x00633E80), (char*)(0x006342E8) },
	{ 382, (char*)(0x00633E5C), (char*)(0x006342E8) },
	{ 383, (char*)(0x00633E34), (char*)(0x006342E8) },
	{ 384, (char*)(0x00633E0C), (char*)(0x006342E8) },
	{ 385, (char*)(0x00633FC0), (char*)(0x006342E8) },
	{ 386, (char*)(0x00633DE4), (char*)(0x006342E8) },
	{ 387, (char*)(0x00633DBC), (char*)(0x006342E8) },
	{ 388, (char*)(0x00633F70), (char*)(0x006342E8) },
	{ 389, (char*)(0x00633D90), (char*)(0x006342E8) },
	{ 390, (char*)(0x00633D64), (char*)(0x006342E8) },
	{ 391, (char*)(0x00633D38), (char*)(0x006342E8) },
	{ 392, (char*)(0x00633F4C), (char*)(0x006342E8) },
	{ 393, (char*)(0x00633F28), (char*)(0x006342E8) },
	{ 394, (char*)(0x006342FC), (char*)(0x00633D1C) },
	{ 395, (char*)(0x006342C4), (char*)(0x00633D1C) },
	{ 396, (char*)(0x006342A0), (char*)(0x00633D1C) },
	{ 397, (char*)(0x0063427C), (char*)(0x00633D1C) },
	{ 398, (char*)(0x00634258), (char*)(0x00633D1C) },
	{ 399, (char*)(0x00634234), (char*)(0x00633D1C) },
	{ 400, (char*)(0x00634210), (char*)(0x00633D1C) },
	{ 401, (char*)(0x006341EC), (char*)(0x00633D1C) },
	{ 402, (char*)(0x006341C8), (char*)(0x00633D1C) },
	{ 403, (char*)(0x006341A4), (char*)(0x00633D1C) },
	{ 404, (char*)(0x00634180), (char*)(0x00633D1C) },
	{ 405, (char*)(0x00634154), (char*)(0x00633D1C) },
	{ 406, (char*)(0x00634128), (char*)(0x00633D1C) },
	{ 407, (char*)(0x00634108), (char*)(0x00633D1C) },
	{ 408, (char*)(0x006340E8), (char*)(0x00633D1C) },
	{ 409, (char*)(0x006340C8), (char*)(0x00633D1C) },
	{ 410, (char*)(0x006340A8), (char*)(0x00633D1C) },
	{ 411, (char*)(0x00634088), (char*)(0x00633D1C) },
	{ 412, (char*)(0x00634060), (char*)(0x00633D1C) },
	{ 413, (char*)(0x00634038), (char*)(0x00633D1C) },
	{ 414, (char*)(0x00634010), (char*)(0x00633D1C) },
	{ 415, (char*)(0x00633FE8), (char*)(0x00633D1C) },
	{ 416, (char*)(0x00633CF4), (char*)(0x00633D1C) },
	{ 417, (char*)(0x00633F98), (char*)(0x00633D1C) },
	{ 418, (char*)(0x00633CD0), (char*)(0x00633D1C) },
	{ 419, (char*)(0x00633CAC), (char*)(0x00633D1C) },
	{ 420, (char*)(0x00633C88), (char*)(0x00633D1C) },
	{ 421, (char*)(0x00633EFC), (char*)(0x00633D1C) },
	{ 422, (char*)(0x00633ED0), (char*)(0x00633D1C) },
	{ 423, (char*)(0x00633EA4), (char*)(0x00633D1C) },
	{ 424, (char*)(0x00633E80), (char*)(0x00633D1C) },
	{ 425, (char*)(0x00633E5C), (char*)(0x00633D1C) },
	{ 426, (char*)(0x00633E34), (char*)(0x00633D1C) },
	{ 427, (char*)(0x00633E0C), (char*)(0x00633D1C) },
	{ 428, (char*)(0x00633FC0), (char*)(0x00633D1C) },
	{ 429, (char*)(0x00633DE4), (char*)(0x00633D1C) },
	{ 430, (char*)(0x00633DBC), (char*)(0x00633D1C) },
	{ 431, (char*)(0x00633F70), (char*)(0x00633D1C) },
	{ 432, (char*)(0x00633D90), (char*)(0x00633D1C) },
	{ 433, (char*)(0x00633D64), (char*)(0x00633D1C) },
	{ 434, (char*)(0x00633D38), (char*)(0x00633D1C) },
	{ 435, (char*)(0x00633F4C), (char*)(0x00633D1C) },
	{ 436, (char*)(0x00633F28), (char*)(0x00633D1C) },
	{ 437, (char*)(0x006342FC), (char*)(0x00633C6C) },
	{ 438, (char*)(0x006342C4), (char*)(0x00633C6C) },
	{ 439, (char*)(0x006342A0), (char*)(0x00633C6C) },
	{ 440, (char*)(0x0063427C), (char*)(0x00633C6C) },
	{ 441, (char*)(0x00634258), (char*)(0x00633C6C) },
	{ 442, (char*)(0x00634234), (char*)(0x00633C6C) },
	{ 443, (char*)(0x00634210), (char*)(0x00633C6C) },
	{ 444, (char*)(0x006341EC), (char*)(0x00633C6C) },
	{ 445, (char*)(0x006341C8), (char*)(0x00633C6C) },
	{ 446, (char*)(0x006341A4), (char*)(0x00633C6C) },
	{ 447, (char*)(0x00634180), (char*)(0x00633C6C) },
	{ 448, (char*)(0x00634154), (char*)(0x00633C6C) },
	{ 449, (char*)(0x00634128), (char*)(0x00633C6C) },
	{ 450, (char*)(0x00634108), (char*)(0x00633C6C) },
	{ 451, (char*)(0x006340E8), (char*)(0x00633C6C) },
	{ 452, (char*)(0x006340C8), (char*)(0x00633C6C) },
	{ 453, (char*)(0x006340A8), (char*)(0x00633C6C) },
	{ 454, (char*)(0x00634088), (char*)(0x00633C6C) },
	{ 455, (char*)(0x00634060), (char*)(0x00633C6C) },
	{ 456, (char*)(0x00634038), (char*)(0x00633C6C) },
	{ 457, (char*)(0x00634010), (char*)(0x00633C6C) },
	{ 458, (char*)(0x00633FE8), (char*)(0x00633C6C) },
	{ 459, (char*)(0x00633CF4), (char*)(0x00633C6C) },
	{ 460, (char*)(0x00633F98), (char*)(0x00633C6C) },
	{ 461, (char*)(0x00633CD0), (char*)(0x00633C6C) },
	{ 462, (char*)(0x00633CAC), (char*)(0x00633C6C) },
	{ 463, (char*)(0x00633C88), (char*)(0x00633C6C) },
	{ 464, (char*)(0x00633EFC), (char*)(0x00633C6C) },
	{ 465, (char*)(0x00633ED0), (char*)(0x00633C6C) },
	{ 466, (char*)(0x00633EA4), (char*)(0x00633C6C) },
	{ 467, (char*)(0x00633E80), (char*)(0x00633C6C) },
	{ 468, (char*)(0x00633E5C), (char*)(0x00633C6C) },
	{ 469, (char*)(0x00633E34), (char*)(0x00633C6C) },
	{ 470, (char*)(0x00633E0C), (char*)(0x00633C6C) },
	{ 471, (char*)(0x00633FC0), (char*)(0x00633C6C) },
	{ 472, (char*)(0x00633DE4), (char*)(0x00633C6C) },
	{ 473, (char*)(0x00633DBC), (char*)(0x00633C6C) },
	{ 474, (char*)(0x00633F70), (char*)(0x00633C6C) },
	{ 475, (char*)(0x00633D90), (char*)(0x00633C6C) },
	{ 476, (char*)(0x00633D64), (char*)(0x00633C6C) },
	{ 477, (char*)(0x00633D38), (char*)(0x00633C6C) },
	{ 478, (char*)(0x00633F4C), (char*)(0x00633C6C) },
	{ 479, (char*)(0x00633F28), (char*)(0x00633C6C) },
	{ 480, (char*)(0x006342FC), (char*)(0x00633C48) },
	{ 481, (char*)(0x006342C4), (char*)(0x00633C48) },
	{ 482, (char*)(0x006342A0), (char*)(0x00633C48) },
	{ 483, (char*)(0x0063427C), (char*)(0x00633C48) },
	{ 484, (char*)(0x00634258), (char*)(0x00633C48) },
	{ 485, (char*)(0x00634234), (char*)(0x00633C48) },
	{ 486, (char*)(0x00634210), (char*)(0x00633C48) },
	{ 487, (char*)(0x006341EC), (char*)(0x00633C48) },
	{ 488, (char*)(0x006341C8), (char*)(0x00633C48) },
	{ 489, (char*)(0x006341A4), (char*)(0x00633C48) },
	{ 490, (char*)(0x00634180), (char*)(0x00633C48) },
	{ 491, (char*)(0x00634154), (char*)(0x00633C48) },
	{ 492, (char*)(0x00634128), (char*)(0x00633C48) },
	{ 493, (char*)(0x00634108), (char*)(0x00633C48) },
	{ 494, (char*)(0x006340E8), (char*)(0x00633C48) },
	{ 495, (char*)(0x006340C8), (char*)(0x00633C48) },
	{ 496, (char*)(0x006340A8), (char*)(0x00633C48) },
	{ 497, (char*)(0x00634088), (char*)(0x00633C48) },
	{ 498, (char*)(0x00634060), (char*)(0x00633C48) },
	{ 499, (char*)(0x00634038), (char*)(0x00633C48) },
	{ 500, (char*)(0x00634010), (char*)(0x00633C48) },
	{ 501, (char*)(0x00633FE8), (char*)(0x00633C48) },
	{ 502, (char*)(0x00633CF4), (char*)(0x00633C48) },
	{ 503, (char*)(0x00633F98), (char*)(0x00633C48) },
	{ 504, (char*)(0x00633CD0), (char*)(0x00633C48) },
	{ 505, (char*)(0x00633CAC), (char*)(0x00633C48) },
	{ 506, (char*)(0x00633C88), (char*)(0x00633C48) },
	{ 507, (char*)(0x00633EFC), (char*)(0x00633C48) },
	{ 508, (char*)(0x00633ED0), (char*)(0x00633C48) },
	{ 509, (char*)(0x00633EA4), (char*)(0x00633C48) },
	{ 510, (char*)(0x00633E80), (char*)(0x00633C48) },
	{ 511, (char*)(0x00633E5C), (char*)(0x00633C48) },
	{ 512, (char*)(0x00633E34), (char*)(0x00633C48) },
	{ 513, (char*)(0x00633E0C), (char*)(0x00633C48) },
	{ 514, (char*)(0x00633FC0), (char*)(0x00633C48) },
	{ 515, (char*)(0x00633DE4), (char*)(0x00633C48) },
	{ 516, (char*)(0x00633DBC), (char*)(0x00633C48) },
	{ 517, (char*)(0x00633F70), (char*)(0x00633C48) },
	{ 518, (char*)(0x00633D90), (char*)(0x00633C48) },
	{ 519, (char*)(0x00633D64), (char*)(0x00633C48) },
	{ 520, (char*)(0x00633D38), (char*)(0x00633C48) },
	{ 521, (char*)(0x00633F4C), (char*)(0x00633C48) },
	{ 522, (char*)(0x00633F28), (char*)(0x00633C48) },
	{ 523, (char*)(0x006342FC), (char*)(0x00633C34) },
	{ 524, (char*)(0x006342C4), (char*)(0x00633C34) },
	{ 525, (char*)(0x006342A0), (char*)(0x00633C34) },
	{ 526, (char*)(0x0063427C), (char*)(0x00633C34) },
	{ 527, (char*)(0x00634258), (char*)(0x00633C34) },
	{ 528, (char*)(0x00634234), (char*)(0x00633C34) },
	{ 529, (char*)(0x00634210), (char*)(0x00633C34) },
	{ 530, (char*)(0x006341EC), (char*)(0x00633C34) },
	{ 531, (char*)(0x006341C8), (char*)(0x00633C34) },
	{ 532, (char*)(0x006341A4), (char*)(0x00633C34) },
	{ 533, (char*)(0x00634180), (char*)(0x00633C34) },
	{ 534, (char*)(0x00634154), (char*)(0x00633C34) },
	{ 535, (char*)(0x00634128), (char*)(0x00633C34) },
	{ 536, (char*)(0x00634108), (char*)(0x00633C34) },
	{ 537, (char*)(0x006340E8), (char*)(0x00633C34) },
	{ 538, (char*)(0x006340C8), (char*)(0x00633C34) },
	{ 539, (char*)(0x006340A8), (char*)(0x00633C34) },
	{ 540, (char*)(0x00634088), (char*)(0x00633C34) },
	{ 541, (char*)(0x00634060), (char*)(0x00633C34) },
	{ 542, (char*)(0x00634038), (char*)(0x00633C34) },
	{ 543, (char*)(0x00634010), (char*)(0x00633C34) },
	{ 544, (char*)(0x00633FE8), (char*)(0x00633C34) },
	{ 545, (char*)(0x00633CF4), (char*)(0x00633C34) },
	{ 546, (char*)(0x00633F98), (char*)(0x00633C34) },
	{ 547, (char*)(0x00633CD0), (char*)(0x00633C34) },
	{ 548, (char*)(0x00633CAC), (char*)(0x00633C34) },
	{ 549, (char*)(0x00633C88), (char*)(0x00633C34) },
	{ 550, (char*)(0x00633EFC), (char*)(0x00633C34) },
	{ 551, (char*)(0x00633ED0), (char*)(0x00633C34) },
	{ 552, (char*)(0x00633EA4), (char*)(0x00633C34) },
	{ 553, (char*)(0x00633E80), (char*)(0x00633C34) },
	{ 554, (char*)(0x00633E5C), (char*)(0x00633C34) },
	{ 555, (char*)(0x00633E34), (char*)(0x00633C34) },
	{ 556, (char*)(0x00633E0C), (char*)(0x00633C34) },
	{ 557, (char*)(0x00633FC0), (char*)(0x00633C34) },
	{ 558, (char*)(0x00633DE4), (char*)(0x00633C34) },
	{ 559, (char*)(0x00633DBC), (char*)(0x00633C34) },
	{ 560, (char*)(0x00633F70), (char*)(0x00633C34) },
	{ 561, (char*)(0x00633D90), (char*)(0x00633C34) },
	{ 562, (char*)(0x00633D64), (char*)(0x00633C34) },
	{ 563, (char*)(0x00633D38), (char*)(0x00633C34) },
	{ 564, (char*)(0x00633F4C), (char*)(0x00633C34) },
	{ 565, (char*)(0x00633F28), (char*)(0x00633C34) },
	{ 566, (char*)(0x006342FC), (char*)(0x00633C20) },
	{ 567, (char*)(0x006342C4), (char*)(0x00633C20) },
	{ 568, (char*)(0x006342A0), (char*)(0x00633C20) },
	{ 569, (char*)(0x0063427C), (char*)(0x00633C20) },
	{ 570, (char*)(0x00634258), (char*)(0x00633C20) },
	{ 571, (char*)(0x00634234), (char*)(0x00633C20) },
	{ 572, (char*)(0x00634210), (char*)(0x00633C20) },
	{ 573, (char*)(0x006341EC), (char*)(0x00633C20) },
	{ 574, (char*)(0x006341C8), (char*)(0x00633C20) },
	{ 575, (char*)(0x006341A4), (char*)(0x00633C20) },
	{ 576, (char*)(0x00634180), (char*)(0x00633C20) },
	{ 577, (char*)(0x00634154), (char*)(0x00633C20) },
	{ 578, (char*)(0x00634128), (char*)(0x00633C20) },
	{ 579, (char*)(0x00634108), (char*)(0x00633C20) },
	{ 580, (char*)(0x006340E8), (char*)(0x00633C20) },
	{ 581, (char*)(0x006340C8), (char*)(0x00633C20) },
	{ 582, (char*)(0x006340A8), (char*)(0x00633C20) },
	{ 583, (char*)(0x00634088), (char*)(0x00633C20) },
	{ 584, (char*)(0x00634060), (char*)(0x00633C20) },
	{ 585, (char*)(0x00634038), (char*)(0x00633C20) },
	{ 586, (char*)(0x00634010), (char*)(0x00633C20) },
	{ 587, (char*)(0x00633FE8), (char*)(0x00633C20) },
	{ 588, (char*)(0x00633CF4), (char*)(0x00633C20) },
	{ 589, (char*)(0x00633F98), (char*)(0x00633C20) },
	{ 590, (char*)(0x00633CD0), (char*)(0x00633C20) },
	{ 591, (char*)(0x00633CAC), (char*)(0x00633C20) },
	{ 592, (char*)(0x00633C88), (char*)(0x00633C20) },
	{ 593, (char*)(0x00633EFC), (char*)(0x00633C20) },
	{ 594, (char*)(0x00633ED0), (char*)(0x00633C20) },
	{ 595, (char*)(0x00633EA4), (char*)(0x00633C20) },
	{ 596, (char*)(0x00633E80), (char*)(0x00633C20) },
	{ 597, (char*)(0x00633E5C), (char*)(0x00633C20) },
	{ 598, (char*)(0x00633E34), (char*)(0x00633C20) },
	{ 599, (char*)(0x00633E0C), (char*)(0x00633C20) },
	{ 600, (char*)(0x00633FC0), (char*)(0x00633C20) },
	{ 601, (char*)(0x00633DE4), (char*)(0x00633C20) },
	{ 602, (char*)(0x00633DBC), (char*)(0x00633C20) },
	{ 603, (char*)(0x00633F70), (char*)(0x00633C20) },
	{ 604, (char*)(0x00633D90), (char*)(0x00633C20) },
	{ 605, (char*)(0x00633D64), (char*)(0x00633C20) },
	{ 606, (char*)(0x00633D38), (char*)(0x00633C20) },
	{ 607, (char*)(0x00633F4C), (char*)(0x00633C20) },
	{ 608, (char*)(0x00633F28), (char*)(0x00633C20) },
	{ 609, (char*)(0x006342FC), (char*)(0x00633C04) },
	{ 610, (char*)(0x006342C4), (char*)(0x00633C04) },
	{ 611, (char*)(0x006342A0), (char*)(0x00633C04) },
	{ 612, (char*)(0x0063427C), (char*)(0x00633C04) },
	{ 613, (char*)(0x00634258), (char*)(0x00633C04) },
	{ 614, (char*)(0x00634234), (char*)(0x00633C04) },
	{ 615, (char*)(0x00634210), (char*)(0x00633C04) },
	{ 616, (char*)(0x006341EC), (char*)(0x00633C04) },
	{ 617, (char*)(0x006341C8), (char*)(0x00633C04) },
	{ 618, (char*)(0x006341A4), (char*)(0x00633C04) },
	{ 619, (char*)(0x00634180), (char*)(0x00633C04) },
	{ 620, (char*)(0x00634154), (char*)(0x00633C04) },
	{ 621, (char*)(0x00634128), (char*)(0x00633C04) },
	{ 622, (char*)(0x00634108), (char*)(0x00633C04) },
	{ 623, (char*)(0x006340E8), (char*)(0x00633C04) },
	{ 624, (char*)(0x006340C8), (char*)(0x00633C04) },
	{ 625, (char*)(0x006340A8), (char*)(0x00633C04) },
	{ 626, (char*)(0x00634088), (char*)(0x00633C04) },
	{ 627, (char*)(0x00634060), (char*)(0x00633C04) },
	{ 628, (char*)(0x00634038), (char*)(0x00633C04) },
	{ 629, (char*)(0x00634010), (char*)(0x00633C04) },
	{ 630, (char*)(0x00633FE8), (char*)(0x00633C04) },
	{ 631, (char*)(0x00633CF4), (char*)(0x00633C04) },
	{ 632, (char*)(0x00633F98), (char*)(0x00633C04) },
	{ 633, (char*)(0x00633CD0), (char*)(0x00633C04) },
	{ 634, (char*)(0x00633CAC), (char*)(0x00633C04) },
	{ 635, (char*)(0x00633C88), (char*)(0x00633C04) },
	{ 636, (char*)(0x00633EFC), (char*)(0x00633C04) },
	{ 637, (char*)(0x00633ED0), (char*)(0x00633C04) },
	{ 638, (char*)(0x00633EA4), (char*)(0x00633C04) },
	{ 639, (char*)(0x00633E80), (char*)(0x00633C04) },
	{ 640, (char*)(0x00633E5C), (char*)(0x00633C04) },
	{ 641, (char*)(0x00633E34), (char*)(0x00633C04) },
	{ 642, (char*)(0x00633E0C), (char*)(0x00633C04) },
	{ 643, (char*)(0x00633FC0), (char*)(0x00633C04) },
	{ 644, (char*)(0x00633DE4), (char*)(0x00633C04) },
	{ 645, (char*)(0x00633DBC), (char*)(0x00633C04) },
	{ 646, (char*)(0x00633F70), (char*)(0x00633C04) },
	{ 647, (char*)(0x00633D90), (char*)(0x00633C04) },
	{ 648, (char*)(0x00633D64), (char*)(0x00633C04) },
	{ 649, (char*)(0x00633D38), (char*)(0x00633C04) },
	{ 650, (char*)(0x00633F4C), (char*)(0x00633C04) },
	{ 651, (char*)(0x00633F28), (char*)(0x00633C04) },
	{ 652, (char*)(0x006342FC), (char*)(0x00633BE8) },
	{ 653, (char*)(0x006342C4), (char*)(0x00633BE8) },
	{ 654, (char*)(0x006342A0), (char*)(0x00633BE8) },
	{ 655, (char*)(0x0063427C), (char*)(0x00633BE8) },
	{ 656, (char*)(0x00634258), (char*)(0x00633BE8) },
	{ 657, (char*)(0x00634234), (char*)(0x00633BE8) },
	{ 658, (char*)(0x00634210), (char*)(0x00633BE8) },
	{ 659, (char*)(0x006341EC), (char*)(0x00633BE8) },
	{ 660, (char*)(0x006341C8), (char*)(0x00633BE8) },
	{ 661, (char*)(0x006341A4), (char*)(0x00633BE8) },
	{ 662, (char*)(0x00634180), (char*)(0x00633BE8) },
	{ 663, (char*)(0x00634154), (char*)(0x00633BE8) },
	{ 664, (char*)(0x00634128), (char*)(0x00633BE8) },
	{ 665, (char*)(0x00634108), (char*)(0x00633BE8) },
	{ 666, (char*)(0x006340E8), (char*)(0x00633BE8) },
	{ 667, (char*)(0x006340C8), (char*)(0x00633BE8) },
	{ 668, (char*)(0x006340A8), (char*)(0x00633BE8) },
	{ 669, (char*)(0x00634088), (char*)(0x00633BE8) },
	{ 670, (char*)(0x00634060), (char*)(0x00633BE8) },
	{ 671, (char*)(0x00634038), (char*)(0x00633BE8) },
	{ 672, (char*)(0x00634010), (char*)(0x00633BE8) },
	{ 673, (char*)(0x00633FE8), (char*)(0x00633BE8) },
	{ 674, (char*)(0x00633CF4), (char*)(0x00633BE8) },
	{ 675, (char*)(0x00633F98), (char*)(0x00633BE8) },
	{ 676, (char*)(0x00633CD0), (char*)(0x00633BE8) },
	{ 677, (char*)(0x00633CAC), (char*)(0x00633BE8) },
	{ 678, (char*)(0x00633C88), (char*)(0x00633BE8) },
	{ 679, (char*)(0x00633EFC), (char*)(0x00633BE8) },
	{ 680, (char*)(0x00633ED0), (char*)(0x00633BE8) },
	{ 681, (char*)(0x00633EA4), (char*)(0x00633BE8) },
	{ 682, (char*)(0x00633E80), (char*)(0x00633BE8) },
	{ 683, (char*)(0x00633E5C), (char*)(0x00633BE8) },
	{ 684, (char*)(0x00633E34), (char*)(0x00633BE8) },
	{ 685, (char*)(0x00633E0C), (char*)(0x00633BE8) },
	{ 686, (char*)(0x00633FC0), (char*)(0x00633BE8) },
	{ 687, (char*)(0x00633DE4), (char*)(0x00633BE8) },
	{ 688, (char*)(0x00633DBC), (char*)(0x00633BE8) },
	{ 689, (char*)(0x00633F70), (char*)(0x00633BE8) },
	{ 690, (char*)(0x00633D90), (char*)(0x00633BE8) },
	{ 691, (char*)(0x00633D64), (char*)(0x00633BE8) },
	{ 692, (char*)(0x00633D38), (char*)(0x00633BE8) },
	{ 693, (char*)(0x00633F4C), (char*)(0x00633BE8) },
	{ 694, (char*)(0x00633F28), (char*)(0x00633BE8) },
	{ 695, (char*)(0x006342FC), (char*)(0x00633BCC) },
	{ 696, (char*)(0x006342C4), (char*)(0x00633BCC) },
	{ 697, (char*)(0x006342A0), (char*)(0x00633BCC) },
	{ 698, (char*)(0x0063427C), (char*)(0x00633BCC) },
	{ 699, (char*)(0x00634258), (char*)(0x00633BCC) },
	{ 700, (char*)(0x00634234), (char*)(0x00633BCC) },
	{ 701, (char*)(0x00634210), (char*)(0x00633BCC) },
	{ 702, (char*)(0x006341EC), (char*)(0x00633BCC) },
	{ 703, (char*)(0x006341C8), (char*)(0x00633BCC) },
	{ 704, (char*)(0x006341A4), (char*)(0x00633BCC) },
	{ 705, (char*)(0x00634180), (char*)(0x00633BCC) },
	{ 706, (char*)(0x00634154), (char*)(0x00633BCC) },
	{ 707, (char*)(0x00634128), (char*)(0x00633BCC) },
	{ 708, (char*)(0x00634108), (char*)(0x00633BCC) },
	{ 709, (char*)(0x006340E8), (char*)(0x00633BCC) },
	{ 710, (char*)(0x006340C8), (char*)(0x00633BCC) },
	{ 711, (char*)(0x006340A8), (char*)(0x00633BCC) },
	{ 712, (char*)(0x00634088), (char*)(0x00633BCC) },
	{ 713, (char*)(0x00634060), (char*)(0x00633BCC) },
	{ 714, (char*)(0x00634038), (char*)(0x00633BCC) },
	{ 715, (char*)(0x00634010), (char*)(0x00633BCC) },
	{ 716, (char*)(0x00633FE8), (char*)(0x00633BCC) },
	{ 717, (char*)(0x00633CF4), (char*)(0x00633BCC) },
	{ 718, (char*)(0x00633F98), (char*)(0x00633BCC) },
	{ 719, (char*)(0x00633CD0), (char*)(0x00633BCC) },
	{ 720, (char*)(0x00633CAC), (char*)(0x00633BCC) },
	{ 721, (char*)(0x00633C88), (char*)(0x00633BCC) },
	{ 722, (char*)(0x00633EFC), (char*)(0x00633BCC) },
	{ 723, (char*)(0x00633ED0), (char*)(0x00633BCC) },
	{ 724, (char*)(0x00633EA4), (char*)(0x00633BCC) },
	{ 725, (char*)(0x00633E80), (char*)(0x00633BCC) },
	{ 726, (char*)(0x00633E5C), (char*)(0x00633BCC) },
	{ 727, (char*)(0x00633E34), (char*)(0x00633BCC) },
	{ 728, (char*)(0x00633E0C), (char*)(0x00633BCC) },
	{ 729, (char*)(0x00633FC0), (char*)(0x00633BCC) },
	{ 730, (char*)(0x00633DE4), (char*)(0x00633BCC) },
	{ 731, (char*)(0x00633DBC), (char*)(0x00633BCC) },
	{ 732, (char*)(0x00633F70), (char*)(0x00633BCC) },
	{ 733, (char*)(0x00633D90), (char*)(0x00633BCC) },
	{ 734, (char*)(0x00633D64), (char*)(0x00633BCC) },
	{ 735, (char*)(0x00633D38), (char*)(0x00633BCC) },
	{ 736, (char*)(0x00633F4C), (char*)(0x00633BCC) },
	{ 737, (char*)(0x00633F28), (char*)(0x00633BCC) },
	{ 738, (char*)(0x006342FC), (char*)(0x00633BB4) },
	{ 739, (char*)(0x006342C4), (char*)(0x00633BB4) },
	{ 740, (char*)(0x006342A0), (char*)(0x00633BB4) },
	{ 741, (char*)(0x0063427C), (char*)(0x00633BB4) },
	{ 742, (char*)(0x00634258), (char*)(0x00633BB4) },
	{ 743, (char*)(0x00634234), (char*)(0x00633BB4) },
	{ 744, (char*)(0x00634210), (char*)(0x00633BB4) },
	{ 745, (char*)(0x006341EC), (char*)(0x00633BB4) },
	{ 746, (char*)(0x006341C8), (char*)(0x00633BB4) },
	{ 747, (char*)(0x006341A4), (char*)(0x00633BB4) },
	{ 748, (char*)(0x00634180), (char*)(0x00633BB4) },
	{ 749, (char*)(0x00634154), (char*)(0x00633BB4) },
	{ 750, (char*)(0x00634128), (char*)(0x00633BB4) },
	{ 751, (char*)(0x00634108), (char*)(0x00633BB4) },
	{ 752, (char*)(0x006340E8), (char*)(0x00633BB4) },
	{ 753, (char*)(0x006340C8), (char*)(0x00633BB4) },
	{ 754, (char*)(0x006340A8), (char*)(0x00633BB4) },
	{ 755, (char*)(0x00634088), (char*)(0x00633BB4) },
	{ 756, (char*)(0x00634060), (char*)(0x00633BB4) },
	{ 757, (char*)(0x00634038), (char*)(0x00633BB4) },
	{ 758, (char*)(0x00634010), (char*)(0x00633BB4) },
	{ 759, (char*)(0x00633FE8), (char*)(0x00633BB4) },
	{ 760, (char*)(0x00633CF4), (char*)(0x00633BB4) },
	{ 761, (char*)(0x00633F98), (char*)(0x00633BB4) },
	{ 762, (char*)(0x00633CD0), (char*)(0x00633BB4) },
	{ 763, (char*)(0x00633CAC), (char*)(0x00633BB4) },
	{ 764, (char*)(0x00633C88), (char*)(0x00633BB4) },
	{ 765, (char*)(0x00633EFC), (char*)(0x00633BB4) },
	{ 766, (char*)(0x00633ED0), (char*)(0x00633BB4) },
	{ 767, (char*)(0x00633EA4), (char*)(0x00633BB4) },
	{ 768, (char*)(0x00633E80), (char*)(0x00633BB4) },
	{ 769, (char*)(0x00633E5C), (char*)(0x00633BB4) },
	{ 770, (char*)(0x00633E34), (char*)(0x00633BB4) },
	{ 771, (char*)(0x00633E0C), (char*)(0x00633BB4) },
	{ 772, (char*)(0x00633FC0), (char*)(0x00633BB4) },
	{ 773, (char*)(0x00633DE4), (char*)(0x00633BB4) },
	{ 774, (char*)(0x00633DBC), (char*)(0x00633BB4) },
	{ 775, (char*)(0x00633F70), (char*)(0x00633BB4) },
	{ 776, (char*)(0x00633D90), (char*)(0x00633BB4) },
	{ 777, (char*)(0x00633D64), (char*)(0x00633BB4) },
	{ 778, (char*)(0x00633D38), (char*)(0x00633BB4) },
	{ 779, (char*)(0x00633F4C), (char*)(0x00633BB4) },
	{ 780, (char*)(0x00633F28), (char*)(0x00633BB4) },
	{ 781, (char*)(0x006342FC), (char*)(0x00633B94) },
	{ 782, (char*)(0x006342C4), (char*)(0x00633B94) },
	{ 783, (char*)(0x006342A0), (char*)(0x00633B94) },
	{ 784, (char*)(0x0063427C), (char*)(0x00633B94) },
	{ 785, (char*)(0x00634258), (char*)(0x00633B94) },
	{ 786, (char*)(0x00634234), (char*)(0x00633B94) },
	{ 787, (char*)(0x00634210), (char*)(0x00633B94) },
	{ 788, (char*)(0x006341EC), (char*)(0x00633B94) },
	{ 789, (char*)(0x006341C8), (char*)(0x00633B94) },
	{ 790, (char*)(0x006341A4), (char*)(0x00633B94) },
	{ 791, (char*)(0x00634180), (char*)(0x00633B94) },
	{ 792, (char*)(0x00634154), (char*)(0x00633B94) },
	{ 793, (char*)(0x00634128), (char*)(0x00633B94) },
	{ 794, (char*)(0x00634108), (char*)(0x00633B94) },
	{ 795, (char*)(0x006340E8), (char*)(0x00633B94) },
	{ 796, (char*)(0x006340C8), (char*)(0x00633B94) },
	{ 797, (char*)(0x006340A8), (char*)(0x00633B94) },
	{ 798, (char*)(0x00634088), (char*)(0x00633B94) },
	{ 799, (char*)(0x00634060), (char*)(0x00633B94) },
	{ 800, (char*)(0x00634038), (char*)(0x00633B94) },
	{ 801, (char*)(0x00634010), (char*)(0x00633B94) },
	{ 802, (char*)(0x00633FE8), (char*)(0x00633B94) },
	{ 803, (char*)(0x00633CF4), (char*)(0x00633B94) },
	{ 804, (char*)(0x00633F98), (char*)(0x00633B94) },
	{ 805, (char*)(0x00633CD0), (char*)(0x00633B94) },
	{ 806, (char*)(0x00633CAC), (char*)(0x00633B94) },
	{ 807, (char*)(0x00633C88), (char*)(0x00633B94) },
	{ 808, (char*)(0x00633EFC), (char*)(0x00633B94) },
	{ 809, (char*)(0x00633ED0), (char*)(0x00633B94) },
	{ 810, (char*)(0x00633EA4), (char*)(0x00633B94) },
	{ 811, (char*)(0x00633E80), (char*)(0x00633B94) },
	{ 812, (char*)(0x00633E5C), (char*)(0x00633B94) },
	{ 813, (char*)(0x00633E34), (char*)(0x00633B94) },
	{ 814, (char*)(0x00633E0C), (char*)(0x00633B94) },
	{ 815, (char*)(0x00633FC0), (char*)(0x00633B94) },
	{ 816, (char*)(0x00633DE4), (char*)(0x00633B94) },
	{ 817, (char*)(0x00633DBC), (char*)(0x00633B94) },
	{ 818, (char*)(0x00633F70), (char*)(0x00633B94) },
	{ 819, (char*)(0x00633D90), (char*)(0x00633B94) },
	{ 820, (char*)(0x00633D64), (char*)(0x00633B94) },
	{ 821, (char*)(0x00633D38), (char*)(0x00633B94) },
	{ 822, (char*)(0x00633F4C), (char*)(0x00633B94) },
	{ 823, (char*)(0x00633F28), (char*)(0x00633B94) },
	{ 824, (char*)(0x006342FC), (char*)(0x00633B7C) },
	{ 825, (char*)(0x006342C4), (char*)(0x00633B7C) },
	{ 826, (char*)(0x006342A0), (char*)(0x00633B7C) },
	{ 827, (char*)(0x0063427C), (char*)(0x00633B7C) },
	{ 828, (char*)(0x00634258), (char*)(0x00633B7C) },
	{ 829, (char*)(0x00634234), (char*)(0x00633B7C) },
	{ 830, (char*)(0x00634210), (char*)(0x00633B7C) },
	{ 831, (char*)(0x006341EC), (char*)(0x00633B7C) },
	{ 832, (char*)(0x006341C8), (char*)(0x00633B7C) },
	{ 833, (char*)(0x006341A4), (char*)(0x00633B7C) },
	{ 834, (char*)(0x00634180), (char*)(0x00633B7C) },
	{ 835, (char*)(0x00634154), (char*)(0x00633B7C) },
	{ 836, (char*)(0x00634128), (char*)(0x00633B7C) },
	{ 837, (char*)(0x00634108), (char*)(0x00633B7C) },
	{ 838, (char*)(0x006340E8), (char*)(0x00633B7C) },
	{ 839, (char*)(0x006340C8), (char*)(0x00633B7C) },
	{ 840, (char*)(0x006340A8), (char*)(0x00633B7C) },
	{ 841, (char*)(0x00634088), (char*)(0x00633B7C) },
	{ 842, (char*)(0x00634060), (char*)(0x00633B7C) },
	{ 843, (char*)(0x00634038), (char*)(0x00633B7C) },
	{ 844, (char*)(0x00634010), (char*)(0x00633B7C) },
	{ 845, (char*)(0x00633FE8), (char*)(0x00633B7C) },
	{ 846, (char*)(0x00633CF4), (char*)(0x00633B7C) },
	{ 847, (char*)(0x00633F98), (char*)(0x00633B7C) },
	{ 848, (char*)(0x00633CD0), (char*)(0x00633B7C) },
	{ 849, (char*)(0x00633CAC), (char*)(0x00633B7C) },
	{ 850, (char*)(0x00633C88), (char*)(0x00633B7C) },
	{ 851, (char*)(0x00633EFC), (char*)(0x00633B7C) },
	{ 852, (char*)(0x00633ED0), (char*)(0x00633B7C) },
	{ 853, (char*)(0x00633EA4), (char*)(0x00633B7C) },
	{ 854, (char*)(0x00633E80), (char*)(0x00633B7C) },
	{ 855, (char*)(0x00633E5C), (char*)(0x00633B7C) },
	{ 856, (char*)(0x00633E34), (char*)(0x00633B7C) },
	{ 857, (char*)(0x00633E0C), (char*)(0x00633B7C) },
	{ 858, (char*)(0x00633FC0), (char*)(0x00633B7C) },
	{ 859, (char*)(0x00633DE4), (char*)(0x00633B7C) },
	{ 860, (char*)(0x00633DBC), (char*)(0x00633B7C) },
	{ 861, (char*)(0x00633F70), (char*)(0x00633B7C) },
	{ 862, (char*)(0x00633D90), (char*)(0x00633B7C) },
	{ 863, (char*)(0x00633D64), (char*)(0x00633B7C) },
	{ 864, (char*)(0x00633D38), (char*)(0x00633B7C) },
	{ 865, (char*)(0x00633F4C), (char*)(0x00633B7C) },
	{ 866, (char*)(0x00633F28), (char*)(0x00633B7C) },
	{ 867, (char*)(0x006342FC), (char*)(0x00633B5C) },
	{ 868, (char*)(0x006342C4), (char*)(0x00633B5C) },
	{ 869, (char*)(0x006342A0), (char*)(0x00633B5C) },
	{ 870, (char*)(0x0063427C), (char*)(0x00633B5C) },
	{ 871, (char*)(0x00634258), (char*)(0x00633B5C) },
	{ 872, (char*)(0x00634234), (char*)(0x00633B5C) },
	{ 873, (char*)(0x00634210), (char*)(0x00633B5C) },
	{ 874, (char*)(0x006341EC), (char*)(0x00633B5C) },
	{ 875, (char*)(0x006341C8), (char*)(0x00633B5C) },
	{ 876, (char*)(0x006341A4), (char*)(0x00633B5C) },
	{ 877, (char*)(0x00634180), (char*)(0x00633B5C) },
	{ 878, (char*)(0x00634154), (char*)(0x00633B5C) },
	{ 879, (char*)(0x00634128), (char*)(0x00633B5C) },
	{ 880, (char*)(0x00634108), (char*)(0x00633B5C) },
	{ 881, (char*)(0x006340E8), (char*)(0x00633B5C) },
	{ 882, (char*)(0x006340C8), (char*)(0x00633B5C) },
	{ 883, (char*)(0x006340A8), (char*)(0x00633B5C) },
	{ 884, (char*)(0x00634088), (char*)(0x00633B5C) },
	{ 885, (char*)(0x00634060), (char*)(0x00633B5C) },
	{ 886, (char*)(0x00634038), (char*)(0x00633B5C) },
	{ 887, (char*)(0x00634010), (char*)(0x00633B5C) },
	{ 888, (char*)(0x00633FE8), (char*)(0x00633B5C) },
	{ 889, (char*)(0x00633CF4), (char*)(0x00633B5C) },
	{ 890, (char*)(0x00633F98), (char*)(0x00633B5C) },
	{ 891, (char*)(0x00633CD0), (char*)(0x00633B5C) },
	{ 892, (char*)(0x00633CAC), (char*)(0x00633B5C) },
	{ 893, (char*)(0x00633C88), (char*)(0x00633B5C) },
	{ 894, (char*)(0x00633EFC), (char*)(0x00633B5C) },
	{ 895, (char*)(0x00633ED0), (char*)(0x00633B5C) },
	{ 896, (char*)(0x00633EA4), (char*)(0x00633B5C) },
	{ 897, (char*)(0x00633E80), (char*)(0x00633B5C) },
	{ 898, (char*)(0x00633E5C), (char*)(0x00633B5C) },
	{ 899, (char*)(0x00633E34), (char*)(0x00633B5C) },
	{ 900, (char*)(0x00633E0C), (char*)(0x00633B5C) },
	{ 901, (char*)(0x00633FC0), (char*)(0x00633B5C) },
	{ 902, (char*)(0x00633DE4), (char*)(0x00633B5C) },
	{ 903, (char*)(0x00633DBC), (char*)(0x00633B5C) },
	{ 904, (char*)(0x00633F70), (char*)(0x00633B5C) },
	{ 905, (char*)(0x00633D90), (char*)(0x00633B5C) },
	{ 906, (char*)(0x00633D64), (char*)(0x00633B5C) },
	{ 907, (char*)(0x00633D38), (char*)(0x00633B5C) },
	{ 908, (char*)(0x00633F4C), (char*)(0x00633B5C) },
	{ 909, (char*)(0x00633F28), (char*)(0x00633B5C) },
	{ 910, (char*)(0x006342FC), (char*)(0x00633B28) },
	{ 911, (char*)(0x006342C4), (char*)(0x00633B28) },
	{ 912, (char*)(0x006342A0), (char*)(0x00633B28) },
	{ 913, (char*)(0x0063427C), (char*)(0x00633B28) },
	{ 914, (char*)(0x00634258), (char*)(0x00633B28) },
	{ 915, (char*)(0x00634234), (char*)(0x00633B28) },
	{ 916, (char*)(0x00634210), (char*)(0x00633B28) },
	{ 917, (char*)(0x006341EC), (char*)(0x00633B28) },
	{ 918, (char*)(0x006341C8), (char*)(0x00633B28) },
	{ 919, (char*)(0x006341A4), (char*)(0x00633B28) },
	{ 920, (char*)(0x00634180), (char*)(0x00633B28) },
	{ 921, (char*)(0x00634154), (char*)(0x00633B28) },
	{ 922, (char*)(0x00634128), (char*)(0x00633B28) },
	{ 923, (char*)(0x00634108), (char*)(0x00633B28) },
	{ 924, (char*)(0x006340E8), (char*)(0x00633B28) },
	{ 925, (char*)(0x006340C8), (char*)(0x00633B28) },
	{ 926, (char*)(0x006340A8), (char*)(0x00633B28) },
	{ 927, (char*)(0x00634088), (char*)(0x00633B28) },
	{ 928, (char*)(0x00634060), (char*)(0x00633B28) },
	{ 929, (char*)(0x00634038), (char*)(0x00633B28) },
	{ 930, (char*)(0x00634010), (char*)(0x00633B28) },
	{ 931, (char*)(0x00633FE8), (char*)(0x00633B28) },
	{ 932, (char*)(0x00633CF4), (char*)(0x00633B28) },
	{ 933, (char*)(0x00633F98), (char*)(0x00633B28) },
	{ 934, (char*)(0x00633CD0), (char*)(0x00633B28) },
	{ 935, (char*)(0x00633CAC), (char*)(0x00633B28) },
	{ 936, (char*)(0x00633C88), (char*)(0x00633B28) },
	{ 937, (char*)(0x00633EFC), (char*)(0x00633B28) },
	{ 938, (char*)(0x00633ED0), (char*)(0x00633B28) },
	{ 939, (char*)(0x00633EA4), (char*)(0x00633B28) },
	{ 940, (char*)(0x00633E80), (char*)(0x00633B28) },
	{ 941, (char*)(0x00633E5C), (char*)(0x00633B28) },
	{ 942, (char*)(0x00633E34), (char*)(0x00633B28) },
	{ 943, (char*)(0x00633E0C), (char*)(0x00633B28) },
	{ 944, (char*)(0x00633FC0), (char*)(0x00633B28) },
	{ 945, (char*)(0x00633DE4), (char*)(0x00633B28) },
	{ 946, (char*)(0x00633DBC), (char*)(0x00633B28) },
	{ 947, (char*)(0x00633F70), (char*)(0x00633B28) },
	{ 948, (char*)(0x00633D90), (char*)(0x00633B28) },
	{ 949, (char*)(0x00633D64), (char*)(0x00633B28) },
	{ 950, (char*)(0x00633D38), (char*)(0x00633B28) },
	{ 951, (char*)(0x00633F4C), (char*)(0x00633B28) },
	{ 952, (char*)(0x00633F28), (char*)(0x00633B28) },
	{ 953, (char*)(0x006342FC), (char*)(0x00633B08) },
	{ 954, (char*)(0x006342C4), (char*)(0x00633B08) },
	{ 955, (char*)(0x006342A0), (char*)(0x00633B08) },
	{ 956, (char*)(0x0063427C), (char*)(0x00633B08) },
	{ 957, (char*)(0x00634258), (char*)(0x00633B08) },
	{ 958, (char*)(0x00634234), (char*)(0x00633B08) },
	{ 959, (char*)(0x00634210), (char*)(0x00633B08) },
	{ 960, (char*)(0x006341EC), (char*)(0x00633B08) },
	{ 961, (char*)(0x006341C8), (char*)(0x00633B08) },
	{ 962, (char*)(0x006341A4), (char*)(0x00633B08) },
	{ 963, (char*)(0x00634180), (char*)(0x00633B08) },
	{ 964, (char*)(0x00634154), (char*)(0x00633B08) },
	{ 965, (char*)(0x00634128), (char*)(0x00633B08) },
	{ 966, (char*)(0x00634108), (char*)(0x00633B08) },
	{ 967, (char*)(0x006340E8), (char*)(0x00633B08) },
	{ 968, (char*)(0x006340C8), (char*)(0x00633B08) },
	{ 969, (char*)(0x006340A8), (char*)(0x00633B08) },
	{ 970, (char*)(0x00634088), (char*)(0x00633B08) },
	{ 971, (char*)(0x00634060), (char*)(0x00633B08) },
	{ 972, (char*)(0x00634038), (char*)(0x00633B08) },
	{ 973, (char*)(0x00634010), (char*)(0x00633B08) },
	{ 974, (char*)(0x00633FE8), (char*)(0x00633B08) },
	{ 975, (char*)(0x00633CF4), (char*)(0x00633B08) },
	{ 976, (char*)(0x00633F98), (char*)(0x00633B08) },
	{ 977, (char*)(0x00633CD0), (char*)(0x00633B08) },
	{ 978, (char*)(0x00633CAC), (char*)(0x00633B08) },
	{ 979, (char*)(0x00633C88), (char*)(0x00633B08) },
	{ 980, (char*)(0x00633EFC), (char*)(0x00633B08) },
	{ 981, (char*)(0x00633ED0), (char*)(0x00633B08) },
	{ 982, (char*)(0x00633EA4), (char*)(0x00633B08) },
	{ 983, (char*)(0x00633E80), (char*)(0x00633B08) },
	{ 984, (char*)(0x00633E5C), (char*)(0x00633B08) },
	{ 985, (char*)(0x00633E34), (char*)(0x00633B08) },
	{ 986, (char*)(0x00633E0C), (char*)(0x00633B08) },
	{ 987, (char*)(0x00633FC0), (char*)(0x00633B08) },
	{ 988, (char*)(0x00633DE4), (char*)(0x00633B08) },
	{ 989, (char*)(0x00633DBC), (char*)(0x00633B08) },
	{ 990, (char*)(0x00633F70), (char*)(0x00633B08) },
	{ 991, (char*)(0x00633D90), (char*)(0x00633B08) },
	{ 992, (char*)(0x00633D64), (char*)(0x00633B08) },
	{ 993, (char*)(0x00633D38), (char*)(0x00633B08) },
	{ 994, (char*)(0x00633F4C), (char*)(0x00633B08) },
	{ 995, (char*)(0x00633F28), (char*)(0x00633B08) },
	{ 996, (char*)(0x006342FC), (char*)(0x00633AE8) },
	{ 997, (char*)(0x006342C4), (char*)(0x00633AE8) },
	{ 998, (char*)(0x006342A0), (char*)(0x00633AE8) },
	{ 999, (char*)(0x0063427C), (char*)(0x00633AE8) },
	{ 1000, (char*)(0x00634258), (char*)(0x00633AE8) },
	{ 1001, (char*)(0x00634234), (char*)(0x00633AE8) },
	{ 1002, (char*)(0x00634210), (char*)(0x00633AE8) },
	{ 1003, (char*)(0x006341EC), (char*)(0x00633AE8) },
	{ 1004, (char*)(0x006341C8), (char*)(0x00633AE8) },
	{ 1005, (char*)(0x006341A4), (char*)(0x00633AE8) },
	{ 1006, (char*)(0x00634180), (char*)(0x00633AE8) },
	{ 1007, (char*)(0x00634154), (char*)(0x00633AE8) },
	{ 1008, (char*)(0x00634128), (char*)(0x00633AE8) },
	{ 1009, (char*)(0x00634108), (char*)(0x00633AE8) },
	{ 1010, (char*)(0x006340E8), (char*)(0x00633AE8) },
	{ 1011, (char*)(0x006340C8), (char*)(0x00633AE8) },
	{ 1012, (char*)(0x006340A8), (char*)(0x00633AE8) },
	{ 1013, (char*)(0x00634088), (char*)(0x00633AE8) },
	{ 1014, (char*)(0x00634060), (char*)(0x00633AE8) },
	{ 1015, (char*)(0x00634038), (char*)(0x00633AE8) },
	{ 1016, (char*)(0x00634010), (char*)(0x00633AE8) },
	{ 1017, (char*)(0x00633FE8), (char*)(0x00633AE8) },
	{ 1018, (char*)(0x00633CF4), (char*)(0x00633AE8) },
	{ 1019, (char*)(0x00633F98), (char*)(0x00633AE8) },
	{ 1020, (char*)(0x00633CD0), (char*)(0x00633AE8) },
	{ 1021, (char*)(0x00633CAC), (char*)(0x00633AE8) },
	{ 1022, (char*)(0x00633C88), (char*)(0x00633AE8) },
	{ 1023, (char*)(0x00633EFC), (char*)(0x00633AE8) },
	{ 1024, (char*)(0x00633ED0), (char*)(0x00633AE8) },
	{ 1025, (char*)(0x00633EA4), (char*)(0x00633AE8) },
	{ 1026, (char*)(0x00633E80), (char*)(0x00633AE8) },
	{ 1027, (char*)(0x00633E5C), (char*)(0x00633AE8) },
	{ 1028, (char*)(0x00633E34), (char*)(0x00633AE8) },
	{ 1029, (char*)(0x00633E0C), (char*)(0x00633AE8) },
	{ 1030, (char*)(0x00633FC0), (char*)(0x00633AE8) },
	{ 1031, (char*)(0x00633DE4), (char*)(0x00633AE8) },
	{ 1032, (char*)(0x00633DBC), (char*)(0x00633AE8) },
	{ 1033, (char*)(0x00633F70), (char*)(0x00633AE8) },
	{ 1034, (char*)(0x00633D90), (char*)(0x00633AE8) },
	{ 1035, (char*)(0x00633D64), (char*)(0x00633AE8) },
	{ 1036, (char*)(0x00633D38), (char*)(0x00633AE8) },
	{ 1037, (char*)(0x00633F4C), (char*)(0x00633AE8) },
	{ 1038, (char*)(0x00633F28), (char*)(0x00633AE8) },
	{ 1039, (char*)(0x006342FC), (char*)(0x00633AC4) },
	{ 1040, (char*)(0x006342C4), (char*)(0x00633AC4) },
	{ 1041, (char*)(0x006342A0), (char*)(0x00633AC4) },
	{ 1042, (char*)(0x0063427C), (char*)(0x00633AC4) },
	{ 1043, (char*)(0x00634258), (char*)(0x00633AC4) },
	{ 1044, (char*)(0x00634234), (char*)(0x00633AC4) },
	{ 1045, (char*)(0x00634210), (char*)(0x00633AC4) },
	{ 1046, (char*)(0x006341EC), (char*)(0x00633AC4) },
	{ 1047, (char*)(0x006341C8), (char*)(0x00633AC4) },
	{ 1048, (char*)(0x006341A4), (char*)(0x00633AC4) },
	{ 1049, (char*)(0x00634180), (char*)(0x00633AC4) },
	{ 1050, (char*)(0x00634154), (char*)(0x00633AC4) },
	{ 1051, (char*)(0x00634128), (char*)(0x00633AC4) },
	{ 1052, (char*)(0x00634108), (char*)(0x00633AC4) },
	{ 1053, (char*)(0x006340E8), (char*)(0x00633AC4) },
	{ 1054, (char*)(0x006340C8), (char*)(0x00633AC4) },
	{ 1055, (char*)(0x006340A8), (char*)(0x00633AC4) },
	{ 1056, (char*)(0x00634088), (char*)(0x00633AC4) },
	{ 1057, (char*)(0x00634060), (char*)(0x00633AC4) },
	{ 1058, (char*)(0x00634038), (char*)(0x00633AC4) },
	{ 1059, (char*)(0x00634010), (char*)(0x00633AC4) },
	{ 1060, (char*)(0x00633FE8), (char*)(0x00633AC4) },
	{ 1061, (char*)(0x00633CF4), (char*)(0x00633AC4) },
	{ 1062, (char*)(0x00633F98), (char*)(0x00633AC4) },
	{ 1063, (char*)(0x00633CD0), (char*)(0x00633AC4) },
	{ 1064, (char*)(0x00633CAC), (char*)(0x00633AC4) },
	{ 1065, (char*)(0x00633C88), (char*)(0x00633AC4) },
	{ 1066, (char*)(0x00633EFC), (char*)(0x00633AC4) },
	{ 1067, (char*)(0x00633ED0), (char*)(0x00633AC4) },
	{ 1068, (char*)(0x00633EA4), (char*)(0x00633AC4) },
	{ 1069, (char*)(0x00633E80), (char*)(0x00633AC4) },
	{ 1070, (char*)(0x00633E5C), (char*)(0x00633AC4) },
	{ 1071, (char*)(0x00633E34), (char*)(0x00633AC4) },
	{ 1072, (char*)(0x00633E0C), (char*)(0x00633AC4) },
	{ 1073, (char*)(0x00633FC0), (char*)(0x00633AC4) },
	{ 1074, (char*)(0x00633DE4), (char*)(0x00633AC4) },
	{ 1075, (char*)(0x00633DBC), (char*)(0x00633AC4) },
	{ 1076, (char*)(0x00633F70), (char*)(0x00633AC4) },
	{ 1077, (char*)(0x00633D90), (char*)(0x00633AC4) },
	{ 1078, (char*)(0x00633D64), (char*)(0x00633AC4) },
	{ 1079, (char*)(0x00633D38), (char*)(0x00633AC4) },
	{ 1080, (char*)(0x00633F4C), (char*)(0x00633AC4) },
	{ 1081, (char*)(0x00633F28), (char*)(0x00633AC4) },
	{ 1082, (char*)(0x006342FC), (char*)(0x00633AA0) },
	{ 1083, (char*)(0x006342C4), (char*)(0x00633AA0) },
	{ 1084, (char*)(0x006342A0), (char*)(0x00633AA0) },
	{ 1085, (char*)(0x0063427C), (char*)(0x00633AA0) },
	{ 1086, (char*)(0x00634258), (char*)(0x00633AA0) },
	{ 1087, (char*)(0x00634234), (char*)(0x00633AA0) },
	{ 1088, (char*)(0x00634210), (char*)(0x00633AA0) },
	{ 1089, (char*)(0x006341EC), (char*)(0x00633AA0) },
	{ 1090, (char*)(0x006341C8), (char*)(0x00633AA0) },
	{ 1091, (char*)(0x006341A4), (char*)(0x00633AA0) },
	{ 1092, (char*)(0x00634180), (char*)(0x00633AA0) },
	{ 1093, (char*)(0x00634154), (char*)(0x00633AA0) },
	{ 1094, (char*)(0x00634128), (char*)(0x00633AA0) },
	{ 1095, (char*)(0x00634108), (char*)(0x00633AA0) },
	{ 1096, (char*)(0x006340E8), (char*)(0x00633AA0) },
	{ 1097, (char*)(0x006340C8), (char*)(0x00633AA0) },
	{ 1098, (char*)(0x006340A8), (char*)(0x00633AA0) },
	{ 1099, (char*)(0x00634088), (char*)(0x00633AA0) },
	{ 1100, (char*)(0x00634060), (char*)(0x00633AA0) },
	{ 1101, (char*)(0x00634038), (char*)(0x00633AA0) },
	{ 1102, (char*)(0x00634010), (char*)(0x00633AA0) },
	{ 1103, (char*)(0x00633FE8), (char*)(0x00633AA0) },
	{ 1104, (char*)(0x00633CF4), (char*)(0x00633AA0) },
	{ 1105, (char*)(0x00633F98), (char*)(0x00633AA0) },
	{ 1106, (char*)(0x00633CD0), (char*)(0x00633AA0) },
	{ 1107, (char*)(0x00633CAC), (char*)(0x00633AA0) },
	{ 1108, (char*)(0x00633C88), (char*)(0x00633AA0) },
	{ 1109, (char*)(0x00633EFC), (char*)(0x00633AA0) },
	{ 1110, (char*)(0x00633ED0), (char*)(0x00633AA0) },
	{ 1111, (char*)(0x00633EA4), (char*)(0x00633AA0) },
	{ 1112, (char*)(0x00633E80), (char*)(0x00633AA0) },
	{ 1113, (char*)(0x00633E5C), (char*)(0x00633AA0) },
	{ 1114, (char*)(0x00633E34), (char*)(0x00633AA0) },
	{ 1115, (char*)(0x00633E0C), (char*)(0x00633AA0) },
	{ 1116, (char*)(0x00633FC0), (char*)(0x00633AA0) },
	{ 1117, (char*)(0x00633DE4), (char*)(0x00633AA0) },
	{ 1118, (char*)(0x00633DBC), (char*)(0x00633AA0) },
	{ 1119, (char*)(0x00633F70), (char*)(0x00633AA0) },
	{ 1120, (char*)(0x00633D90), (char*)(0x00633AA0) },
	{ 1121, (char*)(0x00633D64), (char*)(0x00633AA0) },
	{ 1122, (char*)(0x00633D38), (char*)(0x00633AA0) },
	{ 1123, (char*)(0x00633F4C), (char*)(0x00633AA0) },
	{ 1124, (char*)(0x00633F28), (char*)(0x00633AA0) },
	{ 1125, (char*)(0x006342FC), (char*)(0x00633A7C) },
	{ 1126, (char*)(0x006342C4), (char*)(0x00633A7C) },
	{ 1127, (char*)(0x006342A0), (char*)(0x00633A7C) },
	{ 1128, (char*)(0x0063427C), (char*)(0x00633A7C) },
	{ 1129, (char*)(0x00634258), (char*)(0x00633A7C) },
	{ 1130, (char*)(0x00634234), (char*)(0x00633A7C) },
	{ 1131, (char*)(0x00634210), (char*)(0x00633A7C) },
	{ 1132, (char*)(0x006341EC), (char*)(0x00633A7C) },
	{ 1133, (char*)(0x006341C8), (char*)(0x00633A7C) },
	{ 1134, (char*)(0x006341A4), (char*)(0x00633A7C) },
	{ 1135, (char*)(0x00634180), (char*)(0x00633A7C) },
	{ 1136, (char*)(0x00634154), (char*)(0x00633A7C) },
	{ 1137, (char*)(0x00634128), (char*)(0x00633A7C) },
	{ 1138, (char*)(0x00634108), (char*)(0x00633A7C) },
	{ 1139, (char*)(0x006340E8), (char*)(0x00633A7C) },
	{ 1140, (char*)(0x006340C8), (char*)(0x00633A7C) },
	{ 1141, (char*)(0x006340A8), (char*)(0x00633A7C) },
	{ 1142, (char*)(0x00634088), (char*)(0x00633A7C) },
	{ 1143, (char*)(0x00634060), (char*)(0x00633A7C) },
	{ 1144, (char*)(0x00634038), (char*)(0x00633A7C) },
	{ 1145, (char*)(0x00634010), (char*)(0x00633A7C) },
	{ 1146, (char*)(0x00633FE8), (char*)(0x00633A7C) },
	{ 1147, (char*)(0x00633CF4), (char*)(0x00633A7C) },
	{ 1148, (char*)(0x00633F98), (char*)(0x00633A7C) },
	{ 1149, (char*)(0x00633CD0), (char*)(0x00633A7C) },
	{ 1150, (char*)(0x00633CAC), (char*)(0x00633A7C) },
	{ 1151, (char*)(0x00633C88), (char*)(0x00633A7C) },
	{ 1152, (char*)(0x00633EFC), (char*)(0x00633A7C) },
	{ 1153, (char*)(0x00633ED0), (char*)(0x00633A7C) },
	{ 1154, (char*)(0x00633EA4), (char*)(0x00633A7C) },
	{ 1155, (char*)(0x00633E80), (char*)(0x00633A7C) },
	{ 1156, (char*)(0x00633E5C), (char*)(0x00633A7C) },
	{ 1157, (char*)(0x00633E34), (char*)(0x00633A7C) },
	{ 1158, (char*)(0x00633E0C), (char*)(0x00633A7C) },
	{ 1159, (char*)(0x00633FC0), (char*)(0x00633A7C) },
	{ 1160, (char*)(0x00633DE4), (char*)(0x00633A7C) },
	{ 1161, (char*)(0x00633DBC), (char*)(0x00633A7C) },
	{ 1162, (char*)(0x00633F70), (char*)(0x00633A7C) },
	{ 1163, (char*)(0x00633D90), (char*)(0x00633A7C) },
	{ 1164, (char*)(0x00633D64), (char*)(0x00633A7C) },
	{ 1165, (char*)(0x00633D38), (char*)(0x00633A7C) },
	{ 1166, (char*)(0x00633F4C), (char*)(0x00633A7C) },
	{ 1167, (char*)(0x00633F28), (char*)(0x00633A7C) },
	{ 1168, (char*)(0x006342FC), (char*)(0x00633A58) },
	{ 1169, (char*)(0x006342C4), (char*)(0x00633A58) },
	{ 1170, (char*)(0x006342A0), (char*)(0x00633A58) },
	{ 1171, (char*)(0x0063427C), (char*)(0x00633A58) },
	{ 1172, (char*)(0x00634258), (char*)(0x00633A58) },
	{ 1173, (char*)(0x00634234), (char*)(0x00633A58) },
	{ 1174, (char*)(0x00634210), (char*)(0x00633A58) },
	{ 1175, (char*)(0x006341EC), (char*)(0x00633A58) },
	{ 1176, (char*)(0x006341C8), (char*)(0x00633A58) },
	{ 1177, (char*)(0x006341A4), (char*)(0x00633A58) },
	{ 1178, (char*)(0x00634180), (char*)(0x00633A58) },
	{ 1179, (char*)(0x00634154), (char*)(0x00633A58) },
	{ 1180, (char*)(0x00634128), (char*)(0x00633A58) },
	{ 1181, (char*)(0x00634108), (char*)(0x00633A58) },
	{ 1182, (char*)(0x006340E8), (char*)(0x00633A58) },
	{ 1183, (char*)(0x006340C8), (char*)(0x00633A58) },
	{ 1184, (char*)(0x006340A8), (char*)(0x00633A58) },
	{ 1185, (char*)(0x00634088), (char*)(0x00633A58) },
	{ 1186, (char*)(0x00634060), (char*)(0x00633A58) },
	{ 1187, (char*)(0x00634038), (char*)(0x00633A58) },
	{ 1188, (char*)(0x00634010), (char*)(0x00633A58) },
	{ 1189, (char*)(0x00633FE8), (char*)(0x00633A58) },
	{ 1190, (char*)(0x00633CF4), (char*)(0x00633A58) },
	{ 1191, (char*)(0x00633F98), (char*)(0x00633A58) },
	{ 1192, (char*)(0x00633CD0), (char*)(0x00633A58) },
	{ 1193, (char*)(0x00633CAC), (char*)(0x00633A58) },
	{ 1194, (char*)(0x00633C88), (char*)(0x00633A58) },
	{ 1195, (char*)(0x00633EFC), (char*)(0x00633A58) },
	{ 1196, (char*)(0x00633ED0), (char*)(0x00633A58) },
	{ 1197, (char*)(0x00633EA4), (char*)(0x00633A58) },
	{ 1198, (char*)(0x00633E80), (char*)(0x00633A58) },
	{ 1199, (char*)(0x00633E5C), (char*)(0x00633A58) },
	{ 1200, (char*)(0x00633E34), (char*)(0x00633A58) },
	{ 1201, (char*)(0x00633E0C), (char*)(0x00633A58) },
	{ 1202, (char*)(0x00633FC0), (char*)(0x00633A58) },
	{ 1203, (char*)(0x00633DE4), (char*)(0x00633A58) },
	{ 1204, (char*)(0x00633DBC), (char*)(0x00633A58) },
	{ 1205, (char*)(0x00633F70), (char*)(0x00633A58) },
	{ 1206, (char*)(0x00633D90), (char*)(0x00633A58) },
	{ 1207, (char*)(0x00633D64), (char*)(0x00633A58) },
	{ 1208, (char*)(0x00633D38), (char*)(0x00633A58) },
	{ 1209, (char*)(0x00633F4C), (char*)(0x00633A58) },
	{ 1210, (char*)(0x00633F28), (char*)(0x00633A58) },
	{ 1211, (char*)(0x006342FC), (char*)(0x00633A20) },
	{ 1212, (char*)(0x006342C4), (char*)(0x00633A20) },
	{ 1213, (char*)(0x006342A0), (char*)(0x00633A20) },
	{ 1214, (char*)(0x0063427C), (char*)(0x00633A20) },
	{ 1215, (char*)(0x00634258), (char*)(0x00633A20) },
	{ 1216, (char*)(0x00634234), (char*)(0x00633A20) },
	{ 1217, (char*)(0x00634210), (char*)(0x00633A20) },
	{ 1218, (char*)(0x006341EC), (char*)(0x00633A20) },
	{ 1219, (char*)(0x006341C8), (char*)(0x00633A20) },
	{ 1220, (char*)(0x006341A4), (char*)(0x00633A20) },
	{ 1221, (char*)(0x00634180), (char*)(0x00633A20) },
	{ 1222, (char*)(0x00634154), (char*)(0x00633A20) },
	{ 1223, (char*)(0x00634128), (char*)(0x00633A20) },
	{ 1224, (char*)(0x00634108), (char*)(0x00633A20) },
	{ 1225, (char*)(0x006340E8), (char*)(0x00633A20) },
	{ 1226, (char*)(0x006340C8), (char*)(0x00633A20) },
	{ 1227, (char*)(0x006340A8), (char*)(0x00633A20) },
	{ 1228, (char*)(0x00634088), (char*)(0x00633A20) },
	{ 1229, (char*)(0x00634060), (char*)(0x00633A20) },
	{ 1230, (char*)(0x00634038), (char*)(0x00633A20) },
	{ 1231, (char*)(0x00634010), (char*)(0x00633A20) },
	{ 1232, (char*)(0x00633FE8), (char*)(0x00633A20) },
	{ 1233, (char*)(0x00633CF4), (char*)(0x00633A20) },
	{ 1234, (char*)(0x00633F98), (char*)(0x00633A20) },
	{ 1235, (char*)(0x00633CD0), (char*)(0x00633A20) },
	{ 1236, (char*)(0x00633CAC), (char*)(0x00633A20) },
	{ 1237, (char*)(0x00633C88), (char*)(0x00633A20) },
	{ 1238, (char*)(0x00633EFC), (char*)(0x00633A20) },
	{ 1239, (char*)(0x00633ED0), (char*)(0x00633A20) },
	{ 1240, (char*)(0x00633EA4), (char*)(0x00633A20) },
	{ 1241, (char*)(0x00633E80), (char*)(0x00633A20) },
	{ 1242, (char*)(0x00633E5C), (char*)(0x00633A20) },
	{ 1243, (char*)(0x00633E34), (char*)(0x00633A20) },
	{ 1244, (char*)(0x00633E0C), (char*)(0x00633A20) },
	{ 1245, (char*)(0x00633FC0), (char*)(0x00633A20) },
	{ 1246, (char*)(0x00633DE4), (char*)(0x00633A20) },
	{ 1247, (char*)(0x00633DBC), (char*)(0x00633A20) },
	{ 1248, (char*)(0x00633F70), (char*)(0x00633A20) },
	{ 1249, (char*)(0x00633D90), (char*)(0x00633A20) },
	{ 1250, (char*)(0x00633D64), (char*)(0x00633A20) },
	{ 1251, (char*)(0x00633D38), (char*)(0x00633A20) },
	{ 1252, (char*)(0x00633F4C), (char*)(0x00633A20) },
	{ 1253, (char*)(0x00633F28), (char*)(0x00633A20) },
	{ 1254, (char*)(0x006342FC), (char*)(0x006339FC) },
	{ 1255, (char*)(0x006342C4), (char*)(0x006339FC) },
	{ 1256, (char*)(0x006342A0), (char*)(0x006339FC) },
	{ 1257, (char*)(0x0063427C), (char*)(0x006339FC) },
	{ 1258, (char*)(0x00634258), (char*)(0x006339FC) },
	{ 1259, (char*)(0x00634234), (char*)(0x006339FC) },
	{ 1260, (char*)(0x00634210), (char*)(0x006339FC) },
	{ 1261, (char*)(0x006341EC), (char*)(0x006339FC) },
	{ 1262, (char*)(0x006341C8), (char*)(0x006339FC) },
	{ 1263, (char*)(0x006341A4), (char*)(0x006339FC) },
	{ 1264, (char*)(0x00634180), (char*)(0x006339FC) },
	{ 1265, (char*)(0x00634154), (char*)(0x006339FC) },
	{ 1266, (char*)(0x00634128), (char*)(0x006339FC) },
	{ 1267, (char*)(0x00634108), (char*)(0x006339FC) },
	{ 1268, (char*)(0x006340E8), (char*)(0x006339FC) },
	{ 1269, (char*)(0x006340C8), (char*)(0x006339FC) },
	{ 1270, (char*)(0x006340A8), (char*)(0x006339FC) },
	{ 1271, (char*)(0x00634088), (char*)(0x006339FC) },
	{ 1272, (char*)(0x00634060), (char*)(0x006339FC) },
	{ 1273, (char*)(0x00634038), (char*)(0x006339FC) },
	{ 1274, (char*)(0x00634010), (char*)(0x006339FC) },
	{ 1275, (char*)(0x00633FE8), (char*)(0x006339FC) },
	{ 1276, (char*)(0x00633CF4), (char*)(0x006339FC) },
	{ 1277, (char*)(0x00633F98), (char*)(0x006339FC) },
	{ 1278, (char*)(0x00633CD0), (char*)(0x006339FC) },
	{ 1279, (char*)(0x00633CAC), (char*)(0x006339FC) },
	{ 1280, (char*)(0x00633C88), (char*)(0x006339FC) },
	{ 1281, (char*)(0x00633EFC), (char*)(0x006339FC) },
	{ 1282, (char*)(0x00633ED0), (char*)(0x006339FC) },
	{ 1283, (char*)(0x00633EA4), (char*)(0x006339FC) },
	{ 1284, (char*)(0x00633E80), (char*)(0x006339FC) },
	{ 1285, (char*)(0x00633E5C), (char*)(0x006339FC) },
	{ 1286, (char*)(0x00633E34), (char*)(0x006339FC) },
	{ 1287, (char*)(0x00633E0C), (char*)(0x006339FC) },
	{ 1288, (char*)(0x00633FC0), (char*)(0x006339FC) },
	{ 1289, (char*)(0x00633DE4), (char*)(0x006339FC) },
	{ 1290, (char*)(0x00633DBC), (char*)(0x006339FC) },
	{ 1291, (char*)(0x00633F70), (char*)(0x006339FC) },
	{ 1292, (char*)(0x00633D90), (char*)(0x006339FC) },
	{ 1293, (char*)(0x00633D64), (char*)(0x006339FC) },
	{ 1294, (char*)(0x00633D38), (char*)(0x006339FC) },
	{ 1295, (char*)(0x00633F4C), (char*)(0x006339FC) },
	{ 1296, (char*)(0x00633F28), (char*)(0x006339FC) },
	{ 1297, (char*)(0x006342FC), (char*)(0x006339E4) },
	{ 1298, (char*)(0x006342C4), (char*)(0x006339E4) },
	{ 1299, (char*)(0x006342A0), (char*)(0x006339E4) },
	{ 1300, (char*)(0x0063427C), (char*)(0x006339E4) },
	{ 1301, (char*)(0x00634258), (char*)(0x006339E4) },
	{ 1302, (char*)(0x00634234), (char*)(0x006339E4) },
	{ 1303, (char*)(0x00634210), (char*)(0x006339E4) },
	{ 1304, (char*)(0x006341EC), (char*)(0x006339E4) },
	{ 1305, (char*)(0x006341C8), (char*)(0x006339E4) },
	{ 1306, (char*)(0x006341A4), (char*)(0x006339E4) },
	{ 1307, (char*)(0x00634180), (char*)(0x006339E4) },
	{ 1308, (char*)(0x00634154), (char*)(0x006339E4) },
	{ 1309, (char*)(0x00634128), (char*)(0x006339E4) },
	{ 1310, (char*)(0x00634108), (char*)(0x006339E4) },
	{ 1311, (char*)(0x006340E8), (char*)(0x006339E4) },
	{ 1312, (char*)(0x006340C8), (char*)(0x006339E4) },
	{ 1313, (char*)(0x006340A8), (char*)(0x006339E4) },
	{ 1314, (char*)(0x00634088), (char*)(0x006339E4) },
	{ 1315, (char*)(0x00634060), (char*)(0x006339E4) },
	{ 1316, (char*)(0x00634038), (char*)(0x006339E4) },
	{ 1317, (char*)(0x00634010), (char*)(0x006339E4) },
	{ 1318, (char*)(0x00633FE8), (char*)(0x006339E4) },
	{ 1319, (char*)(0x00633CF4), (char*)(0x006339E4) },
	{ 1320, (char*)(0x00633F98), (char*)(0x006339E4) },
	{ 1321, (char*)(0x00633CD0), (char*)(0x006339E4) },
	{ 1322, (char*)(0x00633CAC), (char*)(0x006339E4) },
	{ 1323, (char*)(0x00633C88), (char*)(0x006339E4) },
	{ 1324, (char*)(0x00633EFC), (char*)(0x006339E4) },
	{ 1325, (char*)(0x00633ED0), (char*)(0x006339E4) },
	{ 1326, (char*)(0x00633EA4), (char*)(0x006339E4) },
	{ 1327, (char*)(0x00633E80), (char*)(0x006339E4) },
	{ 1328, (char*)(0x00633E5C), (char*)(0x006339E4) },
	{ 1329, (char*)(0x00633E34), (char*)(0x006339E4) },
	{ 1330, (char*)(0x00633E0C), (char*)(0x006339E4) },
	{ 1331, (char*)(0x00633FC0), (char*)(0x006339E4) },
	{ 1332, (char*)(0x00633DE4), (char*)(0x006339E4) },
	{ 1333, (char*)(0x00633DBC), (char*)(0x006339E4) },
	{ 1334, (char*)(0x00633F70), (char*)(0x006339E4) },
	{ 1335, (char*)(0x00633D90), (char*)(0x006339E4) },
	{ 1336, (char*)(0x00633D64), (char*)(0x006339E4) },
	{ 1337, (char*)(0x00633D38), (char*)(0x006339E4) },
	{ 1338, (char*)(0x00633F4C), (char*)(0x006339E4) },
	{ 1339, (char*)(0x00633F28), (char*)(0x006339E4) },
	{ 1340, (char*)(0x006342FC), (char*)(0x006339C4) },
	{ 1341, (char*)(0x006342C4), (char*)(0x006339C4) },
	{ 1342, (char*)(0x006342A0), (char*)(0x006339C4) },
	{ 1343, (char*)(0x0063427C), (char*)(0x006339C4) },
	{ 1344, (char*)(0x00634258), (char*)(0x006339C4) },
	{ 1345, (char*)(0x00634234), (char*)(0x006339C4) },
	{ 1346, (char*)(0x00634210), (char*)(0x006339C4) },
	{ 1347, (char*)(0x006341EC), (char*)(0x006339C4) },
	{ 1348, (char*)(0x006341C8), (char*)(0x006339C4) },
	{ 1349, (char*)(0x006341A4), (char*)(0x006339C4) },
	{ 1350, (char*)(0x00634180), (char*)(0x006339C4) },
	{ 1351, (char*)(0x00634154), (char*)(0x006339C4) },
	{ 1352, (char*)(0x00634128), (char*)(0x006339C4) },
	{ 1353, (char*)(0x00634108), (char*)(0x006339C4) },
	{ 1354, (char*)(0x006340E8), (char*)(0x006339C4) },
	{ 1355, (char*)(0x006340C8), (char*)(0x006339C4) },
	{ 1356, (char*)(0x006340A8), (char*)(0x006339C4) },
	{ 1357, (char*)(0x00634088), (char*)(0x006339C4) },
	{ 1358, (char*)(0x00634060), (char*)(0x006339C4) },
	{ 1359, (char*)(0x00634038), (char*)(0x006339C4) },
	{ 1360, (char*)(0x00634010), (char*)(0x006339C4) },
	{ 1361, (char*)(0x00633FE8), (char*)(0x006339C4) },
	{ 1362, (char*)(0x00633CF4), (char*)(0x006339C4) },
	{ 1363, (char*)(0x00633F98), (char*)(0x006339C4) },
	{ 1364, (char*)(0x00633CD0), (char*)(0x006339C4) },
	{ 1365, (char*)(0x00633CAC), (char*)(0x006339C4) },
	{ 1366, (char*)(0x00633C88), (char*)(0x006339C4) },
	{ 1367, (char*)(0x00633EFC), (char*)(0x006339C4) },
	{ 1368, (char*)(0x00633ED0), (char*)(0x006339C4) },
	{ 1369, (char*)(0x00633EA4), (char*)(0x006339C4) },
	{ 1370, (char*)(0x00633E80), (char*)(0x006339C4) },
	{ 1371, (char*)(0x00633E5C), (char*)(0x006339C4) },
	{ 1372, (char*)(0x00633E34), (char*)(0x006339C4) },
	{ 1373, (char*)(0x00633E0C), (char*)(0x006339C4) },
	{ 1374, (char*)(0x00633FC0), (char*)(0x006339C4) },
	{ 1375, (char*)(0x00633DE4), (char*)(0x006339C4) },
	{ 1376, (char*)(0x00633DBC), (char*)(0x006339C4) },
	{ 1377, (char*)(0x00633F70), (char*)(0x006339C4) },
	{ 1378, (char*)(0x00633D90), (char*)(0x006339C4) },
	{ 1379, (char*)(0x00633D64), (char*)(0x006339C4) },
	{ 1380, (char*)(0x00633D38), (char*)(0x006339C4) },
	{ 1381, (char*)(0x00633F4C), (char*)(0x006339C4) },
	{ 1382, (char*)(0x00633F28), (char*)(0x006339C4) },
	{ 1383, (char*)(0x006342FC), (char*)(0x0063399C) },
	{ 1384, (char*)(0x006342C4), (char*)(0x0063399C) },
	{ 1385, (char*)(0x006342A0), (char*)(0x0063399C) },
	{ 1386, (char*)(0x0063427C), (char*)(0x0063399C) },
	{ 1387, (char*)(0x00634258), (char*)(0x0063399C) },
	{ 1388, (char*)(0x00634234), (char*)(0x0063399C) },
	{ 1389, (char*)(0x00634210), (char*)(0x0063399C) },
	{ 1390, (char*)(0x006341EC), (char*)(0x0063399C) },
	{ 1391, (char*)(0x006341C8), (char*)(0x0063399C) },
	{ 1392, (char*)(0x006341A4), (char*)(0x0063399C) },
	{ 1393, (char*)(0x00634180), (char*)(0x0063399C) },
	{ 1394, (char*)(0x00634154), (char*)(0x0063399C) },
	{ 1395, (char*)(0x00634128), (char*)(0x0063399C) },
	{ 1396, (char*)(0x00634108), (char*)(0x0063399C) },
	{ 1397, (char*)(0x006340E8), (char*)(0x0063399C) },
	{ 1398, (char*)(0x006340C8), (char*)(0x0063399C) },
	{ 1399, (char*)(0x006340A8), (char*)(0x0063399C) },
	{ 1400, (char*)(0x00634088), (char*)(0x0063399C) },
	{ 1401, (char*)(0x00634060), (char*)(0x0063399C) },
	{ 1402, (char*)(0x00634038), (char*)(0x0063399C) },
	{ 1403, (char*)(0x00634010), (char*)(0x0063399C) },
	{ 1404, (char*)(0x00633FE8), (char*)(0x0063399C) },
	{ 1405, (char*)(0x00633CF4), (char*)(0x0063399C) },
	{ 1406, (char*)(0x00633F98), (char*)(0x0063399C) },
	{ 1407, (char*)(0x00633CD0), (char*)(0x0063399C) },
	{ 1408, (char*)(0x00633CAC), (char*)(0x0063399C) },
	{ 1409, (char*)(0x00633C88), (char*)(0x0063399C) },
	{ 1410, (char*)(0x00633EFC), (char*)(0x0063399C) },
	{ 1411, (char*)(0x00633ED0), (char*)(0x0063399C) },
	{ 1412, (char*)(0x00633EA4), (char*)(0x0063399C) },
	{ 1413, (char*)(0x00633E80), (char*)(0x0063399C) },
	{ 1414, (char*)(0x00633E5C), (char*)(0x0063399C) },
	{ 1415, (char*)(0x00633E34), (char*)(0x0063399C) },
	{ 1416, (char*)(0x00633E0C), (char*)(0x0063399C) },
	{ 1417, (char*)(0x00633FC0), (char*)(0x0063399C) },
	{ 1418, (char*)(0x00633DE4), (char*)(0x0063399C) },
	{ 1419, (char*)(0x00633DBC), (char*)(0x0063399C) },
	{ 1420, (char*)(0x00633F70), (char*)(0x0063399C) },
	{ 1421, (char*)(0x00633D90), (char*)(0x0063399C) },
	{ 1422, (char*)(0x00633D64), (char*)(0x0063399C) },
	{ 1423, (char*)(0x00633D38), (char*)(0x0063399C) },
	{ 1424, (char*)(0x00633F4C), (char*)(0x0063399C) },
	{ 1425, (char*)(0x00633F28), (char*)(0x0063399C) },
	{ 1426, (char*)(0x006342FC), (char*)(0x0063397C) },
	{ 1427, (char*)(0x006342C4), (char*)(0x0063397C) },
	{ 1428, (char*)(0x006342A0), (char*)(0x0063397C) },
	{ 1429, (char*)(0x0063427C), (char*)(0x0063397C) },
	{ 1430, (char*)(0x00634258), (char*)(0x0063397C) },
	{ 1431, (char*)(0x00634234), (char*)(0x0063397C) },
	{ 1432, (char*)(0x00634210), (char*)(0x0063397C) },
	{ 1433, (char*)(0x006341EC), (char*)(0x0063397C) },
	{ 1434, (char*)(0x006341C8), (char*)(0x0063397C) },
	{ 1435, (char*)(0x006341A4), (char*)(0x0063397C) },
	{ 1436, (char*)(0x00634180), (char*)(0x0063397C) },
	{ 1437, (char*)(0x00634154), (char*)(0x0063397C) },
	{ 1438, (char*)(0x00634128), (char*)(0x0063397C) },
	{ 1439, (char*)(0x00634108), (char*)(0x0063397C) },
	{ 1440, (char*)(0x006340E8), (char*)(0x0063397C) },
	{ 1441, (char*)(0x006340C8), (char*)(0x0063397C) },
	{ 1442, (char*)(0x006340A8), (char*)(0x0063397C) },
	{ 1443, (char*)(0x00634088), (char*)(0x0063397C) },
	{ 1444, (char*)(0x00634060), (char*)(0x0063397C) },
	{ 1445, (char*)(0x00634038), (char*)(0x0063397C) },
	{ 1446, (char*)(0x00634010), (char*)(0x0063397C) },
	{ 1447, (char*)(0x00633FE8), (char*)(0x0063397C) },
	{ 1448, (char*)(0x00633CF4), (char*)(0x0063397C) },
	{ 1449, (char*)(0x00633F98), (char*)(0x0063397C) },
	{ 1450, (char*)(0x00633CD0), (char*)(0x0063397C) },
	{ 1451, (char*)(0x00633CAC), (char*)(0x0063397C) },
	{ 1452, (char*)(0x00633C88), (char*)(0x0063397C) },
	{ 1453, (char*)(0x00633EFC), (char*)(0x0063397C) },
	{ 1454, (char*)(0x00633ED0), (char*)(0x0063397C) },
	{ 1455, (char*)(0x00633EA4), (char*)(0x0063397C) },
	{ 1456, (char*)(0x00633E80), (char*)(0x0063397C) },
	{ 1457, (char*)(0x00633E5C), (char*)(0x0063397C) },
	{ 1458, (char*)(0x00633E34), (char*)(0x0063397C) },
	{ 1459, (char*)(0x00633E0C), (char*)(0x0063397C) },
	{ 1460, (char*)(0x00633FC0), (char*)(0x0063397C) },
	{ 1461, (char*)(0x00633DE4), (char*)(0x0063397C) },
	{ 1462, (char*)(0x00633DBC), (char*)(0x0063397C) },
	{ 1463, (char*)(0x00633F70), (char*)(0x0063397C) },
	{ 1464, (char*)(0x00633D90), (char*)(0x0063397C) },
	{ 1465, (char*)(0x00633D64), (char*)(0x0063397C) },
	{ 1466, (char*)(0x00633D38), (char*)(0x0063397C) },
	{ 1467, (char*)(0x00633F4C), (char*)(0x0063397C) },
	{ 1468, (char*)(0x00633F28), (char*)(0x0063397C) },
	{ 1469, (char*)(0x006342FC), (char*)(0x00633954) },
	{ 1470, (char*)(0x006342C4), (char*)(0x00633954) },
	{ 1471, (char*)(0x006342A0), (char*)(0x00633954) },
	{ 1472, (char*)(0x0063427C), (char*)(0x00633954) },
	{ 1473, (char*)(0x00634258), (char*)(0x00633954) },
	{ 1474, (char*)(0x00634234), (char*)(0x00633954) },
	{ 1475, (char*)(0x00634210), (char*)(0x00633954) },
	{ 1476, (char*)(0x006341EC), (char*)(0x00633954) },
	{ 1477, (char*)(0x006341C8), (char*)(0x00633954) },
	{ 1478, (char*)(0x006341A4), (char*)(0x00633954) },
	{ 1479, (char*)(0x00634180), (char*)(0x00633954) },
	{ 1480, (char*)(0x00634154), (char*)(0x00633954) },
	{ 1481, (char*)(0x00634128), (char*)(0x00633954) },
	{ 1482, (char*)(0x00634108), (char*)(0x00633954) },
	{ 1483, (char*)(0x006340E8), (char*)(0x00633954) },
	{ 1484, (char*)(0x006340C8), (char*)(0x00633954) },
	{ 1485, (char*)(0x006340A8), (char*)(0x00633954) },
	{ 1486, (char*)(0x00634088), (char*)(0x00633954) },
	{ 1487, (char*)(0x00634060), (char*)(0x00633954) },
	{ 1488, (char*)(0x00634038), (char*)(0x00633954) },
	{ 1489, (char*)(0x00634010), (char*)(0x00633954) },
	{ 1490, (char*)(0x00633FE8), (char*)(0x00633954) },
	{ 1491, (char*)(0x00633CF4), (char*)(0x00633954) },
	{ 1492, (char*)(0x00633F98), (char*)(0x00633954) },
	{ 1493, (char*)(0x00633CD0), (char*)(0x00633954) },
	{ 1494, (char*)(0x00633CAC), (char*)(0x00633954) },
	{ 1495, (char*)(0x00633C88), (char*)(0x00633954) },
	{ 1496, (char*)(0x00633EFC), (char*)(0x00633954) },
	{ 1497, (char*)(0x00633ED0), (char*)(0x00633954) },
	{ 1498, (char*)(0x00633EA4), (char*)(0x00633954) },
	{ 1499, (char*)(0x00633E80), (char*)(0x00633954) },
	{ 1500, (char*)(0x00633E5C), (char*)(0x00633954) },
	{ 1501, (char*)(0x00633E34), (char*)(0x00633954) },
	{ 1502, (char*)(0x00633E0C), (char*)(0x00633954) },
	{ 1503, (char*)(0x00633FC0), (char*)(0x00633954) },
	{ 1504, (char*)(0x00633DE4), (char*)(0x00633954) },
	{ 1505, (char*)(0x00633DBC), (char*)(0x00633954) },
	{ 1506, (char*)(0x00633F70), (char*)(0x00633954) },
	{ 1507, (char*)(0x00633D90), (char*)(0x00633954) },
	{ 1508, (char*)(0x00633D64), (char*)(0x00633954) },
	{ 1509, (char*)(0x00633D38), (char*)(0x00633954) },
	{ 1510, (char*)(0x00633F4C), (char*)(0x00633954) },
	{ 1511, (char*)(0x00633F28), (char*)(0x00633954) },
	{ 1512, (char*)(0x006342FC), (char*)(0x00633934) },
	{ 1513, (char*)(0x006342C4), (char*)(0x00633934) },
	{ 1514, (char*)(0x006342A0), (char*)(0x00633934) },
	{ 1515, (char*)(0x0063427C), (char*)(0x00633934) },
	{ 1516, (char*)(0x00634258), (char*)(0x00633934) },
	{ 1517, (char*)(0x00634234), (char*)(0x00633934) },
	{ 1518, (char*)(0x00634210), (char*)(0x00633934) },
	{ 1519, (char*)(0x006341EC), (char*)(0x00633934) },
	{ 1520, (char*)(0x006341C8), (char*)(0x00633934) },
	{ 1521, (char*)(0x006341A4), (char*)(0x00633934) },
	{ 1522, (char*)(0x00634180), (char*)(0x00633934) },
	{ 1523, (char*)(0x00634154), (char*)(0x00633934) },
	{ 1524, (char*)(0x00634128), (char*)(0x00633934) },
	{ 1525, (char*)(0x00634108), (char*)(0x00633934) },
	{ 1526, (char*)(0x006340E8), (char*)(0x00633934) },
	{ 1527, (char*)(0x006340C8), (char*)(0x00633934) },
	{ 1528, (char*)(0x006340A8), (char*)(0x00633934) },
	{ 1529, (char*)(0x00634088), (char*)(0x00633934) },
	{ 1530, (char*)(0x00634060), (char*)(0x00633934) },
	{ 1531, (char*)(0x00634038), (char*)(0x00633934) },
	{ 1532, (char*)(0x00634010), (char*)(0x00633934) },
	{ 1533, (char*)(0x00633FE8), (char*)(0x00633934) },
	{ 1534, (char*)(0x00633CF4), (char*)(0x00633934) },
	{ 1535, (char*)(0x00633F98), (char*)(0x00633934) },
	{ 1536, (char*)(0x00633CD0), (char*)(0x00633934) },
	{ 1537, (char*)(0x00633CAC), (char*)(0x00633934) },
	{ 1538, (char*)(0x00633C88), (char*)(0x00633934) },
	{ 1539, (char*)(0x00633EFC), (char*)(0x00633934) },
	{ 1540, (char*)(0x00633ED0), (char*)(0x00633934) },
	{ 1541, (char*)(0x00633EA4), (char*)(0x00633934) },
	{ 1542, (char*)(0x00633E80), (char*)(0x00633934) },
	{ 1543, (char*)(0x00633E5C), (char*)(0x00633934) },
	{ 1544, (char*)(0x00633E34), (char*)(0x00633934) },
	{ 1545, (char*)(0x00633E0C), (char*)(0x00633934) },
	{ 1546, (char*)(0x00633FC0), (char*)(0x00633934) },
	{ 1547, (char*)(0x00633DE4), (char*)(0x00633934) },
	{ 1548, (char*)(0x00633DBC), (char*)(0x00633934) },
	{ 1549, (char*)(0x00633F70), (char*)(0x00633934) },
	{ 1550, (char*)(0x00633D90), (char*)(0x00633934) },
	{ 1551, (char*)(0x00633D64), (char*)(0x00633934) },
	{ 1552, (char*)(0x00633D38), (char*)(0x00633934) },
	{ 1553, (char*)(0x00633F4C), (char*)(0x00633934) },
	{ 1554, (char*)(0x00633F28), (char*)(0x00633934) },
	{ 1555, (char*)(0x006342FC), (char*)(0x0063390C) },
	{ 1556, (char*)(0x006342C4), (char*)(0x0063390C) },
	{ 1557, (char*)(0x006342A0), (char*)(0x0063390C) },
	{ 1558, (char*)(0x0063427C), (char*)(0x0063390C) },
	{ 1559, (char*)(0x00634258), (char*)(0x0063390C) },
	{ 1560, (char*)(0x00634234), (char*)(0x0063390C) },
	{ 1561, (char*)(0x00634210), (char*)(0x0063390C) },
	{ 1562, (char*)(0x006341EC), (char*)(0x0063390C) },
	{ 1563, (char*)(0x006341C8), (char*)(0x0063390C) },
	{ 1564, (char*)(0x006341A4), (char*)(0x0063390C) },
	{ 1565, (char*)(0x00634180), (char*)(0x0063390C) },
	{ 1566, (char*)(0x00634154), (char*)(0x0063390C) },
	{ 1567, (char*)(0x00634128), (char*)(0x0063390C) },
	{ 1568, (char*)(0x00634108), (char*)(0x0063390C) },
	{ 1569, (char*)(0x006340E8), (char*)(0x0063390C) },
	{ 1570, (char*)(0x006340C8), (char*)(0x0063390C) },
	{ 1571, (char*)(0x006340A8), (char*)(0x0063390C) },
	{ 1572, (char*)(0x00634088), (char*)(0x0063390C) },
	{ 1573, (char*)(0x00634060), (char*)(0x0063390C) },
	{ 1574, (char*)(0x00634038), (char*)(0x0063390C) },
	{ 1575, (char*)(0x00634010), (char*)(0x0063390C) },
	{ 1576, (char*)(0x00633FE8), (char*)(0x0063390C) },
	{ 1577, (char*)(0x00633CF4), (char*)(0x0063390C) },
	{ 1578, (char*)(0x00633F98), (char*)(0x0063390C) },
	{ 1579, (char*)(0x00633CD0), (char*)(0x0063390C) },
	{ 1580, (char*)(0x00633CAC), (char*)(0x0063390C) },
	{ 1581, (char*)(0x00633C88), (char*)(0x0063390C) },
	{ 1582, (char*)(0x00633EFC), (char*)(0x0063390C) },
	{ 1583, (char*)(0x00633ED0), (char*)(0x0063390C) },
	{ 1584, (char*)(0x00633EA4), (char*)(0x0063390C) },
	{ 1585, (char*)(0x00633E80), (char*)(0x0063390C) },
	{ 1586, (char*)(0x00633E5C), (char*)(0x0063390C) },
	{ 1587, (char*)(0x00633E34), (char*)(0x0063390C) },
	{ 1588, (char*)(0x00633E0C), (char*)(0x0063390C) },
	{ 1589, (char*)(0x00633FC0), (char*)(0x0063390C) },
	{ 1590, (char*)(0x00633DE4), (char*)(0x0063390C) },
	{ 1591, (char*)(0x00633DBC), (char*)(0x0063390C) },
	{ 1592, (char*)(0x00633F70), (char*)(0x0063390C) },
	{ 1593, (char*)(0x00633D90), (char*)(0x0063390C) },
	{ 1594, (char*)(0x00633D64), (char*)(0x0063390C) },
	{ 1595, (char*)(0x00633D38), (char*)(0x0063390C) },
	{ 1596, (char*)(0x00633F4C), (char*)(0x0063390C) },
	{ 1597, (char*)(0x00633F28), (char*)(0x0063390C) },
	{ 1598, (char*)(0x006342FC), (char*)(0x006338DC) },
	{ 1599, (char*)(0x006342C4), (char*)(0x006338DC) },
	{ 1600, (char*)(0x006342A0), (char*)(0x006338DC) },
	{ 1601, (char*)(0x0063427C), (char*)(0x006338DC) },
	{ 1602, (char*)(0x00634258), (char*)(0x006338DC) },
	{ 1603, (char*)(0x00634234), (char*)(0x006338DC) },
	{ 1604, (char*)(0x00634210), (char*)(0x006338DC) },
	{ 1605, (char*)(0x006341EC), (char*)(0x006338DC) },
	{ 1606, (char*)(0x006341C8), (char*)(0x006338DC) },
	{ 1607, (char*)(0x006341A4), (char*)(0x006338DC) },
	{ 1608, (char*)(0x00634180), (char*)(0x006338DC) },
	{ 1609, (char*)(0x00634154), (char*)(0x006338DC) },
	{ 1610, (char*)(0x00634128), (char*)(0x006338DC) },
	{ 1611, (char*)(0x00634108), (char*)(0x006338DC) },
	{ 1612, (char*)(0x006340E8), (char*)(0x006338DC) },
	{ 1613, (char*)(0x006340C8), (char*)(0x006338DC) },
	{ 1614, (char*)(0x006340A8), (char*)(0x006338DC) },
	{ 1615, (char*)(0x00634088), (char*)(0x006338DC) },
	{ 1616, (char*)(0x00634060), (char*)(0x006338DC) },
	{ 1617, (char*)(0x00634038), (char*)(0x006338DC) },
	{ 1618, (char*)(0x00634010), (char*)(0x006338DC) },
	{ 1619, (char*)(0x00633FE8), (char*)(0x006338DC) },
	{ 1620, (char*)(0x00633CF4), (char*)(0x006338DC) },
	{ 1621, (char*)(0x00633F98), (char*)(0x006338DC) },
	{ 1622, (char*)(0x00633CD0), (char*)(0x006338DC) },
	{ 1623, (char*)(0x00633CAC), (char*)(0x006338DC) },
	{ 1624, (char*)(0x00633C88), (char*)(0x006338DC) },
	{ 1625, (char*)(0x00633EFC), (char*)(0x006338DC) },
	{ 1626, (char*)(0x00633ED0), (char*)(0x006338DC) },
	{ 1627, (char*)(0x00633EA4), (char*)(0x006338DC) },
	{ 1628, (char*)(0x00633E80), (char*)(0x006338DC) },
	{ 1629, (char*)(0x00633E5C), (char*)(0x006338DC) },
	{ 1630, (char*)(0x00633E34), (char*)(0x006338DC) },
	{ 1631, (char*)(0x00633E0C), (char*)(0x006338DC) },
	{ 1632, (char*)(0x00633FC0), (char*)(0x006338DC) },
	{ 1633, (char*)(0x00633DE4), (char*)(0x006338DC) },
	{ 1634, (char*)(0x00633DBC), (char*)(0x006338DC) },
	{ 1635, (char*)(0x00633F70), (char*)(0x006338DC) },
	{ 1636, (char*)(0x00633D90), (char*)(0x006338DC) },
	{ 1637, (char*)(0x00633D64), (char*)(0x006338DC) },
	{ 1638, (char*)(0x00633D38), (char*)(0x006338DC) },
	{ 1639, (char*)(0x00633F4C), (char*)(0x006338DC) },
	{ 1640, (char*)(0x00633F28), (char*)(0x006338DC) },
	{ 1641, (char*)(0x006342FC), (char*)(0x006338AC) },
	{ 1642, (char*)(0x006342C4), (char*)(0x006338AC) },
	{ 1643, (char*)(0x006342A0), (char*)(0x006338AC) },
	{ 1644, (char*)(0x0063427C), (char*)(0x006338AC) },
	{ 1645, (char*)(0x00634258), (char*)(0x006338AC) },
	{ 1646, (char*)(0x00634234), (char*)(0x006338AC) },
	{ 1647, (char*)(0x00634210), (char*)(0x006338AC) },
	{ 1648, (char*)(0x006341EC), (char*)(0x006338AC) },
	{ 1649, (char*)(0x006341C8), (char*)(0x006338AC) },
	{ 1650, (char*)(0x006341A4), (char*)(0x006338AC) },
	{ 1651, (char*)(0x00634180), (char*)(0x006338AC) },
	{ 1652, (char*)(0x00634154), (char*)(0x006338AC) },
	{ 1653, (char*)(0x00634128), (char*)(0x006338AC) },
	{ 1654, (char*)(0x00634108), (char*)(0x006338AC) },
	{ 1655, (char*)(0x006340E8), (char*)(0x006338AC) },
	{ 1656, (char*)(0x006340C8), (char*)(0x006338AC) },
	{ 1657, (char*)(0x006340A8), (char*)(0x006338AC) },
	{ 1658, (char*)(0x00634088), (char*)(0x006338AC) },
	{ 1659, (char*)(0x00634060), (char*)(0x006338AC) },
	{ 1660, (char*)(0x00634038), (char*)(0x006338AC) },
	{ 1661, (char*)(0x00634010), (char*)(0x006338AC) },
	{ 1662, (char*)(0x00633FE8), (char*)(0x006338AC) },
	{ 1663, (char*)(0x00633CF4), (char*)(0x006338AC) },
	{ 1664, (char*)(0x00633F98), (char*)(0x006338AC) },
	{ 1665, (char*)(0x00633CD0), (char*)(0x006338AC) },
	{ 1666, (char*)(0x00633CAC), (char*)(0x006338AC) },
	{ 1667, (char*)(0x00633C88), (char*)(0x006338AC) },
	{ 1668, (char*)(0x00633EFC), (char*)(0x006338AC) },
	{ 1669, (char*)(0x00633ED0), (char*)(0x006338AC) },
	{ 1670, (char*)(0x00633EA4), (char*)(0x006338AC) },
	{ 1671, (char*)(0x00633E80), (char*)(0x006338AC) },
	{ 1672, (char*)(0x00633E5C), (char*)(0x006338AC) },
	{ 1673, (char*)(0x00633E34), (char*)(0x006338AC) },
	{ 1674, (char*)(0x00633E0C), (char*)(0x006338AC) },
	{ 1675, (char*)(0x00633FC0), (char*)(0x006338AC) },
	{ 1676, (char*)(0x00633DE4), (char*)(0x006338AC) },
	{ 1677, (char*)(0x00633DBC), (char*)(0x006338AC) },
	{ 1678, (char*)(0x00633F70), (char*)(0x006338AC) },
	{ 1679, (char*)(0x00633D90), (char*)(0x006338AC) },
	{ 1680, (char*)(0x00633D64), (char*)(0x006338AC) },
	{ 1681, (char*)(0x00633D38), (char*)(0x006338AC) },
	{ 1682, (char*)(0x00633F4C), (char*)(0x006338AC) },
	{ 1683, (char*)(0x00633F28), (char*)(0x006338AC) },
	{ 1684, (char*)(0x006342FC), (char*)(0x0063387C) },
	{ 1685, (char*)(0x006342C4), (char*)(0x0063387C) },
	{ 1686, (char*)(0x006342A0), (char*)(0x0063387C) },
	{ 1687, (char*)(0x0063427C), (char*)(0x0063387C) },
	{ 1688, (char*)(0x00634258), (char*)(0x0063387C) },
	{ 1689, (char*)(0x00634234), (char*)(0x0063387C) },
	{ 1690, (char*)(0x00634210), (char*)(0x0063387C) },
	{ 1691, (char*)(0x006341EC), (char*)(0x0063387C) },
	{ 1692, (char*)(0x006341C8), (char*)(0x0063387C) },
	{ 1693, (char*)(0x006341A4), (char*)(0x0063387C) },
	{ 1694, (char*)(0x00634180), (char*)(0x0063387C) },
	{ 1695, (char*)(0x00634154), (char*)(0x0063387C) },
	{ 1696, (char*)(0x00634128), (char*)(0x0063387C) },
	{ 1697, (char*)(0x00634108), (char*)(0x0063387C) },
	{ 1698, (char*)(0x006340E8), (char*)(0x0063387C) },
	{ 1699, (char*)(0x006340C8), (char*)(0x0063387C) },
	{ 1700, (char*)(0x006340A8), (char*)(0x0063387C) },
	{ 1701, (char*)(0x00634088), (char*)(0x0063387C) },
	{ 1702, (char*)(0x00634060), (char*)(0x0063387C) },
	{ 1703, (char*)(0x00634038), (char*)(0x0063387C) },
	{ 1704, (char*)(0x00634010), (char*)(0x0063387C) },
	{ 1705, (char*)(0x00633FE8), (char*)(0x0063387C) },
	{ 1706, (char*)(0x00633CF4), (char*)(0x0063387C) },
	{ 1707, (char*)(0x00633F98), (char*)(0x0063387C) },
	{ 1708, (char*)(0x00633CD0), (char*)(0x0063387C) },
	{ 1709, (char*)(0x00633CAC), (char*)(0x0063387C) },
	{ 1710, (char*)(0x00633C88), (char*)(0x0063387C) },
	{ 1711, (char*)(0x00633EFC), (char*)(0x0063387C) },
	{ 1712, (char*)(0x00633ED0), (char*)(0x0063387C) },
	{ 1713, (char*)(0x00633EA4), (char*)(0x0063387C) },
	{ 1714, (char*)(0x00633E80), (char*)(0x0063387C) },
	{ 1715, (char*)(0x00633E5C), (char*)(0x0063387C) },
	{ 1716, (char*)(0x00633E34), (char*)(0x0063387C) },
	{ 1717, (char*)(0x00633E0C), (char*)(0x0063387C) },
	{ 1718, (char*)(0x00633FC0), (char*)(0x0063387C) },
	{ 1719, (char*)(0x00633DE4), (char*)(0x0063387C) },
	{ 1720, (char*)(0x00633DBC), (char*)(0x0063387C) },
	{ 1721, (char*)(0x00633F70), (char*)(0x0063387C) },
	{ 1722, (char*)(0x00633D90), (char*)(0x0063387C) },
	{ 1723, (char*)(0x00633D64), (char*)(0x0063387C) },
	{ 1724, (char*)(0x00633D38), (char*)(0x0063387C) },
	{ 1725, (char*)(0x00633F4C), (char*)(0x0063387C) },
	{ 1726, (char*)(0x00633F28), (char*)(0x0063387C) },
	{ 1727, (char*)(0x006342FC), (char*)(0x00633860) },
	{ 1728, (char*)(0x006342C4), (char*)(0x00633860) },
	{ 1729, (char*)(0x006342A0), (char*)(0x00633860) },
	{ 1730, (char*)(0x0063427C), (char*)(0x00633860) },
	{ 1731, (char*)(0x00634258), (char*)(0x00633860) },
	{ 1732, (char*)(0x00634234), (char*)(0x00633860) },
	{ 1733, (char*)(0x00634210), (char*)(0x00633860) },
	{ 1734, (char*)(0x006341EC), (char*)(0x00633860) },
	{ 1735, (char*)(0x006341C8), (char*)(0x00633860) },
	{ 1736, (char*)(0x006341A4), (char*)(0x00633860) },
	{ 1737, (char*)(0x00634180), (char*)(0x00633860) },
	{ 1738, (char*)(0x00634154), (char*)(0x00633860) },
	{ 1739, (char*)(0x00634128), (char*)(0x00633860) },
	{ 1740, (char*)(0x00634108), (char*)(0x00633860) },
	{ 1741, (char*)(0x006340E8), (char*)(0x00633860) },
	{ 1742, (char*)(0x006340C8), (char*)(0x00633860) },
	{ 1743, (char*)(0x006340A8), (char*)(0x00633860) },
	{ 1744, (char*)(0x00634088), (char*)(0x00633860) },
	{ 1745, (char*)(0x00634060), (char*)(0x00633860) },
	{ 1746, (char*)(0x00634038), (char*)(0x00633860) },
	{ 1747, (char*)(0x00634010), (char*)(0x00633860) },
	{ 1748, (char*)(0x00633FE8), (char*)(0x00633860) },
	{ 1749, (char*)(0x00633CF4), (char*)(0x00633860) },
	{ 1750, (char*)(0x00633F98), (char*)(0x00633860) },
	{ 1751, (char*)(0x00633CD0), (char*)(0x00633860) },
	{ 1752, (char*)(0x00633CAC), (char*)(0x00633860) },
	{ 1753, (char*)(0x00633C88), (char*)(0x00633860) },
	{ 1754, (char*)(0x00633EFC), (char*)(0x00633860) },
	{ 1755, (char*)(0x00633ED0), (char*)(0x00633860) },
	{ 1756, (char*)(0x00633EA4), (char*)(0x00633860) },
	{ 1757, (char*)(0x00633E80), (char*)(0x00633860) },
	{ 1758, (char*)(0x00633E5C), (char*)(0x00633860) },
	{ 1759, (char*)(0x00633E34), (char*)(0x00633860) },
	{ 1760, (char*)(0x00633E0C), (char*)(0x00633860) },
	{ 1761, (char*)(0x00633FC0), (char*)(0x00633860) },
	{ 1762, (char*)(0x00633DE4), (char*)(0x00633860) },
	{ 1763, (char*)(0x00633DBC), (char*)(0x00633860) },
	{ 1764, (char*)(0x00633F70), (char*)(0x00633860) },
	{ 1765, (char*)(0x00633D90), (char*)(0x00633860) },
	{ 1766, (char*)(0x00633D64), (char*)(0x00633860) },
	{ 1767, (char*)(0x00633D38), (char*)(0x00633860) },
	{ 1768, (char*)(0x00633F4C), (char*)(0x00633860) },
	{ 1769, (char*)(0x00633F28), (char*)(0x00633860) },
	{ 1770, (char*)(0x006342FC), (char*)(0x00633844) },
	{ 1771, (char*)(0x006342C4), (char*)(0x00633844) },
	{ 1772, (char*)(0x006342A0), (char*)(0x00633844) },
	{ 1773, (char*)(0x0063427C), (char*)(0x00633844) },
	{ 1774, (char*)(0x00634258), (char*)(0x00633844) },
	{ 1775, (char*)(0x00634234), (char*)(0x00633844) },
	{ 1776, (char*)(0x00634210), (char*)(0x00633844) },
	{ 1777, (char*)(0x006341EC), (char*)(0x00633844) },
	{ 1778, (char*)(0x006341C8), (char*)(0x00633844) },
	{ 1779, (char*)(0x006341A4), (char*)(0x00633844) },
	{ 1780, (char*)(0x00634180), (char*)(0x00633844) },
	{ 1781, (char*)(0x00634154), (char*)(0x00633844) },
	{ 1782, (char*)(0x00634128), (char*)(0x00633844) },
	{ 1783, (char*)(0x00634108), (char*)(0x00633844) },
	{ 1784, (char*)(0x006340E8), (char*)(0x00633844) },
	{ 1785, (char*)(0x006340C8), (char*)(0x00633844) },
	{ 1786, (char*)(0x006340A8), (char*)(0x00633844) },
	{ 1787, (char*)(0x00634088), (char*)(0x00633844) },
	{ 1788, (char*)(0x00634060), (char*)(0x00633844) },
	{ 1789, (char*)(0x00634038), (char*)(0x00633844) },
	{ 1790, (char*)(0x00634010), (char*)(0x00633844) },
	{ 1791, (char*)(0x00633FE8), (char*)(0x00633844) },
	{ 1792, (char*)(0x00633CF4), (char*)(0x00633844) },
	{ 1793, (char*)(0x00633F98), (char*)(0x00633844) },
	{ 1794, (char*)(0x00633CD0), (char*)(0x00633844) },
	{ 1795, (char*)(0x00633CAC), (char*)(0x00633844) },
	{ 1796, (char*)(0x00633C88), (char*)(0x00633844) },
	{ 1797, (char*)(0x00633EFC), (char*)(0x00633844) },
	{ 1798, (char*)(0x00633ED0), (char*)(0x00633844) },
	{ 1799, (char*)(0x00633EA4), (char*)(0x00633844) },
	{ 1800, (char*)(0x00633E80), (char*)(0x00633844) },
	{ 1801, (char*)(0x00633E5C), (char*)(0x00633844) },
	{ 1802, (char*)(0x00633E34), (char*)(0x00633844) },
	{ 1803, (char*)(0x00633E0C), (char*)(0x00633844) },
	{ 1804, (char*)(0x00633FC0), (char*)(0x00633844) },
	{ 1805, (char*)(0x00633DE4), (char*)(0x00633844) },
	{ 1806, (char*)(0x00633DBC), (char*)(0x00633844) },
	{ 1807, (char*)(0x00633F70), (char*)(0x00633844) },
	{ 1808, (char*)(0x00633D90), (char*)(0x00633844) },
	{ 1809, (char*)(0x00633D64), (char*)(0x00633844) },
	{ 1810, (char*)(0x00633D38), (char*)(0x00633844) },
	{ 1811, (char*)(0x00633F4C), (char*)(0x00633844) },
	{ 1812, (char*)(0x00633F28), (char*)(0x00633844) },
	{ 1813, (char*)(0x006342FC), (char*)(0x00633828) },
	{ 1814, (char*)(0x006342C4), (char*)(0x00633828) },
	{ 1815, (char*)(0x006342A0), (char*)(0x00633828) },
	{ 1816, (char*)(0x0063427C), (char*)(0x00633828) },
	{ 1817, (char*)(0x00634258), (char*)(0x00633828) },
	{ 1818, (char*)(0x00634234), (char*)(0x00633828) },
	{ 1819, (char*)(0x00634210), (char*)(0x00633828) },
	{ 1820, (char*)(0x006341EC), (char*)(0x00633828) },
	{ 1821, (char*)(0x006341C8), (char*)(0x00633828) },
	{ 1822, (char*)(0x006341A4), (char*)(0x00633828) },
	{ 1823, (char*)(0x00634180), (char*)(0x00633828) },
	{ 1824, (char*)(0x00634154), (char*)(0x00633828) },
	{ 1825, (char*)(0x00634128), (char*)(0x00633828) },
	{ 1826, (char*)(0x00634108), (char*)(0x00633828) },
	{ 1827, (char*)(0x006340E8), (char*)(0x00633828) },
	{ 1828, (char*)(0x006340C8), (char*)(0x00633828) },
	{ 1829, (char*)(0x006340A8), (char*)(0x00633828) },
	{ 1830, (char*)(0x00634088), (char*)(0x00633828) },
	{ 1831, (char*)(0x00634060), (char*)(0x00633828) },
	{ 1832, (char*)(0x00634038), (char*)(0x00633828) },
	{ 1833, (char*)(0x00634010), (char*)(0x00633828) },
	{ 1834, (char*)(0x00633FE8), (char*)(0x00633828) },
	{ 1835, (char*)(0x00633CF4), (char*)(0x00633828) },
	{ 1836, (char*)(0x00633F98), (char*)(0x00633828) },
	{ 1837, (char*)(0x00633CD0), (char*)(0x00633828) },
	{ 1838, (char*)(0x00633CAC), (char*)(0x00633828) },
	{ 1839, (char*)(0x00633C88), (char*)(0x00633828) },
	{ 1840, (char*)(0x00633EFC), (char*)(0x00633828) },
	{ 1841, (char*)(0x00633ED0), (char*)(0x00633828) },
	{ 1842, (char*)(0x00633EA4), (char*)(0x00633828) },
	{ 1843, (char*)(0x00633E80), (char*)(0x00633828) },
	{ 1844, (char*)(0x00633E5C), (char*)(0x00633828) },
	{ 1845, (char*)(0x00633E34), (char*)(0x00633828) },
	{ 1846, (char*)(0x00633E0C), (char*)(0x00633828) },
	{ 1847, (char*)(0x00633FC0), (char*)(0x00633828) },
	{ 1848, (char*)(0x00633DE4), (char*)(0x00633828) },
	{ 1849, (char*)(0x00633DBC), (char*)(0x00633828) },
	{ 1850, (char*)(0x00633F70), (char*)(0x00633828) },
	{ 1851, (char*)(0x00633D90), (char*)(0x00633828) },
	{ 1852, (char*)(0x00633D64), (char*)(0x00633828) },
	{ 1853, (char*)(0x00633D38), (char*)(0x00633828) },
	{ 1854, (char*)(0x00633F4C), (char*)(0x00633828) },
	{ 1855, (char*)(0x00633F28), (char*)(0x00633828) },
	{ 1856, (char*)(0x006342FC), (char*)(0x00633804) },
	{ 1857, (char*)(0x006342C4), (char*)(0x00633804) },
	{ 1858, (char*)(0x006342A0), (char*)(0x00633804) },
	{ 1859, (char*)(0x0063427C), (char*)(0x00633804) },
	{ 1860, (char*)(0x00634258), (char*)(0x00633804) },
	{ 1861, (char*)(0x00634234), (char*)(0x00633804) },
	{ 1862, (char*)(0x00634210), (char*)(0x00633804) },
	{ 1863, (char*)(0x006341EC), (char*)(0x00633804) },
	{ 1864, (char*)(0x006341C8), (char*)(0x00633804) },
	{ 1865, (char*)(0x006341A4), (char*)(0x00633804) },
	{ 1866, (char*)(0x00634180), (char*)(0x00633804) },
	{ 1867, (char*)(0x00634154), (char*)(0x00633804) },
	{ 1868, (char*)(0x00634128), (char*)(0x00633804) },
	{ 1869, (char*)(0x00634108), (char*)(0x00633804) },
	{ 1870, (char*)(0x006340E8), (char*)(0x00633804) },
	{ 1871, (char*)(0x006340C8), (char*)(0x00633804) },
	{ 1872, (char*)(0x006340A8), (char*)(0x00633804) },
	{ 1873, (char*)(0x00634088), (char*)(0x00633804) },
	{ 1874, (char*)(0x00634060), (char*)(0x00633804) },
	{ 1875, (char*)(0x00634038), (char*)(0x00633804) },
	{ 1876, (char*)(0x00634010), (char*)(0x00633804) },
	{ 1877, (char*)(0x00633FE8), (char*)(0x00633804) },
	{ 1878, (char*)(0x00633CF4), (char*)(0x00633804) },
	{ 1879, (char*)(0x00633F98), (char*)(0x00633804) },
	{ 1880, (char*)(0x00633CD0), (char*)(0x00633804) },
	{ 1881, (char*)(0x00633CAC), (char*)(0x00633804) },
	{ 1882, (char*)(0x00633C88), (char*)(0x00633804) },
	{ 1883, (char*)(0x00633EFC), (char*)(0x00633804) },
	{ 1884, (char*)(0x00633ED0), (char*)(0x00633804) },
	{ 1885, (char*)(0x00633EA4), (char*)(0x00633804) },
	{ 1886, (char*)(0x00633E80), (char*)(0x00633804) },
	{ 1887, (char*)(0x00633E5C), (char*)(0x00633804) },
	{ 1888, (char*)(0x00633E34), (char*)(0x00633804) },
	{ 1889, (char*)(0x00633E0C), (char*)(0x00633804) },
	{ 1890, (char*)(0x00633FC0), (char*)(0x00633804) },
	{ 1891, (char*)(0x00633DE4), (char*)(0x00633804) },
	{ 1892, (char*)(0x00633DBC), (char*)(0x00633804) },
	{ 1893, (char*)(0x00633F70), (char*)(0x00633804) },
	{ 1894, (char*)(0x00633D90), (char*)(0x00633804) },
	{ 1895, (char*)(0x00633D64), (char*)(0x00633804) },
	{ 1896, (char*)(0x00633D38), (char*)(0x00633804) },
	{ 1897, (char*)(0x00633F4C), (char*)(0x00633804) },
	{ 1898, (char*)(0x00633F28), (char*)(0x00633804) },
	{ 1899, (char*)(0x006342FC), (char*)(0x006337EC) },
	{ 1900, (char*)(0x006342C4), (char*)(0x006337EC) },
	{ 1901, (char*)(0x006342A0), (char*)(0x006337EC) },
	{ 1902, (char*)(0x0063427C), (char*)(0x006337EC) },
	{ 1903, (char*)(0x00634258), (char*)(0x006337EC) },
	{ 1904, (char*)(0x00634234), (char*)(0x006337EC) },
	{ 1905, (char*)(0x00634210), (char*)(0x006337EC) },
	{ 1906, (char*)(0x006341EC), (char*)(0x006337EC) },
	{ 1907, (char*)(0x006341C8), (char*)(0x006337EC) },
	{ 1908, (char*)(0x006341A4), (char*)(0x006337EC) },
	{ 1909, (char*)(0x00634180), (char*)(0x006337EC) },
	{ 1910, (char*)(0x00634154), (char*)(0x006337EC) },
	{ 1911, (char*)(0x00634128), (char*)(0x006337EC) },
	{ 1912, (char*)(0x00634108), (char*)(0x006337EC) },
	{ 1913, (char*)(0x006340E8), (char*)(0x006337EC) },
	{ 1914, (char*)(0x006340C8), (char*)(0x006337EC) },
	{ 1915, (char*)(0x006340A8), (char*)(0x006337EC) },
	{ 1916, (char*)(0x00634088), (char*)(0x006337EC) },
	{ 1917, (char*)(0x00634060), (char*)(0x006337EC) },
	{ 1918, (char*)(0x00634038), (char*)(0x006337EC) },
	{ 1919, (char*)(0x00634010), (char*)(0x006337EC) },
	{ 1920, (char*)(0x00633FE8), (char*)(0x006337EC) },
	{ 1921, (char*)(0x00633CF4), (char*)(0x006337EC) },
	{ 1922, (char*)(0x00633F98), (char*)(0x006337EC) },
	{ 1923, (char*)(0x00633CD0), (char*)(0x006337EC) },
	{ 1924, (char*)(0x00633CAC), (char*)(0x006337EC) },
	{ 1925, (char*)(0x00633C88), (char*)(0x006337EC) },
	{ 1926, (char*)(0x00633EFC), (char*)(0x006337EC) },
	{ 1927, (char*)(0x00633ED0), (char*)(0x006337EC) },
	{ 1928, (char*)(0x00633EA4), (char*)(0x006337EC) },
	{ 1929, (char*)(0x00633E80), (char*)(0x006337EC) },
	{ 1930, (char*)(0x00633E5C), (char*)(0x006337EC) },
	{ 1931, (char*)(0x00633E34), (char*)(0x006337EC) },
	{ 1932, (char*)(0x00633E0C), (char*)(0x006337EC) },
	{ 1933, (char*)(0x00633FC0), (char*)(0x006337EC) },
	{ 1934, (char*)(0x00633DE4), (char*)(0x006337EC) },
	{ 1935, (char*)(0x00633DBC), (char*)(0x006337EC) },
	{ 1936, (char*)(0x00633F70), (char*)(0x006337EC) },
	{ 1937, (char*)(0x00633D90), (char*)(0x006337EC) },
	{ 1938, (char*)(0x00633D64), (char*)(0x006337EC) },
	{ 1939, (char*)(0x00633D38), (char*)(0x006337EC) },
	{ 1940, (char*)(0x00633F4C), (char*)(0x006337EC) },
	{ 1941, (char*)(0x00633F28), (char*)(0x006337EC) },
	{ 1942, (char*)(0x006342FC), (char*)(0x006337D4) },
	{ 1943, (char*)(0x006342C4), (char*)(0x006337D4) },
	{ 1944, (char*)(0x006342A0), (char*)(0x006337D4) },
	{ 1945, (char*)(0x0063427C), (char*)(0x006337D4) },
	{ 1946, (char*)(0x00634258), (char*)(0x006337D4) },
	{ 1947, (char*)(0x00634234), (char*)(0x006337D4) },
	{ 1948, (char*)(0x00634210), (char*)(0x006337D4) },
	{ 1949, (char*)(0x006341EC), (char*)(0x006337D4) },
	{ 1950, (char*)(0x006341C8), (char*)(0x006337D4) },
	{ 1951, (char*)(0x006341A4), (char*)(0x006337D4) },
	{ 1952, (char*)(0x00634180), (char*)(0x006337D4) },
	{ 1953, (char*)(0x00634154), (char*)(0x006337D4) },
	{ 1954, (char*)(0x00634128), (char*)(0x006337D4) },
	{ 1955, (char*)(0x00634108), (char*)(0x006337D4) },
	{ 1956, (char*)(0x006340E8), (char*)(0x006337D4) },
	{ 1957, (char*)(0x006340C8), (char*)(0x006337D4) },
	{ 1958, (char*)(0x006340A8), (char*)(0x006337D4) },
	{ 1959, (char*)(0x00634088), (char*)(0x006337D4) },
	{ 1960, (char*)(0x00634060), (char*)(0x006337D4) },
	{ 1961, (char*)(0x00634038), (char*)(0x006337D4) },
	{ 1962, (char*)(0x00634010), (char*)(0x006337D4) },
	{ 1963, (char*)(0x00633FE8), (char*)(0x006337D4) },
	{ 1964, (char*)(0x00633CF4), (char*)(0x006337D4) },
	{ 1965, (char*)(0x00633F98), (char*)(0x006337D4) },
	{ 1966, (char*)(0x00633CD0), (char*)(0x006337D4) },
	{ 1967, (char*)(0x00633CAC), (char*)(0x006337D4) },
	{ 1968, (char*)(0x00633C88), (char*)(0x006337D4) },
	{ 1969, (char*)(0x00633EFC), (char*)(0x006337D4) },
	{ 1970, (char*)(0x00633ED0), (char*)(0x006337D4) },
	{ 1971, (char*)(0x00633EA4), (char*)(0x006337D4) },
	{ 1972, (char*)(0x00633E80), (char*)(0x006337D4) },
	{ 1973, (char*)(0x00633E5C), (char*)(0x006337D4) },
	{ 1974, (char*)(0x00633E34), (char*)(0x006337D4) },
	{ 1975, (char*)(0x00633E0C), (char*)(0x006337D4) },
	{ 1976, (char*)(0x00633FC0), (char*)(0x006337D4) },
	{ 1977, (char*)(0x00633DE4), (char*)(0x006337D4) },
	{ 1978, (char*)(0x00633DBC), (char*)(0x006337D4) },
	{ 1979, (char*)(0x00633F70), (char*)(0x006337D4) },
	{ 1980, (char*)(0x00633D90), (char*)(0x006337D4) },
	{ 1981, (char*)(0x00633D64), (char*)(0x006337D4) },
	{ 1982, (char*)(0x00633D38), (char*)(0x006337D4) },
	{ 1983, (char*)(0x00633F4C), (char*)(0x006337D4) },
	{ 1984, (char*)(0x00633F28), (char*)(0x006337D4) },
	{ 1985, (char*)(0x006342FC), (char*)(0x006337BC) },
	{ 1986, (char*)(0x006342C4), (char*)(0x006337BC) },
	{ 1987, (char*)(0x006342A0), (char*)(0x006337BC) },
	{ 1988, (char*)(0x0063427C), (char*)(0x006337BC) },
	{ 1989, (char*)(0x00634258), (char*)(0x006337BC) },
	{ 1990, (char*)(0x00634234), (char*)(0x006337BC) },
	{ 1991, (char*)(0x00634210), (char*)(0x006337BC) },
	{ 1992, (char*)(0x006341EC), (char*)(0x006337BC) },
	{ 1993, (char*)(0x006341C8), (char*)(0x006337BC) },
	{ 1994, (char*)(0x006341A4), (char*)(0x006337BC) },
	{ 1995, (char*)(0x00634180), (char*)(0x006337BC) },
	{ 1996, (char*)(0x00634154), (char*)(0x006337BC) },
	{ 1997, (char*)(0x00634128), (char*)(0x006337BC) },
	{ 1998, (char*)(0x00634108), (char*)(0x006337BC) },
	{ 1999, (char*)(0x006340E8), (char*)(0x006337BC) },
	{ 2000, (char*)(0x006340C8), (char*)(0x006337BC) },
	{ 2001, (char*)(0x006340A8), (char*)(0x006337BC) },
	{ 2002, (char*)(0x00634088), (char*)(0x006337BC) },
	{ 2003, (char*)(0x00634060), (char*)(0x006337BC) },
	{ 2004, (char*)(0x00634038), (char*)(0x006337BC) },
	{ 2005, (char*)(0x00634010), (char*)(0x006337BC) },
	{ 2006, (char*)(0x00633FE8), (char*)(0x006337BC) },
	{ 2007, (char*)(0x00633CF4), (char*)(0x006337BC) },
	{ 2008, (char*)(0x00633F98), (char*)(0x006337BC) },
	{ 2009, (char*)(0x00633CD0), (char*)(0x006337BC) },
	{ 2010, (char*)(0x00633CAC), (char*)(0x006337BC) },
	{ 2011, (char*)(0x00633C88), (char*)(0x006337BC) },
	{ 2012, (char*)(0x00633EFC), (char*)(0x006337BC) },
	{ 2013, (char*)(0x00633ED0), (char*)(0x006337BC) },
	{ 2014, (char*)(0x00633EA4), (char*)(0x006337BC) },
	{ 2015, (char*)(0x00633E80), (char*)(0x006337BC) },
	{ 2016, (char*)(0x00633E5C), (char*)(0x006337BC) },
	{ 2017, (char*)(0x00633E34), (char*)(0x006337BC) },
	{ 2018, (char*)(0x00633E0C), (char*)(0x006337BC) },
	{ 2019, (char*)(0x00633FC0), (char*)(0x006337BC) },
	{ 2020, (char*)(0x00633DE4), (char*)(0x006337BC) },
	{ 2021, (char*)(0x00633DBC), (char*)(0x006337BC) },
	{ 2022, (char*)(0x00633F70), (char*)(0x006337BC) },
	{ 2023, (char*)(0x00633D90), (char*)(0x006337BC) },
	{ 2024, (char*)(0x00633D64), (char*)(0x006337BC) },
	{ 2025, (char*)(0x00633D38), (char*)(0x006337BC) },
	{ 2026, (char*)(0x00633F4C), (char*)(0x006337BC) },
	{ 2027, (char*)(0x00633F28), (char*)(0x006337BC) },
	{ 2028, (char*)(0x006342FC), (char*)(0x00633798) },
	{ 2029, (char*)(0x006342C4), (char*)(0x00633798) },
	{ 2030, (char*)(0x006342A0), (char*)(0x00633798) },
	{ 2031, (char*)(0x0063427C), (char*)(0x00633798) },
	{ 2032, (char*)(0x00634258), (char*)(0x00633798) },
	{ 2033, (char*)(0x00634234), (char*)(0x00633798) },
	{ 2034, (char*)(0x00634210), (char*)(0x00633798) },
	{ 2035, (char*)(0x006341EC), (char*)(0x00633798) },
	{ 2036, (char*)(0x006341C8), (char*)(0x00633798) },
	{ 2037, (char*)(0x006341A4), (char*)(0x00633798) },
	{ 2038, (char*)(0x00634180), (char*)(0x00633798) },
	{ 2039, (char*)(0x00634154), (char*)(0x00633798) },
	{ 2040, (char*)(0x00634128), (char*)(0x00633798) },
	{ 2041, (char*)(0x00634108), (char*)(0x00633798) },
	{ 2042, (char*)(0x006340E8), (char*)(0x00633798) },
	{ 2043, (char*)(0x006340C8), (char*)(0x00633798) },
	{ 2044, (char*)(0x006340A8), (char*)(0x00633798) },
	{ 2045, (char*)(0x00634088), (char*)(0x00633798) },
	{ 2046, (char*)(0x00634060), (char*)(0x00633798) },
	{ 2047, (char*)(0x00634038), (char*)(0x00633798) },
	{ 2048, (char*)(0x00634010), (char*)(0x00633798) },
	{ 2049, (char*)(0x00633FE8), (char*)(0x00633798) },
	{ 2050, (char*)(0x00633CF4), (char*)(0x00633798) },
	{ 2051, (char*)(0x00633F98), (char*)(0x00633798) },
	{ 2052, (char*)(0x00633CD0), (char*)(0x00633798) },
	{ 2053, (char*)(0x00633CAC), (char*)(0x00633798) },
	{ 2054, (char*)(0x00633C88), (char*)(0x00633798) },
	{ 2055, (char*)(0x00633EFC), (char*)(0x00633798) },
	{ 2056, (char*)(0x00633ED0), (char*)(0x00633798) },
	{ 2057, (char*)(0x00633EA4), (char*)(0x00633798) },
	{ 2058, (char*)(0x00633E80), (char*)(0x00633798) },
	{ 2059, (char*)(0x00633E5C), (char*)(0x00633798) },
	{ 2060, (char*)(0x00633E34), (char*)(0x00633798) },
	{ 2061, (char*)(0x00633E0C), (char*)(0x00633798) },
	{ 2062, (char*)(0x00633FC0), (char*)(0x00633798) },
	{ 2063, (char*)(0x00633DE4), (char*)(0x00633798) },
	{ 2064, (char*)(0x00633DBC), (char*)(0x00633798) },
	{ 2065, (char*)(0x00633F70), (char*)(0x00633798) },
	{ 2066, (char*)(0x00633D90), (char*)(0x00633798) },
	{ 2067, (char*)(0x00633D64), (char*)(0x00633798) },
	{ 2068, (char*)(0x00633D38), (char*)(0x00633798) },
	{ 2069, (char*)(0x00633F4C), (char*)(0x00633798) },
	{ 2070, (char*)(0x00633F28), (char*)(0x00633798) },
	{ 2071, (char*)(0x00637708), (char*)(0x006376E8) },
	{ 2072, (char*)(0x006376DC), (char*)(0x006376E8) },
	{ 2073, (char*)(0x006376D0), (char*)(0x006376E8) },
	{ 2074, (char*)(0x006376C4), (char*)(0x006376E8) },
	{ 2075, (char*)(0x006376B8), (char*)(0x006376E8) },
	{ 2076, (char*)(0x006376AC), (char*)(0x006376E8) },
	{ 2077, (char*)(0x0063769C), (char*)(0x00637670) },
	{ 2078, (char*)(0x00637660), (char*)(0x00637670) },
	{ 2079, (char*)(0x00637650), (char*)(0x00637670) },
	{ 2080, (char*)(0x00637640), (char*)(0x00637670) },
	{ 2081, (char*)(0x00637630), (char*)(0x00637670) },
	{ 2082, (char*)(0x00637620), (char*)(0x00637670) },
	{ 2085, (char*)(0x00637604), (char*)(0x006375DC) },
	{ 2086, (char*)(0x006375C0), (char*)(0x00637594) },
	{ 2087, (char*)(0x00637578), (char*)(0x00637548) },
	{ 2088, (char*)(0x00637530), (char*)(0x00637508) },
	{ 2089, (char*)(0x006374F0), (char*)(0x006374C4) },
	{ 2090, (char*)(0x006374A8), (char*)(0x0063747C) },
	{ 2091, (char*)(0x00637464), (char*)(0x00637434) },
	{ 2092, (char*)(0x0063741C), (char*)(0x006373E8) },
	{ 2093, (char*)(0x006373D4), (char*)(0x006373A8) },
	{ 2094, (char*)(0x00637394), (char*)(0x00637368) },
	{ 2095, (char*)(0x00637354), (char*)(0x00637328) },
	{ 2096, (char*)(0x00637310), (char*)(0x006372E0) },
	{ 2097, (char*)(0x006372C8), (char*)(0x00637290) },
	{ 2098, (char*)(0x00637274), (char*)(0x00637248) },
	{ 2099, (char*)(0x0063722C), (char*)(0x006371FC) },
	{ 2100, (char*)(0x006371E4), (char*)(0x006371B8) },
	{ 2101, (char*)(0x006371A0), (char*)(0x00637174) },
	{ 2102, (char*)(0x00637158), (char*)(0x00637124) },
	{ 2103, (char*)(0x00637108), (char*)(0x006370D8) },
	{ 2104, (char*)(0x006370C0), (char*)(0x00637098) },
	{ 2105, (char*)(0x00637080), (char*)(0x00637048) },
	{ 2106, (char*)(0x00637030), (char*)(0x00637004) },
	{ 2107, (char*)(0x00636FEC), (char*)(0x00636FBC) },
	{ 2108, (char*)(0x00636FA0), (char*)(0x00636F6C) },
	{ 2109, (char*)(0x00636F44), (char*)(0x00636F28) },
	{ 2110, (char*)(0x00636EFC), (char*)(0x00636ED8) },
	{ 2111, (char*)(0x00636EAC), (char*)(0x00636E88) },
	{ 2112, (char*)(0x00636E64), (char*)(0x00636E44) },
	{ 2113, (char*)(0x00636E20), (char*)(0x00636E00) },
	{ 2114, (char*)(0x00636DDC), (char*)(0x00636DB8) },
	{ 2115, (char*)(0x00636D90), (char*)(0x00636D68) },
	{ 2116, (char*)(0x00636D40), (char*)(0x00636D18) },
	{ 2117, (char*)(0x00636CEC), (char*)(0x00636CB0) },
	{ 2159, (char*)(0x00636CA8), (char*)(0x00636C70) },
	{ 2160, (char*)(0x00636CA8), (char*)(0x00636C38) },
	{ 2161, (char*)(0x00636CA8), (char*)(0x00636C00) },
	{ 2162, (char*)(0x00636CA8), (char*)(0x00636BC8) },
	{ 2163, (char*)(0x00636CA8), (char*)(0x00636B8C) },
	{ 2164, (char*)(0x00636CA8), (char*)(0x00636B50) },
	{ 2165, (char*)(0x00636CA8), (char*)(0x00636B14) },
	{ 2169, (char*)(0x00636B0C), (char*)(0x00636ABC) },
	{ 2170, (char*)(0x00636AB0), (char*)(0x00636A60) },
	{ 2219, (char*)(0x00636A50), (char*)(0x00636A10) },
	{ 2220, (char*)(0x00636A00), (char*)(0x006369C0) },
	{ 2221, (char*)(0x006369B0), (char*)(0x00636970) },
	{ 2222, (char*)(0x00636960), (char*)(0x00636920) },
	{ 2223, (char*)(0x00636910), (char*)(0x006368D0) },
	{ 2269, (char*)(0x006368C4), (char*)(0x00636894) },
	{ 2270, (char*)(0x00636884), (char*)(0x00636858) },
	//{ 2271, "Sign New",	    "New Signs from Tofuman" },
};

const char* CHAT_SEPARATOR = ": ";