#ifndef FLUTTER_PLUGIN_SUPER_NATIVE_EXTENSIONS_PLUGIN_H_
#define FLUTTER_PLUGIN_SUPER_NATIVE_EXTENSIONS_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace fork_super_native_extensions {

class ForkSuperNativeExtensionsPlugin : public flutter::Plugin {
public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  ForkSuperNativeExtensionsPlugin();

  virtual ~ForkSuperNativeExtensionsPlugin();

  // Disallow copy and assign.
  ForkSuperNativeExtensionsPlugin(const ForkSuperNativeExtensionsPlugin &) = delete;
  ForkSuperNativeExtensionsPlugin &
  operator=(const ForkSuperNativeExtensionsPlugin &) = delete;

private:
};

} // namespace fork_super_native_extensions

#endif // FLUTTER_PLUGIN_SUPER_NATIVE_EXTENSIONS_PLUGIN_H_
