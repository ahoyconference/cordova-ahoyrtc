//
//  ApiManager.h
//  AhoyUC
//
//  Created by kapejod on 06/01/15.
//  Copyright (c) 2015 Junghanns Communications GmbH. All rights reserved.
//

#ifndef AhoyUC_ApiManager_h
#define AhoyUC_ApiManager_h

#import <foundation/Foundation.h>
#import <UIKit/UIApplication.h>
#import <PushKit/PushKit.h>
#import "SocketRocket/SRWebSocket.h"
#import "RTCPeerConnection.h"
#import "RTCPair.h"
#import "RTCMediaConstraints.h"
#import "RTCIceCandidate.h"
#import "AhoyPeerConnectionFactory.h"
#import "AhoySessionDelegateProtocol.h"
#import "AhoyMediaLayerDelegateProtocol.h"
#import "AhoySession.h"
#import "AhoyReachability.h"

@interface AhoyApiManager : NSObject <SRWebSocketDelegate, PKPushRegistryDelegate>

@property (nonatomic, strong) NSString *apiKey;
@property (nonatomic, strong) NSString *apiUrl;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *firstName;
@property (nonatomic, strong) NSString *lastName;
@property (nonatomic, strong) NSString *screenName;
@property (nonatomic) UIBackgroundTaskIdentifier backgroundTask;
@property (nonatomic, strong) SRWebSocket *apiSocket;
@property (nonatomic, strong) NSTimer *reconnectTimer;
@property (nonatomic, strong) NSTimer *endBackgroundTimer;
@property (nonatomic) __block BOOL isInitialized;
@property (nonatomic) __block BOOL isConnected;
@property (nonatomic) __block BOOL isConnecting;
@property (nonatomic) __block BOOL isLoggedIn;
@property (nonatomic) __block BOOL isInBackground;
@property (nonatomic) __block BOOL isPushSupported;
@property (nonatomic, strong) __block NSString *callStatus;
@property (nonatomic, strong) __block NSString *presenceStatus;
@property (nonatomic, strong) NSString *pushToken;
@property (nonatomic) double statisticsInterval;
@property (nonatomic) NetworkStatus networkStatus;

+ (id)sharedInstance;
- (void)setApiKey:(NSString *)apiKey apiUrl:(NSString *)apiUrl;
- (void)updatePushToken:(NSString *)token callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)initializeWithCallback:(void (^)(BOOL, NSDictionary *))callback debugBuild:(BOOL)isDebugBuild;

- (void)loginWithEmail:(NSString *)email password:(NSString *)password callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getTemporaryIdentityWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)logoutWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (NSString *)updateCallStatus:(NSString *)status;
- (void)sendUserStatusEventWithCallStatus:(NSString *)callStatus callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getContactListWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getContactInfo:(NSString *)contactUuid withCallback:(void (^)(BOOL, NSDictionary *))callback;
- (AhoySession *)callContact:(NSDictionary *)contact withAudio:(BOOL)enableAudio andVideo:(BOOL)enableVideo withCallback:(void (^)(BOOL, NSDictionary *))callback;
- (AhoySession *)callAddress:(NSString *)address withAudio:(BOOL)enableAudio andVideo:(BOOL)enableVideo metaData:(NSDictionary *)metaData withCallback:(void (^)(BOOL, NSDictionary *))callback;

- (void)answerIncomingCall:(NSString *)uuid withAudio:(BOOL)enableAudio andVideo:(BOOL)enableVideo  callback:(void(^)(BOOL, NSDictionary *))callback;
- (void)rejectIncomingCall:(NSString *)uuid withReason:(NSString *)reason;
- (void)sessionDidGetHungUp:(AhoySession *)session;
- (void)getConferenceListWithCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getConferenceInfo:(NSString *)uuid callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)getConferenceInvitation:(NSString *)conferenceUuid callback:(void (^)(BOOL, NSDictionary *))callback;
- (void)findConference:(NSString *)conferenceUuid withCallback:(void (^)(BOOL, NSDictionary *))callback;
- (void)sendMessage:(NSDictionary *)message to:(NSString *)address callback:(void (^)(BOOL, NSDictionary *))callback;

- (void)enablePushKit;
- (void)didReceiveLocalNotification:(NSDictionary *)notification;
- (void)updatePresenceStatus:(NSString *)status;
- (void)sendSessionStatistics:(NSDictionary *)statistics originatorAddress:(NSString *)originatorAddress terminatorAddress:(NSString *)terminatorAddress forSession:(NSString *)sessionUuid;
- (void)sendConferenceStatistics:(NSDictionary *)statistics conferenceID:(NSString *)conferenceID memberID:(NSString *)memberID memberName:(NSString *)memberName;
@end

#endif
