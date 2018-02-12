//
//  AhoyConferenceMemberTouchDelegateProtocol.h
//  AhoySDK
//
//  Created by kapejod on 19.02.15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol AhoyConferenceMemberTouchDelegateProtocol <NSObject>
- (void)targetdDidReceiveSingleTap:(id)target;
- (void)targetdDidReceiveDoubleTap:(id)target;
@end
