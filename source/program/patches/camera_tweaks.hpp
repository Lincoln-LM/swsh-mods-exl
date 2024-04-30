#include "lib.hpp"
#include "external.hpp"
#include "symbols.hpp"
#include "config.hpp"
#include <math.h>

HOOK_DEFINE_INLINE(PatchCameraConstants) {
    static void Callback(exl::hook::nx64::InlineCtx* ctx) {
        EXL_ASSERT(global_config.initialized);
        if (global_config.camera_tweaks.active) {
            auto camera_obj = reinterpret_cast<Field::Camera*>(ctx->X[19]);
            camera_obj->camera_speed = global_config.camera_tweaks.adjustment_speed / 180 * M_PI;
            camera_obj->maximum_pitch = global_config.camera_tweaks.max_pitch / 180 * M_PI;
            camera_obj->minimum_pitch = global_config.camera_tweaks.min_pitch / 180 * M_PI;
            camera_obj->minimum_distance = global_config.camera_tweaks.min_distance;
            camera_obj->maximum_distance = global_config.camera_tweaks.max_distance;
        }
    }
};
void install_camera_tweaks_patch() {
    PatchCameraConstants::InstallAtOffset(Field::Camera::Camera_offset + 0x164);
}