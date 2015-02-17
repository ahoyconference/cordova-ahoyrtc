module.exports = {
	init: function(successCallback, errorCallback, apiKey, apiUrl) {
	    var params = [];
	    if (apiKey) params.push(apiKey);
	    if (apiUrl) params.push(apiUrl);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "init", params);
	},
	login: function(successCallback, errorCallback, email, password) {
	    var params = [];
	    if (email) params.push(email);
	    if (password) params.push(password);
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
	    if (uuid) params.push(uuid);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "getConferenceInfo", params);
	},
	joinConference: function(successCallback, errorCallback, uuid) {
	    var params = [];
	    if (uuid) params.push(uuid);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "joinConference", params);
	},
	joinConferenceRoomOnServer: function(successCallback, errorCallback, room, url, name, password) {
	    var params = [];
	    if (room) params.push(room);
	    if (url) params.push(url);
	    if (name) params.push(name);
	    if (password) params.push(password);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "joinConferenceRoomOnServer", params);
	},
	getSettings: function(successCallback, errorCallback) {
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "getSettings", []);
	},
	setSettings: function(successCallback, errorCallback, settings) {
	    var params = [];
	    if (settings) params.push(JSON.stringify(settings));
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "setSettings", params);
	},
	setPushToken: function(successCallback, errorCallback, tokenType, token) {
	    var params = [];
	    if (tokenType) params.push(tokenType);
	    if (token) params.push(token);
    	    cordova.exec(successCallback, errorCallback, "AhoyRTC", "setPushToken", params);
	}
}
