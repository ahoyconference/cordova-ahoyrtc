//
//  AhoySDK.h
//  AhoySDK
//
//  Created by kapejod on 06.02.15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface AhoySDK : NSObject

+ (id)sharedInstance;
+ (void)destroy;
+ (BOOL)isDeviceVideoCapable;
+ (BOOL)isDeviceHdVideoCapable;
+ (BOOL)isVideoCaptureAvailable;

- (void)setApiKey:(NSString *)apiKey apiUrl:(NSString *)apiUrl;
- (void)setApnToken:(NSString *)token;
- (void)setPushKitToken:(NSString *)token;
- (void)initializeWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (NSDictionary *)getSettings;
- (NSDictionary *)setSettings:(NSDictionary *)settings;
- (NSDictionary *)uiColors;
- (UIColor *)uiColor:(NSString *)name or:(unsigned int)hex;

- (void)didReceivePushNotification:(NSDictionary *)notification;
- (void)didReceiveLocalNotification:(NSDictionary *)notification;

- (void)loginWithEmail:(NSString *)email password:(NSString *)password callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)logoutWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getContactListWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getConferenceListWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getConferenceInfo:(NSString *)uuid callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)joinConference:(NSString *)uuid presentingViewController:(UIViewController *)viewController callback:(void(^)(BOOL, NSDictionary *))callback;
- (void)joinConferenceRoom:(NSString *)roomName name:(NSString *)name password:(NSString *)password at:(NSString *)wsUrl presentingViewController:(UIViewController *)viewController callback:(void (^)(BOOL, NSDictionary *))callback;

- (BOOL)isSpeakerEnabled;
- (BOOL)isHeadphonesEnabled;
- (BOOL)isBluetoothEnabled;
@end
