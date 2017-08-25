//
//  Conference.h
//  FSKtest
//
//  Created by kapejod on 10/12/14.
//  Copyright (c) 2014 Junghanns Communications GmbH. All rights reserved.
//

#import <foundation/Foundation.h>
#import "AhoyConferenceMember.h"
#import "AhoyConferenceDelegateProtocol.h"

@interface AhoyConference : NSObject

@property (nonatomic, strong) NSString *conferenceID;
@property (nonatomic, strong) NSString *conferenceName;
@property (nonatomic, strong) NSString *conferenceDescription;
@property (nonatomic, strong) NSString *conferenceUuid;
@property (nonatomic, strong) NSString *conferenceWsUrl;

@property (nonatomic) BOOL isLocked;
@property (nonatomic, strong) NSMutableDictionary *members;
@property (nonatomic, strong) AhoyConferenceMember *speaker;
@property (nonatomic, weak) id delegate;
@property (nonatomic, strong) AhoyConferenceMember *localMember;
@property (nonatomic, weak) RTCMediaStream *localStream;
@property (nonatomic)BOOL isSpeakerDetectionEnabled;

-(void)addConferenceMember:(AhoyConferenceMember *)member;
-(void)removeConferenceMemberByID:(NSString *)memberID;
-(AhoyConferenceMember *)getMemberByID:(NSString *)memberID;
-(AhoyConferenceMember *)electSpeaker:(BOOL)force;
-(void)addMediaStream:(RTCMediaStream *)stream toMember:(AhoyConferenceMember *)member;
-(void)attachDelegate:(id)delegate;
-(void)destroy;
@end
