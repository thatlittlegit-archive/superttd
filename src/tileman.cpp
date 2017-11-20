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
#include <vector>
#include <algorithm>
#include <spriteman.hpp>
#include <tileman.hpp>

using std::vector;

namespace SuperTTD {
	void Tile::construct(int argId, WORLD_SIZE_VARTYPE argX, WORLD_SIZE_VARTYPE argY) {
		id = argId;
		x = argX;
		y = argY;
	}

	Tile::Tile(int argId, WORLD_SIZE_VARTYPE argX, WORLD_SIZE_VARTYPE argY) {
		construct(argId, argX, argY);
	}

	Tile::Tile(SuperTTD::Sprite argSprite, WORLD_SIZE_VARTYPE argX, WORLD_SIZE_VARTYPE argY) {
		construct(argSprite.world, argX, argY);
	}
}
std::vector<SuperTTD::Tile> SuperTTD::Tile::tiles;
