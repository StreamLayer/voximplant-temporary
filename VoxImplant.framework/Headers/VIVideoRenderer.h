/*
 *  Copyright (c) 2011-2021, Zingaya, Inc. All rights reserved.
 */

#import <WebRTC/WebRTC.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Delegate that may be used to handle renderer events.
 *
 * @namespace hardware
 */
@protocol VIVideoRenderer <RTCVideoRenderer>

@optional
/**
 * Triggered when the video renderer is started.
 */
- (void)didStart;

/**
 * Triggered when the video renderer is stopped.
 */
- (void)didStop;

@end

NS_ASSUME_NONNULL_END
