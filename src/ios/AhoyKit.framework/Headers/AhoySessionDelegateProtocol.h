//
//  CallDelegateProtocol.h
//  AhoyUC
//
//  Created by kapejod on 06/01/15.
//  Copyright (c) 2015 Junghanns Communications GmbH. All rights reserved.
//


@protocol AhoySessionDelegateProtocol <NSObject>

@required
- (void)sessionDidGetAcknowledged:(id)call;
- (void)sessionDidDisconnectMediaLayer:(id)call;
- (void)sessionIsConnecting:(id)call;
- (void)sessionDidBecomeConnected:(id)call;
- (void)sessionDidGetHungUp:(id)call;

@optional
- (void)sessionIsProgressing:(id)call progress:(NSDictionary *)information;
- (void)didGetLocalMediaStream:(id) stream;
- (void)didGetRemoteMediaStream:(id) stream;

@end
