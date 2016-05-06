//
//  AhoyEmailInfoProvider.h
//  AhoySDK
//
//  Created by kapejod on 15/06/15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//
#import <UIKit/UIKit.h>

@interface AhoyEmailInfoProvider : UIActivityItemProvider
@property (nonatomic, strong) NSString *body;
@property (nonatomic, strong) NSString *subject;

- (id)initWithBody:(NSString *)body andSubject:(NSString *)subject;
@end
