#include<stdio.h>
#include<time.h>

// Moon Phase Algorithim
int moonPhase(int year, int month, int day){

    int d, g, e;

    d = day;
    if(month == 2){
        d += 31;

    }else if(month  > 2){
        d += 59 + (month - 3) * 30.6 + 0.5;

    }

    g = (year - 1900) % 19;
    e = (11*g + 29) % 30;

    if(e == 25 || e == 24)
        ++e;
    
    int result = ((((e + d) * 6 + 5) % 177) / 22 & 7);

    return result;
}

int main(int argc, char *argv[]){

    // Declaration of moonPhasevalue
    int moonPhaseValue;

    // Declaration and initialization of seconds variable
    time_t seconds;
    time(&seconds);

    // Initializing the struct
    struct tm *clock_ptr;
    clock_ptr = localtime(&seconds);
    char time_string[64];

    // Formating time and running moonPhase function
    strftime(time_string,64,"Today is %A %B %d, %Y time is %r\n", clock_ptr);
    moonPhaseValue = moonPhase(clock_ptr->tm_year, clock_ptr->tm_mon, clock_ptr->tm_mday);

    // Char array for finding moon phase
    const char *phase[8] = { 
        "waxing crescent", "at first quarter", "waxing gibbous",
        "full", "waning gibbous", "at last quarter", "waning crescent", "new"
    };

    // Dispalying time and moon phase
    printf("Hello Edu! :)\n");
    printf("%s", time_string);

    // MOON ASCII print
    puts(
"o                     __...__     *               \n"
"              *   .--'    __.=-.             o\n"
"     |          ./     .-'     \n"
"    -O-        /      /   \n"
"     |        /    '\"/               * \n"
"             |     (@)     \n"
"            |        \\                         .\n"
"            |         \\ \n"
" *          |       ___\\                  | \n"
"             |  .   /  `                 -O-\n"
"              \\  `~~\\                     |\n"
"         o     \\     \\            *         \n"
"                `\\    `-.__           .  \n"
"    .             `--._    `--'Edu\n"
"                       `---~~`                *\n"
"            *                   o\n"
);

    printf("The moon is %s\n", phase[moonPhaseValue]);  

}
