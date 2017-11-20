/* (c) 2017 thatlittlegit and PinguPenguin.
 * This file is from the SuperTTD project.
 *
 * SuperTTD, and by extension this file, is free software under
 * the GNU General Public License, 2.0.
 *
 * SuperTTD is distributed in the hope that it will be useful,
 * but comes with NO WARRANTY WHATSOEVER. Please se the official
 * GNU GPL 2.0 for more information.
 *
 * You should have recieved a copy of the GPL with this project.
 * If not, see https://gnu.org/licenses/.
 */
#pragma once
#include <vector>
#include <algorithm>
#include "spriteman.hpp"

/*
 * I used shorts because we really don't need more than
 * 65536*65536 worlds. If we need to make this bigger,
 * go incrementally (int, long, long long...) but don't
 * unless we must.
 * ~thatlittlegit
 */
#define WORLD_SIZE_VARTYPE short

using std::vector;

namespace SuperTTD {
	class Tile {
	private:
		void construct(int argId, WORLD_SIZE_VARTYPE argX, WORLD_SIZE_VARTYPE argY, unsigned int spriteIndex);
	public:
		int id;
		WORLD_SIZE_VARTYPE x;
		WORLD_SIZE_VARTYPE y;
		unsigned int spriteIndex;
		static vector<Tile> tiles;

		Tile(int argId, WORLD_SIZE_VARTYPE argX, WORLD_SIZE_VARTYPE argY, unsigned int argSpriteIndex);
		Tile(SuperTTD::Sprite argSprite, WORLD_SIZE_VARTYPE argX, WORLD_SIZE_VARTYPE argY, unsigned int argSpriteIndex);
	};
}
