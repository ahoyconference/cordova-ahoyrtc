//
//  AhoyCordova.m
//  AhoyCordova
//
//  Created by kapejod on 05.02.15.
//
//

#import "AhoyCordova.h"

@implementation AhoyCordova

- (void) pluginInitialize{
    NSLog(@"AhoyCordova.pluginInitialize");
    self.sdk = [AhoySDK sharedInstance];
}

- (void) init:(CDVInvokedUrlCommand *)command {
    CDVPluginResult *pluginResult = nil;

    if ([command.arguments count] >= 1) {
        self.apiKey = [command.arguments objectAtIndex:0];
    }
    if ([command.arguments count] == 2) {
        self.apiUrl = [command.arguments objectAtIndex:1];
    }
    if (!self.apiUrl || ([self.apiUrl length] <10)) {
	self.apiUrl = @"wss://api.ahoyrtc.com/user.ws/";
    }

    if (!self.apiKey) {
        pluginResult = [ CDVPluginResult
                        resultWithStatus    :  CDVCommandStatus_ERROR
                        messageAsString : @"Missing mandatory parameters"
        ];
        return;
    }

    void (^_callback)(BOOL success, NSDictionary *result);
    _callback = ^(BOOL success, NSDictionary *result) {
        CDVPluginResult *pluginResult = [ CDVPluginResult
                    resultWithStatus    :  CDVCommandStatus_OK
                    messageAsDictionary : result
        ];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    };

    [self.commandDelegate runInBackground:^{
	[self.sdk setApiKey:self.apiKey apiUrl:self.apiUrl];
        [self.sdk setViewController:self.viewController];
        [self.sdk initializeWithCallback:_callback];
    }];
}

- (void) login:(CDVInvokedUrlCommand *)command {
    if ([command.arguments count] >= 1) {
        self.email = [command.arguments objectAtIndex:0];
    }
    if ([command.arguments count] == 2) {
        self.password = [command.arguments objectAtIndex:1];
    }
    if (!self.email || !self.password) {
        CDVPluginResult *pluginResult = [ CDVPluginResult
                        resultWithStatus    :  CDVCommandStatus_ERROR
                        messageAsString : @"Missing mandatory parameters"
                        ];
	[self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
	void (^_callback)(BOOL success, NSDictionary *result);
	
	_callback = ^(BOOL success, NSDictionary *result) {
    	    CDVPluginResult *pluginResult;
	    if (success) {
    		pluginResult = [ CDVPluginResult
                        resultWithStatus    :  CDVCommandStatus_OK
                	messageAsDictionary : result
        	];
	    } else {
    		pluginResult = [ CDVPluginResult
                        resultWithStatus    :  CDVCommandStatus_ERROR
                	messageAsDictionary : result
        	];
	    }
	    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
	};
	[self.commandDelegate runInBackground:^{
	    [self.sdk loginWithEmail:self.email password:self.password callback:_callback];
	}];
    }
}

- (void) logout:(CDVInvokedUrlCommand *)command {
    void (^_callback)(BOOL success, NSDictionary *result);
    _callback = ^(BOOL success, NSDictionary *result) {
    	CDVPluginResult *pluginResult = [ CDVPluginResult
                resultWithStatus    :  CDVCommandStatus_OK
        ];
	[self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    };
    [self.commandDelegate runInBackground:^{
        [self.sdk logoutWithCallback:_callback];
    }];
}

- (void) getContactList:(CDVInvokedUrlCommand *)command {
    void (^_callback)(BOOL success, NSDictionary *result);

    _callback = ^(BOOL success, NSDictionary *result) {
	CDVPluginResult *pluginResult = nil;
	if (success) {
    	    pluginResult = [ CDVPluginResult
                resultWithStatus    :  CDVCommandStatus_OK
                messageAsDictionary: [result objectForKey:@"contacts"]
            ];
        } else {
    	    pluginResult = [ CDVPluginResult
                resultWithStatus    :  CDVCommandStatus_ERROR
            ];
        }
	[self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    };

    [self.commandDelegate runInBackground:^{
	[self.sdk getContactListWithCallback:_callback];
    }];
}

- (void) callContact:(CDVInvokedUrlCommand *)command {
    NSString *uuid = nil;
    BOOL audio = YES;
    BOOL video = YES;
    if ([command.arguments count] >= 1) {
        uuid = [command.arguments objectAtIndex:0];
    }
    if ([command.arguments count] >= 2) {
        audio = [command.arguments objectAtIndex:1];
    }
    if ([command.arguments count] >= 3) {
        video = [command.arguments objectAtIndex:2];
    }
    if (!uuid) {
        CDVPluginResult *pluginResult = [ CDVPluginResult
                                         resultWithStatus    :  CDVCommandStatus_ERROR
                                         messageAsString:@"missing_mandatory_parameter"
                                         ];
        
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
        void (^_callback)(BOOL success, NSDictionary *result);
        
        _callback = ^(BOOL success, NSDictionary *result) {
            CDVPluginResult *pluginResult;
            if (success) {
                pluginResult = [ CDVPluginResult
                                resultWithStatus    :  CDVCommandStatus_OK
                                messageAsDictionary:result
                                ];
            } else {
                pluginResult = [ CDVPluginResult
                                resultWithStatus    :  CDVCommandStatus_ERROR
                                messageAsDictionary:result
                                ];
                
            }
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];

        };
        [self.sdk callContactByUuid:uuid presentingViewController:self.viewController callback:_callback];
    }
}

- (void) getConferenceList:(CDVInvokedUrlCommand *)command {
    void (^_callback)(BOOL success, NSDictionary *result);

    _callback = ^(BOOL success, NSDictionary *result) {
	CDVPluginResult *pluginResult = nil;
	if (success) {
    	    pluginResult = [ CDVPluginResult
                resultWithStatus    :  CDVCommandStatus_OK
                messageAsDictionary: [result objectForKey:@"conferences"]
            ];
        } else {
    	    pluginResult = [ CDVPluginResult
                resultWithStatus    :  CDVCommandStatus_ERROR
            ];
        }
	[self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    };

    [self.commandDelegate runInBackground:^{
	[self.sdk getConferenceListWithCallback:_callback];
    }];
}

- (void) getConferenceInfo:(CDVInvokedUrlCommand *)command {
    NSString *uuid = nil;
    if ([command.arguments count] == 1) {
        uuid = [command.arguments objectAtIndex:0];
    }
    if (!uuid) {
        CDVPluginResult *pluginResult = [ CDVPluginResult
                                         resultWithStatus    :  CDVCommandStatus_ERROR
                                         messageAsString:@"missing_mandatory_parameter"
                                         ];
        
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
	void (^_callback)(BOOL success, NSDictionary *result);

	_callback = ^(BOOL success, NSDictionary *result) {
	    CDVPluginResult *pluginResult = nil;
	    if (success) {
    		pluginResult = [ CDVPluginResult
            	    resultWithStatus    :  CDVCommandStatus_OK
            	    messageAsDictionary: [result objectForKey:@"conference"]
        	];
    	    } else {
    	        pluginResult = [ CDVPluginResult
            	    resultWithStatus    :  CDVCommandStatus_ERROR
        	];
    	    }
	    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
	};

	[self.commandDelegate runInBackground:^{
	    [self.sdk getConferenceInfo:uuid callback:_callback];
	}];
    }
}


- (void) joinConference:(CDVInvokedUrlCommand *)command {
    NSString *uuid = nil;
    if ([command.arguments count] == 1) {
        uuid = [command.arguments objectAtIndex:0];
    }
    if (!uuid) {
        CDVPluginResult *pluginResult = [ CDVPluginResult
                                         resultWithStatus    :  CDVCommandStatus_ERROR
                                         messageAsString:@"missing_mandatory_parameter"
                                         ];
        
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
        void (^_callback)(BOOL success, NSDictionary *result);
        
        _callback = ^(BOOL success, NSDictionary *result) {
            CDVPluginResult *pluginResult;
            if (success) {
                pluginResult = [ CDVPluginResult
                                resultWithStatus    :  CDVCommandStatus_OK
                                messageAsDictionary:result
                                ];
            } else {
                pluginResult = [ CDVPluginResult
                                resultWithStatus    :  CDVCommandStatus_ERROR
                                messageAsDictionary:result
                                ];
                
            }
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];

        };
        [self.sdk joinConference:uuid presentingViewController:self.viewController callback:_callback];
    }
}

- (void) joinConferenceRoomOnServer:(CDVInvokedUrlCommand *)command {
    NSString *room = nil;
    NSString *url = nil;
    NSString *name = nil;
    NSString *password = @"";
    if ([command.arguments count] >= 3) {
        room = [command.arguments objectAtIndex:0];
        url = [command.arguments objectAtIndex:1];
        name = [command.arguments objectAtIndex:2];
    }
    if ([command.arguments count] == 4) {
        password = [command.arguments objectAtIndex:3];
    }
    if (!room || !name || !url || !password) {
        CDVPluginResult *pluginResult = [ CDVPluginResult
                                         resultWithStatus    :  CDVCommandStatus_ERROR
                                         messageAsString:@"missing_mandatory_parameter"
                                         ];
        
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
        void (^_callback)(BOOL success, NSDictionary *result);
        
        _callback = ^(BOOL success, NSDictionary *result) {
            CDVPluginResult *pluginResult;
            if (success) {
                pluginResult = [ CDVPluginResult
                                resultWithStatus    :  CDVCommandStatus_OK
                                messageAsDictionary:result
                                ];
            } else {
                pluginResult = [ CDVPluginResult
                                resultWithStatus    :  CDVCommandStatus_ERROR
                                messageAsDictionary:result
                                ];
                
            }
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];

        };
        [self.sdk joinConferenceRoom:room name:name password:password at:url presentingViewController:self.viewController callback:_callback];
    }
}

- (void) createConferenceRoomOnServer:(CDVInvokedUrlCommand *)command {
    NSString *room = nil;
    NSString *url = nil;
    NSString *password = @"";
    NSString *moderatorPassword = @"";
    if ([command.arguments count] >= 2) {
        room = [command.arguments objectAtIndex:0];
        url = [command.arguments objectAtIndex:1];
    }
    if ([command.arguments count] >= 3) {
        password = [command.arguments objectAtIndex:2];
    }
    if ([command.arguments count] == 4) {
        moderatorPassword = [command.arguments objectAtIndex:3];
    }
    if (!room || !url || !password || !moderatorPassword) {
        CDVPluginResult *pluginResult = [ CDVPluginResult
                                         resultWithStatus    :  CDVCommandStatus_ERROR
                                         messageAsString:@"missing_mandatory_parameter"
                                         ];
        
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    } else {
        void (^_callback)(BOOL success, NSDictionary *result);
        
        _callback = ^(BOOL success, NSDictionary *result) {
            CDVPluginResult *pluginResult;
            if (success) {
                pluginResult = [ CDVPluginResult
                                resultWithStatus    :  CDVCommandStatus_OK
                                messageAsDictionary:result
                                ];
            } else {
                pluginResult = [ CDVPluginResult
                                resultWithStatus    :  CDVCommandStatus_ERROR
                                messageAsDictionary:result
                                ];
                
            }
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];

        };
        [self.sdk createConferenceRoom:room password:password moderatorPassword:moderatorPassword at:url callback:_callback];
    }
}

- (void) setSettings:(CDVInvokedUrlCommand *)command {
    NSDictionary *settings = nil;

    if ([command.arguments count] >= 1) {
        NSData *jsonData = [[command.arguments objectAtIndex:0] dataUsingEncoding:NSUTF8StringEncoding];
        NSError *e;
        settings = (NSDictionary *)[NSJSONSerialization JSONObjectWithData:jsonData options:nil error:&e];
    }
    if (settings) {
	[self.commandDelegate runInBackground:^{
	    NSDictionary *updatedSettings = [self.sdk setSettings:settings];
	    CDVPluginResult *pluginResult = [ CDVPluginResult
		resultWithStatus    :  CDVCommandStatus_OK
		messageAsDictionary :  updatedSettings
	    ];
	    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
	}];
    } else {
        CDVPluginResult *pluginResult = [ CDVPluginResult
    	    resultWithStatus    :  CDVCommandStatus_ERROR
    	    messageAsString : @"Missing mandatory parameter"
        ];
	[self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    }
}

- (void) getSettings:(CDVInvokedUrlCommand *)command {
    [self.commandDelegate runInBackground:^{
	CDVPluginResult *pluginResult = nil;
	NSDictionary *settings = [self.sdk getSettings];
	if (settings) {
	    pluginResult = [ CDVPluginResult
		resultWithStatus    :  CDVCommandStatus_OK
		messageAsDictionary: settings
	    ];
	} else {
    	    pluginResult = [ CDVPluginResult
    	        resultWithStatus    :  CDVCommandStatus_ERROR
    	    ];
	}
	[self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    }];
}

- (void) setPushToken:(CDVInvokedUrlCommand *)command {
    CDVPluginResult *pluginResult = nil;
    NSString *tokenType;
    NSString *token;

    if ([command.arguments count] >= 2) {
        tokenType = [command.arguments objectAtIndex:0];
        token = [command.arguments objectAtIndex:1];
	if ([tokenType isEqualToString:@"apn"]) {
	    [self.sdk setApnToken:token];
	} else if ([tokenType isEqualToString:@"apk"]) {
	    [self.sdk setPushKitToken:token];
	} else {
    	    pluginResult = [ CDVPluginResult
    		resultWithStatus    :  CDVCommandStatus_ERROR
    	        messageAsString : @"invalid token type"
    	    ];
	}
        pluginResult = [ CDVPluginResult
    	    resultWithStatus    :  CDVCommandStatus_OK
        ];
    } else {
        pluginResult = [ CDVPluginResult
    	    resultWithStatus    :  CDVCommandStatus_ERROR
    	    messageAsString : @"Missing mandatory parameter"
        ];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

@end
