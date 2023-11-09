#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

//最大候选人为9
#define MAX 9

// preferences[i][j]代表选民i的第j偏好
int preferences[MAX][MAX];

// locked[i][j]:从i指向j
bool locked[MAX][MAX];

// 每一对都有一个winner和loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
char candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

bool vote(int rank, char name[100], int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
int voter_count(void);

int main(int argc, char argv[100])
{
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];

        for (int j = 0; j < candidate_count; j++)
        {
            char name[100] = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

bool vote(int rank, char name[100], int ranks[])
{
    for (int i = 0,n = candidate_count; i < n; i++)
    {
        if (strcmp(name,candidates[i] == 0))
        {
            ranks[rank] = i;
        }
        return false;
    }
}

void record_preferences(int ranks[])
{
    for (int i = 0; i < voter_count ; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            preferences[i][j] = ranks[i];
        }
        
    }
    return;
}

void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i+1; j < candidate_count; j++)
        {
            if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
            
        }
        
    }
    
    return;
}

void sort_pairs(void)
{
    int left_strength, right_strength, r_winner, r_loser;
    int swap_counter = -1;
    do
    {
        swap_counter = 0;
        for (int i = 0; i < pair_count; i++)
        {
            left_strength = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[i].loser][pairs[i].winner];
            right_strength = preferences[pairs[i + 1].winner][pairs[i + 1].loser] - preferences[pairs[i + 1].loser][pairs[i + 1].winner];
            if (left_strength < right_strength)
            {
                r_winner = pairs[i + 1].winner;
                r_loser = pairs[i + 1].loser;
                pairs[i + 1].winner = pairs[i].winner;
                pairs[i + 1].loser = pairs[i].loser;
                pairs[i].winner = r_winner;
                pairs[i].loser = r_loser;
                swap_counter++;
            }
        }
    }
    while (swap_counter != 0);
    return;
}

void lock_pairs(void)
{
     for (int i = 0; i < pair_count; i++)
    {
        // Lock
        locked[pairs[i].winner][pairs[i].loser] = true;

        // Search for edges
        bool edges_pointing[candidate_count];
        for (int j = 0; j < candidate_count; j++)
        {
            int arrow = 0;
            for (int k = 0; k < candidate_count; k++)
            {
                if (locked[k][j])
                {
                    arrow++;
                }
            }
            edges_pointing[j] = (!arrow) ? false : true;
        }

        // Check if current lock created a cycle
        int cycles = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (!edges_pointing[j])
            {
                cycles++;
            }
        }

        // Unlock if cycle
        if (!cycles)
        {
            locked[pairs[i].winner][pairs[i].loser] = false;
        }
    }
    return;
}

void print_winner(void)
{
     int winner = 0;
    for (int i = 0; i < pair_count; i++)
    {
        int not_source = 0;
        for (int j = 0; j < pair_count; j++)
        {
            not_source += (locked[j][i]) ? 1 : 0;
        }
        if (!not_source)
        {
            winner = i + 1;
        }
    }

    return winner;
}