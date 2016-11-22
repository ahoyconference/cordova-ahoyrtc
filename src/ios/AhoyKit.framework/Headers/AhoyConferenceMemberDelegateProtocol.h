//
//  AhoyConferenceMemberDelegateProtocol.h
//  AhoySDK
//
//  Created by kapejod on 18.02.15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//
//
//  ConferenceDelegateProtocol.h
//  FSKtest
//
//  Created by kapejod on 10/12/14.
//  Copyright (c) 2014 Junghanns Communications GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <WebRTC/WebRTC.h>

@protocol AhoyConferenceMemberDelegateProtocol <NSObject>
- (void)didGetMediaStream:(RTCMediaStream *)stream;
@end
