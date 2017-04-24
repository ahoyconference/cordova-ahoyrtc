//
//  Call.h
//  AhoyUC
//
//  Created by kapejod on 06/01/15.
//  Copyright (c) 2015 Junghanns Communications GmbH. All rights reserved.
//

#import <foundation/Foundation.h>
#import <WebRTC/WebRTC.h>
#import "AhoyMediaLayerDelegateProtocol.h"
#import "AhoySessionDelegateProtocol.h"

@interface AhoySession : NSObject <RTCPeerConnectionDelegate>

@property (nonatomic, weak) id<AhoySessionDelegateProtocol> delegate;
@property (nonatomic, weak) id<AhoyMediaLayerDelegateProtocol> mediaLayerDelegate;
@property (nonatomic, strong) NSString *uuid;
@property (nonatomic, strong) NSString *email;
@property (nonatomic, strong) NSString *url;
@property (nonatomic) BOOL isOutgoingSession;
@property (nonatomic, strong) NSString *localAddress;
@property (nonatomic, strong) NSString *peerAddress;
@property (nonatomic, strong) NSString *remoteAddress;
@property (nonatomic, strong) NSDictionary *from;
@property (nonatomic, strong) NSString *peerFirstName;
@property (nonatomic, strong) NSString *peerLastName;
@property (nonatomic, strong) NSDictionary *metaData;
@property (nonatomic) BOOL isAudioEnabled;
@property (nonatomic) BOOL isVideoEnabled;
@property (nonatomic) BOOL isTrickleIceEnabled;
@property (nonatomic, strong) UILocalNotification *localNotification;
@property (nonatomic, strong) UIAlertController *alertController;

@property (nonatomic, strong) RTCPeerConnection *peerConnection;
@property (nonatomic, strong) RTCMediaStream *localStream;
@property (nonatomic, strong) RTCMediaStream *remoteStream;
@property (nonatomic, strong) RTCSessionDescription *localDescription;
@property (nonatomic, weak) RTCMediaStreamTrack *localAudioTrack;
@property (nonatomic) int localAudioLostPackets;
@property (nonatomic, weak) RTCMediaStreamTrack *localVideoTrack;
@property (nonatomic) int localVideoLostPackets;
@property (nonatomic) int localVideoMaxBitrate;
@property (nonatomic) int bweAvailableSendBandwidth;
@property (nonatomic) int bweAvailableReceiveBandwidth;
@property (nonatomic) BOOL isBandwidthWarningActive;

@property (nonatomic, strong) RTCSessionDescription *remoteDescription;
@property (nonatomic, strong) NSDictionary *turn;
@property (nonatomic, strong) NSMutableArray *localIceCandidates;
@property (nonatomic, strong) NSMutableArray *pendingIceCandidates;
@property (nonatomic) BOOL isMediaLayerConnected;
@property (nonatomic) BOOL isConnected;
@property (nonatomic) int receivedAcks;
@property (nonatomic, strong) NSTimer *statisticsTimer;
@property (nonatomic, strong) NSTimer *rejectionTimer;
@property int timeout;
@property (nonatomic, strong) NSTimer *timeoutTimer;


@property (nonatomic, copy) void (^onIceCandidatesCompleteCallback)(void);
@property (nonatomic, copy) void (^onIceGatheringCompleteCallback)(void);
@property (nonatomic, copy) void (^onStreamAddedCallback)(RTCPeerConnection *peerConnection, RTCMediaStream *stream);

- (id)initWithSdpOffer:(NSDictionary *)sessionOffer fromAddress:(NSString *)address localAddress:(NSString *)localAddress;
- (id)initOutgoingSessionWithDestinationAddress:(NSString *)address audio:(BOOL)enableAudio video:(BOOL)enableVideo localAddress:(NSString *)localAddress from:(NSDictionary *)from timeout:(int)timeout;

- (void)onSetRemoteDescription:(NSError * _Nullable)error;
- (void)onSetLocalDescription:(NSError * _Nullable)error;

- (void)answerWithAudio:(BOOL)enableAudio andVideo:(BOOL)enableVideo callback:(void(^)(BOOL, NSDictionary *))callback;
- (void)answerIncomingSessionWithAudio:(BOOL) enableAudio andVideo:(BOOL) enableVideo;
- (void)startOutgoingSession;
- (void)rejectWithStatus:(int)status andReason:(NSString *)reason;

- (void)didReceiveIceCandidate:(RTCIceCandidate *)candidate;
- (void)didGetAnswered:(NSDictionary *)sessionAnswer fromAddress:(NSString *)address;
- (void)didGetCanceled;
- (void)didGetAcknowledged;
- (void)didGetTerminated;
- (void)didGetRejectedWithStatus:(int)status andReason:(NSString *)reason;
- (void)didGetConfirmedForAddress:(NSString *)address;
- (void)showAlertView;

- (void)terminate;
- (void)hangup;

@end

