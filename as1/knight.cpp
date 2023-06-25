#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue)
{
    cout << "HP=" << HP
         << ", level=" << level
         << ", remedy=" << remedy
         << ", maidenkiss=" << maidenkiss
         << ", phoenixdown=" << phoenixdown
         << ", rescue=" << rescue << '\n';
}

bool containMerlinOnly(string Merlin_item)
{
    if (Merlin_item.find("Merlin") != string::npos || Merlin_item.find("merlin") != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool containMerlinLetters(string Merlin_item)
{
    bool foundM = false;
    bool foundE = false;
    bool foundR = false;
    bool foundL = false;
    bool foundI = false;
    bool foundN = false;
    for (char c : Merlin_item)
    {
        if (tolower(c) == 'm')
        {
            foundM = true;
        }
        else if (tolower(c) == 'e')
        {
            foundE = true;
        }
        else if (tolower(c) == 'r')
        {
            foundR = true;
        }
        else if (tolower(c) == 'l')
        {
            foundL = true;
        }
        else if (tolower(c) == 'i')
        {
            foundI = true;
        }
        else if (tolower(c) == 'n')
        {
            foundN = true;
        }
    }
    return foundM && foundE && foundR && foundL && foundI && foundN;
}

void checkMountainSequence(int n2_sequence[], int n2, int &mtx, int &mti)
{
    mtx = -2;
    mti = -3;
    int i = 0;
    while (i < n2 - 1 && n2_sequence[i] < n2_sequence[i + 1]) // scan for increasing values
    {
        i++;
    }
    if (i == 0) // if no increasing values, check if the peak is at the beginning
    {
        int j = 0;
        while (j < n2 - 1 && n2_sequence[j] > n2_sequence[j + 1])
        {
            j++;
        }
        if (j == n2 - 1)
        {
            mtx = n2_sequence[0];
            mti = 0;
            return;
        }
    }
    else
    {
        int k = i;
        while (k < n2 - 1 && n2_sequence[k] > n2_sequence[k + 1]) // scan for decreasing values
        {
            k++;
        }
        if (k == n2 - 1 || (i == k && n2_sequence[i] != n2_sequence[i + 1])) // the peak is inside the sequence or the peak is at the end
        {
            mtx = n2_sequence[i];
            mti = i;
        }
    }
}

int decrementToNearestFibonacciMushFib(int n)
{
    int prevFib = 0;
    int currFib = 1;
    int nextFib = 1;
    while (nextFib <= n)
    {
        prevFib = currFib;
        currFib = nextFib;
        nextFib = prevFib + currFib;
    }
    return currFib == n ? prevFib : currFib;
}

bool isPrimeMushMario(int n)
{
    if (n <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int nextPrimeMushMario(int n)
{
    while (!isPrimeMushMario(n))
    {
        n++;
    }
    return n;
}

int incrementToNearestPrimeMushMario(int n)
{
    int next = nextPrimeMushMario(n + 1);
    return next;
}

int s1MushMario(int n1)
{
    int nums[45];
    int idx = 0;
    for (int i = 11; i <= 99; i += 2)
    {
        nums[idx++] = i;
    }
    for (int i = 0; i < 44; i++)
    {
        for (int j = i + 1; j < 45; j++)
        {
            if (nums[j] > nums[i])
            {
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n1; i++)
    {
        sum += nums[i];
    }
    return sum;
}

void checkFrogState(int &frog_state_cnt, int level_before_frog, int &level, int &maidenkiss)
{
    if (frog_state_cnt > 0)
    {
        if (maidenkiss > 0)
        {
            maidenkiss--;
            frog_state_cnt = 0;
            level = level_before_frog;
        }
        else
        {
            frog_state_cnt--;
            if (frog_state_cnt == 0)
            {
                level = level_before_frog;
            }
        }
    }
}

void checkTinyState(int &tiny_state_cnt, int maxHP, /* int HP_before_tiny, */ int &HP, int &remedy, int &phoenixdown)
{
    if (tiny_state_cnt > 0)
    {
        if (remedy > 0)
        {
            remedy--;
            tiny_state_cnt = 0;
            /* HP = HP_before_tiny; */
            HP = HP * 5;
            if (HP > maxHP)
            {
                HP = maxHP;
            }
        }
        else if (HP <= 0 && phoenixdown) // still conflicts with using phoenixdown at event 1->5
        {
            phoenixdown--;
            tiny_state_cnt = 0;
            HP = maxHP;
        }
        else
        {
            tiny_state_cnt--;
            if (tiny_state_cnt == 0)
            {
                HP = HP * 5;
                if (HP > maxHP)
                {
                    HP = maxHP;
                }
            }
        }
    }
}

int updateLevelO(int i)
{
    int b = i % 10;
    int levelO = (i > 6) ? ((b > 5) ? b : 5) : b;
    return levelO;
}

void checkLimit(int maxHP, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown)
{
    if (HP > HP_MAX)
        HP = HP_MAX;
    if (HP <= HP_MIN)
        HP = HP_MIN;
    if (level > LEVEL_MAX)
        level = LEVEL_MAX;
    if (level < LEVEL_MIN)
        level = LEVEL_MIN;
    if (remedy > REMEDY_MAX)
        remedy = REMEDY_MAX;
    if (remedy < REMEDY_MIN)
        remedy = REMEDY_MIN;
    if (maidenkiss > MAIDENKISS_MAX)
        maidenkiss = MAIDENKISS_MAX;
    if (maidenkiss < MAIDENKISS_MIN)
        maidenkiss = MAIDENKISS_MIN;
    if (phoenixdown > PHOENIXDOWN_MAX)
        phoenixdown = PHOENIXDOWN_MAX;
    if (phoenixdown < PHOENIXDOWN_MIN)
        phoenixdown = PHOENIXDOWN_MIN;
}

int countEvents(string line_Events)
{
    int cnt = 0;
    istringstream get_Events(line_Events);
    string event;
    while (get_Events >> event)
    {
        cnt++;
    }
    return cnt;
}

void adventureToKoopa(string file_input, int &HP, int &level, int &remedy, int &maidenkiss, int &phoenixdown, int &rescue)
{
    string line_Knight, line_Events, line_Special;
    ifstream myfile(file_input);
    if (myfile.is_open())
    {
        while (myfile.good())
        {
            getline(myfile, line_Knight);
            getline(myfile, line_Events);
            getline(myfile, line_Special);
        }
        myfile.close();
    }
    else
        cout << "The file cannot be opened!" << '\n';
    // get Knight
    istringstream get_Knight(line_Knight);
    while (get_Knight)
    {
        get_Knight >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    }
    int maxHP = HP;
    bool ARTHUR = false, LANCELOT = false;
    if (maxHP == 999)
    {
        ARTHUR = true;
    }
    if (isPrimeMushMario(maxHP))
    {
        LANCELOT = true;
    }
    // get Events
    int num_of_Events = countEvents(line_Events);
    int event[num_of_Events];
    istringstream get_Events(line_Events);
    for (int m = 0; m < num_of_Events; m++)
    {
        get_Events >> event[m];
    }
    // get Special
    string file_input_MushGhost, file_input_Asclepius, file_input_Merlin;
    istringstream get_Special(line_Special);
    getline(get_Special, file_input_MushGhost, ',');
    getline(get_Special, file_input_Asclepius, ',');
    getline(get_Special, file_input_Merlin, ',');
    // process Events
    bool journey_ended = false;
    int levelO;
    int tiny_state_cnt = 0;
    int HP_before_tiny;
    int frog_state_cnt = 0;
    int level_before_frog;
    int n1, s1;
    string line_n2, line_n2_sequence;
    string event_MushGhost;
    int maxi, mini;
    int maxi_val = MIN_INT;
    int mini_val = MAX_INT;
    int mtx, mti;
    int maxi2, mini2;
    int maxi2_val = MIN_INT;
    int mini2_val = MAX_INT;
    int max2_3x, max2_3i;
    int max_3x = MIN_INT;
    int min_3x = MAX_INT;
    string line_r1, line_c1;
    bool met_Asclepius_once = false;
    bool met_Merlin_once = false;
    string line_n9;
    for (int n = 0; n < num_of_Events; n++)
    {
        switch (event[n])
        {
        case BOWSER_SURRENDERED:
            rescue = 1;
            journey_ended = true;
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            goto end;

        case MEET_MADBEAR:
            levelO = updateLevelO(n + 1);
            level = (level > levelO || ARTHUR || LANCELOT) ? (level + 1) : level;
            HP = (level < levelO && !ARTHUR && !LANCELOT) ? (HP - BASE_DMG_MADBEAR * levelO * 10) : HP;
            if (HP <= 0)
            {
                if (phoenixdown)
                {
                    phoenixdown--;
                    HP = maxHP;
                }
                else
                {
                    rescue = 0;
                    journey_ended = true;
                    goto end;
                }
            }
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case MEET_BANDIT:
            levelO = updateLevelO(n + 1);
            level = (level > levelO || ARTHUR || LANCELOT) ? (level + 1) : level;
            HP = (level < levelO && !ARTHUR && !LANCELOT) ? (HP - BASE_DMG_BANDIT * levelO * 10) : HP;
            if (HP <= 0)
            {
                if (phoenixdown)
                {
                    phoenixdown--;
                    HP = maxHP;
                }
                else
                {
                    rescue = 0;
                    journey_ended = true;
                    goto end;
                }
            }
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case MEET_LORDLUPIN:
            levelO = updateLevelO(n + 1);
            level = (level > levelO || ARTHUR || LANCELOT) ? (level + 1) : level;
            HP = (level < levelO && !ARTHUR && !LANCELOT) ? (HP - BASE_DMG_LORDLUPIN * levelO * 10) : HP;
            if (HP <= 0)
            {
                if (phoenixdown)
                {
                    phoenixdown--;
                    HP = maxHP;
                }
                else
                {
                    rescue = 0;
                    journey_ended = true;
                    goto end;
                }
            }
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case MEET_ELF:
            levelO = updateLevelO(n + 1);
            level = (level > levelO || ARTHUR || LANCELOT) ? (level + 1) : level;
            HP = (level < levelO && !ARTHUR && !LANCELOT) ? (HP - BASE_DMG_ELF * levelO * 10) : HP;
            if (HP <= 0)
            {
                if (phoenixdown)
                {
                    phoenixdown--;
                    HP = maxHP;
                }
                else
                {
                    rescue = 0;
                    journey_ended = true;
                    goto end;
                }
            }
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case MEET_TROLL:
            levelO = updateLevelO(n + 1);
            level = (level > levelO || ARTHUR || LANCELOT) ? (level + 1) : level;
            HP = (level < levelO && !ARTHUR && !LANCELOT) ? (HP - BASE_DMG_TROLL * levelO * 10) : HP;
            if (HP <= 0)
            {
                if (phoenixdown)
                {
                    phoenixdown--;
                    HP = maxHP;
                }
                else
                {
                    rescue = 0;
                    journey_ended = true;
                    goto end;
                }
            }
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case MEET_SHAMAN:
            levelO = updateLevelO(n + 1);
            if (tiny_state_cnt == 0 && frog_state_cnt == 0) // not being in tiny and frog state at the time
            {
                level = (level > levelO || ARTHUR || LANCELOT) ? (level + 2) : level;
                if (level < levelO && !ARTHUR && !LANCELOT)
                {
                    if (remedy > 0) // if remedy, use immediately
                    {
                        remedy--;
                    }
                    else // being turned into tiny
                    {
                        /* HP_before_tiny = HP; */
                        HP = (HP >= 5) ? (int)(HP / 5) : 1;
                        tiny_state_cnt += 3;
                    }
                }
            }
            else // being in tiny or frog state at the time
            {
                checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown); // handle as other events
                checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            }
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case MEET_SIRENVAJSH:
            levelO = updateLevelO(n + 1);
            if (frog_state_cnt == 0 && tiny_state_cnt == 0) // not being in frog and tiny state at the time
            {
                if (level > levelO || ARTHUR || LANCELOT)
                {
                    level += 2;
                    checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
                    rescue = -1;
                    goto next_event;
                }
                else if (level < levelO && !ARTHUR && !LANCELOT)
                {
                    if (maidenkiss > 0) // if maidenkiss, use immediately
                    {
                        maidenkiss--;
                    }
                    else // being turned into frog
                    {
                        level_before_frog = level;
                        level = 1;
                        frog_state_cnt += 3;
                    }
                }
            }
            else // being in frog or tiny state at the time
            {
                checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss); // handle as other events
                checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            }
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case PICK_MUSHMARIO:
            n1 = ((level + phoenixdown) % 5 + 1) * 3;
            s1 = s1MushMario(n1);
            HP = HP + (s1 % 100);
            HP = incrementToNearestPrimeMushMario(HP);
            if (HP > maxHP)
            {
                HP = maxHP;
            }
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case PICK_MUSHFIB:
            if (HP > 1)
            {
                HP = decrementToNearestFibonacciMushFib(HP);
            }
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case PICK_MUSHGHOST:
            // implement in the default case
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case OBTAIN_REMEDY:
            remedy++;
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case OBTAIN_MAIDENKISS:
            maidenkiss++;
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case PICK_PHOENIXDOWN:
            phoenixdown++;
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;

        case MEET_MERLIN:
        {
            if (met_Merlin_once == false)
            {
                ifstream myfileM(file_input_Merlin);
                if (!myfileM.is_open())
                {
                    cout << "myfileM cannot be opened!" << '\n';
                }
                // get n9
                getline(myfileM, line_n9);
                unsigned int n9 = stoi(line_n9);
                // get Merlin's items
                string Merlin_item[n9];
                for (unsigned int n; n < n9; n++)
                {
                    getline(myfileM, Merlin_item[n]);
                }
                myfileM.close();
                // handle enchanted items
                for (unsigned int m; m < n9; m++)
                {
                    if (containMerlinOnly(Merlin_item[m]))
                    {
                        HP = HP + 3;
                    }
                    else if (containMerlinLetters(Merlin_item[m]))
                    {
                        HP = HP + 2;
                    }
                }
                if (HP > maxHP)
                {
                    HP = maxHP;
                }
                met_Merlin_once = true;
            }
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;
        }

        case MEET_ASCLEPIUS:
        {
            if (met_Asclepius_once == false)
            {
                ifstream myfileA(file_input_Asclepius);
                if (!myfileA.is_open())
                {
                    cout << "myfileA cannot be opened!" << '\n';
                }
                // get r1
                getline(myfileA, line_r1);
                unsigned int r1 = stoi(line_r1);
                // get c1
                getline(myfileA, line_c1);
                unsigned int c1 = stoi(line_c1);
                // get 2D array
                int arr_Asclepius[r1][c1];
                string str_Asclepius[r1][c1];
                string line_Asclepius[r1];
                for (unsigned int i = 0; i < r1; i++)
                {
                    getline(myfileA, line_Asclepius[i]);
                    istringstream get_arr_Asclepius(line_Asclepius[i]);
                    for (unsigned int j = 0; j < c1; j++)
                    {
                        getline(get_arr_Asclepius, str_Asclepius[i][j], ' ');
                        stringstream(str_Asclepius[i][j]) >> arr_Asclepius[i][j];
                    }
                }
                myfileA.close();
                // handle Asclepius cases
                int cnt_3_potions = 0;
                for (unsigned int i = 0; i < r1; i++)
                {
                    for (unsigned int j = 0; j < c1; j++)
                    {
                        if (cnt_3_potions < 3)
                        {
                            if (arr_Asclepius[i][j] == 16)
                            {
                                remedy++;
                                cnt_3_potions++;
                            }
                            if (arr_Asclepius[i][j] == 17)
                            {
                                maidenkiss++;
                                cnt_3_potions++;
                            }
                            if (arr_Asclepius[i][j] == 18)
                            {
                                phoenixdown++;
                                cnt_3_potions++;
                            }
                        }
                    }
                    cnt_3_potions = 0;
                }
                met_Asclepius_once = true;
            }
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;
        }

        case MEET_BOWSER:
            if (ARTHUR || (LANCELOT && level >= 8) || level == 10)
            {
                level = 10;
            }
            else
            {
                rescue = 0;
                journey_ended = true;
                checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
                checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
                goto end;
            }
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            rescue = -1;
            break;

        default:
        {
            // PICK_MUSHGHOST
            ifstream myfileMG(file_input_MushGhost);
            if (myfileMG.is_open())
            {
                while (myfileMG.good())
                {
                    getline(myfileMG, line_n2);
                    getline(myfileMG, line_n2_sequence);
                }
                myfileMG.close();
            }
            else
            {
                cout << "myfileMG cannot be opened!" << '\n';
            }
            // get n2
            unsigned int n2 = stoi(line_n2); // stoi() available in C++11 or newer
            // get n2 sequence
            int n2_sequence[n2];
            string n2_str[n2];
            istringstream get_n2_sequence(line_n2_sequence);
            for (unsigned int p = 0; p < n2; p++)
            {
                getline(get_n2_sequence, n2_str[p], ',');
                stringstream(n2_str[p]) >> n2_sequence[p];
            }
            // sequence for transformation
            int n2_trans_sequence[n2];
            // handle MushGhost types
            event_MushGhost = to_string(event[n]);
            for (int q = 2; q < event_MushGhost.size(); q++)
            {
                switch (event_MushGhost[q])
                {
                case '1':
                    for (unsigned int k = 0; k < n2; k++)
                    {
                        if (n2_sequence[k] >= maxi_val)
                        {
                            maxi_val = n2_sequence[k];
                            maxi = k;
                        }
                        if (n2_sequence[k] <= mini_val)
                        {
                            mini_val = n2_sequence[k];
                            mini = k;
                        }
                    }
                    HP = HP - (maxi + mini);
                    break;
                case '2':
                    checkMountainSequence(n2_sequence, n2, mtx, mti);
                    HP = HP - (mtx + mti);
                    break;
                case '3':
                    for (unsigned int z = 0; z < n2; z++)
                    {
                        n2_trans_sequence[z] = n2_sequence[z];
                    }
                    for (unsigned int l = 0; l < n2; l++)
                    {
                        if (n2_trans_sequence[l] < 0)
                        {
                            n2_trans_sequence[l] = -n2_trans_sequence[l];
                        }
                        n2_trans_sequence[l] = (17 * n2_trans_sequence[l] + 9) % 257;
                    }
                    for (unsigned int r = 0; r < n2; r++)
                    {
                        if (n2_trans_sequence[r] > maxi2_val)
                        {
                            maxi2_val = n2_trans_sequence[r];
                            maxi2 = r;
                        }
                        if (n2_trans_sequence[r] < mini2_val)
                        {
                            mini2_val = n2_trans_sequence[r];
                            mini2 = r;
                        }
                    }
                    HP = HP - (maxi2 + mini2);
                    break;
                case '4':
                    for (unsigned int z = 0; z < n2; z++)
                    {
                        n2_trans_sequence[z] = n2_sequence[z];
                    }
                    for (unsigned int h = 0; h < n2; h++)
                    {
                        if (n2_trans_sequence[h] < 0)
                        {
                            n2_trans_sequence[h] = -n2_trans_sequence[h];
                        }
                        n2_trans_sequence[h] = (17 * n2_trans_sequence[h] + 9) % 257;
                    }
                    max2_3x = -5;
                    max2_3i = -7;
                    if (n2 > 1)
                    {
                        if (n2 == 2)
                        {
                            if (n2_trans_sequence[0] > n2_trans_sequence[1])
                            {
                                max2_3x = n2_trans_sequence[1];
                                max2_3i = 1;
                            }
                            if (n2_trans_sequence[0] < n2_trans_sequence[1])
                            {
                                max2_3x = n2_trans_sequence[0];
                                max2_3i = 0;
                            }
                        }
                        else
                        {
                            for (unsigned int v = 0; v < 3; v++)
                            {
                                if (n2_trans_sequence[v] > max_3x)
                                {
                                    max_3x = n2_trans_sequence[v];
                                }
                                if (n2_trans_sequence[v] < min_3x)
                                {
                                    min_3x = n2_trans_sequence[v];
                                }
                            }
                            if (n2_trans_sequence[0] != n2_trans_sequence[1] && n2_trans_sequence[1] != n2_trans_sequence[2] && n2_trans_sequence[2] != n2_trans_sequence[0]) // 3 diffrent int
                            {
                                for (unsigned int x = 0; x < 3; x++)
                                {
                                    if (n2_trans_sequence[x] < max_3x && n2_trans_sequence[x] > min_3x)
                                    {
                                        max2_3x = n2_trans_sequence[x];
                                        max2_3i = x;
                                    }
                                }
                            }
                            else // 2 max 1 min or 2 min 1 max, take the first min
                            {
                                for (unsigned int x = 0; x < 3; x++)
                                {
                                    if (n2_trans_sequence[x] < max_3x && n2_trans_sequence[x] == min_3x)
                                    {
                                        max2_3x = n2_trans_sequence[x];
                                        max2_3i = x;
                                    }
                                }
                            }
                        }
                    }
                    HP = HP - (max2_3x + max2_3i);
                    break;
                default:
                    break;
                }
                if (HP > maxHP)
                {
                    HP = maxHP;
                }
                if (HP <= 0)
                {
                    if (phoenixdown)
                    {
                        phoenixdown--;
                        HP = maxHP;
                    }
                    else
                    {
                        rescue = 0;
                        journey_ended = true;
                        goto end;
                    }
                }
            }
            checkTinyState(tiny_state_cnt, maxHP, /* HP_before_tiny, */ HP, remedy, phoenixdown);
            checkFrogState(frog_state_cnt, level_before_frog, level, maidenkiss);
            checkLimit(maxHP, HP, level, remedy, maidenkiss, phoenixdown);
            rescue = -1;
            break;
        }
        }
    next_event:
        if (n == num_of_Events - 1)
            rescue = 1;
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
    }
end:
    if (journey_ended == 1)
        display(HP, level, remedy, maidenkiss, phoenixdown, rescue);
}