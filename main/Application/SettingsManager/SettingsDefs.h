#pragma once

#include "SettingsManager.h"

// ──────────────────────────────────────────────────────────────
// Predefined setting keys — use these instead of raw strings
// ──────────────────────────────────────────────────────────────

namespace Settings {
    namespace Wifi {
        constexpr SettingKey Ssid     { "wifi.ssid" };
        constexpr SettingKey Password { "wifi.password" };
    }
    namespace Device {
        constexpr SettingKey Name { "device.name" };
        constexpr SettingKey Pin  { "device.pin" };
    }
    namespace Mqtt {
        constexpr SettingKey Enabled { "mqtt.enabled" };
        constexpr SettingKey Broker  { "mqtt.broker" };
        constexpr SettingKey Port    { "mqtt.port" };
        constexpr SettingKey User    { "mqtt.user" };
        constexpr SettingKey Pass    { "mqtt.pass" };
        constexpr SettingKey Prefix  { "mqtt.prefix" };
    }
    namespace Ntp {
        constexpr SettingKey Server   { "ntp.server" };
        constexpr SettingKey Timezone { "ntp.timezone" };
    }
}

// ──────────────────────────────────────────────────────────────
// Setting definitions — add new settings here
// ──────────────────────────────────────────────────────────────

inline const SettingDef SETTINGS_DEFS[] = {
    // WiFi
    { Settings::Wifi::Ssid,     SettingType::String, "WiFi SSID",      "" },
    { Settings::Wifi::Password, SettingType::String, "WiFi Password",  "" },

    // Device
    { Settings::Device::Name,   SettingType::String, "Device Name",    "Strux" },
    { Settings::Device::Pin,    SettingType::String, "Device PIN",     "" },

    // MQTT
    { Settings::Mqtt::Enabled,  SettingType::Bool,   "MQTT Enabled",   "0" },
    { Settings::Mqtt::Broker,   SettingType::String, "MQTT Broker",    "" },
    { Settings::Mqtt::Port,     SettingType::Int,    "MQTT Port",      "1883" },
    { Settings::Mqtt::User,     SettingType::String, "MQTT User",      "" },
    { Settings::Mqtt::Pass,     SettingType::String, "MQTT Password",  "" },
    { Settings::Mqtt::Prefix,   SettingType::String, "MQTT Prefix",    "strux" },

    // NTP
    { Settings::Ntp::Server,    SettingType::String, "NTP Server",     "pool.ntp.org" },
    { Settings::Ntp::Timezone,  SettingType::String, "NTP Timezone",   "UTC0" },
};

inline constexpr int SETTINGS_DEFS_COUNT = sizeof(SETTINGS_DEFS) / sizeof(SETTINGS_DEFS[0]);
