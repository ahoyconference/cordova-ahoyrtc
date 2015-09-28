# cordova-ahoyrtc
  [Cordova](http://cordova.apache.org) plugin for AhoyRTC
  (currently only iOS is supported)

## Installation

Add the plugin to your existing cordova app with:

    $ cordova plugin add https://github.com/ahoyconference/cordova-ahoyrtc.git

The inner workings of the AhoyRTC plugin changed recently (from a statically linked library and a resource bundle) to an iOS framework (AhoyKit). Make sure that your XCode project embedds the AhoyKit framework ("General" ... "Embedded Binaries" ).

Because some dependencies (included with the AhoyRTC plugin) do not support bitcode (yet), you will need to disable bitcode support for your XCode project when you are using XCode 7+("Build Settings" ... "Build Options" ... "Enable Bitcode").


## Examples

### Get and modify settings (stored on the device)

```js
 // wait for the deviceready event to ensure that the plugin has been loaded
 document.addEventListener('deviceready', function() {
   AhoyRTC.getSettings(
     function(settings) {
       // try to enable HD video
       settings.video.hd = true;
       AhoyRTC.setSettings(
         function(updatedSettings) {
           if (updatedSettings.video.hd) {
             // you will now send your own video in HD
           } else {
             // could not enable HD, probably your device is too slow
           }
         },
         function(error) {
         },
         settings
       );
     },
     function(error) {
     }
   );
 }, false);
```

### Standalone ahoyconference server, join a conference room

```js
 // wait for the deviceready event to ensure that the plugin has been loaded
 document.addEventListener('deviceready', function() {
   AhoyRTC.joinConferenceRoomOnServer(
     function() {
       console.log("you have left the conference.");
     },
     function(error) {
       console.log("there was a problem joining the conference");
       console.log(error);
     },
     "myRoom",
     "wss://myserver.example.com",
     "myName",
     "optional password"
   );
 }, false);
````

### AhoyUC cloud, initialization

```js
 // wait for the deviceready event to ensure that the plugin has been loaded
 document.addEventListener('deviceready', function() {
   AhoyRTC.init(
     function(user) {
        if (user) {
          // the user is still logged in
        } else {
          // the user is not logged in
        }
     },
     function(error) {
       console.log(error);
      },
      "put your api key in here",
      "wss://uc.ahoyrtc.com/api/"	// optional API url, replace this when you are using a private AhoyUC cloud
    );
 }, false);
```

### AhoyUC cloud, login and list all conference rooms

```js
 AhoyRTC.login(
   function(user) {
     // user logged in
     AhoyRTC.getConferenceList(
       function(conferences) {
         console.log(conferences);
       },
       function(error) {
         console.log("getConferenceList error: "+error);
       }
     );
   },
   function(error) {
     console.log("login failed.");
   },
   "email@example.com",
   "password123"
 );
```

### AhoyUC cloud, get participant information for a conference room (by its uuid, obtained from the conference list)

```js
 AhoyRTC.getConferenceInfo(
   function(conference) {
     console.log(conference);
   },
   function(error) {
     console.log(error);
   },
   "e984bce2-6a5f-4003-8d31-0f95dca0be2a"
 );
```

### AhoyUC cloud, join a conference room (by its uuid, obtained from the conference list)

```js
 AhoyRTC.joinConference(
   function() {
     console.log("you have left the conference.");
   },
   function(error) {
     console.log("there was a problem joining the conference");
     console.log(error);
   },
   "e984bce2-6a5f-4003-8d31-0f95dca0be2a"
 );
```

### AhoyUC cloud, login, list all contacts and call the first contact

```js
 AhoyRTC.login(
   function(user) {
     // user logged in
     AhoyRTC.getContactList(
       function(contacts) {
         console.log(contacts);
         AhoyRTC.callContact(
           function(result) {
           },
           function(error) {
           },
           contacts[0].uuid,
           true,	// audio
           true		// video
	 );
       },
       function(error) {
         console.log("getContactList error: "+error);
       }
     );
   },
   function(error) {
     console.log("login failed.");
   },
   "email@example.com",
   "password123"
 );
```

### AhoyUC cloud, handle incoming call in JavaScript
```js
    AhoyRTC.registerCallListener(
	function() {
	    console.log("registered incoming call listener");
	},
	function(error) {
	    console.log("error registering incoming call listener");
	},
	function(event, call) {
	    if (event == "NewIncomingCall") {
		if (confirm("Answer incoming call?") == true){
		    call.answer(
			function() {
			    console.log("answered incoming call");
			},
			function(error) {
			    console.log(error);
			},
			true,	// enable audio
			true	// enable video
		    );
		} else {
		    call.reject(
			function() {
			    console.log("answered incoming call");
			},
			function(error) {
			    console.log(error);
			},
			"gone fishing..."
		    );
		}
	    } else if (event == "IncomingCallCanceled") {
		console.log("Incoming call canceled: "+JSON.stringify(call));
	    }
	}
    );
```


### AhoyUC cloud, logout

```js
 AhoyRTC.logout(
   function() {
     // logged out
   },
   function(error) {
     console.log("logout failed");
   }
 );
```
