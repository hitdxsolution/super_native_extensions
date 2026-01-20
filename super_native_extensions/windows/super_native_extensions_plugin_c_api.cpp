#include "include/super_native_extensions/super_native_extensions_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "super_native_extensions_plugin.h"

void ForkSuperNativeExtensionsPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  fork_super_native_extensions::ForkSuperNativeExtensionsPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}
