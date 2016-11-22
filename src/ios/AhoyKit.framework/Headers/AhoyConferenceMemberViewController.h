//
//  AhoyConferenceMemberView.h
//  AhoySDK
//
//  Created by kapejod on 18.02.15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebRTC/WebRTC.h>
#import "AhoyEAGLVideoView.h"
#import "AhoyConferenceMember.h"
#import "AhoyConferenceDelegateProtocol.h"
#import "AhoyConferenceMemberDelegateProtocol.h"
#import "AhoyConferenceMemberTouchDelegateProtocol.h"

@interface AhoyConferenceMemberViewController : UIView <RTCEAGLVideoViewDelegate, AhoyConferenceMemberDelegateProtocol>
@property (nonatomic, strong)UILabel *nameLabel;
@property (nonatomic, strong)AhoyEAGLVideoView *videoView;
@property (nonatomic, weak)AhoyConferenceMember *member;
@property (nonatomic, weak)RTCVideoTrack *videoTrack;
@property (nonatomic)CGSize videoSize;
@property (nonatomic)BOOL hasTitle;
@property (nonatomic)NSInteger verticalOffset;
@property (nonatomic)CGSize aspectRatio;
@property (nonatomic)BOOL zoom;
@property (nonatomic, strong) id <AhoyConferenceDelegateProtocol> conferenceDelegate;
@property (nonatomic, strong) id <AhoyConferenceMemberTouchDelegateProtocol> touchDelegate;

- (id)initWithFrame:(CGRect)frame member:(AhoyConferenceMember *)member conferenceDelegate:(id<AhoyConferenceDelegateProtocol>) conferenceDelegate hasTitle:(BOOL)hasTitle borderColor:(UIColor *)borderColor;
- (void)setFrame:(CGRect)frame;
- (void) destroy;
@end
