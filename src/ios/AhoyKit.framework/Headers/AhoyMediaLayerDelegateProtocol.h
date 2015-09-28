//
//  MediaLayerDelegateProtocol.h
//  AhoyUC
//
//  Created by kapejod on 08/01/15.
//  Copyright (c) 2015 Junghanns Communications GmbH. All rights reserved.
//

@protocol AhoyMediaLayerDelegateProtocol <NSObject>
- (void)sessionDidEstablishMediaLayer:(id)call;
- (void)sessionDidDisconnectMediaLayer:(id)call;

@end