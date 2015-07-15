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
    AhoyVideoFormat_320_240_30,
    AhoyVideoFormat_352_288_30,
    AhoyVideoFormat_640_480_30,
    AhoyVideoFormat_1280_720_30
};

typedef NS_ENUM(NSInteger, AhoyCallEvent) {
    AhoyCallEvent_NewIncomingCall,
    AhoyCallEvent_IncomingCallCanceled,
    AhoyCallEvent_CallStatus
};


@property (nonatomic, strong) __block void (^callListener)(AhoyCallEvent, NSDictionary *);

+ (id)sharedInstance;
+ (void)destroy;
+ (NSString *)platform;
+ (BOOL)isDeviceVideoCapable;
+ (BOOL)isDeviceHdVideoCapable;
+ (BOOL)isVideoCaptureAvailable;
+ (BOOL)isSpeakerEnabled;
+ (BOOL)isHeadphonesEnabled;
+ (BOOL)isBluetoothEnabled;
+ (void)enableSpeaker;
+ (void)disableSpeaker;
+ (void)autoselectOutputDevice;
+ (NSInteger)videoCaptureFormatForConferencing;
+ (NSInteger)videoCaptureFormatForCalling;
+ (NSString *)callViewControllerNameByApiKey:(NSString *)apiKey;
+ (NSString *)conferenceViewControllerNameByApiKey:(NSString *)apiKey;

// generic
- (NSDictionary *)getSettings;
- (NSDictionary *)setSettings:(NSDictionary *)settings;
- (NSDictionary *)uiColors;
- (UIColor *)uiColor:(NSString *)name or:(unsigned int)hex;

// AhoyUC
- (void)setApiKey:(NSString *)apiKey apiUrl:(NSString *)apiUrl;
- (void)setViewController:(UIViewController *)vc;
- (void)setPresenceStatus:(NSString *)status;
- (NSString *)getPresenceStatus;
- (UIViewController *)getViewController;
- (void)initializeWithCallback:(void (^)(BOOL, NSDictionary *))callback debugBuild:(BOOL)isDebugBuild;

- (void)loginWithEmail:(NSString *)email password:(NSString *)password callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)logoutWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getContactListWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)callAddress:(NSString *)address withAudio:(BOOL)enableAudio andVideo:(BOOL)enableVideo metaData:(NSDictionary *)metaData presentingViewController:(UIViewController *)viewController viewControllerName:(NSString *)viewControllerName callback:(void(^)(BOOL, NSDictionary *))callback;
- (void)callContact:(NSDictionary *)contact withAudio:(BOOL)enableAudio andVideo:(BOOL)enableVideo callback:(void(^)(BOOL, NSDictionary *))callback;
- (void)callContactByUuid:(NSString *)uuid withAudio:(BOOL)enableAudio andVideo:(BOOL)enableVideo presentingViewController:(UIViewController *)viewController callback:(void(^)(BOOL, NSDictionary *))callback;
- (void)getContactInfo:(NSString *)contactUuid withCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getConferenceListWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getConferenceInfo:(NSString *)uuid callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)joinConference:(NSString *)uuid presentingViewController:(UIViewController *)viewController callback:(void(^)(BOOL, NSDictionary *))callback;
- (void)answerIncomingCall:(NSString *)uuid withAudio:(BOOL)enableAudio andVideo:(BOOL)enableVideo callback:(void(^)(BOOL, NSDictionary *))callback;
- (void)rejectIncomingCall:(NSString *)uuid withReason:(NSString *)reason;

// AhoyConference
- (void)joinConferenceRoom:(NSString *)roomName name:(NSString *)name password:(NSString *)password at:(NSString *)wsUrl presentingViewController:(UIViewController *)viewController callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)createConferenceRoom:(NSString *)roomName password:(NSString *)password moderatorPassword:(NSString *)moderatorPassword at:(NSString *)wsUrl callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)joinConferenceWithInvitation:(NSDictionary *)invitation at:(NSString *)wsUrl presentingViewController:(UIViewController *)viewController callback:(void (^)(BOOL, NSDictionary *))callback;

@end
