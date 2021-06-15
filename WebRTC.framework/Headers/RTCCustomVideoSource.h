/*
 *  Copyright (c) 2011-2019, Zingaya, Inc. All rights reserved.
 */

#import <WebRTC/RTCMacros.h>
#import <WebRTC/RTCVideoSource.h>

@class RTCPeerConnectionFactory;
@class RTCMediaConstraints;

// right now only NV12 supported

RTC_EXTERN uint32_t kFOURCC_I420;

RTC_OBJC_EXPORT
@interface RTCVideoFormat : NSObject

@property(nonatomic, assign, readonly) NSUInteger width;
@property(nonatomic, assign, readonly) NSUInteger height;
@property(nonatomic, assign, readonly) NSUInteger interval; // Nanoseconds = 1/FPS
@property(nonatomic, assign, readonly) uint32_t fourcc; // Nanoseconds = 1/FPS

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithWidth:(NSUInteger)width height:(NSUInteger)height interval:(NSUInteger)interval fourcc:(uint32_t)fourcc;

- (instancetype)initWithWidth:(NSUInteger)width height:(NSUInteger)height fps:(NSUInteger)fps fourcc:(uint32_t)fourcc;

@end

RTC_OBJC_EXPORT
@protocol RTCCustomVideoSourceDelegate <NSObject>

- (void)startWithVideoFormat:(RTCVideoFormat *)videoFormat;

- (void)stop;

@end

@class RTCVideoFrame;

RTC_OBJC_EXPORT
@interface RTCCustomVideoSource : RTCVideoSource

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithFactory:(RTCPeerConnectionFactory *)factory
                    constraints:(RTCMediaConstraints *)constraints
               supportedFormats:(NSArray<RTCVideoFormat *> *)supportedFormats
                       delegate:(id <RTCCustomVideoSourceDelegate>)delegate
                   isScreenCast:(BOOL)isScreenCast;

- (void)sendVideoFrame:(RTCVideoFrame *)videoFrame;

@end
