typedef struct {

    int max_n_players;
    int n_decks;

} Settings;

void init_settings(Settings* settings){ //TODO: Read settings from a file
    settings->max_n_players = 7;
    settings->n_decks = 1;
}