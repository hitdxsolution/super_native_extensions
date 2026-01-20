#include "include/super_native_extensions/super_native_extensions_plugin.h"

#include <flutter_linux/flutter_linux.h>
#include <gtk/gtk.h>
#include <sys/utsname.h>

#include <cstring>
#include <dlfcn.h>

#define FORK_SUPER_NATIVE_EXTENSIONS_PLUGIN(obj)                                    \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),                                           \
                              fork_super_native_extensions_plugin_get_type(),       \
                              ForkSuperNativeExtensionsPlugin))

struct _ForkSuperNativeExtensionsPlugin {
  GObject parent_instance;
};

G_DEFINE_TYPE(ForkSuperNativeExtensionsPlugin, fork_super_native_extensions_plugin,
              g_object_get_type())

static void super_native_extensions_plugin_dispose(GObject *object) {
  G_OBJECT_CLASS(super_native_extensions_plugin_parent_class)->dispose(object);
}

static void fork_super_native_extensions_plugin_class_init(
    ForkSuperNativeExtensionsPluginClass *klass) {
  G_OBJECT_CLASS(klass)->dispose = super_native_extensions_plugin_dispose;
}

extern "C" {
extern void super_native_extensions_init(void);
}

static void
fork_super_native_extensions_plugin_init(ForkSuperNativeExtensionsPlugin *self) {
  static bool initialized = false;
  if (!initialized) {
    super_native_extensions_init();
    initialized = true;
  }
}

void fork_super_native_extensions_plugin_register_with_registrar(
    FlPluginRegistrar *registrar) {
  ForkSuperNativeExtensionsPlugin *plugin = FORK_SUPER_NATIVE_EXTENSIONS_PLUGIN(
      g_object_new(super_native_extensions_plugin_get_type(), nullptr));

  g_object_unref(plugin);
}
