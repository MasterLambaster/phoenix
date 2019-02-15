/*
 * Phoenix is released under the MIT License. Refer to https://github.com/kasper/phoenix/blob/master/LICENSE.md
 */

@import Foundation;
@import Cocoa;
@import JavaScriptCore;

#import "PHHandler.h"
#import "PHIdentifiableJSExport.h"

@protocol PHMenuItemJSExport <JSExport>

@property(copy) NSString *toolTip;
@property long long tag;
@property BOOL enabled;
@property long long state;
@property(readonly, copy) NSString *userKeyEquivalent;
@property(copy) NSString *keyEquivalent;

@property(readonly) BOOL separatorItem;
@property(copy) NSString *title;
@property BOOL hidden;
@property(readonly) BOOL hasSubmenu;
@property(readonly, copy) NSString *description;
@property(strong) NSMenu *submenu;

+ (instancetype)separatorItem;
- (instancetype) initWithTitle:(NSString *)title;

@end

@interface PHMenuItem : NSMenuItem<PHMenuItemJSExport>

- (instancetype) initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;
- (instancetype) initWithTitle:(NSString *)string action:(SEL)selector keyEquivalent:(NSString *)charCode NS_UNAVAILABLE;
- (instancetype) initWithTitle:(NSString *)title NS_DESIGNATED_INITIALIZER;
- (void) call;

@end
