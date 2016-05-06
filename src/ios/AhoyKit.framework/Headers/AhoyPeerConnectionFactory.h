//
//  PeerConnectionFactory.h
//  FSKtest
//
//  Created by kapejod on 09/12/14.
//  Copyright (c) 2014 Junghanns Communications GmbH. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#import "RTCICECandidate.h"
#import "RTCICEServer.h"
#import "RTCMediaConstraints.h"
#import "RTCMediaStream.h"
#import "RTCPair.h"
#import "RTCPeerConnection.h"
#import "RTCPeerConnectionDelegate.h"
#import "RTCPeerConnectionFactory.h"
#import "RTCSessionDescription.h"
#import "RTCVideoSource.h"
#import "RTCAVFoundationVideoSource.h"
#import "RTCVideoCapturer.h"
#import "RTCAudioTrack.h"
#import "RTCVideoTrack.h"
#import "RTCStatsReport.h"
#import "AhoySDK.h"


@interface AhoyPeerConnectionFactory : NSObject

@property (strong, nonatomic) RTCPeerConnectionFactory *factory;
@property (strong, nonatomic) RTCAVFoundationVideoSource *localVideoSource;
@property (nonatomic) BOOL isUsingBackCamera;

+ (id)sharedInstance;
+ (void) addStatisticsPair:(RTCPair *)pair toDictionary:(NSMutableDictionary *)dictionary;
+ (NSString *)processSdp:(NSString *)origSDP  maxVideoBitrate:(NSNumber *)maxVideoBitrate limitVideoBitrate:(bool)limitVideoBitrate;
+ (NSString *)processSdp:(NSString *)origSDP;
+ (RTCSessionDescription *)descriptionForDescription:(RTCSessionDescription *)description preferredVideoCodec:(NSString *)codec;
- (RTCPeerConnection *)createPeerConnectionWithAudio:(BOOL) audio andVideo:(BOOL)video andStunUri:(NSString *)stunUri andDelegate:(id<RTCPeerConnectionDelegate>)delegate;
- (RTCPeerConnection *)createPeerConnectionWithAudio:(BOOL) audio andVideo:(BOOL)video andTurn:(NSDictionary *)turn andDelegate:(id<RTCPeerConnectionDelegate>)delegate;
- (RTCMediaStream *)addLocalMediaToPeerConnection:(RTCPeerConnection *)peerConnection audio:(BOOL)audio video:(BOOL)video  cameraPosition:(AVCaptureDevicePosition) position noiseReduction:(BOOL) enableNoiseReduction hdVideo: (BOOL) enableHdVideo forConferencing:(BOOL)forConferencing;
- (void)muteAudioStream:(RTCMediaStream *)mediaStream;
- (void)unmuteAudioStream:(RTCMediaStream *)mediaStream;
- (void)muteVideoStream:(RTCMediaStream *)mediaStream;
- (void)unmuteVideoStream:(RTCMediaStream *)mediaStream;
- (BOOL) switchCamera;
- (void) setTorchEnabled:(BOOL) enabled;
- (BOOL) getTorchEnabled;
@end
