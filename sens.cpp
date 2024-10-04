#include <iostream>
#include <cstdint>
#include <string.h>
#include <unordered_map>

#define add_game(sens_multiplier, ...) \
    do { \
        for ( auto &&arg : {__VA_ARGS__} ) { \
            games.insert(std::make_pair(std::string(arg), sens_multiplier)); \
        } \
    } while (0)

// todo( hamid ): switch to std::cout
#define print_valid_game( name, description ) printf( "\t" name "\t\t" description "\n" )

#define CONST_UNREAL         13070.32617
#define CONST_SOURCE         41563.63672
#define CONST_ROBLOX           904.80005
#define CONST_OW_COD        138545.45312
#define CONST_SIEGE         159581.15625
#define CONST_FORTNITE      164756.75000


void usage() {
    printf("usage:\n\tsens <dpi> <sensitivity> <input game> <output game>\n");
    printf("\nvalid games:\n");
    // todo( hamid ): fix these to actually have all the extra names that i've added for each
    print_valid_game( "cm",     "cm/360"          );
    print_valid_game( "val",    "valorant"        );
    print_valid_game( "cs",     "counterstrike"   );
    print_valid_game( "dl",     "deadlock"        );
    print_valid_game( "cod",    "call of duty"    );
    print_valid_game( "ow",     "overwatch"       );
    print_valid_game( "roblox", "roblox"          );
    print_valid_game( "fn",     "fortnite"        );
    print_valid_game( "r6",     "rainbow 6 siege" );
}

void init_games( std::unordered_map<std::string, double>& games ) {
    add_game( CONST_UNREAL,     "val", "valorant", "valo");
    add_game( CONST_SOURCE,     "cs", "csgo", "cs2", "css", "cs1.6", "source", "apex", "al", "counterstrike");
    add_game( CONST_SOURCE / 2, "dl", "deadlock");
    add_game( CONST_OW_COD,     "cod", "mw", "mw2", "bo6", "bo", "ow", "ow2", "overwatch");
    add_game( CONST_FORTNITE,   "fn", "fortnite");
    add_game( CONST_SIEGE,      "r6", "siege");
    add_game( CONST_ROBLOX,     "roblox");
}

#define a_dpi  argv[1]
#define a_sens argv[2]
#define a_from argv[3]
#define a_to   argv[4]

int main( int argc, char** argv ) {

    std::unordered_map<std::string, double> games;
    init_games(games);

    if ( argc != 5 ) {
        usage();
        return 0;
    }

    // todo( hamid ): error checking
    int64_t dpi = atoll( a_dpi );
    double sens = atof( a_sens );
    double from = games[ a_from ];
    double to   = games[ a_to ];

    if ( !strcmp( a_from, "cm" ) || !strcmp( a_from, "cm/360" ) ) {
        sens = to / ( sens * dpi );
    } else if ( !strcmp( a_to, "cm" ) || !strcmp( a_from, "cm/360" ) ) {
        sens = from / ( sens * dpi );
    } else {
        sens = sens * ( to / from );
    }


    std::cout << sens << std::endl;

    return 0;
}