module.exports = {
	init: function(successCallback, errorCallback, apiKey, apiUrl) {
	    var params = [];
	    if (apiKey != undefined) params.push(apiKey);
	    if (apiUrl != undefined) params.push(apiUrl);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "init", params);
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
	getSettings: function(successCallback, errorCallback) {
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "getSettings", []);
	},
	setSettings: function(successCallback, errorCallback, settings) {
	    var params = [];
	    if (settings != undefined) params.push(JSON.stringify(settings));
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "setSettings", params);
	},
	setPushToken: function(successCallback, errorCallback, tokenType, token) {
	    var params = [];
	    if (tokenType != undefined) params.push(tokenType);
	    if (token != undefined) params.push(token);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "setPushToken", params);
	}
}
