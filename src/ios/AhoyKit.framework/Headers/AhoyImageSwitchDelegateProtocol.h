//
//  AhoyImageSwitchDelegateProtocol.h
//  AhoySDK
//
//  Created by kapejod on 10/06/15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//


#import <Foundation/Foundation.h>

@protocol AhoyImageSwitchDelegateProtocol <NSObject>
- (void)ahoyImageSwitchEnabled:(id)target;
- (void)ahoyImageSwitchDisabled:(id)target;
@end