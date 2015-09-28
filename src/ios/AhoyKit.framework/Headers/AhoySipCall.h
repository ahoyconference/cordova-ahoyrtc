//
//  AhoySipCall.h
//  AhoySDK
//
//  Created by kapejod on 12/04/15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//

#import <foundation/Foundation.h>
#import "AhoySipCallDelegateProtocol.h"

@interface AhoySipCall : NSObject
typedef NS_ENUM(NSInteger, AhoySipCallState) {
    AhoySipCallState_NULL,
    AhoySipCallState_INVITE_SENT,
    AhoySipCallState_RINGING,
    AhoySipCallState_CONNECTING,
    AhoySipCallState_CONNECTED,
    AhoySipCallState_DISCONNECTING,
    AhoySIPCallState_DISCONNECTED
};

@property (nonatomic, weak) id delegate;
@property (nonatomic) AhoySipCallState state;

- (void)hangup;

+ (AhoySipCall *)callTo:(NSString *)calledPartyNumber from:(NSString *)callingPartyNumber forSubscriber:(NSString *)subscriberHash loadbalancers:(NSArray *)loadbalancers apiKey:(NSString *)apiKey delegate:(id<AhoySipCallDelegateProtocol>)delegate;

@end
