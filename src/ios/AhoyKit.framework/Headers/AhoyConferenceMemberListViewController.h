//
//  AhoyConferenceMemberListView.h
//  AhoySDK
//
//  Created by kapejod on 18.02.15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AhoyConferenceMember.h"
#import "AhoyConferenceDelegateProtocol.h"

@interface AhoyConferenceMemberListViewController : UIView
@property (nonatomic, strong)UIScrollView *scroll;
@property (nonatomic, strong)UILabel *emptyMessage;
@property (nonatomic)NSInteger numberOfViews;
@property (nonatomic, strong) UIColor *borderColor;
@property (nonatomic)NSInteger contentWidth;
@property (nonatomic, strong) id <AhoyConferenceDelegateProtocol> conferenceDelegate;

- initWithFrame:(CGRect)frame members:(NSArray *)members conferenceDelegate:(id<AhoyConferenceDelegateProtocol>) conferenceDelegate borderColor:(UIColor *)borderColor;

- (void)addMember:(AhoyConferenceMember *)member;
- (void)removeMember:(AhoyConferenceMember *)member;
- (void)destroy;
@end
