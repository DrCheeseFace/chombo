#ifndef M_MAHC_H
#define M_MAHC_H

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define AKAFIVE_VALUE '0'

#define DRAGON_SUIT_CHAR 'd'

#define EAST_VALUE 'E'

#define EAST_VALUE_Z '1'

#define EIGHT_VALUE '8'

#define FIVE_VALUE '5'

#define FOUR_VALUE '4'

#define GREEN_VALUE 'g'

#define GREEN_VALUE_Z '6'

#define MAN_SUIT_CHAR 'm'

#define MAX_GROUPS_PER_HAND 14

#define MAX_HAND_SHAPES 4

#define NINE_VALUE '9'

#define NORTH_VALUE 'N'

#define NORTH_VALUE_Z '4'

#define ONE_VALUE '1'

#define OPEN_CHAR 'o'

#define PIN_SUIT_CHAR 'p'

#define RED_VALUE 'r'

#define RED_VALUE_Z '7'

#define SEVEN_VALUE '7'

#define SIX_VALUE '6'

#define SOUTH_VALUE 'S'

#define SOUTH_VALUE_Z '2'

#define SOU_SUIT_CHAR 's'

#define THREE_VALUE '3'

#define TWO_VALUE '2'

#define WEST_VALUE 'W'

#define WEST_VALUE_Z '3'

#define WHITE_VALUE 'w'

#define WHITE_VALUE_Z '5'

#define WIND_SUIT_CHAR 'w'

#define Z_SUIT_CHAR 'z'

typedef enum DValue {
	DValue_Red,
	DValue_Green,
	DValue_White,
} DValue;

typedef enum Fu {
	Fu_BasePoints,
	Fu_BasePointsChitoi,
	Fu_ClosedRon,
	Fu_Tsumo,
	Fu_NonSimpleClosedTriplet,
	Fu_SimpleClosedTriplet,
	Fu_NonSimpleOpenTriplet,
	Fu_SimpleOpenTriplet,
	Fu_NonSimpleClosedKan,
	Fu_SimpleClosedKan,
	Fu_NonSimpleOpenKan,
	Fu_SimpleOpenKan,
	Fu_Toitsu,
	Fu_SingleWait,
} Fu;

typedef enum GroupType {
	GroupType_Sequence,
	GroupType_Triplet,
	GroupType_Kan,
	GroupType_Pair,
	GroupType_None,
} GroupType;

typedef enum MpsValue {
	MpsValue_One = 0,
	MpsValue_Two,
	MpsValue_Three,
	MpsValue_Four,
	MpsValue_Five,
	MpsValue_AkaFive,
	MpsValue_Six,
	MpsValue_Seven,
	MpsValue_Eight,
	MpsValue_Nine,
} MpsValue;

typedef enum Suit {
	Suit_Manzu,
	Suit_Pinzu,
	Suit_Souzu,
	Suit_Wind,
	Suit_Dragon,
} Suit;

typedef enum WValue {
	WValue_East,
	WValue_South,
	WValue_West,
	WValue_North,
} WValue;

typedef enum Yaku {
	Yaku_Tanyao,
	Yaku_Iipeikou,
	Yaku_Yakuhai,
	Yaku_MenzenTsumo,
	Yaku_Pinfu,
	Yaku_Riichi,
	Yaku_Ippatsu,
	Yaku_Haitei,
	Yaku_RinshanKaihou,
	Yaku_Chankan,
	Yaku_DoubleRiichi,
	Yaku_Toitoi,
	Yaku_Ittsuu,
	Yaku_SanshokuDoujun,
	Yaku_Chantaiyao,
	Yaku_Sanankou,
	Yaku_SanshokuDoukou,
	Yaku_Sankantsu,
	Yaku_Honroutou,
	Yaku_Shousangen,
	Yaku_Chiitoitsu,
	Yaku_Honitsu,
	Yaku_JunchanTaiyao,
	Yaku_Ryanpeikou,
	Yaku_Chinitsu,
	Yaku_KazoeYakuman,
	Yaku_KokushiMusou,
	Yaku_KokushiMusou13SidedWait,
	Yaku_Suuankou,
	Yaku_SuuankouTankiWait,
	Yaku_Daisangen,
	Yaku_Shousuushii,
	Yaku_Daisuushii,
	Yaku_Tsuuiisou,
	Yaku_Daichiishin,
	Yaku_Chinroutou,
	Yaku_Ryuuiisou,
	Yaku_ChuurenPoutou,
	Yaku_ChuurenPoutou9SidedWait,
	Yaku_Suukantsu,
	Yaku_Tenhou,
	Yaku_Chiihou,
} Yaku;

typedef struct TileGroup TileGroup;

typedef enum Tile_Tag {
	Tile_Man,
	Tile_Pin,
	Tile_Sou,
	Tile_Wind,
	Tile_Dragon,
} Tile_Tag;

typedef struct Tile {
	Tile_Tag tag;
	union {
		struct {
			enum MpsValue man;
		};
		struct {
			enum MpsValue pin;
		};
		struct {
			enum MpsValue sou;
		};
		struct {
			enum WValue wind;
		};
		struct {
			enum DValue dragon;
		};
	};
} Tile;

typedef struct CTileGroup {
	struct Tile tiles[4];
	size_t tiles_len;
	bool isopen;
	enum GroupType group_type;
} CTileGroup;

typedef struct HandShape {
	struct CTileGroup groups[MAX_GROUPS_PER_HAND];
	size_t group_count;
} HandShape;

typedef struct HandShapes {
	struct HandShape hands[MAX_HAND_SHAPES];
	size_t hands_len;
} HandShapes;

void C_free_hand_shapes(struct HandShapes *ptr);

struct HandShapes *C_get_valid_hand_shapes(const char *tiles_string);

#endif /* M_MAHC_H */
