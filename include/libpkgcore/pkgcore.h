/*!
 * \file libpkgcore.h
 * \brief Umbrella header for libpkgcore public API.
 *
 * Including this header pulls in all public interfaces:
 *   - db_lock: RAII database locking
 *   - fs_utils: filesystem helpers
 *   - pkgutil: package database and install/remove logic
 *
 * Consumers may alternatively include individual headers from
 * <pkgcore/...> for finer granularity.
 *
 * \copyright See COPYING for license terms and COPYRIGHT for notices.
 */

#pragma once

#include "pkgcore/db_lock.h"
#include "pkgcore/fs_utils.h"
#include "pkgcore/pkgutil.h"
