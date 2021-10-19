/*
 * Copyright (c) 2021 Bartosz Kościelniak <kostek233@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <logging/log.h>
LOG_MODULE_REGISTER(main);

void main(void)
{
	LOG_INF("Welcome to Sound Direction Detector, version: %u.%u.%u (%s)",
		APP_VERSION_MAJOR, APP_VERSION_MINOR, APP_VERSION_PATCH,
		APP_VERSION_STRING);
}
