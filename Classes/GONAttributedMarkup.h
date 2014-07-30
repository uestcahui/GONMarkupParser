//
//  GONAttributedMarkup.h
//  GONMarkupParserSample
//
//  Created by Nicolas Goutaland on 25/06/14.
//  Copyright (c) 2014 Nicolas Goutaland All rights reserved.
//
// Subclass for Markup, but handling ( markups
// This class will automatically extract attributes from given tag
// Tags should be space separated, values affected using equal sign, and between double quotes. To escape double quotes, use \
//
// Example :
// Tag                     | Supported
// -----------------------------------
// <color value="red">     | YES
// <color value = "red">   | YES
// <color value = red>     | NO
// <color value = "re"d">  | NO
// <color value = "re\"d"> | YES
//
// When subclassing, override openingMarkupFound:configuration:fromTag:attributes: instead of openingMarkupFound:configuration:fromTag:
// When subclassing, override closingMarkupFound:configuration:fromTag:attributes: instead of closingMarkupFound:configuration:fromTag:
//

#import "GONMarkup.h"

@interface GONAttributedMarkup : GONMarkup
/* This method will be called if markup is matching current opening tag.
 * Object is responsible to update attributed string parameters in "aConfigurationDictionary"
 *
 * "aTag" is matching tag, allowing you to extract parameters
 * "aDicAttributes" contains all extracted parameters
 * "aContext" is a mutable dictionary use by marker to add contextual information. This dictioanry is shared throught all markers in a parser and is reset each time a new parse is started
 * It is used for example by list markers to handle list type, tabulation index and count
 *
 * You should override this method to implement new behavior
 */
- (void)openingMarkupFound:(NSString *)aTag configuration:(NSMutableDictionary *)aConfigurationDictionary context:(NSMutableDictionary *)aContext attributes:(NSDictionary *)aDicAttributes;

/* This method will be called once current marker tag is closed
 * This allows marker to update string content
 * "aDicAttributes" contains all previously extracted parameters
 * "aContext" is the same as in openingMarkupFound:configuration:fromTag:context:attributes:
 *
 * Default implementation return input string
 */
- (NSString *)updatedContentString:(NSString *)aString context:(NSMutableDictionary *)aContext attributes:(NSDictionary *)aDicAttributes;

/* This method will be called if markup is matching current closing tag.
 * Object is responsible to update attributed string parameters in "aConfigurationDictionary"
 *
 * "aTag" is matching tag, allowing you to extract parameters
 * "aDicAttributes" contains all previously extracted parameters
 * "aContext" is a mutable dictionary use by marker to add contextual information. This dictioanry is shared throught all markers in a parser and is reset each time a new parse is started
 * It is used for example by list markers to handle list type, tabulation index and count
 *
 * You should override this method to implement new behavior
 */
- (void)closingMarkupFound:(NSString *)aTag configuration:(NSMutableDictionary *)aConfigurationDictionary context:(NSMutableDictionary *)aContext attributes:(NSDictionary *)aDicAttributes;

@end