/*
 *  Copyright (c) 2011-2021, Zingaya, Inc. All rights reserved.
 */

#ifdef __OBJC__
#import <Foundation/Foundation.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#define VOXIMPLANT_SDK 1
#import <VoxImplant/VoxImplant.h>

#ifdef VOXIMPLANT_COCOALUMBERJACK
#import <VoxImplantSDK/VIClient+FileLogging.h>
#endif

FOUNDATION_EXPORT double VoxImplantSDKVersionNumber;
FOUNDATION_EXPORT const unsigned char VoxImplantSDKVersionString[];

