//
//  AhoyCordova.h
//  AhoyCordova
//
//  Created by kapejod on 05.02.15.
//
//
#import "AhoySDK.h"
#import <Cordova/CDV.h>

@interface AhoyCordova : CDVPlugin
@property (strong, nonatomic) AhoySDK *sdk;
@property (strong, nonatomic) NSString *apiKey;
@property (strong, nonatomic) NSString *apiUrl;
@property (strong, nonatomic) NSString *email;
@property (strong, nonatomic) NSString *password;

- (void) pluginInitialize;
- (void) init:(CDVInvokedUrlCommand *)command;
- (void) login:(CDVInvokedUrlCommand *)command;
- (void) logout:(CDVInvokedUrlCommand *)command;
- (void) getContactList:(CDVInvokedUrlCommand *)command;
- (void) getConferenceList:(CDVInvokedUrlCommand *)command;
- (void) getConferenceInfo:(CDVInvokedUrlCommand *)command;
- (void) joinConference:(CDVInvokedUrlCommand *)command;
- (void) joinConferenceRoomOnServer:(CDVInvokedUrlCommand *)command;
- (void) createConferenceRoomOnServer:(CDVInvokedUrlCommand *)command;
- (void) getSettings:(CDVInvokedUrlCommand *)command;
- (void) setSettings:(CDVInvokedUrlCommand *)command;
- (void) setPushToken:(CDVInvokedUrlCommand *)command;
@end
