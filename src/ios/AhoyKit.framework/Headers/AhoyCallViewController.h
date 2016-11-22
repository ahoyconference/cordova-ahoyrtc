//
//  AhoyCallViewController.h
//  AhoySDK
//
//  Created by kapejod on 07/06/15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//

//
//  ConferenceViewController.h
//  AhoyConference
//
//  Created by kapejod on 14/12/14.
//  Copyright (c) 2014 Junghanns Communications GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebRTC/WebRTC.h>
#import <AVFoundation/AVFoundation.h>
#import "AhoySDK.h"
#import "AhoySession.h"
#import "AhoyImageButton.h"
#import "AhoyImageSwitch.h"

@interface AhoyCallViewController : UIViewController <AhoySessionDelegateProtocol, AhoyMediaLayerDelegateProtocol, RTCEAGLVideoViewDelegate, AhoyImageButtonDelegateProtocol, AhoyImageSwitchDelegateProtocol>


- (id)initWithSession:(AhoySession *)session callback:(void(^)(BOOL, NSDictionary *))callback;

@end
