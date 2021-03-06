//
//  TopBarViewController.h
//  GridViewTest
//
//  Created by mic on 17.07.11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "Artist.h"
#import "AudioStreamer.h"
#import <QuartzCore/CoreAnimation.h>
#import <MediaPlayer/MediaPlayer.h>
#import <CFNetwork/CFNetwork.h>
#import "ArtistDBConnector.h"
#import "ArtistsTableViewController.h"
#import "PlayerSongListViewController.h"
#import "AppInfoView.h"

@interface TopBarViewController : UIViewController <UITextFieldDelegate> {
    
    UIImageView *imageView;
    UILabel *titleLabel;
    UILabel *tagsLabel;
	UIButton *playButton;
    UILabel *songTitleLabel;	
	
	AudioStreamer *streamer;
	NSTimer *progressUpdateTimer;
	NSArray* songs;
    UISegmentedControl *segmentedControl;
    UISegmentedControl *prevNextSegCtrl;
	int songIdx;
	UIPopoverController* popoverController;
    UIPopoverController* songListPopover;
    UIPopoverController* infoPopover;
}

@property (nonatomic, retain) IBOutlet UIImageView *imageView;
@property (nonatomic, retain) IBOutlet UILabel *titleLabel;
@property (nonatomic, retain) IBOutlet UILabel *tagsLabel;
@property (nonatomic, retain) IBOutlet UILabel *songTitleLabel;

@property (nonatomic, retain) IBOutlet UIButton *playButton;

@property (nonatomic, retain) NSArray* songs;
@property (nonatomic, retain) IBOutlet UISegmentedControl *segmentedControl;
@property (nonatomic, retain) IBOutlet UISegmentedControl *prevNextSegCtrl;
@property (retain, nonatomic) IBOutlet UITextField *searchTextField;
@property (nonatomic, retain) 	UIPopoverController* popoverController;

- (IBAction)onBackButtonPressed:(id)sender;

- (void) changeImage:(UIImage*)image;

- (void) updateArtist:(Artist*) artist;
- (IBAction)playPressed:(id)sender;
- (IBAction)prevPressed:(id)sender;
- (IBAction)nextPressed:(id)sender;

- (void) createStreamer;
- (void) destroyStreamer;

-(void) songsForArtistLoaded:(Artist*) artist;

-(void) stopPlaying;
-(void) startPlaying;
-(BOOL) isPlaying;

- (IBAction)segmentedControlValueChanged:(id)sender;
- (IBAction)prevNextSegCtrlValueChanged:(id)sender;
- (void) artistLoaded:(NSNotification*) notification;

- (IBAction)onListArtistsButtonPressed:(id)sender;
- (IBAction)infoButtonPressed:(id)sender;

@end
