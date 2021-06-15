/*
 *  Copyright (c) 2011-2021, Zingaya, Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class VIEndpoint;
@class VIRemoteAudioStream;
@class VIRemoteVideoStream;
@class VICall;
@class VIEndpointStat;

NS_ASSUME_NONNULL_BEGIN

/**
 * Delegate that may be used to handle endpoint events.
 *
 * @namespace call
 */
@protocol VIEndpointDelegate <NSObject>

@optional

/**
 * Triggered after endpoint added video stream to the call.
 *
 * Triggered always on the main thread, even delegateQueue (set in <[VIClient initWithDelegateQueue:]>) is not the main thread.
 *
 * @param endpoint    Endpoint that triggered this event.
 * @param videoStream Remote video stream added to the call.
 */
- (void)endpoint:(VIEndpoint *)endpoint didAddRemoteVideoStream:(VIRemoteVideoStream *)videoStream
NS_SWIFT_NAME(endpoint(_:didAddRemoteVideoStream:));

/**
 * Triggered after endpoint removed video stream from the call.
 *
 * Triggered always on the main thread, even delegateQueue (set in <[VIClient initWithDelegateQueue:]>) is not the main thread.
 *
 * @param endpoint    Endpoint that triggered this event.
 * @param videoStream Remote video stream removed from the call.
 */
- (void)endpoint:(VIEndpoint *)endpoint didRemoveRemoteVideoStream:(VIRemoteVideoStream *)videoStream
NS_SWIFT_NAME(endpoint(_:didRemoveRemoteVideoStream:));


/**
 * Invoked when endpoint information such as display name, user name and sip uri is updated.
 *
 * @param endpoint Endpoint which information is updated.
 */
- (void)endpointInfoDidUpdate:(VIEndpoint *)endpoint;

/**
 * Invoked after endpoint is removed from the call. Event is not triggered on call end.
 *
 * @param endpoint Removed endpoint.
 */
- (void)endpointDidRemove:(VIEndpoint *)endpoint;

@end

/**
 * VIEndpoint
 *
 * @namespace call
 */
@interface VIEndpoint : NSObject

/**
 * A delegate to handle the endpoint events.
 */
@property(nonatomic, weak, nullable) id <VIEndpointDelegate> delegate;


/**
 * The call associated with the endpoint.
 */
@property(nonatomic, weak, nullable, readonly) VICall *call;

/**
 * The active audio streams associated with the endpoint
 */
@property(nonatomic, strong, readonly) NSArray<VIRemoteAudioStream *> *remoteAudioStreams;

/**
 * The active video streams associated with the endpoint.
 */
@property(nonatomic, strong, readonly) NSArray<VIRemoteVideoStream *> *remoteVideoStreams;

/**
 * The endpoint id.
 */
@property(nonatomic, strong, readonly) NSString *endpointId;

/**
 * A user name of the endpoint.
 */
@property(nonatomic, strong, readonly, nullable) NSString *user;

/**
 * The SIP URI of the endpoint.
 */
@property(nonatomic, strong, readonly, nullable) NSString *sipURI;

/**
 * A user display name of the endpoint.
 */
@property(nonatomic, strong, readonly, nullable) NSString *userDisplayName;

/**
 * Place of this endpoint in a video conference.
 *
 * May be used as a position of this endpoint's video stream to render in a video conference call.
 *
 * Nil for audio and video calls.
 */
@property(nonatomic, strong, readonly, nullable) NSNumber *place;

@end

NS_ASSUME_NONNULL_END
