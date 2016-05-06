//
//  ConferenceManager.h
//  FSKtest
//
//  Created by kapejod on 04.12.14.
//  Copyright (c) 2014 Junghanns Communications GmbH. All rights reserved.
//

#import <foundation/Foundation.h>
#import "SocketRocket/SRWebSocket.h"
#import "RTCPeerConnection.h"
#import "AhoyConferenceMember.h"
#import "AhoyConference.h"

@interface AhoyConferenceManager : NSObject <SRWebSocketDelegate>

@property (nonatomic, strong) NSString *myRoom;
@property (nonatomic, strong) NSString *myName;
@property (nonatomic, strong) NSString *myPassword;
@property (nonatomic, strong) NSString *myWsUrl;
@property (nonatomic, strong) NSDictionary *invitation;
@property (nonatomic, strong) NSTimer *reconnectTimer;
@property (nonatomic, strong) AhoyConferenceMember *localMember;
@property (nonatomic, strong) AhoyConference *conference;
@property (nonatomic, strong) NSString *mediaReceiveTransactionID;
@property (nonatomic) double statisticsInterval;


+ (id)sharedInstance;

- (void)joinConference:(NSString *)uuid
          withSession:(NSString *)session
              at:(NSString *)wsUrl callback:(void (^)(BOOL, NSDictionary *, AhoyConference *))callback;

- (void)joinRoom:(NSString *)room
        withName:(NSString *)name
    withPassword:(NSString *)password
              at:(NSString *)wsUrl callback:(void (^)(BOOL, NSDictionary *, AhoyConference *))callback;

- (void)createRoom:(NSString *)room
      withPassword:(NSString *)password
      withListenerPassword:(NSString *)listenerPassword
    withModeratorPassword:(NSString *)moderatorPassword
              at:(NSString *)wsUrl callback:(void (^)(BOOL, NSDictionary *, AhoyConference *))callback;

- (void)joinConferenceWithInvitation:(NSDictionary *)invitation
                                  at:(NSString *)wsUrl callback:(void (^)(BOOL, NSDictionary *, AhoyConference *))callback;

    
- (void)sendSdpResponse:(NSString *)sdp forMember:(AhoyConferenceMember *)member;
- (void)leaveRoom;
- (void)publishMedia;
- (void)lockRoom;
- (void)unlockRoom;
- (void)setDescription:(NSString *)description;
- (void)getInvitationUrlWithCallback:(void (^)(BOOL, NSString *))callback;
- (void)sendConferenceStatistics:(NSDictionary *)statistics memberID:(NSString *)memberID memberName:(NSString *)memberName;
@end