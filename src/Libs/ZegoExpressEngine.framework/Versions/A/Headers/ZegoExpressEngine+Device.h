//
//  ZegoExpressEngine+Device.h
//  ZegoExpressEngine
//
//  Copyright © 2019 Zego. All rights reserved.
//

#import "ZegoExpressEngine.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZegoExpressEngine (Device)

/// On/off microphone
///
/// This interface is used to control whether the collected audio data is used. When the microphone is turned off, the data is collected and discarded, and the microphone is still occupied.
/// @param mute Whether to turn off the microphone, YES: turn off microphone, NO: turn on microphone
- (void)muteMicrophone:(BOOL)mute;

/// Turn on/off audio output to the device
///
/// This interface is used to control whether the SDK needs to throw audio data to the device.
/// @param mute Whether to disable audio output to the device, YES: disable audio output, NO: enable audio output
- (void)muteAudioOutput:(BOOL)mute;

#if TARGET_OS_OSX
/// Choose to use an audio device
///
/// Only for macOS
/// @param deviceID ID of a device obtained by getAudioDeviceList
/// @param deviceType Audio device type
- (void)useAudioDevice:(NSString *)deviceID deviceType:(ZegoAudioDeviceType)deviceType;
#endif

#if TARGET_OS_OSX
/// Get a list of audio devices
///
/// Only for macOS
/// @param deviceType Audio device type
/// @return Audo device List
- (NSArray<ZegoDeviceInfo *> *)getAudioDeviceList:(ZegoAudioDeviceType)deviceType;
#endif

/// On/off audio capture device
///
/// This interface is used to control whether to release the audio collection device. When the audio collection device is turned off, the SDK will no longer occupy the audio device. Of course, if the stream is being pushed at this time, there is no audio data.
/// @param enable Whether to enable the audio capture device, YES: disable audio capture device, NO: enable audio capture device
- (void)enableAudioCaptureDevice:(BOOL)enable;

#if TARGET_OS_IPHONE
/// Whether to use the built-in speaker to play sound
///
/// When you choose not to use the built-in speaker to play sound, that is, set to NO, the SDK will select the currently highest priority audio output device to play the sound according to the system schedule
/// @param enable Whether to use the built-in speaker to play sound, YES: use the built-in speaker to play sound, NO: use the highest priority audio output device scheduled by the current system to play sound
- (void)setBuiltInSpeakerOn:(BOOL)enable;
#endif

/// On/off camera
///
/// This interface is used to control whether to start the camera acquisition. After the camera is turned off, video capture will not be performed. At this time, the push stream will also have no video data.
/// @param enable Whether to turn on the camera, YES: turn on camera, NO: turn off camera
- (void)enableCamera:(BOOL)enable;

/// On/off camera
///
/// This interface is used to control whether to start the camera acquisition. After the camera is turned off, video capture will not be performed. At this time, the push stream will also have no video data.
/// @param enable Whether to turn on the camera, YES: turn on camera, NO: turn off camera
/// @param channel Publishing stream channel.
- (void)enableCamera:(BOOL)enable channel:(ZegoPublishChannel)channel;

#if TARGET_OS_IPHONE
/// Switch front and rear camera
///
/// This interface is used to control the front or rear camera
/// @param enable Whether to use the front camera, YES: use the front camera, NO: use the the rear camera
- (void)useFrontCamera:(BOOL)enable;
#endif

#if TARGET_OS_IPHONE
/// Switch front and rear camera
///
/// This interface is used to control the front or rear camera
/// @param enable Whether to use the front camera, YES: use the front camera, NO: use the the rear camera
/// @param channel Publishing stream channel.
- (void)useFrontCamera:(BOOL)enable channel:(ZegoPublishChannel)channel;
#endif

#if TARGET_OS_OSX
/// Choose to use a video device
///
/// Only for macOS
/// @param deviceID ID of a device obtained by getVideoDeviceList
- (void)useVideoDevice:(NSString *)deviceID;
#endif

#if TARGET_OS_OSX
/// Choose to use a video device
///
/// Only for macOS
/// @param deviceID ID of a device obtained by getVideoDeviceList
/// @param channel Publishing stream channel.
- (void)useVideoDevice:(NSString *)deviceID channel:(ZegoPublishChannel)channel;
#endif

#if TARGET_OS_OSX
/// Get a list of video devices
///
/// Only for macOS
/// @return Video device List
- (NSArray<ZegoDeviceInfo *> *)getVideoDeviceList;
#endif

/// Start the sound level monitor
///
- (void)startSoundLevelMonitor;

/// Stop the sound level monitor
///
- (void)stopSoundLevelMonitor;

/// Start the audio spectrum monitor
///
- (void)startAudioSpectrumMonitor;

/// Stop the audio spectrum monitor
///
- (void)stopAudioSpectrumMonitor;

@end

NS_ASSUME_NONNULL_END
