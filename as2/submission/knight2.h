#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
#define KNIGHTS_MIN 1
#define KNIGHTS_MAX 1000

#define HP_MIN 0
#define HP_MAX 999
#define LEVEL_MIN 1
#define LEVEL_MAX 10
#define PHOENIXDOWN_I_MIN 0
#define PHOENIXDOWN_I_MAX 5
#define GIL_MIN 0
#define GIL_MAX 999
#define ANTIDOTE_MIN 0
#define ANTIDOTE_MAX 5

#define EVENTS_MIN 1
#define EVENTS_MAX 1000

#define MEET_MADBEAR 1
#define MEET_BANDIT 2
#define MEET_LORDLUPIN 3
#define MEET_ELF 4
#define MEET_TROLL 5
#define MEET_TORNBERY 6
#define MEET_QUEENOFCARDS 7
#define MEET_NINA 8
#define MEET_DURIANGARDEN 9
#define MEET_OMEGAWEAPON 10
#define MEET_HADES 11
#define PICK_PHOENIXDOWN_II 112
#define PICK_PHOENIXDOWN_III 113
#define PICK_PHOENIXDOWN_IV 114
#define PICK_PALADIN_SHIELD 95
#define PICK_LANCELOT_SPEAR 96
#define PICK_GUINEVERE_HAIR 97
#define MEET_EXCALIBUR 98
#define MEET_ULTIMECIA 99

#define BASE_DMG_MADBEAR 10
#define BASE_DMG_BANDIT 15
#define BASE_DMG_LORDLUPIN 45
#define BASE_DMG_ELF 75
#define BASE_DMG_TROLL 95

// just for better type safety
constexpr double BASE_DMG_PALADIN = 0.06;
constexpr double BASE_DMG_LANCELOT = 0.05;
constexpr double BASE_DMG_DRAGON = 0.075;

#define GIL_MADBEAR 100
#define GIL_BANDIT 150
#define GIL_LORDLUPIN 450
#define GIL_ELF 750
#define GIL_TROLL 800

#define MAX_INT 2147483647
#define MIN_INT -2147483648

enum ItemType
{
    ANTIDOTE = 0,
    PHOENIXDOWN_I,
    PHOENIXDOWN_II,
    PHOENIXDOWN_III,
    PHOENIXDOWN_IV
};

enum KnightType
{
    PALADIN = 0,
    LANCELOT,
    DRAGON,
    NORMAL
};

class BaseKnight;
class BaseOpponent;
class Events;

/* * * class BaseItem * * */
class BaseItem
{
protected:
    ItemType item_type;

public:
    BaseItem *next;
    BaseItem() = default;
    virtual ~BaseItem() = default;

    virtual ItemType get_type() = 0;
    virtual bool canUse(BaseKnight *knight) = 0;
    virtual void use(BaseKnight *knight) = 0;
};

class Antidote : public BaseItem
{
public:
    Antidote();
    ~Antidote() = default;

    ItemType get_type() override;
    bool canUse(BaseKnight *knight) override;
    void use(BaseKnight *knight) override;
    // for being poisoned
};

class PhoenixDownI : public BaseItem
{
public:
    PhoenixDownI();
    ~PhoenixDownI() = default;

    ItemType get_type() override;
    bool canUse(BaseKnight *knight) override;
    void use(BaseKnight *knight) override;
};

class PhoenixDownII : public BaseItem
{
public:
    PhoenixDownII();
    ~PhoenixDownII() = default;

    ItemType get_type() override;
    bool canUse(BaseKnight *knight) override;
    void use(BaseKnight *knight) override;
};

class PhoenixDownIII : public BaseItem
{
public:
    PhoenixDownIII();
    ~PhoenixDownIII() = default;

    ItemType get_type() override;
    bool canUse(BaseKnight *knight) override;
    void use(BaseKnight *knight) override;
};

class PhoenixDownIV : public BaseItem
{
public:
    PhoenixDownIV();
    ~PhoenixDownIV() = default;

    ItemType get_type() override;
    bool canUse(BaseKnight *knight) override;
    void use(BaseKnight *knight) override;
};

/* * * class BaseBag * * */
class BaseBag
{
protected:
    BaseItem *head;
    BaseItem *tail;
    int count;
    BaseKnight *knight;
    int item_max = MAX_INT;
    int antidote_cnt = 0;
    int phoenixdown_cnt = 0;

public:
    BaseBag() = default;
    virtual ~BaseBag() = default;

    virtual bool insertFirst(BaseItem *item);
    virtual BaseItem *get(ItemType itemType);
    virtual string toString() const;
    // linked list helper functions
    int get_count();
    int get_antidote_cnt();
    int get_phoenixdown_cnt();
    void clear();
    void remove_fisrt();
    // int getElement(int idx);
    // int getIndex(ItemType itemType);
    // void setElement(int idx, ItemType itemType);
    // bool doesContain(ItemType itemType);
    // bool isEmpty();
    // bool remove(ItemType itemType);
    // int removeAt(int idx);
};

class BagOfPaladin : public BaseBag
{
public:
    BagOfPaladin(BaseKnight *knight, int antidote, int phoenixdownI);
    ~BagOfPaladin();
};

class BagOfLancelot : public BaseBag
{
public:
    BagOfLancelot(BaseKnight *knight, int antidote, int phoenixdownI);
    ~BagOfLancelot();
};

class BagOfDragon : public BaseBag
{
public:
    BagOfDragon(BaseKnight *knight, int antidote, int phoenixdownI);
    ~BagOfDragon();
};

class BagOfNormal : public BaseBag
{
public:
    BagOfNormal(BaseKnight *knight, int antidote, int phoenixdownI);
    ~BagOfNormal();
};

/* * * class BaseKnight * * */
class BaseKnight
{
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;
    BaseBag *bag;
    KnightType knightType;
    bool is_poisoned;

public:
    BaseKnight() = default;
    virtual ~BaseKnight() = default;

    virtual bool fight(BaseOpponent *opponent) = 0;
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
    static bool is_Paladin(int init_hp);
    static bool is_Lancelot(int init_hp);
    static bool is_Dragon(int init_hp);
    int get_id();
    int get_hp();
    int get_maxhp();
    int get_level();
    int get_gil();
    int get_antidote();
    int get_phoenixdownI();
    BaseBag *get_bag() const;
    KnightType get_type();
    bool get_is_poisoned();
    void set_id(int new_id);
    void set_hp(int new_hp);
    void set_level(int new_level);
    void set_level_method2(int new_level);
    void set_gil(int new_gil);
    void set_gil_method2(int new_gil);
    void set_bag(BaseKnight *knight);
    void set_is_poisoned(bool is_poisoned);
};

class PaladinKnight : public BaseKnight
{
public:
    PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    ~PaladinKnight();

    bool fight(BaseOpponent *opponent) override;
};

class LancelotKnight : public BaseKnight
{
public:
    LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    ~LancelotKnight();

    bool fight(BaseOpponent *opponent) override;
};

class DragonKnight : public BaseKnight
{
public:
    DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    ~DragonKnight();

    bool fight(BaseOpponent *opponent) override;
};

class NormalKnight : public BaseKnight
{
public:
    NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    ~NormalKnight();

    bool fight(BaseOpponent *opponent) override;
};

/* * * class BaseOpponent * * */
class BaseOpponent
{
protected:
    int type_O;
    int level_O;
    int base_dmg_O;
    int gil_O;

public:
    BaseOpponent() = default;
    virtual ~BaseOpponent() = default;

    virtual int get_type_O() = 0;
    virtual int get_level_O() = 0;
    virtual int get_base_dmg_O() = 0;
    virtual int get_gil_O() = 0;
    virtual void set_level_O(int i, int event_id) = 0;
};

class MadBear : public BaseOpponent
{
public:
    MadBear();
    ~MadBear() = default;

    int get_type_O() override;
    int get_level_O() override;
    int get_base_dmg_O() override;
    int get_gil_O() override;
    void set_level_O(int i, int event_id) override;
};

class Bandit : public BaseOpponent
{
public:
    Bandit();
    ~Bandit() = default;

    int get_type_O() override;
    int get_level_O() override;
    int get_base_dmg_O() override;
    int get_gil_O() override;
    void set_level_O(int i, int event_id) override;
};

class LordLupin : public BaseOpponent
{
public:
    LordLupin();
    ~LordLupin() = default;

    int get_type_O() override;
    int get_level_O() override;
    int get_base_dmg_O() override;
    int get_gil_O() override;
    void set_level_O(int i, int event_id) override;
};

class Elf : public BaseOpponent
{
public:
    Elf();
    ~Elf() = default;

    int get_type_O() override;
    int get_level_O() override;
    int get_base_dmg_O() override;
    int get_gil_O() override;
    void set_level_O(int i, int event_id) override;
};

class Troll : public BaseOpponent
{
public:
    Troll();
    ~Troll() = default;

    int get_type_O() override;
    int get_level_O() override;
    int get_base_dmg_O() override;
    int get_gil_O() override;
    void set_level_O(int i, int event_id) override;
};

class Tornbery : public BaseOpponent
{
public:
    Tornbery();
    ~Tornbery() = default;

    int get_type_O() override;
    int get_level_O() override;
    int get_base_dmg_O() override;
    int get_gil_O() override;
    void set_level_O(int i, int event_id) override;
};

class QueenOfCards : public BaseOpponent
{
public:
    QueenOfCards();
    ~QueenOfCards() = default;

    int get_type_O() override;
    int get_level_O() override;
    int get_base_dmg_O() override;
    int get_gil_O() override;
    void set_level_O(int i, int event_id) override;
};

class NinaDeRings : public BaseOpponent
{
public:
    NinaDeRings();
    ~NinaDeRings() = default;

    int get_type_O() override;
    int get_level_O() override;
    int get_base_dmg_O() override;
    int get_gil_O() override;
    void set_level_O(int i, int event_id) override;
};

class DurianGarden : public BaseOpponent
{
public:
    DurianGarden();
    ~DurianGarden() = default;

    int get_type_O() override;
    int get_level_O() override;
    int get_base_dmg_O() override;
    int get_gil_O() override;
    void set_level_O(int i, int event_id) override;
};

class OmegaWeapon : public BaseOpponent
{
public:
    OmegaWeapon();
    ~OmegaWeapon() = default;

    int get_type_O() override;
    int get_level_O() override;
    int get_base_dmg_O() override;
    int get_gil_O() override;
    void set_level_O(int i, int event_id) override;
};

class Hades : public BaseOpponent
{
public:
    Hades();
    ~Hades() = default;

    int get_type_O() override;
    int get_level_O() override;
    int get_base_dmg_O() override;
    int get_gil_O() override;
    void set_level_O(int i, int event_id) override;
};

/* * * class ArmyKnights * * */
class ArmyKnights
{
private:
    int armyknights_cnt;
    int armyknights_hp, armyknights_level, armyknights_phoenixdownI, armyknights_gil, armyknights_antidote;
    BaseKnight **armyknight;
    bool hasShield = false, hasSpear = false, hasHair = false, hasExcalibur = false;
    bool met_OmegaWeapon = false;
    bool met_Hades = false;
    bool defeated_Ultimecia = false;

public:
    ArmyKnights(const string &file_armyknights);
    ~ArmyKnights();

    bool fight(BaseOpponent *opponent, int i);
    bool adventure(Events *events);
    BaseKnight *lastKnight() const;
    BaseKnight *getKnight(int id) const;
    int count() const;
    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    void gil_passing_back(int prevknight_id, int gil_excess);
    bool check_Paladin_Lancelot_Dragon();
    void delete_knight_at(int id);

    void printInfo() const;
    void printResult(bool win) const;
};

/* * * class Events * * */
class Events // DONE!
{
private:
    int events_cnt;
    int *event;

public:
    Events(const string &file_events);
    ~Events();

    int count() const;
    int get(int i) const;
};

/* * * class KnightAdventure * * */
class KnightAdventure // DONE!
{
private:
    ArmyKnights *armyKnights;
    Events *events;

public:
    KnightAdventure();
    ~KnightAdventure();

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

#endif // __KNIGHT2_H__