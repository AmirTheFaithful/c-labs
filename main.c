#include <stdio.h>
#include <string.h>

enum power_states
{
    ON = 0x0f,
    SLEEP = 0x9fa,
    OFF = 0x567
};

int curr_pw_st;

int set_power_state(void);
int err_cmmd_hndlr(void);
int power_loop(void);

int main()
{
    printf("\nSession ended with code %d.\n", set_power_state());

    return 0;
}

int set_power_state()
{
    int max;
    extern int curr_pw_st;
    int status;
    char c, i;

    max = 40;
    char cmmd[max];

    while ((c = getchar()) != EOF && c != '\n')
    {
        if (i < max)
        {
            cmmd[i++] = c;
        }
    }

    cmmd[i] = '\0';

    printf("%s", cmmd);

    if (strcmp(cmmd, "start") == 0)
    {
        curr_pw_st = ON;
        printf("\nDevice is on.\n");
        printf("\nCurrent state is %d\n", curr_pw_st);
        status = 0;
    }
    else if (strcmp(cmmd, "off") == 0)
    {
        curr_pw_st = OFF;
        printf("\nDevice is off.\n");
        printf("\nCurrent state is %d\n", curr_pw_st);
        status = 2;
    }
    else if (strcmp(cmmd, "sleep") == 0)
    {
        curr_pw_st = SLEEP;
        printf("\nDevice is on sleep regime.\n");
        printf("\nCurrent state is %d\n", curr_pw_st);
        status = 1;
    }
    else
        err_cmmd_hndlr();

    return status;
}

int err_cmmd_hndlr()
{
    int c;

    printf("\nWrong command.\nRestart? (y/n)\n");
    c = getchar();

    if (c == 'y')
    {
        set_power_state();
        return 0;
    }
    else if (c == 'n')
        return 1;

    return -1;
}

int power_loop()
{
    int res;
    while (__GCC_ATOMIC_TEST_AND_SET_TRUEVAL)
    {
        res = set_power_state();
        if (res == 0 && curr_pw_st == OFF)
            break;
        else if (res == 0 && curr_pw_st == 2554)
            break;
        else if (res == 0 && curr_pw_st == ON)
            break;
    }

    return 0;
}