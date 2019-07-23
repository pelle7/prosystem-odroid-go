#pragma once

#include <stdint.h>

char* odroid_util_GetFileName(const char* path);
char* odroid_util_GetFileExtenstion(const char* path);
char* odroid_util_GetFileNameWithoutExtension(const char* path);

typedef enum
{
    ODROID_START_ACTION_NORMAL = 0,
    ODROID_START_ACTION_RESTART
} ODROID_START_ACTION;

int32_t odroid_settings_VRef_get();
void odroid_settings_VRef_set(int32_t value);

int32_t odroid_settings_Volume_get();
void odroid_settings_Volume_set(int32_t value);

char* odroid_settings_RomFilePath_get();
void odroid_settings_RomFilePath_set(char* value);

int32_t odroid_settings_AppSlot_get();
void odroid_settings_AppSlot_set(int32_t value);

int32_t odroid_settings_DataSlot_get();
void odroid_settings_DataSlot_set(int32_t value);

int32_t odroid_settings_Backlight_get();
void odroid_settings_Backlight_set(int32_t value);

ODROID_START_ACTION odroid_settings_StartAction_get();
void odroid_settings_StartAction_set(ODROID_START_ACTION value);
