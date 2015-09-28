//
//  AhoyImageButton.h
//  AhoySDK
//
//  Created by kapejod on 10/06/15.
//  Copyright (c) 2015 AhoyRTC. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <AhoyKit/AhoyImageButtonDelegateProtocol.h>

@interface AhoyImageButton : UIView
@property (nonatomic, strong)UIButton *button;
@property (nonatomic, strong)UIImageView *imageView;
@property (nonatomic, weak) id<AhoyImageButtonDelegateProtocol> delegate;

- (id) initWithFrame:(CGRect)frame delegate:(id<AhoyImageButtonDelegateProtocol>)delegate text:(NSString *)text fontSize:(float)fontsize fontColor:(UIColor *)fontColor imageName:(NSString *)imageName;
- (void)setFrame:(CGRect)frame;

@end