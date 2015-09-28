//
//  AhoyImageSwitch.h
//  AhoySDK
//
//  Created by kapejod on 10/06/15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <AhoyKit/AhoyImageSwitchDelegateProtocol.h>

@interface AhoyImageSwitch : UIView
@property (nonatomic, strong)UIButton *button;
@property (nonatomic, strong)NSString *textOn;
@property (nonatomic, strong)NSString *textOff;
@property (nonatomic, strong)UIImageView *imageViewOn;
@property (nonatomic, strong)UIImageView *imageViewOff;
@property (nonatomic)BOOL isEnabled;
@property (nonatomic, weak) id<AhoyImageSwitchDelegateProtocol> delegate;

- (id) initWithFrame:(CGRect)frame delegate:(id<AhoyImageSwitchDelegateProtocol>)delegate textOn:(NSString *)textOn textOff:(NSString *)textOff fontSize:(float)fontsize fontColor:(UIColor *)fontColor imageOnName:(NSString *)imageOnName imageOffName:(NSString *)imageOffName isOn:(BOOL)isOn;
- (void)setFrame:(CGRect)frame;
- (void)enable;
- (void)disable;

@end