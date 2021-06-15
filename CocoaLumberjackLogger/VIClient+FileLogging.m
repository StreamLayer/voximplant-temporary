/*
 *  Copyright (c) 2011-2021, Zingaya, Inc. All rights reserved.
 */

#import "VIClient+FileLogging.h"

#import <CocoaLumberjack/CocoaLumberjack.h>

@interface VILumberjackBridge : NSObject <VILogDelegate>
@end

@implementation VILumberjackBridge

+ (instancetype)instance {
    static VILumberjackBridge *instance;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        instance = [[VILumberjackBridge alloc] init];
    });
    return instance;
}

- (void)didReceiveLogMessage:(NSString *)logMessage severity:(VILogSeverity)severity {
    [DDLog log:severity != VILogSeverityError
         level:(DDLogLevel) VILogLevelVerbose
          flag:(DDLogFlag) severity
       context:0
          file:""
      function:""
          line:0
           tag:nil
        format:@"%@", logMessage];
}

@end

@implementation VIClient (FileLogging)

+ (void)writeLogsToFile {
    DDFileLogger *fileLogger = [[DDFileLogger alloc] init]; // File Logger
    fileLogger.maximumFileSize = 1024 * 1024 * 4; // 4 MiB
    fileLogger.rollingFrequency = 60 * 60 * 24; // 24 hour rolling
    fileLogger.logFileManager.maximumNumberOfLogFiles = 7;

    [VIClient writeLogsToFileLogger:fileLogger];
}

+ (void)writeLogsToFileLogger:(DDFileLogger *)fileLogger {
    [DDLog addLogger:fileLogger withLevel:(DDLogLevel) VILogLevelVerbose];

    [VIClient setLogDelegate:VILumberjackBridge.instance];
}

@end

