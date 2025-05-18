/* SPDX-License-Identifier: MIT */
/* Copyright © 2024 Intel Corporation */

#ifndef __INTEL_BO__
#define __INTEL_BO__

#include <linux/types.h>
#include <linux/version.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6,13,0)

struct drm_gem_object;
struct seq_file;
struct vm_area_struct;

bool intel_bo_is_tiled(struct drm_gem_object *obj);
bool intel_bo_is_userptr(struct drm_gem_object *obj);
bool intel_bo_is_shmem(struct drm_gem_object *obj);
bool intel_bo_is_protected(struct drm_gem_object *obj);
void intel_bo_flush_if_display(struct drm_gem_object *obj);
int intel_bo_fb_mmap(struct drm_gem_object *obj, struct vm_area_struct *vma);
int intel_bo_read_from_page(struct drm_gem_object *obj, u64 offset, void *dst, int size);

struct intel_frontbuffer *intel_bo_get_frontbuffer(struct drm_gem_object *obj);
struct intel_frontbuffer *intel_bo_set_frontbuffer(struct drm_gem_object *obj,
						   struct intel_frontbuffer *front);

void intel_bo_describe(struct seq_file *m, struct drm_gem_object *obj);
#endif
#endif /* __INTEL_BO__ */