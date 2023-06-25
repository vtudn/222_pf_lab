#include "knight2.h"

/* * * BEGIN implementation of class BaseItem * * */
Antidote::Antidote() // DONE!
{
    this->item_type = ANTIDOTE;
    this->next = nullptr;
}
ItemType Antidote::get_type() // DONE!
{
    return this->item_type;
}
bool Antidote::canUse(BaseKnight *knight)
{
    return true;
}
void Antidote::use(BaseKnight *knight) // DONE!
{
    knight->set_is_poisoned(false);
}

PhoenixDownI::PhoenixDownI() // DONE!
{
    this->item_type = PHOENIXDOWN_I;
    this->next = nullptr;
}
ItemType PhoenixDownI::get_type() // DONE!
{
    return this->item_type;
}
bool PhoenixDownI::canUse(BaseKnight *knight)
{
    return true;
}
void PhoenixDownI::use(BaseKnight *knight) // DONE!
{
    knight->set_hp(knight->get_maxhp());
}

PhoenixDownII::PhoenixDownII() // DONE!
{
    this->item_type = PHOENIXDOWN_II;
    this->next = nullptr;
}
ItemType PhoenixDownII::get_type() // DONE!
{
    return this->item_type;
}
bool PhoenixDownII::canUse(BaseKnight *knight)
{
    return true;
}
void PhoenixDownII::use(BaseKnight *knight)
{
}

PhoenixDownIII::PhoenixDownIII() // DONE!
{
    this->item_type = PHOENIXDOWN_III;
    this->next = nullptr;
}
ItemType PhoenixDownIII::get_type() // DONE!
{
    return this->item_type;
}
bool PhoenixDownIII::canUse(BaseKnight *knight)
{
    return true;
}
void PhoenixDownIII::use(BaseKnight *knight)
{
}

PhoenixDownIV::PhoenixDownIV() // DONE!
{
    this->item_type = PHOENIXDOWN_IV;
    this->next = nullptr;
}
ItemType PhoenixDownIV::get_type() // DONE!
{
    return this->item_type;
}
bool PhoenixDownIV::canUse(BaseKnight *knight)
{
    return true;
}
void PhoenixDownIV::use(BaseKnight *knight)
{
}

/* * * BEGIN implementation of class BaseBag * * */
// bool BaseBag::can_add_item(ItemType t)
// {
//     // if (knight->get_type() == DRAGON && t == ANTIDOTE)
//     //     return false;
//     // if (knight->get_type() == NORMAL && count < 16)
//     //     return true;
//     // if (knight->get_type() == LANCELOT && count < 19)
//     //     return true;
//     // if (knight->get_type() == DRAGON && count < 14)
//     //     return true;
//     // if (knight->get_type() == PALADIN)
//     //     return true;
//     // return false;
//     return true;
// }

bool BaseBag::insertFirst(BaseItem *item) // DONE!
{
    if (this->count < this->item_max)
    {
        if (this->head == nullptr)
        {
            this->head = this->tail = item;
            count++;
            if (item->get_type() == ANTIDOTE)
                antidote_cnt++;
            else
                phoenixdown_cnt++;
        }
        else
        {
            item->next = this->head;
            this->head = item;
            count++;
            if (item->get_type() == ANTIDOTE)
                antidote_cnt++;
            else
                phoenixdown_cnt++;
        }
        return true;
    }
    else
        return false;
}

BaseItem *BaseBag::get(ItemType itemType) // DONE! (need test)
{
    if (this->count == 0)
    {
        return nullptr;
    }
    if (this->head->get_type() == itemType)
    {
        BaseItem *result = this->head;
        this->head = this->head->next;
        result->next = nullptr;
        this->count--;
        if (itemType == ANTIDOTE)
            antidote_cnt--;
        else
            phoenixdown_cnt--;
        return result; // delete result??
    }
    else
    {
        BaseItem *item = this->head;
        BaseItem *prev = nullptr;
        while (item != nullptr && item->get_type() != itemType)
        {
            prev = item;
            item = item->next;
        }
        if (item == nullptr)
        {
            return nullptr;
        }
        // found, swap with head
        BaseItem *temp = this->head->next;
        this->head->next = item->next;
        prev->next = this->head;
        item->next = temp;
        this->head = item;
        delete temp;
        // remove
        BaseItem *result = this->head;
        this->head = this->head->next;
        result->next = nullptr;
        this->count--;
        if (itemType == ANTIDOTE)
            antidote_cnt--;
        else
            phoenixdown_cnt--;
        return result; // delete result??
    }
}

string BaseBag::toString() const // DONE!
{
    string str_bag = "Bag[count=" + to_string(this->count) + ";";
    BaseItem *temp = this->head;
    if (temp == nullptr)
        return "Bag[count=0;]";
    while (temp != nullptr)
    {
        string str_item_type = (temp->get_type() == ANTIDOTE) ? "Antidote" : ((temp->get_type() == PHOENIXDOWN_I) ? "PhoenixI" : ((temp->get_type() == PHOENIXDOWN_II) ? "PhoenixII" : ((temp->get_type() == PHOENIXDOWN_III) ? "PhoenixIII" : "PhoenixIV")));
        str_bag += str_item_type;
        str_bag += (temp->next != nullptr) ? "," : "]";
        temp = temp->next;
    }
    return str_bag;
}

int BaseBag::get_count() // DONE!
{
    return this->count;
}

int BaseBag::get_antidote_cnt()
{
    return this->antidote_cnt;
}

int BaseBag::get_phoenixdown_cnt()
{
    return this->phoenixdown_cnt;
}

void BaseBag::clear()
{
    while (this->head != NULL)
    {
        BaseItem *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

void BaseBag::remove_fisrt() // DONE!
{
    BaseItem *temp = this->head;
    if (temp->get_type() == ANTIDOTE)
        antidote_cnt--;
    else
        phoenixdown_cnt--;
    this->head = temp->next;
    delete temp;
    count--;
}

BagOfPaladin::BagOfPaladin(BaseKnight *knight, int antidote, int phoenixdownI) // DONE!
{
    this->head = this->tail = nullptr;
    this->count = 0;
    this->antidote_cnt += antidote;
    this->phoenixdown_cnt += phoenixdownI;
    this->knight = knight;
    if ((antidote + phoenixdownI) <= item_max)
    {
        BaseItem *new_item;
        while (phoenixdownI > 0)
        {
            new_item = new PhoenixDownI();
            insertFirst(new_item);
            phoenixdownI--;
        }
        while (antidote > 0)
        {
            new_item = new Antidote();
            insertFirst(new_item);
            antidote--;
        }
    }
}

BagOfPaladin::~BagOfPaladin() // DONE!
{
    while (this->head != NULL)
    {
        BaseItem *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

BagOfLancelot::BagOfLancelot(BaseKnight *knight, int antidote, int phoenixdownI) // DONE!
{
    this->head = this->tail = nullptr;
    this->count = 0;
    this->antidote_cnt += antidote;
    this->phoenixdown_cnt += phoenixdownI;
    this->knight = knight;
    this->item_max = 16;
    if ((antidote + phoenixdownI) <= this->item_max)
    {
        BaseItem *new_item;
        while (phoenixdownI > 0)
        {
            new_item = new PhoenixDownI();
            insertFirst(new_item);
            phoenixdownI--;
        }
        while (antidote > 0)
        {
            new_item = new Antidote();
            insertFirst(new_item);
            antidote--;
        }
    }
}

BagOfLancelot::~BagOfLancelot() // DONE!
{
    while (this->head != NULL)
    {
        BaseItem *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

BagOfDragon::BagOfDragon(BaseKnight *knight, int antidote, int phoenixdownI) // DONE!
{
    this->head = this->tail = nullptr;
    this->count = 0;
    this->antidote_cnt += antidote;
    this->phoenixdown_cnt += phoenixdownI;
    this->knight = knight;
    this->item_max = 14;
    if (phoenixdownI <= this->item_max)
    {
        BaseItem *new_item;
        while (phoenixdownI > 0)
        {
            new_item = new PhoenixDownI();
            insertFirst(new_item);
            phoenixdownI--;
        }
    }
}

BagOfDragon::~BagOfDragon() // DONE!
{
    while (this->head != NULL)
    {
        BaseItem *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

BagOfNormal::BagOfNormal(BaseKnight *knight, int antidote, int phoenixdownI) // DONE!
{
    this->head = this->tail = nullptr;
    this->count = 0;
    this->antidote_cnt += antidote;
    this->phoenixdown_cnt += phoenixdownI;
    this->knight = knight;
    this->item_max = 19;
    if ((antidote + phoenixdownI) <= this->item_max)
    {
        BaseItem *new_item;
        while (phoenixdownI > 0)
        {
            new_item = new PhoenixDownI();
            insertFirst(new_item);
            phoenixdownI--;
        }
        while (antidote > 0)
        {
            new_item = new Antidote();
            insertFirst(new_item);
            antidote--;
        }
    }
}

BagOfNormal::~BagOfNormal() // DONE!
{
    while (this->head != NULL)
    {
        BaseItem *temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

/* * * BEGIN implementation of class BaseKnight * * */
BaseKnight *BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) // DONE!
{
    BaseKnight *newKnight = nullptr;
    if (is_Paladin(maxhp))
    {
        newKnight = new PaladinKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        newKnight->set_bag(newKnight);
    }
    else if (is_Lancelot(maxhp))
    {
        newKnight = new LancelotKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        newKnight->set_bag(newKnight);
    }
    else if (is_Dragon(maxhp))
    {
        newKnight = new DragonKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        newKnight->set_bag(newKnight);
    }
    else
    {
        newKnight = new NormalKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        newKnight->set_bag(newKnight);
    }
    return newKnight;
}

string BaseKnight::toString() const // DONE!
{
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) + ",hp:" + to_string(hp) + ",maxhp:" + to_string(maxhp) + ",level:" + to_string(level) + ",gil:" + to_string(gil) + "," + bag->toString() + ",knight_type:" + typeString[knightType] + "]";
    return s;
}

bool BaseKnight::is_Paladin(int init_hp) // DONE!
{
    if (init_hp <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= init_hp; i++)
    {
        if (init_hp % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool BaseKnight::is_Lancelot(int init_hp) // DONE!
{
    if (init_hp == 888)
        return true;
    else
        return false;
}

bool BaseKnight::is_Dragon(int init_hp) // DONE!
{
    if (init_hp < 100 || init_hp > HP_MAX)
    {
        return false;
    }
    int hundreds = init_hp / 100;
    int tens = (init_hp / 10) % 10;
    int units = init_hp % 10;
    int squareSum = (hundreds * hundreds) + (tens * tens);
    return (squareSum == (units * units));
}

int BaseKnight::get_id() // DONE!
{
    return this->id;
}

int BaseKnight::get_hp() // DONE!
{
    return this->hp;
}

int BaseKnight::get_maxhp() // DONE!
{
    return this->maxhp;
}

int BaseKnight::get_level() // DONE!
{
    return this->level;
}

int BaseKnight::get_gil() // DONE!
{
    return this->gil;
}

int BaseKnight::get_antidote() // DONE!
{
    return this->antidote;
}

int BaseKnight::get_phoenixdownI() // DONE!
{
    return this->phoenixdownI;
}

BaseBag *BaseKnight::get_bag() const // DONE!
{
    return this->bag;
}

KnightType BaseKnight::get_type() // DONE!
{
    return this->knightType;
}

bool BaseKnight::get_is_poisoned() // DONE!
{
    return this->is_poisoned;
}

void BaseKnight::set_id(int new_id) // DONE!
{
    this->id = new_id;
}

void BaseKnight::set_hp(int new_hp) // DONE!
{
    this->hp = new_hp;
    if (this->hp > HP_MAX)
    {
        this->hp = HP_MAX;
    }
}

void BaseKnight::set_level(int new_level) // DONE!
{
    this->level += new_level;
    if (this->level > LEVEL_MAX)
    {
        this->level = LEVEL_MAX;
    }
    if (this->level < LEVEL_MIN)
    {
        this->level = LEVEL_MIN;
    }
}

void BaseKnight::set_level_method2(int new_level) // DONE!
{
    this->level = new_level;
    if (this->level > LEVEL_MAX)
    {
        this->level = LEVEL_MAX;
    }
    if (this->level < LEVEL_MIN)
    {
        this->level = LEVEL_MIN;
    }
}

void BaseKnight::set_gil(int new_gil) // DONE!
{
    this->gil += new_gil;
    if (this->gil > GIL_MAX)
    {
        this->gil = GIL_MAX;
    }
    if (this->gil < GIL_MIN)
    {
        this->gil = GIL_MIN;
    }
}

void BaseKnight::set_gil_method2(int new_gil)
{
    this->gil = new_gil;
    if (this->gil > GIL_MAX)
    {
        this->gil = GIL_MAX;
    }
    if (this->gil < GIL_MIN)
    {
        this->gil = GIL_MIN;
    }
}

void BaseKnight::set_bag(BaseKnight *knight) // DONE!
{
    if (knight->get_type() == PALADIN)
    {
        this->bag = new BagOfPaladin(knight, knight->get_antidote(), knight->get_phoenixdownI());
    }
    else if (knight->get_type() == LANCELOT)
    {
        this->bag = new BagOfLancelot(knight, knight->get_antidote(), knight->get_phoenixdownI());
    }
    else if (knight->get_type() == DRAGON)
    {
        this->bag = new BagOfDragon(knight, knight->get_antidote(), knight->get_phoenixdownI());
    }
    else
    {
        this->bag = new BagOfNormal(knight, knight->get_antidote(), knight->get_phoenixdownI());
    }
}

void BaseKnight::set_is_poisoned(bool is_poisoned) // DONE!
{
    this->is_poisoned = is_poisoned;
}

PaladinKnight::PaladinKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) // DONE!
{
    this->id = id;
    this->hp = maxhp;
    this->maxhp = maxhp;
    this->level = level;
    this->gil = gil;
    this->antidote = antidote;
    this->phoenixdownI = phoenixdownI;
    this->bag = nullptr;
    this->knightType = PALADIN;
    this->is_poisoned = false;
}

PaladinKnight::~PaladinKnight() // DONE!
{
    delete this->bag;
}

bool PaladinKnight::fight(BaseOpponent *opponent) // ********************* TO-DO *********************
{
    return true;
}

LancelotKnight::LancelotKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) // DONE!
{
    this->id = id;
    this->hp = maxhp;
    this->maxhp = maxhp;
    this->level = level;
    this->gil = gil;
    this->antidote = antidote;
    this->phoenixdownI = phoenixdownI;
    this->bag = nullptr;
    this->knightType = LANCELOT;
    this->is_poisoned = false;
}

LancelotKnight::~LancelotKnight() // DONE!
{
    delete this->bag;
}

bool LancelotKnight::fight(BaseOpponent *opponent) // ********************* TO-DO *********************
{
    return true;
}

DragonKnight::DragonKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) // DONE!
{
    this->id = id;
    this->hp = maxhp;
    this->maxhp = maxhp;
    this->level = level;
    this->gil = gil;
    this->antidote = antidote;
    this->phoenixdownI = phoenixdownI;
    this->bag = nullptr;
    this->knightType = DRAGON;
    this->is_poisoned = false;
}

DragonKnight::~DragonKnight() // DONE!
{
    delete this->bag;
}

bool DragonKnight::fight(BaseOpponent *opponent) // ********************* TO-DO *********************
{
    return true;
}

NormalKnight::NormalKnight(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI) // DONE!
{
    this->id = id;
    this->hp = maxhp;
    this->maxhp = maxhp;
    this->level = level;
    this->gil = gil;
    this->antidote = antidote;
    this->phoenixdownI = phoenixdownI;
    this->bag = nullptr;
    this->knightType = NORMAL;
    this->is_poisoned = false;
}

NormalKnight::~NormalKnight() // DONE!
{
    delete this->bag;
}

bool NormalKnight::fight(BaseOpponent *opponent) // ********************* TO-DO *********************
{
    return true;
}

/* * * BEGIN implementation of class BaseOpponent * * */
MadBear::MadBear() // DONE!
{
    this->level_O = 0;
    this->type_O = MEET_MADBEAR;
    this->base_dmg_O = BASE_DMG_MADBEAR;
    this->gil_O = GIL_MADBEAR;
}
int MadBear::get_type_O() // DONE!
{
    return this->type_O;
}
int MadBear::get_level_O() // DONE!
{
    return this->level_O;
}
int MadBear::get_base_dmg_O() // DONE!
{
    return this->base_dmg_O;
}
int MadBear::get_gil_O() // DONE!
{
    return this->gil_O;
}
void MadBear::set_level_O(int i, int event_id) // DONE!
{
    this->level_O = (i + event_id) % 10 + 1;
}

Bandit::Bandit() // DONE!
{
    this->level_O = 0;
    this->type_O = MEET_BANDIT;
    this->base_dmg_O = BASE_DMG_BANDIT;
    this->gil_O = GIL_BANDIT;
}
int Bandit::get_type_O() // DONE!
{
    return this->type_O;
}
int Bandit::get_level_O() // DONE!
{
    return this->level_O;
}
int Bandit::get_base_dmg_O() // DONE!
{
    return this->base_dmg_O;
}
int Bandit::get_gil_O() // DONE!
{
    return this->gil_O;
}
void Bandit::set_level_O(int i, int event_id) // DONE!
{
    this->level_O = (i + event_id) % 10 + 1;
}

LordLupin::LordLupin() // DONE!
{
    this->level_O = 0;
    this->type_O = MEET_LORDLUPIN;
    this->base_dmg_O = BASE_DMG_LORDLUPIN;
    this->gil_O = GIL_LORDLUPIN;
}
int LordLupin::get_type_O() // DONE!
{
    return this->type_O;
}
int LordLupin::get_level_O() // DONE!
{
    return this->level_O;
}
int LordLupin::get_base_dmg_O() // DONE!
{
    return this->base_dmg_O;
}
int LordLupin::get_gil_O() // DONE!
{
    return this->gil_O;
}
void LordLupin::set_level_O(int i, int event_id) // DONE!
{
    this->level_O = (i + event_id) % 10 + 1;
}

Elf::Elf() // DONE!
{
    this->level_O = 0;
    this->type_O = MEET_ELF;
    this->base_dmg_O = BASE_DMG_ELF;
    this->gil_O = GIL_ELF;
}
int Elf::get_type_O() // DONE!
{
    return this->type_O;
}
int Elf::get_level_O() // DONE!
{
    return this->level_O;
}
int Elf::get_base_dmg_O() // DONE!
{
    return this->base_dmg_O;
}
int Elf::get_gil_O() // DONE!
{
    return this->gil_O;
}
void Elf::set_level_O(int i, int event_id) // DONE!
{
    this->level_O = (i + event_id) % 10 + 1;
}

Troll::Troll() // DONE!
{
    this->level_O = 0;
    this->type_O = MEET_TROLL;
    this->base_dmg_O = BASE_DMG_TROLL;
    this->gil_O = GIL_TROLL;
}
int Troll::get_type_O() // DONE!
{
    return this->type_O;
}
int Troll::get_level_O() // DONE!
{
    return this->level_O;
}
int Troll::get_base_dmg_O() // DONE!
{
    return this->base_dmg_O;
}
int Troll::get_gil_O() // DONE!
{
    return this->gil_O;
}
void Troll::set_level_O(int i, int event_id) // DONE!
{
    this->level_O = (i + event_id) % 10 + 1;
}

Tornbery::Tornbery() // DONE!
{
    this->level_O = 0;
    this->type_O = MEET_TORNBERY;
    this->base_dmg_O = 0;
    this->gil_O = 0;
}
int Tornbery::get_type_O() // DONE!
{
    return this->type_O;
}
int Tornbery::get_level_O() // DONE!
{
    return this->level_O;
}
int Tornbery::get_base_dmg_O() // DONE!
{
    return this->base_dmg_O;
}
int Tornbery::get_gil_O() // DONE!
{
    return this->gil_O;
}
void Tornbery::set_level_O(int i, int event_id) // DONE!
{
    this->level_O = (i + event_id) % 10 + 1;
}

QueenOfCards::QueenOfCards() // DONE!
{
    this->level_O = 0;
    this->type_O = MEET_QUEENOFCARDS;
    this->base_dmg_O = 0;
    this->gil_O = 0;
}
int QueenOfCards::get_type_O() // DONE!
{
    return this->type_O;
}
int QueenOfCards::get_level_O() // DONE!
{
    return this->level_O;
}
int QueenOfCards::get_base_dmg_O() // DONE!
{
    return this->base_dmg_O;
}
int QueenOfCards::get_gil_O() // DONE!
{
    return this->gil_O;
}
void QueenOfCards::set_level_O(int i, int event_id) // DONE!
{
    this->level_O = (i + event_id) % 10 + 1;
}

NinaDeRings::NinaDeRings() // DONE!
{
    this->level_O = 0;
    this->type_O = MEET_NINA;
    this->base_dmg_O = 0;
    this->gil_O = 0;
}
int NinaDeRings::get_type_O() // DONE!
{
    return this->type_O;
}
int NinaDeRings::get_level_O() // DONE!
{
    return this->level_O;
}
int NinaDeRings::get_base_dmg_O() // DONE!
{
    return this->base_dmg_O;
}
int NinaDeRings::get_gil_O() // DONE!
{
    return this->gil_O;
}
void NinaDeRings::set_level_O(int i, int event_id) // DONE!
{
    this->level_O = (i + event_id) % 10 + 1;
}

DurianGarden::DurianGarden() // DONE!
{
    this->level_O = 0;
    this->type_O = MEET_DURIANGARDEN;
    this->base_dmg_O = 0;
    this->gil_O = 0;
}
int DurianGarden::get_type_O() // DONE!
{
    return this->type_O;
}
int DurianGarden::get_level_O() // DONE!
{
    return this->level_O;
}
int DurianGarden::get_base_dmg_O() // DONE!
{
    return this->base_dmg_O;
}
int DurianGarden::get_gil_O() // DONE!
{
    return this->gil_O;
}
void DurianGarden::set_level_O(int i, int event_id) // DONE!
{
    this->level_O = (i + event_id) % 10 + 1;
}

OmegaWeapon::OmegaWeapon() // DONE!
{
    this->level_O = 0;
    this->type_O = MEET_OMEGAWEAPON;
    this->base_dmg_O = 0;
    this->gil_O = 0;
}
int OmegaWeapon::get_type_O() // DONE!
{
    return this->type_O;
}
int OmegaWeapon::get_level_O() // DONE!
{
    return this->level_O;
}
int OmegaWeapon::get_base_dmg_O() // DONE!
{
    return this->base_dmg_O;
}
int OmegaWeapon::get_gil_O() // DONE!
{
    return this->gil_O;
}
void OmegaWeapon::set_level_O(int i, int event_id) // DONE!
{
    this->level_O = (i + event_id) % 10 + 1;
}

Hades::Hades() // DONE!
{
    this->level_O = 0;
    this->type_O = MEET_HADES;
    this->base_dmg_O = 0;
    this->gil_O = 0;
}
int Hades::get_type_O() // DONE!
{
    return this->type_O;
}
int Hades::get_level_O() // DONE!
{
    return this->level_O;
}
int Hades::get_base_dmg_O() // DONE!
{
    return this->base_dmg_O;
}
int Hades::get_gil_O() // DONE!
{
    return this->gil_O;
}
void Hades::set_level_O(int i, int event_id) // DONE!
{
    this->level_O = (i + event_id) % 10 + 1;
}

/* * * BEGIN implementation of class ArmyKnights * * */
ArmyKnights::ArmyKnights(const string &file_armyknights) // DONE!
{
    ifstream myfile_a(file_armyknights);
    if (!myfile_a.is_open())
    {
        cout << "The file cannot be opened!\n";
        exit(1);
    }
    if (!myfile_a.good())
    {
        cout << "The file has an error!\n";
        exit(1);
    }
    // get armyknights_cnt
    string line_armyknights_cnt;
    getline(myfile_a, line_armyknights_cnt);
    istringstream get_events_cnt(line_armyknights_cnt);
    get_events_cnt >> armyknights_cnt;
    // get armyknights
    string line_armyknights;
    armyknight = new BaseKnight *[armyknights_cnt];
    for (int i = 0; i < armyknights_cnt; i++)
    {
        getline(myfile_a, line_armyknights);
        istringstream get_armyknights(line_armyknights);
        get_armyknights >> armyknights_hp >> armyknights_level >> armyknights_phoenixdownI >> armyknights_gil >> armyknights_antidote;
        armyknight[i] = BaseKnight::create(i + 1, armyknights_hp, armyknights_level, armyknights_gil, armyknights_antidote, armyknights_phoenixdownI);
    }
    myfile_a.close();
}

ArmyKnights::~ArmyKnights() // DONE!
{
    for (int i = 0; i < armyknights_cnt; i++)
    {
        delete armyknight[i];
    }
    delete[] armyknight;
}

bool ArmyKnights::fight(BaseOpponent *opponent, int i) // ********************* TO-DO *********************
{
    if (opponent->get_type_O() >= 1 && opponent->get_type_O() <= 5) // EVENT CODE 1 -> 5
    {
        opponent->set_level_O(i, opponent->get_type_O());
        if (lastKnight()->get_type() == LANCELOT || lastKnight()->get_type() == PALADIN || (lastKnight()->get_level() >= opponent->get_level_O()))
        {
            if ((lastKnight()->get_gil() + opponent->get_gil_O()) > 999) // gil passing back
            {
                int gil_excess = lastKnight()->get_gil() + opponent->get_gil_O() - 999;
                gil_passing_back(lastKnight()->get_id() - 1, gil_excess);
            }
            lastKnight()->set_gil(opponent->get_gil_O());
        }
        else
        {
            int new_hp = lastKnight()->get_hp() - opponent->get_base_dmg_O() * (opponent->get_level_O() - lastKnight()->get_level());
            lastKnight()->set_hp(new_hp);
            if (lastKnight()->get_hp() <= HP_MIN)
            {
                lastKnight()->get_bag()->get(PHOENIXDOWN_I)->use(lastKnight());
                if (lastKnight()->get_hp() <= HP_MIN)
                {
                    if (lastKnight()->get_gil() >= 100)
                    {
                        lastKnight()->set_gil(-100);
                        lastKnight()->set_hp((int)((lastKnight()->get_maxhp()) / 2));
                    }
                    else // last knight be fallen
                    {
                        this->armyknights_cnt--;
                    }
                }
            }
        }
    }

    if (opponent->get_type_O() == 6) // EVENT CODE 6
    {
        opponent->set_level_O(i, opponent->get_type_O());
        if (lastKnight()->get_level() >= opponent->get_level_O())
        {
            lastKnight()->set_level(1);
        }
        else
        {
            if (lastKnight()->get_type() != DRAGON)
            {
                lastKnight()->set_is_poisoned(true);
                if (lastKnight()->get_bag()->get_antidote_cnt() > 0)
                {
                    lastKnight()->get_bag()->get(ANTIDOTE)->use(lastKnight());
                }
                else
                {
                    if (lastKnight()->get_bag()->get_count() <= 3)
                    {
                        lastKnight()->get_bag()->clear();
                    }
                    else if (lastKnight()->get_bag()->get_count() > 3)
                    {
                        lastKnight()->get_bag()->remove_fisrt();
                        lastKnight()->get_bag()->remove_fisrt();
                        lastKnight()->get_bag()->remove_fisrt();
                    }
                    lastKnight()->set_hp(lastKnight()->get_hp() - 10);
                    if (lastKnight()->get_hp() <= HP_MIN)
                    {
                        lastKnight()->get_bag()->get(PHOENIXDOWN_I)->use(lastKnight());
                        if (lastKnight()->get_hp() <= HP_MIN)
                        {
                            if (lastKnight()->get_gil() >= 100)
                            {
                                lastKnight()->set_gil(-100);
                                lastKnight()->set_hp((int)((lastKnight()->get_maxhp()) / 2));
                            }
                            else // last knight be fallen
                            {
                                this->armyknights_cnt--;
                            }
                        }
                    }
                }
            }
        }
    }

    if (opponent->get_type_O() == 7) // EVENT CODE 7
    {
        opponent->set_level_O(i, opponent->get_type_O());
        if (lastKnight()->get_level() >= opponent->get_level_O())
        {
            if ((lastKnight()->get_gil() * 2) > 999) // gil passing back
            {
                int gil_excess = lastKnight()->get_gil() * 2 - 999;
                gil_passing_back(lastKnight()->get_id() - 1, gil_excess);
            }
            lastKnight()->set_gil_method2(lastKnight()->get_gil() * 2);
        }
        else
        {
            if (lastKnight()->get_type() != PALADIN)
            {
                lastKnight()->set_gil_method2((int)(lastKnight()->get_gil() / 2));
            }
        }
    }

    if (opponent->get_type_O() == 8) // EVENT CODE 8
    {
        if ((lastKnight()->get_type() == PALADIN || lastKnight()->get_gil() >= 50) && lastKnight()->get_hp() < (int)((lastKnight()->get_maxhp() / 3)))
        {
            if (lastKnight()->get_type() != PALADIN)
                lastKnight()->set_gil(-50);
            lastKnight()->set_hp((int)(lastKnight()->get_maxhp() / 5));
        }
    }

    if (opponent->get_type_O() == 9) // EVENT CODE 9
    {
        lastKnight()->set_hp(lastKnight()->get_maxhp());
    }

    if (opponent->get_type_O() == 10) // EVENT CODE 10
    {
        if (met_OmegaWeapon)
        {
            return true;
        }
        if ((lastKnight()->get_level() == 10 && lastKnight()->get_hp() == lastKnight()->get_maxhp()) || lastKnight()->get_type() == DRAGON)
        {
            lastKnight()->set_level_method2(10);
            lastKnight()->set_gil_method2(999);
            met_OmegaWeapon = true;
        }
        else
        {
            lastKnight()->set_hp(0);
            if (lastKnight()->get_hp() <= HP_MIN)
            {
                lastKnight()->get_bag()->get(PHOENIXDOWN_I)->use(lastKnight());
                if (lastKnight()->get_hp() <= HP_MIN)
                {
                    if (lastKnight()->get_gil() >= 100)
                    {
                        lastKnight()->set_gil(-100);
                        lastKnight()->set_hp((int)((lastKnight()->get_maxhp()) / 2));
                    }
                    else // last knight be fallen
                    {
                        this->armyknights_cnt--;
                    }
                }
            }
        }
    }

    if (opponent->get_type_O() == 11) // EVENT CODE 11
    {
        if (met_Hades)
        {
            return true;
        }
        if ((lastKnight()->get_level() == 10) || (lastKnight()->get_type() == PALADIN && lastKnight()->get_level() >= 8))
        {
            hasShield = true;
            met_Hades = true;
        }
        else
        {
            lastKnight()->set_hp(0);
            if (lastKnight()->get_hp() <= HP_MIN)
            {
                lastKnight()->get_bag()->get(PHOENIXDOWN_I)->use(lastKnight());
                if (lastKnight()->get_hp() <= HP_MIN)
                {
                    if (lastKnight()->get_gil() >= 100)
                    {
                        lastKnight()->set_gil(-100);
                        lastKnight()->set_hp((int)((lastKnight()->get_maxhp()) / 2));
                    }
                    else // last knight be fallen
                    {
                        this->armyknights_cnt--;
                    }
                }
            }
        }
    }

    return true;
}

bool ArmyKnights::adventure(Events *events) // ********************* TO-DO *********************
{
    for (int i = 0; i < events->count(); i++)
    {
        switch (events->get(i))
        {
        case MEET_MADBEAR:
        {
            BaseOpponent *opponent_MadBear = new MadBear();
            fight(opponent_MadBear, i);
            delete opponent_MadBear;
            break;
        }
        case MEET_BANDIT:
        {
            BaseOpponent *opponent_Bandit = new Bandit();
            fight(opponent_Bandit, i);
            delete opponent_Bandit;
            break;
        }
        case MEET_LORDLUPIN:
        {
            BaseOpponent *opponent_LordLupin = new LordLupin();
            fight(opponent_LordLupin, i);
            delete opponent_LordLupin;
            break;
        }
        case MEET_ELF:
        {
            BaseOpponent *opponent_Elf = new Elf();
            fight(opponent_Elf, i);
            delete opponent_Elf;
            break;
        }
        case MEET_TROLL:
        {
            BaseOpponent *opponent_Troll = new Troll();
            fight(opponent_Troll, i);
            delete opponent_Troll;
            break;
        }
        case MEET_TORNBERY:
        {
            BaseOpponent *opponent_Tornbery = new Tornbery();
            fight(opponent_Tornbery, i);
            delete opponent_Tornbery;
            break;
        }
        case MEET_QUEENOFCARDS:
        {
            BaseOpponent *opponent_QueenOfCards = new QueenOfCards();
            fight(opponent_QueenOfCards, i);
            delete opponent_QueenOfCards;
            break;
        }
        case MEET_NINA:
        {
            BaseOpponent *opponent_NinaDeRings = new NinaDeRings();
            fight(opponent_NinaDeRings, i);
            delete opponent_NinaDeRings;
            break;
        }
        case MEET_DURIANGARDEN:
        {
            BaseOpponent *opponent_DurianGarden = new DurianGarden();
            fight(opponent_DurianGarden, i);
            delete opponent_DurianGarden;
            break;
        }
        case MEET_OMEGAWEAPON:
        {
            BaseOpponent *opponent_OmegaWeapon = new OmegaWeapon();
            fight(opponent_OmegaWeapon, i);
            delete opponent_OmegaWeapon;
            break;
        }
        case MEET_HADES:
        {
            BaseOpponent *opponent_Hades = new Hades();
            fight(opponent_Hades, i);
            delete opponent_Hades;
            break;
        }
        case PICK_PHOENIXDOWN_II:
        {
            break;
        }
        case PICK_PHOENIXDOWN_III:
        {
            break;
        }
        case PICK_PHOENIXDOWN_IV:
        {
            break;
        }
        case PICK_PALADIN_SHIELD:
        {
            hasShield = true;
            break;
        }
        case PICK_LANCELOT_SPEAR:
        {
            hasSpear = true;
            break;
        }
        case PICK_GUINEVERE_HAIR:
        {
            hasHair = true;
            break;
        }
        case MEET_EXCALIBUR:
        {
            if (hasShield == true && hasSpear == true && hasHair == true)
            {
                hasExcalibur = true;
            }
            break;
        }
        case MEET_ULTIMECIA:
        {
            if (hasExcalibur)
            {
                defeated_Ultimecia = true;
                break;
            }
            if (hasShield == true && hasSpear == true && hasHair == true)
            {
                int Ultimecia_HP = 5000;
                for (int i = this->armyknights_cnt; i >= 1; i--)
                {
                    if (getKnight(i)->get_type() == PALADIN || getKnight(i)->get_type() == LANCELOT || getKnight(i)->get_type() == DRAGON)
                    {
                        int Knight_Damage = 0;
                        if (getKnight(i)->get_type() == PALADIN)
                        {
                            Knight_Damage = (int)(getKnight(i)->get_hp() * getKnight(i)->get_level() * BASE_DMG_PALADIN);
                        }
                        else if (getKnight(i)->get_type() == LANCELOT)
                        {
                            Knight_Damage = (int)(getKnight(i)->get_hp() * getKnight(i)->get_level() * BASE_DMG_LANCELOT);
                        }
                        else if (getKnight(i)->get_type() == DRAGON)
                        {
                            Knight_Damage = (int)(getKnight(i)->get_hp() * getKnight(i)->get_level() * BASE_DMG_DRAGON);
                        }
                        Ultimecia_HP -= Knight_Damage;
                        if (Ultimecia_HP > 0)
                        {
                            delete_knight_at(i);
                            armyknights_cnt--;
                        }
                    }
                }
                if (Ultimecia_HP > 0)
                {
                    defeated_Ultimecia = false;
                    armyknights_cnt = 0;
                }
                if (Ultimecia_HP <= 0)
                {
                    defeated_Ultimecia = true;
                    break;
                }
            }
            else
            {
                defeated_Ultimecia = false;
                armyknights_cnt == 0;
            }
            break;
        }
        default:
        {
            break;
        }
        }
        printInfo();
    }
    if (defeated_Ultimecia)
        return true;
    else
        return false;
}

BaseKnight *ArmyKnights::lastKnight() const // DONE!
{
    if (armyknights_cnt == 0)
        return nullptr;
    return armyknight[armyknights_cnt - 1];
}

BaseKnight *ArmyKnights::getKnight(int id) const // DONE!
{
    if (id < 1 || id > armyknights_cnt)
        return nullptr;
    return armyknight[id - 1];
}

int ArmyKnights::count() const // DONE!
{
    return this->armyknights_cnt;
}

bool ArmyKnights::hasPaladinShield() const // DONE!
{
    return this->hasShield;
}

bool ArmyKnights::hasLancelotSpear() const // DONE!
{
    return this->hasSpear;
}

bool ArmyKnights::hasGuinevereHair() const // DONE!
{
    return this->hasHair;
}

bool ArmyKnights::hasExcaliburSword() const // DONE!
{
    return this->hasExcalibur;
}

void ArmyKnights::gil_passing_back(int prevknight_id, int gil_excess) // DONE!
{
    if (prevknight_id == 0)
    {
        return;
    }
    if ((getKnight(prevknight_id)->get_gil() + gil_excess) > 999)
    {
        int gil_excess_again = getKnight(prevknight_id)->get_gil() + gil_excess - 999;
        gil_passing_back(prevknight_id - 1, gil_excess_again);
    }
    getKnight(prevknight_id)->set_gil(gil_excess);
}

bool ArmyKnights::check_Paladin_Lancelot_Dragon() // DONE!
{
    bool check_Paladin = false;
    bool check_Lancelot = false;
    bool check_Dragon = false;
    for (int i = 1; i <= this->armyknights_cnt; i++)
    {
        if (getKnight(i)->get_type() == PALADIN)
            check_Paladin = true;
        if (getKnight(i)->get_type() == LANCELOT)
            check_Lancelot = true;
        if (getKnight(i)->get_type() == DRAGON)
            check_Dragon = true;
    }
    if (check_Paladin && check_Lancelot && check_Dragon)
        return true;
    else
        return false;
}

void ArmyKnights::delete_knight_at(int id)
{
    if (id < 1 || id > armyknights_cnt)
    {
        return;
    }
    int idx = armyknights_cnt - 1;
    while (idx)
    {
        if (armyknight[idx]->get_id() == id)
            break;
        idx--;
    }
    for (int i = idx; i < armyknights_cnt - 1; i++)
    {
        armyknight[i] = armyknight[i + 1];
    }
    armyknights_cnt--;
    BaseKnight **new_armyknights = new BaseKnight *[armyknights_cnt];
    for (int i = 0; i < armyknights_cnt; i++)
    {
        new_armyknights[i] = armyknight[i];
    }
    delete[] armyknight;
    armyknight = new_armyknights;
}

void ArmyKnights::printInfo() const // DONE!
{
    cout << "No. knights: " << this->armyknights_cnt;
    if (this->armyknights_cnt > 0)
    {
        BaseKnight *lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasShield
         << ";LancelotSpear:" << this->hasSpear
         << ";GuinevereHair:" << this->hasHair
         << ";ExcaliburSword:" << this->hasExcalibur
         << endl
         << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const // DONE!
{
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * BEGIN implementation of class Events * * */
Events::Events(const string &file_events) // DONE!
{
    ifstream myfile_e(file_events);
    if (!myfile_e.is_open())
    {
        cout << "The file_events cannot be opened!\n";
        exit(1);
    }
    if (!myfile_e.good())
    {
        cout << "The file_events has an error!\n";
        exit(1);
    }
    // get events_cnt
    string line_events_cnt;
    getline(myfile_e, line_events_cnt);
    istringstream get_events_cnt(line_events_cnt);
    get_events_cnt >> events_cnt;
    // get event
    string line_event;
    getline(myfile_e, line_event);
    istringstream get_event(line_event);
    event = new int[events_cnt];
    for (int m = 0; m < events_cnt; m++)
    {
        get_event >> event[m];
    }
    myfile_e.close();
}

Events::~Events() // DONE!
{
    delete[] event;
}

int Events::count() const // DONE!
{
    return events_cnt;
}

int Events::get(int i) const // DONE!
{
    return event[i];
}

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() // DONE!
{
    armyKnights = nullptr;
    events = nullptr;
}

KnightAdventure::~KnightAdventure() // DONE!
{
    delete armyKnights;
    delete events;
}

void KnightAdventure::loadArmyKnights(const string &file_armyknights) // DONE!
{
    armyKnights = new ArmyKnights(file_armyknights);
}

void KnightAdventure::loadEvents(const string &file_events) // DONE!
{
    events = new Events(file_events);
}

void KnightAdventure::run() // DONE!
{
    (armyKnights->adventure(events)) ? armyKnights->printResult(true) : armyKnights->printResult(false);
}