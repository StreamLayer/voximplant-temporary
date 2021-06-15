/*
 *  Copyright (c) 2011-2021, Zingaya, Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <VoxImplant/VIClient.h>

@class DDFileLogger;

NS_ASSUME_NONNULL_BEGIN

@interface VIClient (FileLogging)

/**
 * Enable saving of the logs to file(s). Log files are located at: Library/Caches/Logs.
 *
 * Available via the [CocoaLumberjackLogger](https://voximplant.com/blog/ios-sdk-third-party-independence#cocoalumberjacklogger) subspec.
 */
+ (void)writeLogsToFile;

/**
 * Enable saving of the logs to the specified CocoaLumberjack file logger.
 *
 * Available via the [CocoaLumberjackLogger](https://voximplant.com/blog/ios-sdk-third-party-independence#cocoalumberjacklogger) subspec.
 *
 * @param fileLogger configured DDFileLogger instance
 */
+ (void)writeLogsToFileLogger:(DDFileLogger *)fileLogger NS_SWIFT_NAME(writeLogsToFileLogger(_:));

@end

NS_ASSUME_NONNULL_END
