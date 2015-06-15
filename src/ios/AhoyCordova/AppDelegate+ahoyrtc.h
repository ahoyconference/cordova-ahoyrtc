//
//  AppDelegate+ahoy.h
//  AhoySDK
//
//  Created by kapejod on 14/06/15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate (ahoyrtc)
- (void)application:(UIApplication *)application handleActionWithIdentifier:(NSString *)identifier forLocalNotification:(UILocalNotification *)notification completionHandler:(void (^)())completionHandler;
@end
