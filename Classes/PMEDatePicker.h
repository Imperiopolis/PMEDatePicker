//  Created by Michael Kamphausen on 06.11.13.
//  Copyright (c) 2013 Michael Kamphausen. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PMEDatePicker;

typedef void (^PMEDatePickerHandler)(NSDate *date);

@protocol PMEDatePickerDelegate;

@interface PMEDatePicker : UIPickerView

@property (nonatomic, retain) NSDate* date;
@property (nonatomic, retain) NSDate* maximumDate;
@property (nonatomic, retain) NSDate* minimumDate;
@property (nonatomic, strong, readonly) NSDateFormatter* dateFormatter;
//! Supported date symbols are yyyy, MMM, d, HH, h, mm, j, a. Default is 'yyyyMMMdjmm'. Order is determined by locale.
@property (nonatomic, copy) NSString* dateFormatTemplate;
//! Use this delegate instead of inherited delegate and dataSource properties
@property (nonatomic, weak) IBOutlet id<PMEDatePickerDelegate> dateDelegate;
@property PMEDatePickerHandler handler;

- (void)setDate:(NSDate*)date animated:(BOOL)animated;

@end

@protocol PMEDatePickerDelegate <NSObject>

- (void)datePicker:(PMEDatePicker*)datePicker didSelectDate:(NSDate*)date;

@end
