//
//  AhoySDK.h
//  AhoySDK
//
//  Created by kapejod on 06.02.15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AhoySipCall.h"

@interface AhoySDK : NSObject

typedef NS_ENUM(NSInteger, AhoyVideoFormat) {
    AhoyVideoFormat_352_288_30,
    AhoyVideoFormat_640_480_30,
    AhoyVideoFormat_1280_720_30
};

+ (id)sharedInstance;
+ (void)destroy;
+ (BOOL)isDeviceVideoCapable;
+ (BOOL)isDeviceHdVideoCapable;
+ (BOOL)isVideoCaptureAvailable;
+ (NSInteger)videoCaptureFormatForConferencing;
+ (NSInteger)videoCaptureFormatForCalling;

// generic
- (NSDictionary *)getSettings;
- (NSDictionary *)setSettings:(NSDictionary *)settings;
- (NSDictionary *)uiColors;
- (UIColor *)uiColor:(NSString *)name or:(unsigned int)hex;

- (BOOL)isSpeakerEnabled;
- (BOOL)isHeadphonesEnabled;
- (BOOL)isBluetoothEnabled;

// AhoyUC
- (void)setApiKey:(NSString *)apiKey apiUrl:(NSString *)apiUrl;
- (void)setApnToken:(NSString *)token;
- (void)setPushKitToken:(NSString *)token;
- (void)initializeWithCallback:(void (^)(BOOL, NSDictionary *))callback;

- (void)didReceivePushNotification:(NSDictionary *)notification;
- (void)loginWithEmail:(NSString *)email password:(NSString *)password callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)logoutWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getContactListWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getConferenceListWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getConferenceInfo:(NSString *)uuid callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)joinConference:(NSString *)uuid presentingViewController:(UIViewController *)viewController callback:(void(^)(BOOL, NSDictionary *))callback;

// AhoyConference
- (void)joinConferenceRoom:(NSString *)roomName name:(NSString *)name password:(NSString *)password at:(NSString *)wsUrl presentingViewController:(UIViewController *)viewController callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)createConferenceRoom:(NSString *)roomName password:(NSString *)password moderatorPassword:(NSString *)moderatorPassword at:(NSString *)wsUrl callback:(void (^)(BOOL, NSDictionary *))callback;

@end
