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
#pragma once
#include <string>
#include <vector>

namespace SuperTTD {
/*
 * I used shorts because we really don't need more than
 * 65536*65536 worlds. If we need to make this bigger,
 * go incrementally (int, long, long long...) but don't
 * unless we must.
 *
 *                2     32
 * Remember: 65536   = 2   = 4 GIGABYTES
 *                      16
 *           65536   = 2   = 65 kilobytes <-- much smaller!
 * ~thatlittlegit
 */
typedef uint16_t WORLD_SIZE_VARTYPE;

class Tile {
public:
    std::string spriteId;
    WORLD_SIZE_VARTYPE x;
    WORLD_SIZE_VARTYPE y;
    static std::vector<Tile> tiles;

    Tile(std::string spriteId, WORLD_SIZE_VARTYPE argX, WORLD_SIZE_VARTYPE argY);
};
}
