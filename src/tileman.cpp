/* (c) 2017-2019 thatlittlegit and PinguPenguin.
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
#include "tileman.hpp"

namespace SuperTTD {
Tile::Tile(std::string argSpriteId, WORLD_SIZE_VARTYPE argX, WORLD_SIZE_VARTYPE argY)
    : spriteId(argSpriteId)
    , x(argX)
    , y(argY)
{
}

std::vector<SuperTTD::Tile> SuperTTD::Tile::tiles;
}
