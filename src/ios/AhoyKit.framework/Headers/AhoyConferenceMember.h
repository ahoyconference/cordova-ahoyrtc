//
//  ConferenceMember.h
//  FSKtest
//
//  Created by kapejod on 09/12/14.
//  Copyright (c) 2014 Junghanns Communications GmbH. All rights reserved.
//

#import <foundation/Foundation.h>
#import <WebRTC/WebRTC.h>
#import "AhoyConferenceMemberDelegateProtocol.h"

@interface AhoyConferenceMember : NSObject <RTCPeerConnectionDelegate>

@property (nonatomic, strong, nullable) NSString *name;
@property (nonatomic, strong, nullable) NSString *email;
@property (nonatomic, strong, nullable) NSString *memberID;
@property (nonatomic) BOOL isLocalMember;
@property (nonatomic) BOOL isModerator;
@property (nonatomic) BOOL isSpeaker;
@property (nonatomic) BOOL isAudioAvailable;
@property (nonatomic) BOOL isAudioMuted;
@property (nonatomic) BOOL isVideoAvailable;
@property (nonatomic) BOOL isVideoMuted;
@property (nonatomic) BOOL isSpeaking;
@property (nonatomic, strong, nullable) RTCSessionDescription *localDescription;
@property (nonatomic, strong, nullable) RTCSessionDescription *remoteDescription;
@property (nonatomic, weak, nullable) RTCMediaStreamTrack *audioTrack;
@property (nonatomic, weak, nullable) RTCMediaStreamTrack *videoTrack;
@property (nonatomic) double statisticsInterval;
@property (nonatomic, strong, nullable) NSTimer *statisticsTimer;
@property (nonatomic) BOOL isMediaLayerConnected;


/*
@property (nonatomic, copy) void (^onSetSessionDescriptionCallback)(NSError *error);
@property (nonatomic, copy) void (^onCreateSessionDescriptionCallback)(RTCSessionDescription *description, NSError *error);
@property (nonatomic, copy) void (^onIceCandidatesCompleteCallback)(void);
@property (nonatomic, copy) void (^onIceGatheringCompleteCallback)(void); */
@property (nonatomic, weak, nullable) id<AhoyConferenceMemberDelegateProtocol> delegate;

@property (nonatomic, strong, nullable) RTCPeerConnection *peerConnection;
@property (nonatomic, strong, nullable)RTCMediaStream *mediaStream;

- (id _Nullable)initWithMemberName:(nonnull NSString *)memberName andMemberID:(NSString * _Nonnull)memberID;
- (id _Nullable)initFromDictionary:(nonnull NSDictionary *)dict;
- (void)handleSdpRequest:(nonnull NSDictionary *)message;
- (void)destroyPeerConnection;
- (void)destroy;

@end
