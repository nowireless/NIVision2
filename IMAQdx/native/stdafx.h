// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>
#include <iostream>

// TODO: reference additional headers your program requires here
#include <NIIMAQdx.h>
#include "jni\org_nowireless_imaqdx_IMAQdx.h"
#include "jni\org_nowireless_imaqdx_IMAQdx_IMAQdxBusType.h"
#include "jni\org_nowireless_imaqdx_IMAQdx_IMAQdxCameraInformation.h"
#include "jni\org_nowireless_imaqdx_IMAQdx_IMAQdxCameraInformationArray.h"
#include "jni\org_nowireless_imaqdx_IMAQdx_IMAQdxException.h"