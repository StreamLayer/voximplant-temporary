/*
 *  Copyright (c) 2011-2020, Zingaya, Inc. All rights reserved.
 */

#import <AVFoundation/AVFoundation.h>
#import <Foundation/Foundation.h>

#import <WebRTC/RTCMacros.h>
#import <WebRTC/RTCVideoCapturer.h>

NS_ASSUME_NONNULL_BEGIN

RTC_OBJC_EXPORT
// InApp screen capture that implements RTCVideoCapturer. Delivers frames to a RTCVideoCapturerDelegate
// (usually RTCVideoSource).
NS_EXTENSION_UNAVAILABLE_IOS("InApp screen capture not available in app extensions.")
NS_CLASS_AVAILABLE_IOS(11)
@interface RTCScreenVideoCapturer : RTCVideoCapturer

@property(nonatomic, strong) VideoPreProcessBlock videoPreProcessBlock;

// Starts the capture session asynchronously and notifies callback on completion.
- (void)startCaptureWithCompletionHandler:(nullable void (^)(NSError *))completionHandler;

// Stops the capture session asynchronously and notifies callback on completion.
- (void)stopCaptureWithCompletionHandler:(nullable void (^)(void))completionHandler;

@end

NS_ASSUME_NONNULL_END
