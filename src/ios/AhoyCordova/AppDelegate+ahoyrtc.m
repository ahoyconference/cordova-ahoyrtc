//
//  AppDelegate+ahoy.m
//  AhoySDK
//
//  Created by kapejod on 14/06/15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AhoyKit/AhoyKit.h>
#import "AppDelegate+ahoyrtc.h"

@implementation AppDelegate (ahoyrtc)

- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forLocalNotification:(UILocalNotification *)notification completionHandler:(void (^)())completionHandler {
    NSDictionary *userInfo = [notification userInfo];
    NSString *uuid = nil;
    NSNumber *incoming = nil;
    if (userInfo) {
        NSDictionary *ahoy = [userInfo objectForKey:@"ahoy"];
        if (ahoy) {
            NSDictionary *session = [ahoy objectForKey:@"session"];
            if (session) {
                uuid = [session valueForKey:@"uuid"];
                incoming = [session objectForKey:@"incoming"];
            }
        }
    }

    if ([identifier isEqualToString:@"AHOY_ACTION_ANSWER"]) {
        if (uuid && incoming && [incoming boolValue]) {
            [[AhoySDK sharedInstance] answerIncomingCall:uuid withAudio:YES andVideo:YES callback:nil];
        }
    } else if ([identifier isEqualToString:@"AHOY_ACTION_REJECT"]) {
        if (uuid && incoming && [incoming boolValue]) {
            [[AhoySDK sharedInstance] rejectIncomingCall:uuid withReason:@"busy"];
        }
    }
    [[UIApplication sharedApplication] cancelLocalNotification: notification];

    if (completionHandler) {
        completionHandler();
    }
}

@end