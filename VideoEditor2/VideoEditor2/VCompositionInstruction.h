//
//  VCompositionInstruction.h
//  VideoEditor2
//
//  Created by Alexander on 9/25/15.
//  Copyright © 2015 Onix-Systems. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@class VFrameProvider;

@interface VCompositionInstruction : NSObject <AVVideoCompositionInstruction>

@property (nonatomic) CMTimeRange timeRange;
@property (nonatomic) BOOL enablePostProcessing;
@property (nonatomic) BOOL containsTweening;
@property (nonatomic) NSArray<NSValue *> *requiredSourceTrackIDs;
@property (nonatomic) CMPersistentTrackID passthroughTrackID; // kCMPersistentTrackID_Invalid if not a passthrough instruction


- (instancetype)initWithFrameProvider: (VFrameProvider*) frameProvider;

-(void) processRequest: (AVAsynchronousVideoCompositionRequest*) request usingCIContext: (CIContext*) ciContext;

-(void) registerTrackIDAsInputFrameProvider: (CMPersistentTrackID) trackID;

@end
