//
//  Call.h
//  AhoyUC
//
//  Created by kapejod on 06/01/15.
//  Copyright (c) 2015 Junghanns Communications GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebRTC/WebRTC.h>
#import "AhoySessionDelegateProtocol.h"

@interface AhoySession : NSObject <RTCPeerConnectionDelegate>

@property (nonatomic, weak, nullable) id<AhoySessionDelegateProtocol> delegate;
@property (nonatomic, strong, nullable) NSString *uuid;
@property (nonatomic, strong, nullable) NSString *email;
@property (nonatomic, strong, nullable) NSString *url;
@property (nonatomic) BOOL isOutgoingSession;
@property (nonatomic, strong, nullable) NSString *localAddress;
@property (nonatomic, strong, nullable) NSString *peerAddress;
@property (nonatomic, strong, nullable) NSString *remoteAddress;
@property (nonatomic, strong, nullable) NSDictionary *from;
@property (nonatomic, strong, nullable) NSString *peerFirstName;
@property (nonatomic, strong, nullable) NSString *peerLastName;
@property (nonatomic, strong, nullable) NSDictionary *metaData;
@property (nonatomic, strong, nullable) NSDictionary *sip;
@property (nonatomic) BOOL isAudioEnabled;
@property (nonatomic) BOOL isVideoEnabled;
@property (nonatomic) BOOL isHdVideoEnabled;
@property (nonatomic) BOOL isNoiseReductionEnabled;
@property (nonatomic) BOOL isTrickleIceEnabled;
@property (nonatomic, strong, nullable) UILocalNotification *localNotification;
@property (nonatomic, strong, nullable) UIAlertController *alertController;

@property (nonatomic, strong, nullable) RTCPeerConnection *peerConnection;
@property (nonatomic, strong, nullable) RTCMediaStream *localStream;
@property (nonatomic, strong, nullable) RTCMediaStream *remoteStream;
@property (nonatomic, strong, nullable) RTCSessionDescription *localDescription;
@property (nonatomic, weak, nullable) RTCMediaStreamTrack *localAudioTrack;
@property (nonatomic) int localAudioLostPackets;
@property (nonatomic, weak, nullable) RTCMediaStreamTrack *localVideoTrack;
@property (nonatomic) int localVideoLostPackets;
@property (nonatomic, strong, nullable) NSNumber *maxVideoBitrate;
@property (nonatomic) AVCaptureDevicePosition captureDevicePosition;
@property (nonatomic, strong, nullable) NSDictionary *preferredVideoCodec;

@property (nonatomic) int bweAvailableSendBandwidth;
@property (nonatomic) int bweAvailableReceiveBandwidth;
@property (nonatomic) BOOL isBandwidthWarningActive;

@property (nonatomic, strong, nullable) RTCSessionDescription *remoteDescription;
@property (nonatomic, strong, nullable) NSDictionary *turn;
@property (nonatomic, strong, nullable) NSMutableArray *localIceCandidates;
@property (nonatomic, strong, nullable) NSMutableArray *pendingIceCandidates;
@property (nonatomic) BOOL isMediaLayerConnected;
@property (nonatomic) BOOL isConnected;
@property (nonatomic) BOOL isIceGatheringComplete;
@property (nonatomic) int receivedAcks;
@property (nonatomic, strong, nullable) NSTimer *statisticsTimer;
@property (nonatomic, strong, nullable) NSTimer *rejectionTimer;
@property int timeout;
@property (nonatomic, strong, nullable) NSTimer *timeoutTimer;
@property (nonatomic, strong, nullable) NSTimer *iceGatheringTimeoutTimer;


@property (nonatomic, copy, nullable) void (^onIceCandidatesCompleteCallback)(void);
@property (nonatomic, copy, nullable) void (^onIceGatheringCompleteCallback)(void);
@property (nonatomic, copy, nullable) void (^onStreamAddedCallback)(RTCPeerConnection * _Nonnull peerConnection, RTCMediaStream * _Nonnull stream);

- (nonnull id)initWithSdpOffer:(nonnull NSDictionary *)sessionOffer fromAddress:(nonnull NSString *)address localAddress:(nonnull NSString *)localAddress;
- (nonnull id)initOutgoingSessionWithDestinationAddress:(nonnull NSString *)address audio:(BOOL)enableAudio video:(BOOL)enableVideo localAddress:(nonnull NSString *)localAddress from:(nullable NSDictionary *)from timeout:(int)timeout;
- (nonnull id)initOutgoingSessionWithDestinationAddress:(nonnull NSString *)address audio:(BOOL)enableAudio video:(BOOL)enableVideo localAddress:(nonnull NSString *)localAddress from:(nullable NSDictionary *)from sip:(nonnull NSDictionary *)sip timeout:(int)timeout;

- (void)onSetRemoteDescription:(NSError * _Nullable)error;
- (void)onSetLocalDescription:(NSError * _Nullable)error;

- (void)answerWithAudio:(BOOL)enableAudio andVideo:(BOOL)enableVideo callback:(nullable void(^)(BOOL, NSDictionary * _Nullable))callback;
- (void)answerIncomingSessionWithAudio:(BOOL) enableAudio andVideo:(BOOL) enableVideo;
- (void)setVideoOptionsWithCaptureDevicePosition:(AVCaptureDevicePosition)captureDevicePosition hdVideo:(BOOL)enableHdVideo noiseReduction:(BOOL)enableNoiseReduction preferredCodec:(NSString *)codec bitrate:(NSNumber *)bitrate;
- (void)startOutgoingSession;
- (void)rejectWithStatus:(int)status andReason:(nullable NSString *)reason;

- (void)didReceiveIceCandidate:(nullable RTCIceCandidate *)candidate;
- (void)didGetAnswered:(nonnull NSDictionary *)sessionAnswer fromAddress:(nonnull NSString *)address;
- (void)didGetCanceled;
- (void)isProgressing:(nonnull NSDictionary *)information;
- (void)didGetAcknowledged;
- (void)didGetTerminated;
- (void)didGetRejectedWithStatus:(int)status andReason:(nullable NSString *)reason;
- (void)didGetConfirmedForAddress:(nonnull NSString *)address;
- (void)showAlertView;
- (void)setMicrophoneMuted:(BOOL)muted;
- (void)terminate;
- (void)hangup;
- (void)sendDtmf:(nonnull NSString *)tones withDuration:(NSTimeInterval)duration andInterToneGap:(NSTimeInterval)interToneGap;
- (void)sendDtmf:(nonnull NSString *)tones;

@end

