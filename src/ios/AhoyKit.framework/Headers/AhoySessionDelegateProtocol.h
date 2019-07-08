//
//  CallDelegateProtocol.h
//  AhoyUC
//
//  Created by kapejod on 06/01/15.
//  Copyright (c) 2015 Junghanns Communications GmbH. All rights reserved.
//

@class AhoySession;
@class RTCMediaStream;

@protocol AhoySessionDelegateProtocol <NSObject>

@required
- (void)sessionDidGetAcknowledged:(AhoySession *)call;
- (void)sessionDidGetAnswered:(AhoySession *)call withPeer:(NSDictionary *)peer;
- (void)sessionDidGetRejected:(AhoySession *)call withReason:(NSString *)reason;
- (void)sessionDidGetCanceled:(AhoySession *)call;
- (void)sessionDidGetTerminated:(AhoySession *)call;
- (void)sessionDidFail:(AhoySession *)call;

@optional
- (void)sessionDidGetLocalMediaStream:(RTCMediaStream *) stream;
- (void)sessionDidGetRemoteMediaStream:(RTCMediaStream *) stream;
- (void)sessionDidNotGetLocalMediaStream;

- (void)sessionIsProgressing:(AhoySession *)call progress:(NSDictionary *)information;
- (void)sessionDidEstablishMediaLayer:(AhoySession *)call;
- (void)sessionDidDisconnectMediaLayer:(AhoySession *)call;
- (void)sessionDidFailToEstablishMediaLayer:(AhoySession *)call;
@end
