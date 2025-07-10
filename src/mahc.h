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
  Red,
  Green,
  White,
} DValue;

typedef enum Fu {
  BasePoints,
  BasePointsChitoi,
  ClosedRon,
  Tsumo,
  NonSimpleClosedTriplet,
  SimpleClosedTriplet,
  NonSimpleOpenTriplet,
  SimpleOpenTriplet,
  NonSimpleClosedKan,
  SimpleClosedKan,
  NonSimpleOpenKan,
  SimpleOpenKan,
  Toitsu,
  SingleWait,
} Fu;

typedef enum GroupType {
  Sequence,
  Triplet,
  Kan,
  Pair,
  None,
} GroupType;

typedef enum MpsValue {
  One = 0,
  Two,
  Three,
  Four,
  Five,
  AkaFive,
  Six,
  Seven,
  Eight,
  Nine,
} MpsValue;

typedef enum Suit {
  Manzu,
  Pinzu,
  Souzu,
  Wind,
  Dragon,
} Suit;

typedef enum WValue {
  East,
  South,
  West,
  North,
} WValue;

typedef enum Yaku {
  Tanyao,
  Iipeikou,
  Yakuhai,
  MenzenTsumo,
  Pinfu,
  Riichi,
  Ippatsu,
  Haitei,
  RinshanKaihou,
  Chankan,
  DoubleRiichi,
  Toitoi,
  Ittsuu,
  SanshokuDoujun,
  Chantaiyao,
  Sanankou,
  SanshokuDoukou,
  Sankantsu,
  Honroutou,
  Shousangen,
  Chiitoitsu,
  Honitsu,
  JunchanTaiyao,
  Ryanpeikou,
  Chinitsu,
  KazoeYakuman,
  KokushiMusou,
  KokushiMusou13SidedWait,
  Suuankou,
  SuuankouTankiWait,
  Daisangen,
  Shousuushii,
  Daisuushii,
  Tsuuiisou,
  Daichiishin,
  Chinroutou,
  Ryuuiisou,
  ChuurenPoutou,
  ChuurenPoutou9SidedWait,
  Suukantsu,
  Tenhou,
  Chiihou,
} Yaku;

typedef enum Tile_Tag {
  TMan,
  TPin,
  TSou,
  TWind,
  TDragon,
} Tile_Tag;

typedef struct Tile {
  Tile_Tag tag;
  union {
    struct {
      enum MpsValue t_man;
    };
    struct {
      enum MpsValue t_pin;
    };
    struct {
      enum MpsValue t_sou;
    };
    struct {
      enum WValue t_wind;
    };
    struct {
      enum DValue t_dragon;
    };
  };
} Tile;

void sanity_check(void);
