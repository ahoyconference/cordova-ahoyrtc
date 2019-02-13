module.exports = {
	calls: {},
	init: function(successCallback, errorCallback, apiKey, apiUrl) {
	    var params = [];
	    if (apiKey != undefined) params.push(apiKey);
	    if (apiUrl != undefined) params.push(apiUrl);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "init", params);
	},
	setApiCredentials: function(successCallback, errorCallback, apiKey, apiUrl) {
	    var params = [];
	    if (apiKey != undefined) params.push(apiKey);
	    if (apiUrl != undefined) params.push(apiUrl);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "setApiCredentials", params);
	},
	registerCallListener: function(successCallback, errorCallback, eventCallback) {
    	    cordova.exec(
    		function(event) {
    		    if (event.event == "NewIncomingCall") {
    			if (event.call && event.call.uuid) {
    			    var call = {
    				uuid: event.call.uuid,
    				from: event.call.from,
    				audio: (event.call.audio == "YES")?true:false,
    				video: (event.call.video == "YES")?true:false,
    				answer: function(answerSuccessCallback, answerErrorCallback, audio, video, activityName) {
    				    var params = [ event.call.uuid ];
    				    if (audio != undefined) { params.push(audio) } else { params.push(true) };
    				    if (video != undefined) { params.push(video) } else { params.push(true) };
    				    if (activityName != undefined) params.push(activityName);
    				    cordova.exec(answerSuccessCallback, answerErrorCallback, "AhoyRTC", "answerIncomingCall", params);
    				},
    				reject: function(rejectSuccessCallback, rejectErrorCallback, reason) {
    				    var params = [ event.call.uuid ];
    				    if (reason != undefined) params.push(reason);
    				    cordova.exec(rejectSuccessCallback, rejectErrorCallback, "AhoyRTC", "rejectIncomingCall", params);
    				    delete AhoyRTC.calls[event.call.uuid];
    				}
    			    };
    			    AhoyRTC.calls[call.uuid] = call;
    			    eventCallback(event.event, AhoyRTC.calls[event.call.uuid]);
    			}
    		    } else if (event.event == "IncomingCallCanceled") {
    			if (event.call && event.call.uuid && (AhoyRTC.calls[event.call.uuid] != undefined)) {
    			    AhoyRTC.calls[event.call.uuid].answer = null;
    			    AhoyRTC.calls[event.call.uuid].reject = null;
    			    eventCallback(event.event, AhoyRTC.calls[event.call.uuid]);
    			    delete AhoyRTC.calls[event.call.uuid];
    			}
    		    } else if (event.event == "CallStatus") {
    			if (event.data) {
    			    eventCallback(event.event, event.data);
    			}
    		    }
    		},
		errorCallback, "AhoyRTC", "registerCallListener", []
	    );
	    successCallback();
	},
	unregisterCallListener: function(successCallback, errorCallback) {
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "unregisterCallListener", []);
	},
	login: function(successCallback, errorCallback, email, password) {
	    var params = [];
	    if (email != undefined) params.push(email);
	    if (password != undefined) params.push(password);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "login", params);
	},
	logout: function(successCallback, errorCallback) {
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "logout", []);
	},
	getContactList: function(successCallback, errorCallback) {
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "getContactList", []);
	},
	getContactInfo: function(successCallback, errorCallback, uuid) {
	    var params = [];
	    if (uuid != undefined) params.push(uuid);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "getContactInfo", params);
	},
	callContact: function(successCallback, errorCallback, uuid, audio, video) {
	    var params = [];
	    if (uuid != undefined) params.push(uuid);
	    if (audio != undefined) params.push(audio);
	    if (video != undefined) params.push(video);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "callContact", params);
	},
	callAddress: function(successCallback, errorCallback, address, metaData, customViewController, audio, video) {
	    var params = [];
	    if (address != undefined) params.push(address);
	    if (metaData != undefined) {
		params.push(JSON.stringify(metaData));
	    } else {
		params.push(JSON.stringify({}));
	    }
	    if (customViewController != undefined) {
		params.push(customViewController);
	    } else {
		params.push("AhoyCallViewController");
	    }
	    if (audio != undefined) params.push(audio);
	    if (video != undefined) params.push(video);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "callAddress", params);
	},
	getConferenceList: function(successCallback, errorCallback) {
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "getConferenceList", []);
	},
	getConferenceInfo: function(successCallback, errorCallback, uuid) {
	    var params = [];
	    if (uuid != undefined) params.push(uuid);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "getConferenceInfo", params);
	},
	joinConference: function(successCallback, errorCallback, uuid) {
	    var params = [];
	    if (uuid != undefined) params.push(uuid);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "joinConference", params);
	},
	joinConferenceRoomOnServer: function(successCallback, errorCallback, room, url, name, password) {
	    var params = [];
	    if (room != undefined) params.push(room);
	    if (url != undefined) params.push(url);
	    if (name != undefined) params.push(name);
	    if (password != undefined) params.push(password);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "joinConferenceRoomOnServer", params);
	},
	createConferenceRoomOnServer: function(successCallback, errorCallback, room, url, password, moderatorPassword) {
	    var params = [];
	    if (room != undefined) params.push(room);
	    if (url != undefined) params.push(url);
	    if (password != undefined) params.push(password);
	    if (moderatorPassword != undefined) params.push(moderatorPassword);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "createConferenceRoomOnServer", params);
	},
	joinConferenceOnServerWithInvitation: function(successCallback, errorCallback, url, invitation) {
	    var params = [];
	    if (url != undefined) params.push(url);
	    if (invitation != undefined) params.push(invitation);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "joinConferenceOnServerWithInvitation", params);
	},
	getSettings: function(successCallback, errorCallback) {
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "getSettings", []);
	},
	setSettings: function(successCallback, errorCallback, settings) {
	    var params = [];
	    if (settings != undefined) params.push(JSON.stringify(settings));
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "setSettings", params);
	},
	setPresenceStatus: function(successCallback, errorCallback, status) {
	    var params = [];
	    if ((status == "available") || (status == "dnd")) {
		params.push(status);
    		cordova.exec(successCallback, errorCallback, "AhoyRTC", "setPresenceStatus", params);
	    } else {
		errorCallback({error:"invalid_presence_status"});
	    }
	},
	getPresenceStatus: function(successCallback, errorCallback) {
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "getPresenceStatus", []);
	},
	shutdown: function(successCallback, errorCallback) {
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "shutdown", []);
	},
	sipRegister: function(successCallback, errorCallback, options) {
	    var params = [];
	    if (!options.username) {
		return errorCallback({ error: "missing_mandatory_parameter" });
	    }
	    params.push(options.username);
	    if (!options.password) {
		return errorCallback({ error: "missing_mandatory_parameter" });
	    }
	    params.push(options.password);
	    if (!options.registrar) {
		return errorCallback({ error: "missing_mandatory_parameter" });
	    }
	    if (!options.registrar.hostname) {
		return errorCallback({ error: "missing_mandatory_parameter" });
	    }
	    params.push(options.registrar.hostname);
	    if (options.registrar.port) {
		params.push(options.registrar.port);
	    } else {
		params.push(5060);
	    }
	    if (options.proxyUrl) {
		params.push(options.proxyUrl);
	    } else {
		params.push("");
	    }
	    if (options.useragent) {
		params.push(options.useragent);
	    } else {
		params.push("AhoyRTC Cordova Plugin");
	    }
	    if (options.refresh) {
		params.push(options.refresh);
	    } else {
		params.push(300);
	    }
    	    cordova.exec(
    		function(result) {
    		    successCallback({
    			registrationId: result.registrationId,
    			isRegistered: true,
    			unregister: function(unregisterSuccessCallback, unregisterErrorCallback) {
    			    var self = this;
    			    if (self.isRegistered) {
    				AhoyRTC.sipUnregister(
    				    function() {
    					self.isRegistered = false;
    					if (unregisterSuccessCallback != null) unregisterSuccessCallback();
    				    },
    				    unregisterErrorCallback, { registrationId: self.registrationId }
    				);
    			    }
    			}
    		    });
    		},
    		function(result) { 
    		    errorCallback(result.reason);
    		},
    		"AhoyRTC", "sipRegister", params
    	    );
	},
	sipUnregister: function(successCallback, errorCallback, options) {
	    var params = [];
	    if (!options.registrationId) {
		return errorCallback({ error: "missing_mandatory_parameter" });
	    }
	    params.push(options.registrationId);
    	    cordova.exec(
    		successCallback,
    		errorCallback,
    		"AhoyRTC", "sipUnregister", params
    	    );
	}
}
