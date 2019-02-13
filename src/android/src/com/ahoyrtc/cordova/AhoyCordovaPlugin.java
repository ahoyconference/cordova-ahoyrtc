package com.ahoyrtc.cordova;

import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaWebView;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;

import android.util.Log;
import java.util.UUID;
import android.app.Activity;
import android.content.Context;
import android.os.PowerManager;
import android.media.AudioManager;
import java.util.Set;
import java.util.HashMap;
import java.util.ListIterator;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.ahoyrtc.sdk.AhoySdk;
import com.ahoyrtc.sdk.AhoySipRegistration;
import com.ahoyrtc.sdk.AhoySession;

public class AhoyCordovaPlugin extends CordovaPlugin {
    private AhoySdk ahoySdk;

    @Override
    public void initialize(CordovaInterface cordova, CordovaWebView webView) {
	super.initialize(cordova, webView);
	ahoySdk = AhoySdk.getSharedInstance(cordova.getActivity().getApplicationContext());
    }

    @Override
    public boolean execute(String action, JSONArray args, final CallbackContext callbackContext) throws JSONException {
        if (action.equals("init")) {
	    if (args.length() >= 1) {
		String apiKey = args.getString(0);
    	        ahoySdk.setApiKey(apiKey);
	    }
	    if (args.length() >= 2) {
		String apiUrl = args.getString(1);
    	        ahoySdk.setApiUrl(apiUrl);
    	    }
	    cordova.getThreadPool().execute(new Runnable() {
        	@Override
    		public void run() {
		    ahoySdk.initializeWithCallback(new AhoySdk.AhoySdkInterface() {
        		@Override
        		public void callback(boolean success, JSONObject result) {
        		    PluginResult pluginResult;
			    if (success) {
				pluginResult = new PluginResult(PluginResult.Status.OK, result); 
			    } else {
				pluginResult = new PluginResult(PluginResult.Status.ERROR, result); 
			    }
			    callbackContext.sendPluginResult(pluginResult);
        		}
    		    });
        	}
    	    });
            return true;
        } else if (action.equals("setApiCredentials")) {
	    if (args.length() >= 1) {
		String apiUrl = args.getString(0);
    	        ahoySdk.setApiUrl(apiUrl);
	    }
	    if (args.length() >= 2) {
		String apiKey = args.getString(1);
    	        ahoySdk.setApiKey(apiKey);
    	    }
	    PluginResult pluginResult = new PluginResult(PluginResult.Status.OK); 
	    callbackContext.sendPluginResult(pluginResult);
    	    return true;
        } else if (action.equals("callAddress")) {
    	    String address = null;
    	    JSONObject metaData = null;
    	    String activityName = null;
    	    boolean audio = false;
    	    boolean video = false;
	    if (args.length() >= 1) {
		address = args.getString(0);
	    }
	    if (args.length() >= 2) {
		metaData = new JSONObject(args.getString(1));
	    }
	    if (args.length() >= 3) {
		activityName = args.getString(2);
		if ((activityName.length() == 0) || activityName.equalsIgnoreCase("AhoyCallViewController")) {
		    activityName = "com.ahoyrtc.sdk.AhoyVideoCallActivity";
		} else if (activityName.contains(".") == false) {
		    activityName = this.cordova.getActivity().getPackageName() + "." + activityName;
		}
	    }
	    if (args.length() >= 4) {
		audio = args.getBoolean(3);
	    }
	    if (args.length() >= 5) {
		video = args.getBoolean(4);
	    }
	    final String finalAddress = address;
	    final boolean finalAudio = audio;
	    final boolean finalVideo = video;
	    final JSONObject finalMetaData = metaData;
	    final String finalActivityName = activityName;
	    cordova.getThreadPool().execute(new Runnable() {
        	@Override
        	public void run() {
		    ahoySdk.callAddress(finalAddress, finalAudio, finalVideo, finalMetaData, finalActivityName, new AhoySdk.AhoySdkInterface() {
        		@Override
        		public void callback(boolean success, JSONObject result) {
        		    PluginResult pluginResult;
			    if (success) {
				pluginResult = new PluginResult(PluginResult.Status.OK, result); 
			    } else {
				pluginResult = new PluginResult(PluginResult.Status.ERROR, result); 
			    }
			    callbackContext.sendPluginResult(pluginResult);
        		}
    		    });
        	}
    	    });
    	    return true;
        } else if (action.equals("shutdown")) {
	    PluginResult pluginResult = new PluginResult(PluginResult.Status.OK); 
	    callbackContext.sendPluginResult(pluginResult);
	    ahoySdk.shutdown();
    	    return true;
        } else if (action.equals("registerCallListener")) {
	    ahoySdk.registerCallListener(new AhoySdk.AhoyCallListenerInterface() {
		@Override
		public void incomingCallReceived(AhoySession session) {
    		    JSONObject callEvent = new JSONObject();
    		    JSONObject call = new JSONObject();
    		    try {
    			call.put("uuid", session.getUuid());
    			call.put("audio", session.isAudioEnabled()?"YES":"NO");
    			call.put("video", session.isVideoEnabled()?"YES":"NO");
			callEvent.put("event", "NewIncomingCall");
			callEvent.put("call", call);
		    } catch (JSONException je) {
		    }
		    session.acknowledge();
		    PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, callEvent); 
		    pluginResult.setKeepCallback(true);
		    callbackContext.sendPluginResult(pluginResult);
		}

		@Override
		public void incomingCallCanceled(AhoySession session) {
    		    JSONObject callEvent = new JSONObject();
    		    JSONObject call = new JSONObject();
    		    try {
    			call.put("uuid", session.getUuid());
			callEvent.put("event", "IncomingCallCanceled");
			callEvent.put("call", call);
		    } catch (JSONException je) {
		    }
		    PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, callEvent); 
		    pluginResult.setKeepCallback(true);
		    callbackContext.sendPluginResult(pluginResult);
		}
	    });
	    PluginResult pluginResult = new PluginResult(PluginResult.Status.OK); 
	    pluginResult.setKeepCallback(true);
	    callbackContext.sendPluginResult(pluginResult);
    	    return true;
        } else if (action.equals("unregisterCallListener")) {
	    PluginResult pluginResult = new PluginResult(PluginResult.Status.OK); 
	    callbackContext.sendPluginResult(pluginResult);
	    ahoySdk.unregisterCallListener();
    	    return true;
        } else if (action.equals("answerIncomingCall")) {
	    if (args.length() >= 3) {
		boolean isAudioEnabled = args.getBoolean(1);
		boolean isVideoEnabled = args.getBoolean(2);
		String activityName = null;
		if (args.length() > 3) {
		    activityName = args.getString(3);
		}
	        ahoySdk.answerIncomingSessionByUuid(args.getString(0), isAudioEnabled, isVideoEnabled, activityName, new AhoySdk.AhoySdkInterface() {
	    	    @Override
	    	    public void callback(boolean success, JSONObject result) {
	    		PluginResult pluginResult = new PluginResult(PluginResult.Status.OK); 
	    		callbackContext.sendPluginResult(pluginResult);
	    	    }
	        });
	    } else {
    		JSONObject result = new JSONObject();
		result.put("success", false);
		result.put("reason", "missing_mandatory_parameter");
		PluginResult pluginResult = new PluginResult(PluginResult.Status.ERROR, result); 
		callbackContext.sendPluginResult(pluginResult);
	    }
    	    return true;
        } else if (action.equals("rejectIncomingCall")) {
	    if (args.length() >= 1) {
		String reason = "busy";
		if (args.length() > 1) {
		    reason = args.getString(1);
		}
	        ahoySdk.rejectIncomingSessionByUuid(args.getString(0), reason);
	        PluginResult pluginResult = new PluginResult(PluginResult.Status.OK); 
	        callbackContext.sendPluginResult(pluginResult);
	    } else {
    		JSONObject result = new JSONObject();
		result.put("success", false);
		result.put("reason", "missing_mandatory_parameter");
		PluginResult pluginResult = new PluginResult(PluginResult.Status.ERROR, result); 
		callbackContext.sendPluginResult(pluginResult);
	    }
    	    return true;
        } else if (action.equals("sipRegister")) {
    	    try {
		if (args.length() == 7) {
		    String username = args.getString(0);
		    String password = args.getString(1);
		    String registrarHostname = args.getString(2);
		    int registrarPort = args.getInt(3);
		    String proxyUrl= args.getString(4);
		    String useragent = args.getString(5);
		    int refresh = args.getInt(6);
		    ahoySdk.sipRegister(username, password, registrarHostname, registrarPort, proxyUrl, useragent, refresh, new AhoySdk.AhoySipRegistrationInterface() {
			@Override
			public void sipRegistrationDidRegister(AhoySipRegistration registration) {
    			    JSONObject result = new JSONObject();
    			    try {
				result.put("success", true);
				result.put("registrationId", registration.getId());
			    } catch (JSONException je) {
			    }
			    PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, result); 
			    pluginResult.setKeepCallback(true);
			    callbackContext.sendPluginResult(pluginResult);
			}

			@Override
			public void sipRegistrationDidFailToRegister(String reason) {
    			    JSONObject result = new JSONObject();
    			    try {
			        result.put("success", false);
				result.put("reason", reason);
			    } catch (JSONException je) {
			    }
			    PluginResult pluginResult = new PluginResult(PluginResult.Status.ERROR, result); 
			    pluginResult.setKeepCallback(true);
			    callbackContext.sendPluginResult(pluginResult);
			}

			@Override
			public void sipRegistrationDidUnregister(AhoySipRegistration registration) {
			}

			@Override
			public void sipRegistrationDidFailToUnregister(AhoySipRegistration registration, String reason) {
			}
		    });
    		} else {
    		    JSONObject result = new JSONObject();
		    result.put("success", false);
		    result.put("reason", "missing_mandatory_parameter");
		    PluginResult pluginResult = new PluginResult(PluginResult.Status.ERROR, result); 
		    callbackContext.sendPluginResult(pluginResult);
    		}
    	    } catch (JSONException je) {
    		JSONObject result = new JSONObject();
		result.put("success", false);
		result.put("reason", je.toString());
		PluginResult pluginResult = new PluginResult(PluginResult.Status.ERROR, result); 
		callbackContext.sendPluginResult(pluginResult);
    	    }
    	    return true;
        } else if (action.equals("sipUnregister")) {
    	    try {
		if (args.length() == 1) {
		    String registrationId = args.getString(0);
		    ahoySdk.sipUnregister(registrationId, new AhoySdk.AhoySipRegistrationInterface() {
			@Override
			public void sipRegistrationDidRegister(AhoySipRegistration registration) {
			}

			@Override
			public void sipRegistrationDidFailToRegister(String reason) {
			}

			@Override
			public void sipRegistrationDidUnregister(AhoySipRegistration registration) {
    			    JSONObject result = new JSONObject();
    			    try {
			        result.put("success", true);
			    } catch (JSONException je) {
			    }
			    PluginResult pluginResult = new PluginResult(PluginResult.Status.OK, result); 
			    callbackContext.sendPluginResult(pluginResult);
			}

			@Override
			public void sipRegistrationDidFailToUnregister(AhoySipRegistration registration, String reason) {
    			    JSONObject result = new JSONObject();
    			    try {
			        result.put("success", false);
				result.put("reason", reason);
			    } catch (JSONException je) {
			    }
			    PluginResult pluginResult = new PluginResult(PluginResult.Status.ERROR, result); 
			    callbackContext.sendPluginResult(pluginResult);
			}
		    });
    		} else {
    		    JSONObject result = new JSONObject();
		    result.put("success", false);
		    result.put("reason", "missing_mandatory_parameter");
		    PluginResult pluginResult = new PluginResult(PluginResult.Status.ERROR, result); 
		    callbackContext.sendPluginResult(pluginResult);
    		}
    	    } catch (JSONException je) {
    		JSONObject result = new JSONObject();
		result.put("success", false);
		result.put("reason", je.toString());
		PluginResult pluginResult = new PluginResult(PluginResult.Status.ERROR, result); 
		callbackContext.sendPluginResult(pluginResult);
    	    }
    	    return true;
        }
        return false;
    }
    
}
