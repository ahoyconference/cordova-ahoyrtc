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
        		public void callback(Boolean success, JSONObject result) {
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
        		public void callback(Boolean success, JSONObject result) {
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
        }
        return false;
    }
    
}
