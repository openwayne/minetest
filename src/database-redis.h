/*
Minetest
Copyright (C) 2014 celeron55, Perttu Ahola <celeron55@gmail.com>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation; either version 2.1 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef DATABASE_REDIS_HEADER
#define DATABASE_REDIS_HEADER

#include "config.h"

#if USE_REDIS

#include "hiredis/hiredis.h"
#include <string>
#include "database.h"

class Settings;

class Database_Redis : public MapDatabase
{
public:
	Database_Redis(Settings &conf);
	~Database_Redis();

	void beginSave();
	void endSave();

	bool saveBlock(const v3s16 &pos, const std::string &data);
	void loadBlock(const v3s16 &pos, std::string *block);
	bool deleteBlock(const v3s16 &pos);
	void listAllLoadableBlocks(std::vector<v3s16> &dst);

private:
	redisContext *ctx;
	std::string hash;
};

#endif // USE_REDIS

#endif
