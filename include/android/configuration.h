/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file configuration.h
 */

#ifndef ANDROID_CONFIGURATION_H
#define ANDROID_CONFIGURATION_H

#include <android/asset_manager.h>

#ifdef __cplusplus
extern "C" {
#endif

struct AConfiguration;
/**
 * {@link AConfiguration} is an opaque type used to get and set
 * various subsystem configurations.
 *
 * A {@link AConfiguration} pointer can be obtained using:
 * - AConfiguration_new()
 * - AConfiguration_fromAssetManager()
 */
typedef struct AConfiguration AConfiguration;


/**
 * Define flags and constants for various subsystem configurations.
 */
enum {
    /** Any. */
    ACONFIGURATION_ORIENTATION_ANY  = 0x0000,
    /** Portrait. */
    ACONFIGURATION_ORIENTATION_PORT = 0x0001,
    /** Landscape. */
    ACONFIGURATION_ORIENTATION_LAND = 0x0002,
    /** Deprecated. */
    ACONFIGURATION_ORIENTATION_SQUARE = 0x0003,

    /** any */
    ACONFIGURATION_TOUCHSCREEN_ANY  = 0x0000,
    /** no touch */
    ACONFIGURATION_TOUCHSCREEN_NOTOUCH  = 0x0001,
    /** stylus */
    ACONFIGURATION_TOUCHSCREEN_STYLUS  = 0x0002,
    /** finger */
    ACONFIGURATION_TOUCHSCREEN_FINGER  = 0x0003,

    /** default */
    ACONFIGURATION_DENSITY_DEFAULT = 0,
    /** low: ~120dpi */
    ACONFIGURATION_DENSITY_LOW = 120,
    /** medium: ~160dpi */
    ACONFIGURATION_DENSITY_MEDIUM = 160,
    /** tv: ~213dpi */
    ACONFIGURATION_DENSITY_TV = 213,
    /** high: ~240dpi */
    ACONFIGURATION_DENSITY_HIGH = 240,
    /** x-high: ~320dpi */
    ACONFIGURATION_DENSITY_XHIGH = 320,
    /** xx-high: ~480dpi */
    ACONFIGURATION_DENSITY_XXHIGH = 480,
    /** xxx-high: ~640dpi */
    ACONFIGURATION_DENSITY_XXXHIGH = 640,
    /** any */
    ACONFIGURATION_DENSITY_ANY = 0xfffe,
    /** none */
    ACONFIGURATION_DENSITY_NONE = 0xffff,

    /** any */
    ACONFIGURATION_KEYBOARD_ANY  = 0x0000,
    /** no keys */
    ACONFIGURATION_KEYBOARD_NOKEYS  = 0x0001,
    /** qwerty */
    ACONFIGURATION_KEYBOARD_QWERTY  = 0x0002,
    /** 12-key */
    ACONFIGURATION_KEYBOARD_12KEY  = 0x0003,

    /** any */
    ACONFIGURATION_NAVIGATION_ANY  = 0x0000,
    /** no navigation */
    ACONFIGURATION_NAVIGATION_NONAV  = 0x0001,
    /** d-pad */
    ACONFIGURATION_NAVIGATION_DPAD  = 0x0002,
    /** trackball */
    ACONFIGURATION_NAVIGATION_TRACKBALL  = 0x0003,
    /** wheel(s) */
    ACONFIGURATION_NAVIGATION_WHEEL  = 0x0004,

    /** any */
    ACONFIGURATION_KEYSHIDDEN_ANY = 0x0000,
    /** keys hidden */
    ACONFIGURATION_KEYSHIDDEN_NO = 0x0001,
    /** keys exposed */
    ACONFIGURATION_KEYSHIDDEN_YES = 0x0002,
    /** software keyboard */
    ACONFIGURATION_KEYSHIDDEN_SOFT = 0x0003,

    /** any */
    ACONFIGURATION_NAVHIDDEN_ANY = 0x0000,
    /** navigation keys exposed */
    ACONFIGURATION_NAVHIDDEN_NO = 0x0001,
    /** navigation keys hidden */
    ACONFIGURATION_NAVHIDDEN_YES = 0x0002,

    /** any */
    ACONFIGURATION_SCREENSIZE_ANY  = 0x00,
    /** small */
    ACONFIGURATION_SCREENSIZE_SMALL = 0x01,
    /** normal */
    ACONFIGURATION_SCREENSIZE_NORMAL = 0x02,
    /** large */
    ACONFIGURATION_SCREENSIZE_LARGE = 0x03,
    /** x-large */
    ACONFIGURATION_SCREENSIZE_XLARGE = 0x04,

    /** any */
    ACONFIGURATION_SCREENLONG_ANY = 0x00,
    /** not long screens, such as QVGA, HVGA, VGA */
    ACONFIGURATION_SCREENLONG_NO = 0x1,
    /** long screens, such as WQVGA, WVGA, FWVGA */
    ACONFIGURATION_SCREENLONG_YES = 0x2,

    /** any */
    ACONFIGURATION_UI_MODE_TYPE_ANY = 0x00,
    /** normal */
    ACONFIGURATION_UI_MODE_TYPE_NORMAL = 0x01,
    /** desk dock */
    ACONFIGURATION_UI_MODE_TYPE_DESK = 0x02,
    /** car doc */
    ACONFIGURATION_UI_MODE_TYPE_CAR = 0x03,
    /** tv */
    ACONFIGURATION_UI_MODE_TYPE_TELEVISION = 0x04,
    /** application with no display */
    ACONFIGURATION_UI_MODE_TYPE_APPLIANCE = 0x05,
    /** watch */
    ACONFIGURATION_UI_MODE_TYPE_WATCH = 0x06,

    /** any */
    ACONFIGURATION_UI_MODE_NIGHT_ANY = 0x00,
    /** day time */
    ACONFIGURATION_UI_MODE_NIGHT_NO = 0x1,
    /** night time */
    ACONFIGURATION_UI_MODE_NIGHT_YES = 0x2,

    /** any */
    ACONFIGURATION_SCREEN_WIDTH_DP_ANY = 0x0000,

    /** any */
    ACONFIGURATION_SCREEN_HEIGHT_DP_ANY = 0x0000,

    /** any */
    ACONFIGURATION_SMALLEST_SCREEN_WIDTH_DP_ANY = 0x0000,

    /** any */
    ACONFIGURATION_LAYOUTDIR_ANY  = 0x00,
    /** left to right */
    ACONFIGURATION_LAYOUTDIR_LTR  = 0x01,
    /** right to left */
    ACONFIGURATION_LAYOUTDIR_RTL  = 0x02,

    /** mobile country code */
    ACONFIGURATION_MCC = 0x0001,
    /** mobile network code */
    ACONFIGURATION_MNC = 0x0002,
    /** locale */
    ACONFIGURATION_LOCALE = 0x0004,
    /** touchscreen */
    ACONFIGURATION_TOUCHSCREEN = 0x0008,
    /** keyboard */
    ACONFIGURATION_KEYBOARD = 0x0010,
    /** keyboard availability */
    ACONFIGURATION_KEYBOARD_HIDDEN = 0x0020,
    /** navigation */
    ACONFIGURATION_NAVIGATION = 0x0040,
    /** orientation */
    ACONFIGURATION_ORIENTATION = 0x0080,
    /** density */
    ACONFIGURATION_DENSITY = 0x0100,
    /** screen size */
    ACONFIGURATION_SCREEN_SIZE = 0x0200,
    /** version */
    ACONFIGURATION_VERSION = 0x0400,
    /** screen layout */
    ACONFIGURATION_SCREEN_LAYOUT = 0x0800,
    /** ui mode */
    ACONFIGURATION_UI_MODE = 0x1000,
    /** smalless screen size */
    ACONFIGURATION_SMALLEST_SCREEN_SIZE = 0x2000,
    /** layout direction */
    ACONFIGURATION_LAYOUTDIR = 0x4000,

    /** mobile network code zero */
    ACONFIGURATION_MNC_ZERO = 0xffff,
};

/**
 * Create a new AConfiguration, initialized with no values set.
 */
AConfiguration* AConfiguration_new();

/**
 * Free an AConfiguration that was previously created with
 * AConfiguration_new().
 */
void AConfiguration_delete(AConfiguration* config);

/**
 * Create and return a new AConfiguration based on the current configuration in
 * use in the given AssetManager.
 */
void AConfiguration_fromAssetManager(AConfiguration* out, AAssetManager* am);

/**
 * Copy the contents of 'src' to 'dest'.
 */
void AConfiguration_copy(AConfiguration* dest, AConfiguration* src);

/**
 * Return the current MCC set in the configuration.  0 if not set.
 */
int32_t AConfiguration_getMcc(AConfiguration* config);

/**
 * Set the current MCC in the configuration.  0 to clear.
 */
void AConfiguration_setMcc(AConfiguration* config, int32_t mcc);

/**
 * Return the current MNC set in the configuration.  0 if not set.
 */
int32_t AConfiguration_getMnc(AConfiguration* config);

/**
 * Set the current MNC in the configuration.  0 to clear.
 */
void AConfiguration_setMnc(AConfiguration* config, int32_t mnc);

/**
 * Return the current language code set in the configuration.  The output will
 * be filled with an array of two characters.  They are not 0-terminated.  If
 * a language is not set, they will be 0.
 */
void AConfiguration_getLanguage(AConfiguration* config, char* outLanguage);

/**
 * Set the current language code in the configuration, from the first two
 * characters in the string.
 */
void AConfiguration_setLanguage(AConfiguration* config, const char* language);

/**
 * Return the current country code set in the configuration.  The output will
 * be filled with an array of two characters.  They are not 0-terminated.  If
 * a country is not set, they will be 0.
 */
void AConfiguration_getCountry(AConfiguration* config, char* outCountry);

/**
 * Set the current country code in the configuration, from the first two
 * characters in the string.
 */
void AConfiguration_setCountry(AConfiguration* config, const char* country);

/**
 * Return the current ACONFIGURATION_ORIENTATION_* set in the configuration.
 */
int32_t AConfiguration_getOrientation(AConfiguration* config);

/**
 * Set the current orientation in the configuration.
 */
void AConfiguration_setOrientation(AConfiguration* config, int32_t orientation);

/**
 * Return the current ACONFIGURATION_TOUCHSCREEN_* set in the configuration.
 */
int32_t AConfiguration_getTouchscreen(AConfiguration* config);

/**
 * Set the current touchscreen in the configuration.
 */
void AConfiguration_setTouchscreen(AConfiguration* config, int32_t touchscreen);

/**
 * Return the current ACONFIGURATION_DENSITY_* set in the configuration.
 */
int32_t AConfiguration_getDensity(AConfiguration* config);

/**
 * Set the current density in the configuration.
 */
void AConfiguration_setDensity(AConfiguration* config, int32_t density);

/**
 * Return the current ACONFIGURATION_KEYBOARD_* set in the configuration.
 */
int32_t AConfiguration_getKeyboard(AConfiguration* config);

/**
 * Set the current keyboard in the configuration.
 */
void AConfiguration_setKeyboard(AConfiguration* config, int32_t keyboard);

/**
 * Return the current ACONFIGURATION_NAVIGATION_* set in the configuration.
 */
int32_t AConfiguration_getNavigation(AConfiguration* config);

/**
 * Set the current navigation in the configuration.
 */
void AConfiguration_setNavigation(AConfiguration* config, int32_t navigation);

/**
 * Return the current ACONFIGURATION_KEYSHIDDEN_* set in the configuration.
 */
int32_t AConfiguration_getKeysHidden(AConfiguration* config);

/**
 * Set the current keys hidden in the configuration.
 */
void AConfiguration_setKeysHidden(AConfiguration* config, int32_t keysHidden);

/**
 * Return the current ACONFIGURATION_NAVHIDDEN_* set in the configuration.
 */
int32_t AConfiguration_getNavHidden(AConfiguration* config);

/**
 * Set the current nav hidden in the configuration.
 */
void AConfiguration_setNavHidden(AConfiguration* config, int32_t navHidden);

/**
 * Return the current SDK (API) version set in the configuration.
 */
int32_t AConfiguration_getSdkVersion(AConfiguration* config);

/**
 * Set the current SDK version in the configuration.
 */
void AConfiguration_setSdkVersion(AConfiguration* config, int32_t sdkVersion);

/**
 * Return the current ACONFIGURATION_SCREENSIZE_* set in the configuration.
 */
int32_t AConfiguration_getScreenSize(AConfiguration* config);

/**
 * Set the current screen size in the configuration.
 */
void AConfiguration_setScreenSize(AConfiguration* config, int32_t screenSize);

/**
 * Return the current ACONFIGURATION_SCREENLONG_* set in the configuration.
 */
int32_t AConfiguration_getScreenLong(AConfiguration* config);

/**
 * Set the current screen long in the configuration.
 */
void AConfiguration_setScreenLong(AConfiguration* config, int32_t screenLong);

/**
 * Return the current ACONFIGURATION_UI_MODE_TYPE_* set in the configuration.
 */
int32_t AConfiguration_getUiModeType(AConfiguration* config);

/**
 * Set the current UI mode type in the configuration.
 */
void AConfiguration_setUiModeType(AConfiguration* config, int32_t uiModeType);

/**
 * Return the current ACONFIGURATION_UI_MODE_NIGHT_* set in the configuration.
 */
int32_t AConfiguration_getUiModeNight(AConfiguration* config);

/**
 * Set the current UI mode night in the configuration.
 */
void AConfiguration_setUiModeNight(AConfiguration* config, int32_t uiModeNight);

/**
 * Return the current configuration screen width in dp units, or
 * ACONFIGURATION_SCREEN_WIDTH_DP_ANY if not set.
 */
int32_t AConfiguration_getScreenWidthDp(AConfiguration* config);

/**
 * Set the configuration's current screen width in dp units.
 */
void AConfiguration_setScreenWidthDp(AConfiguration* config, int32_t value);

/**
 * Return the current configuration screen height in dp units, or
 * ACONFIGURATION_SCREEN_HEIGHT_DP_ANY if not set.
 */
int32_t AConfiguration_getScreenHeightDp(AConfiguration* config);

/**
 * Set the configuration's current screen width in dp units.
 */
void AConfiguration_setScreenHeightDp(AConfiguration* config, int32_t value);

/**
 * Return the configuration's smallest screen width in dp units, or
 * ACONFIGURATION_SMALLEST_SCREEN_WIDTH_DP_ANY if not set.
 */
int32_t AConfiguration_getSmallestScreenWidthDp(AConfiguration* config);

/**
 * Set the configuration's smallest screen width in dp units.
 */
void AConfiguration_setSmallestScreenWidthDp(AConfiguration* config, int32_t value);

/**
 * Return the configuration's layout direction, or
 * ACONFIGURATION_LAYOUTDIR_ANY if not set.
 */
int32_t AConfiguration_getLayoutDirection(AConfiguration* config);

/**
 * Set the configuration's layout direction.
 */
void AConfiguration_setLayoutDirection(AConfiguration* config, int32_t value);

/**
 * Perform a diff between two configurations.  Returns a bit mask of
 * ACONFIGURATION_* constants, each bit set meaning that configuration element
 * is different between them.
 */
int32_t AConfiguration_diff(AConfiguration* config1, AConfiguration* config2);

/**
 * Determine whether 'base' is a valid configuration for use within the
 * environment 'requested'.  Returns 0 if there are any values in 'base'
 * that conflict with 'requested'.  Returns 1 if it does not conflict.
 */
int32_t AConfiguration_match(AConfiguration* base, AConfiguration* requested);

/**
 * Determine whether the configuration in 'test' is better than the existing
 * configuration in 'base'.  If 'requested' is non-NULL, this decision is based
 * on the overall configuration given there.  If it is NULL, this decision is
 * simply based on which configuration is more specific.  Returns non-0 if
 * 'test' is better than 'base'.
 *
 * This assumes you have already filtered the configurations with
 * AConfiguration_match().
 */
int32_t AConfiguration_isBetterThan(AConfiguration* base, AConfiguration* test,
        AConfiguration* requested);

#ifdef __cplusplus
};
#endif

#endif // ANDROID_CONFIGURATION_H
