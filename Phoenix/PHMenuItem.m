/*
 * Phoenix is released under the MIT License. Refer to https://github.com/kasper/phoenix/blob/master/LICENSE.md
 */

#import "PHMenuItem.h"
#import "PHKeyTranslator.h"

@interface PHMenuItem ()

@property JSManagedValue *callback;

@end

@implementation PHMenuItem

- (instancetype) initWithTitle:(NSString *)title {

    if (self = [super initWithTitle:title action:@selector(call) keyEquivalent:@""]) {

        self.keyEquivalentModifierMask = 0;
        self.target = self;

        NSArray *args = [JSContext currentArguments];

        // Last argument should always be callback if more than just title provided
        if (args.count > 1) {
            self.callback = [JSManagedValue managedValueWithValue:args[args.count-1] andOwner:self];
        }

        // Second argument is key if ther are 3 or more arguments
        if (args.count > 2 && [args[1] isString]) {
            self.keyEquivalent = [args[1] toString];
        }

        if (args.count == 4 && [args[2] isArray]) {
            NSArray *mod = [args[2] toArray];
            self.keyEquivalentModifierMask = [PHKeyTranslator carbonToCocoaModifierFlags:[PHKeyTranslator modifierFlagsForModifiers:mod]];
        }
    }
    return self;
}

- (void) call {

    JSValue *function = self.callback.value;

    if (!function.isUndefined) {
        [function callWithArguments:@[ self ]];
    }
}

@end
