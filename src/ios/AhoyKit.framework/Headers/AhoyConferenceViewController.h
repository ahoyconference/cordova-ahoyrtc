//
//  ConferenceViewController.h
//  AhoyConference
//
//  Created by kapejod on 14/12/14.
//  Copyright (c) 2014 Junghanns Communications GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AhoyConference.h"
#import "AhoyConferenceMemberListViewController.h"
#import "AhoyConferenceMemberViewController.h"
#import "AhoyImageButton.h"
#import "AhoyImageSwitch.h"

@interface AhoyConferenceViewController : UIViewController <AhoyConferenceDelegateProtocol, AhoyConferenceMemberTouchDelegateProtocol, AhoyImageButtonDelegateProtocol, AhoyImageSwitchDelegateProtocol>
- (id)initWithConference:(AhoyConference *)conference callback:(void(^)(BOOL, NSDictionary *))callback;
- (void)didLeaveConference;
@end
