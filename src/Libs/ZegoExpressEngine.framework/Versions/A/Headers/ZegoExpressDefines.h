//
//  ZegoExpressDefines.h
//  ZegoExpressEngine
//
//  Copyright © 2019 Zego. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <AVFoundation/AVFoundation.h>

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
#define ZGView UIView
#define ZGImage UIImage
#elif TARGET_OS_OSX
#import <AppKit/AppKit.h>
#define ZGView NSView
#define ZGImage NSImage
#endif

NS_ASSUME_NONNULL_BEGIN

@protocol ZegoMediaPlayerEventHandler;
@protocol ZegoMediaPlayerVideoHandler;
@protocol ZegoMediaPlayerAudioHandler;

/// Callback for asynchronous destruction completion
///
typedef void(^ZegoDestroyCompletionCallback)(void);

/// Callback for updating stream extra information
///
/// @param errorCode Error code, please refer to the common error code document for details
typedef void(^ZegoPublisherSetStreamExtraInfoCallback)(int errorCode);

/// Callback for add/remove CDN URL
///
/// @param errorCode Error code, please refer to the common error code document for details
typedef void(^ZegoPublisherUpdateCDNURLCallback)(int errorCode);

/// Results of starting a mixer task
///
/// @param errorCode Error code, please refer to the common error code document for details
/// @param extendedData Extended Information
typedef void(^ZegoMixerStartCallback)(int errorCode, NSDictionary * _Nullable extendedData);

/// Results of stoping a mixer task
///
/// @param errorCode Error code, please refer to the common error code document for details
typedef void(^ZegoMixerStopCallback)(int errorCode);

/// Callback for sending broadcast messages
///
/// @param errorCode Error code, please refer to the common error code document for details
/// @param messageID ID of this message
typedef void(^ZegoIMSendBroadcastMessageCallback)(int errorCode, unsigned long long messageID);

/// Callback for sending barrage message
///
/// @param errorCode Error code, please refer to the common error code document for details
/// @param messageID ID of this message
typedef void(^ZegoIMSendBarrageMessageCallback)(int errorCode, NSString *messageID);

/// Callback for sending custom command
///
/// @param errorCode Error code, please refer to the common error code document for details
typedef void(^ZegoIMSendCustomCommandCallback)(int errorCode);

/// Callback for media player loads resources
///
/// @param errorCode Error code, please refer to the common error code document for details
typedef void(^ZegoMediaPlayerLoadResourceCallback)(int errorCode);

/// Callback for media player seek to playback progress
///
/// @param errorCode Error code, please refer to the common error code document for details
typedef void(^ZegoMediaPlayerSeekToCallback)(int errorCode);


/// Application cenario
typedef NS_ENUM(NSUInteger, ZegoScenario) {
    /// General scenario
    ZegoScenarioGeneral = 0,
    /// Communication scenario
    ZegoScenarioCommunication = 1,
    /// Live scenario
    ZegoScenarioLive = 2
};


/// Language
typedef NS_ENUM(NSUInteger, ZegoLanguage) {
    /// English
    ZegoLanguageEnglish = 0,
    /// Chinese
    ZegoLanguageChinese = 1
};


/// Room state
typedef NS_ENUM(NSUInteger, ZegoRoomState) {
    /// Unconnected state, enter this state before logging in and after exiting the room. If there is a steady state abnormality in the process of logging in to the room, such as AppID and AppSign are incorrect, or if the same user name is logged in elsewhere and the local end is KickOut, it will enter this state.
    ZegoRoomStateDisconnected = 0,
    /// The state that the connection is being requested. It will enter this state after successful execution login room function. The display of the application interface is usually performed using this state. If the connection is interrupted due to poor network quality, the SDK will perform an internal retry and will return to the requesting connection status.
    ZegoRoomStateConnecting = 1,
    /// The status that is successfully connected. Entering this status indicates that the login to the room has been successful. The user can receive the callback notification of the user and the stream information in the room.
    ZegoRoomStateConnected = 2
};


/// Publish channel
typedef NS_ENUM(NSUInteger, ZegoPublishChannel) {
    /// Main publish channel
    ZegoPublishChannelMain = 0,
    /// Auxiliary publish channel
    ZegoPublishChannelAux = 1
};


/// Video rendering mode
typedef NS_ENUM(NSUInteger, ZegoViewMode) {
    /// The proportional scaling up, there may be black borders
    ZegoViewModeAspectFit = 0,
    /// The proportional zoom fills the entire View and may be partially cut
    ZegoViewModeAspectFill = 1,
    /// Fill the entire view, the image may be stretched
    ZegoViewModeScaleToFill = 2
};


/// Mirror mode for previewing or playing the  of the stream
typedef NS_ENUM(NSUInteger, ZegoVideoMirrorMode) {
    /// The mirror image only for previewing locally. This mode is used by default.
    ZegoVideoMirrorModeOnlyPreviewMirror = 0,
    /// Both the video previewed locally and the far end playing the stream will see mirror image.
    ZegoVideoMirrorModeBothMirror = 1,
    /// Both the video previewed locally and the far end playing the stream will not see mirror image.
    ZegoVideoMirrorModeNoMirror = 2,
    /// The mirror image only for far end playing the stream.
    ZegoVideoMirrorModeOnlyPublishMirror = 3
};


/// Publish stream status
typedef NS_ENUM(NSUInteger, ZegoPublisherState) {
    /// The state is not published, and it is in this state before publishing the stream. If a steady-state exception occurs in the publish process, such as AppID and AppSign are incorrect, or if other users are already publishing the stream, there will be a failure and enter this state.
    ZegoPublisherStateNoPublish = 0,
    /// The state that it is requesting to publish the stream. After the publish stream interface is successfully called, and the application interface is usually displayed using the state. If the connection is interrupted due to poor network quality, the SDK will perform an internal retry and will return to the requesting state.
    ZegoPublisherStatePublishRequesting = 1,
    /// The state that the stream is being published, entering the state indicates that the stream has been successfully published, and the user can communicate normally.
    ZegoPublisherStatePublishing = 2
};


/// Video Resolution
typedef NS_ENUM(NSUInteger, ZegoVideoConfigPreset) {
    /// Set the resolution to 180x320, the default is 15 fps, the code rate is 300 kbps
    ZegoVideoConfigPreset180P = 0,
    /// Set the resolution to 270x480, the default is 15 fps, the code rate is 400 kbps
    ZegoVideoConfigPreset270P = 1,
    /// Set the resolution to 360x640, the default is 15 fps, the code rate is 600 kbps
    ZegoVideoConfigPreset360P = 2,
    /// Set the resolution to 540x960, the default is 15 fps, the code rate is 1200 kbps
    ZegoVideoConfigPreset540P = 3,
    /// Set the resolution to 720x1280, the default is 15 fps, the code rate is 1500 kbps
    ZegoVideoConfigPreset720P = 4,
    /// Set the resolution to 1080x1920, the default is 15 fps, the code rate is 3000 kbps
    ZegoVideoConfigPreset1080P = 5
};


/// Deprecated
/// @deprecated Deprecated, use ZegoVideoConfigPreset instead
typedef NS_ENUM(NSUInteger, ZegoResolution) {
    /// Deprecated
    ZegoResolution180x320 DEPRECATED_ATTRIBUTE = 0,
    /// Deprecated
    ZegoResolution270x480 DEPRECATED_ATTRIBUTE = 1,
    /// Deprecated
    ZegoResolution360x640 DEPRECATED_ATTRIBUTE = 2,
    /// Deprecated
    ZegoResolution540x960 DEPRECATED_ATTRIBUTE = 3,
    /// Deprecated
    ZegoResolution720x1280 DEPRECATED_ATTRIBUTE = 4,
    /// Deprecated
    ZegoResolution1080x1920 DEPRECATED_ATTRIBUTE = 5
};


/// Deprecated
/// @deprecated Deprecated
typedef NS_ENUM(NSUInteger, ZegoPublisherFirstFrameEvent) {
    /// Deprecated
    ZegoPublisherFirstFrameEventAudioCaptured DEPRECATED_ATTRIBUTE = 0,
    /// Deprecated
    ZegoPublisherFirstFrameEventVideoCaptured DEPRECATED_ATTRIBUTE = 1
};


/// Stream quality level
typedef NS_ENUM(NSUInteger, ZegoStreamQualityLevel) {
    /// Excellent
    ZegoStreamQualityLevelExcellent = 0,
    /// Good
    ZegoStreamQualityLevelGood = 1,
    /// Normal
    ZegoStreamQualityLevelMedium = 2,
    /// Bad
    ZegoStreamQualityLevelBad = 3,
    /// Failed
    ZegoStreamQualityLevelDie = 4
};


/// Audio channel type
typedef NS_ENUM(NSUInteger, ZegoAudioChannel) {
    /// MONO
    ZegoAudioChannelMono = 0,
    /// STEREO
    ZegoAudioChannelStereo = 1
};


/// Audio Codec ID
typedef NS_ENUM(NSUInteger, ZegoAudioCodecID) {
    /// default
    ZegoAudioCodecIDDefault = 0,
    /// Normal
    ZegoAudioCodecIDNormal = 1,
    /// Normal2
    ZegoAudioCodecIDNormal2 = 2,
    /// Normal3
    ZegoAudioCodecIDNormal3 = 3,
    /// Low
    ZegoAudioCodecIDLow = 4,
    /// Low2
    ZegoAudioCodecIDLow2 = 5,
    /// Low3
    ZegoAudioCodecIDLow3 = 6
};


/// Video Codec ID
typedef NS_ENUM(NSUInteger, ZegoVideoCodecID) {
    /// default
    ZegoVideoCodecIDDefault = 0,
    /// Multiple Layer
    ZegoVideoCodecIDMultiLayer = 1,
    /// VP8
    ZegoVideoCodecIDVP8 = 2
};


/// Player video layer
typedef NS_ENUM(NSUInteger, ZegoPlayerVideoLayer) {
    /// The layer to be played depends on the network status
    ZegoPlayerVideoLayerAuto = 0,
    /// Play the base layer (small resolution)
    ZegoPlayerVideoLayerBase = 1,
    /// Play the extend layer (big resolution)
    ZegoPlayerVideoLayerBaseExtend = 2
};


/// Audio echo cancellation mode
typedef NS_ENUM(NSUInteger, ZegoAECMode) {
    /// Aggressive echo cancellation may affect the sound quality slightly, but the echo will be very clean
    ZegoAECModeAggressive = 0,
    /// Moderate echo cancellation, which may slightly affect a little bit of sound, but the residual echo will be less
    ZegoAECModeMedium = 1,
    /// Comfortable echo cancellation, that is, echo cancellation does not affect the sound quality of the sound, and sometimes there may be a little echo, but it will not affect the normal listening.
    ZegoAECModeSoft = 2
};


/// Traffic control property
typedef NS_OPTIONS(NSUInteger, ZegoTrafficControlProperty) {
    /// Basic
    ZegoTrafficControlBasic = 0,
    /// Adaptive FPS
    ZegoTrafficControlAdaptiveFPS = 1,
    /// Adaptive resolution
    ZegoTrafficControlAdaptiveResolution = 1 << 1,
    /// Adaptive Audio bitrate
    ZegoTrafficControlAdaptiveAudioBitrate = 1 << 2
};


/// Video transmission mode when current bitrate is lower than the set minimum bitrate
typedef NS_ENUM(NSUInteger, ZegoTrafficControlMinVideoBitrateMode) {
    /// Stop video transmission when current bitrate is lower than the set minimum bitrate
    ZegoTrafficControlMinVideoBitrateModeNoVideo = 0,
    /// Video is sent at a very low frequency (no more than 2fps) which is lower than the set minimum bitrate
    ZegoTrafficControlMinVideoBitrateModeUltraLowFPS = 1
};


/// Playing stream status
typedef NS_ENUM(NSUInteger, ZegoPlayerState) {
    /// The state of the flow is not played, and it is in this state before the stream is played. If the steady flow anomaly occurs during the playing process, such as AppID and AppSign are incorrect, it will enter this state.
    ZegoPlayerStateNoPlay = 0,
    /// The state that the stream is being requested for playing. After the stream playing interface is successfully called, it will enter the state, and the application interface is usually displayed using this state. If the connection is interrupted due to poor network quality, the SDK will perform an internal retry and will return to the requesting state.
    ZegoPlayerStatePlayRequesting = 1,
    /// The state that the stream is being playing, entering the state indicates that the stream has been successfully played, and the user can communicate normally.
    ZegoPlayerStatePlaying = 2
};


/// Media event when playing
typedef NS_ENUM(NSUInteger, ZegoPlayerMediaEvent) {
    /// Audio stuck event when playing
    ZegoPlayerMediaEventAudioBreakOccur = 0,
    /// Audio stuck event recovery when playing
    ZegoPlayerMediaEventAudioBreakResume = 1,
    /// Video stuck event when playing
    ZegoPlayerMediaEventVideoBreakOccur = 2,
    /// Video stuck event recovery when playing
    ZegoPlayerMediaEventVideoBreakResume = 3
};


/// Deprecated
/// @deprecated Deprecated
typedef NS_ENUM(NSUInteger, ZegoPlayerFirstFrameEvent) {
    /// Deprecated
    ZegoPlayerFirstFrameEventAudioRcv DEPRECATED_ATTRIBUTE = 0,
    /// Deprecated
    ZegoPlayerFirstFrameEventVideoRcv DEPRECATED_ATTRIBUTE = 1,
    /// Deprecated
    ZegoPlayerFirstFrameEventVideoRender DEPRECATED_ATTRIBUTE = 2
};


/// Update type
typedef NS_ENUM(NSUInteger, ZegoUpdateType) {
    /// Add
    ZegoUpdateTypeAdd = 0,
    /// Delete
    ZegoUpdateTypeDelete = 1
};


/// State of CDN relay
typedef NS_ENUM(NSUInteger, ZegoStreamRelayCDNState) {
    /// The state indicates that there is no CDN relay
    ZegoStreamRelayCDNStateNoRelay = 0,
    /// The CDN relay is being requested
    ZegoStreamRelayCDNStateRelayRequesting = 1,
    /// Entering this status indicates that the CDN relay has been successful
    ZegoStreamRelayCDNStateRelaying = 2
};


/// Reason for state of CDN relay changed
typedef NS_ENUM(NSUInteger, ZegoStreamRelayCDNUpdateReason) {
    /// No error
    ZegoStreamRelayCDNUpdateReasonNone = 0,
    /// Server error
    ZegoStreamRelayCDNUpdateReasonServerError = 1,
    /// Handshake error
    ZegoStreamRelayCDNUpdateReasonHandshakeFailed = 2,
    /// Access point error
    ZegoStreamRelayCDNUpdateReasonAccessPointError = 3,
    /// Stream create failure
    ZegoStreamRelayCDNUpdateReasonCreateStreamFailed = 4,
    /// Bad name
    ZegoStreamRelayCDNUpdateReasonBadName = 5,
    /// CDN server actively disconnected
    ZegoStreamRelayCDNUpdateReasonCDNServerDisconnected = 6,
    /// Active disconnect
    ZegoStreamRelayCDNUpdateReasonDisconnected = 7
};


/// Beauty feature
typedef NS_OPTIONS(NSUInteger, ZegoBeautifyFeature) {
    /// No beautifying
    ZegoBeautifyFeatureNone = 0,
    /// Polish
    ZegoBeautifyFeaturePolish = 1 << 0,
    /// Sharpen
    ZegoBeautifyFeatureWhiten = 1 << 1,
    /// Skin whiten
    ZegoBeautifyFeatureSkinWhiten = 1 << 2,
    /// Whiten
    ZegoBeautifyFeatureSharpen = 1 << 3
};


/// Remote device status
typedef NS_ENUM(NSUInteger, ZegoRemoteDeviceState) {
    /// Device on
    ZegoRemoteDeviceStateOpen = 0,
    /// General device error
    ZegoRemoteDeviceStateGenericError = 1,
    /// Invalid device ID
    ZegoRemoteDeviceStateInvalidID = 2,
    /// No permission
    ZegoRemoteDeviceStateNoAuthorization = 3,
    /// Captured frame rate is 0
    ZegoRemoteDeviceStateZeroFPS = 4,
    /// The device is occupied
    ZegoRemoteDeviceStateInUseByOther = 5,
    /// The device is not plugged in or unplugged
    ZegoRemoteDeviceStateUnplugged = 6,
    /// The system needs to be restarted
    ZegoRemoteDeviceStateRebootRequired = 7,
    /// System media services stop, such as under the iOS platform, when the system detects that the current pressure is huge (such as playing a lot of animation), it is possible to disable all media related services.
    ZegoRemoteDeviceStateSystemMediaServicesLost = 8,
    /// Capturing disabled
    ZegoRemoteDeviceStateDisable = 9,
    /// The remote device is muted
    ZegoRemoteDeviceStateMute = 10,
    /// The device is interrupted, such as a phone call interruption, etc.
    ZegoRemoteDeviceStateInterruption = 11,
    /// There are multiple apps at the same time in the foreground, such as the iPad app split screen, the system will prohibit all apps from using the camera.
    ZegoRemoteDeviceStateInBackground = 12,
    /// CDN server actively disconnected
    ZegoRemoteDeviceStateMultiForegroundApp = 13,
    /// The system is under high load pressure and may cause abnormal equipment.
    ZegoRemoteDeviceStateBySystemPressure = 14
};


/// Audio device type
typedef NS_ENUM(NSUInteger, ZegoAudioDeviceType) {
    /// Audio input type
    ZegoAudioDeviceTypeInput = 0,
    /// Audio output type
    ZegoAudioDeviceTypeOutput = 1
};


/// Mix stream content type
typedef NS_ENUM(NSUInteger, ZegoMixerInputContentType) {
    /// Mix stream for audio only
    ZegoMixerInputContentTypeAudio = 0,
    /// Mix stream for both audio and video
    ZegoMixerInputContentTypeVideo = 1
};


/// Capture pipline scale mode
typedef NS_ENUM(NSUInteger, ZegoCapturePipelineScaleMode) {
    /// Zoom immediately after acquisition, default
    ZegoCapturePipelineScaleModePre = 0,
    /// Scaling while encoding
    ZegoCapturePipelineScaleModePost = 1
};


/// Video frame format
typedef NS_ENUM(NSUInteger, ZegoVideoFrameFormat) {
    /// Unknown format, will take platform default
    ZegoVideoFrameFormatUnknown = 0,
    /// I420 (YUV420Planar) format
    ZegoVideoFrameFormatI420 = 1,
    /// NV12 (YUV420SemiPlanar) format
    ZegoVideoFrameFormatNV12 = 2,
    /// NV21 (YUV420SemiPlanar) format
    ZegoVideoFrameFormatNV21 = 3,
    /// BGRA32 format
    ZegoVideoFrameFormatBGRA32 = 4,
    /// RGBA32 format
    ZegoVideoFrameFormatRGBA32 = 5,
    /// ARGB32 format
    ZegoVideoFrameFormatARGB32 = 6,
    /// ABGR32 format
    ZegoVideoFrameFormatABGR32 = 7,
    /// I422 (YUV422Planar) format
    ZegoVideoFrameFormatI422 = 8
};


/// Video frame buffer type
typedef NS_ENUM(NSUInteger, ZegoVideoBufferType) {
    /// Raw data type video frame
    ZegoVideoBufferTypeUnknown = 0,
    /// Raw data type video frame
    ZegoVideoBufferTypeRawData = 1,
    /// Texture 2D type video frame
    ZegoVideoBufferTypeGLTexture2D = 3,
    /// CVPixelBuffer type video frame
    ZegoVideoBufferTypeCVPixelBuffer = 4
};


/// Video frame format series
typedef NS_ENUM(NSUInteger, ZegoVideoFrameFormatSeries) {
    /// RGB series
    ZegoVideoFrameFormatSeriesRGB = 0,
    /// YUV series
    ZegoVideoFrameFormatSeriesYUV = 1
};


/// Video frame flip mode
typedef NS_ENUM(NSUInteger, ZegoVideoFlipMode) {
    /// No flip
    ZegoVideoFlipModeNone = 0,
    /// X-axis flip
    ZegoVideoFlipModeX = 1
};


/// Audio Config Preset
typedef NS_ENUM(NSUInteger, ZegoAudioConfigPreset) {
    /// basic-quality
    ZegoAudioConfigPresetBasicQuality = 0,
    /// standard-quality
    ZegoAudioConfigPresetStandardQuality = 1,
    /// standard-quality-stereo
    ZegoAudioConfigPresetStandardQualityStereo = 2,
    /// high-quality
    ZegoAudioConfigPresetHighQuality = 3,
    /// high-quality-stereo
    ZegoAudioConfigPresetHighQualityStereo = 4
};


/// Player state
typedef NS_ENUM(NSUInteger, ZegoMediaPlayerState) {
    /// Not playing
    ZegoMediaPlayerStateNoPlay = 0,
    /// Playing
    ZegoMediaPlayerStatePlaying = 1,
    /// Pausing
    ZegoMediaPlayerStatePausing = 2,
    /// End of play
    ZegoMediaPlayerStatePlayEnded = 3
};


/// Player network event
typedef NS_ENUM(NSUInteger, ZegoMediaPlayerNetworkEvent) {
    /// Network resources are not playing well, and start trying to cache data
    ZegoMediaPlayerNetworkEventBufferBegin = 0,
    /// Network resources can be played smoothly
    ZegoMediaPlayerNetworkEventBufferEnded = 1
};


/// Log config
///
/// Configure the log file save path and the maximum log file size
@interface ZegoLogConfig : NSObject

/// The log file save path. The default path is [NSCachesDirectory]/ZegoLogs/
@property (nonatomic, copy) NSString *logPath;

/// The maximum log file size (Bytes). The default maximum size is 5MB (5 * 1024 * 1024 Bytes)
@property (nonatomic, assign) unsigned long long logSize;

@end


/// Custom video capture configuration
///
@interface ZegoCustomVideoCaptureConfig : NSObject

/// Custom video capture video frame data type
@property (nonatomic, assign) ZegoVideoBufferType bufferType;

@end


/// Custom video render configuration
///
@interface ZegoCustomVideoRenderConfig : NSObject

/// Custom video capture video frame data type
@property (nonatomic, assign) ZegoVideoBufferType bufferType;

/// Custom video rendering video frame data format
@property (nonatomic, assign) ZegoVideoFrameFormatSeries frameFormatSeries;

/// Whether the engine also renders while customizing video rendering
@property (nonatomic, assign) BOOL enableEngineRender;

@end


/// Advanced engine configuration
///
@interface ZegoEngineConfig : NSObject

/// Set the log file path and the maximum log file size (Bytes). The default path is [NSCachesDirectory]/ZegoLogs/, default maximum size is 5MB
@property (nonatomic, strong, nullable) ZegoLogConfig *logConfig;

/// Main channel custom video capture config, if not set, custom video capture config is not enabled by default
@property (nonatomic, strong, nullable) ZegoCustomVideoCaptureConfig *customVideoCaptureMainConfig;

/// Auxiliary channel custom video capture config, if not set, custom video capture config is not enabled by default
@property (nonatomic, strong, nullable) ZegoCustomVideoCaptureConfig *customVideoCaptureAuxConfig;

/// Custom video render config, if not set, custom video render config is not enabled by default
@property (nonatomic, strong, nullable) ZegoCustomVideoRenderConfig *customVideoRenderConfig;

/// Advanced config, if not set, advanced config is not enabled by default
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *advancedConfig;

@end


/// Advanced room configuration
///
@interface ZegoRoomConfig : NSObject

/// The maximum number of users in the room, the default is unlimited
@property (nonatomic, assign) unsigned int maxMemberCount;

/// Whether to enable the user in and out of the room callback notification [onRoomUserUpdate], the default is off
@property (nonatomic, assign) BOOL isUserStatusNotify;

/// The token issued by the developer's business server is used to ensure security. The generation rules are detailed in [https://doc.zego.im/CN/565.html](https://doc.zego.im/CN/565.html). Default is empty string, that is, no authentication
@property (nonatomic, copy) NSString *token;

/// Create a default room configuration
///
+ (instancetype)defaultConfig;

@end


/// Video config
///
@interface ZegoVideoConfig : NSObject

/// Capture resolution
@property (nonatomic, assign) CGSize captureResolution;

/// Encode resolution
@property (nonatomic, assign) CGSize encodeResolution;

/// frame rate
@property (nonatomic, assign) int fps;

/// Bit rate in kbps
@property (nonatomic, assign) int bitrate;

/// codec ID
@property (nonatomic, assign) ZegoVideoCodecID codecID;

/// Create default video configuration(360p, 15fps, 600kbps)
///
+ (instancetype)defaultConfig;

/// Create video configuration with preset enumeration values
///
+ (instancetype)configWithPreset:(ZegoVideoConfigPreset)preset;

/// Create video configuration with preset enumeration values
///
- (instancetype)initWithPreset:(ZegoVideoConfigPreset)preset;

/// @deprecated This interface is deprecated, please use [+configWithPreset:] instead
///
+ (instancetype)configWithResolution:(ZegoResolution)resolution DEPRECATED_ATTRIBUTE;

/// @deprecated This interface is deprecated, please use [-initWithPreset:] instead
///
- (instancetype)initWithResolution:(ZegoResolution)resolution DEPRECATED_ATTRIBUTE;

@end


/// User object
///
@interface ZegoUser : NSObject

/// User ID, a string with a maximum length of 128 bytes or less
@property (nonatomic, copy) NSString *userID;

/// User Name, a string with a maximum length of 128 bytes or less
@property (nonatomic, copy) NSString *userName;

/// Create a ZegoUser object, userName and userID are set to match
///
+ (instancetype)userWithUserID:(NSString *)userID;

/// Create a ZegoUser object, userName and userID are set to match
///
- (instancetype)initWithUserID:(NSString *)userID;

/// Create a ZegoUser object
///
+ (instancetype)userWithUserID:(NSString *)userID userName:(NSString *)userName;

/// Create a ZegoUser object
///
- (instancetype)initWithUserID:(NSString *)userID userName:(NSString *)userName;

@end


/// Stream object
///
@interface ZegoStream : NSObject

/// User object instance
@property (nonatomic, strong) ZegoUser *user;

/// Stream ID,a string with a maximum length of no more than 128 bytes
@property (nonatomic, copy) NSString *streamID;

/// Stream extra info
@property (nonatomic, copy) NSString *extraInfo;

@end


/// View object
///
@interface ZegoCanvas : NSObject

/// View
@property (nonatomic, strong) ZGView *view;

/// View mode, default is ZegoViewModeAspectFit
@property (nonatomic, assign) ZegoViewMode viewMode;

/// Background color, the format is 0xRRGGBB, default is black, which is 0x000000
@property (nonatomic, assign) int backgroundColor;

/// Create a ZegoCanvas, default viewMode is ZegoViewModeAspectFit, default background color is black
///
+ (instancetype)canvasWithView:(ZGView *)view;

/// Create a ZegoCanvas, default viewMode is ZegoViewModeAspectFit, default background color is black
///
- (instancetype)initWithView:(ZGView *)view;

@end


/// Published stream quality information
///
@interface ZegoPublishStreamQuality : NSObject

/// Video capture frame rate
@property (nonatomic, assign) double videoCaptureFPS;

/// Video encoding frame rate
@property (nonatomic, assign) double videoEncodeFPS;

/// Video transmission frame rate
@property (nonatomic, assign) double videoSendFPS;

/// Video bit rate in kbps
@property (nonatomic, assign) double videoKBPS;

/// Audio capture frame rate
@property (nonatomic, assign) double audioCaptureFPS;

/// Audio transmission frame rate
@property (nonatomic, assign) double audioSendFPS;

/// Audio bit rate in kbps
@property (nonatomic, assign) double audioKBPS;

/// Local to server delay, in milliseconds
@property (nonatomic, assign) int rtt;

/// Packet loss rate, in percentage, 0.0 ~ 1.0
@property (nonatomic, assign) double packetLostRate;

/// Published stream quality level
@property (nonatomic, assign) ZegoStreamQualityLevel level;

/// Whether to enable hardware encoding
@property (nonatomic, assign) BOOL isHardwareEncode;

@end


/// Turn stream to CDN config
///
@interface ZegoCDNConfig : NSObject

/// URL of pusing stream to CDN
@property (nonatomic, copy) NSString *URL;

/// Auth param of URL
@property (nonatomic, copy) NSString *authParam;

@end


/// Turn stream to CDN info
///
@interface ZegoStreamRelayCDNInfo : NSObject

/// URL of pusing stream to CDN
@property (nonatomic, copy) NSString *URL;

/// Status of turning stream to CDN
@property (nonatomic, assign) ZegoStreamRelayCDNState state;

/// Reason for relay status change
@property (nonatomic, assign) ZegoStreamRelayCDNUpdateReason updateReason;

/// The timestamp when the state changed, in milliseconds
@property (nonatomic, assign) unsigned long long stateTime;

@end


/// Advanced player configuration
///
@interface ZegoPlayerConfig : NSObject

/// The CDN configuration for playing stream. If set, the stream is play according to the URL instead of the streamID. After that, the streamID is only used as the ID of SDK internal callback.
@property (nonatomic, strong, nullable) ZegoCDNConfig *CDNConfig;

/// Set the video layer for playing the stream
/// @discussion This API only works when the remote publisher set the video codecID as MultiLayer
@property (nonatomic, assign) ZegoPlayerVideoLayer videoLayer;

@end


/// Played stream quality information
///
@interface ZegoPlayStreamQuality : NSObject

/// Video reception frame rate
@property (nonatomic, assign) double videoRecvFPS;

/// Video decoding frame rate
@property (nonatomic, assign) double videoDecodeFPS;

/// Video rendering frame rate
@property (nonatomic, assign) double videoRenderFPS;

/// Video bit rate in kbps
@property (nonatomic, assign) double videoKBPS;

/// Audio reception frame rate
@property (nonatomic, assign) double audioRecvFPS;

/// Audio decoding frame rate
@property (nonatomic, assign) double audioDecodeFPS;

/// Audio rendering frame rate
@property (nonatomic, assign) double audioRenderFPS;

/// Audio bit rate in kbps
@property (nonatomic, assign) double audioKBPS;

/// Server to local delay, in milliseconds
@property (nonatomic, assign) int rtt;

/// Packet loss rate, in percentage, 0.0 ~ 1.0
@property (nonatomic, assign) double packetLostRate;

/// Published stream quality level
@property (nonatomic, assign) ZegoStreamQualityLevel level;

/// Delay after the data is received by the local end, in milliseconds
@property (nonatomic, assign) int delay;

/// Whether to enable hardware decoding
@property (nonatomic, assign) BOOL isHardwareDecode;

@end


/// Device Info
///
@interface ZegoDeviceInfo : NSObject

/// Device ID
@property (nonatomic, copy) NSString *deviceID;

/// Device name
@property (nonatomic, copy) NSString *deviceName;

@end


/// Beauty configuration options
///
@interface ZegoBeautifyOption : NSObject

/// The sample step size of beauty peeling, the value range is [0,1]. Default 0.2
@property (nonatomic, assign) double polishStep;

/// Brightness parameter for beauty and whitening, ranging from [0,1]. The larger the value, the brighter the brightness. Default 0.5
@property (nonatomic, assign) double whitenFactor;

/// Beauty sharpening parameter, value range [0,1], the larger the value, the stronger the sharpening. Default 0.1
@property (nonatomic, assign) double sharpenFactor;

/// Create a default beauty parameter object
///
+ (instancetype)defaultConfig;

@end


/// Mix stream audio configuration
///
@interface ZegoMixerAudioConfig : NSObject

/// Audio bitrate in kbps, default is 48 kbps, cannot be modified after starting a mixer task
@property (nonatomic, assign) int bitrate;

/// Audio channel, default is Mono
@property (nonatomic, assign) ZegoAudioChannel channel;

/// codec ID, default is ZegoAudioCodecIDDefault
@property (nonatomic, assign) ZegoAudioCodecID codecID;

/// Create a default mix stream audio configuration
///
+ (instancetype)defaultConfig;

@end


/// Mix stream video config object
///
@interface ZegoMixerVideoConfig : NSObject

/// video resolution
@property (nonatomic, assign) CGSize resolution;

/// Video FPS, cannot be modified after starting a mixer task
@property (nonatomic, assign) int fps;

/// Video bitrate in kbps
@property (nonatomic, assign) int bitrate;

/// Create a mixer video configuration
///
+ (instancetype)configWithResolution:(CGSize)resolution fps:(int)fps bitrate:(int)bitrate;

/// Create a mixer video configuration
///
- (instancetype)initWithResolution:(CGSize)resolution fps:(int)fps bitrate:(int)bitrate;

@end


/// Mixer input
///
@interface ZegoMixerInput : NSObject

/// Stream ID
@property (nonatomic, copy) NSString *streamID;

/// Mix stream content type
@property (nonatomic, assign) ZegoMixerInputContentType contentType;

/// Stream layout
@property (nonatomic, assign) CGRect layout;

/// If enable soundLevel in mix stream task, an unique soundLevelID is need for every stream
@property (nonatomic, assign) unsigned int soundLevelID;

/// Create a mixed input object
///
- (instancetype)initWithStreamID:(NSString *)streamID contentType:(ZegoMixerInputContentType)contentType layout:(CGRect)layout;

/// Create a mixed input object
///
- (instancetype)initWithStreamID:(NSString *)streamID contentType:(ZegoMixerInputContentType)contentType layout:(CGRect)layout soundLevelID:(unsigned int)soundLevelID;

@end


/// Mixer output
///
@interface ZegoMixerOutput : NSObject

/// Mix stream output target, URL or stream ID
@property (nonatomic, copy) NSString *target;

/// Create a mix stream output object
///
- (instancetype)initWithTarget:(NSString *)target;

@end


/// Watermark object
///
@interface ZegoWatermark : NSObject

/// Watermark image URL
@property (nonatomic, copy) NSString *imageURL;

/// Watermark image layout
@property (nonatomic, assign) CGRect layout;

/// Create a watermark object
///
- (instancetype)initWithImageURL:(NSString *)imageURL layout:(CGRect)layout;

@end


/// Mix stream task object
///
@interface ZegoMixerTask : NSObject

/// Mix stream task ID
@property (nonatomic, copy, readonly) NSString *taskID;

/// This method is unavaialble. Please use [initWithTaskID:] instead.
///
+ (instancetype)new NS_UNAVAILABLE;

/// This method is unavaialble. Please use [initWithTaskID:] instead.
///
- (instancetype)init NS_UNAVAILABLE;

/// Create a mix stream task object with TaskID
///
- (instancetype)initWithTaskID:(NSString *)taskID;

/// Set the audio configuration of the mix stream task object
///
- (void)setAudioConfig:(ZegoMixerAudioConfig *)audioConfig;

/// Set the video configuration of the mix stream task object
///
- (void)setVideoConfig:(ZegoMixerVideoConfig *)videoConfig;

/// Set the input stream list for the mix stream task object
///
- (void)setInputList:(NSArray<ZegoMixerInput *> *)inputList;

/// Set the output list of the mix stream task object
///
- (void)setOutputList:(NSArray<ZegoMixerOutput *> *)outputList;

/// Set the watermark of the mix stream task object
///
- (void)setWatermark:(ZegoWatermark *)watermark;

/// Set the background image of the mix stream task object
///
- (void)setBackgroundImageURL:(NSString *)backgroundImageURL;

/// Enable or disable sound level callback for the task. If enabled, then the remote player can get the soundLevel of every stream in the inputlist by [onMixerSoundLevelUpdate] callback.
///
- (void)enableSoundLevel:(BOOL)enable;

@end


/// Received broadcast message
///
@interface ZegoBroadcastMessageInfo : NSObject

/// message content
@property (nonatomic, copy) NSString *message;

/// message id
@property (nonatomic, assign) unsigned long long messageID;

/// Message send time
@property (nonatomic, assign) unsigned long long sendTime;

/// Message sender
@property (nonatomic, strong) ZegoUser *fromUser;

@end


/// Received barrage message
///
@interface ZegoBarrageMessageInfo : NSObject

/// message content
@property (nonatomic, copy) NSString *message;

/// message id
@property (nonatomic, assign) NSString *messageID;

/// Message send time
@property (nonatomic, assign) unsigned long long sendTime;

/// Message sender
@property (nonatomic, strong) ZegoUser *fromUser;

@end


/// Object for video frame fieldeter
///
@interface ZegoVideoFrameParam : NSObject

/// Video frame format
@property (nonatomic, assign) ZegoVideoFrameFormat format;

/// Number of bytes per line (for example: RGBA only needs to consider strides [0], I420 needs to consider strides [0,1,2])
@property (nonatomic, assign) int *strides;

/// Video frame size
@property (nonatomic, assign) CGSize size;

@end


/// Parameter object for audio frame
///
@interface ZegoAudioFrameParam : NSObject

/// Sampling Rate
@property (nonatomic, assign) int sampleRate;

/// Audio channel, default is Mono
@property (nonatomic, assign) ZegoAudioChannel channel;

@end


/// Audio configuration
///
@interface ZegoAudioConfig : NSObject

/// Audio bitrate in kbps, default is 48 kbps
@property (nonatomic, assign) int bitrate;

/// Audio channel, default is Mono
@property (nonatomic, assign) ZegoAudioChannel channel;

/// codec ID, default is ZegoAudioCodecIDDefault
@property (nonatomic, assign) ZegoAudioCodecID codecID;

/// Create a default audio configuration (ZegoAudioConfigPresetStandardQuality, 48 kbps, Mono, ZegoAudioCodecIDDefault)
///
+ (instancetype)defaultConfig;

/// Create a audio configuration with preset enumeration values
///
+ (instancetype)configWithPreset:(ZegoAudioConfigPreset)preset;

/// Create a audio configuration with preset enumeration values
///
- (instancetype)initWithPreset:(ZegoAudioConfigPreset)preset;

@end


/// Zego MediaPlayer
///
/// Yon can use ZegoMediaPlayer to play media resource files on the local or remote server, and can mix the sound of the media resource files that are played into the push stream to achieve the effect of background music.
@interface ZegoMediaPlayer : NSObject

/// Total duration of media resources
/// @discussion Unit is millisecond
@property (nonatomic, assign, readonly) unsigned long long totalDuration;

/// Current playback progress of the media resource
/// @discussion Unit is millisecond
@property (nonatomic, assign, readonly) unsigned long long currentProgress;

/// Current volume
/// @discussion The range is 0 ~ 100
@property (nonatomic, assign, readonly) int volume;

/// Player's current playback status
@property (nonatomic, assign, readonly) ZegoMediaPlayerState currentState;

/// Create a media player instance object
///
/// Currently, a maximum of 4 instances can be created, after which it will return nil.
/// @return Media player instance, nil will be returned when the maximum number is exceeded.
+ (nullable ZegoMediaPlayer *)createMediaPlayer;

/// Set event callback handler for media player
///
/// You can change the player UI widget according to the related event callback of the media player
/// @param handler Media player event callback object
- (void)setEventHandler:(nullable id<ZegoMediaPlayerEventHandler>)handler;

/// Set video callback handler
///
/// You can set this callback to throw the video data of the media resource file played by the media player
/// @param handler Video event callback object for media player
/// @param format Video frame format for video data
/// @param type Buffer type for video data
- (void)setVideoHandler:(nullable id<ZegoMediaPlayerVideoHandler>)handler format:(ZegoVideoFrameFormat)format type:(ZegoVideoBufferType)type;

/// Set audio callback handler
///
/// You can set this callback to throw the audio data of the media resource file played by the media player
/// @param handler Audio event callback object for media player
- (void)setAudioHandler:(nullable id<ZegoMediaPlayerAudioHandler>)handler;

/// Load media resource
///
/// Yon can pass the absolute path of the local resource or the URL of the network resource
/// @param path the absolute path of the local resource or the URL of the network resource
/// @param callback Notification of resource loading results
- (void)loadResource:(NSString *)path callback:(nullable ZegoMediaPlayerLoadResourceCallback)callback;

/// Start playing
///
/// You need to load resources before playing
- (void)start;

/// Stop playing
///
- (void)stop;

/// Pause playing
///
- (void)pause;

/// resume playing
///
- (void)resume;

/// Set the specified playback progress
///
/// Unit is millisecond
/// @param millisecond Point in time of specified playback progress
/// @param callback the result notification of set the specified playback progress
- (void)seekTo:(unsigned long long)millisecond callback:(nullable ZegoMediaPlayerSeekToCallback)callback;

/// Whether to repeat playback
///
/// @param enable repeat playback flag
- (void)enableRepeat:(BOOL)enable;

/// Whether to mix the player's sound into the stream being pushed
///
/// @param enable Aux audio flag
- (void)enableAux:(BOOL)enable;

/// Whether to play locally silently
///
/// If [enableAux] switch is turned on, there is still sound in the pushing stream
/// @param mute Mute loacal audio flag
- (void)muteLocal:(BOOL)mute;

/// Set the view of the player playing video
///
/// @param canvas Video rendered canvas object
- (void)setPlayerCanvas:(nullable ZegoCanvas *)canvas;

/// Set player volume
///
/// @param volume The range is 0 ~ 100
- (void)setVolume:(int)volume;

/// Set playback progress callback interval
///
/// This interface can control the callback frequency of [mediaPlayer:playingProgress:]
/// @param millisecond Interval of playback progress callback in milliseconds
- (void)setProgressInterval:(unsigned long long)millisecond;

/// This method is unavaialble. Please use [+createMediaPlayer] instead
///
+ (instancetype)new NS_UNAVAILABLE;

/// This method is unavaialble. Please use [+createMediaPlayer] instead
///
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
