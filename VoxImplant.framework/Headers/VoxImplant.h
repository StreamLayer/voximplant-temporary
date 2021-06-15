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

#import <VoxImplant/VIClient.h>
#import <VoxImplant/VICall.h>
#import <VoxImplant/VIEndpoint.h>
#import <VoxImplant/VIAudioManager.h>
#import <VoxImplant/VIAudioStream.h>
#import <VoxImplant/VIVideoSource.h>
#import <VoxImplant/VICameraManager.h>
#import <VoxImplant/VIVideoRenderer.h>
#import <VoxImplant/VIVideoRendererView.h>
#import <VoxImplant/VIVideoStream.h>
#import <VoxImplant/VICallStats.h>
#import <VoxImplant/VIOutboundAudioStats.h>
#import <VoxImplant/VIOutboundVideoStats.h>
#import <VoxImplant/VIVideoStreamLayerStats.h>
#import <VoxImplant/VIEndpointStats.h>
#import <VoxImplant/VIInboundAudioStats.h>
#import <VoxImplant/VIInboundVideoStats.h>
#import <VoxImplant/VICallSettings.h>
#import <VoxImplant/VIVideoFlags.h>
#import <VoxImplant/VIQualityIssueDelegate.h>
#import <VoxImplant/VIError.h>
#import <VoxImplant/VIAuthParams.h>
#import <VoxImplant/VIAudioFile.h>
#import <VoxImplant/VILocalAudioStream.h>
#import <VoxImplant/VIRemoteAudioStream.h>
#import <VoxImplant/VILocalVideoStream.h>
#import <VoxImplant/VIRemoteVideoStream.h>

// Messenger
#import <VoxImplant/VIConversation.h>
#import <VoxImplant/VIConversationConfig.h>
#import <VoxImplant/VIConversationEvent.h>
#import <VoxImplant/VIConversationListEvent.h>
#import <VoxImplant/VIConversationParticipant.h>
#import <VoxImplant/VIConversationServiceEvent.h>
#import <VoxImplant/VIErrorEvent.h>
#import <VoxImplant/VIMessage.h>
#import <VoxImplant/VIMessageEvent.h>
#import <VoxImplant/VIMessenger.h>
#import <VoxImplant/VIMessengerCompletion.h>
#import <VoxImplant/VIMessengerEvent.h>
#import <VoxImplant/VIMessengerPushNotificationProcessing.h>
#import <VoxImplant/VIRetransmitEvent.h>
#import <VoxImplant/VIStatusEvent.h>
#import <VoxImplant/VISubscriptionEvent.h>
#import <VoxImplant/VIUser.h>
#import <VoxImplant/VIUserEvent.h>

FOUNDATION_EXPORT double VoxImplantVersionNumber;
FOUNDATION_EXPORT const unsigned char VoxImplantVersionString[];
