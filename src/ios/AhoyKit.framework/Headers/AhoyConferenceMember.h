//
//  ConferenceMember.h
//  FSKtest
//
//  Created by kapejod on 09/12/14.
//  Copyright (c) 2014 Junghanns Communications GmbH. All rights reserved.
//

#import <foundation/Foundation.h>
#import "RTCPeerConnection.h"
#import "RTCMediaStream.h"
#import "RTCSessionDescription.h"
#import "RTCSessionDescriptionDelegate.h"
#import "RTCStatsDelegate.h"
#import "AhoyConferenceMemberDelegateProtocol.h"

@interface AhoyConferenceMember : NSObject <RTCPeerConnectionDelegate, RTCSessionDescriptionDelegate, RTCStatsDelegate>

@property (nonatomic, strong) NSString *name;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *memberID;
@property (nonatomic) BOOL isLocalMember;
@property (nonatomic) BOOL isModerator;
@property (nonatomic) BOOL isSpeaker;
@property (nonatomic) BOOL isAudioAvailable;
@property (nonatomic) BOOL isAudioMuted;
@property (nonatomic) BOOL isVideoAvailable;
@property (nonatomic) BOOL isVideoMuted;
@property (nonatomic) BOOL isSpeaking;
@property (nonatomic, strong) RTCSessionDescription *localDescription;
@property (nonatomic, strong) RTCSessionDescription *remoteDescription;
@property (nonatomic, weak) RTCMediaStreamTrack *audioTrack;
@property (nonatomic, weak) RTCMediaStreamTrack *videoTrack;
@property (nonatomic) double statisticsInterval;
@property (nonatomic, strong) NSTimer *statisticsTimer;
@property (nonatomic) BOOL isMediaLayerConnected;


@property (nonatomic, copy) void (^onSetSessionDescriptionCallback)(NSError *error);
@property (nonatomic, copy) void (^onCreateSessionDescriptionCallback)(RTCSessionDescription *description, NSError *error);
@property (nonatomic, copy) void (^onIceCandidatesCompleteCallback)(void);
@property (nonatomic, copy) void (^onIceGatheringCompleteCallback)(void);
@property (nonatomic, copy) void (^onStreamAddedCallback)(RTCPeerConnection *peerConnection, RTCMediaStream *stream);
@property (nonatomic, weak) id<AhoyConferenceMemberDelegateProtocol> delegate;

@property (nonatomic, strong) RTCPeerConnection *peerConnection;
@property (nonatomic, strong)RTCMediaStream *mediaStream;

- (void)peerConnection:(RTCPeerConnection *)peerConnection addedStream:(RTCMediaStream *)stream;
- (void)peerConnection:(RTCPeerConnection *)peerConnection iceConnectionChanged:(RTCICEConnectionState)newState;
- (id)initWithMemberName:(NSString *)memberName andMemberID:(NSString *)memberID;
- (id)initFromDictionary:(NSDictionary *)dict;
- (void)handleSdpRequest:(NSDictionary *)message;
- (void)destroyPeerConnection;
- (void)destroy;

@end