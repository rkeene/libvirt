/*
 * storage_backend.h: internal storage driver backend contract
 *
 * Copyright (C) 2007-2008 Red Hat, Inc.
 * Copyright (C) 2007-2008 Daniel P. Berrange
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
 *
 * Author: Daniel P. Berrange <berrange@redhat.com>
 */

#include <config.h>

#include <string.h>
#include <regex.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "util.h"

#include "storage_backend.h"


virStorageBackendPtr
virStorageBackendForType(int type) {
    virStorageReportError(NULL, VIR_ERR_INTERNAL_ERROR,
                          _("missing backend for pool type %d"), type);
    return NULL;
}

virStorageBackendPoolOptionsPtr
virStorageBackendPoolOptionsForType(int type) {
    virStorageBackendPtr backend = virStorageBackendForType(type);
    if (backend == NULL)
        return NULL;
    return &backend->poolOptions;
}

virStorageBackendVolOptionsPtr
virStorageBackendVolOptionsForType(int type) {
    virStorageBackendPtr backend = virStorageBackendForType(type);
    if (backend == NULL)
        return NULL;
    return &backend->volOptions;
}


int
virStorageBackendFromString(const char *type) {
    virStorageReportError(NULL, VIR_ERR_INTERNAL_ERROR,
                          _("unknown storage backend type %s"), type);
    return -1;
}

const char *
virStorageBackendToString(int type) {
    virStorageReportError(NULL, VIR_ERR_INTERNAL_ERROR,
                          _("unknown storage backend type %d"), type);
    return NULL;
}


/*
 * vim: set tabstop=4:
 * vim: set shiftwidth=4:
 * vim: set expandtab:
 */
/*
 * Local variables:
 *  indent-tabs-mode: nil
 *  c-indent-level: 4
 *  c-basic-offset: 4
 *  tab-width: 4
 * End:
 */
