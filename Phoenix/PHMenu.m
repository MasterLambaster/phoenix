/*
 * Phoenix is released under the MIT License. Refer to https://github.com/kasper/phoenix/blob/master/LICENSE.md
 */

#import "PHMenu.h"

@implementation PHMenu

static PHMenu *_applicationMenu = nil;
static NSArray<NSMenuItem *> *_intialMenuItems = nil;

+ (void)setApplicationMenu:(PHMenu *)menu {
    _applicationMenu = menu;
    _intialMenuItems = [menu itemArray];
}

+ (PHMenu *) applicationMenu {
    return _applicationMenu;
}

+ (void) reset {
    [_applicationMenu removeAllItems];
    for (NSMenuItem *item in _intialMenuItems) {
        [_applicationMenu addItem:(PHMenuItem *)item];
    }
}

- (void) addItems:(NSArray<PHMenuItem *> *)newItems {
    for(PHMenuItem *item in newItems) {
        [self addItem:item];
    }
}

- (void) insertItems:(NSArray<PHMenuItem *> *)newItems
            atIndex:(NSInteger)index {

    for(PHMenuItem *item in newItems) {
        [self insertItem:item atIndex:index];
        index++;
    }
}

@end
