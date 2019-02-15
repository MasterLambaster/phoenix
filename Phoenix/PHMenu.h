/*
 * Phoenix is released under the MIT License. Refer to https://github.com/kasper/phoenix/blob/master/LICENSE.md
 */

@import Foundation;
@import JavaScriptCore;

#import "PHMenuItem.h"
@class PHMenu;

static NSString * const PHMenuDidChangeNotification = @"PHMenuDidChangeNotification";

@protocol PHMenuJSExport <JSExport>

- (instancetype)initWithTitle:(NSString *)title;

#pragma mark - Manipulation

- (void)addItem:(PHMenuItem *)newItem;
- (void)addItems:(NSArray<PHMenuItem *> *)newItems;
JSExportAs(insertItem, - (void)insertItem:(PHMenuItem *)newItem
           atIndex:(NSInteger)index);
JSExportAs(insertItems, - (void)insertItems:(NSArray<PHMenuItem *> *)newItems
           atIndex:(NSInteger)index);
- (void)removeItem:(NSMenuItem *)item;
- (void)removeItemAtIndex:(NSInteger)index;
- (void)removeAllItems;

#pragma mark - Finders

- (PHMenuItem *)itemWithTag:(NSInteger)tag;
- (PHMenuItem *)itemWithTitle:(NSString *)title;
- (PHMenuItem *)itemAtIndex:(NSInteger)index;

- (NSInteger)indexOfItem:(NSMenuItem *)item;
- (NSInteger)indexOfItemWithTitle:(NSString *)title;
- (NSInteger)indexOfItemWithTag:(NSInteger)tag;

#pragma mark - Application menu

+ (PHMenu *)applicationMenu;
@end

@interface PHMenu : NSMenu <PHMenuJSExport>

@property (weak, class) PHMenu *applicationMenu;

+ (void)setApplicationMenu:(PHMenu *)menu;
+ (PHMenu *) applicationMenu;
+ (void) reset;

@end
