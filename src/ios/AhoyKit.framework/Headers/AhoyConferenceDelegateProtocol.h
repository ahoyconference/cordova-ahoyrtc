//
//  ConferenceDelegateProtocol.h
//  FSKtest
//
//  Created by kapejod on 10/12/14.
//  Copyright (c) 2014 Junghanns Communications GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AhoyConference.h"
#import "AhoyConferenceMember.h"
#import "RTCMediaStream.h"

@protocol AhoyConferenceDelegateProtocol <NSObject>
- (void)member:(AhoyConferenceMember *)member didJoinConference:(id)conference;
- (void)member:(AhoyConferenceMember *)member didLeaveConference:(id)conference;
- (void)memberDidStartSharingMedia:(AhoyConferenceMember *)member;
- (void)memberDidStopSharingMedia:(AhoyConferenceMember *)member;
- (void)memberDidBecomeSpeaker:(AhoyConferenceMember *)member;
- (void)memberDidGetSelected:(AhoyConferenceMember *)member;
- (void)didGetKicked;
- (void)didLeaveConference;
- (void)didGetLocalMediaStream:(RTCMediaStream *)stream;
- (void)didGetLocked;
- (void)didGetUnlocked;
- (void)didGetDescription:(NSString *)description;
@end
