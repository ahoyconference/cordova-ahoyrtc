//
//  AhoySipCallDelegateProtocol.h
//  AhoySDK
//
//  Created by kapejod on 12/04/15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//
@protocol AhoySipCallDelegateProtocol <NSObject>
- (void)sipCallIsProgressing:(id)call;
- (void)sipCallIsRinging:(id)call;
- (void)sipCallDidGetAnswered:(id)call;
- (void)sipCallDidGetHungup:(id)call;
- (void)sipCallDidFail:(id)call withStatus:(NSInteger)code reason:(NSString *)phrase;
@end