#include <iostream>
#include <cstdint>
#include <string.h>
#include <unordered_map>

#define add_game( game, sens ) games.insert( std::pair<std::string, double>( std::string(#game), sens ) )

#define CONST_UNREAL 13070.328
#define CONST_SOURCE 41563.632

void usage() {
    printf("usage:\n\tsens <dpi> <input sens> <input game> <output game>\n");
    printf("\nvalid input/output games:\n");
    printf("\tcm\t\t cm/360\n");
    printf("\tval\t\t valorant\n");
    printf("\tcs\t\t counterstrike\n");
    printf("\tdl\t\t deadlock\n");
}

void init_games( std::unordered_map<std::string, double>& games ) {
    add_game( val, CONST_UNREAL );
    add_game( cs,  CONST_SOURCE );
    add_game( dl,  CONST_SOURCE / 2 );
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

    int64_t dpi = atoll( a_dpi );
    double sens = atof( a_sens );
    double from = games[ a_from ];
    double to   = games[ a_to ];

    if ( !strcmp( a_from, "cm" ) ) {
        sens = to / ( sens * dpi );
    } else if ( !strcmp( a_to, "cm" ) ) {
        sens = from / ( sens * dpi );
    } else {
        sens = sens * ( to / from );
    }

    printf("%lf\n", sens);

    return 0;
}